
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6b0420","include_decompile":true,"include_proto":true},{"addr":"0x6b0430","include_decompile":true,"include_proto":true},{"addr":"0x6b0480","include_decompile":true,"include_proto":true},{"addr":"0x6b04e0","include_decompile":true,"include_proto":true},{"addr":"0x6b04f0","include_decompile":true,"include_proto":true},{"addr":"0x6b05f0","include_decompile":true,"include_proto":true},{"addr":"0x6b0720","include_decompile":true,"include_proto":true},{"addr":"0x6b1bc0","include_decompile":true,"include_proto":true},{"addr":"0x6b1cb0","include_decompile":true,"include_proto":true},{"addr":"0x6b1d70","include_decompile":true,"include_proto":true},{"addr":"0x6b1d80","include_decompile":true,"include_proto":true},{"addr":"0x6b1e10","include_decompile":true,"include_proto":true},{"addr":"0x6b1e30","include_decompile":true,"include_proto":true},{"addr":"0x6b1e50","include_decompile":true,"include_proto":true},{"addr":"0x6b1e60","include_decompile":true,"include_proto":true},{"addr":"0x6b1f00","include_decompile":true,"include_proto":true},{"addr":"0x6b1f10","include_decompile":true,"include_proto":true},{"addr":"0x6b1f20","include_decompile":true,"include_proto":true},{"addr":"0x6b1f30","include_decompile":true,"include_proto":true},{"addr":"0x6b1f40","include_decompile":true,"include_proto":true},{"addr":"0x6b1f50","include_decompile":true,"include_proto":true},{"addr":"0x6b1f60","include_decompile":true,"include_proto":true},{"addr":"0x6b1f70","include_decompile":true,"include_proto":true},{"addr":"0x6b1f80","include_decompile":true,"include_proto":true},{"addr":"0x6b1f90","include_decompile":true,"include_proto":true},{"addr":"0x6b2040","include_decompile":true,"include_proto":true},{"addr":"0x6b20d0","include_decompile":true,"include_proto":true},{"addr":"0x6b20e0","include_decompile":true,"include_proto":true},{"addr":"0x6b21a0","include_decompile":true,"include_proto":true},{"addr":"0x6b21b0","include_decompile":true,"include_proto":true},{"addr":"0x6b21c0","include_decompile":true,"include_proto":true},{"addr":"0x6b21f0","include_decompile":true,"include_proto":true},{"addr":"0x6b2270","include_decompile":true,"include_proto":true},{"addr":"0x6b2280","include_decompile":true,"include_proto":true},{"addr":"0x6b22e0","include_decompile":true,"include_proto":true},{"addr":"0x6b2380","include_decompile":true,"include_proto":true},{"addr":"0x6b2430","include_decompile":true,"include_proto":true},{"addr":"0x6b2550","include_decompile":true,"include_proto":true},{"addr":"0x6b2630","include_decompile":true,"include_proto":true},{"addr":"0x6b26c0","include_decompile":true,"include_proto":true},{"addr":"0x6b2750","include_decompile":true,"include_proto":true},{"addr":"0x6b2800","include_decompile":true,"include_proto":true},{"addr":"0x6b2880","include_decompile":true,"include_proto":true},{"addr":"0x6b2950","include_decompile":true,"include_proto":true},{"addr":"0x6b2a20","include_decompile":true,"include_proto":true},{"addr":"0x6b2a30","include_decompile":true,"include_proto":true},{"addr":"0x6b2a40","include_decompile":true,"include_proto":true},{"addr":"0x6b2b10","include_decompile":true,"include_proto":true},{"addr":"0x6b2df0","include_decompile":true,"include_proto":true},{"addr":"0x6b30a0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0092', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0092: empty response'); return; }
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
      console.log('Batch 0092: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0092 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0092 conn error:', e.message));
req.write(body);
req.end();
