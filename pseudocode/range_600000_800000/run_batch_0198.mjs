
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7d6980","include_decompile":true,"include_proto":true},{"addr":"0x7d6ae0","include_decompile":true,"include_proto":true},{"addr":"0x7d6cf0","include_decompile":true,"include_proto":true},{"addr":"0x7d6e00","include_decompile":true,"include_proto":true},{"addr":"0x7d7000","include_decompile":true,"include_proto":true},{"addr":"0x7d7060","include_decompile":true,"include_proto":true},{"addr":"0x7d7100","include_decompile":true,"include_proto":true},{"addr":"0x7d7210","include_decompile":true,"include_proto":true},{"addr":"0x7d7310","include_decompile":true,"include_proto":true},{"addr":"0x7d7380","include_decompile":true,"include_proto":true},{"addr":"0x7d7410","include_decompile":true,"include_proto":true},{"addr":"0x7d7910","include_decompile":true,"include_proto":true},{"addr":"0x7d7950","include_decompile":true,"include_proto":true},{"addr":"0x7d7970","include_decompile":true,"include_proto":true},{"addr":"0x7d7a50","include_decompile":true,"include_proto":true},{"addr":"0x7d7fc0","include_decompile":true,"include_proto":true},{"addr":"0x7d91f0","include_decompile":true,"include_proto":true},{"addr":"0x7d9310","include_decompile":true,"include_proto":true},{"addr":"0x7d9390","include_decompile":true,"include_proto":true},{"addr":"0x7d9470","include_decompile":true,"include_proto":true},{"addr":"0x7d9500","include_decompile":true,"include_proto":true},{"addr":"0x7d9620","include_decompile":true,"include_proto":true},{"addr":"0x7d9870","include_decompile":true,"include_proto":true},{"addr":"0x7d99d0","include_decompile":true,"include_proto":true},{"addr":"0x7d9a10","include_decompile":true,"include_proto":true},{"addr":"0x7d9a20","include_decompile":true,"include_proto":true},{"addr":"0x7d9b40","include_decompile":true,"include_proto":true},{"addr":"0x7daae0","include_decompile":true,"include_proto":true},{"addr":"0x7dabf0","include_decompile":true,"include_proto":true},{"addr":"0x7dadf0","include_decompile":true,"include_proto":true},{"addr":"0x7dbdf0","include_decompile":true,"include_proto":true},{"addr":"0x7dcd90","include_decompile":true,"include_proto":true},{"addr":"0x7dcdd0","include_decompile":true,"include_proto":true},{"addr":"0x7dce80","include_decompile":true,"include_proto":true},{"addr":"0x7dd390","include_decompile":true,"include_proto":true},{"addr":"0x7dd4f0","include_decompile":true,"include_proto":true},{"addr":"0x7dd7a0","include_decompile":true,"include_proto":true},{"addr":"0x7de610","include_decompile":true,"include_proto":true},{"addr":"0x7de6a0","include_decompile":true,"include_proto":true},{"addr":"0x7dfcf0","include_decompile":true,"include_proto":true},{"addr":"0x7e0f20","include_decompile":true,"include_proto":true},{"addr":"0x7e10b0","include_decompile":true,"include_proto":true},{"addr":"0x7e11e0","include_decompile":true,"include_proto":true},{"addr":"0x7e1360","include_decompile":true,"include_proto":true},{"addr":"0x7e1500","include_decompile":true,"include_proto":true},{"addr":"0x7e1a80","include_decompile":true,"include_proto":true},{"addr":"0x7e1b40","include_decompile":true,"include_proto":true},{"addr":"0x7e1bd0","include_decompile":true,"include_proto":true},{"addr":"0x7e1c60","include_decompile":true,"include_proto":true},{"addr":"0x7e1da0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0198', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0198: empty response'); return; }
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
      console.log('Batch 0198: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0198 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0198 conn error:', e.message));
req.write(body);
req.end();
