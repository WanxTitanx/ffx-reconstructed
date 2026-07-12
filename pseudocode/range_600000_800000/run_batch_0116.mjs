
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6f3660","include_decompile":true,"include_proto":true},{"addr":"0x6f36d0","include_decompile":true,"include_proto":true},{"addr":"0x6f36f0","include_decompile":true,"include_proto":true},{"addr":"0x6f38e0","include_decompile":true,"include_proto":true},{"addr":"0x6f3990","include_decompile":true,"include_proto":true},{"addr":"0x6f39a0","include_decompile":true,"include_proto":true},{"addr":"0x6f39c0","include_decompile":true,"include_proto":true},{"addr":"0x6f39e0","include_decompile":true,"include_proto":true},{"addr":"0x6f3a60","include_decompile":true,"include_proto":true},{"addr":"0x6f3aa0","include_decompile":true,"include_proto":true},{"addr":"0x6f3ab0","include_decompile":true,"include_proto":true},{"addr":"0x6f3ac0","include_decompile":true,"include_proto":true},{"addr":"0x6f3b00","include_decompile":true,"include_proto":true},{"addr":"0x6f3c20","include_decompile":true,"include_proto":true},{"addr":"0x6f3d00","include_decompile":true,"include_proto":true},{"addr":"0x6f3d20","include_decompile":true,"include_proto":true},{"addr":"0x6f3da0","include_decompile":true,"include_proto":true},{"addr":"0x6f4010","include_decompile":true,"include_proto":true},{"addr":"0x6f4020","include_decompile":true,"include_proto":true},{"addr":"0x6f40a0","include_decompile":true,"include_proto":true},{"addr":"0x6f4110","include_decompile":true,"include_proto":true},{"addr":"0x6f4120","include_decompile":true,"include_proto":true},{"addr":"0x6f4130","include_decompile":true,"include_proto":true},{"addr":"0x6f4140","include_decompile":true,"include_proto":true},{"addr":"0x6f4170","include_decompile":true,"include_proto":true},{"addr":"0x6f41d0","include_decompile":true,"include_proto":true},{"addr":"0x6f41e0","include_decompile":true,"include_proto":true},{"addr":"0x6f4220","include_decompile":true,"include_proto":true},{"addr":"0x6f42b0","include_decompile":true,"include_proto":true},{"addr":"0x6f42f0","include_decompile":true,"include_proto":true},{"addr":"0x6f4340","include_decompile":true,"include_proto":true},{"addr":"0x6f4410","include_decompile":true,"include_proto":true},{"addr":"0x6f4490","include_decompile":true,"include_proto":true},{"addr":"0x6f4550","include_decompile":true,"include_proto":true},{"addr":"0x6f4670","include_decompile":true,"include_proto":true},{"addr":"0x6f4720","include_decompile":true,"include_proto":true},{"addr":"0x6f47f0","include_decompile":true,"include_proto":true},{"addr":"0x6f4820","include_decompile":true,"include_proto":true},{"addr":"0x6f48d0","include_decompile":true,"include_proto":true},{"addr":"0x6f49a0","include_decompile":true,"include_proto":true},{"addr":"0x6f49b0","include_decompile":true,"include_proto":true},{"addr":"0x6f49c0","include_decompile":true,"include_proto":true},{"addr":"0x6f49d0","include_decompile":true,"include_proto":true},{"addr":"0x6f4a40","include_decompile":true,"include_proto":true},{"addr":"0x6f51e0","include_decompile":true,"include_proto":true},{"addr":"0x6f5560","include_decompile":true,"include_proto":true},{"addr":"0x6f5590","include_decompile":true,"include_proto":true},{"addr":"0x6f55b0","include_decompile":true,"include_proto":true},{"addr":"0x6f5630","include_decompile":true,"include_proto":true},{"addr":"0x6f58a0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0116', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0116: empty response'); return; }
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
      console.log('Batch 0116: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0116 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0116 conn error:', e.message));
req.write(body);
req.end();
