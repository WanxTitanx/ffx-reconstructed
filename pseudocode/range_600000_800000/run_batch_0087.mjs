
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6a24b0","include_decompile":true,"include_proto":true},{"addr":"0x6a24d0","include_decompile":true,"include_proto":true},{"addr":"0x6a2720","include_decompile":true,"include_proto":true},{"addr":"0x6a27b0","include_decompile":true,"include_proto":true},{"addr":"0x6a2840","include_decompile":true,"include_proto":true},{"addr":"0x6a28d0","include_decompile":true,"include_proto":true},{"addr":"0x6a2970","include_decompile":true,"include_proto":true},{"addr":"0x6a29f0","include_decompile":true,"include_proto":true},{"addr":"0x6a2ae0","include_decompile":true,"include_proto":true},{"addr":"0x6a2af0","include_decompile":true,"include_proto":true},{"addr":"0x6a2b00","include_decompile":true,"include_proto":true},{"addr":"0x6a2b90","include_decompile":true,"include_proto":true},{"addr":"0x6a2ba0","include_decompile":true,"include_proto":true},{"addr":"0x6a2bb0","include_decompile":true,"include_proto":true},{"addr":"0x6a2bc0","include_decompile":true,"include_proto":true},{"addr":"0x6a2bd0","include_decompile":true,"include_proto":true},{"addr":"0x6a2be0","include_decompile":true,"include_proto":true},{"addr":"0x6a2bf0","include_decompile":true,"include_proto":true},{"addr":"0x6a2c00","include_decompile":true,"include_proto":true},{"addr":"0x6a2c10","include_decompile":true,"include_proto":true},{"addr":"0x6a2c20","include_decompile":true,"include_proto":true},{"addr":"0x6a2c30","include_decompile":true,"include_proto":true},{"addr":"0x6a2c40","include_decompile":true,"include_proto":true},{"addr":"0x6a2c50","include_decompile":true,"include_proto":true},{"addr":"0x6a2c60","include_decompile":true,"include_proto":true},{"addr":"0x6a2cd0","include_decompile":true,"include_proto":true},{"addr":"0x6a2da0","include_decompile":true,"include_proto":true},{"addr":"0x6a2f80","include_decompile":true,"include_proto":true},{"addr":"0x6a2fa0","include_decompile":true,"include_proto":true},{"addr":"0x6a3110","include_decompile":true,"include_proto":true},{"addr":"0x6a3210","include_decompile":true,"include_proto":true},{"addr":"0x6a3240","include_decompile":true,"include_proto":true},{"addr":"0x6a3880","include_decompile":true,"include_proto":true},{"addr":"0x6a3930","include_decompile":true,"include_proto":true},{"addr":"0x6a3b40","include_decompile":true,"include_proto":true},{"addr":"0x6a3b60","include_decompile":true,"include_proto":true},{"addr":"0x6a3c60","include_decompile":true,"include_proto":true},{"addr":"0x6a3c70","include_decompile":true,"include_proto":true},{"addr":"0x6a3c80","include_decompile":true,"include_proto":true},{"addr":"0x6a3ca0","include_decompile":true,"include_proto":true},{"addr":"0x6a4390","include_decompile":true,"include_proto":true},{"addr":"0x6a4620","include_decompile":true,"include_proto":true},{"addr":"0x6a4810","include_decompile":true,"include_proto":true},{"addr":"0x6a4830","include_decompile":true,"include_proto":true},{"addr":"0x6a4950","include_decompile":true,"include_proto":true},{"addr":"0x6a4a20","include_decompile":true,"include_proto":true},{"addr":"0x6a4b30","include_decompile":true,"include_proto":true},{"addr":"0x6a4b50","include_decompile":true,"include_proto":true},{"addr":"0x6a4ba0","include_decompile":true,"include_proto":true},{"addr":"0x6a51c0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0087', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0087: empty response'); return; }
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
      console.log('Batch 0087: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0087 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0087 conn error:', e.message));
req.write(body);
req.end();
