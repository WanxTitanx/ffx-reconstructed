#!/usr/bin/env python3
"""
FFX Damage Calculator
====================
Python implementation of the FFX damage formula (from batch_0012 decompilation).

The damage formula pipeline (30+ sub-functions):
1. Base damage = f(physical, magical, multi-hit)
2. Modifiers applied in order:
   - Quarter damage
   - Magic guard halving
   - Phys guard halving
   - Critical hit (1.5x)
   - Doublecast (2x)
   - DoubleDamagePierce (2x)
   - Element affinity (50% bonus/penalty)
   - Element resistance
   - Shield damage
   - Guard damage
   - Overdrive damage multiplier
3. Final clamp: min(damage, 9999) or min(damage, 99999)

Usage:
    python ffx_damage_calculator.py --attacker "Tidus:50:30:20:fire" --defender "Grat:100:10:0:none"
    python ffx_damage_calculator.py --demo
"""

import argparse
import sys
from dataclasses import dataclass, field
from typing import List, Optional
from enum import IntEnum


class ElementType(IntEnum):
    NONE = 0
    FIRE = 1
    ICE = 2
    THUNDER = 3
    WATER = 4
    HOLY = 5
    DARK = 6


class DamageType(IntEnum):
    PHYSICAL = 1
    MAGICAL = 2
    MULTI_HIT = 4


@dataclass
class Actor:
    name: str = ""
    hp: int = 100
    mp: int = 50
    strength: int = 30
    magic: int = 20
    defense: int = 10
    magic_def: int = 10
    agility: int = 30
    luck: int = 15
    evasion: int = 10
    element_weakness: ElementType = ElementType.NONE
    element_resist: ElementType = ElementType.NONE
    element_immune: ElementType = ElementType.NONE
    is_guarding: bool = False
    has_shield: bool = False
    has_break_damage_limit: bool = False
    overdrive_mode: str = "Stoic"


@dataclass
class DamageResult:
    base_damage: int = 0
    modifiers: List[str] = field(default_factory=list)
    final_damage: int = 0
    is_critical: bool = False
    is_overkill: bool = False
    element_modifier: float = 1.0
    guard_modifier: float = 1.0
    od_modifier: float = 1.0


