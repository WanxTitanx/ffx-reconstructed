
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6e31f0","include_decompile":true,"include_proto":true},{"addr":"0x6e32c0","include_decompile":true,"include_proto":true},{"addr":"0x6e32f0","include_decompile":true,"include_proto":true},{"addr":"0x6e3300","include_decompile":true,"include_proto":true},{"addr":"0x6e3370","include_decompile":true,"include_proto":true},{"addr":"0x6e33d0","include_decompile":true,"include_proto":true},{"addr":"0x6e33f0","include_decompile":true,"include_proto":true},{"addr":"0x6e3450","include_decompile":true,"include_proto":true},{"addr":"0x6e3520","include_decompile":true,"include_proto":true},{"addr":"0x6e3530","include_decompile":true,"include_proto":true},{"addr":"0x6e35b0","include_decompile":true,"include_proto":true},{"addr":"0x6e3620","include_decompile":true,"include_proto":true},{"addr":"0x6e36f0","include_decompile":true,"include_proto":true},{"addr":"0x6e37f0","include_decompile":true,"include_proto":true},{"addr":"0x6e3820","include_decompile":true,"include_proto":true},{"addr":"0x6e3890","include_decompile":true,"include_proto":true},{"addr":"0x6e3900","include_decompile":true,"include_proto":true},{"addr":"0x6e3b60","include_decompile":true,"include_proto":true},{"addr":"0x6e3bd0","include_decompile":true,"include_proto":true},{"addr":"0x6e3c40","include_decompile":true,"include_proto":true},{"addr":"0x6e3cb0","include_decompile":true,"include_proto":true},{"addr":"0x6e4040","include_decompile":true,"include_proto":true},{"addr":"0x6e4070","include_decompile":true,"include_proto":true},{"addr":"0x6e4140","include_decompile":true,"include_proto":true},{"addr":"0x6e4150","include_decompile":true,"include_proto":true},{"addr":"0x6e41e0","include_decompile":true,"include_proto":true},{"addr":"0x6e4230","include_decompile":true,"include_proto":true},{"addr":"0x6e45a0","include_decompile":true,"include_proto":true},{"addr":"0x6e4710","include_decompile":true,"include_proto":true},{"addr":"0x6e4880","include_decompile":true,"include_proto":true},{"addr":"0x6e4890","include_decompile":true,"include_proto":true},{"addr":"0x6e48a0","include_decompile":true,"include_proto":true},{"addr":"0x6e4a50","include_decompile":true,"include_proto":true},{"addr":"0x6e4fd0","include_decompile":true,"include_proto":true},{"addr":"0x6e5100","include_decompile":true,"include_proto":true},{"addr":"0x6e5120","include_decompile":true,"include_proto":true},{"addr":"0x6e5150","include_decompile":true,"include_proto":true},{"addr":"0x6e51d0","include_decompile":true,"include_proto":true},{"addr":"0x6e54c0","include_decompile":true,"include_proto":true},{"addr":"0x6e54d0","include_decompile":true,"include_proto":true},{"addr":"0x6e54e0","include_decompile":true,"include_proto":true},{"addr":"0x6e54f0","include_decompile":true,"include_proto":true},{"addr":"0x6e55c0","include_decompile":true,"include_proto":true},{"addr":"0x6e55e0","include_decompile":true,"include_proto":true},{"addr":"0x6e5700","include_decompile":true,"include_proto":true},{"addr":"0x6e5710","include_decompile":true,"include_proto":true},{"addr":"0x6e57c0","include_decompile":true,"include_proto":true},{"addr":"0x6e57d0","include_decompile":true,"include_proto":true},{"addr":"0x6e5800","include_decompile":true,"include_proto":true},{"addr":"0x6e5870","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0110', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0110: empty response'); return; }
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
      console.log('Batch 0110: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0110 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0110 conn error:', e.message));
req.write(body);
req.end();
