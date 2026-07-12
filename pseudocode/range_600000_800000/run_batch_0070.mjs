
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x67a690","include_decompile":true,"include_proto":true},{"addr":"0x67a6b0","include_decompile":true,"include_proto":true},{"addr":"0x67a6c0","include_decompile":true,"include_proto":true},{"addr":"0x67a6e0","include_decompile":true,"include_proto":true},{"addr":"0x67a700","include_decompile":true,"include_proto":true},{"addr":"0x67a720","include_decompile":true,"include_proto":true},{"addr":"0x67a740","include_decompile":true,"include_proto":true},{"addr":"0x67a760","include_decompile":true,"include_proto":true},{"addr":"0x67a780","include_decompile":true,"include_proto":true},{"addr":"0x67a7b0","include_decompile":true,"include_proto":true},{"addr":"0x67a850","include_decompile":true,"include_proto":true},{"addr":"0x67a870","include_decompile":true,"include_proto":true},{"addr":"0x67a880","include_decompile":true,"include_proto":true},{"addr":"0x67a8a0","include_decompile":true,"include_proto":true},{"addr":"0x67a8c0","include_decompile":true,"include_proto":true},{"addr":"0x67a8d0","include_decompile":true,"include_proto":true},{"addr":"0x67a900","include_decompile":true,"include_proto":true},{"addr":"0x67a920","include_decompile":true,"include_proto":true},{"addr":"0x67a960","include_decompile":true,"include_proto":true},{"addr":"0x67a980","include_decompile":true,"include_proto":true},{"addr":"0x67a9d0","include_decompile":true,"include_proto":true},{"addr":"0x67aa80","include_decompile":true,"include_proto":true},{"addr":"0x67aa90","include_decompile":true,"include_proto":true},{"addr":"0x67aab0","include_decompile":true,"include_proto":true},{"addr":"0x67aae0","include_decompile":true,"include_proto":true},{"addr":"0x67ab00","include_decompile":true,"include_proto":true},{"addr":"0x67ab10","include_decompile":true,"include_proto":true},{"addr":"0x67ab60","include_decompile":true,"include_proto":true},{"addr":"0x67ab80","include_decompile":true,"include_proto":true},{"addr":"0x67aba0","include_decompile":true,"include_proto":true},{"addr":"0x67ac00","include_decompile":true,"include_proto":true},{"addr":"0x67ac20","include_decompile":true,"include_proto":true},{"addr":"0x67ac70","include_decompile":true,"include_proto":true},{"addr":"0x67ac90","include_decompile":true,"include_proto":true},{"addr":"0x67ace0","include_decompile":true,"include_proto":true},{"addr":"0x67ad00","include_decompile":true,"include_proto":true},{"addr":"0x67ad20","include_decompile":true,"include_proto":true},{"addr":"0x67ad30","include_decompile":true,"include_proto":true},{"addr":"0x67ad60","include_decompile":true,"include_proto":true},{"addr":"0x67ad90","include_decompile":true,"include_proto":true},{"addr":"0x67adc0","include_decompile":true,"include_proto":true},{"addr":"0x67adf0","include_decompile":true,"include_proto":true},{"addr":"0x67ae30","include_decompile":true,"include_proto":true},{"addr":"0x67ae40","include_decompile":true,"include_proto":true},{"addr":"0x67ae50","include_decompile":true,"include_proto":true},{"addr":"0x67ae60","include_decompile":true,"include_proto":true},{"addr":"0x67ae70","include_decompile":true,"include_proto":true},{"addr":"0x67ae80","include_decompile":true,"include_proto":true},{"addr":"0x67aea0","include_decompile":true,"include_proto":true},{"addr":"0x67aeb0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0070', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0070: empty response'); return; }
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
      console.log('Batch 0070: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0070 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0070 conn error:', e.message));
req.write(body);
req.end();
