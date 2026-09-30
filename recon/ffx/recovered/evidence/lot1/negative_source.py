"""Run the plan's live no-fallback test, restoring only this task's own edit."""
from pathlib import Path
import hashlib
import json
import subprocess

root = Path.cwd()
python = '/mnt/ssd-kingston/ffx-reconstructed/work/cos-byteproof-41719/recon/ffx/.venv-asm/bin/python'
source = root/'recon/ffx/recovered/src/math/vec3_normalize.c'
original = source.read_bytes()
assert original.count(b'1.0 / length') == 1
altered = original.replace(b'1.0 / length', b'2.0 / length')
output = root/'work/cpp-recovery-41520/negative-live-text'
assert not output.exists()
command = [python, '-B', 'tools/match/text_build.py', '--output', str(output)]
try:
    source.write_bytes(altered)
    process = subprocess.run(command, capture_output=True, timeout=90)
    log = process.stdout+process.stderr
    (root/'work/cpp-recovery-41520/negative-live-text.log').write_bytes(log)
    assert process.returncode != 0, 'changed source was silently accepted'
    assert b'changed after compilation' in log, log.decode(errors='replace')
finally:
    if source.read_bytes() != altered:
        raise RuntimeError('another edit appeared; refusing to overwrite it')
    source.write_bytes(original)
assert source.read_bytes() == original
report = {'test': 'active source constant mutation blocks actual text_build',
          'command': command, 'exit_code': process.returncode,
          'source_sha256_before': hashlib.sha256(original).hexdigest(),
          'mutated_source_sha256': hashlib.sha256(altered).hexdigest(),
          'source_restored_exactly': True, 'silent_assembly_fallback': False,
          'log_sha256': hashlib.sha256(log).hexdigest(),
          'scope': 'real build rejected stale source before emitting the changed provider'}
(root/'recon/ffx/recovered/proofs/no-fallback.json').write_text(json.dumps(report, indent=2)+'\n')
print(json.dumps(report, indent=2))
