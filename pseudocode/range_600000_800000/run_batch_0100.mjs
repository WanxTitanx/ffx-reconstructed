
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6c5cc0","include_decompile":true,"include_proto":true},{"addr":"0x6c5dd0","include_decompile":true,"include_proto":true},{"addr":"0x6c5ee0","include_decompile":true,"include_proto":true},{"addr":"0x6c5f70","include_decompile":true,"include_proto":true},{"addr":"0x6c6000","include_decompile":true,"include_proto":true},{"addr":"0x6c64d0","include_decompile":true,"include_proto":true},{"addr":"0x6c6970","include_decompile":true,"include_proto":true},{"addr":"0x6c6d70","include_decompile":true,"include_proto":true},{"addr":"0x6c71d0","include_decompile":true,"include_proto":true},{"addr":"0x6c72d0","include_decompile":true,"include_proto":true},{"addr":"0x6c7390","include_decompile":true,"include_proto":true},{"addr":"0x6c7460","include_decompile":true,"include_proto":true},{"addr":"0x6c7550","include_decompile":true,"include_proto":true},{"addr":"0x6c7610","include_decompile":true,"include_proto":true},{"addr":"0x6c76a0","include_decompile":true,"include_proto":true},{"addr":"0x6c7740","include_decompile":true,"include_proto":true},{"addr":"0x6c7860","include_decompile":true,"include_proto":true},{"addr":"0x6c7870","include_decompile":true,"include_proto":true},{"addr":"0x6c78e0","include_decompile":true,"include_proto":true},{"addr":"0x6c79d0","include_decompile":true,"include_proto":true},{"addr":"0x6c7a30","include_decompile":true,"include_proto":true},{"addr":"0x6c7a40","include_decompile":true,"include_proto":true},{"addr":"0x6c7d00","include_decompile":true,"include_proto":true},{"addr":"0x6c7d10","include_decompile":true,"include_proto":true},{"addr":"0x6c7db0","include_decompile":true,"include_proto":true},{"addr":"0x6c7de0","include_decompile":true,"include_proto":true},{"addr":"0x6c7df0","include_decompile":true,"include_proto":true},{"addr":"0x6c7e00","include_decompile":true,"include_proto":true},{"addr":"0x6c7ec0","include_decompile":true,"include_proto":true},{"addr":"0x6c7fa0","include_decompile":true,"include_proto":true},{"addr":"0x6c8020","include_decompile":true,"include_proto":true},{"addr":"0x6c8180","include_decompile":true,"include_proto":true},{"addr":"0x6c81d0","include_decompile":true,"include_proto":true},{"addr":"0x6c85c0","include_decompile":true,"include_proto":true},{"addr":"0x6c89e0","include_decompile":true,"include_proto":true},{"addr":"0x6c9090","include_decompile":true,"include_proto":true},{"addr":"0x6c93b0","include_decompile":true,"include_proto":true},{"addr":"0x6c9620","include_decompile":true,"include_proto":true},{"addr":"0x6c9640","include_decompile":true,"include_proto":true},{"addr":"0x6c96c0","include_decompile":true,"include_proto":true},{"addr":"0x6c98c0","include_decompile":true,"include_proto":true},{"addr":"0x6c9f40","include_decompile":true,"include_proto":true},{"addr":"0x6c9f80","include_decompile":true,"include_proto":true},{"addr":"0x6cb010","include_decompile":true,"include_proto":true},{"addr":"0x6cc050","include_decompile":true,"include_proto":true},{"addr":"0x6cc9e0","include_decompile":true,"include_proto":true},{"addr":"0x6cc9f0","include_decompile":true,"include_proto":true},{"addr":"0x6cca10","include_decompile":true,"include_proto":true},{"addr":"0x6cca30","include_decompile":true,"include_proto":true},{"addr":"0x6cca50","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0100', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0100: empty response'); return; }
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
      console.log('Batch 0100: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0100 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0100 conn error:', e.message));
req.write(body);
req.end();
