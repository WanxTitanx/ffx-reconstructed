
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7a8640","include_decompile":true,"include_proto":true},{"addr":"0x7a8670","include_decompile":true,"include_proto":true},{"addr":"0x7a86a0","include_decompile":true,"include_proto":true},{"addr":"0x7a8700","include_decompile":true,"include_proto":true},{"addr":"0x7a8720","include_decompile":true,"include_proto":true},{"addr":"0x7a8740","include_decompile":true,"include_proto":true},{"addr":"0x7a8810","include_decompile":true,"include_proto":true},{"addr":"0x7a8900","include_decompile":true,"include_proto":true},{"addr":"0x7a8940","include_decompile":true,"include_proto":true},{"addr":"0x7a8990","include_decompile":true,"include_proto":true},{"addr":"0x7a89e0","include_decompile":true,"include_proto":true},{"addr":"0x7a8af0","include_decompile":true,"include_proto":true},{"addr":"0x7a8b60","include_decompile":true,"include_proto":true},{"addr":"0x7a8c00","include_decompile":true,"include_proto":true},{"addr":"0x7a8c40","include_decompile":true,"include_proto":true},{"addr":"0x7a8c70","include_decompile":true,"include_proto":true},{"addr":"0x7a8ca0","include_decompile":true,"include_proto":true},{"addr":"0x7a8f40","include_decompile":true,"include_proto":true},{"addr":"0x7a8f80","include_decompile":true,"include_proto":true},{"addr":"0x7a8fe0","include_decompile":true,"include_proto":true},{"addr":"0x7a9170","include_decompile":true,"include_proto":true},{"addr":"0x7a9250","include_decompile":true,"include_proto":true},{"addr":"0x7a92e0","include_decompile":true,"include_proto":true},{"addr":"0x7a9340","include_decompile":true,"include_proto":true},{"addr":"0x7a9400","include_decompile":true,"include_proto":true},{"addr":"0x7a9670","include_decompile":true,"include_proto":true},{"addr":"0x7a9730","include_decompile":true,"include_proto":true},{"addr":"0x7a99d0","include_decompile":true,"include_proto":true},{"addr":"0x7a9a40","include_decompile":true,"include_proto":true},{"addr":"0x7a9a60","include_decompile":true,"include_proto":true},{"addr":"0x7a9ae0","include_decompile":true,"include_proto":true},{"addr":"0x7a9fe0","include_decompile":true,"include_proto":true},{"addr":"0x7aa070","include_decompile":true,"include_proto":true},{"addr":"0x7aa120","include_decompile":true,"include_proto":true},{"addr":"0x7aa160","include_decompile":true,"include_proto":true},{"addr":"0x7aa180","include_decompile":true,"include_proto":true},{"addr":"0x7aa280","include_decompile":true,"include_proto":true},{"addr":"0x7aa2a0","include_decompile":true,"include_proto":true},{"addr":"0x7aa2c0","include_decompile":true,"include_proto":true},{"addr":"0x7aaae0","include_decompile":true,"include_proto":true},{"addr":"0x7aab00","include_decompile":true,"include_proto":true},{"addr":"0x7aaba0","include_decompile":true,"include_proto":true},{"addr":"0x7aac60","include_decompile":true,"include_proto":true},{"addr":"0x7ab010","include_decompile":true,"include_proto":true},{"addr":"0x7ab030","include_decompile":true,"include_proto":true},{"addr":"0x7ab0d0","include_decompile":true,"include_proto":true},{"addr":"0x7ab160","include_decompile":true,"include_proto":true},{"addr":"0x7ab180","include_decompile":true,"include_proto":true},{"addr":"0x7ab190","include_decompile":true,"include_proto":true},{"addr":"0x7ab1b0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0185', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0185: empty response'); return; }
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
      console.log('Batch 0185: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0185 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0185 conn error:', e.message));
req.write(body);
req.end();
