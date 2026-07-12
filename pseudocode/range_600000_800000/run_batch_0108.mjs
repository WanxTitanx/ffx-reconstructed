
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6e0660","include_decompile":true,"include_proto":true},{"addr":"0x6e06f0","include_decompile":true,"include_proto":true},{"addr":"0x6e0790","include_decompile":true,"include_proto":true},{"addr":"0x6e0930","include_decompile":true,"include_proto":true},{"addr":"0x6e0950","include_decompile":true,"include_proto":true},{"addr":"0x6e0990","include_decompile":true,"include_proto":true},{"addr":"0x6e0b40","include_decompile":true,"include_proto":true},{"addr":"0x6e0b50","include_decompile":true,"include_proto":true},{"addr":"0x6e0b60","include_decompile":true,"include_proto":true},{"addr":"0x6e0b70","include_decompile":true,"include_proto":true},{"addr":"0x6e0b80","include_decompile":true,"include_proto":true},{"addr":"0x6e0bc0","include_decompile":true,"include_proto":true},{"addr":"0x6e0bd0","include_decompile":true,"include_proto":true},{"addr":"0x6e0be0","include_decompile":true,"include_proto":true},{"addr":"0x6e0c70","include_decompile":true,"include_proto":true},{"addr":"0x6e0d30","include_decompile":true,"include_proto":true},{"addr":"0x6e0d60","include_decompile":true,"include_proto":true},{"addr":"0x6e0d90","include_decompile":true,"include_proto":true},{"addr":"0x6e0dc0","include_decompile":true,"include_proto":true},{"addr":"0x6e0df0","include_decompile":true,"include_proto":true},{"addr":"0x6e0e20","include_decompile":true,"include_proto":true},{"addr":"0x6e0e50","include_decompile":true,"include_proto":true},{"addr":"0x6e0e80","include_decompile":true,"include_proto":true},{"addr":"0x6e0eb0","include_decompile":true,"include_proto":true},{"addr":"0x6e0ee0","include_decompile":true,"include_proto":true},{"addr":"0x6e0f10","include_decompile":true,"include_proto":true},{"addr":"0x6e0f40","include_decompile":true,"include_proto":true},{"addr":"0x6e0fd0","include_decompile":true,"include_proto":true},{"addr":"0x6e1060","include_decompile":true,"include_proto":true},{"addr":"0x6e1140","include_decompile":true,"include_proto":true},{"addr":"0x6e1220","include_decompile":true,"include_proto":true},{"addr":"0x6e1300","include_decompile":true,"include_proto":true},{"addr":"0x6e13e0","include_decompile":true,"include_proto":true},{"addr":"0x6e14c0","include_decompile":true,"include_proto":true},{"addr":"0x6e14d0","include_decompile":true,"include_proto":true},{"addr":"0x6e14e0","include_decompile":true,"include_proto":true},{"addr":"0x6e14f0","include_decompile":true,"include_proto":true},{"addr":"0x6e1500","include_decompile":true,"include_proto":true},{"addr":"0x6e1510","include_decompile":true,"include_proto":true},{"addr":"0x6e1520","include_decompile":true,"include_proto":true},{"addr":"0x6e1530","include_decompile":true,"include_proto":true},{"addr":"0x6e1540","include_decompile":true,"include_proto":true},{"addr":"0x6e1550","include_decompile":true,"include_proto":true},{"addr":"0x6e1560","include_decompile":true,"include_proto":true},{"addr":"0x6e1570","include_decompile":true,"include_proto":true},{"addr":"0x6e1580","include_decompile":true,"include_proto":true},{"addr":"0x6e1920","include_decompile":true,"include_proto":true},{"addr":"0x6e1e10","include_decompile":true,"include_proto":true},{"addr":"0x6e1e30","include_decompile":true,"include_proto":true},{"addr":"0x6e1e50","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0108', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0108: empty response'); return; }
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
      console.log('Batch 0108: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0108 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0108 conn error:', e.message));
req.write(body);
req.end();
