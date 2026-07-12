
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7e1e90","include_decompile":true,"include_proto":true},{"addr":"0x7e2050","include_decompile":true,"include_proto":true},{"addr":"0x7e2160","include_decompile":true,"include_proto":true},{"addr":"0x7e2180","include_decompile":true,"include_proto":true},{"addr":"0x7e2510","include_decompile":true,"include_proto":true},{"addr":"0x7e2570","include_decompile":true,"include_proto":true},{"addr":"0x7e2630","include_decompile":true,"include_proto":true},{"addr":"0x7e2680","include_decompile":true,"include_proto":true},{"addr":"0x7e2970","include_decompile":true,"include_proto":true},{"addr":"0x7e2ca0","include_decompile":true,"include_proto":true},{"addr":"0x7e2d40","include_decompile":true,"include_proto":true},{"addr":"0x7e2de0","include_decompile":true,"include_proto":true},{"addr":"0x7e2ec0","include_decompile":true,"include_proto":true},{"addr":"0x7e2fa0","include_decompile":true,"include_proto":true},{"addr":"0x7e3010","include_decompile":true,"include_proto":true},{"addr":"0x7e32f0","include_decompile":true,"include_proto":true},{"addr":"0x7e34d0","include_decompile":true,"include_proto":true},{"addr":"0x7e3720","include_decompile":true,"include_proto":true},{"addr":"0x7e37b0","include_decompile":true,"include_proto":true},{"addr":"0x7e3a50","include_decompile":true,"include_proto":true},{"addr":"0x7e3a80","include_decompile":true,"include_proto":true},{"addr":"0x7e3d40","include_decompile":true,"include_proto":true},{"addr":"0x7e3d80","include_decompile":true,"include_proto":true},{"addr":"0x7e3e60","include_decompile":true,"include_proto":true},{"addr":"0x7e3ea0","include_decompile":true,"include_proto":true},{"addr":"0x7e4330","include_decompile":true,"include_proto":true},{"addr":"0x7e4450","include_decompile":true,"include_proto":true},{"addr":"0x7e44c0","include_decompile":true,"include_proto":true},{"addr":"0x7e44f0","include_decompile":true,"include_proto":true},{"addr":"0x7e4520","include_decompile":true,"include_proto":true},{"addr":"0x7e45c0","include_decompile":true,"include_proto":true},{"addr":"0x7e45e0","include_decompile":true,"include_proto":true},{"addr":"0x7e4630","include_decompile":true,"include_proto":true},{"addr":"0x7e4740","include_decompile":true,"include_proto":true},{"addr":"0x7e4b40","include_decompile":true,"include_proto":true},{"addr":"0x7e4d50","include_decompile":true,"include_proto":true},{"addr":"0x7e4d90","include_decompile":true,"include_proto":true},{"addr":"0x7e4e30","include_decompile":true,"include_proto":true},{"addr":"0x7e4f00","include_decompile":true,"include_proto":true},{"addr":"0x7e4f40","include_decompile":true,"include_proto":true},{"addr":"0x7e5120","include_decompile":true,"include_proto":true},{"addr":"0x7e5170","include_decompile":true,"include_proto":true},{"addr":"0x7e52a0","include_decompile":true,"include_proto":true},{"addr":"0x7e5590","include_decompile":true,"include_proto":true},{"addr":"0x7e55e0","include_decompile":true,"include_proto":true},{"addr":"0x7e5b20","include_decompile":true,"include_proto":true},{"addr":"0x7e5bb0","include_decompile":true,"include_proto":true},{"addr":"0x7e5be0","include_decompile":true,"include_proto":true},{"addr":"0x7e5c40","include_decompile":true,"include_proto":true},{"addr":"0x7e5c50","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0199', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0199: empty response'); return; }
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
      console.log('Batch 0199: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0199 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0199 conn error:', e.message));
req.write(body);
req.end();
