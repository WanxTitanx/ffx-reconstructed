
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x76b970","include_decompile":true,"include_proto":true},{"addr":"0x76b9e0","include_decompile":true,"include_proto":true},{"addr":"0x76ba50","include_decompile":true,"include_proto":true},{"addr":"0x76ba70","include_decompile":true,"include_proto":true},{"addr":"0x76ba80","include_decompile":true,"include_proto":true},{"addr":"0x76bee0","include_decompile":true,"include_proto":true},{"addr":"0x76c080","include_decompile":true,"include_proto":true},{"addr":"0x76c360","include_decompile":true,"include_proto":true},{"addr":"0x76c380","include_decompile":true,"include_proto":true},{"addr":"0x76c430","include_decompile":true,"include_proto":true},{"addr":"0x76c520","include_decompile":true,"include_proto":true},{"addr":"0x76c550","include_decompile":true,"include_proto":true},{"addr":"0x76c5a0","include_decompile":true,"include_proto":true},{"addr":"0x76c620","include_decompile":true,"include_proto":true},{"addr":"0x76c670","include_decompile":true,"include_proto":true},{"addr":"0x76cdc0","include_decompile":true,"include_proto":true},{"addr":"0x76cf30","include_decompile":true,"include_proto":true},{"addr":"0x76cf60","include_decompile":true,"include_proto":true},{"addr":"0x76d080","include_decompile":true,"include_proto":true},{"addr":"0x76d0a0","include_decompile":true,"include_proto":true},{"addr":"0x76d0c0","include_decompile":true,"include_proto":true},{"addr":"0x76d0e0","include_decompile":true,"include_proto":true},{"addr":"0x76d0f0","include_decompile":true,"include_proto":true},{"addr":"0x76d100","include_decompile":true,"include_proto":true},{"addr":"0x76d1e0","include_decompile":true,"include_proto":true},{"addr":"0x76d1f0","include_decompile":true,"include_proto":true},{"addr":"0x76d250","include_decompile":true,"include_proto":true},{"addr":"0x76d310","include_decompile":true,"include_proto":true},{"addr":"0x76d550","include_decompile":true,"include_proto":true},{"addr":"0x76d620","include_decompile":true,"include_proto":true},{"addr":"0x76d640","include_decompile":true,"include_proto":true},{"addr":"0x76d6b0","include_decompile":true,"include_proto":true},{"addr":"0x76d710","include_decompile":true,"include_proto":true},{"addr":"0x76d770","include_decompile":true,"include_proto":true},{"addr":"0x76d7c0","include_decompile":true,"include_proto":true},{"addr":"0x76d7d0","include_decompile":true,"include_proto":true},{"addr":"0x76d850","include_decompile":true,"include_proto":true},{"addr":"0x76d8d0","include_decompile":true,"include_proto":true},{"addr":"0x76d950","include_decompile":true,"include_proto":true},{"addr":"0x76d9d0","include_decompile":true,"include_proto":true},{"addr":"0x76da50","include_decompile":true,"include_proto":true},{"addr":"0x76dad0","include_decompile":true,"include_proto":true},{"addr":"0x76db50","include_decompile":true,"include_proto":true},{"addr":"0x76dbd0","include_decompile":true,"include_proto":true},{"addr":"0x76dc50","include_decompile":true,"include_proto":true},{"addr":"0x76dd30","include_decompile":true,"include_proto":true},{"addr":"0x76dd60","include_decompile":true,"include_proto":true},{"addr":"0x76dd70","include_decompile":true,"include_proto":true},{"addr":"0x76dd80","include_decompile":true,"include_proto":true},{"addr":"0x76ddc0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0147', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0147: empty response'); return; }
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
      console.log('Batch 0147: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0147 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0147 conn error:', e.message));
req.write(body);
req.end();
