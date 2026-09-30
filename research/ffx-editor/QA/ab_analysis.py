#!/usr/bin/env python3
"""ab_analysis.py - A/B comparison Linux baseline vs Windows VM run for FFXResearchTools.

(QA-WINDOWS lane FFX-STRUCTURES, 2026-09-14)
Reads the Linux TRX (reproduced baseline: 1332/1139p/192f/1ne) and a Windows TRX,
joins by fully-qualified test name, and classifies each outcome pair into families.
"""
import xml.etree.ElementTree as ET
from collections import Counter, defaultdict

NS = '{http://microsoft.com/schemas/VisualStudio/TeamTest/2010}'
LINUX_TRX = '/home/wanderson/Documents/ffx-editor-main/work/_qa_win/qa-linux-baseline-local.trx'
WIN_TRX = '/home/wanderson/Documents/ffx-editor-main/work/_qa_win/qa-win5.trx'


def load(path):
    root = ET.parse(path).getroot()
    results = {}
    for ut in root.iter(NS + 'UnitTestResult'):
        name = ut.get('testName')
        outcome = ut.get('outcome')
        msg = ''
        node = ut.find(f'.//{NS}Message')
        if node is not None and node.text:
            msg = ' '.join(node.text.strip().split())[:300]
        results[name] = (outcome, msg)
    return results


def family(name: str, msg: str) -> str:
    lower = (name + ' ' + msg).lower()
    if 'windows final-path identity is unavailable' in lower:
        return 'WindowsPathIdentity(direct)'
    if 'ext4' in lower or 'f_type' in lower:
        return 'ext4 f_type'
    if 'jsonschema' in lower or 'modulenotfounderror' in lower or 'draft 2020-12' in lower:
        return 'python/jsonschema'
    if 'repository root not found' in lower or 'ffxprojecteditor.sln' in lower:
        return 'repo-context'
    return 'other'


def main():
    linux = load(LINUX_TRX)
    win = load(WIN_TRX)
    print(f'linux tests={len(linux)} outcomes={Counter(v[0] for v in linux.values())}')
    print(f'win   tests={len(win)} outcomes={Counter(v[0] for v in win.values())}')

    lfail = {n for n, v in linux.items() if v[0] == 'Failed'}
    wfail = {n for n, v in win.items() if v[0] == 'Failed'}
    wskip = {n for n, v in win.items() if v[0] in ('NotExecuted', 'Skipped')}

    only_linux = set(linux) - set(win)
    only_win = set(win) - set(linux)

    print('\n== TESTS ONLY IN LINUX (not discovered on Windows):', len(only_linux))
    fam = Counter(family(n, linux[n][1]) for n in only_linux)
    print('  by family:', dict(fam))

    print('\n== TESTS ONLY IN WINDOWS (not discovered on Linux):', len(only_win))
    for n in sorted(only_win)[:10]:
        print('  -', n)

    a_b = Counter()
    detail = defaultdict(list)
    for n in sorted(set(linux) & set(win)):
        lo, lm = linux[n]
        wo, wm = win[n]
        key = f'L:{lo[:4]}->W:{wo[:4]}'
        a_b[key] += 1
        detail[key].append((n, lm, wm))

    print('\n== OUTCOME TRANSITIONS (common tests) ==')
    for k, v in sorted(a_b.items(), key=lambda x: -x[1]):
        print(f'  {k}: {v}')

    print('\n== Linux FAILED -> Windows PASSED (the Windows-bound family):',
          a_b.get('L:Fail->W:Pass', 0))
    print('== Linux FAILED -> Windows FAILED (both platforms fail):',
          a_b.get('L:Fail->W:Fail', 0))
    ff = detail.get('L:Fail->W:Fail', [])
    famff = Counter(family(n, wm) for n, _, wm in ff)
    print('  both-fail by family:', dict(famff))
    for n, lm, wm in ff:
        print(f'  BOTH-FAIL: {n}')
        print(f'    L: {lm[:220]}')
        print(f'    W: {wm[:220]}')

    print('\n== Linux PASSED -> Windows FAILED:', a_b.get('L:Pass->W:Fail', 0))
    for n, lm, wm in detail.get('L:Pass->W:Fail', []):
        print(f'  REGRESSION?: {n}')
        print(f'    W: {wm[:220]}')

    print('\n== Linux PASSED -> Windows SKIPPED:', a_b.get('L:Pass->W:Not', 0))
    sk = detail.get('L:Pass->W:Not', [])
    famsk = Counter(family(n, wm) for n, _, wm in sk)
    print('  skip by family:', dict(famsk))
    for n, _, wm in sk[:15]:
        print(f'  SKIP: {n} | {wm[:160]}')

    with open('/home/wanderson/Documents/ffx-editor-main/work/_qa_win/ab_full_detail.txt', 'w') as f:
        for key, rows in sorted(detail.items()):
            f.write(f'##### {key} ({len(rows)}) #####\n')
            for n, lm, wm in rows:
                f.write(f'{n}\n  L: {lm}\n  W: {wm}\n')
            f.write('\n')
    print('\nwrote ab_full_detail.txt')


if __name__ == '__main__':
    main()
