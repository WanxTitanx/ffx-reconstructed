const fs = require('fs');
const path = require('path');
const OUT = 'C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\pseudocode\\range_600000_800000';
const results = JSON.parse(fs.readFileSync(path.join(OUT, 'batch0_full.json'), 'utf8')).result;
const S = /[<>:"\\\/|?*@&$!#(){}]/g;
let ok = 0;
for (const r of results) {
  if (!r || !r.addr) continue;
  const addr = r.addr.replace('0x', '');
  const name = (r.name || 'unk').replace(S, '_').replace(/__+/g, '_');
  const proto = r.analysis?.prototype || '';
  const sz = r.analysis?.size || '0';
  let dec = r.analysis?.decompile || '';
  let c = '// Function: ' + r.name + '\n// Address: ' + r.addr + '\n// Size: ' + sz + '\n';
  if (proto) c += '// Prototype: ' + proto + '\n';
  c += '\n' + dec;
  if (!dec.endsWith('\n')) c += '\n';
  try { fs.writeFileSync(path.join(OUT, addr + '_' + name + '.c'), c); ok++; } catch (e) {}
}
console.log('Saved ' + ok + ' files');
