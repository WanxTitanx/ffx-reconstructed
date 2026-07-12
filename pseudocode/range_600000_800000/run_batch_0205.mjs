
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7fe9f0","include_decompile":true,"include_proto":true},{"addr":"0x7fea40","include_decompile":true,"include_proto":true},{"addr":"0x7feac0","include_decompile":true,"include_proto":true},{"addr":"0x7fed10","include_decompile":true,"include_proto":true},{"addr":"0x7fed30","include_decompile":true,"include_proto":true},{"addr":"0x7fede0","include_decompile":true,"include_proto":true},{"addr":"0x7fee90","include_decompile":true,"include_proto":true},{"addr":"0x7fef00","include_decompile":true,"include_proto":true},{"addr":"0x7fefb0","include_decompile":true,"include_proto":true},{"addr":"0x7ff020","include_decompile":true,"include_proto":true},{"addr":"0x7ff0f0","include_decompile":true,"include_proto":true},{"addr":"0x7ff180","include_decompile":true,"include_proto":true},{"addr":"0x7ff1b0","include_decompile":true,"include_proto":true},{"addr":"0x7ff1d0","include_decompile":true,"include_proto":true},{"addr":"0x7ff1f0","include_decompile":true,"include_proto":true},{"addr":"0x7ff280","include_decompile":true,"include_proto":true},{"addr":"0x7ff590","include_decompile":true,"include_proto":true},{"addr":"0x7ff5a0","include_decompile":true,"include_proto":true},{"addr":"0x7ff690","include_decompile":true,"include_proto":true},{"addr":"0x7ff6a0","include_decompile":true,"include_proto":true},{"addr":"0x7ff800","include_decompile":true,"include_proto":true},{"addr":"0x7ff880","include_decompile":true,"include_proto":true},{"addr":"0x7ff9b0","include_decompile":true,"include_proto":true},{"addr":"0x7ffb80","include_decompile":true,"include_proto":true},{"addr":"0x7ffc40","include_decompile":true,"include_proto":true},{"addr":"0x7ffd00","include_decompile":true,"include_proto":true},{"addr":"0x7ffd30","include_decompile":true,"include_proto":true},{"addr":"0x7ffdd0","include_decompile":true,"include_proto":true},{"addr":"0x7ffe50","include_decompile":true,"include_proto":true},{"addr":"0x7ffea0","include_decompile":true,"include_proto":true},{"addr":"0x7ffec0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0205', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0205: empty response'); return; }
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
      console.log('Batch 0205: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0205 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0205 conn error:', e.message));
req.write(body);
req.end();