class FFxDamageCalculator:
    """FFX damage formula calculator."""

    # Damage cap
    NORMAL_CAP = 9999
    BREAK_CAP = 99999

    # Element effectiveness multipliers
    ELEMENT_WEAKNESS = 1.5
    ELEMENT_RESIST = 0.5
    ELEMENT_NEUTRAL = 1.0

    # Guard/defense multipliers
    GUARD_HALF = 0.5
    QUARTER_DAMAGE = 0.25

    # Critical hit multiplier
    CRITICAL_MULTIPLIER = 1.5

    # Doublecast multiplier
    DOUBLECAST_MULTIPLIER = 2.0

    # Overdrive multipliers by mode
    OD_MULTIPLIERS = {
        "Stoic": 1.5,
        "Warrior": 1.0,
        "Healer": 0.5,
        "Slayer": 2.0,
        "Tactician": 1.0,
        "Comrade": 1.0,
    }

    def compute_physical_damage(self, attacker: Actor, defender: Actor,
                                 base_power: int = 100) -> int:
        """Compute base physical damage."""
        # Physical damage = (base_power + strength) * weapon_multiplier
        damage = base_power + attacker.strength

        # Apply defense reduction
        damage = max(1, damage - defender.defense // 2)

        return damage

    def compute_magical_damage(self, attacker: Actor, defender: Actor,
                                base_power: int = 100) -> int:
        """Compute base magical damage."""
        # Magical damage = (base_power + magic) * spell_multiplier
        damage = base_power + attacker.magic

        # Apply magic defense reduction
        damage = max(1, damage - defender.magic_def // 2)

        return damage

    def apply_quarter_damage(self, damage: int, defender: Actor) -> tuple:
        """Apply quarter damage modifier (defending)."""
        if defender.is_guarding:
            damage = int(damage * self.QUARTER_DAMAGE)
            return damage, "Quarter damage (guarding)"
        return damage, ""

    def apply_magic_guard_halving(self, damage: int, defender: Actor) -> tuple:
        """Apply magic guard halving."""
        if defender.is_guarding:
            damage //= 2
            return damage, "Magic guard halving"
        return damage, ""

    def apply_phys_guard_halving(self, damage: int, defender: Actor) -> tuple:
        """Apply physical guard halving."""
        if defender.is_guarding:
            damage //= 2
            return damage, "Phys guard halving"
        return damage, ""

    def apply_critical_hit(self, damage: int, attacker: Actor,
                           is_critical: bool = False) -> tuple:
        """Apply critical hit multiplier."""
        if is_critical:
            damage = int(damage * self.CRITICAL_MULTIPLIER)
            return damage, f"Critical hit (x{self.CRITICAL_MULTIPLIER})"
        return damage, ""

    def apply_doublecast(self, damage: int, is_doublecast: bool = False) -> tuple:
        """Apply doublecast multiplier."""
        if is_doublecast:
            damage = int(damage * self.DOUBLECAST_MULTIPLIER)
            return damage, f"Doublecast (x{self.DOUBLECAST_MULTIPLIER})"
        return damage, ""

    def apply_element_affinity(self, damage: int, attacker: Actor,
                               defender: Actor) -> tuple:
        """Apply element affinity modifier."""
        if attacker.element_weakness == ElementType.NONE:
            return damage, ""

        # Check if defender is weak to attacker's element
        if defender.element_weakness == attacker.element_weakness:
            damage = int(damage * self.ELEMENT_WEAKNESS)
            return damage, f"Element weakness (x{self.ELEMENT_WEAKNESS})"

        # Check if defender resists attacker's element
        if defender.element_resist == attacker.element_weakness:
            damage = int(damage * self.ELEMENT_RESIST)
            return damage, f"Element resist (x{self.ELEMENT_RESIST})"

        # Check if defender is immune
        if defender.element_immune == attacker.element_weakness:
            damage = 0
            return damage, "Element immunity"

        return damage, ""

    def apply_shield_damage(self, damage: int, defender: Actor) -> tuple:
        """Apply shield damage reduction."""
        if defender.has_shield:
            damage = int(damage * 0.75)  # 25% reduction
            return damage, "Shield damage reduction"
        return damage, ""

    def apply_guard_damage(self, damage: int, defender: Actor) -> tuple:
        """Apply guard damage reduction."""
        if defender.is_guarding:
            damage = int(damage * 0.5)  # 50% reduction
            return damage, "Guard damage reduction"
        return damage, ""

    def apply_overdrive_multiplier(self, damage: int, attacker: Actor) -> tuple:
        """Apply overdrive damage multiplier."""
        multiplier = self.OD_MULTIPLIERS.get(attacker.overdrive_mode, 1.0)
        if multiplier != 1.0:
            damage = int(damage * multiplier)
            return damage, f"Overdrive {attacker.overdrive_mode} (x{multiplier})"
        return damage, ""

    def apply_damage_cap(self, damage: int, attacker: Actor) -> int:
        """Apply damage cap (9999 or 99999)."""
        cap = self.BREAK_CAP if attacker.has_break_damage_limit else self.NORMAL_CAP
        return min(damage, cap)

    def calculate(self, attacker: Actor, defender: Actor,
                  damage_type: DamageType = DamageType.PHYSICAL,
                  base_power: int = 100,
                  is_critical: bool = False,
                  is_doublecast: bool = False) -> DamageResult:
        """Calculate final damage with all modifiers."""
        result = DamageResult()

        # Step 1: Compute base damage
        if damage_type == DamageType.PHYSICAL:
            result.base_damage = self.compute_physical_damage(attacker, defender, base_power)
        elif damage_type == DamageType.MAGICAL:
            result.base_damage = self.compute_magical_damage(attacker, defender, base_power)
        else:
            result.base_damage = self.compute_physical_damage(attacker, defender, base_power)

        damage = result.base_damage

        # Step 2: Apply modifiers in order
        modifiers = []

        # Quarter damage
        damage, mod = self.apply_quarter_damage(damage, defender)
        if mod: modifiers.append(mod)

        # Magic guard halving
        damage, mod = self.apply_magic_guard_halving(damage, defender)
        if mod: modifiers.append(mod)

        # Phys guard halving
        damage, mod = self.apply_phys_guard_halving(damage, defender)
        if mod: modifiers.append(mod)

        # Critical hit
        damage, mod = self.apply_critical_hit(damage, attacker, is_critical)
        if mod:
            modifiers.append(mod)
            result.is_critical = True

        # Doublecast
        damage, mod = self.apply_doublecast(damage, is_doublecast)
        if mod: modifiers.append(mod)

        # Element affinity
        damage, mod = self.apply_element_affinity(damage, attacker, defender)
        if mod: modifiers.append(mod)

        # Shield damage
        damage, mod = self.apply_shield_damage(damage, defender)
        if mod: modifiers.append(mod)

        # Guard damage
        damage, mod = self.apply_guard_damage(damage, defender)
        if mod: modifiers.append(mod)

        # Overdrive multiplier
        damage, mod = self.apply_overdrive_multiplier(damage, attacker)
        if mod: modifiers.append(mod)

        # Step 3: Apply damage cap
        damage = self.apply_damage_cap(damage, attacker)

        # Step 4: Check overkill
        if damage > defender.hp:
            result.is_overkill = True

        result.modifiers = modifiers
        result.final_damage = damage

        return result

    def print_result(self, attacker: Actor, defender: Actor,
                     result: DamageResult):
        """Pretty-print the damage calculation result."""
        print(f"\n{'='*60}")
        print(f"FFX DAMAGE CALCULATION")
        print(f"{'='*60}")
        print(f"Attacker: {attacker.name}")
        print(f"  STR={attacker.strength} MAG={attacker.magic} "
              f"Element={attacker.element_weakness.name}")
        print(f"Defender: {defender.name}")
        print(f"  HP={defender.hp} DEF={defender.defense} MDEF={defender.magic_def}")
        print(f"  Guarding={defender.is_guarding} Shield={defender.has_shield}")
        print(f"\nBase damage: {result.base_damage}")
        print(f"\nModifiers applied:")
        for mod in result.modifiers:
            print(f"  - {mod}")
        print(f"\nFinal damage: {result.final_damage}")
        if result.is_critical:
            print(f"  *** CRITICAL HIT ***")
        if result.is_overkill:
            print(f"  *** OVERKILL ***")
        print(f"{'='*60}")


def demo():
    """Run a demo calculation."""
    calc = FFxDamageCalculator()

    # Tidus vs Grat
    tidus = Actor(
        name="Tidus",
        hp=520, mp=82,
        strength=30, magic=17,
        defense=12, magic_def=10,
        agility=40, luck=15,
        element_weakness=ElementType.NONE,
        overdrive_mode="Stoic"
    )

    grat = Actor(
        name="Grat",
        hp=180, mp=0,
        strength=8, magic=5,
        defense=5, magic_def=3,
        agility=20, luck=5,
        element_weakness=ElementType.FIRE,
        has_shield=False
    )

    print("Demo: Tidus vs Grat (physical attack)")
    result = calc.calculate(tidus, grat, DamageType.PHYSICAL, 100, False)
    calc.print_result(tidus, grat, result)

    print("\n\nDemo: Tidus vs Grat (critical hit)")
    result = calc.calculate(tidus, grat, DamageType.PHYSICAL, 100, True)
    calc.print_result(tidus, grat, result)

    print("\n\nDemo: Lulu vs Grat (fire magic)")
    lulu = Actor(
        name="Lulu",
        hp=310, mp=120,
        strength=10, magic=40,
        defense=8, magic_def=15,
        agility=30, luck=10,
        element_weakness=ElementType.ICE,
        overdrive_mode="Warrior"
    )
    result = calc.calculate(lulu, grat, DamageType.MAGICAL, 150, False)
    calc.print_result(lulu, grat, result)


def main():
    parser = argparse.ArgumentParser(
        description="FFX Damage Calculator")
    parser.add_argument("--demo", action="store_true",
                       help="Run demo calculation")
    parser.add_argument("--attacker", type=str,
                       help="Attacker: name:str:mag:element")
    parser.add_argument("--defender", type=str,
                       help="Defender: name:hp:def:mdef:element")
    parser.add_argument("--power", type=int, default=100,
                       help="Base power (default: 100)")
    parser.add_argument("--critical", action="store_true",
                       help="Critical hit")
    parser.add_argument("--doublecast", action="store_true",
                       help="Doublecast")

    args = parser.parse_args()

    if args.demo:
        demo()
        return

    if not args.attacker or not args.defender:
        parser.print_help()
        return

    calc = FFxDamageCalculator()

    # Parse attacker
    a_parts = args.attacker.split(":")
    attacker = Actor(
        name=a_parts[0] if len(a_parts) > 0 else "Attacker",
        strength=int(a_parts[1]) if len(a_parts) > 1 else 30,
        magic=int(a_parts[2]) if len(a_parts) > 2 else 20,
        element_weakness=ElementType[a_parts[3].upper()] if len(a_parts) > 3 else ElementType.NONE
    )

    # Parse defender
    d_parts = args.defender.split(":")
    defender = Actor(
        name=d_parts[0] if len(d_parts) > 0 else "Defender",
        hp=int(d_parts[1]) if len(d_parts) > 1 else 100,
        defense=int(d_parts[2]) if len(d_parts) > 2 else 10,
        magic_def=int(d_parts[3]) if len(d_parts) > 3 else 10,
        element_weakness=ElementType[d_parts[4].upper()] if len(d_parts) > 4 else ElementType.NONE
    )

    result = calc.calculate(attacker, defender, DamageType.PHYSICAL,
                           args.power, args.critical, args.doublecast)
    calc.print_result(attacker, defender, result)


if __name__ == '__main__':
    main()
