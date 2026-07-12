
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7b0530","include_decompile":true,"include_proto":true},{"addr":"0x7b06c0","include_decompile":true,"include_proto":true},{"addr":"0x7b06f0","include_decompile":true,"include_proto":true},{"addr":"0x7b0730","include_decompile":true,"include_proto":true},{"addr":"0x7b0780","include_decompile":true,"include_proto":true},{"addr":"0x7b07e0","include_decompile":true,"include_proto":true},{"addr":"0x7b0840","include_decompile":true,"include_proto":true},{"addr":"0x7b0870","include_decompile":true,"include_proto":true},{"addr":"0x7b09c0","include_decompile":true,"include_proto":true},{"addr":"0x7b09f0","include_decompile":true,"include_proto":true},{"addr":"0x7b0a20","include_decompile":true,"include_proto":true},{"addr":"0x7b0a40","include_decompile":true,"include_proto":true},{"addr":"0x7b0ba0","include_decompile":true,"include_proto":true},{"addr":"0x7b0c30","include_decompile":true,"include_proto":true},{"addr":"0x7b0cb0","include_decompile":true,"include_proto":true},{"addr":"0x7b0ce0","include_decompile":true,"include_proto":true},{"addr":"0x7b0d60","include_decompile":true,"include_proto":true},{"addr":"0x7b0f90","include_decompile":true,"include_proto":true},{"addr":"0x7b10a0","include_decompile":true,"include_proto":true},{"addr":"0x7b10d0","include_decompile":true,"include_proto":true},{"addr":"0x7b1190","include_decompile":true,"include_proto":true},{"addr":"0x7b12d0","include_decompile":true,"include_proto":true},{"addr":"0x7b13d0","include_decompile":true,"include_proto":true},{"addr":"0x7b1550","include_decompile":true,"include_proto":true},{"addr":"0x7b15a0","include_decompile":true,"include_proto":true},{"addr":"0x7b1720","include_decompile":true,"include_proto":true},{"addr":"0x7b1920","include_decompile":true,"include_proto":true},{"addr":"0x7b19e0","include_decompile":true,"include_proto":true},{"addr":"0x7b1a00","include_decompile":true,"include_proto":true},{"addr":"0x7b1a80","include_decompile":true,"include_proto":true},{"addr":"0x7b1ab0","include_decompile":true,"include_proto":true},{"addr":"0x7b1b60","include_decompile":true,"include_proto":true},{"addr":"0x7b1e50","include_decompile":true,"include_proto":true},{"addr":"0x7b1e90","include_decompile":true,"include_proto":true},{"addr":"0x7b1f20","include_decompile":true,"include_proto":true},{"addr":"0x7b1fe0","include_decompile":true,"include_proto":true},{"addr":"0x7b2030","include_decompile":true,"include_proto":true},{"addr":"0x7b2070","include_decompile":true,"include_proto":true},{"addr":"0x7b20c0","include_decompile":true,"include_proto":true},{"addr":"0x7b20f0","include_decompile":true,"include_proto":true},{"addr":"0x7b22a0","include_decompile":true,"include_proto":true},{"addr":"0x7b22f0","include_decompile":true,"include_proto":true},{"addr":"0x7b2310","include_decompile":true,"include_proto":true},{"addr":"0x7b2440","include_decompile":true,"include_proto":true},{"addr":"0x7b24b0","include_decompile":true,"include_proto":true},{"addr":"0x7b2520","include_decompile":true,"include_proto":true},{"addr":"0x7b26e0","include_decompile":true,"include_proto":true},{"addr":"0x7b2750","include_decompile":true,"include_proto":true},{"addr":"0x7b27c0","include_decompile":true,"include_proto":true},{"addr":"0x7b2860","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0188', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0188: empty response'); return; }
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
      console.log('Batch 0188: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0188 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0188 conn error:', e.message));
req.write(body);
req.end();
