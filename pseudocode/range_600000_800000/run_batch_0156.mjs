
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x773770","include_decompile":true,"include_proto":true},{"addr":"0x773790","include_decompile":true,"include_proto":true},{"addr":"0x7737b0","include_decompile":true,"include_proto":true},{"addr":"0x7737d0","include_decompile":true,"include_proto":true},{"addr":"0x7737f0","include_decompile":true,"include_proto":true},{"addr":"0x773810","include_decompile":true,"include_proto":true},{"addr":"0x773830","include_decompile":true,"include_proto":true},{"addr":"0x773850","include_decompile":true,"include_proto":true},{"addr":"0x773870","include_decompile":true,"include_proto":true},{"addr":"0x773890","include_decompile":true,"include_proto":true},{"addr":"0x7738d0","include_decompile":true,"include_proto":true},{"addr":"0x7738f0","include_decompile":true,"include_proto":true},{"addr":"0x773910","include_decompile":true,"include_proto":true},{"addr":"0x773930","include_decompile":true,"include_proto":true},{"addr":"0x773950","include_decompile":true,"include_proto":true},{"addr":"0x773970","include_decompile":true,"include_proto":true},{"addr":"0x773990","include_decompile":true,"include_proto":true},{"addr":"0x7739d0","include_decompile":true,"include_proto":true},{"addr":"0x7739f0","include_decompile":true,"include_proto":true},{"addr":"0x773a10","include_decompile":true,"include_proto":true},{"addr":"0x773a30","include_decompile":true,"include_proto":true},{"addr":"0x773a50","include_decompile":true,"include_proto":true},{"addr":"0x773a60","include_decompile":true,"include_proto":true},{"addr":"0x773a80","include_decompile":true,"include_proto":true},{"addr":"0x773aa0","include_decompile":true,"include_proto":true},{"addr":"0x773ab0","include_decompile":true,"include_proto":true},{"addr":"0x773ad0","include_decompile":true,"include_proto":true},{"addr":"0x773b00","include_decompile":true,"include_proto":true},{"addr":"0x773b20","include_decompile":true,"include_proto":true},{"addr":"0x773b40","include_decompile":true,"include_proto":true},{"addr":"0x773b70","include_decompile":true,"include_proto":true},{"addr":"0x773b90","include_decompile":true,"include_proto":true},{"addr":"0x773bb0","include_decompile":true,"include_proto":true},{"addr":"0x773be0","include_decompile":true,"include_proto":true},{"addr":"0x773c00","include_decompile":true,"include_proto":true},{"addr":"0x773c20","include_decompile":true,"include_proto":true},{"addr":"0x773c30","include_decompile":true,"include_proto":true},{"addr":"0x773c50","include_decompile":true,"include_proto":true},{"addr":"0x773c70","include_decompile":true,"include_proto":true},{"addr":"0x773c90","include_decompile":true,"include_proto":true},{"addr":"0x773ca0","include_decompile":true,"include_proto":true},{"addr":"0x773cb0","include_decompile":true,"include_proto":true},{"addr":"0x773cd0","include_decompile":true,"include_proto":true},{"addr":"0x773cf0","include_decompile":true,"include_proto":true},{"addr":"0x773d10","include_decompile":true,"include_proto":true},{"addr":"0x773d30","include_decompile":true,"include_proto":true},{"addr":"0x773d50","include_decompile":true,"include_proto":true},{"addr":"0x773d70","include_decompile":true,"include_proto":true},{"addr":"0x773da0","include_decompile":true,"include_proto":true},{"addr":"0x773dc0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0156', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0156: empty response'); return; }
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
      console.log('Batch 0156: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0156 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0156 conn error:', e.message));
req.write(body);
req.end();
