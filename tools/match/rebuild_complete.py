#!/usr/bin/env python3
"""Build data, code and the complete PE from prepared source and bound C objects.

Use run_source_only.py for a reference-read guard. The reference comparison is
a separate command, verify_complete_image.py. Preparing source is not rebuilding.
"""
import argparse
from pathlib import Path
import pe_data_source
import text_build
import pe_link

ROOT=Path(__file__).resolve().parents[2]


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root',type=Path,default=ROOT)
    parser.add_argument('--output',type=Path,default=ROOT/'recon/ffx/complete')
    parser.add_argument('--link-only',action='store_true',
                        help='Replay the link from validated retained objects for independent acceptance')
    args=parser.parse_args()
    root=args.root.resolve()
    if not args.link_only:
        pe_data_source.build(root/'recon/ffx/pe_data')
        text_build.build(root,root/'recon/ffx/text_program',root/'recon/ffx/text_program/build')
    pe_link.link(root,args.output)


if __name__=='__main__': main()
