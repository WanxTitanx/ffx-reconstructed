
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7cf470","include_decompile":true,"include_proto":true},{"addr":"0x7cf4c0","include_decompile":true,"include_proto":true},{"addr":"0x7cf570","include_decompile":true,"include_proto":true},{"addr":"0x7cf5f0","include_decompile":true,"include_proto":true},{"addr":"0x7cf6b0","include_decompile":true,"include_proto":true},{"addr":"0x7cf790","include_decompile":true,"include_proto":true},{"addr":"0x7cf820","include_decompile":true,"include_proto":true},{"addr":"0x7cf8a0","include_decompile":true,"include_proto":true},{"addr":"0x7cf9d0","include_decompile":true,"include_proto":true},{"addr":"0x7cfa50","include_decompile":true,"include_proto":true},{"addr":"0x7cfa90","include_decompile":true,"include_proto":true},{"addr":"0x7cfad0","include_decompile":true,"include_proto":true},{"addr":"0x7cfbd0","include_decompile":true,"include_proto":true},{"addr":"0x7cfc00","include_decompile":true,"include_proto":true},{"addr":"0x7d0a20","include_decompile":true,"include_proto":true},{"addr":"0x7d0bc0","include_decompile":true,"include_proto":true},{"addr":"0x7d0e10","include_decompile":true,"include_proto":true},{"addr":"0x7d0f60","include_decompile":true,"include_proto":true},{"addr":"0x7d0ff0","include_decompile":true,"include_proto":true},{"addr":"0x7d1150","include_decompile":true,"include_proto":true},{"addr":"0x7d11d0","include_decompile":true,"include_proto":true},{"addr":"0x7d1230","include_decompile":true,"include_proto":true},{"addr":"0x7d1420","include_decompile":true,"include_proto":true},{"addr":"0x7d16c0","include_decompile":true,"include_proto":true},{"addr":"0x7d1870","include_decompile":true,"include_proto":true},{"addr":"0x7d1b00","include_decompile":true,"include_proto":true},{"addr":"0x7d1e80","include_decompile":true,"include_proto":true},{"addr":"0x7d2300","include_decompile":true,"include_proto":true},{"addr":"0x7d2340","include_decompile":true,"include_proto":true},{"addr":"0x7d2350","include_decompile":true,"include_proto":true},{"addr":"0x7d2360","include_decompile":true,"include_proto":true},{"addr":"0x7d2e40","include_decompile":true,"include_proto":true},{"addr":"0x7d2e80","include_decompile":true,"include_proto":true},{"addr":"0x7d2ef0","include_decompile":true,"include_proto":true},{"addr":"0x7d3350","include_decompile":true,"include_proto":true},{"addr":"0x7d33d0","include_decompile":true,"include_proto":true},{"addr":"0x7d35e0","include_decompile":true,"include_proto":true},{"addr":"0x7d3630","include_decompile":true,"include_proto":true},{"addr":"0x7d37f0","include_decompile":true,"include_proto":true},{"addr":"0x7d3e70","include_decompile":true,"include_proto":true},{"addr":"0x7d4210","include_decompile":true,"include_proto":true},{"addr":"0x7d4220","include_decompile":true,"include_proto":true},{"addr":"0x7d43d0","include_decompile":true,"include_proto":true},{"addr":"0x7d53b0","include_decompile":true,"include_proto":true},{"addr":"0x7d61f0","include_decompile":true,"include_proto":true},{"addr":"0x7d6370","include_decompile":true,"include_proto":true},{"addr":"0x7d63a0","include_decompile":true,"include_proto":true},{"addr":"0x7d6460","include_decompile":true,"include_proto":true},{"addr":"0x7d6600","include_decompile":true,"include_proto":true},{"addr":"0x7d6780","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0197', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0197: empty response'); return; }
      const results = JSON.parse(text);
      let count = 0;
      for (const r of results) {
        if (!r || !r.addr) continue;
        const name = r.name || 'unknown';
        const sname = name.replace(/[<>:"\\\/|?*@&$!#(){}]/g,'_').replace(/__+/g,'_');
        const addr = r.addr.replace('0x','');
        const proto = r.analysis?.prototype || '';
        const size = r.analysis?.size || '0';
        let decomp = r.analysis?.decompile || '';
        let content = '// Function: ' + name + '\n// Address: ' + r.addr + '\n// Size: ' + size + '\n';
        if (proto) content += '// Prototype: ' + proto + '\n';
        content += '\n';
        if (decomp) { content += decomp; if (!decomp.endsWith('\n')) content += '\n'; }
        else content += '// No decompilation available\n';
        const fname = addr + '_' + sname + '.c';
        try {
          fs.writeFileSync('C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_600000_800000\\' + fname, content);
          count++;
        } catch(e) { console.log('Write error for', fname, e.message); }
      }
      console.log('Batch 0197: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0197 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0197 conn error:', e.message));
req.write(body);
req.end();
