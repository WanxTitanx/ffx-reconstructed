
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x61e640","include_decompile":true,"include_proto":true},{"addr":"0x61e650","include_decompile":true,"include_proto":true},{"addr":"0x61e660","include_decompile":true,"include_proto":true},{"addr":"0x61e690","include_decompile":true,"include_proto":true},{"addr":"0x61e6d0","include_decompile":true,"include_proto":true},{"addr":"0x61e720","include_decompile":true,"include_proto":true},{"addr":"0x61e730","include_decompile":true,"include_proto":true},{"addr":"0x61e750","include_decompile":true,"include_proto":true},{"addr":"0x61e760","include_decompile":true,"include_proto":true},{"addr":"0x61e770","include_decompile":true,"include_proto":true},{"addr":"0x61e780","include_decompile":true,"include_proto":true},{"addr":"0x61e790","include_decompile":true,"include_proto":true},{"addr":"0x61e7a0","include_decompile":true,"include_proto":true},{"addr":"0x61e7b0","include_decompile":true,"include_proto":true},{"addr":"0x61e7c0","include_decompile":true,"include_proto":true},{"addr":"0x61e7d0","include_decompile":true,"include_proto":true},{"addr":"0x61e7e0","include_decompile":true,"include_proto":true},{"addr":"0x61e7f0","include_decompile":true,"include_proto":true},{"addr":"0x61e850","include_decompile":true,"include_proto":true},{"addr":"0x61e860","include_decompile":true,"include_proto":true},{"addr":"0x61e870","include_decompile":true,"include_proto":true},{"addr":"0x61e8e0","include_decompile":true,"include_proto":true},{"addr":"0x61e8f0","include_decompile":true,"include_proto":true},{"addr":"0x61e930","include_decompile":true,"include_proto":true},{"addr":"0x61ecb0","include_decompile":true,"include_proto":true},{"addr":"0x61edb0","include_decompile":true,"include_proto":true},{"addr":"0x61ede0","include_decompile":true,"include_proto":true},{"addr":"0x61ee50","include_decompile":true,"include_proto":true},{"addr":"0x61ee70","include_decompile":true,"include_proto":true},{"addr":"0x61f070","include_decompile":true,"include_proto":true},{"addr":"0x61f180","include_decompile":true,"include_proto":true},{"addr":"0x61f190","include_decompile":true,"include_proto":true},{"addr":"0x61f1a0","include_decompile":true,"include_proto":true},{"addr":"0x61f1b0","include_decompile":true,"include_proto":true},{"addr":"0x61f1c0","include_decompile":true,"include_proto":true},{"addr":"0x61f1e0","include_decompile":true,"include_proto":true},{"addr":"0x61f200","include_decompile":true,"include_proto":true},{"addr":"0x61f220","include_decompile":true,"include_proto":true},{"addr":"0x61f240","include_decompile":true,"include_proto":true},{"addr":"0x61f260","include_decompile":true,"include_proto":true},{"addr":"0x61f280","include_decompile":true,"include_proto":true},{"addr":"0x61f290","include_decompile":true,"include_proto":true},{"addr":"0x61f2a0","include_decompile":true,"include_proto":true},{"addr":"0x61f2b0","include_decompile":true,"include_proto":true},{"addr":"0x61f2c0","include_decompile":true,"include_proto":true},{"addr":"0x61f2d0","include_decompile":true,"include_proto":true},{"addr":"0x61f2e0","include_decompile":true,"include_proto":true},{"addr":"0x61f2f0","include_decompile":true,"include_proto":true},{"addr":"0x61f300","include_decompile":true,"include_proto":true},{"addr":"0x61f310","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0017', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0017: empty response'); return; }
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
      console.log('Batch 0017: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0017 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0017 conn error:', e.message));
req.write(body);
req.end();
