
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6d9590","include_decompile":true,"include_proto":true},{"addr":"0x6d9db0","include_decompile":true,"include_proto":true},{"addr":"0x6da320","include_decompile":true,"include_proto":true},{"addr":"0x6da370","include_decompile":true,"include_proto":true},{"addr":"0x6da3d0","include_decompile":true,"include_proto":true},{"addr":"0x6da4d0","include_decompile":true,"include_proto":true},{"addr":"0x6da4e0","include_decompile":true,"include_proto":true},{"addr":"0x6da4f0","include_decompile":true,"include_proto":true},{"addr":"0x6da500","include_decompile":true,"include_proto":true},{"addr":"0x6da510","include_decompile":true,"include_proto":true},{"addr":"0x6da520","include_decompile":true,"include_proto":true},{"addr":"0x6da530","include_decompile":true,"include_proto":true},{"addr":"0x6da540","include_decompile":true,"include_proto":true},{"addr":"0x6da550","include_decompile":true,"include_proto":true},{"addr":"0x6da560","include_decompile":true,"include_proto":true},{"addr":"0x6da570","include_decompile":true,"include_proto":true},{"addr":"0x6da580","include_decompile":true,"include_proto":true},{"addr":"0x6da590","include_decompile":true,"include_proto":true},{"addr":"0x6da5b0","include_decompile":true,"include_proto":true},{"addr":"0x6da5c0","include_decompile":true,"include_proto":true},{"addr":"0x6da5d0","include_decompile":true,"include_proto":true},{"addr":"0x6da5e0","include_decompile":true,"include_proto":true},{"addr":"0x6da610","include_decompile":true,"include_proto":true},{"addr":"0x6da620","include_decompile":true,"include_proto":true},{"addr":"0x6daae0","include_decompile":true,"include_proto":true},{"addr":"0x6dad20","include_decompile":true,"include_proto":true},{"addr":"0x6daf20","include_decompile":true,"include_proto":true},{"addr":"0x6daf30","include_decompile":true,"include_proto":true},{"addr":"0x6db010","include_decompile":true,"include_proto":true},{"addr":"0x6db060","include_decompile":true,"include_proto":true},{"addr":"0x6db0f0","include_decompile":true,"include_proto":true},{"addr":"0x6db170","include_decompile":true,"include_proto":true},{"addr":"0x6db1a0","include_decompile":true,"include_proto":true},{"addr":"0x6db1c0","include_decompile":true,"include_proto":true},{"addr":"0x6db320","include_decompile":true,"include_proto":true},{"addr":"0x6db420","include_decompile":true,"include_proto":true},{"addr":"0x6db670","include_decompile":true,"include_proto":true},{"addr":"0x6db690","include_decompile":true,"include_proto":true},{"addr":"0x6db7a0","include_decompile":true,"include_proto":true},{"addr":"0x6db820","include_decompile":true,"include_proto":true},{"addr":"0x6db860","include_decompile":true,"include_proto":true},{"addr":"0x6db910","include_decompile":true,"include_proto":true},{"addr":"0x6db930","include_decompile":true,"include_proto":true},{"addr":"0x6db9a0","include_decompile":true,"include_proto":true},{"addr":"0x6db9d0","include_decompile":true,"include_proto":true},{"addr":"0x6dbb50","include_decompile":true,"include_proto":true},{"addr":"0x6dbe40","include_decompile":true,"include_proto":true},{"addr":"0x6dbf10","include_decompile":true,"include_proto":true},{"addr":"0x6dbf20","include_decompile":true,"include_proto":true},{"addr":"0x6dbf30","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0105', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0105: empty response'); return; }
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
      console.log('Batch 0105: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0105 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0105 conn error:', e.message));
req.write(body);
req.end();
