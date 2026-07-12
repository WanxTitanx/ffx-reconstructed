
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6f25e0","include_decompile":true,"include_proto":true},{"addr":"0x6f2620","include_decompile":true,"include_proto":true},{"addr":"0x6f2630","include_decompile":true,"include_proto":true},{"addr":"0x6f2640","include_decompile":true,"include_proto":true},{"addr":"0x6f2660","include_decompile":true,"include_proto":true},{"addr":"0x6f2670","include_decompile":true,"include_proto":true},{"addr":"0x6f26a0","include_decompile":true,"include_proto":true},{"addr":"0x6f2760","include_decompile":true,"include_proto":true},{"addr":"0x6f2880","include_decompile":true,"include_proto":true},{"addr":"0x6f2890","include_decompile":true,"include_proto":true},{"addr":"0x6f29a0","include_decompile":true,"include_proto":true},{"addr":"0x6f29f0","include_decompile":true,"include_proto":true},{"addr":"0x6f2ae0","include_decompile":true,"include_proto":true},{"addr":"0x6f2b30","include_decompile":true,"include_proto":true},{"addr":"0x6f2c20","include_decompile":true,"include_proto":true},{"addr":"0x6f2c50","include_decompile":true,"include_proto":true},{"addr":"0x6f2ce0","include_decompile":true,"include_proto":true},{"addr":"0x6f2cf0","include_decompile":true,"include_proto":true},{"addr":"0x6f2da0","include_decompile":true,"include_proto":true},{"addr":"0x6f2dd0","include_decompile":true,"include_proto":true},{"addr":"0x6f2de0","include_decompile":true,"include_proto":true},{"addr":"0x6f2e00","include_decompile":true,"include_proto":true},{"addr":"0x6f2e20","include_decompile":true,"include_proto":true},{"addr":"0x6f2e50","include_decompile":true,"include_proto":true},{"addr":"0x6f2e60","include_decompile":true,"include_proto":true},{"addr":"0x6f2e70","include_decompile":true,"include_proto":true},{"addr":"0x6f2e90","include_decompile":true,"include_proto":true},{"addr":"0x6f2ec0","include_decompile":true,"include_proto":true},{"addr":"0x6f2f20","include_decompile":true,"include_proto":true},{"addr":"0x6f2f50","include_decompile":true,"include_proto":true},{"addr":"0x6f2ff0","include_decompile":true,"include_proto":true},{"addr":"0x6f3000","include_decompile":true,"include_proto":true},{"addr":"0x6f3010","include_decompile":true,"include_proto":true},{"addr":"0x6f3040","include_decompile":true,"include_proto":true},{"addr":"0x6f3090","include_decompile":true,"include_proto":true},{"addr":"0x6f30a0","include_decompile":true,"include_proto":true},{"addr":"0x6f30b0","include_decompile":true,"include_proto":true},{"addr":"0x6f3140","include_decompile":true,"include_proto":true},{"addr":"0x6f3190","include_decompile":true,"include_proto":true},{"addr":"0x6f31b0","include_decompile":true,"include_proto":true},{"addr":"0x6f3230","include_decompile":true,"include_proto":true},{"addr":"0x6f3270","include_decompile":true,"include_proto":true},{"addr":"0x6f3340","include_decompile":true,"include_proto":true},{"addr":"0x6f3380","include_decompile":true,"include_proto":true},{"addr":"0x6f3410","include_decompile":true,"include_proto":true},{"addr":"0x6f3420","include_decompile":true,"include_proto":true},{"addr":"0x6f3440","include_decompile":true,"include_proto":true},{"addr":"0x6f3450","include_decompile":true,"include_proto":true},{"addr":"0x6f3510","include_decompile":true,"include_proto":true},{"addr":"0x6f3630","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0115', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0115: empty response'); return; }
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
      console.log('Batch 0115: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0115 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0115 conn error:', e.message));
req.write(body);
req.end();
