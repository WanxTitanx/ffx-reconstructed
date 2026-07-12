
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x69d440","include_decompile":true,"include_proto":true},{"addr":"0x69d460","include_decompile":true,"include_proto":true},{"addr":"0x69d480","include_decompile":true,"include_proto":true},{"addr":"0x69d4a0","include_decompile":true,"include_proto":true},{"addr":"0x69d4c0","include_decompile":true,"include_proto":true},{"addr":"0x69d4e0","include_decompile":true,"include_proto":true},{"addr":"0x69d500","include_decompile":true,"include_proto":true},{"addr":"0x69d520","include_decompile":true,"include_proto":true},{"addr":"0x69d730","include_decompile":true,"include_proto":true},{"addr":"0x69d740","include_decompile":true,"include_proto":true},{"addr":"0x69d750","include_decompile":true,"include_proto":true},{"addr":"0x69d760","include_decompile":true,"include_proto":true},{"addr":"0x69d770","include_decompile":true,"include_proto":true},{"addr":"0x69d780","include_decompile":true,"include_proto":true},{"addr":"0x69d820","include_decompile":true,"include_proto":true},{"addr":"0x69d830","include_decompile":true,"include_proto":true},{"addr":"0x69d840","include_decompile":true,"include_proto":true},{"addr":"0x69d860","include_decompile":true,"include_proto":true},{"addr":"0x69d870","include_decompile":true,"include_proto":true},{"addr":"0x69d880","include_decompile":true,"include_proto":true},{"addr":"0x69d890","include_decompile":true,"include_proto":true},{"addr":"0x69d8a0","include_decompile":true,"include_proto":true},{"addr":"0x69d8b0","include_decompile":true,"include_proto":true},{"addr":"0x69d8c0","include_decompile":true,"include_proto":true},{"addr":"0x69d8d0","include_decompile":true,"include_proto":true},{"addr":"0x69d8e0","include_decompile":true,"include_proto":true},{"addr":"0x69d8f0","include_decompile":true,"include_proto":true},{"addr":"0x69d900","include_decompile":true,"include_proto":true},{"addr":"0x69d910","include_decompile":true,"include_proto":true},{"addr":"0x69d920","include_decompile":true,"include_proto":true},{"addr":"0x69d930","include_decompile":true,"include_proto":true},{"addr":"0x69d940","include_decompile":true,"include_proto":true},{"addr":"0x69d950","include_decompile":true,"include_proto":true},{"addr":"0x69d960","include_decompile":true,"include_proto":true},{"addr":"0x69d970","include_decompile":true,"include_proto":true},{"addr":"0x69d980","include_decompile":true,"include_proto":true},{"addr":"0x69d990","include_decompile":true,"include_proto":true},{"addr":"0x69d9a0","include_decompile":true,"include_proto":true},{"addr":"0x69dad0","include_decompile":true,"include_proto":true},{"addr":"0x69db60","include_decompile":true,"include_proto":true},{"addr":"0x69dc20","include_decompile":true,"include_proto":true},{"addr":"0x69dca0","include_decompile":true,"include_proto":true},{"addr":"0x69dcb0","include_decompile":true,"include_proto":true},{"addr":"0x69dd40","include_decompile":true,"include_proto":true},{"addr":"0x69ddb0","include_decompile":true,"include_proto":true},{"addr":"0x69dfc0","include_decompile":true,"include_proto":true},{"addr":"0x69dfd0","include_decompile":true,"include_proto":true},{"addr":"0x69dfe0","include_decompile":true,"include_proto":true},{"addr":"0x69dff0","include_decompile":true,"include_proto":true},{"addr":"0x69e000","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0083', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0083: empty response'); return; }
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
      console.log('Batch 0083: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0083 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0083 conn error:', e.message));
req.write(body);
req.end();
