
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6421e0","include_decompile":true,"include_proto":true},{"addr":"0x6421f0","include_decompile":true,"include_proto":true},{"addr":"0x642200","include_decompile":true,"include_proto":true},{"addr":"0x642220","include_decompile":true,"include_proto":true},{"addr":"0x642240","include_decompile":true,"include_proto":true},{"addr":"0x642260","include_decompile":true,"include_proto":true},{"addr":"0x642280","include_decompile":true,"include_proto":true},{"addr":"0x642290","include_decompile":true,"include_proto":true},{"addr":"0x6422a0","include_decompile":true,"include_proto":true},{"addr":"0x6422c0","include_decompile":true,"include_proto":true},{"addr":"0x642490","include_decompile":true,"include_proto":true},{"addr":"0x6424b0","include_decompile":true,"include_proto":true},{"addr":"0x6424d0","include_decompile":true,"include_proto":true},{"addr":"0x642510","include_decompile":true,"include_proto":true},{"addr":"0x642530","include_decompile":true,"include_proto":true},{"addr":"0x642540","include_decompile":true,"include_proto":true},{"addr":"0x642560","include_decompile":true,"include_proto":true},{"addr":"0x642580","include_decompile":true,"include_proto":true},{"addr":"0x6425c0","include_decompile":true,"include_proto":true},{"addr":"0x642780","include_decompile":true,"include_proto":true},{"addr":"0x6427a0","include_decompile":true,"include_proto":true},{"addr":"0x6427c0","include_decompile":true,"include_proto":true},{"addr":"0x642840","include_decompile":true,"include_proto":true},{"addr":"0x642850","include_decompile":true,"include_proto":true},{"addr":"0x642870","include_decompile":true,"include_proto":true},{"addr":"0x642890","include_decompile":true,"include_proto":true},{"addr":"0x642900","include_decompile":true,"include_proto":true},{"addr":"0x642970","include_decompile":true,"include_proto":true},{"addr":"0x642990","include_decompile":true,"include_proto":true},{"addr":"0x6429a0","include_decompile":true,"include_proto":true},{"addr":"0x642a10","include_decompile":true,"include_proto":true},{"addr":"0x642a80","include_decompile":true,"include_proto":true},{"addr":"0x642aa0","include_decompile":true,"include_proto":true},{"addr":"0x642ae0","include_decompile":true,"include_proto":true},{"addr":"0x642b00","include_decompile":true,"include_proto":true},{"addr":"0x642b30","include_decompile":true,"include_proto":true},{"addr":"0x642ba0","include_decompile":true,"include_proto":true},{"addr":"0x642bc0","include_decompile":true,"include_proto":true},{"addr":"0x642cc0","include_decompile":true,"include_proto":true},{"addr":"0x642d60","include_decompile":true,"include_proto":true},{"addr":"0x642d90","include_decompile":true,"include_proto":true},{"addr":"0x642db0","include_decompile":true,"include_proto":true},{"addr":"0x642e10","include_decompile":true,"include_proto":true},{"addr":"0x642e20","include_decompile":true,"include_proto":true},{"addr":"0x642e30","include_decompile":true,"include_proto":true},{"addr":"0x642e70","include_decompile":true,"include_proto":true},{"addr":"0x642e80","include_decompile":true,"include_proto":true},{"addr":"0x642e90","include_decompile":true,"include_proto":true},{"addr":"0x642ea0","include_decompile":true,"include_proto":true},{"addr":"0x642ec0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0041', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0041: empty response'); return; }
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
      console.log('Batch 0041: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0041 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0041 conn error:', e.message));
req.write(body);
req.end();
