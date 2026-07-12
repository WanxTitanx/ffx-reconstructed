
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x624f00","include_decompile":true,"include_proto":true},{"addr":"0x624f30","include_decompile":true,"include_proto":true},{"addr":"0x624f60","include_decompile":true,"include_proto":true},{"addr":"0x625250","include_decompile":true,"include_proto":true},{"addr":"0x625290","include_decompile":true,"include_proto":true},{"addr":"0x6252a0","include_decompile":true,"include_proto":true},{"addr":"0x6252f0","include_decompile":true,"include_proto":true},{"addr":"0x625790","include_decompile":true,"include_proto":true},{"addr":"0x625840","include_decompile":true,"include_proto":true},{"addr":"0x6258e0","include_decompile":true,"include_proto":true},{"addr":"0x625930","include_decompile":true,"include_proto":true},{"addr":"0x625a10","include_decompile":true,"include_proto":true},{"addr":"0x625a40","include_decompile":true,"include_proto":true},{"addr":"0x625a90","include_decompile":true,"include_proto":true},{"addr":"0x625aa0","include_decompile":true,"include_proto":true},{"addr":"0x625b20","include_decompile":true,"include_proto":true},{"addr":"0x625ba0","include_decompile":true,"include_proto":true},{"addr":"0x625bb0","include_decompile":true,"include_proto":true},{"addr":"0x625be0","include_decompile":true,"include_proto":true},{"addr":"0x625bf0","include_decompile":true,"include_proto":true},{"addr":"0x625c00","include_decompile":true,"include_proto":true},{"addr":"0x625c10","include_decompile":true,"include_proto":true},{"addr":"0x625c20","include_decompile":true,"include_proto":true},{"addr":"0x625c80","include_decompile":true,"include_proto":true},{"addr":"0x625ca0","include_decompile":true,"include_proto":true},{"addr":"0x625cc0","include_decompile":true,"include_proto":true},{"addr":"0x625d20","include_decompile":true,"include_proto":true},{"addr":"0x625e30","include_decompile":true,"include_proto":true},{"addr":"0x625e60","include_decompile":true,"include_proto":true},{"addr":"0x625ec0","include_decompile":true,"include_proto":true},{"addr":"0x625ed0","include_decompile":true,"include_proto":true},{"addr":"0x625f90","include_decompile":true,"include_proto":true},{"addr":"0x626090","include_decompile":true,"include_proto":true},{"addr":"0x626110","include_decompile":true,"include_proto":true},{"addr":"0x626210","include_decompile":true,"include_proto":true},{"addr":"0x626220","include_decompile":true,"include_proto":true},{"addr":"0x6264c0","include_decompile":true,"include_proto":true},{"addr":"0x6264d0","include_decompile":true,"include_proto":true},{"addr":"0x6264e0","include_decompile":true,"include_proto":true},{"addr":"0x626590","include_decompile":true,"include_proto":true},{"addr":"0x6266a0","include_decompile":true,"include_proto":true},{"addr":"0x626700","include_decompile":true,"include_proto":true},{"addr":"0x626740","include_decompile":true,"include_proto":true},{"addr":"0x626790","include_decompile":true,"include_proto":true},{"addr":"0x6267e0","include_decompile":true,"include_proto":true},{"addr":"0x626850","include_decompile":true,"include_proto":true},{"addr":"0x6268b0","include_decompile":true,"include_proto":true},{"addr":"0x626930","include_decompile":true,"include_proto":true},{"addr":"0x626990","include_decompile":true,"include_proto":true},{"addr":"0x6269e0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0022', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0022: empty response'); return; }
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
      console.log('Batch 0022: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0022 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0022 conn error:', e.message));
req.write(body);
req.end();
