
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6a5440","include_decompile":true,"include_proto":true},{"addr":"0x6a5530","include_decompile":true,"include_proto":true},{"addr":"0x6a5b20","include_decompile":true,"include_proto":true},{"addr":"0x6a6010","include_decompile":true,"include_proto":true},{"addr":"0x6a6060","include_decompile":true,"include_proto":true},{"addr":"0x6a6110","include_decompile":true,"include_proto":true},{"addr":"0x6a6190","include_decompile":true,"include_proto":true},{"addr":"0x6a6250","include_decompile":true,"include_proto":true},{"addr":"0x6a62c0","include_decompile":true,"include_proto":true},{"addr":"0x6a6330","include_decompile":true,"include_proto":true},{"addr":"0x6a63a0","include_decompile":true,"include_proto":true},{"addr":"0x6a6540","include_decompile":true,"include_proto":true},{"addr":"0x6a6750","include_decompile":true,"include_proto":true},{"addr":"0x6a6760","include_decompile":true,"include_proto":true},{"addr":"0x6a6870","include_decompile":true,"include_proto":true},{"addr":"0x6a68d0","include_decompile":true,"include_proto":true},{"addr":"0x6a6930","include_decompile":true,"include_proto":true},{"addr":"0x6a69b0","include_decompile":true,"include_proto":true},{"addr":"0x6a69c0","include_decompile":true,"include_proto":true},{"addr":"0x6a6a40","include_decompile":true,"include_proto":true},{"addr":"0x6a6ad0","include_decompile":true,"include_proto":true},{"addr":"0x6a6ae0","include_decompile":true,"include_proto":true},{"addr":"0x6a6af0","include_decompile":true,"include_proto":true},{"addr":"0x6a6b00","include_decompile":true,"include_proto":true},{"addr":"0x6a6bf0","include_decompile":true,"include_proto":true},{"addr":"0x6a6d00","include_decompile":true,"include_proto":true},{"addr":"0x6a6e20","include_decompile":true,"include_proto":true},{"addr":"0x6a6ea0","include_decompile":true,"include_proto":true},{"addr":"0x6a6f20","include_decompile":true,"include_proto":true},{"addr":"0x6a6f50","include_decompile":true,"include_proto":true},{"addr":"0x6a6f80","include_decompile":true,"include_proto":true},{"addr":"0x6a6f90","include_decompile":true,"include_proto":true},{"addr":"0x6a6fe0","include_decompile":true,"include_proto":true},{"addr":"0x6a73d0","include_decompile":true,"include_proto":true},{"addr":"0x6a76a0","include_decompile":true,"include_proto":true},{"addr":"0x6a78f0","include_decompile":true,"include_proto":true},{"addr":"0x6a7930","include_decompile":true,"include_proto":true},{"addr":"0x6a7940","include_decompile":true,"include_proto":true},{"addr":"0x6a79a0","include_decompile":true,"include_proto":true},{"addr":"0x6a8360","include_decompile":true,"include_proto":true},{"addr":"0x6a8560","include_decompile":true,"include_proto":true},{"addr":"0x6a8570","include_decompile":true,"include_proto":true},{"addr":"0x6a8580","include_decompile":true,"include_proto":true},{"addr":"0x6a8590","include_decompile":true,"include_proto":true},{"addr":"0x6a8620","include_decompile":true,"include_proto":true},{"addr":"0x6a86d0","include_decompile":true,"include_proto":true},{"addr":"0x6a8c90","include_decompile":true,"include_proto":true},{"addr":"0x6a8d10","include_decompile":true,"include_proto":true},{"addr":"0x6a8d90","include_decompile":true,"include_proto":true},{"addr":"0x6a8e50","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0088', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0088: empty response'); return; }
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
      console.log('Batch 0088: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0088 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0088 conn error:', e.message));
req.write(body);
req.end();
