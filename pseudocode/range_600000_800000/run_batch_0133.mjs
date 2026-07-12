
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x72a270","include_decompile":true,"include_proto":true},{"addr":"0x72a350","include_decompile":true,"include_proto":true},{"addr":"0x72a3d0","include_decompile":true,"include_proto":true},{"addr":"0x72a620","include_decompile":true,"include_proto":true},{"addr":"0x72a680","include_decompile":true,"include_proto":true},{"addr":"0x72a6d0","include_decompile":true,"include_proto":true},{"addr":"0x72a720","include_decompile":true,"include_proto":true},{"addr":"0x72a780","include_decompile":true,"include_proto":true},{"addr":"0x72a840","include_decompile":true,"include_proto":true},{"addr":"0x72a850","include_decompile":true,"include_proto":true},{"addr":"0x72a8e0","include_decompile":true,"include_proto":true},{"addr":"0x72ab30","include_decompile":true,"include_proto":true},{"addr":"0x72ac10","include_decompile":true,"include_proto":true},{"addr":"0x72ad10","include_decompile":true,"include_proto":true},{"addr":"0x72ad20","include_decompile":true,"include_proto":true},{"addr":"0x72c280","include_decompile":true,"include_proto":true},{"addr":"0x72c290","include_decompile":true,"include_proto":true},{"addr":"0x72c2a0","include_decompile":true,"include_proto":true},{"addr":"0x72c4c0","include_decompile":true,"include_proto":true},{"addr":"0x72c570","include_decompile":true,"include_proto":true},{"addr":"0x72c600","include_decompile":true,"include_proto":true},{"addr":"0x72c680","include_decompile":true,"include_proto":true},{"addr":"0x72c6e0","include_decompile":true,"include_proto":true},{"addr":"0x72c740","include_decompile":true,"include_proto":true},{"addr":"0x72c790","include_decompile":true,"include_proto":true},{"addr":"0x72c820","include_decompile":true,"include_proto":true},{"addr":"0x72c8f0","include_decompile":true,"include_proto":true},{"addr":"0x72c980","include_decompile":true,"include_proto":true},{"addr":"0x72ca10","include_decompile":true,"include_proto":true},{"addr":"0x72cae0","include_decompile":true,"include_proto":true},{"addr":"0x72cb70","include_decompile":true,"include_proto":true},{"addr":"0x72cc00","include_decompile":true,"include_proto":true},{"addr":"0x72ccd0","include_decompile":true,"include_proto":true},{"addr":"0x72cd60","include_decompile":true,"include_proto":true},{"addr":"0x72cdf0","include_decompile":true,"include_proto":true},{"addr":"0x72d290","include_decompile":true,"include_proto":true},{"addr":"0x72d470","include_decompile":true,"include_proto":true},{"addr":"0x72d650","include_decompile":true,"include_proto":true},{"addr":"0x72d830","include_decompile":true,"include_proto":true},{"addr":"0x72da10","include_decompile":true,"include_proto":true},{"addr":"0x72dbf0","include_decompile":true,"include_proto":true},{"addr":"0x72ddd0","include_decompile":true,"include_proto":true},{"addr":"0x72dfb0","include_decompile":true,"include_proto":true},{"addr":"0x72e7b0","include_decompile":true,"include_proto":true},{"addr":"0x72e810","include_decompile":true,"include_proto":true},{"addr":"0x72e840","include_decompile":true,"include_proto":true},{"addr":"0x72e870","include_decompile":true,"include_proto":true},{"addr":"0x72ec00","include_decompile":true,"include_proto":true},{"addr":"0x72ee50","include_decompile":true,"include_proto":true},{"addr":"0x72ee90","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0133', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0133: empty response'); return; }
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
      console.log('Batch 0133: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0133 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0133 conn error:', e.message));
req.write(body);
req.end();
