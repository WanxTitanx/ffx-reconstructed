
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7976b0","include_decompile":true,"include_proto":true},{"addr":"0x7979e0","include_decompile":true,"include_proto":true},{"addr":"0x797a50","include_decompile":true,"include_proto":true},{"addr":"0x797aa0","include_decompile":true,"include_proto":true},{"addr":"0x797af0","include_decompile":true,"include_proto":true},{"addr":"0x797b80","include_decompile":true,"include_proto":true},{"addr":"0x797bd0","include_decompile":true,"include_proto":true},{"addr":"0x797ce0","include_decompile":true,"include_proto":true},{"addr":"0x797d60","include_decompile":true,"include_proto":true},{"addr":"0x798000","include_decompile":true,"include_proto":true},{"addr":"0x798010","include_decompile":true,"include_proto":true},{"addr":"0x7981f0","include_decompile":true,"include_proto":true},{"addr":"0x7982b0","include_decompile":true,"include_proto":true},{"addr":"0x7983a0","include_decompile":true,"include_proto":true},{"addr":"0x7984d0","include_decompile":true,"include_proto":true},{"addr":"0x7985a0","include_decompile":true,"include_proto":true},{"addr":"0x7986b0","include_decompile":true,"include_proto":true},{"addr":"0x7986d0","include_decompile":true,"include_proto":true},{"addr":"0x798730","include_decompile":true,"include_proto":true},{"addr":"0x798770","include_decompile":true,"include_proto":true},{"addr":"0x7987c0","include_decompile":true,"include_proto":true},{"addr":"0x798800","include_decompile":true,"include_proto":true},{"addr":"0x798830","include_decompile":true,"include_proto":true},{"addr":"0x798850","include_decompile":true,"include_proto":true},{"addr":"0x7988a0","include_decompile":true,"include_proto":true},{"addr":"0x798900","include_decompile":true,"include_proto":true},{"addr":"0x798940","include_decompile":true,"include_proto":true},{"addr":"0x798960","include_decompile":true,"include_proto":true},{"addr":"0x7989b0","include_decompile":true,"include_proto":true},{"addr":"0x798a10","include_decompile":true,"include_proto":true},{"addr":"0x798aa0","include_decompile":true,"include_proto":true},{"addr":"0x798ad0","include_decompile":true,"include_proto":true},{"addr":"0x798b70","include_decompile":true,"include_proto":true},{"addr":"0x798b80","include_decompile":true,"include_proto":true},{"addr":"0x798be0","include_decompile":true,"include_proto":true},{"addr":"0x798c20","include_decompile":true,"include_proto":true},{"addr":"0x798ea0","include_decompile":true,"include_proto":true},{"addr":"0x798ec0","include_decompile":true,"include_proto":true},{"addr":"0x798fa0","include_decompile":true,"include_proto":true},{"addr":"0x798fe0","include_decompile":true,"include_proto":true},{"addr":"0x799000","include_decompile":true,"include_proto":true},{"addr":"0x799030","include_decompile":true,"include_proto":true},{"addr":"0x7990e0","include_decompile":true,"include_proto":true},{"addr":"0x7993c0","include_decompile":true,"include_proto":true},{"addr":"0x7993f0","include_decompile":true,"include_proto":true},{"addr":"0x799430","include_decompile":true,"include_proto":true},{"addr":"0x7995d0","include_decompile":true,"include_proto":true},{"addr":"0x799620","include_decompile":true,"include_proto":true},{"addr":"0x7996a0","include_decompile":true,"include_proto":true},{"addr":"0x7996e0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0174', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0174: empty response'); return; }
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
      console.log('Batch 0174: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0174 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0174 conn error:', e.message));
req.write(body);
req.end();
