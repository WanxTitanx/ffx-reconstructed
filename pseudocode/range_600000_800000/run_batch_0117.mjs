
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6f58d0","include_decompile":true,"include_proto":true},{"addr":"0x6f5920","include_decompile":true,"include_proto":true},{"addr":"0x6f5950","include_decompile":true,"include_proto":true},{"addr":"0x6f5980","include_decompile":true,"include_proto":true},{"addr":"0x6f59b0","include_decompile":true,"include_proto":true},{"addr":"0x6f5ae0","include_decompile":true,"include_proto":true},{"addr":"0x6f5b30","include_decompile":true,"include_proto":true},{"addr":"0x6f5c20","include_decompile":true,"include_proto":true},{"addr":"0x6f5c90","include_decompile":true,"include_proto":true},{"addr":"0x6f5d80","include_decompile":true,"include_proto":true},{"addr":"0x6f5ee0","include_decompile":true,"include_proto":true},{"addr":"0x6f5ef0","include_decompile":true,"include_proto":true},{"addr":"0x6f5f20","include_decompile":true,"include_proto":true},{"addr":"0x6f5f70","include_decompile":true,"include_proto":true},{"addr":"0x6f61b0","include_decompile":true,"include_proto":true},{"addr":"0x6f61e0","include_decompile":true,"include_proto":true},{"addr":"0x6f6420","include_decompile":true,"include_proto":true},{"addr":"0x6f6430","include_decompile":true,"include_proto":true},{"addr":"0x6f6440","include_decompile":true,"include_proto":true},{"addr":"0x6f64b0","include_decompile":true,"include_proto":true},{"addr":"0x6f64f0","include_decompile":true,"include_proto":true},{"addr":"0x6f6520","include_decompile":true,"include_proto":true},{"addr":"0x6f6530","include_decompile":true,"include_proto":true},{"addr":"0x6f6560","include_decompile":true,"include_proto":true},{"addr":"0x6f66f0","include_decompile":true,"include_proto":true},{"addr":"0x6f6770","include_decompile":true,"include_proto":true},{"addr":"0x6f67b0","include_decompile":true,"include_proto":true},{"addr":"0x6f69a0","include_decompile":true,"include_proto":true},{"addr":"0x6f6a30","include_decompile":true,"include_proto":true},{"addr":"0x6f6a40","include_decompile":true,"include_proto":true},{"addr":"0x6f6a50","include_decompile":true,"include_proto":true},{"addr":"0x6f6a70","include_decompile":true,"include_proto":true},{"addr":"0x6f6a90","include_decompile":true,"include_proto":true},{"addr":"0x6f6b30","include_decompile":true,"include_proto":true},{"addr":"0x6f6bd0","include_decompile":true,"include_proto":true},{"addr":"0x6f6d40","include_decompile":true,"include_proto":true},{"addr":"0x6f6eb0","include_decompile":true,"include_proto":true},{"addr":"0x6f6ef0","include_decompile":true,"include_proto":true},{"addr":"0x6f6f00","include_decompile":true,"include_proto":true},{"addr":"0x6f70c0","include_decompile":true,"include_proto":true},{"addr":"0x6f70e0","include_decompile":true,"include_proto":true},{"addr":"0x6f7390","include_decompile":true,"include_proto":true},{"addr":"0x6f73e0","include_decompile":true,"include_proto":true},{"addr":"0x6f7420","include_decompile":true,"include_proto":true},{"addr":"0x6f7430","include_decompile":true,"include_proto":true},{"addr":"0x6f7550","include_decompile":true,"include_proto":true},{"addr":"0x6f7660","include_decompile":true,"include_proto":true},{"addr":"0x6f76a0","include_decompile":true,"include_proto":true},{"addr":"0x6f77a0","include_decompile":true,"include_proto":true},{"addr":"0x6f77e0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0117', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0117: empty response'); return; }
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
      console.log('Batch 0117: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0117 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0117 conn error:', e.message));
req.write(body);
req.end();
