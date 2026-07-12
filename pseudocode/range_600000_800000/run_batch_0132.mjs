
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x71edb0","include_decompile":true,"include_proto":true},{"addr":"0x71edf0","include_decompile":true,"include_proto":true},{"addr":"0x71ee90","include_decompile":true,"include_proto":true},{"addr":"0x71ef60","include_decompile":true,"include_proto":true},{"addr":"0x71f400","include_decompile":true,"include_proto":true},{"addr":"0x7257a0","include_decompile":true,"include_proto":true},{"addr":"0x726a90","include_decompile":true,"include_proto":true},{"addr":"0x727200","include_decompile":true,"include_proto":true},{"addr":"0x7283c0","include_decompile":true,"include_proto":true},{"addr":"0x728750","include_decompile":true,"include_proto":true},{"addr":"0x728840","include_decompile":true,"include_proto":true},{"addr":"0x7288a0","include_decompile":true,"include_proto":true},{"addr":"0x728ac0","include_decompile":true,"include_proto":true},{"addr":"0x728b50","include_decompile":true,"include_proto":true},{"addr":"0x728ba0","include_decompile":true,"include_proto":true},{"addr":"0x728bb0","include_decompile":true,"include_proto":true},{"addr":"0x728ec0","include_decompile":true,"include_proto":true},{"addr":"0x728f30","include_decompile":true,"include_proto":true},{"addr":"0x729000","include_decompile":true,"include_proto":true},{"addr":"0x729140","include_decompile":true,"include_proto":true},{"addr":"0x729150","include_decompile":true,"include_proto":true},{"addr":"0x7292b0","include_decompile":true,"include_proto":true},{"addr":"0x729370","include_decompile":true,"include_proto":true},{"addr":"0x729380","include_decompile":true,"include_proto":true},{"addr":"0x7293c0","include_decompile":true,"include_proto":true},{"addr":"0x7293e0","include_decompile":true,"include_proto":true},{"addr":"0x7294c0","include_decompile":true,"include_proto":true},{"addr":"0x7294d0","include_decompile":true,"include_proto":true},{"addr":"0x7294e0","include_decompile":true,"include_proto":true},{"addr":"0x7294f0","include_decompile":true,"include_proto":true},{"addr":"0x729530","include_decompile":true,"include_proto":true},{"addr":"0x729570","include_decompile":true,"include_proto":true},{"addr":"0x7295e0","include_decompile":true,"include_proto":true},{"addr":"0x729620","include_decompile":true,"include_proto":true},{"addr":"0x729660","include_decompile":true,"include_proto":true},{"addr":"0x7296a0","include_decompile":true,"include_proto":true},{"addr":"0x7296e0","include_decompile":true,"include_proto":true},{"addr":"0x729750","include_decompile":true,"include_proto":true},{"addr":"0x729790","include_decompile":true,"include_proto":true},{"addr":"0x7297f0","include_decompile":true,"include_proto":true},{"addr":"0x729830","include_decompile":true,"include_proto":true},{"addr":"0x7298d0","include_decompile":true,"include_proto":true},{"addr":"0x729900","include_decompile":true,"include_proto":true},{"addr":"0x729940","include_decompile":true,"include_proto":true},{"addr":"0x729ad0","include_decompile":true,"include_proto":true},{"addr":"0x729b00","include_decompile":true,"include_proto":true},{"addr":"0x729ba0","include_decompile":true,"include_proto":true},{"addr":"0x72a060","include_decompile":true,"include_proto":true},{"addr":"0x72a080","include_decompile":true,"include_proto":true},{"addr":"0x72a210","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0132', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0132: empty response'); return; }
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
      console.log('Batch 0132: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0132 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0132 conn error:', e.message));
req.write(body);
req.end();
