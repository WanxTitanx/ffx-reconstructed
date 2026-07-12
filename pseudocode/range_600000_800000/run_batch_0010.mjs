
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6149a0","include_decompile":true,"include_proto":true},{"addr":"0x6149c0","include_decompile":true,"include_proto":true},{"addr":"0x614a70","include_decompile":true,"include_proto":true},{"addr":"0x614a80","include_decompile":true,"include_proto":true},{"addr":"0x614a90","include_decompile":true,"include_proto":true},{"addr":"0x614d20","include_decompile":true,"include_proto":true},{"addr":"0x614d30","include_decompile":true,"include_proto":true},{"addr":"0x614dc0","include_decompile":true,"include_proto":true},{"addr":"0x614df0","include_decompile":true,"include_proto":true},{"addr":"0x614e20","include_decompile":true,"include_proto":true},{"addr":"0x615300","include_decompile":true,"include_proto":true},{"addr":"0x6153d0","include_decompile":true,"include_proto":true},{"addr":"0x615420","include_decompile":true,"include_proto":true},{"addr":"0x615460","include_decompile":true,"include_proto":true},{"addr":"0x6154b0","include_decompile":true,"include_proto":true},{"addr":"0x615710","include_decompile":true,"include_proto":true},{"addr":"0x615c80","include_decompile":true,"include_proto":true},{"addr":"0x615d10","include_decompile":true,"include_proto":true},{"addr":"0x615d80","include_decompile":true,"include_proto":true},{"addr":"0x615e10","include_decompile":true,"include_proto":true},{"addr":"0x615e90","include_decompile":true,"include_proto":true},{"addr":"0x615ec0","include_decompile":true,"include_proto":true},{"addr":"0x615f60","include_decompile":true,"include_proto":true},{"addr":"0x615fa0","include_decompile":true,"include_proto":true},{"addr":"0x616060","include_decompile":true,"include_proto":true},{"addr":"0x616100","include_decompile":true,"include_proto":true},{"addr":"0x6161d0","include_decompile":true,"include_proto":true},{"addr":"0x6162c0","include_decompile":true,"include_proto":true},{"addr":"0x6162d0","include_decompile":true,"include_proto":true},{"addr":"0x6162e0","include_decompile":true,"include_proto":true},{"addr":"0x616300","include_decompile":true,"include_proto":true},{"addr":"0x616310","include_decompile":true,"include_proto":true},{"addr":"0x616330","include_decompile":true,"include_proto":true},{"addr":"0x616360","include_decompile":true,"include_proto":true},{"addr":"0x6163a0","include_decompile":true,"include_proto":true},{"addr":"0x6164d0","include_decompile":true,"include_proto":true},{"addr":"0x6164f0","include_decompile":true,"include_proto":true},{"addr":"0x6165f0","include_decompile":true,"include_proto":true},{"addr":"0x616630","include_decompile":true,"include_proto":true},{"addr":"0x616640","include_decompile":true,"include_proto":true},{"addr":"0x616650","include_decompile":true,"include_proto":true},{"addr":"0x616680","include_decompile":true,"include_proto":true},{"addr":"0x616690","include_decompile":true,"include_proto":true},{"addr":"0x6166e0","include_decompile":true,"include_proto":true},{"addr":"0x6166f0","include_decompile":true,"include_proto":true},{"addr":"0x616780","include_decompile":true,"include_proto":true},{"addr":"0x6167b0","include_decompile":true,"include_proto":true},{"addr":"0x6167c0","include_decompile":true,"include_proto":true},{"addr":"0x6167d0","include_decompile":true,"include_proto":true},{"addr":"0x616870","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0010', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0010: empty response'); return; }
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
      console.log('Batch 0010: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0010 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0010 conn error:', e.message));
req.write(body);
req.end();
