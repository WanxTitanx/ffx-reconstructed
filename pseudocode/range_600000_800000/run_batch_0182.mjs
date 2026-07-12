
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7a5bb0","include_decompile":true,"include_proto":true},{"addr":"0x7a5be0","include_decompile":true,"include_proto":true},{"addr":"0x7a5c10","include_decompile":true,"include_proto":true},{"addr":"0x7a5c40","include_decompile":true,"include_proto":true},{"addr":"0x7a5cd0","include_decompile":true,"include_proto":true},{"addr":"0x7a5d10","include_decompile":true,"include_proto":true},{"addr":"0x7a5d80","include_decompile":true,"include_proto":true},{"addr":"0x7a5da0","include_decompile":true,"include_proto":true},{"addr":"0x7a5de0","include_decompile":true,"include_proto":true},{"addr":"0x7a5e10","include_decompile":true,"include_proto":true},{"addr":"0x7a5e70","include_decompile":true,"include_proto":true},{"addr":"0x7a5eb0","include_decompile":true,"include_proto":true},{"addr":"0x7a5ee0","include_decompile":true,"include_proto":true},{"addr":"0x7a5ef0","include_decompile":true,"include_proto":true},{"addr":"0x7a5f30","include_decompile":true,"include_proto":true},{"addr":"0x7a5fa0","include_decompile":true,"include_proto":true},{"addr":"0x7a5fe0","include_decompile":true,"include_proto":true},{"addr":"0x7a6050","include_decompile":true,"include_proto":true},{"addr":"0x7a6080","include_decompile":true,"include_proto":true},{"addr":"0x7a6110","include_decompile":true,"include_proto":true},{"addr":"0x7a6150","include_decompile":true,"include_proto":true},{"addr":"0x7a6190","include_decompile":true,"include_proto":true},{"addr":"0x7a61f0","include_decompile":true,"include_proto":true},{"addr":"0x7a6220","include_decompile":true,"include_proto":true},{"addr":"0x7a62c0","include_decompile":true,"include_proto":true},{"addr":"0x7a62f0","include_decompile":true,"include_proto":true},{"addr":"0x7a6320","include_decompile":true,"include_proto":true},{"addr":"0x7a6350","include_decompile":true,"include_proto":true},{"addr":"0x7a63b0","include_decompile":true,"include_proto":true},{"addr":"0x7a63f0","include_decompile":true,"include_proto":true},{"addr":"0x7a6410","include_decompile":true,"include_proto":true},{"addr":"0x7a64e0","include_decompile":true,"include_proto":true},{"addr":"0x7a6510","include_decompile":true,"include_proto":true},{"addr":"0x7a6560","include_decompile":true,"include_proto":true},{"addr":"0x7a65c0","include_decompile":true,"include_proto":true},{"addr":"0x7a65f0","include_decompile":true,"include_proto":true},{"addr":"0x7a6620","include_decompile":true,"include_proto":true},{"addr":"0x7a6660","include_decompile":true,"include_proto":true},{"addr":"0x7a66c0","include_decompile":true,"include_proto":true},{"addr":"0x7a6720","include_decompile":true,"include_proto":true},{"addr":"0x7a6750","include_decompile":true,"include_proto":true},{"addr":"0x7a6780","include_decompile":true,"include_proto":true},{"addr":"0x7a67b0","include_decompile":true,"include_proto":true},{"addr":"0x7a6820","include_decompile":true,"include_proto":true},{"addr":"0x7a6890","include_decompile":true,"include_proto":true},{"addr":"0x7a6950","include_decompile":true,"include_proto":true},{"addr":"0x7a6970","include_decompile":true,"include_proto":true},{"addr":"0x7a6980","include_decompile":true,"include_proto":true},{"addr":"0x7a6990","include_decompile":true,"include_proto":true},{"addr":"0x7a6a30","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0182', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0182: empty response'); return; }
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
      console.log('Batch 0182: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0182 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0182 conn error:', e.message));
req.write(body);
req.end();
