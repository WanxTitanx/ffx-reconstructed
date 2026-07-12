
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x610170","include_decompile":true,"include_proto":true},{"addr":"0x610260","include_decompile":true,"include_proto":true},{"addr":"0x610270","include_decompile":true,"include_proto":true},{"addr":"0x6102e0","include_decompile":true,"include_proto":true},{"addr":"0x610350","include_decompile":true,"include_proto":true},{"addr":"0x6103d0","include_decompile":true,"include_proto":true},{"addr":"0x610480","include_decompile":true,"include_proto":true},{"addr":"0x6104e0","include_decompile":true,"include_proto":true},{"addr":"0x610540","include_decompile":true,"include_proto":true},{"addr":"0x6105a0","include_decompile":true,"include_proto":true},{"addr":"0x6105f0","include_decompile":true,"include_proto":true},{"addr":"0x610750","include_decompile":true,"include_proto":true},{"addr":"0x6107f0","include_decompile":true,"include_proto":true},{"addr":"0x6108c0","include_decompile":true,"include_proto":true},{"addr":"0x610940","include_decompile":true,"include_proto":true},{"addr":"0x610a00","include_decompile":true,"include_proto":true},{"addr":"0x610ae0","include_decompile":true,"include_proto":true},{"addr":"0x610b70","include_decompile":true,"include_proto":true},{"addr":"0x610be0","include_decompile":true,"include_proto":true},{"addr":"0x610c50","include_decompile":true,"include_proto":true},{"addr":"0x610cc0","include_decompile":true,"include_proto":true},{"addr":"0x610e00","include_decompile":true,"include_proto":true},{"addr":"0x610e70","include_decompile":true,"include_proto":true},{"addr":"0x611050","include_decompile":true,"include_proto":true},{"addr":"0x6110c0","include_decompile":true,"include_proto":true},{"addr":"0x6110e0","include_decompile":true,"include_proto":true},{"addr":"0x6110f0","include_decompile":true,"include_proto":true},{"addr":"0x611100","include_decompile":true,"include_proto":true},{"addr":"0x611120","include_decompile":true,"include_proto":true},{"addr":"0x611130","include_decompile":true,"include_proto":true},{"addr":"0x611140","include_decompile":true,"include_proto":true},{"addr":"0x6112b0","include_decompile":true,"include_proto":true},{"addr":"0x611450","include_decompile":true,"include_proto":true},{"addr":"0x611520","include_decompile":true,"include_proto":true},{"addr":"0x611590","include_decompile":true,"include_proto":true},{"addr":"0x6115f0","include_decompile":true,"include_proto":true},{"addr":"0x611650","include_decompile":true,"include_proto":true},{"addr":"0x6116b0","include_decompile":true,"include_proto":true},{"addr":"0x611730","include_decompile":true,"include_proto":true},{"addr":"0x6117c0","include_decompile":true,"include_proto":true},{"addr":"0x611840","include_decompile":true,"include_proto":true},{"addr":"0x6118c0","include_decompile":true,"include_proto":true},{"addr":"0x611950","include_decompile":true,"include_proto":true},{"addr":"0x611960","include_decompile":true,"include_proto":true},{"addr":"0x6119e0","include_decompile":true,"include_proto":true},{"addr":"0x6119f0","include_decompile":true,"include_proto":true},{"addr":"0x611a00","include_decompile":true,"include_proto":true},{"addr":"0x611a10","include_decompile":true,"include_proto":true},{"addr":"0x611a20","include_decompile":true,"include_proto":true},{"addr":"0x611a40","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0007', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0007: empty response'); return; }
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
      console.log('Batch 0007: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0007 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0007 conn error:', e.message));
req.write(body);
req.end();
