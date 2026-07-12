
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6fee10","include_decompile":true,"include_proto":true},{"addr":"0x6fee20","include_decompile":true,"include_proto":true},{"addr":"0x6fee30","include_decompile":true,"include_proto":true},{"addr":"0x6fee40","include_decompile":true,"include_proto":true},{"addr":"0x6feed0","include_decompile":true,"include_proto":true},{"addr":"0x6ff100","include_decompile":true,"include_proto":true},{"addr":"0x6ff140","include_decompile":true,"include_proto":true},{"addr":"0x6ff290","include_decompile":true,"include_proto":true},{"addr":"0x6ff2c0","include_decompile":true,"include_proto":true},{"addr":"0x6ff370","include_decompile":true,"include_proto":true},{"addr":"0x6ff570","include_decompile":true,"include_proto":true},{"addr":"0x6ff590","include_decompile":true,"include_proto":true},{"addr":"0x6ff5d0","include_decompile":true,"include_proto":true},{"addr":"0x6ff610","include_decompile":true,"include_proto":true},{"addr":"0x6ff650","include_decompile":true,"include_proto":true},{"addr":"0x6ff690","include_decompile":true,"include_proto":true},{"addr":"0x6ff6d0","include_decompile":true,"include_proto":true},{"addr":"0x6ff740","include_decompile":true,"include_proto":true},{"addr":"0x6ff840","include_decompile":true,"include_proto":true},{"addr":"0x6ff850","include_decompile":true,"include_proto":true},{"addr":"0x6ffb80","include_decompile":true,"include_proto":true},{"addr":"0x6ffc90","include_decompile":true,"include_proto":true},{"addr":"0x6ffd10","include_decompile":true,"include_proto":true},{"addr":"0x6ffd30","include_decompile":true,"include_proto":true},{"addr":"0x6ffd60","include_decompile":true,"include_proto":true},{"addr":"0x700e80","include_decompile":true,"include_proto":true},{"addr":"0x701270","include_decompile":true,"include_proto":true},{"addr":"0x7014c0","include_decompile":true,"include_proto":true},{"addr":"0x701550","include_decompile":true,"include_proto":true},{"addr":"0x701740","include_decompile":true,"include_proto":true},{"addr":"0x701760","include_decompile":true,"include_proto":true},{"addr":"0x701980","include_decompile":true,"include_proto":true},{"addr":"0x701a10","include_decompile":true,"include_proto":true},{"addr":"0x701a90","include_decompile":true,"include_proto":true},{"addr":"0x701cc0","include_decompile":true,"include_proto":true},{"addr":"0x701d30","include_decompile":true,"include_proto":true},{"addr":"0x701f20","include_decompile":true,"include_proto":true},{"addr":"0x701f40","include_decompile":true,"include_proto":true},{"addr":"0x702080","include_decompile":true,"include_proto":true},{"addr":"0x702330","include_decompile":true,"include_proto":true},{"addr":"0x702640","include_decompile":true,"include_proto":true},{"addr":"0x702650","include_decompile":true,"include_proto":true},{"addr":"0x702670","include_decompile":true,"include_proto":true},{"addr":"0x702740","include_decompile":true,"include_proto":true},{"addr":"0x702ac0","include_decompile":true,"include_proto":true},{"addr":"0x702b10","include_decompile":true,"include_proto":true},{"addr":"0x702b50","include_decompile":true,"include_proto":true},{"addr":"0x702b60","include_decompile":true,"include_proto":true},{"addr":"0x702cc0","include_decompile":true,"include_proto":true},{"addr":"0x702db0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0121', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0121: empty response'); return; }
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
      console.log('Batch 0121: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0121 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0121 conn error:', e.message));
req.write(body);
req.end();
