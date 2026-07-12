
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7ad650","include_decompile":true,"include_proto":true},{"addr":"0x7ad6f0","include_decompile":true,"include_proto":true},{"addr":"0x7ad720","include_decompile":true,"include_proto":true},{"addr":"0x7ad760","include_decompile":true,"include_proto":true},{"addr":"0x7ad830","include_decompile":true,"include_proto":true},{"addr":"0x7ad950","include_decompile":true,"include_proto":true},{"addr":"0x7ad980","include_decompile":true,"include_proto":true},{"addr":"0x7ada50","include_decompile":true,"include_proto":true},{"addr":"0x7ada70","include_decompile":true,"include_proto":true},{"addr":"0x7adaf0","include_decompile":true,"include_proto":true},{"addr":"0x7ade20","include_decompile":true,"include_proto":true},{"addr":"0x7adf20","include_decompile":true,"include_proto":true},{"addr":"0x7adfa0","include_decompile":true,"include_proto":true},{"addr":"0x7ae0b0","include_decompile":true,"include_proto":true},{"addr":"0x7ae100","include_decompile":true,"include_proto":true},{"addr":"0x7ae130","include_decompile":true,"include_proto":true},{"addr":"0x7ae1b0","include_decompile":true,"include_proto":true},{"addr":"0x7ae2f0","include_decompile":true,"include_proto":true},{"addr":"0x7ae380","include_decompile":true,"include_proto":true},{"addr":"0x7aeed0","include_decompile":true,"include_proto":true},{"addr":"0x7aef30","include_decompile":true,"include_proto":true},{"addr":"0x7aefc0","include_decompile":true,"include_proto":true},{"addr":"0x7af070","include_decompile":true,"include_proto":true},{"addr":"0x7af100","include_decompile":true,"include_proto":true},{"addr":"0x7af240","include_decompile":true,"include_proto":true},{"addr":"0x7af270","include_decompile":true,"include_proto":true},{"addr":"0x7af2c0","include_decompile":true,"include_proto":true},{"addr":"0x7af300","include_decompile":true,"include_proto":true},{"addr":"0x7af330","include_decompile":true,"include_proto":true},{"addr":"0x7af3a0","include_decompile":true,"include_proto":true},{"addr":"0x7af4c0","include_decompile":true,"include_proto":true},{"addr":"0x7af500","include_decompile":true,"include_proto":true},{"addr":"0x7af780","include_decompile":true,"include_proto":true},{"addr":"0x7af810","include_decompile":true,"include_proto":true},{"addr":"0x7af850","include_decompile":true,"include_proto":true},{"addr":"0x7af890","include_decompile":true,"include_proto":true},{"addr":"0x7af8b0","include_decompile":true,"include_proto":true},{"addr":"0x7af930","include_decompile":true,"include_proto":true},{"addr":"0x7afa70","include_decompile":true,"include_proto":true},{"addr":"0x7afa90","include_decompile":true,"include_proto":true},{"addr":"0x7afac0","include_decompile":true,"include_proto":true},{"addr":"0x7afb70","include_decompile":true,"include_proto":true},{"addr":"0x7afbe0","include_decompile":true,"include_proto":true},{"addr":"0x7afca0","include_decompile":true,"include_proto":true},{"addr":"0x7afd40","include_decompile":true,"include_proto":true},{"addr":"0x7afdf0","include_decompile":true,"include_proto":true},{"addr":"0x7afe10","include_decompile":true,"include_proto":true},{"addr":"0x7b03f0","include_decompile":true,"include_proto":true},{"addr":"0x7b0480","include_decompile":true,"include_proto":true},{"addr":"0x7b0510","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0187', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0187: empty response'); return; }
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
      console.log('Batch 0187: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0187 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0187 conn error:', e.message));
req.write(body);
req.end();
