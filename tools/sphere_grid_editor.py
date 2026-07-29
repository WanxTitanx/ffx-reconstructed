#!/usr/bin/env python3
"""
Sphere Grid Node Editor for FFX.exe reverse engineering.

Parses, displays, edits, and exports FFX Sphere Grid data from binary files
or memory dumps. Based on batch_0014 IDA decompilation analysis.

Sphere Grid structure (217 nodes, 40 bytes each):
  +0   nodePosY       (int16)
  +2   nodePosX       (int16)
  +4   nodePosZ       (int16)
  +6   linkIdx        (int16, offset into link table, -1 = no links)
  +8   nodeType       (uint16)
  +10  cost           (uint16, AP/sphere level)
  +12  linkPtr[5]     (5 x int32, pointers into link table, 20 bytes)
  +32  activationFlags(uint8, bit per character)
  +33  padding[7]

Link table: 10 bytes per link
  +0  fromNodeId (uint16)
  +2  toNodeId   (uint16)
  +4  reserved   (6 bytes)

MAXSPHECONE = 5 (max neighbors per node)
State global @ MEMORY[0x2305834] (~71KB)

Usage examples:
  python sphere_grid_editor.py --bin grid.bin --list
  python sphere_grid_editor.py --bin grid.bin --show 42
  python sphere_grid_editor.py --bin grid.bin --edit 42 --pos 100,200,50
  python sphere_grid_editor.py --bin grid.bin --export out.bin
  python sphere_grid_editor.py --generate 217 --out grid.bin
"""

import argparse
import struct
import sys
import os
from dataclasses import dataclass, field
from typing import List, Optional, Tuple

NODE_SIZE = 40
LINK_SIZE = 10
MAX_NEIGHBORS = 5
MAX_NODES = 217
CHARACTERS = ["Tidus", "Yuna", "Auron", "Kimahri", "Wakka", "Lulu", "Rikku"]
NODE_TYPES = {
    0: "STAT_STR", 1: "STAT_DEF", 2: "STAT_MAG", 3: "STAT_MDEF",
    4: "STAT_SPD", 5: "STAT_LCK", 6: "STAT_HP", 7: "STAT_MP",
    8: "ABILITY", 9: "LOCK_LEVEL1", 10: "LOCK_LEVEL2", 11: "LOCK_LEVEL3",
    12: "LOCK_LEVEL4", 13: "LOCK_LEVEL5",
}
NODE_TYPES_REV = {v: k for k, v in NODE_TYPES.items()}


@dataclass
class LinkEntry:
    from_id: int = 0
    to_id: int = 0
    reserved: bytes = b'\x00' * 6

    def pack(self) -> bytes:
        return struct.pack('<HH', self.from_id, self.to_id) + self.reserved

    @classmethod
    def unpack(cls, data: bytes, offset: int = 0) -> 'LinkEntry':
        d = data[offset:offset + LINK_SIZE]
        if len(d) < LINK_SIZE:
            return cls()
        from_id, to_id = struct.unpack_from('<HH', d)
        reserved = d[4:LINK_SIZE]
        return cls(from_id=from_id, to_id=to_id, reserved=reserved)


@dataclass
class NodeEntry:
    pos_y: int = 0
    pos_x: int = 0
    pos_z: int = 0
    link_idx: int = -1
    node_type: int = 0
    cost: int = 0
    link_ptrs: List[int] = field(default_factory=lambda: [-1] * MAX_NEIGHBORS)
    activation_flags: int = 0

    def pack(self) -> bytes:
        parts = []
        parts.append(struct.pack('<hhi', self.pos_y, self.pos_x, self.pos_z))
        parts.append(struct.pack('<hH', self.link_idx, self.node_type))
        parts.append(struct.pack('<H', self.cost))
        for ptr in self.link_ptrs:
            parts.append(struct.pack('<i', ptr))
        parts.append(struct.pack('<B', self.activation_flags))
        parts.append(b'\x00' * 7)
        raw = b''.join(parts)
        return raw[:NODE_SIZE]

    @classmethod
    def unpack(cls, data: bytes, offset: int = 0) -> 'NodeEntry':
        d = data[offset:offset + NODE_SIZE]
        if len(d) < NODE_SIZE:
            d = d.ljust(NODE_SIZE, b'\x00')
        pos_y, pos_x, pos_z = struct.unpack_from('<hhh', d, 0)
        link_idx, node_type = struct.unpack_from('<hH', d, 6)
        cost = struct.unpack_from('<H', d, 10)[0]
        link_ptrs = []
        for i in range(MAX_NEIGHBORS):
            ptr = struct.unpack_from('<i', d, 12 + i * 4)[0]
            link_ptrs.append(ptr)
        activation_flags = d[32]
        return cls(pos_y=pos_y, pos_x=pos_x, pos_z=pos_z, link_idx=link_idx,
                   node_type=node_type, cost=cost, link_ptrs=link_ptrs,
                   activation_flags=activation_flags)


