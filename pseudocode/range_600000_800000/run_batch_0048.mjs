
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x64b260","include_decompile":true,"include_proto":true},{"addr":"0x64b280","include_decompile":true,"include_proto":true},{"addr":"0x64b2a0","include_decompile":true,"include_proto":true},{"addr":"0x64b2c0","include_decompile":true,"include_proto":true},{"addr":"0x64b2e0","include_decompile":true,"include_proto":true},{"addr":"0x64b350","include_decompile":true,"include_proto":true},{"addr":"0x64b3c0","include_decompile":true,"include_proto":true},{"addr":"0x64b590","include_decompile":true,"include_proto":true},{"addr":"0x64b5b0","include_decompile":true,"include_proto":true},{"addr":"0x64b5d0","include_decompile":true,"include_proto":true},{"addr":"0x64b5f0","include_decompile":true,"include_proto":true},{"addr":"0x64b610","include_decompile":true,"include_proto":true},{"addr":"0x64b630","include_decompile":true,"include_proto":true},{"addr":"0x64b650","include_decompile":true,"include_proto":true},{"addr":"0x64b670","include_decompile":true,"include_proto":true},{"addr":"0x64b690","include_decompile":true,"include_proto":true},{"addr":"0x64b6b0","include_decompile":true,"include_proto":true},{"addr":"0x64b720","include_decompile":true,"include_proto":true},{"addr":"0x64b790","include_decompile":true,"include_proto":true},{"addr":"0x64b7f0","include_decompile":true,"include_proto":true},{"addr":"0x64b860","include_decompile":true,"include_proto":true},{"addr":"0x64b9d0","include_decompile":true,"include_proto":true},{"addr":"0x64b9e0","include_decompile":true,"include_proto":true},{"addr":"0x64b9f0","include_decompile":true,"include_proto":true},{"addr":"0x64ba00","include_decompile":true,"include_proto":true},{"addr":"0x64ba10","include_decompile":true,"include_proto":true},{"addr":"0x64ba20","include_decompile":true,"include_proto":true},{"addr":"0x64ba70","include_decompile":true,"include_proto":true},{"addr":"0x64bb50","include_decompile":true,"include_proto":true},{"addr":"0x64bba0","include_decompile":true,"include_proto":true},{"addr":"0x64bbf0","include_decompile":true,"include_proto":true},{"addr":"0x64bc00","include_decompile":true,"include_proto":true},{"addr":"0x64bc10","include_decompile":true,"include_proto":true},{"addr":"0x64bc20","include_decompile":true,"include_proto":true},{"addr":"0x64bc30","include_decompile":true,"include_proto":true},{"addr":"0x64bc40","include_decompile":true,"include_proto":true},{"addr":"0x64bc50","include_decompile":true,"include_proto":true},{"addr":"0x64bc60","include_decompile":true,"include_proto":true},{"addr":"0x64bc70","include_decompile":true,"include_proto":true},{"addr":"0x64bc80","include_decompile":true,"include_proto":true},{"addr":"0x64bc90","include_decompile":true,"include_proto":true},{"addr":"0x64bca0","include_decompile":true,"include_proto":true},{"addr":"0x64bcb0","include_decompile":true,"include_proto":true},{"addr":"0x64bcc0","include_decompile":true,"include_proto":true},{"addr":"0x64bcd0","include_decompile":true,"include_proto":true},{"addr":"0x64bce0","include_decompile":true,"include_proto":true},{"addr":"0x64bcf0","include_decompile":true,"include_proto":true},{"addr":"0x64bd00","include_decompile":true,"include_proto":true},{"addr":"0x64bd10","include_decompile":true,"include_proto":true},{"addr":"0x64bd20","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0048', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0048: empty response'); return; }
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
      console.log('Batch 0048: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0048 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0048 conn error:', e.message));
req.write(body);
req.end();
