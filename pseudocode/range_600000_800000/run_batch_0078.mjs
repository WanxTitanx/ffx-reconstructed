
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x690940","include_decompile":true,"include_proto":true},{"addr":"0x690960","include_decompile":true,"include_proto":true},{"addr":"0x690b40","include_decompile":true,"include_proto":true},{"addr":"0x690b60","include_decompile":true,"include_proto":true},{"addr":"0x690bd0","include_decompile":true,"include_proto":true},{"addr":"0x690be0","include_decompile":true,"include_proto":true},{"addr":"0x690bf0","include_decompile":true,"include_proto":true},{"addr":"0x690cf0","include_decompile":true,"include_proto":true},{"addr":"0x690d70","include_decompile":true,"include_proto":true},{"addr":"0x690db0","include_decompile":true,"include_proto":true},{"addr":"0x690df0","include_decompile":true,"include_proto":true},{"addr":"0x690e20","include_decompile":true,"include_proto":true},{"addr":"0x690e80","include_decompile":true,"include_proto":true},{"addr":"0x690ec0","include_decompile":true,"include_proto":true},{"addr":"0x690f90","include_decompile":true,"include_proto":true},{"addr":"0x6910a0","include_decompile":true,"include_proto":true},{"addr":"0x691120","include_decompile":true,"include_proto":true},{"addr":"0x6911f0","include_decompile":true,"include_proto":true},{"addr":"0x6912b0","include_decompile":true,"include_proto":true},{"addr":"0x691320","include_decompile":true,"include_proto":true},{"addr":"0x6913f0","include_decompile":true,"include_proto":true},{"addr":"0x691400","include_decompile":true,"include_proto":true},{"addr":"0x691450","include_decompile":true,"include_proto":true},{"addr":"0x691480","include_decompile":true,"include_proto":true},{"addr":"0x691490","include_decompile":true,"include_proto":true},{"addr":"0x691660","include_decompile":true,"include_proto":true},{"addr":"0x691670","include_decompile":true,"include_proto":true},{"addr":"0x691680","include_decompile":true,"include_proto":true},{"addr":"0x691760","include_decompile":true,"include_proto":true},{"addr":"0x691790","include_decompile":true,"include_proto":true},{"addr":"0x6918a0","include_decompile":true,"include_proto":true},{"addr":"0x691920","include_decompile":true,"include_proto":true},{"addr":"0x6919e0","include_decompile":true,"include_proto":true},{"addr":"0x691bb0","include_decompile":true,"include_proto":true},{"addr":"0x691c30","include_decompile":true,"include_proto":true},{"addr":"0x691c70","include_decompile":true,"include_proto":true},{"addr":"0x691e70","include_decompile":true,"include_proto":true},{"addr":"0x691ef0","include_decompile":true,"include_proto":true},{"addr":"0x691f90","include_decompile":true,"include_proto":true},{"addr":"0x692030","include_decompile":true,"include_proto":true},{"addr":"0x6920a0","include_decompile":true,"include_proto":true},{"addr":"0x692150","include_decompile":true,"include_proto":true},{"addr":"0x692540","include_decompile":true,"include_proto":true},{"addr":"0x692610","include_decompile":true,"include_proto":true},{"addr":"0x692670","include_decompile":true,"include_proto":true},{"addr":"0x6926f0","include_decompile":true,"include_proto":true},{"addr":"0x692770","include_decompile":true,"include_proto":true},{"addr":"0x692780","include_decompile":true,"include_proto":true},{"addr":"0x692790","include_decompile":true,"include_proto":true},{"addr":"0x6927a0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0078', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0078: empty response'); return; }
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
      console.log('Batch 0078: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0078 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0078 conn error:', e.message));
req.write(body);
req.end();
