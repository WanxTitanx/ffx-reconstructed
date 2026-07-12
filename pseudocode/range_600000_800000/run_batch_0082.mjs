
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x69b070","include_decompile":true,"include_proto":true},{"addr":"0x69b0b0","include_decompile":true,"include_proto":true},{"addr":"0x69b150","include_decompile":true,"include_proto":true},{"addr":"0x69b450","include_decompile":true,"include_proto":true},{"addr":"0x69b510","include_decompile":true,"include_proto":true},{"addr":"0x69b520","include_decompile":true,"include_proto":true},{"addr":"0x69b530","include_decompile":true,"include_proto":true},{"addr":"0x69b5f0","include_decompile":true,"include_proto":true},{"addr":"0x69b670","include_decompile":true,"include_proto":true},{"addr":"0x69b700","include_decompile":true,"include_proto":true},{"addr":"0x69b790","include_decompile":true,"include_proto":true},{"addr":"0x69b820","include_decompile":true,"include_proto":true},{"addr":"0x69b8f0","include_decompile":true,"include_proto":true},{"addr":"0x69b900","include_decompile":true,"include_proto":true},{"addr":"0x69b980","include_decompile":true,"include_proto":true},{"addr":"0x69b9d0","include_decompile":true,"include_proto":true},{"addr":"0x69ba80","include_decompile":true,"include_proto":true},{"addr":"0x69bc40","include_decompile":true,"include_proto":true},{"addr":"0x69bc80","include_decompile":true,"include_proto":true},{"addr":"0x69bc90","include_decompile":true,"include_proto":true},{"addr":"0x69bca0","include_decompile":true,"include_proto":true},{"addr":"0x69bcb0","include_decompile":true,"include_proto":true},{"addr":"0x69bcc0","include_decompile":true,"include_proto":true},{"addr":"0x69bee0","include_decompile":true,"include_proto":true},{"addr":"0x69bef0","include_decompile":true,"include_proto":true},{"addr":"0x69bfd0","include_decompile":true,"include_proto":true},{"addr":"0x69c150","include_decompile":true,"include_proto":true},{"addr":"0x69c340","include_decompile":true,"include_proto":true},{"addr":"0x69c3b0","include_decompile":true,"include_proto":true},{"addr":"0x69c6c0","include_decompile":true,"include_proto":true},{"addr":"0x69c700","include_decompile":true,"include_proto":true},{"addr":"0x69c730","include_decompile":true,"include_proto":true},{"addr":"0x69c770","include_decompile":true,"include_proto":true},{"addr":"0x69c7d0","include_decompile":true,"include_proto":true},{"addr":"0x69c7e0","include_decompile":true,"include_proto":true},{"addr":"0x69c7f0","include_decompile":true,"include_proto":true},{"addr":"0x69ca20","include_decompile":true,"include_proto":true},{"addr":"0x69cc30","include_decompile":true,"include_proto":true},{"addr":"0x69ce80","include_decompile":true,"include_proto":true},{"addr":"0x69d120","include_decompile":true,"include_proto":true},{"addr":"0x69d270","include_decompile":true,"include_proto":true},{"addr":"0x69d280","include_decompile":true,"include_proto":true},{"addr":"0x69d2f0","include_decompile":true,"include_proto":true},{"addr":"0x69d3a0","include_decompile":true,"include_proto":true},{"addr":"0x69d3b0","include_decompile":true,"include_proto":true},{"addr":"0x69d3c0","include_decompile":true,"include_proto":true},{"addr":"0x69d3d0","include_decompile":true,"include_proto":true},{"addr":"0x69d3e0","include_decompile":true,"include_proto":true},{"addr":"0x69d400","include_decompile":true,"include_proto":true},{"addr":"0x69d420","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0082', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0082: empty response'); return; }
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
      console.log('Batch 0082: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0082 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0082 conn error:', e.message));
req.write(body);
req.end();
