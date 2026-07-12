
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x644cc0","include_decompile":true,"include_proto":true},{"addr":"0x644d00","include_decompile":true,"include_proto":true},{"addr":"0x644d70","include_decompile":true,"include_proto":true},{"addr":"0x644d90","include_decompile":true,"include_proto":true},{"addr":"0x644df0","include_decompile":true,"include_proto":true},{"addr":"0x644e20","include_decompile":true,"include_proto":true},{"addr":"0x644e50","include_decompile":true,"include_proto":true},{"addr":"0x644ea0","include_decompile":true,"include_proto":true},{"addr":"0x644ef0","include_decompile":true,"include_proto":true},{"addr":"0x644f60","include_decompile":true,"include_proto":true},{"addr":"0x644f80","include_decompile":true,"include_proto":true},{"addr":"0x644f90","include_decompile":true,"include_proto":true},{"addr":"0x6451f0","include_decompile":true,"include_proto":true},{"addr":"0x645430","include_decompile":true,"include_proto":true},{"addr":"0x6454c0","include_decompile":true,"include_proto":true},{"addr":"0x6454d0","include_decompile":true,"include_proto":true},{"addr":"0x6454e0","include_decompile":true,"include_proto":true},{"addr":"0x645500","include_decompile":true,"include_proto":true},{"addr":"0x645530","include_decompile":true,"include_proto":true},{"addr":"0x645560","include_decompile":true,"include_proto":true},{"addr":"0x645580","include_decompile":true,"include_proto":true},{"addr":"0x6455b0","include_decompile":true,"include_proto":true},{"addr":"0x645600","include_decompile":true,"include_proto":true},{"addr":"0x645650","include_decompile":true,"include_proto":true},{"addr":"0x645670","include_decompile":true,"include_proto":true},{"addr":"0x6457b0","include_decompile":true,"include_proto":true},{"addr":"0x6457d0","include_decompile":true,"include_proto":true},{"addr":"0x6457e0","include_decompile":true,"include_proto":true},{"addr":"0x645820","include_decompile":true,"include_proto":true},{"addr":"0x645850","include_decompile":true,"include_proto":true},{"addr":"0x645880","include_decompile":true,"include_proto":true},{"addr":"0x6458c0","include_decompile":true,"include_proto":true},{"addr":"0x645900","include_decompile":true,"include_proto":true},{"addr":"0x645930","include_decompile":true,"include_proto":true},{"addr":"0x6459f0","include_decompile":true,"include_proto":true},{"addr":"0x645a10","include_decompile":true,"include_proto":true},{"addr":"0x645a40","include_decompile":true,"include_proto":true},{"addr":"0x645a50","include_decompile":true,"include_proto":true},{"addr":"0x645bf0","include_decompile":true,"include_proto":true},{"addr":"0x645c00","include_decompile":true,"include_proto":true},{"addr":"0x645c50","include_decompile":true,"include_proto":true},{"addr":"0x645d50","include_decompile":true,"include_proto":true},{"addr":"0x645ef0","include_decompile":true,"include_proto":true},{"addr":"0x645f40","include_decompile":true,"include_proto":true},{"addr":"0x645f60","include_decompile":true,"include_proto":true},{"addr":"0x645f70","include_decompile":true,"include_proto":true},{"addr":"0x645f90","include_decompile":true,"include_proto":true},{"addr":"0x645fa0","include_decompile":true,"include_proto":true},{"addr":"0x645ff0","include_decompile":true,"include_proto":true},{"addr":"0x646000","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0044', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0044: empty response'); return; }
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
      console.log('Batch 0044: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0044 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0044 conn error:', e.message));
req.write(body);
req.end();
