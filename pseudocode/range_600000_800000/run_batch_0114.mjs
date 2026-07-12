
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6f08e0","include_decompile":true,"include_proto":true},{"addr":"0x6f09a0","include_decompile":true,"include_proto":true},{"addr":"0x6f0a90","include_decompile":true,"include_proto":true},{"addr":"0x6f0bb0","include_decompile":true,"include_proto":true},{"addr":"0x6f0da0","include_decompile":true,"include_proto":true},{"addr":"0x6f10f0","include_decompile":true,"include_proto":true},{"addr":"0x6f1290","include_decompile":true,"include_proto":true},{"addr":"0x6f12e0","include_decompile":true,"include_proto":true},{"addr":"0x6f1560","include_decompile":true,"include_proto":true},{"addr":"0x6f1570","include_decompile":true,"include_proto":true},{"addr":"0x6f1650","include_decompile":true,"include_proto":true},{"addr":"0x6f1690","include_decompile":true,"include_proto":true},{"addr":"0x6f16c0","include_decompile":true,"include_proto":true},{"addr":"0x6f16d0","include_decompile":true,"include_proto":true},{"addr":"0x6f16e0","include_decompile":true,"include_proto":true},{"addr":"0x6f16f0","include_decompile":true,"include_proto":true},{"addr":"0x6f1720","include_decompile":true,"include_proto":true},{"addr":"0x6f1730","include_decompile":true,"include_proto":true},{"addr":"0x6f1810","include_decompile":true,"include_proto":true},{"addr":"0x6f1960","include_decompile":true,"include_proto":true},{"addr":"0x6f1970","include_decompile":true,"include_proto":true},{"addr":"0x6f1990","include_decompile":true,"include_proto":true},{"addr":"0x6f19a0","include_decompile":true,"include_proto":true},{"addr":"0x6f19c0","include_decompile":true,"include_proto":true},{"addr":"0x6f19d0","include_decompile":true,"include_proto":true},{"addr":"0x6f1a30","include_decompile":true,"include_proto":true},{"addr":"0x6f1a40","include_decompile":true,"include_proto":true},{"addr":"0x6f1ac0","include_decompile":true,"include_proto":true},{"addr":"0x6f1bb0","include_decompile":true,"include_proto":true},{"addr":"0x6f1be0","include_decompile":true,"include_proto":true},{"addr":"0x6f1c40","include_decompile":true,"include_proto":true},{"addr":"0x6f1d50","include_decompile":true,"include_proto":true},{"addr":"0x6f1d80","include_decompile":true,"include_proto":true},{"addr":"0x6f1de0","include_decompile":true,"include_proto":true},{"addr":"0x6f1eb0","include_decompile":true,"include_proto":true},{"addr":"0x6f1f80","include_decompile":true,"include_proto":true},{"addr":"0x6f2010","include_decompile":true,"include_proto":true},{"addr":"0x6f2020","include_decompile":true,"include_proto":true},{"addr":"0x6f2040","include_decompile":true,"include_proto":true},{"addr":"0x6f20e0","include_decompile":true,"include_proto":true},{"addr":"0x6f21b0","include_decompile":true,"include_proto":true},{"addr":"0x6f21d0","include_decompile":true,"include_proto":true},{"addr":"0x6f2260","include_decompile":true,"include_proto":true},{"addr":"0x6f2280","include_decompile":true,"include_proto":true},{"addr":"0x6f22d0","include_decompile":true,"include_proto":true},{"addr":"0x6f23a0","include_decompile":true,"include_proto":true},{"addr":"0x6f2540","include_decompile":true,"include_proto":true},{"addr":"0x6f2550","include_decompile":true,"include_proto":true},{"addr":"0x6f2570","include_decompile":true,"include_proto":true},{"addr":"0x6f2590","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0114', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0114: empty response'); return; }
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
      console.log('Batch 0114: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0114 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0114 conn error:', e.message));
req.write(body);
req.end();
