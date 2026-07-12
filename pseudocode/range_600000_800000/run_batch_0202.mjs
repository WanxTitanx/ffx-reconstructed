
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7ec700","include_decompile":true,"include_proto":true},{"addr":"0x7ec7b0","include_decompile":true,"include_proto":true},{"addr":"0x7ec8b0","include_decompile":true,"include_proto":true},{"addr":"0x7ec910","include_decompile":true,"include_proto":true},{"addr":"0x7ec980","include_decompile":true,"include_proto":true},{"addr":"0x7eca40","include_decompile":true,"include_proto":true},{"addr":"0x7ecb40","include_decompile":true,"include_proto":true},{"addr":"0x7ecb50","include_decompile":true,"include_proto":true},{"addr":"0x7ecb60","include_decompile":true,"include_proto":true},{"addr":"0x7ecbc0","include_decompile":true,"include_proto":true},{"addr":"0x7ecc20","include_decompile":true,"include_proto":true},{"addr":"0x7ecce0","include_decompile":true,"include_proto":true},{"addr":"0x7ecde0","include_decompile":true,"include_proto":true},{"addr":"0x7ece30","include_decompile":true,"include_proto":true},{"addr":"0x7ece50","include_decompile":true,"include_proto":true},{"addr":"0x7ece70","include_decompile":true,"include_proto":true},{"addr":"0x7ecfe0","include_decompile":true,"include_proto":true},{"addr":"0x7f4900","include_decompile":true,"include_proto":true},{"addr":"0x7f5e20","include_decompile":true,"include_proto":true},{"addr":"0x7f5e30","include_decompile":true,"include_proto":true},{"addr":"0x7f5e40","include_decompile":true,"include_proto":true},{"addr":"0x7f5e50","include_decompile":true,"include_proto":true},{"addr":"0x7f5e60","include_decompile":true,"include_proto":true},{"addr":"0x7f5e80","include_decompile":true,"include_proto":true},{"addr":"0x7f5e90","include_decompile":true,"include_proto":true},{"addr":"0x7f5fd0","include_decompile":true,"include_proto":true},{"addr":"0x7f64f0","include_decompile":true,"include_proto":true},{"addr":"0x7f66e0","include_decompile":true,"include_proto":true},{"addr":"0x7f7280","include_decompile":true,"include_proto":true},{"addr":"0x7f72f0","include_decompile":true,"include_proto":true},{"addr":"0x7f7500","include_decompile":true,"include_proto":true},{"addr":"0x7f7960","include_decompile":true,"include_proto":true},{"addr":"0x7f7d50","include_decompile":true,"include_proto":true},{"addr":"0x7f8100","include_decompile":true,"include_proto":true},{"addr":"0x7f83a0","include_decompile":true,"include_proto":true},{"addr":"0x7f8490","include_decompile":true,"include_proto":true},{"addr":"0x7f8850","include_decompile":true,"include_proto":true},{"addr":"0x7f8d50","include_decompile":true,"include_proto":true},{"addr":"0x7f8da0","include_decompile":true,"include_proto":true},{"addr":"0x7f91a0","include_decompile":true,"include_proto":true},{"addr":"0x7f9400","include_decompile":true,"include_proto":true},{"addr":"0x7fa430","include_decompile":true,"include_proto":true},{"addr":"0x7fa4e0","include_decompile":true,"include_proto":true},{"addr":"0x7fa5f0","include_decompile":true,"include_proto":true},{"addr":"0x7fa670","include_decompile":true,"include_proto":true},{"addr":"0x7fa720","include_decompile":true,"include_proto":true},{"addr":"0x7fa7b0","include_decompile":true,"include_proto":true},{"addr":"0x7fa9f0","include_decompile":true,"include_proto":true},{"addr":"0x7fad60","include_decompile":true,"include_proto":true},{"addr":"0x7fadb0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0202', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0202: empty response'); return; }
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
      console.log('Batch 0202: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0202 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0202 conn error:', e.message));
req.write(body);
req.end();
