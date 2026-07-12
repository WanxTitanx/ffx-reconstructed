
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7ab2c0","include_decompile":true,"include_proto":true},{"addr":"0x7ab320","include_decompile":true,"include_proto":true},{"addr":"0x7ab380","include_decompile":true,"include_proto":true},{"addr":"0x7ab520","include_decompile":true,"include_proto":true},{"addr":"0x7ab540","include_decompile":true,"include_proto":true},{"addr":"0x7ab560","include_decompile":true,"include_proto":true},{"addr":"0x7ab6e0","include_decompile":true,"include_proto":true},{"addr":"0x7ab720","include_decompile":true,"include_proto":true},{"addr":"0x7ab750","include_decompile":true,"include_proto":true},{"addr":"0x7ab770","include_decompile":true,"include_proto":true},{"addr":"0x7ab890","include_decompile":true,"include_proto":true},{"addr":"0x7ab910","include_decompile":true,"include_proto":true},{"addr":"0x7ab930","include_decompile":true,"include_proto":true},{"addr":"0x7ab990","include_decompile":true,"include_proto":true},{"addr":"0x7aba10","include_decompile":true,"include_proto":true},{"addr":"0x7abb90","include_decompile":true,"include_proto":true},{"addr":"0x7abbc0","include_decompile":true,"include_proto":true},{"addr":"0x7abbf0","include_decompile":true,"include_proto":true},{"addr":"0x7abc80","include_decompile":true,"include_proto":true},{"addr":"0x7abcc0","include_decompile":true,"include_proto":true},{"addr":"0x7abd30","include_decompile":true,"include_proto":true},{"addr":"0x7abde0","include_decompile":true,"include_proto":true},{"addr":"0x7abe10","include_decompile":true,"include_proto":true},{"addr":"0x7abe50","include_decompile":true,"include_proto":true},{"addr":"0x7abed0","include_decompile":true,"include_proto":true},{"addr":"0x7abf60","include_decompile":true,"include_proto":true},{"addr":"0x7ac000","include_decompile":true,"include_proto":true},{"addr":"0x7ac2d0","include_decompile":true,"include_proto":true},{"addr":"0x7ac620","include_decompile":true,"include_proto":true},{"addr":"0x7ac670","include_decompile":true,"include_proto":true},{"addr":"0x7ac6a0","include_decompile":true,"include_proto":true},{"addr":"0x7ac6c0","include_decompile":true,"include_proto":true},{"addr":"0x7ac860","include_decompile":true,"include_proto":true},{"addr":"0x7ac960","include_decompile":true,"include_proto":true},{"addr":"0x7ac9e0","include_decompile":true,"include_proto":true},{"addr":"0x7acb20","include_decompile":true,"include_proto":true},{"addr":"0x7acb60","include_decompile":true,"include_proto":true},{"addr":"0x7accb0","include_decompile":true,"include_proto":true},{"addr":"0x7acd60","include_decompile":true,"include_proto":true},{"addr":"0x7aceb0","include_decompile":true,"include_proto":true},{"addr":"0x7acec0","include_decompile":true,"include_proto":true},{"addr":"0x7ad0d0","include_decompile":true,"include_proto":true},{"addr":"0x7ad140","include_decompile":true,"include_proto":true},{"addr":"0x7ad190","include_decompile":true,"include_proto":true},{"addr":"0x7ad1a0","include_decompile":true,"include_proto":true},{"addr":"0x7ad400","include_decompile":true,"include_proto":true},{"addr":"0x7ad480","include_decompile":true,"include_proto":true},{"addr":"0x7ad580","include_decompile":true,"include_proto":true},{"addr":"0x7ad5c0","include_decompile":true,"include_proto":true},{"addr":"0x7ad5f0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0186', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0186: empty response'); return; }
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
      console.log('Batch 0186: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0186 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0186 conn error:', e.message));
req.write(body);
req.end();
