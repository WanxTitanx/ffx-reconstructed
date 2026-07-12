
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6c2060","include_decompile":true,"include_proto":true},{"addr":"0x6c2150","include_decompile":true,"include_proto":true},{"addr":"0x6c2200","include_decompile":true,"include_proto":true},{"addr":"0x6c2260","include_decompile":true,"include_proto":true},{"addr":"0x6c22d0","include_decompile":true,"include_proto":true},{"addr":"0x6c2350","include_decompile":true,"include_proto":true},{"addr":"0x6c23d0","include_decompile":true,"include_proto":true},{"addr":"0x6c2490","include_decompile":true,"include_proto":true},{"addr":"0x6c2550","include_decompile":true,"include_proto":true},{"addr":"0x6c25f0","include_decompile":true,"include_proto":true},{"addr":"0x6c2660","include_decompile":true,"include_proto":true},{"addr":"0x6c27f0","include_decompile":true,"include_proto":true},{"addr":"0x6c2800","include_decompile":true,"include_proto":true},{"addr":"0x6c2810","include_decompile":true,"include_proto":true},{"addr":"0x6c2820","include_decompile":true,"include_proto":true},{"addr":"0x6c2830","include_decompile":true,"include_proto":true},{"addr":"0x6c2840","include_decompile":true,"include_proto":true},{"addr":"0x6c2850","include_decompile":true,"include_proto":true},{"addr":"0x6c29e0","include_decompile":true,"include_proto":true},{"addr":"0x6c29f0","include_decompile":true,"include_proto":true},{"addr":"0x6c2a20","include_decompile":true,"include_proto":true},{"addr":"0x6c2ad0","include_decompile":true,"include_proto":true},{"addr":"0x6c2cf0","include_decompile":true,"include_proto":true},{"addr":"0x6c2de0","include_decompile":true,"include_proto":true},{"addr":"0x6c2f00","include_decompile":true,"include_proto":true},{"addr":"0x6c3110","include_decompile":true,"include_proto":true},{"addr":"0x6c3130","include_decompile":true,"include_proto":true},{"addr":"0x6c3300","include_decompile":true,"include_proto":true},{"addr":"0x6c3370","include_decompile":true,"include_proto":true},{"addr":"0x6c3380","include_decompile":true,"include_proto":true},{"addr":"0x6c3410","include_decompile":true,"include_proto":true},{"addr":"0x6c3560","include_decompile":true,"include_proto":true},{"addr":"0x6c3610","include_decompile":true,"include_proto":true},{"addr":"0x6c3690","include_decompile":true,"include_proto":true},{"addr":"0x6c36c0","include_decompile":true,"include_proto":true},{"addr":"0x6c3700","include_decompile":true,"include_proto":true},{"addr":"0x6c3710","include_decompile":true,"include_proto":true},{"addr":"0x6c39c0","include_decompile":true,"include_proto":true},{"addr":"0x6c39d0","include_decompile":true,"include_proto":true},{"addr":"0x6c39e0","include_decompile":true,"include_proto":true},{"addr":"0x6c39f0","include_decompile":true,"include_proto":true},{"addr":"0x6c3a80","include_decompile":true,"include_proto":true},{"addr":"0x6c3a90","include_decompile":true,"include_proto":true},{"addr":"0x6c3ab0","include_decompile":true,"include_proto":true},{"addr":"0x6c3d80","include_decompile":true,"include_proto":true},{"addr":"0x6c3e00","include_decompile":true,"include_proto":true},{"addr":"0x6c3e10","include_decompile":true,"include_proto":true},{"addr":"0x6c3e80","include_decompile":true,"include_proto":true},{"addr":"0x6c4110","include_decompile":true,"include_proto":true},{"addr":"0x6c4160","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0098', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0098: empty response'); return; }
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
      console.log('Batch 0098: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0098 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0098 conn error:', e.message));
req.write(body);
req.end();
