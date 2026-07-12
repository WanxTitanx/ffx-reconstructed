
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6283a0","include_decompile":true,"include_proto":true},{"addr":"0x6283b0","include_decompile":true,"include_proto":true},{"addr":"0x6283c0","include_decompile":true,"include_proto":true},{"addr":"0x6283d0","include_decompile":true,"include_proto":true},{"addr":"0x6283e0","include_decompile":true,"include_proto":true},{"addr":"0x6283f0","include_decompile":true,"include_proto":true},{"addr":"0x628410","include_decompile":true,"include_proto":true},{"addr":"0x628430","include_decompile":true,"include_proto":true},{"addr":"0x628440","include_decompile":true,"include_proto":true},{"addr":"0x628450","include_decompile":true,"include_proto":true},{"addr":"0x628460","include_decompile":true,"include_proto":true},{"addr":"0x628470","include_decompile":true,"include_proto":true},{"addr":"0x6284b0","include_decompile":true,"include_proto":true},{"addr":"0x6284c0","include_decompile":true,"include_proto":true},{"addr":"0x6284d0","include_decompile":true,"include_proto":true},{"addr":"0x6285c0","include_decompile":true,"include_proto":true},{"addr":"0x6285d0","include_decompile":true,"include_proto":true},{"addr":"0x6285e0","include_decompile":true,"include_proto":true},{"addr":"0x6285f0","include_decompile":true,"include_proto":true},{"addr":"0x628600","include_decompile":true,"include_proto":true},{"addr":"0x628610","include_decompile":true,"include_proto":true},{"addr":"0x628620","include_decompile":true,"include_proto":true},{"addr":"0x628760","include_decompile":true,"include_proto":true},{"addr":"0x628890","include_decompile":true,"include_proto":true},{"addr":"0x6288a0","include_decompile":true,"include_proto":true},{"addr":"0x6288d0","include_decompile":true,"include_proto":true},{"addr":"0x6288e0","include_decompile":true,"include_proto":true},{"addr":"0x6288f0","include_decompile":true,"include_proto":true},{"addr":"0x628900","include_decompile":true,"include_proto":true},{"addr":"0x628910","include_decompile":true,"include_proto":true},{"addr":"0x628920","include_decompile":true,"include_proto":true},{"addr":"0x6289d0","include_decompile":true,"include_proto":true},{"addr":"0x628a60","include_decompile":true,"include_proto":true},{"addr":"0x628a80","include_decompile":true,"include_proto":true},{"addr":"0x628aa0","include_decompile":true,"include_proto":true},{"addr":"0x628ac0","include_decompile":true,"include_proto":true},{"addr":"0x628ad0","include_decompile":true,"include_proto":true},{"addr":"0x628b40","include_decompile":true,"include_proto":true},{"addr":"0x628b50","include_decompile":true,"include_proto":true},{"addr":"0x628b70","include_decompile":true,"include_proto":true},{"addr":"0x628b80","include_decompile":true,"include_proto":true},{"addr":"0x628ba0","include_decompile":true,"include_proto":true},{"addr":"0x628bc0","include_decompile":true,"include_proto":true},{"addr":"0x628bd0","include_decompile":true,"include_proto":true},{"addr":"0x628be0","include_decompile":true,"include_proto":true},{"addr":"0x628bf0","include_decompile":true,"include_proto":true},{"addr":"0x628c80","include_decompile":true,"include_proto":true},{"addr":"0x628e60","include_decompile":true,"include_proto":true},{"addr":"0x628e70","include_decompile":true,"include_proto":true},{"addr":"0x628ed0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0024', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0024: empty response'); return; }
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
      console.log('Batch 0024: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0024 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0024 conn error:', e.message));
req.write(body);
req.end();
