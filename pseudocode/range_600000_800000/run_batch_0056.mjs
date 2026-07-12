
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x65a8f0","include_decompile":true,"include_proto":true},{"addr":"0x65afd0","include_decompile":true,"include_proto":true},{"addr":"0x65b0f0","include_decompile":true,"include_proto":true},{"addr":"0x65b730","include_decompile":true,"include_proto":true},{"addr":"0x65b740","include_decompile":true,"include_proto":true},{"addr":"0x65b890","include_decompile":true,"include_proto":true},{"addr":"0x65b8a0","include_decompile":true,"include_proto":true},{"addr":"0x65b8b0","include_decompile":true,"include_proto":true},{"addr":"0x65b8c0","include_decompile":true,"include_proto":true},{"addr":"0x65b8d0","include_decompile":true,"include_proto":true},{"addr":"0x65b8e0","include_decompile":true,"include_proto":true},{"addr":"0x65b9b0","include_decompile":true,"include_proto":true},{"addr":"0x65ba20","include_decompile":true,"include_proto":true},{"addr":"0x65cd70","include_decompile":true,"include_proto":true},{"addr":"0x65d010","include_decompile":true,"include_proto":true},{"addr":"0x65d3c0","include_decompile":true,"include_proto":true},{"addr":"0x65d900","include_decompile":true,"include_proto":true},{"addr":"0x65d920","include_decompile":true,"include_proto":true},{"addr":"0x65d930","include_decompile":true,"include_proto":true},{"addr":"0x65d940","include_decompile":true,"include_proto":true},{"addr":"0x65d950","include_decompile":true,"include_proto":true},{"addr":"0x65d960","include_decompile":true,"include_proto":true},{"addr":"0x65d970","include_decompile":true,"include_proto":true},{"addr":"0x65d980","include_decompile":true,"include_proto":true},{"addr":"0x65d990","include_decompile":true,"include_proto":true},{"addr":"0x65d9a0","include_decompile":true,"include_proto":true},{"addr":"0x65d9c0","include_decompile":true,"include_proto":true},{"addr":"0x65d9d0","include_decompile":true,"include_proto":true},{"addr":"0x65d9e0","include_decompile":true,"include_proto":true},{"addr":"0x65dbf0","include_decompile":true,"include_proto":true},{"addr":"0x65dc00","include_decompile":true,"include_proto":true},{"addr":"0x65def0","include_decompile":true,"include_proto":true},{"addr":"0x65df00","include_decompile":true,"include_proto":true},{"addr":"0x65df10","include_decompile":true,"include_proto":true},{"addr":"0x65df20","include_decompile":true,"include_proto":true},{"addr":"0x65df30","include_decompile":true,"include_proto":true},{"addr":"0x65df40","include_decompile":true,"include_proto":true},{"addr":"0x65df50","include_decompile":true,"include_proto":true},{"addr":"0x65df60","include_decompile":true,"include_proto":true},{"addr":"0x65df70","include_decompile":true,"include_proto":true},{"addr":"0x65df80","include_decompile":true,"include_proto":true},{"addr":"0x65df90","include_decompile":true,"include_proto":true},{"addr":"0x65dfa0","include_decompile":true,"include_proto":true},{"addr":"0x65dfb0","include_decompile":true,"include_proto":true},{"addr":"0x65dfc0","include_decompile":true,"include_proto":true},{"addr":"0x65dfd0","include_decompile":true,"include_proto":true},{"addr":"0x65dfe0","include_decompile":true,"include_proto":true},{"addr":"0x65dff0","include_decompile":true,"include_proto":true},{"addr":"0x65e010","include_decompile":true,"include_proto":true},{"addr":"0x65e040","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0056', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0056: empty response'); return; }
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
      console.log('Batch 0056: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0056 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0056 conn error:', e.message));
req.write(body);
req.end();
