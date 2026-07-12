
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7b80b0","include_decompile":true,"include_proto":true},{"addr":"0x7b80d0","include_decompile":true,"include_proto":true},{"addr":"0x7b80f0","include_decompile":true,"include_proto":true},{"addr":"0x7b8110","include_decompile":true,"include_proto":true},{"addr":"0x7b8130","include_decompile":true,"include_proto":true},{"addr":"0x7b8190","include_decompile":true,"include_proto":true},{"addr":"0x7b81f0","include_decompile":true,"include_proto":true},{"addr":"0x7b8250","include_decompile":true,"include_proto":true},{"addr":"0x7b82b0","include_decompile":true,"include_proto":true},{"addr":"0x7b8350","include_decompile":true,"include_proto":true},{"addr":"0x7b83f0","include_decompile":true,"include_proto":true},{"addr":"0x7b84b0","include_decompile":true,"include_proto":true},{"addr":"0x7b8570","include_decompile":true,"include_proto":true},{"addr":"0x7b85e0","include_decompile":true,"include_proto":true},{"addr":"0x7b8650","include_decompile":true,"include_proto":true},{"addr":"0x7b8670","include_decompile":true,"include_proto":true},{"addr":"0x7b8690","include_decompile":true,"include_proto":true},{"addr":"0x7b86b0","include_decompile":true,"include_proto":true},{"addr":"0x7b86d0","include_decompile":true,"include_proto":true},{"addr":"0x7b86f0","include_decompile":true,"include_proto":true},{"addr":"0x7b8710","include_decompile":true,"include_proto":true},{"addr":"0x7b8730","include_decompile":true,"include_proto":true},{"addr":"0x7b8750","include_decompile":true,"include_proto":true},{"addr":"0x7b87c0","include_decompile":true,"include_proto":true},{"addr":"0x7b8830","include_decompile":true,"include_proto":true},{"addr":"0x7b88a0","include_decompile":true,"include_proto":true},{"addr":"0x7b8920","include_decompile":true,"include_proto":true},{"addr":"0x7b8990","include_decompile":true,"include_proto":true},{"addr":"0x7b89f0","include_decompile":true,"include_proto":true},{"addr":"0x7b8a50","include_decompile":true,"include_proto":true},{"addr":"0x7b8ad0","include_decompile":true,"include_proto":true},{"addr":"0x7b8b00","include_decompile":true,"include_proto":true},{"addr":"0x7b8b20","include_decompile":true,"include_proto":true},{"addr":"0x7b8b80","include_decompile":true,"include_proto":true},{"addr":"0x7b8bb0","include_decompile":true,"include_proto":true},{"addr":"0x7b8be0","include_decompile":true,"include_proto":true},{"addr":"0x7b8c10","include_decompile":true,"include_proto":true},{"addr":"0x7b8c40","include_decompile":true,"include_proto":true},{"addr":"0x7b8c90","include_decompile":true,"include_proto":true},{"addr":"0x7b8cc0","include_decompile":true,"include_proto":true},{"addr":"0x7b8cf0","include_decompile":true,"include_proto":true},{"addr":"0x7b8d40","include_decompile":true,"include_proto":true},{"addr":"0x7b8d60","include_decompile":true,"include_proto":true},{"addr":"0x7b8d80","include_decompile":true,"include_proto":true},{"addr":"0x7b8da0","include_decompile":true,"include_proto":true},{"addr":"0x7b8dc0","include_decompile":true,"include_proto":true},{"addr":"0x7b8de0","include_decompile":true,"include_proto":true},{"addr":"0x7b8e00","include_decompile":true,"include_proto":true},{"addr":"0x7b8e20","include_decompile":true,"include_proto":true},{"addr":"0x7b8e90","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0190', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0190: empty response'); return; }
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
      console.log('Batch 0190: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0190 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0190 conn error:', e.message));
req.write(body);
req.end();
