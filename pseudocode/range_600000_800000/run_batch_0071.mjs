
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x67aec0","include_decompile":true,"include_proto":true},{"addr":"0x67aed0","include_decompile":true,"include_proto":true},{"addr":"0x67aee0","include_decompile":true,"include_proto":true},{"addr":"0x67b330","include_decompile":true,"include_proto":true},{"addr":"0x67b3e0","include_decompile":true,"include_proto":true},{"addr":"0x67b620","include_decompile":true,"include_proto":true},{"addr":"0x67b6e0","include_decompile":true,"include_proto":true},{"addr":"0x67b830","include_decompile":true,"include_proto":true},{"addr":"0x67b870","include_decompile":true,"include_proto":true},{"addr":"0x67b8f0","include_decompile":true,"include_proto":true},{"addr":"0x67b920","include_decompile":true,"include_proto":true},{"addr":"0x67b980","include_decompile":true,"include_proto":true},{"addr":"0x67b9d0","include_decompile":true,"include_proto":true},{"addr":"0x67ba00","include_decompile":true,"include_proto":true},{"addr":"0x67bb00","include_decompile":true,"include_proto":true},{"addr":"0x67bb10","include_decompile":true,"include_proto":true},{"addr":"0x67bb20","include_decompile":true,"include_proto":true},{"addr":"0x67bb40","include_decompile":true,"include_proto":true},{"addr":"0x67bb80","include_decompile":true,"include_proto":true},{"addr":"0x67bc00","include_decompile":true,"include_proto":true},{"addr":"0x67c1e0","include_decompile":true,"include_proto":true},{"addr":"0x67c320","include_decompile":true,"include_proto":true},{"addr":"0x67c3c0","include_decompile":true,"include_proto":true},{"addr":"0x67c480","include_decompile":true,"include_proto":true},{"addr":"0x67c5e0","include_decompile":true,"include_proto":true},{"addr":"0x67c5f0","include_decompile":true,"include_proto":true},{"addr":"0x67c7d0","include_decompile":true,"include_proto":true},{"addr":"0x67c8a0","include_decompile":true,"include_proto":true},{"addr":"0x67c8d0","include_decompile":true,"include_proto":true},{"addr":"0x67c950","include_decompile":true,"include_proto":true},{"addr":"0x67ca70","include_decompile":true,"include_proto":true},{"addr":"0x67caa0","include_decompile":true,"include_proto":true},{"addr":"0x67cad0","include_decompile":true,"include_proto":true},{"addr":"0x67cce0","include_decompile":true,"include_proto":true},{"addr":"0x67cd50","include_decompile":true,"include_proto":true},{"addr":"0x67cd80","include_decompile":true,"include_proto":true},{"addr":"0x67cff0","include_decompile":true,"include_proto":true},{"addr":"0x67d250","include_decompile":true,"include_proto":true},{"addr":"0x67d320","include_decompile":true,"include_proto":true},{"addr":"0x67d510","include_decompile":true,"include_proto":true},{"addr":"0x67d6f0","include_decompile":true,"include_proto":true},{"addr":"0x67d7f0","include_decompile":true,"include_proto":true},{"addr":"0x67d810","include_decompile":true,"include_proto":true},{"addr":"0x67d830","include_decompile":true,"include_proto":true},{"addr":"0x67d900","include_decompile":true,"include_proto":true},{"addr":"0x67dac0","include_decompile":true,"include_proto":true},{"addr":"0x67dd50","include_decompile":true,"include_proto":true},{"addr":"0x67dd90","include_decompile":true,"include_proto":true},{"addr":"0x67de10","include_decompile":true,"include_proto":true},{"addr":"0x67df10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0071', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0071: empty response'); return; }
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
      console.log('Batch 0071: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0071 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0071 conn error:', e.message));
req.write(body);
req.end();
