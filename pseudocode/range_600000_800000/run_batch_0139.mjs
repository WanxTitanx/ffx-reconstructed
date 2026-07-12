
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x748bd0","include_decompile":true,"include_proto":true},{"addr":"0x749120","include_decompile":true,"include_proto":true},{"addr":"0x749180","include_decompile":true,"include_proto":true},{"addr":"0x749190","include_decompile":true,"include_proto":true},{"addr":"0x7491a0","include_decompile":true,"include_proto":true},{"addr":"0x7498b0","include_decompile":true,"include_proto":true},{"addr":"0x7498e0","include_decompile":true,"include_proto":true},{"addr":"0x7499c0","include_decompile":true,"include_proto":true},{"addr":"0x749a20","include_decompile":true,"include_proto":true},{"addr":"0x749be0","include_decompile":true,"include_proto":true},{"addr":"0x749c10","include_decompile":true,"include_proto":true},{"addr":"0x749d00","include_decompile":true,"include_proto":true},{"addr":"0x749d60","include_decompile":true,"include_proto":true},{"addr":"0x749f30","include_decompile":true,"include_proto":true},{"addr":"0x749f60","include_decompile":true,"include_proto":true},{"addr":"0x74a060","include_decompile":true,"include_proto":true},{"addr":"0x74a0c0","include_decompile":true,"include_proto":true},{"addr":"0x74a2b0","include_decompile":true,"include_proto":true},{"addr":"0x74a830","include_decompile":true,"include_proto":true},{"addr":"0x74a920","include_decompile":true,"include_proto":true},{"addr":"0x74ae50","include_decompile":true,"include_proto":true},{"addr":"0x74af40","include_decompile":true,"include_proto":true},{"addr":"0x74b5d0","include_decompile":true,"include_proto":true},{"addr":"0x74b610","include_decompile":true,"include_proto":true},{"addr":"0x74b700","include_decompile":true,"include_proto":true},{"addr":"0x74b720","include_decompile":true,"include_proto":true},{"addr":"0x74b740","include_decompile":true,"include_proto":true},{"addr":"0x74b770","include_decompile":true,"include_proto":true},{"addr":"0x74ba70","include_decompile":true,"include_proto":true},{"addr":"0x74ba90","include_decompile":true,"include_proto":true},{"addr":"0x74bd20","include_decompile":true,"include_proto":true},{"addr":"0x74beb0","include_decompile":true,"include_proto":true},{"addr":"0x74bf60","include_decompile":true,"include_proto":true},{"addr":"0x74bfa0","include_decompile":true,"include_proto":true},{"addr":"0x74bff0","include_decompile":true,"include_proto":true},{"addr":"0x74c0d0","include_decompile":true,"include_proto":true},{"addr":"0x74c360","include_decompile":true,"include_proto":true},{"addr":"0x74c490","include_decompile":true,"include_proto":true},{"addr":"0x74c570","include_decompile":true,"include_proto":true},{"addr":"0x74c620","include_decompile":true,"include_proto":true},{"addr":"0x74c650","include_decompile":true,"include_proto":true},{"addr":"0x74cff0","include_decompile":true,"include_proto":true},{"addr":"0x74d0d0","include_decompile":true,"include_proto":true},{"addr":"0x74d360","include_decompile":true,"include_proto":true},{"addr":"0x74d490","include_decompile":true,"include_proto":true},{"addr":"0x74d570","include_decompile":true,"include_proto":true},{"addr":"0x74d620","include_decompile":true,"include_proto":true},{"addr":"0x74d650","include_decompile":true,"include_proto":true},{"addr":"0x74dff0","include_decompile":true,"include_proto":true},{"addr":"0x74e0d0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0139', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0139: empty response'); return; }
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
      console.log('Batch 0139: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0139 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0139 conn error:', e.message));
req.write(body);
req.end();
