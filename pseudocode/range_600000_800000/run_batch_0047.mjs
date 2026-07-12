
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x649e60","include_decompile":true,"include_proto":true},{"addr":"0x649f40","include_decompile":true,"include_proto":true},{"addr":"0x649f50","include_decompile":true,"include_proto":true},{"addr":"0x649f60","include_decompile":true,"include_proto":true},{"addr":"0x649f70","include_decompile":true,"include_proto":true},{"addr":"0x649fa0","include_decompile":true,"include_proto":true},{"addr":"0x64a040","include_decompile":true,"include_proto":true},{"addr":"0x64a1a0","include_decompile":true,"include_proto":true},{"addr":"0x64a2e0","include_decompile":true,"include_proto":true},{"addr":"0x64a510","include_decompile":true,"include_proto":true},{"addr":"0x64a7b0","include_decompile":true,"include_proto":true},{"addr":"0x64a820","include_decompile":true,"include_proto":true},{"addr":"0x64a830","include_decompile":true,"include_proto":true},{"addr":"0x64a840","include_decompile":true,"include_proto":true},{"addr":"0x64a850","include_decompile":true,"include_proto":true},{"addr":"0x64a860","include_decompile":true,"include_proto":true},{"addr":"0x64a9f0","include_decompile":true,"include_proto":true},{"addr":"0x64aa00","include_decompile":true,"include_proto":true},{"addr":"0x64aa30","include_decompile":true,"include_proto":true},{"addr":"0x64aa60","include_decompile":true,"include_proto":true},{"addr":"0x64ab20","include_decompile":true,"include_proto":true},{"addr":"0x64ab50","include_decompile":true,"include_proto":true},{"addr":"0x64ab90","include_decompile":true,"include_proto":true},{"addr":"0x64abc0","include_decompile":true,"include_proto":true},{"addr":"0x64ae80","include_decompile":true,"include_proto":true},{"addr":"0x64ae90","include_decompile":true,"include_proto":true},{"addr":"0x64aea0","include_decompile":true,"include_proto":true},{"addr":"0x64aeb0","include_decompile":true,"include_proto":true},{"addr":"0x64aec0","include_decompile":true,"include_proto":true},{"addr":"0x64aed0","include_decompile":true,"include_proto":true},{"addr":"0x64aee0","include_decompile":true,"include_proto":true},{"addr":"0x64afa0","include_decompile":true,"include_proto":true},{"addr":"0x64b020","include_decompile":true,"include_proto":true},{"addr":"0x64b040","include_decompile":true,"include_proto":true},{"addr":"0x64b060","include_decompile":true,"include_proto":true},{"addr":"0x64b080","include_decompile":true,"include_proto":true},{"addr":"0x64b0a0","include_decompile":true,"include_proto":true},{"addr":"0x64b0c0","include_decompile":true,"include_proto":true},{"addr":"0x64b0e0","include_decompile":true,"include_proto":true},{"addr":"0x64b100","include_decompile":true,"include_proto":true},{"addr":"0x64b120","include_decompile":true,"include_proto":true},{"addr":"0x64b140","include_decompile":true,"include_proto":true},{"addr":"0x64b160","include_decompile":true,"include_proto":true},{"addr":"0x64b180","include_decompile":true,"include_proto":true},{"addr":"0x64b1a0","include_decompile":true,"include_proto":true},{"addr":"0x64b1c0","include_decompile":true,"include_proto":true},{"addr":"0x64b1e0","include_decompile":true,"include_proto":true},{"addr":"0x64b200","include_decompile":true,"include_proto":true},{"addr":"0x64b220","include_decompile":true,"include_proto":true},{"addr":"0x64b240","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0047', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0047: empty response'); return; }
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
      console.log('Batch 0047: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0047 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0047 conn error:', e.message));
req.write(body);
req.end();
