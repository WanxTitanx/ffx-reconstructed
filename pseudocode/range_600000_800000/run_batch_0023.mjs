
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x626a40","include_decompile":true,"include_proto":true},{"addr":"0x626a90","include_decompile":true,"include_proto":true},{"addr":"0x626b10","include_decompile":true,"include_proto":true},{"addr":"0x626bb0","include_decompile":true,"include_proto":true},{"addr":"0x626c50","include_decompile":true,"include_proto":true},{"addr":"0x626d40","include_decompile":true,"include_proto":true},{"addr":"0x626dd0","include_decompile":true,"include_proto":true},{"addr":"0x626df0","include_decompile":true,"include_proto":true},{"addr":"0x626e40","include_decompile":true,"include_proto":true},{"addr":"0x626e60","include_decompile":true,"include_proto":true},{"addr":"0x6271e0","include_decompile":true,"include_proto":true},{"addr":"0x627210","include_decompile":true,"include_proto":true},{"addr":"0x627240","include_decompile":true,"include_proto":true},{"addr":"0x627250","include_decompile":true,"include_proto":true},{"addr":"0x6272a0","include_decompile":true,"include_proto":true},{"addr":"0x6272e0","include_decompile":true,"include_proto":true},{"addr":"0x627380","include_decompile":true,"include_proto":true},{"addr":"0x627630","include_decompile":true,"include_proto":true},{"addr":"0x627770","include_decompile":true,"include_proto":true},{"addr":"0x627780","include_decompile":true,"include_proto":true},{"addr":"0x627790","include_decompile":true,"include_proto":true},{"addr":"0x627890","include_decompile":true,"include_proto":true},{"addr":"0x627960","include_decompile":true,"include_proto":true},{"addr":"0x627980","include_decompile":true,"include_proto":true},{"addr":"0x6279c0","include_decompile":true,"include_proto":true},{"addr":"0x627a00","include_decompile":true,"include_proto":true},{"addr":"0x627a60","include_decompile":true,"include_proto":true},{"addr":"0x627ac0","include_decompile":true,"include_proto":true},{"addr":"0x627ad0","include_decompile":true,"include_proto":true},{"addr":"0x627ae0","include_decompile":true,"include_proto":true},{"addr":"0x627af0","include_decompile":true,"include_proto":true},{"addr":"0x628000","include_decompile":true,"include_proto":true},{"addr":"0x628010","include_decompile":true,"include_proto":true},{"addr":"0x628040","include_decompile":true,"include_proto":true},{"addr":"0x628070","include_decompile":true,"include_proto":true},{"addr":"0x6280a0","include_decompile":true,"include_proto":true},{"addr":"0x628120","include_decompile":true,"include_proto":true},{"addr":"0x628150","include_decompile":true,"include_proto":true},{"addr":"0x6281c0","include_decompile":true,"include_proto":true},{"addr":"0x6281f0","include_decompile":true,"include_proto":true},{"addr":"0x628220","include_decompile":true,"include_proto":true},{"addr":"0x628250","include_decompile":true,"include_proto":true},{"addr":"0x628280","include_decompile":true,"include_proto":true},{"addr":"0x628290","include_decompile":true,"include_proto":true},{"addr":"0x6282c0","include_decompile":true,"include_proto":true},{"addr":"0x6282d0","include_decompile":true,"include_proto":true},{"addr":"0x6282e0","include_decompile":true,"include_proto":true},{"addr":"0x6282f0","include_decompile":true,"include_proto":true},{"addr":"0x628310","include_decompile":true,"include_proto":true},{"addr":"0x628320","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0023', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0023: empty response'); return; }
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
      console.log('Batch 0023: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0023 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0023 conn error:', e.message));
req.write(body);
req.end();
