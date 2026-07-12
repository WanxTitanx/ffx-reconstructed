
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x66d120","include_decompile":true,"include_proto":true},{"addr":"0x66d140","include_decompile":true,"include_proto":true},{"addr":"0x66d170","include_decompile":true,"include_proto":true},{"addr":"0x66d190","include_decompile":true,"include_proto":true},{"addr":"0x66d320","include_decompile":true,"include_proto":true},{"addr":"0x66d330","include_decompile":true,"include_proto":true},{"addr":"0x66d340","include_decompile":true,"include_proto":true},{"addr":"0x66d360","include_decompile":true,"include_proto":true},{"addr":"0x66d540","include_decompile":true,"include_proto":true},{"addr":"0x66d750","include_decompile":true,"include_proto":true},{"addr":"0x66d7a0","include_decompile":true,"include_proto":true},{"addr":"0x66d880","include_decompile":true,"include_proto":true},{"addr":"0x66d9a0","include_decompile":true,"include_proto":true},{"addr":"0x66daa0","include_decompile":true,"include_proto":true},{"addr":"0x66dad0","include_decompile":true,"include_proto":true},{"addr":"0x66dc90","include_decompile":true,"include_proto":true},{"addr":"0x66e570","include_decompile":true,"include_proto":true},{"addr":"0x66e680","include_decompile":true,"include_proto":true},{"addr":"0x66e770","include_decompile":true,"include_proto":true},{"addr":"0x66e940","include_decompile":true,"include_proto":true},{"addr":"0x66e990","include_decompile":true,"include_proto":true},{"addr":"0x66e9c0","include_decompile":true,"include_proto":true},{"addr":"0x66e9e0","include_decompile":true,"include_proto":true},{"addr":"0x66ec00","include_decompile":true,"include_proto":true},{"addr":"0x66eca0","include_decompile":true,"include_proto":true},{"addr":"0x66ecb0","include_decompile":true,"include_proto":true},{"addr":"0x66ee90","include_decompile":true,"include_proto":true},{"addr":"0x66f000","include_decompile":true,"include_proto":true},{"addr":"0x66f1a0","include_decompile":true,"include_proto":true},{"addr":"0x66f2d0","include_decompile":true,"include_proto":true},{"addr":"0x66f470","include_decompile":true,"include_proto":true},{"addr":"0x66f480","include_decompile":true,"include_proto":true},{"addr":"0x66f510","include_decompile":true,"include_proto":true},{"addr":"0x66f960","include_decompile":true,"include_proto":true},{"addr":"0x66fbb0","include_decompile":true,"include_proto":true},{"addr":"0x66fbc0","include_decompile":true,"include_proto":true},{"addr":"0x66fbd0","include_decompile":true,"include_proto":true},{"addr":"0x66fbe0","include_decompile":true,"include_proto":true},{"addr":"0x66fbf0","include_decompile":true,"include_proto":true},{"addr":"0x66fc00","include_decompile":true,"include_proto":true},{"addr":"0x66fc30","include_decompile":true,"include_proto":true},{"addr":"0x66fcd0","include_decompile":true,"include_proto":true},{"addr":"0x66fcf0","include_decompile":true,"include_proto":true},{"addr":"0x66fd10","include_decompile":true,"include_proto":true},{"addr":"0x6708f0","include_decompile":true,"include_proto":true},{"addr":"0x670900","include_decompile":true,"include_proto":true},{"addr":"0x670a80","include_decompile":true,"include_proto":true},{"addr":"0x670ac0","include_decompile":true,"include_proto":true},{"addr":"0x670b00","include_decompile":true,"include_proto":true},{"addr":"0x670ca0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0061', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0061: empty response'); return; }
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
      console.log('Batch 0061: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0061 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0061 conn error:', e.message));
req.write(body);
req.end();
