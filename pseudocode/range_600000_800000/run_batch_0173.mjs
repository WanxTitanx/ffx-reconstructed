
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x795e80","include_decompile":true,"include_proto":true},{"addr":"0x795ec0","include_decompile":true,"include_proto":true},{"addr":"0x796000","include_decompile":true,"include_proto":true},{"addr":"0x796080","include_decompile":true,"include_proto":true},{"addr":"0x7960d0","include_decompile":true,"include_proto":true},{"addr":"0x7960e0","include_decompile":true,"include_proto":true},{"addr":"0x796120","include_decompile":true,"include_proto":true},{"addr":"0x796160","include_decompile":true,"include_proto":true},{"addr":"0x7961e0","include_decompile":true,"include_proto":true},{"addr":"0x796230","include_decompile":true,"include_proto":true},{"addr":"0x7962c0","include_decompile":true,"include_proto":true},{"addr":"0x7962e0","include_decompile":true,"include_proto":true},{"addr":"0x796370","include_decompile":true,"include_proto":true},{"addr":"0x796440","include_decompile":true,"include_proto":true},{"addr":"0x796490","include_decompile":true,"include_proto":true},{"addr":"0x796560","include_decompile":true,"include_proto":true},{"addr":"0x796670","include_decompile":true,"include_proto":true},{"addr":"0x796690","include_decompile":true,"include_proto":true},{"addr":"0x7966b0","include_decompile":true,"include_proto":true},{"addr":"0x7967b0","include_decompile":true,"include_proto":true},{"addr":"0x7967d0","include_decompile":true,"include_proto":true},{"addr":"0x796800","include_decompile":true,"include_proto":true},{"addr":"0x796870","include_decompile":true,"include_proto":true},{"addr":"0x796890","include_decompile":true,"include_proto":true},{"addr":"0x7968c0","include_decompile":true,"include_proto":true},{"addr":"0x7968f0","include_decompile":true,"include_proto":true},{"addr":"0x796950","include_decompile":true,"include_proto":true},{"addr":"0x7969b0","include_decompile":true,"include_proto":true},{"addr":"0x7969d0","include_decompile":true,"include_proto":true},{"addr":"0x796a00","include_decompile":true,"include_proto":true},{"addr":"0x796bc0","include_decompile":true,"include_proto":true},{"addr":"0x796c40","include_decompile":true,"include_proto":true},{"addr":"0x796d20","include_decompile":true,"include_proto":true},{"addr":"0x796d80","include_decompile":true,"include_proto":true},{"addr":"0x796dd0","include_decompile":true,"include_proto":true},{"addr":"0x796eb0","include_decompile":true,"include_proto":true},{"addr":"0x796f30","include_decompile":true,"include_proto":true},{"addr":"0x796f80","include_decompile":true,"include_proto":true},{"addr":"0x797030","include_decompile":true,"include_proto":true},{"addr":"0x797090","include_decompile":true,"include_proto":true},{"addr":"0x7972d0","include_decompile":true,"include_proto":true},{"addr":"0x7972f0","include_decompile":true,"include_proto":true},{"addr":"0x797360","include_decompile":true,"include_proto":true},{"addr":"0x7973c0","include_decompile":true,"include_proto":true},{"addr":"0x797420","include_decompile":true,"include_proto":true},{"addr":"0x7974a0","include_decompile":true,"include_proto":true},{"addr":"0x7974f0","include_decompile":true,"include_proto":true},{"addr":"0x797510","include_decompile":true,"include_proto":true},{"addr":"0x797560","include_decompile":true,"include_proto":true},{"addr":"0x7975d0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0173', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0173: empty response'); return; }
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
      console.log('Batch 0173: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0173 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0173 conn error:', e.message));
req.write(body);
req.end();
