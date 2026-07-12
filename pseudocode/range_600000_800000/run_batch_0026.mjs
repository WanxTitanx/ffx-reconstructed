
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x62a2d0","include_decompile":true,"include_proto":true},{"addr":"0x62a2e0","include_decompile":true,"include_proto":true},{"addr":"0x62a610","include_decompile":true,"include_proto":true},{"addr":"0x62a7b0","include_decompile":true,"include_proto":true},{"addr":"0x62ae20","include_decompile":true,"include_proto":true},{"addr":"0x62ae40","include_decompile":true,"include_proto":true},{"addr":"0x62af70","include_decompile":true,"include_proto":true},{"addr":"0x62b660","include_decompile":true,"include_proto":true},{"addr":"0x62b6a0","include_decompile":true,"include_proto":true},{"addr":"0x62b6e0","include_decompile":true,"include_proto":true},{"addr":"0x62b720","include_decompile":true,"include_proto":true},{"addr":"0x62b750","include_decompile":true,"include_proto":true},{"addr":"0x62b780","include_decompile":true,"include_proto":true},{"addr":"0x62b7a0","include_decompile":true,"include_proto":true},{"addr":"0x62bc60","include_decompile":true,"include_proto":true},{"addr":"0x62bd10","include_decompile":true,"include_proto":true},{"addr":"0x62be30","include_decompile":true,"include_proto":true},{"addr":"0x62be50","include_decompile":true,"include_proto":true},{"addr":"0x62be70","include_decompile":true,"include_proto":true},{"addr":"0x62be90","include_decompile":true,"include_proto":true},{"addr":"0x62bfa0","include_decompile":true,"include_proto":true},{"addr":"0x62bfb0","include_decompile":true,"include_proto":true},{"addr":"0x62c020","include_decompile":true,"include_proto":true},{"addr":"0x62c040","include_decompile":true,"include_proto":true},{"addr":"0x62c050","include_decompile":true,"include_proto":true},{"addr":"0x62c0a0","include_decompile":true,"include_proto":true},{"addr":"0x62c0b0","include_decompile":true,"include_proto":true},{"addr":"0x62c3a0","include_decompile":true,"include_proto":true},{"addr":"0x62c410","include_decompile":true,"include_proto":true},{"addr":"0x62c5e0","include_decompile":true,"include_proto":true},{"addr":"0x62c630","include_decompile":true,"include_proto":true},{"addr":"0x62c8a0","include_decompile":true,"include_proto":true},{"addr":"0x62c8e0","include_decompile":true,"include_proto":true},{"addr":"0x62cb40","include_decompile":true,"include_proto":true},{"addr":"0x62cc80","include_decompile":true,"include_proto":true},{"addr":"0x62cd20","include_decompile":true,"include_proto":true},{"addr":"0x62cd40","include_decompile":true,"include_proto":true},{"addr":"0x62cd50","include_decompile":true,"include_proto":true},{"addr":"0x62d100","include_decompile":true,"include_proto":true},{"addr":"0x62d110","include_decompile":true,"include_proto":true},{"addr":"0x62d140","include_decompile":true,"include_proto":true},{"addr":"0x62d1a0","include_decompile":true,"include_proto":true},{"addr":"0x62d210","include_decompile":true,"include_proto":true},{"addr":"0x62d280","include_decompile":true,"include_proto":true},{"addr":"0x62d2b0","include_decompile":true,"include_proto":true},{"addr":"0x62d320","include_decompile":true,"include_proto":true},{"addr":"0x62d540","include_decompile":true,"include_proto":true},{"addr":"0x62d580","include_decompile":true,"include_proto":true},{"addr":"0x62d700","include_decompile":true,"include_proto":true},{"addr":"0x62d770","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0026', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0026: empty response'); return; }
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
      console.log('Batch 0026: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0026 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0026 conn error:', e.message));
req.write(body);
req.end();
