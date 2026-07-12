
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7a00b0","include_decompile":true,"include_proto":true},{"addr":"0x7a00d0","include_decompile":true,"include_proto":true},{"addr":"0x7a00f0","include_decompile":true,"include_proto":true},{"addr":"0x7a0120","include_decompile":true,"include_proto":true},{"addr":"0x7a0160","include_decompile":true,"include_proto":true},{"addr":"0x7a0190","include_decompile":true,"include_proto":true},{"addr":"0x7a01d0","include_decompile":true,"include_proto":true},{"addr":"0x7a0390","include_decompile":true,"include_proto":true},{"addr":"0x7a0420","include_decompile":true,"include_proto":true},{"addr":"0x7a04d0","include_decompile":true,"include_proto":true},{"addr":"0x7a04e0","include_decompile":true,"include_proto":true},{"addr":"0x7a04f0","include_decompile":true,"include_proto":true},{"addr":"0x7a0520","include_decompile":true,"include_proto":true},{"addr":"0x7a0560","include_decompile":true,"include_proto":true},{"addr":"0x7a06d0","include_decompile":true,"include_proto":true},{"addr":"0x7a0740","include_decompile":true,"include_proto":true},{"addr":"0x7a07d0","include_decompile":true,"include_proto":true},{"addr":"0x7a0840","include_decompile":true,"include_proto":true},{"addr":"0x7a08c0","include_decompile":true,"include_proto":true},{"addr":"0x7a0900","include_decompile":true,"include_proto":true},{"addr":"0x7a0930","include_decompile":true,"include_proto":true},{"addr":"0x7a0950","include_decompile":true,"include_proto":true},{"addr":"0x7a0a50","include_decompile":true,"include_proto":true},{"addr":"0x7a0bb0","include_decompile":true,"include_proto":true},{"addr":"0x7a0bd0","include_decompile":true,"include_proto":true},{"addr":"0x7a0c40","include_decompile":true,"include_proto":true},{"addr":"0x7a0c70","include_decompile":true,"include_proto":true},{"addr":"0x7a0cd0","include_decompile":true,"include_proto":true},{"addr":"0x7a0cf0","include_decompile":true,"include_proto":true},{"addr":"0x7a0d10","include_decompile":true,"include_proto":true},{"addr":"0x7a2620","include_decompile":true,"include_proto":true},{"addr":"0x7a2690","include_decompile":true,"include_proto":true},{"addr":"0x7a26b0","include_decompile":true,"include_proto":true},{"addr":"0x7a2750","include_decompile":true,"include_proto":true},{"addr":"0x7a2770","include_decompile":true,"include_proto":true},{"addr":"0x7a27a0","include_decompile":true,"include_proto":true},{"addr":"0x7a2800","include_decompile":true,"include_proto":true},{"addr":"0x7a29a0","include_decompile":true,"include_proto":true},{"addr":"0x7a29c0","include_decompile":true,"include_proto":true},{"addr":"0x7a2a10","include_decompile":true,"include_proto":true},{"addr":"0x7a2a40","include_decompile":true,"include_proto":true},{"addr":"0x7a2aa0","include_decompile":true,"include_proto":true},{"addr":"0x7a2af0","include_decompile":true,"include_proto":true},{"addr":"0x7a2b30","include_decompile":true,"include_proto":true},{"addr":"0x7a2b70","include_decompile":true,"include_proto":true},{"addr":"0x7a2bc0","include_decompile":true,"include_proto":true},{"addr":"0x7a2c30","include_decompile":true,"include_proto":true},{"addr":"0x7a2c70","include_decompile":true,"include_proto":true},{"addr":"0x7a2c90","include_decompile":true,"include_proto":true},{"addr":"0x7a2cc0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0178', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0178: empty response'); return; }
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
      console.log('Batch 0178: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0178 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0178 conn error:', e.message));
req.write(body);
req.end();
