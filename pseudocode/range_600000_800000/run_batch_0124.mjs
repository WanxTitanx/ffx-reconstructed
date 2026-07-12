
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x706f40","include_decompile":true,"include_proto":true},{"addr":"0x706f60","include_decompile":true,"include_proto":true},{"addr":"0x706f80","include_decompile":true,"include_proto":true},{"addr":"0x706fa0","include_decompile":true,"include_proto":true},{"addr":"0x706fc0","include_decompile":true,"include_proto":true},{"addr":"0x706fe0","include_decompile":true,"include_proto":true},{"addr":"0x707000","include_decompile":true,"include_proto":true},{"addr":"0x707020","include_decompile":true,"include_proto":true},{"addr":"0x707040","include_decompile":true,"include_proto":true},{"addr":"0x707070","include_decompile":true,"include_proto":true},{"addr":"0x7070a0","include_decompile":true,"include_proto":true},{"addr":"0x7070c0","include_decompile":true,"include_proto":true},{"addr":"0x7070e0","include_decompile":true,"include_proto":true},{"addr":"0x707170","include_decompile":true,"include_proto":true},{"addr":"0x7071c0","include_decompile":true,"include_proto":true},{"addr":"0x7072d0","include_decompile":true,"include_proto":true},{"addr":"0x707370","include_decompile":true,"include_proto":true},{"addr":"0x7073e0","include_decompile":true,"include_proto":true},{"addr":"0x707420","include_decompile":true,"include_proto":true},{"addr":"0x707490","include_decompile":true,"include_proto":true},{"addr":"0x707500","include_decompile":true,"include_proto":true},{"addr":"0x707510","include_decompile":true,"include_proto":true},{"addr":"0x707560","include_decompile":true,"include_proto":true},{"addr":"0x707570","include_decompile":true,"include_proto":true},{"addr":"0x7075b0","include_decompile":true,"include_proto":true},{"addr":"0x7075c0","include_decompile":true,"include_proto":true},{"addr":"0x7075e0","include_decompile":true,"include_proto":true},{"addr":"0x707600","include_decompile":true,"include_proto":true},{"addr":"0x707610","include_decompile":true,"include_proto":true},{"addr":"0x707620","include_decompile":true,"include_proto":true},{"addr":"0x707630","include_decompile":true,"include_proto":true},{"addr":"0x707640","include_decompile":true,"include_proto":true},{"addr":"0x707650","include_decompile":true,"include_proto":true},{"addr":"0x707670","include_decompile":true,"include_proto":true},{"addr":"0x707680","include_decompile":true,"include_proto":true},{"addr":"0x707ac0","include_decompile":true,"include_proto":true},{"addr":"0x707b40","include_decompile":true,"include_proto":true},{"addr":"0x707b90","include_decompile":true,"include_proto":true},{"addr":"0x707c10","include_decompile":true,"include_proto":true},{"addr":"0x707c80","include_decompile":true,"include_proto":true},{"addr":"0x707ca0","include_decompile":true,"include_proto":true},{"addr":"0x707cb0","include_decompile":true,"include_proto":true},{"addr":"0x707cc0","include_decompile":true,"include_proto":true},{"addr":"0x707cd0","include_decompile":true,"include_proto":true},{"addr":"0x707cf0","include_decompile":true,"include_proto":true},{"addr":"0x707d00","include_decompile":true,"include_proto":true},{"addr":"0x707d20","include_decompile":true,"include_proto":true},{"addr":"0x707d30","include_decompile":true,"include_proto":true},{"addr":"0x707d50","include_decompile":true,"include_proto":true},{"addr":"0x707d70","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0124', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0124: empty response'); return; }
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
      console.log('Batch 0124: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0124 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0124 conn error:', e.message));
req.write(body);
req.end();
