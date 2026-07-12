
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7a77b0","include_decompile":true,"include_proto":true},{"addr":"0x7a77c0","include_decompile":true,"include_proto":true},{"addr":"0x7a77e0","include_decompile":true,"include_proto":true},{"addr":"0x7a7870","include_decompile":true,"include_proto":true},{"addr":"0x7a7880","include_decompile":true,"include_proto":true},{"addr":"0x7a78a0","include_decompile":true,"include_proto":true},{"addr":"0x7a7910","include_decompile":true,"include_proto":true},{"addr":"0x7a79c0","include_decompile":true,"include_proto":true},{"addr":"0x7a79d0","include_decompile":true,"include_proto":true},{"addr":"0x7a79e0","include_decompile":true,"include_proto":true},{"addr":"0x7a7a30","include_decompile":true,"include_proto":true},{"addr":"0x7a7ab0","include_decompile":true,"include_proto":true},{"addr":"0x7a7ac0","include_decompile":true,"include_proto":true},{"addr":"0x7a7ad0","include_decompile":true,"include_proto":true},{"addr":"0x7a7b20","include_decompile":true,"include_proto":true},{"addr":"0x7a7b30","include_decompile":true,"include_proto":true},{"addr":"0x7a7b50","include_decompile":true,"include_proto":true},{"addr":"0x7a7b60","include_decompile":true,"include_proto":true},{"addr":"0x7a7bb0","include_decompile":true,"include_proto":true},{"addr":"0x7a7c10","include_decompile":true,"include_proto":true},{"addr":"0x7a7c40","include_decompile":true,"include_proto":true},{"addr":"0x7a7c60","include_decompile":true,"include_proto":true},{"addr":"0x7a7cd0","include_decompile":true,"include_proto":true},{"addr":"0x7a7d10","include_decompile":true,"include_proto":true},{"addr":"0x7a7d30","include_decompile":true,"include_proto":true},{"addr":"0x7a7d40","include_decompile":true,"include_proto":true},{"addr":"0x7a7d80","include_decompile":true,"include_proto":true},{"addr":"0x7a7dc0","include_decompile":true,"include_proto":true},{"addr":"0x7a7e10","include_decompile":true,"include_proto":true},{"addr":"0x7a7e30","include_decompile":true,"include_proto":true},{"addr":"0x7a7f00","include_decompile":true,"include_proto":true},{"addr":"0x7a7f40","include_decompile":true,"include_proto":true},{"addr":"0x7a7f80","include_decompile":true,"include_proto":true},{"addr":"0x7a7f90","include_decompile":true,"include_proto":true},{"addr":"0x7a7fa0","include_decompile":true,"include_proto":true},{"addr":"0x7a7fc0","include_decompile":true,"include_proto":true},{"addr":"0x7a8000","include_decompile":true,"include_proto":true},{"addr":"0x7a80b0","include_decompile":true,"include_proto":true},{"addr":"0x7a80c0","include_decompile":true,"include_proto":true},{"addr":"0x7a80d0","include_decompile":true,"include_proto":true},{"addr":"0x7a8180","include_decompile":true,"include_proto":true},{"addr":"0x7a81f0","include_decompile":true,"include_proto":true},{"addr":"0x7a8210","include_decompile":true,"include_proto":true},{"addr":"0x7a8450","include_decompile":true,"include_proto":true},{"addr":"0x7a8470","include_decompile":true,"include_proto":true},{"addr":"0x7a84e0","include_decompile":true,"include_proto":true},{"addr":"0x7a8550","include_decompile":true,"include_proto":true},{"addr":"0x7a8570","include_decompile":true,"include_proto":true},{"addr":"0x7a85c0","include_decompile":true,"include_proto":true},{"addr":"0x7a8610","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0184', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0184: empty response'); return; }
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
      console.log('Batch 0184: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0184 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0184 conn error:', e.message));
req.write(body);
req.end();
