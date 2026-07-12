
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x667890","include_decompile":true,"include_proto":true},{"addr":"0x667900","include_decompile":true,"include_proto":true},{"addr":"0x667d40","include_decompile":true,"include_proto":true},{"addr":"0x667f90","include_decompile":true,"include_proto":true},{"addr":"0x668010","include_decompile":true,"include_proto":true},{"addr":"0x668090","include_decompile":true,"include_proto":true},{"addr":"0x668110","include_decompile":true,"include_proto":true},{"addr":"0x668190","include_decompile":true,"include_proto":true},{"addr":"0x668210","include_decompile":true,"include_proto":true},{"addr":"0x668290","include_decompile":true,"include_proto":true},{"addr":"0x668310","include_decompile":true,"include_proto":true},{"addr":"0x668390","include_decompile":true,"include_proto":true},{"addr":"0x668410","include_decompile":true,"include_proto":true},{"addr":"0x668490","include_decompile":true,"include_proto":true},{"addr":"0x668510","include_decompile":true,"include_proto":true},{"addr":"0x6686e0","include_decompile":true,"include_proto":true},{"addr":"0x6687d0","include_decompile":true,"include_proto":true},{"addr":"0x668810","include_decompile":true,"include_proto":true},{"addr":"0x668930","include_decompile":true,"include_proto":true},{"addr":"0x668ac0","include_decompile":true,"include_proto":true},{"addr":"0x66b2c0","include_decompile":true,"include_proto":true},{"addr":"0x66b370","include_decompile":true,"include_proto":true},{"addr":"0x66b470","include_decompile":true,"include_proto":true},{"addr":"0x66b4f0","include_decompile":true,"include_proto":true},{"addr":"0x66b6f0","include_decompile":true,"include_proto":true},{"addr":"0x66c3d0","include_decompile":true,"include_proto":true},{"addr":"0x66c820","include_decompile":true,"include_proto":true},{"addr":"0x66c890","include_decompile":true,"include_proto":true},{"addr":"0x66c900","include_decompile":true,"include_proto":true},{"addr":"0x66c980","include_decompile":true,"include_proto":true},{"addr":"0x66ca30","include_decompile":true,"include_proto":true},{"addr":"0x66cab0","include_decompile":true,"include_proto":true},{"addr":"0x66cb30","include_decompile":true,"include_proto":true},{"addr":"0x66cb40","include_decompile":true,"include_proto":true},{"addr":"0x66cb50","include_decompile":true,"include_proto":true},{"addr":"0x66cb60","include_decompile":true,"include_proto":true},{"addr":"0x66cb70","include_decompile":true,"include_proto":true},{"addr":"0x66cb80","include_decompile":true,"include_proto":true},{"addr":"0x66cb90","include_decompile":true,"include_proto":true},{"addr":"0x66cba0","include_decompile":true,"include_proto":true},{"addr":"0x66cbb0","include_decompile":true,"include_proto":true},{"addr":"0x66cbc0","include_decompile":true,"include_proto":true},{"addr":"0x66cbd0","include_decompile":true,"include_proto":true},{"addr":"0x66cbe0","include_decompile":true,"include_proto":true},{"addr":"0x66cbf0","include_decompile":true,"include_proto":true},{"addr":"0x66cd70","include_decompile":true,"include_proto":true},{"addr":"0x66cf30","include_decompile":true,"include_proto":true},{"addr":"0x66d000","include_decompile":true,"include_proto":true},{"addr":"0x66d100","include_decompile":true,"include_proto":true},{"addr":"0x66d110","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0060', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0060: empty response'); return; }
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
      console.log('Batch 0060: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0060 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0060 conn error:', e.message));
req.write(body);
req.end();
