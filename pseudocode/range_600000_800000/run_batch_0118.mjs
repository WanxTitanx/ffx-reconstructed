
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6f7850","include_decompile":true,"include_proto":true},{"addr":"0x6f78d0","include_decompile":true,"include_proto":true},{"addr":"0x6f7900","include_decompile":true,"include_proto":true},{"addr":"0x6f7950","include_decompile":true,"include_proto":true},{"addr":"0x6f7990","include_decompile":true,"include_proto":true},{"addr":"0x6f79b0","include_decompile":true,"include_proto":true},{"addr":"0x6f79e0","include_decompile":true,"include_proto":true},{"addr":"0x6f7a20","include_decompile":true,"include_proto":true},{"addr":"0x6f7a50","include_decompile":true,"include_proto":true},{"addr":"0x6f7ab0","include_decompile":true,"include_proto":true},{"addr":"0x6f7ae0","include_decompile":true,"include_proto":true},{"addr":"0x6f7b10","include_decompile":true,"include_proto":true},{"addr":"0x6f7bf0","include_decompile":true,"include_proto":true},{"addr":"0x6f7c00","include_decompile":true,"include_proto":true},{"addr":"0x6f7c90","include_decompile":true,"include_proto":true},{"addr":"0x6f7ca0","include_decompile":true,"include_proto":true},{"addr":"0x6f7cb0","include_decompile":true,"include_proto":true},{"addr":"0x6f7cc0","include_decompile":true,"include_proto":true},{"addr":"0x6f7cd0","include_decompile":true,"include_proto":true},{"addr":"0x6f7ce0","include_decompile":true,"include_proto":true},{"addr":"0x6f7cf0","include_decompile":true,"include_proto":true},{"addr":"0x6f7f40","include_decompile":true,"include_proto":true},{"addr":"0x6f81f0","include_decompile":true,"include_proto":true},{"addr":"0x6f82a0","include_decompile":true,"include_proto":true},{"addr":"0x6f8490","include_decompile":true,"include_proto":true},{"addr":"0x6f8680","include_decompile":true,"include_proto":true},{"addr":"0x6f8930","include_decompile":true,"include_proto":true},{"addr":"0x6f8a90","include_decompile":true,"include_proto":true},{"addr":"0x6f8bf0","include_decompile":true,"include_proto":true},{"addr":"0x6f8c20","include_decompile":true,"include_proto":true},{"addr":"0x6f8c80","include_decompile":true,"include_proto":true},{"addr":"0x6f8cc0","include_decompile":true,"include_proto":true},{"addr":"0x6f8d30","include_decompile":true,"include_proto":true},{"addr":"0x6f8fe0","include_decompile":true,"include_proto":true},{"addr":"0x6f9320","include_decompile":true,"include_proto":true},{"addr":"0x6f9350","include_decompile":true,"include_proto":true},{"addr":"0x6f9480","include_decompile":true,"include_proto":true},{"addr":"0x6f9570","include_decompile":true,"include_proto":true},{"addr":"0x6f9590","include_decompile":true,"include_proto":true},{"addr":"0x6f95b0","include_decompile":true,"include_proto":true},{"addr":"0x6f95c0","include_decompile":true,"include_proto":true},{"addr":"0x6f95d0","include_decompile":true,"include_proto":true},{"addr":"0x6f9600","include_decompile":true,"include_proto":true},{"addr":"0x6f9630","include_decompile":true,"include_proto":true},{"addr":"0x6f9660","include_decompile":true,"include_proto":true},{"addr":"0x6f96b0","include_decompile":true,"include_proto":true},{"addr":"0x6f9730","include_decompile":true,"include_proto":true},{"addr":"0x6f9810","include_decompile":true,"include_proto":true},{"addr":"0x6f9820","include_decompile":true,"include_proto":true},{"addr":"0x6f9950","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0118', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0118: empty response'); return; }
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
      console.log('Batch 0118: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0118 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0118 conn error:', e.message));
req.write(body);
req.end();
