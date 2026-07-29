#!/usr/bin/env python3
"""
CTB (Conditional Turn-Based) Battle Simulator for FFX.exe reverse engineering.

Simulates FFX's turn scheduling system based on batch_0004 IDA decompilation.

CTB system overview:
  - Turn order = f(AGI, equipment bonuses, status effects)
  - Delay = baseDelay / (AGI + modifiers)
  - When delay <= 0, turn is granted
  - After acting, delay is reset: baseDelay / (AGI + modifiers)
  - Actors: 7 party slots + 8 monster slots
  - CtbSelectNextActor picks the actor with lowest accumulated delay

Key functions from decompilation:
  - CtbSelectNextActor: 446 bytes, main scheduler loop
  - CtbEdgeOverdriveEvent: 372 bytes, overdrive turn insertion
  - 3-tier actor dispatch: 3984B / 912B / singleton patterns
  - 17 overdrive slots, 4 modes (Aggressive 2x, Stoic 3x, High-level 2x, Decay 10%/turn)

Usage examples:
  python ctb_simulator.py --turns 20 --party "Tidus:40" "Wakka:35" --monsters "Sin:25"
  python ctb_simulator.py --turns 10 --party "Tidus:50,haste" --monsters "Seymour:30" --base-delay 200
  python ctb_simulator.py --turns 5 --party "Yuna:35,berserk" --monsters "Anima:40" --status
"""

import argparse
import sys
from dataclasses import dataclass, field
from typing import List, Optional, Tuple

BASE_DELAY = 100.0

STATUS_MODIFIERS = {
    "haste":      {"agi_mult": 1.5, "label": "Haste"},
    "slow":       {"agi_mult": 0.5, "label": "Slow"},
    "stop":       {"agi_mult": 0.0, "label": "Stop"},
    "berserk":    {"agi_mult": 1.0, "agi_add": 0, "label": "Berserk", "skip_turn": True},
    "sleep":      {"agi_mult": 0.0, "label": "Sleep"},
    "silence":    {"agi_mult": 1.0, "label": "Silence"},
    "petrify":    {"agi_mult": 0.0, "label": "Petrify"},
    "death":      {"agi_mult": 0.0, "label": "Dead"},
    "zombie":     {"agi_mult": 1.0, "label": "Zombie"},
    "shield":     {"agi_mult": 1.0, "label": "Shield"},
    "protect":    {"agi_mult": 1.0, "label": "Protect"},
    "regen":      {"agi_mult": 1.0, "label": "Regen"},
}

OVERDRIVE_MODES = {
    "aggressive":   {"multiplier": 2.0, "label": "Aggressive (2x)"},
    "stoic":        {"multiplier": 3.0, "label": "Stoic (3x)"},
    "highlevel":    {"multiplier": 2.0, "label": "High-level (2x)"},
    "decay":        {"multiplier": 1.0, "decay": 0.90, "label": "Decay (10%/turn)"},
}


@dataclass
class Actor:
    name: str
    agi: int
    is_monster: bool = False
    equipment_agi_bonus: int = 0
    statuses: List[str] = field(default_factory=list)
    overdrive_mode: Optional[str] = None
    delay: float = 0.0
    turns_taken: int = 0
    active: bool = True

    @property
    def effective_agi(self) -> float:
        agi = self.agi + self.equipment_agi_bonus
        for s in self.statuses:
            mod = STATUS_MODIFIERS.get(s)
            if mod:
                agi *= mod.get("agi_mult", 1.0)
                agi += mod.get("agi_add", 0)
        return max(agi, 0)

    @property
    def is_disabled(self) -> bool:
        for s in self.statuses:
            mod = STATUS_MODIFIERS.get(s, {})
            if mod.get("agi_mult", 1.0) == 0.0:
                return True
            if mod.get("skip_turn", False):
                return True
        return False

    @property
    def status_label(self) -> str:
        labels = []
        for s in self.statuses:
            mod = STATUS_MODIFIERS.get(s, {})
            labels.append(mod.get("label", s))
        return ", ".join(labels) if labels else "-"

    def compute_delay(self, base_delay: float) -> float:
        eff = self.effective_agi
        if eff <= 0:
            return float('inf')
        return base_delay / eff

    def reset_delay(self, base_delay: float):
        self.delay = self.compute_delay(base_delay)

    def apply_overdrive_decay(self):
        if self.overdrive_mode == "decay":
            self.delay *= 0.90


@dataclass
class TurnRecord:
    turn_number: int
    actor: Actor
    delay_at_grant: float
    all_delays: List[Tuple[str, float]]