@dataclass
class SphereGrid:
    nodes: List[NodeEntry] = field(default_factory=list)
    links: List[LinkEntry] = field(default_factory=list)

    @classmethod
    def from_bytes(cls, data: bytes, num_nodes: int = MAX_NODES) -> 'SphereGrid':
        sg = cls()
        for i in range(num_nodes):
            off = i * NODE_SIZE
            if off + NODE_SIZE > len(data):
                break
            sg.nodes.append(NodeEntry.unpack(data, off))
        num_links = len(data) // LINK_SIZE - num_nodes * NODE_SIZE // LINK_SIZE
        link_area_start = num_nodes * NODE_SIZE
        for i in range(num_links):
            off = link_area_start + i * LINK_SIZE
            if off + LINK_SIZE > len(data):
                break
            sg.links.append(LinkEntry.unpack(data, off))
        return sg

    def to_bytes(self) -> bytes:
        parts = [n.pack() for n in self.nodes]
        parts.extend(l.pack() for l in self.links)
        return b''.join(parts)

    def get_neighbors(self, node_id: int) -> List[int]:
        if node_id < 0 or node_id >= len(self.nodes):
            return []
        node = self.nodes[node_id]
        neighbors = []
        for link_ptr in node.link_ptrs:
            if 0 <= link_ptr < len(self.links):
                link = self.links[link_ptr]
                if link.from_id == node_id:
                    neighbors.append(link.to_id)
                elif link.to_id == node_id:
                    neighbors.append(link.from_id)
        return neighbors

    def display_ascii(self, width: int = 80, height: int = 30) -> str:
        if not self.nodes:
            return "(empty grid)"
        min_x = min(n.pos_x for n in self.nodes)
        max_x = max(n.pos_x for n in self.nodes)
        min_y = min(n.pos_y for n in self.nodes)
        max_y = max(n.pos_y for n in self.nodes)
        range_x = max_x - min_x or 1
        range_y = max_y - min_y or 1
        canvas = [['.' for _ in range(width)] for _ in range(height)]
        node_positions = {}
        for nid, node in enumerate(self.nodes):
            cx = int((node.pos_x - min_x) / range_x * (width - 3)) + 1
            cy = int((node.pos_y - min_y) / range_y * (height - 2)) + 1
            cx = max(0, min(width - 1, cx))
            cy = max(0, min(height - 1, cy))
            node_positions[nid] = (cx, cy)
            label = f"{nid:02X}" if nid < 256 else "?"
            if node.node_type >= 9:
                label = "##"
            canvas[cy][cx] = label[0]
            if cx + 1 < width:
                canvas[cy][cx + 1] = label[1] if len(label) > 1 else '.'
        drawn_links = set()
        for nid, node in enumerate(self.nodes):
            if nid not in node_positions:
                continue
            for neighbor in self.get_neighbors(nid):
                if neighbor not in node_positions:
                    continue
                link_key = (min(nid, neighbor), max(nid, neighbor))
                if link_key in drawn_links:
                    continue
                drawn_links.add(link_key)
                x1, y1 = node_positions[nid]
                x2, y2 = node_positions[neighbor]
                if y1 == y2:
                    for x in range(min(x1, x2) + 2, max(x1, x2)):
                        if canvas[y1][x] == '.':
                            canvas[y1][x] = '-'
                elif x1 == x2:
                    for y in range(min(y1, y2) + 1, max(y1, y2)):
                        if canvas[y][x1] == '.':
                            canvas[y][x1] = '|'
                else:
                    steps = max(abs(x2 - x1), abs(y2 - y1))
                    for s in range(1, steps):
                        sx = int(x1 + (x2 - x1) * s / steps)
                        sy = int(y1 + (y2 - y1) * s / steps)
                        if 0 <= sy < height and 0 <= sx < width:
                            if canvas[sy][sx] == '.':
                                canvas[sy][sx] = '+'
        lines = [''.join(row).rstrip() for row in canvas]
        return '\n'.join(lines)

    def show_node(self, node_id: int) -> str:
        if node_id < 0 or node_id >= len(self.nodes):
            return f"Error: node {node_id} out of range (0-{len(self.nodes)-1})"
        node = self.nodes[node_id]
        type_name = NODE_TYPES.get(node.node_type, f"UNKNOWN({node.node_type})")
        activated = [CHARACTERS[i] for i in range(len(CHARACTERS))
                     if node.activation_flags & (1 << i)]
        neighbors = self.get_neighbors(node_id)
        lines = [
            f"Node {node_id} (0x{node_id:04X})",
            f"  Position:  X={node.pos_x}  Y={node.pos_y}  Z={node.pos_z}",
            f"  Type:      {type_name} ({node.node_type})",
            f"  Cost:      {node.cost} AP",
            f"  LinkIdx:   {node.link_idx}",
            f"  Neighbors: {neighbors if neighbors else '(none)'}",
            f"  Activated: {', '.join(activated) if activated else '(none)'}",
            f"  Flags:     0b{node.activation_flags:08b} = 0x{node.activation_flags:02X}",
        ]
        return '\n'.join(lines)

    def edit_node(self, node_id: int, pos: Optional[Tuple[int, int, int]] = None,
                  node_type: Optional[int] = None, cost: Optional[int] = None,
                  activate: Optional[int] = None, deactivate: Optional[int] = None) -> str:
        if node_id < 0 or node_id >= len(self.nodes):
            return f"Error: node {node_id} out of range"
        node = self.nodes[node_id]
        changes = []
        if pos is not None:
            node.pos_x, node.pos_y, node.pos_z = pos
            changes.append(f"pos=({pos[0]},{pos[1]},{pos[2]})")
        if node_type is not None:
            node.node_type = node_type
            changes.append(f"type={NODE_TYPES.get(node_type, node_type)}")
        if cost is not None:
            node.cost = cost
            changes.append(f"cost={cost}")
        if activate is not None:
            node.activation_flags |= (1 << activate)
            changes.append(f"activate={CHARACTERS[activate] if activate < len(CHARACTERS) else activate}")
        if deactivate is not None:
            node.activation_flags &= ~(1 << deactivate)
            changes.append(f"deactivate={CHARACTERS[deactivate] if deactivate < len(CHARACTERS) else deactivate}")
        if not changes:
            return "No changes specified."
        return f"Node {node_id} updated: {', '.join(changes)}"

    def list_nodes(self) -> str:
        lines = [f"{'ID':>4}  {'Pos':>14}  {'Type':<14}  {'Cost':>4}  {'Neighbors':>8}  {'Active'}"]
        lines.append("-" * 72)
        for nid, node in enumerate(self.nodes):
            type_name = NODE_TYPES.get(node.node_type, f"?{node.node_type}")
            neighbors = self.get_neighbors(nid)
            activated = sum(1 for i in range(7) if node.activation_flags & (1 << i))
            lines.append(
                f"{nid:>4}  ({node.pos_x:>4},{node.pos_y:>4},{node.pos_z:>4})  "
                f"{type_name:<14}  {node.cost:>4}  {len(neighbors):>8}  "
                f"{activated}/7"
            )
        lines.append(f"\nTotal: {len(self.nodes)} nodes, {len(self.links)} links")
        return '\n'.join(lines)


