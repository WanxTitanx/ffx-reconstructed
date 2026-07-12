
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6c4200","include_decompile":true,"include_proto":true},{"addr":"0x6c4220","include_decompile":true,"include_proto":true},{"addr":"0x6c43d0","include_decompile":true,"include_proto":true},{"addr":"0x6c4610","include_decompile":true,"include_proto":true},{"addr":"0x6c4620","include_decompile":true,"include_proto":true},{"addr":"0x6c4700","include_decompile":true,"include_proto":true},{"addr":"0x6c4760","include_decompile":true,"include_proto":true},{"addr":"0x6c47c0","include_decompile":true,"include_proto":true},{"addr":"0x6c4820","include_decompile":true,"include_proto":true},{"addr":"0x6c4850","include_decompile":true,"include_proto":true},{"addr":"0x6c4870","include_decompile":true,"include_proto":true},{"addr":"0x6c48e0","include_decompile":true,"include_proto":true},{"addr":"0x6c4960","include_decompile":true,"include_proto":true},{"addr":"0x6c4ae0","include_decompile":true,"include_proto":true},{"addr":"0x6c4b70","include_decompile":true,"include_proto":true},{"addr":"0x6c4bb0","include_decompile":true,"include_proto":true},{"addr":"0x6c4bd0","include_decompile":true,"include_proto":true},{"addr":"0x6c4bf0","include_decompile":true,"include_proto":true},{"addr":"0x6c4c00","include_decompile":true,"include_proto":true},{"addr":"0x6c4c10","include_decompile":true,"include_proto":true},{"addr":"0x6c4c20","include_decompile":true,"include_proto":true},{"addr":"0x6c4c30","include_decompile":true,"include_proto":true},{"addr":"0x6c4c40","include_decompile":true,"include_proto":true},{"addr":"0x6c4c90","include_decompile":true,"include_proto":true},{"addr":"0x6c4ca0","include_decompile":true,"include_proto":true},{"addr":"0x6c4e30","include_decompile":true,"include_proto":true},{"addr":"0x6c4f00","include_decompile":true,"include_proto":true},{"addr":"0x6c4f40","include_decompile":true,"include_proto":true},{"addr":"0x6c5000","include_decompile":true,"include_proto":true},{"addr":"0x6c5080","include_decompile":true,"include_proto":true},{"addr":"0x6c50f0","include_decompile":true,"include_proto":true},{"addr":"0x6c5170","include_decompile":true,"include_proto":true},{"addr":"0x6c51f0","include_decompile":true,"include_proto":true},{"addr":"0x6c5270","include_decompile":true,"include_proto":true},{"addr":"0x6c5290","include_decompile":true,"include_proto":true},{"addr":"0x6c54a0","include_decompile":true,"include_proto":true},{"addr":"0x6c5520","include_decompile":true,"include_proto":true},{"addr":"0x6c5550","include_decompile":true,"include_proto":true},{"addr":"0x6c56b0","include_decompile":true,"include_proto":true},{"addr":"0x6c5740","include_decompile":true,"include_proto":true},{"addr":"0x6c57b0","include_decompile":true,"include_proto":true},{"addr":"0x6c5800","include_decompile":true,"include_proto":true},{"addr":"0x6c5830","include_decompile":true,"include_proto":true},{"addr":"0x6c58d0","include_decompile":true,"include_proto":true},{"addr":"0x6c5900","include_decompile":true,"include_proto":true},{"addr":"0x6c5920","include_decompile":true,"include_proto":true},{"addr":"0x6c5990","include_decompile":true,"include_proto":true},{"addr":"0x6c5ae0","include_decompile":true,"include_proto":true},{"addr":"0x6c5b00","include_decompile":true,"include_proto":true},{"addr":"0x6c5ca0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0099', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0099: empty response'); return; }
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
      console.log('Batch 0099: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0099 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0099 conn error:', e.message));
req.write(body);
req.end();
