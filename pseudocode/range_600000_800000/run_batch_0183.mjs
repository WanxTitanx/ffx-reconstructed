
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7a6a50","include_decompile":true,"include_proto":true},{"addr":"0x7a6a60","include_decompile":true,"include_proto":true},{"addr":"0x7a6aa0","include_decompile":true,"include_proto":true},{"addr":"0x7a6af0","include_decompile":true,"include_proto":true},{"addr":"0x7a6b00","include_decompile":true,"include_proto":true},{"addr":"0x7a6b60","include_decompile":true,"include_proto":true},{"addr":"0x7a6be0","include_decompile":true,"include_proto":true},{"addr":"0x7a6c70","include_decompile":true,"include_proto":true},{"addr":"0x7a6c90","include_decompile":true,"include_proto":true},{"addr":"0x7a6cd0","include_decompile":true,"include_proto":true},{"addr":"0x7a6d20","include_decompile":true,"include_proto":true},{"addr":"0x7a6d50","include_decompile":true,"include_proto":true},{"addr":"0x7a6d90","include_decompile":true,"include_proto":true},{"addr":"0x7a6dd0","include_decompile":true,"include_proto":true},{"addr":"0x7a6dea","include_decompile":true,"include_proto":true},{"addr":"0x7a6df0","include_decompile":true,"include_proto":true},{"addr":"0x7a6e30","include_decompile":true,"include_proto":true},{"addr":"0x7a6e60","include_decompile":true,"include_proto":true},{"addr":"0x7a6ea0","include_decompile":true,"include_proto":true},{"addr":"0x7a6ec0","include_decompile":true,"include_proto":true},{"addr":"0x7a6f10","include_decompile":true,"include_proto":true},{"addr":"0x7a6f90","include_decompile":true,"include_proto":true},{"addr":"0x7a7030","include_decompile":true,"include_proto":true},{"addr":"0x7a7040","include_decompile":true,"include_proto":true},{"addr":"0x7a70d0","include_decompile":true,"include_proto":true},{"addr":"0x7a70e0","include_decompile":true,"include_proto":true},{"addr":"0x7a7150","include_decompile":true,"include_proto":true},{"addr":"0x7a71a0","include_decompile":true,"include_proto":true},{"addr":"0x7a7210","include_decompile":true,"include_proto":true},{"addr":"0x7a7220","include_decompile":true,"include_proto":true},{"addr":"0x7a7280","include_decompile":true,"include_proto":true},{"addr":"0x7a72e0","include_decompile":true,"include_proto":true},{"addr":"0x7a7360","include_decompile":true,"include_proto":true},{"addr":"0x7a7380","include_decompile":true,"include_proto":true},{"addr":"0x7a73f0","include_decompile":true,"include_proto":true},{"addr":"0x7a7420","include_decompile":true,"include_proto":true},{"addr":"0x7a7460","include_decompile":true,"include_proto":true},{"addr":"0x7a7490","include_decompile":true,"include_proto":true},{"addr":"0x7a7500","include_decompile":true,"include_proto":true},{"addr":"0x7a7510","include_decompile":true,"include_proto":true},{"addr":"0x7a7520","include_decompile":true,"include_proto":true},{"addr":"0x7a753f","include_decompile":true,"include_proto":true},{"addr":"0x7a7550","include_decompile":true,"include_proto":true},{"addr":"0x7a75a0","include_decompile":true,"include_proto":true},{"addr":"0x7a7600","include_decompile":true,"include_proto":true},{"addr":"0x7a7650","include_decompile":true,"include_proto":true},{"addr":"0x7a7660","include_decompile":true,"include_proto":true},{"addr":"0x7a7700","include_decompile":true,"include_proto":true},{"addr":"0x7a7710","include_decompile":true,"include_proto":true},{"addr":"0x7a7760","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0183', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0183: empty response'); return; }
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
      console.log('Batch 0183: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0183 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0183 conn error:', e.message));
req.write(body);
req.end();