def generate_empty(num_nodes: int) -> SphereGrid:
    sg = SphereGrid()
    for i in range(num_nodes):
        sg.nodes.append(NodeEntry())
    return sg


def main():
    parser = argparse.ArgumentParser(
        description="Sphere Grid Node Editor for FFX.exe RE",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__
    )
    parser.add_argument("--bin", help="Path to binary Sphere Grid file")
    parser.add_argument("--nodes", type=int, default=MAX_NODES, help="Number of nodes (default 217)")
    parser.add_argument("--list", action="store_true", help="List all nodes")
    parser.add_argument("--show", type=int, metavar="NODE_ID", help="Show node details")
    parser.add_argument("--graph", action="store_true", help="Display ASCII art graph")
    parser.add_argument("--graph-width", type=int, default=80, help="Graph width (default 80)")
    parser.add_argument("--graph-height", type=int, default=30, help="Graph height (default 30)")
    parser.add_argument("--edit", type=int, metavar="NODE_ID", help="Edit a node")
    parser.add_argument("--pos", help="New position X,Y,Z (for --edit)")
    parser.add_argument("--type", type=int, dest="node_type", help="New node type (for --edit)")
    parser.add_argument("--cost", type=int, help="New cost (for --edit)")
    parser.add_argument("--activate", type=int, help="Activate for character index (0-6)")
    parser.add_argument("--deactivate", type=int, help="Deactivate for character index (0-6)")
    parser.add_argument("--export", help="Export modified grid to file")
    parser.add_argument("--generate", type=int, metavar="N", help="Generate empty grid with N nodes")
    parser.add_argument("--out", help="Output path for --generate")
    args = parser.parse_args()

    if args.generate:
        sg = generate_empty(args.generate)
        out_path = args.out or f"sphere_grid_{args.generate}.bin"
        with open(out_path, 'wb') as f:
            f.write(sg.to_bytes())
        print(f"Generated {args.generate}-node grid -> {out_path} ({os.path.getsize(out_path)} bytes)")
        return

    if not args.bin:
        parser.error("--bin required (or use --generate)")

    with open(args.bin, 'rb') as f:
        data = f.read()
    sg = SphereGrid.from_bytes(data, args.nodes)
    print(f"Loaded {len(sg.nodes)} nodes, {len(sg.links)} links from {args.bin} ({len(data)} bytes)")

    if args.list:
        print(sg.list_nodes())
    elif args.show is not None:
        print(sg.show_node(args.show))
    elif args.graph:
        print(sg.display_ascii(args.graph_width, args.graph_height))
    elif args.edit is not None:
        pos = None
        if args.pos:
            parts = args.pos.split(',')
            pos = (int(parts[0]), int(parts[1]), int(parts[2]))
        result = sg.edit_node(args.edit, pos=pos, node_type=args.node_type,
                              cost=args.cost, activate=args.activate,
                              deactivate=args.deactivate)
        print(result)
    elif args.export:
        with open(args.export, 'wb') as f:
            f.write(sg.to_bytes())
        print(f"Exported to {args.export}")
    else:
        parser.print_help()


if __name__ == "__main__":
    main()
