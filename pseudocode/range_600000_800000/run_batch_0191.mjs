
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7b8eb0","include_decompile":true,"include_proto":true},{"addr":"0x7b8f20","include_decompile":true,"include_proto":true},{"addr":"0x7b8f40","include_decompile":true,"include_proto":true},{"addr":"0x7b8f60","include_decompile":true,"include_proto":true},{"addr":"0x7b8f70","include_decompile":true,"include_proto":true},{"addr":"0x7b8f90","include_decompile":true,"include_proto":true},{"addr":"0x7b9010","include_decompile":true,"include_proto":true},{"addr":"0x7b9030","include_decompile":true,"include_proto":true},{"addr":"0x7b90d0","include_decompile":true,"include_proto":true},{"addr":"0x7b90f0","include_decompile":true,"include_proto":true},{"addr":"0x7b9110","include_decompile":true,"include_proto":true},{"addr":"0x7b9150","include_decompile":true,"include_proto":true},{"addr":"0x7b9170","include_decompile":true,"include_proto":true},{"addr":"0x7b9180","include_decompile":true,"include_proto":true},{"addr":"0x7b91a0","include_decompile":true,"include_proto":true},{"addr":"0x7b91c0","include_decompile":true,"include_proto":true},{"addr":"0x7b91e0","include_decompile":true,"include_proto":true},{"addr":"0x7b9200","include_decompile":true,"include_proto":true},{"addr":"0x7b9220","include_decompile":true,"include_proto":true},{"addr":"0x7b9240","include_decompile":true,"include_proto":true},{"addr":"0x7b9260","include_decompile":true,"include_proto":true},{"addr":"0x7b9280","include_decompile":true,"include_proto":true},{"addr":"0x7b92a0","include_decompile":true,"include_proto":true},{"addr":"0x7b92c0","include_decompile":true,"include_proto":true},{"addr":"0x7b92e0","include_decompile":true,"include_proto":true},{"addr":"0x7b9300","include_decompile":true,"include_proto":true},{"addr":"0x7b9320","include_decompile":true,"include_proto":true},{"addr":"0x7b9340","include_decompile":true,"include_proto":true},{"addr":"0x7b9360","include_decompile":true,"include_proto":true},{"addr":"0x7b9380","include_decompile":true,"include_proto":true},{"addr":"0x7b93a0","include_decompile":true,"include_proto":true},{"addr":"0x7b93c0","include_decompile":true,"include_proto":true},{"addr":"0x7b93e0","include_decompile":true,"include_proto":true},{"addr":"0x7b9400","include_decompile":true,"include_proto":true},{"addr":"0x7b9420","include_decompile":true,"include_proto":true},{"addr":"0x7b9440","include_decompile":true,"include_proto":true},{"addr":"0x7b9460","include_decompile":true,"include_proto":true},{"addr":"0x7b9480","include_decompile":true,"include_proto":true},{"addr":"0x7b94a0","include_decompile":true,"include_proto":true},{"addr":"0x7b9500","include_decompile":true,"include_proto":true},{"addr":"0x7b9520","include_decompile":true,"include_proto":true},{"addr":"0x7b9590","include_decompile":true,"include_proto":true},{"addr":"0x7b95b0","include_decompile":true,"include_proto":true},{"addr":"0x7b9640","include_decompile":true,"include_proto":true},{"addr":"0x7b96b0","include_decompile":true,"include_proto":true},{"addr":"0x7b9720","include_decompile":true,"include_proto":true},{"addr":"0x7b9780","include_decompile":true,"include_proto":true},{"addr":"0x7b97f0","include_decompile":true,"include_proto":true},{"addr":"0x7b9860","include_decompile":true,"include_proto":true},{"addr":"0x7b98c0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0191', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0191: empty response'); return; }
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
      console.log('Batch 0191: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0191 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0191 conn error:', e.message));
req.write(body);
req.end();
