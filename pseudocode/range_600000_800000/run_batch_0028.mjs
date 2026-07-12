
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x62f8e0","include_decompile":true,"include_proto":true},{"addr":"0x62f8f0","include_decompile":true,"include_proto":true},{"addr":"0x62f900","include_decompile":true,"include_proto":true},{"addr":"0x62f910","include_decompile":true,"include_proto":true},{"addr":"0x62f930","include_decompile":true,"include_proto":true},{"addr":"0x62f940","include_decompile":true,"include_proto":true},{"addr":"0x62f950","include_decompile":true,"include_proto":true},{"addr":"0x62f960","include_decompile":true,"include_proto":true},{"addr":"0x62f970","include_decompile":true,"include_proto":true},{"addr":"0x62f980","include_decompile":true,"include_proto":true},{"addr":"0x62f990","include_decompile":true,"include_proto":true},{"addr":"0x62f9a0","include_decompile":true,"include_proto":true},{"addr":"0x62f9b0","include_decompile":true,"include_proto":true},{"addr":"0x62f9c0","include_decompile":true,"include_proto":true},{"addr":"0x62f9d0","include_decompile":true,"include_proto":true},{"addr":"0x62f9e0","include_decompile":true,"include_proto":true},{"addr":"0x62f9f0","include_decompile":true,"include_proto":true},{"addr":"0x62fa00","include_decompile":true,"include_proto":true},{"addr":"0x62fa10","include_decompile":true,"include_proto":true},{"addr":"0x62fa20","include_decompile":true,"include_proto":true},{"addr":"0x62fa30","include_decompile":true,"include_proto":true},{"addr":"0x62fa40","include_decompile":true,"include_proto":true},{"addr":"0x62fa50","include_decompile":true,"include_proto":true},{"addr":"0x62fa60","include_decompile":true,"include_proto":true},{"addr":"0x62fa70","include_decompile":true,"include_proto":true},{"addr":"0x62fa80","include_decompile":true,"include_proto":true},{"addr":"0x62fa90","include_decompile":true,"include_proto":true},{"addr":"0x62faa0","include_decompile":true,"include_proto":true},{"addr":"0x62fab0","include_decompile":true,"include_proto":true},{"addr":"0x62fad0","include_decompile":true,"include_proto":true},{"addr":"0x62faf0","include_decompile":true,"include_proto":true},{"addr":"0x62fb00","include_decompile":true,"include_proto":true},{"addr":"0x62fb10","include_decompile":true,"include_proto":true},{"addr":"0x62fb20","include_decompile":true,"include_proto":true},{"addr":"0x62fb30","include_decompile":true,"include_proto":true},{"addr":"0x62fb40","include_decompile":true,"include_proto":true},{"addr":"0x62fb50","include_decompile":true,"include_proto":true},{"addr":"0x62fb70","include_decompile":true,"include_proto":true},{"addr":"0x62fb90","include_decompile":true,"include_proto":true},{"addr":"0x62fba0","include_decompile":true,"include_proto":true},{"addr":"0x62fbd0","include_decompile":true,"include_proto":true},{"addr":"0x62fbe0","include_decompile":true,"include_proto":true},{"addr":"0x62fcb0","include_decompile":true,"include_proto":true},{"addr":"0x62fcc0","include_decompile":true,"include_proto":true},{"addr":"0x62fcd0","include_decompile":true,"include_proto":true},{"addr":"0x62fce0","include_decompile":true,"include_proto":true},{"addr":"0x62fcf0","include_decompile":true,"include_proto":true},{"addr":"0x62fd00","include_decompile":true,"include_proto":true},{"addr":"0x62fd10","include_decompile":true,"include_proto":true},{"addr":"0x62fd20","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0028', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0028: empty response'); return; }
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
      console.log('Batch 0028: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0028 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0028 conn error:', e.message));
req.write(body);
req.end();