def parse_actor_arg(arg: str, is_monster: bool = False) -> Actor:
    parts = arg.split(",")
    name_agi = parts[0]
    statuses = [s.strip().lower() for s in parts[1:] if s.strip()]
    if ":" in name_agi:
        name, agi_str = name_agi.split(":", 1)
        agi = int(agi_str)
    else:
        name = name_agi
        agi = 20
    od_mode = None
    clean_statuses = []
    for s in statuses:
        if s in OVERDRIVE_MODES:
            od_mode = s
        else:
            clean_statuses.append(s)
    return Actor(name=name, agi=agi, is_monster=is_monster,
                 statuses=clean_statuses, overdrive_mode=od_mode)


def simulate(base_delay: float, party: List[Actor], monsters: List[Actor],
             num_turns: int, show_status: bool = False) -> List[TurnRecord]:
    all_actors = party + monsters
    for a in all_actors:
        a.delay = a.compute_delay(base_delay)

    records: List[TurnRecord] = []
    for turn in range(1, num_turns + 1):
        enabled = [a for a in all_actors if a.active and not a.is_disabled]
        if not enabled:
            break
        best = min(enabled, key=lambda a: a.delay)
        snapshot = [(a.name, round(a.delay, 2)) for a in enabled]
        records.append(TurnRecord(turn, best, round(best.delay, 2), snapshot))
        best.delay = best.compute_delay(base_delay)
        best.apply_overdrive_decay()
        best.turns_taken += 1
        for a in enabled:
            if a is not best:
                a.delay -= best.delay
    return records


def print_table(records: List[TurnRecord], show_status: bool, party: List[Actor],
                monsters: List[Actor]):
    all_actors = party + monsters

    print("=" * 90)
    print("CTB TURN ORDER SIMULATION")
    print("=" * 90)

    print("\n--- ROSTER ---")
    hdr = f"  {'Name':<16} {'AGI':>4} {'Eq':>3} {'EffAGI':>7} {'Delay':>7} {'Type':<8} {'Statuses'}"
    print(hdr)
    print("  " + "-" * 80)
    for a in all_actors:
        atype = "MON" if a.is_monster else "PTY"
        print(f"  {a.name:<16} {a.agi:>4} {a.equipment_agi_bonus:>+3} "
              f"{a.effective_agi:>7.1f} {a.compute_delay(BASE_DELAY):>7.2f} "
              f"{atype:<8} {a.status_label}")

    print("\n--- TURN ORDER ---")
    print(f"  {'Turn':>4}  {'Actor':<16} {'Type':<5} {'Delay':>8} {'AGI':>5} {'Statuses'}")
    print("  " + "-" * 70)
    for rec in records:
        a = rec.actor
        atype = "MON" if a.is_monster else "PTY"
        status = ""
        if show_status:
            disabled = [s for s in a.statuses if STATUS_MODIFIERS.get(s, {}).get("agi_mult", 1.0) == 0.0]
            if disabled:
                status = f" [{', '.join(disabled)}]"
        print(f"  {rec.turn_number:>4}  {a.name:<16} {atype:<5} {rec.delay_at_grant:>8.2f} "
              f"{a.effective_agi:>5.1f}{status}")

    print(f"\n--- SUMMARY ({len(records)} turns) ---")
    for a in all_actors:
        print(f"  {a.name:<16} turns taken: {a.turns_taken}")
    print("=" * 90)


def main():
    parser = argparse.ArgumentParser(
        description="CTB Turn Scheduler Simulator for FFX.exe RE",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__
    )
    parser.add_argument("--turns", type=int, default=10, help="Number of turns to simulate (default 10)")
    parser.add_argument("--base-delay", type=float, default=BASE_DELAY,
                        help=f"Base delay constant (default {BASE_DELAY})")
    parser.add_argument("--party", nargs="+", metavar="Name:AGI[,status]",
                        help="Party members, e.g. 'Tidus:40,haste' 'Wakka:35'")
    parser.add_argument("--monsters", nargs="+", metavar="Name:AGI[,status]",
                        help="Monsters, e.g. 'Sin:25,berserk'")
    parser.add_argument("--status", action="store_true", help="Show status effects in turn table")
    args = parser.parse_args()

    if not args.party and not args.monsters:
        args.party = ["Tidus:40", "Yuna:35", "Auron:38", "Wakka:35", "Lulu:30", "Kimahri:32", "Rikku:38"]
        args.monsters = ["Grat:20", "Ochu:18"]
        print("(Using default roster for demo)")

    party = [parse_actor_arg(a, is_monster=False) for a in args.party]
    monsters = [parse_actor_arg(a, is_monster=True) for a in args.monsters]

    records = simulate(args.base_delay, party, monsters, args.turns, args.status)
    print_table(records, args.status, party, monsters)


if __name__ == "__main__":
    main()
