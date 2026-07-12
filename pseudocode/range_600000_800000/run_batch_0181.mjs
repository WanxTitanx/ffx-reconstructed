
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7a4c50","include_decompile":true,"include_proto":true},{"addr":"0x7a4c90","include_decompile":true,"include_proto":true},{"addr":"0x7a4cf0","include_decompile":true,"include_proto":true},{"addr":"0x7a4d10","include_decompile":true,"include_proto":true},{"addr":"0x7a4d70","include_decompile":true,"include_proto":true},{"addr":"0x7a4dc0","include_decompile":true,"include_proto":true},{"addr":"0x7a4e10","include_decompile":true,"include_proto":true},{"addr":"0x7a4e20","include_decompile":true,"include_proto":true},{"addr":"0x7a4e80","include_decompile":true,"include_proto":true},{"addr":"0x7a4eb0","include_decompile":true,"include_proto":true},{"addr":"0x7a4ec0","include_decompile":true,"include_proto":true},{"addr":"0x7a4f00","include_decompile":true,"include_proto":true},{"addr":"0x7a4f40","include_decompile":true,"include_proto":true},{"addr":"0x7a4fa0","include_decompile":true,"include_proto":true},{"addr":"0x7a50b0","include_decompile":true,"include_proto":true},{"addr":"0x7a50e0","include_decompile":true,"include_proto":true},{"addr":"0x7a5160","include_decompile":true,"include_proto":true},{"addr":"0x7a5200","include_decompile":true,"include_proto":true},{"addr":"0x7a5240","include_decompile":true,"include_proto":true},{"addr":"0x7a5260","include_decompile":true,"include_proto":true},{"addr":"0x7a5290","include_decompile":true,"include_proto":true},{"addr":"0x7a52d0","include_decompile":true,"include_proto":true},{"addr":"0x7a5330","include_decompile":true,"include_proto":true},{"addr":"0x7a5350","include_decompile":true,"include_proto":true},{"addr":"0x7a5380","include_decompile":true,"include_proto":true},{"addr":"0x7a53c0","include_decompile":true,"include_proto":true},{"addr":"0x7a53d0","include_decompile":true,"include_proto":true},{"addr":"0x7a5410","include_decompile":true,"include_proto":true},{"addr":"0x7a5470","include_decompile":true,"include_proto":true},{"addr":"0x7a5510","include_decompile":true,"include_proto":true},{"addr":"0x7a5560","include_decompile":true,"include_proto":true},{"addr":"0x7a55c0","include_decompile":true,"include_proto":true},{"addr":"0x7a5630","include_decompile":true,"include_proto":true},{"addr":"0x7a5670","include_decompile":true,"include_proto":true},{"addr":"0x7a56a0","include_decompile":true,"include_proto":true},{"addr":"0x7a56b0","include_decompile":true,"include_proto":true},{"addr":"0x7a56f0","include_decompile":true,"include_proto":true},{"addr":"0x7a5710","include_decompile":true,"include_proto":true},{"addr":"0x7a57a0","include_decompile":true,"include_proto":true},{"addr":"0x7a5800","include_decompile":true,"include_proto":true},{"addr":"0x7a5860","include_decompile":true,"include_proto":true},{"addr":"0x7a58b0","include_decompile":true,"include_proto":true},{"addr":"0x7a58e0","include_decompile":true,"include_proto":true},{"addr":"0x7a58f0","include_decompile":true,"include_proto":true},{"addr":"0x7a5950","include_decompile":true,"include_proto":true},{"addr":"0x7a59a0","include_decompile":true,"include_proto":true},{"addr":"0x7a59b0","include_decompile":true,"include_proto":true},{"addr":"0x7a59f0","include_decompile":true,"include_proto":true},{"addr":"0x7a5a30","include_decompile":true,"include_proto":true},{"addr":"0x7a5b10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0181', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0181: empty response'); return; }
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
      console.log('Batch 0181: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0181 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0181 conn error:', e.message));
req.write(body);
req.end();
