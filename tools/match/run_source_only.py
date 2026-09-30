#!/usr/bin/env python3
"""Run a build command with reads of the original executable explicitly forbidden."""
import builtins
import io
import os
from pathlib import Path
import runpy
import sys
from unittest.mock import patch

ORIGINAL=Path('/home/wanderson/Documents/ffx-editor-main/work/_ppp_pool/FFX.exe').resolve()


def guarded(function):
    def checked(file,*args,**kwargs):
        if not isinstance(file,int):
            try:
                path=Path(os.fsdecode(file)).resolve()
            except (TypeError,ValueError):
                path=None
            if path==ORIGINAL:
                raise RuntimeError('SOURCE-ONLY BUILD: reference executable read is forbidden')
        return function(file,*args,**kwargs)
    return checked


def main():
    if len(sys.argv)<2: raise ValueError('supply a build script and arguments')
    script=Path(sys.argv[1]).resolve()
    sys.argv=sys.argv[1:]
    with patch.object(builtins,'open',guarded(builtins.open)),patch.object(io,'open',guarded(io.open)):
        runpy.run_path(str(script),run_name='__main__')


if __name__=='__main__': main()
