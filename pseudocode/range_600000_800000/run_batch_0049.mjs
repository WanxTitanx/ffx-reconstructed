
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x64bd30","include_decompile":true,"include_proto":true},{"addr":"0x64bd40","include_decompile":true,"include_proto":true},{"addr":"0x64bf90","include_decompile":true,"include_proto":true},{"addr":"0x64c010","include_decompile":true,"include_proto":true},{"addr":"0x64c020","include_decompile":true,"include_proto":true},{"addr":"0x64c090","include_decompile":true,"include_proto":true},{"addr":"0x64c0f0","include_decompile":true,"include_proto":true},{"addr":"0x64c150","include_decompile":true,"include_proto":true},{"addr":"0x64c1d0","include_decompile":true,"include_proto":true},{"addr":"0x64c250","include_decompile":true,"include_proto":true},{"addr":"0x64c380","include_decompile":true,"include_proto":true},{"addr":"0x64c3a0","include_decompile":true,"include_proto":true},{"addr":"0x64c3b0","include_decompile":true,"include_proto":true},{"addr":"0x64c3c0","include_decompile":true,"include_proto":true},{"addr":"0x64c3e0","include_decompile":true,"include_proto":true},{"addr":"0x64c400","include_decompile":true,"include_proto":true},{"addr":"0x64c420","include_decompile":true,"include_proto":true},{"addr":"0x64c430","include_decompile":true,"include_proto":true},{"addr":"0x64c450","include_decompile":true,"include_proto":true},{"addr":"0x64c460","include_decompile":true,"include_proto":true},{"addr":"0x64c480","include_decompile":true,"include_proto":true},{"addr":"0x64c490","include_decompile":true,"include_proto":true},{"addr":"0x64c4b0","include_decompile":true,"include_proto":true},{"addr":"0x64c4d0","include_decompile":true,"include_proto":true},{"addr":"0x64c4e0","include_decompile":true,"include_proto":true},{"addr":"0x64c500","include_decompile":true,"include_proto":true},{"addr":"0x64c520","include_decompile":true,"include_proto":true},{"addr":"0x64c560","include_decompile":true,"include_proto":true},{"addr":"0x64c5a0","include_decompile":true,"include_proto":true},{"addr":"0x64c5b0","include_decompile":true,"include_proto":true},{"addr":"0x64c5d0","include_decompile":true,"include_proto":true},{"addr":"0x64c5e0","include_decompile":true,"include_proto":true},{"addr":"0x64c660","include_decompile":true,"include_proto":true},{"addr":"0x64c680","include_decompile":true,"include_proto":true},{"addr":"0x64c6d0","include_decompile":true,"include_proto":true},{"addr":"0x64c6f0","include_decompile":true,"include_proto":true},{"addr":"0x64c710","include_decompile":true,"include_proto":true},{"addr":"0x64c760","include_decompile":true,"include_proto":true},{"addr":"0x64c780","include_decompile":true,"include_proto":true},{"addr":"0x64c7a0","include_decompile":true,"include_proto":true},{"addr":"0x64c7c0","include_decompile":true,"include_proto":true},{"addr":"0x64c7e0","include_decompile":true,"include_proto":true},{"addr":"0x64c800","include_decompile":true,"include_proto":true},{"addr":"0x64c820","include_decompile":true,"include_proto":true},{"addr":"0x64c840","include_decompile":true,"include_proto":true},{"addr":"0x64c850","include_decompile":true,"include_proto":true},{"addr":"0x64c860","include_decompile":true,"include_proto":true},{"addr":"0x64c870","include_decompile":true,"include_proto":true},{"addr":"0x64c9a0","include_decompile":true,"include_proto":true},{"addr":"0x64ca10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0049', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0049: empty response'); return; }
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
      console.log('Batch 0049: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0049 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0049 conn error:', e.message));
req.write(body);
req.end();
