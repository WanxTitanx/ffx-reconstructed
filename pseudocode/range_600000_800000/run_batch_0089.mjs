
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6a8e60","include_decompile":true,"include_proto":true},{"addr":"0x6a8e70","include_decompile":true,"include_proto":true},{"addr":"0x6a8e80","include_decompile":true,"include_proto":true},{"addr":"0x6a8ef0","include_decompile":true,"include_proto":true},{"addr":"0x6a90d0","include_decompile":true,"include_proto":true},{"addr":"0x6a9330","include_decompile":true,"include_proto":true},{"addr":"0x6a9600","include_decompile":true,"include_proto":true},{"addr":"0x6a9800","include_decompile":true,"include_proto":true},{"addr":"0x6a9bd0","include_decompile":true,"include_proto":true},{"addr":"0x6a9c20","include_decompile":true,"include_proto":true},{"addr":"0x6a9c30","include_decompile":true,"include_proto":true},{"addr":"0x6a9c90","include_decompile":true,"include_proto":true},{"addr":"0x6a9d00","include_decompile":true,"include_proto":true},{"addr":"0x6a9e20","include_decompile":true,"include_proto":true},{"addr":"0x6aa050","include_decompile":true,"include_proto":true},{"addr":"0x6aa160","include_decompile":true,"include_proto":true},{"addr":"0x6aa3b0","include_decompile":true,"include_proto":true},{"addr":"0x6aa520","include_decompile":true,"include_proto":true},{"addr":"0x6aa560","include_decompile":true,"include_proto":true},{"addr":"0x6aa740","include_decompile":true,"include_proto":true},{"addr":"0x6aa7a0","include_decompile":true,"include_proto":true},{"addr":"0x6aaa10","include_decompile":true,"include_proto":true},{"addr":"0x6aaa70","include_decompile":true,"include_proto":true},{"addr":"0x6aaa90","include_decompile":true,"include_proto":true},{"addr":"0x6aab40","include_decompile":true,"include_proto":true},{"addr":"0x6aac90","include_decompile":true,"include_proto":true},{"addr":"0x6aad40","include_decompile":true,"include_proto":true},{"addr":"0x6aae50","include_decompile":true,"include_proto":true},{"addr":"0x6aae70","include_decompile":true,"include_proto":true},{"addr":"0x6aaee0","include_decompile":true,"include_proto":true},{"addr":"0x6aaf90","include_decompile":true,"include_proto":true},{"addr":"0x6aaff0","include_decompile":true,"include_proto":true},{"addr":"0x6ab040","include_decompile":true,"include_proto":true},{"addr":"0x6ab0f0","include_decompile":true,"include_proto":true},{"addr":"0x6ab110","include_decompile":true,"include_proto":true},{"addr":"0x6ab160","include_decompile":true,"include_proto":true},{"addr":"0x6ab220","include_decompile":true,"include_proto":true},{"addr":"0x6ab2d0","include_decompile":true,"include_proto":true},{"addr":"0x6ab690","include_decompile":true,"include_proto":true},{"addr":"0x6ab710","include_decompile":true,"include_proto":true},{"addr":"0x6ab780","include_decompile":true,"include_proto":true},{"addr":"0x6ab870","include_decompile":true,"include_proto":true},{"addr":"0x6ab8f0","include_decompile":true,"include_proto":true},{"addr":"0x6ab9b0","include_decompile":true,"include_proto":true},{"addr":"0x6aba10","include_decompile":true,"include_proto":true},{"addr":"0x6abaa0","include_decompile":true,"include_proto":true},{"addr":"0x6abc70","include_decompile":true,"include_proto":true},{"addr":"0x6abc80","include_decompile":true,"include_proto":true},{"addr":"0x6abd70","include_decompile":true,"include_proto":true},{"addr":"0x6abf00","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0089', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0089: empty response'); return; }
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
      console.log('Batch 0089: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0089 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0089 conn error:', e.message));
req.write(body);
req.end();
