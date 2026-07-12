const fs = require('fs');
const path = require('path');
const funcs = JSON.parse(fs.readFileSync(
  'C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\pseudocode\\range_600000_800000\\filtered_funcs.json','utf8'));
const BATCH = 50;
const outDir = 'C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\pseudocode\\range_600000_800000';
const PORT = 52029;

for (let i = 0; i < funcs.length; i += BATCH) {
  const batch = funcs.slice(i, Math.min(i + BATCH, funcs.length));
  const idx = String(Math.floor(i/BATCH)).padStart(4,'0');
  
  const scriptContent = `
import http from 'http';
import fs from 'fs';
const queries = ${JSON.stringify(batch.map(f => ({addr: f.addr, include_decompile: true, include_proto: true})))};
const body = JSON.stringify({jsonrpc:'2.0', id:'b${idx}', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:${PORT}, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch ${idx}: empty response'); return; }
      const results = JSON.parse(text);
      let count = 0;
      for (const r of results) {
        if (!r || !r.addr) continue;
        const name = r.name || 'unknown';
        const sname = name.replace(/[<>:"\\\\\\/|?*@&$!#(){}]/g,'_').replace(/__+/g,'_');
        const addr = r.addr.replace('0x','');
        const proto = r.analysis?.prototype || '';
        const size = r.analysis?.size || '0';
        let decomp = r.analysis?.decompile || '';
        let content = '// Function: ' + name + '\\n// Address: ' + r.addr + '\\n// Size: ' + size + '\\n';
        if (proto) content += '// Prototype: ' + proto + '\\n';
        content += '\\n';
        if (decomp) { content += decomp; if (!decomp.endsWith('\\n')) content += '\\n'; }
        else content += '// No decompilation available\\n';
        const fname = addr + '_' + sname + '.c';
        try {
          fs.writeFileSync('${outDir.replace(/\\\\/g,'\\\\\\\\')}\\\\' + fname, content);
          count++;
        } catch(e) { console.log('Write error for', fname, e.message); }
      }
      console.log('Batch ${idx}: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch ${idx} error:', e.message); }
  });
});
req.on('error', e => console.log('Batch ${idx} conn error:', e.message));
req.write(body);
req.end();
`;
  const filePath = path.join(outDir, 'run_batch_' + idx + '.mjs');
  fs.writeFileSync(filePath, scriptContent);
}
console.log('Generated ' + Math.ceil(funcs.length/BATCH) + ' batch scripts');
