
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x74e360","include_decompile":true,"include_proto":true},{"addr":"0x74e490","include_decompile":true,"include_proto":true},{"addr":"0x74e570","include_decompile":true,"include_proto":true},{"addr":"0x74e620","include_decompile":true,"include_proto":true},{"addr":"0x74e650","include_decompile":true,"include_proto":true},{"addr":"0x74f030","include_decompile":true,"include_proto":true},{"addr":"0x74f110","include_decompile":true,"include_proto":true},{"addr":"0x74f3a0","include_decompile":true,"include_proto":true},{"addr":"0x74f4d0","include_decompile":true,"include_proto":true},{"addr":"0x74f5b0","include_decompile":true,"include_proto":true},{"addr":"0x74f660","include_decompile":true,"include_proto":true},{"addr":"0x74f690","include_decompile":true,"include_proto":true},{"addr":"0x7500f0","include_decompile":true,"include_proto":true},{"addr":"0x7501a0","include_decompile":true,"include_proto":true},{"addr":"0x750200","include_decompile":true,"include_proto":true},{"addr":"0x7502a0","include_decompile":true,"include_proto":true},{"addr":"0x750380","include_decompile":true,"include_proto":true},{"addr":"0x750390","include_decompile":true,"include_proto":true},{"addr":"0x7505e0","include_decompile":true,"include_proto":true},{"addr":"0x750670","include_decompile":true,"include_proto":true},{"addr":"0x750700","include_decompile":true,"include_proto":true},{"addr":"0x751760","include_decompile":true,"include_proto":true},{"addr":"0x751820","include_decompile":true,"include_proto":true},{"addr":"0x751a10","include_decompile":true,"include_proto":true},{"addr":"0x751ab0","include_decompile":true,"include_proto":true},{"addr":"0x751b90","include_decompile":true,"include_proto":true},{"addr":"0x751d80","include_decompile":true,"include_proto":true},{"addr":"0x751f90","include_decompile":true,"include_proto":true},{"addr":"0x752020","include_decompile":true,"include_proto":true},{"addr":"0x7520b0","include_decompile":true,"include_proto":true},{"addr":"0x753170","include_decompile":true,"include_proto":true},{"addr":"0x7532b0","include_decompile":true,"include_proto":true},{"addr":"0x753320","include_decompile":true,"include_proto":true},{"addr":"0x753400","include_decompile":true,"include_proto":true},{"addr":"0x753690","include_decompile":true,"include_proto":true},{"addr":"0x753760","include_decompile":true,"include_proto":true},{"addr":"0x753ea0","include_decompile":true,"include_proto":true},{"addr":"0x754000","include_decompile":true,"include_proto":true},{"addr":"0x754270","include_decompile":true,"include_proto":true},{"addr":"0x754350","include_decompile":true,"include_proto":true},{"addr":"0x7543f0","include_decompile":true,"include_proto":true},{"addr":"0x7550a0","include_decompile":true,"include_proto":true},{"addr":"0x7550b0","include_decompile":true,"include_proto":true},{"addr":"0x7550e0","include_decompile":true,"include_proto":true},{"addr":"0x7550f0","include_decompile":true,"include_proto":true},{"addr":"0x755100","include_decompile":true,"include_proto":true},{"addr":"0x755130","include_decompile":true,"include_proto":true},{"addr":"0x755520","include_decompile":true,"include_proto":true},{"addr":"0x755af0","include_decompile":true,"include_proto":true},{"addr":"0x756330","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0140', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0140: empty response'); return; }
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
      console.log('Batch 0140: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0140 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0140 conn error:', e.message));
req.write(body);
req.end();
