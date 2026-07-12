
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x646010","include_decompile":true,"include_proto":true},{"addr":"0x646060","include_decompile":true,"include_proto":true},{"addr":"0x6460b0","include_decompile":true,"include_proto":true},{"addr":"0x6460d0","include_decompile":true,"include_proto":true},{"addr":"0x6460e0","include_decompile":true,"include_proto":true},{"addr":"0x646100","include_decompile":true,"include_proto":true},{"addr":"0x646240","include_decompile":true,"include_proto":true},{"addr":"0x646250","include_decompile":true,"include_proto":true},{"addr":"0x6463a0","include_decompile":true,"include_proto":true},{"addr":"0x646ac0","include_decompile":true,"include_proto":true},{"addr":"0x646ad0","include_decompile":true,"include_proto":true},{"addr":"0x646c80","include_decompile":true,"include_proto":true},{"addr":"0x646ce0","include_decompile":true,"include_proto":true},{"addr":"0x646e50","include_decompile":true,"include_proto":true},{"addr":"0x646fa0","include_decompile":true,"include_proto":true},{"addr":"0x647140","include_decompile":true,"include_proto":true},{"addr":"0x647150","include_decompile":true,"include_proto":true},{"addr":"0x647160","include_decompile":true,"include_proto":true},{"addr":"0x647170","include_decompile":true,"include_proto":true},{"addr":"0x6471a0","include_decompile":true,"include_proto":true},{"addr":"0x6473d0","include_decompile":true,"include_proto":true},{"addr":"0x6474f0","include_decompile":true,"include_proto":true},{"addr":"0x647530","include_decompile":true,"include_proto":true},{"addr":"0x647540","include_decompile":true,"include_proto":true},{"addr":"0x647580","include_decompile":true,"include_proto":true},{"addr":"0x6475f0","include_decompile":true,"include_proto":true},{"addr":"0x647640","include_decompile":true,"include_proto":true},{"addr":"0x647710","include_decompile":true,"include_proto":true},{"addr":"0x6477c0","include_decompile":true,"include_proto":true},{"addr":"0x647cf0","include_decompile":true,"include_proto":true},{"addr":"0x647d00","include_decompile":true,"include_proto":true},{"addr":"0x647d10","include_decompile":true,"include_proto":true},{"addr":"0x647d20","include_decompile":true,"include_proto":true},{"addr":"0x647e40","include_decompile":true,"include_proto":true},{"addr":"0x647e60","include_decompile":true,"include_proto":true},{"addr":"0x647e70","include_decompile":true,"include_proto":true},{"addr":"0x647ef0","include_decompile":true,"include_proto":true},{"addr":"0x647f00","include_decompile":true,"include_proto":true},{"addr":"0x647f20","include_decompile":true,"include_proto":true},{"addr":"0x647fc0","include_decompile":true,"include_proto":true},{"addr":"0x647ff0","include_decompile":true,"include_proto":true},{"addr":"0x648090","include_decompile":true,"include_proto":true},{"addr":"0x6480b0","include_decompile":true,"include_proto":true},{"addr":"0x6480e0","include_decompile":true,"include_proto":true},{"addr":"0x648120","include_decompile":true,"include_proto":true},{"addr":"0x648160","include_decompile":true,"include_proto":true},{"addr":"0x648190","include_decompile":true,"include_proto":true},{"addr":"0x6481c0","include_decompile":true,"include_proto":true},{"addr":"0x6481d0","include_decompile":true,"include_proto":true},{"addr":"0x6481f0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0045', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0045: empty response'); return; }
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
      console.log('Batch 0045: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0045 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0045 conn error:', e.message));
req.write(body);
req.end();
