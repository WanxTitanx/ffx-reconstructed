
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x634750","include_decompile":true,"include_proto":true},{"addr":"0x634760","include_decompile":true,"include_proto":true},{"addr":"0x634770","include_decompile":true,"include_proto":true},{"addr":"0x634780","include_decompile":true,"include_proto":true},{"addr":"0x634790","include_decompile":true,"include_proto":true},{"addr":"0x6347a0","include_decompile":true,"include_proto":true},{"addr":"0x6347b0","include_decompile":true,"include_proto":true},{"addr":"0x6347c0","include_decompile":true,"include_proto":true},{"addr":"0x6348b0","include_decompile":true,"include_proto":true},{"addr":"0x634940","include_decompile":true,"include_proto":true},{"addr":"0x6349f0","include_decompile":true,"include_proto":true},{"addr":"0x634a00","include_decompile":true,"include_proto":true},{"addr":"0x635290","include_decompile":true,"include_proto":true},{"addr":"0x6352b0","include_decompile":true,"include_proto":true},{"addr":"0x6352d0","include_decompile":true,"include_proto":true},{"addr":"0x635330","include_decompile":true,"include_proto":true},{"addr":"0x635460","include_decompile":true,"include_proto":true},{"addr":"0x6354b0","include_decompile":true,"include_proto":true},{"addr":"0x635500","include_decompile":true,"include_proto":true},{"addr":"0x6355a0","include_decompile":true,"include_proto":true},{"addr":"0x6357e0","include_decompile":true,"include_proto":true},{"addr":"0x635830","include_decompile":true,"include_proto":true},{"addr":"0x6358b0","include_decompile":true,"include_proto":true},{"addr":"0x635930","include_decompile":true,"include_proto":true},{"addr":"0x6359a0","include_decompile":true,"include_proto":true},{"addr":"0x635b50","include_decompile":true,"include_proto":true},{"addr":"0x635b60","include_decompile":true,"include_proto":true},{"addr":"0x635b70","include_decompile":true,"include_proto":true},{"addr":"0x635b80","include_decompile":true,"include_proto":true},{"addr":"0x635b90","include_decompile":true,"include_proto":true},{"addr":"0x635ba0","include_decompile":true,"include_proto":true},{"addr":"0x635bb0","include_decompile":true,"include_proto":true},{"addr":"0x635bc0","include_decompile":true,"include_proto":true},{"addr":"0x635bd0","include_decompile":true,"include_proto":true},{"addr":"0x635be0","include_decompile":true,"include_proto":true},{"addr":"0x635bf0","include_decompile":true,"include_proto":true},{"addr":"0x635c10","include_decompile":true,"include_proto":true},{"addr":"0x635c20","include_decompile":true,"include_proto":true},{"addr":"0x635ca0","include_decompile":true,"include_proto":true},{"addr":"0x635dc0","include_decompile":true,"include_proto":true},{"addr":"0x635dd0","include_decompile":true,"include_proto":true},{"addr":"0x635de0","include_decompile":true,"include_proto":true},{"addr":"0x635df0","include_decompile":true,"include_proto":true},{"addr":"0x635e30","include_decompile":true,"include_proto":true},{"addr":"0x635e90","include_decompile":true,"include_proto":true},{"addr":"0x635f70","include_decompile":true,"include_proto":true},{"addr":"0x635f80","include_decompile":true,"include_proto":true},{"addr":"0x635f90","include_decompile":true,"include_proto":true},{"addr":"0x635fa0","include_decompile":true,"include_proto":true},{"addr":"0x635fb0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0033', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0033: empty response'); return; }
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
      console.log('Batch 0033: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0033 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0033 conn error:', e.message));
req.write(body);
req.end();
