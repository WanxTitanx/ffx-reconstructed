
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6e1ea0","include_decompile":true,"include_proto":true},{"addr":"0x6e1f10","include_decompile":true,"include_proto":true},{"addr":"0x6e1f70","include_decompile":true,"include_proto":true},{"addr":"0x6e1ff0","include_decompile":true,"include_proto":true},{"addr":"0x6e2070","include_decompile":true,"include_proto":true},{"addr":"0x6e2080","include_decompile":true,"include_proto":true},{"addr":"0x6e20b0","include_decompile":true,"include_proto":true},{"addr":"0x6e20e0","include_decompile":true,"include_proto":true},{"addr":"0x6e2130","include_decompile":true,"include_proto":true},{"addr":"0x6e2280","include_decompile":true,"include_proto":true},{"addr":"0x6e22c0","include_decompile":true,"include_proto":true},{"addr":"0x6e22e0","include_decompile":true,"include_proto":true},{"addr":"0x6e22f0","include_decompile":true,"include_proto":true},{"addr":"0x6e2310","include_decompile":true,"include_proto":true},{"addr":"0x6e2320","include_decompile":true,"include_proto":true},{"addr":"0x6e2330","include_decompile":true,"include_proto":true},{"addr":"0x6e2340","include_decompile":true,"include_proto":true},{"addr":"0x6e2470","include_decompile":true,"include_proto":true},{"addr":"0x6e2480","include_decompile":true,"include_proto":true},{"addr":"0x6e2490","include_decompile":true,"include_proto":true},{"addr":"0x6e24a0","include_decompile":true,"include_proto":true},{"addr":"0x6e24c0","include_decompile":true,"include_proto":true},{"addr":"0x6e24e0","include_decompile":true,"include_proto":true},{"addr":"0x6e2500","include_decompile":true,"include_proto":true},{"addr":"0x6e25d0","include_decompile":true,"include_proto":true},{"addr":"0x6e25f0","include_decompile":true,"include_proto":true},{"addr":"0x6e2610","include_decompile":true,"include_proto":true},{"addr":"0x6e2630","include_decompile":true,"include_proto":true},{"addr":"0x6e26a0","include_decompile":true,"include_proto":true},{"addr":"0x6e2700","include_decompile":true,"include_proto":true},{"addr":"0x6e2730","include_decompile":true,"include_proto":true},{"addr":"0x6e2890","include_decompile":true,"include_proto":true},{"addr":"0x6e2910","include_decompile":true,"include_proto":true},{"addr":"0x6e2990","include_decompile":true,"include_proto":true},{"addr":"0x6e2a20","include_decompile":true,"include_proto":true},{"addr":"0x6e2aa0","include_decompile":true,"include_proto":true},{"addr":"0x6e2ae0","include_decompile":true,"include_proto":true},{"addr":"0x6e2b20","include_decompile":true,"include_proto":true},{"addr":"0x6e2b60","include_decompile":true,"include_proto":true},{"addr":"0x6e2b90","include_decompile":true,"include_proto":true},{"addr":"0x6e2bc0","include_decompile":true,"include_proto":true},{"addr":"0x6e2bf0","include_decompile":true,"include_proto":true},{"addr":"0x6e2c40","include_decompile":true,"include_proto":true},{"addr":"0x6e2dd0","include_decompile":true,"include_proto":true},{"addr":"0x6e2e40","include_decompile":true,"include_proto":true},{"addr":"0x6e2eb0","include_decompile":true,"include_proto":true},{"addr":"0x6e2f20","include_decompile":true,"include_proto":true},{"addr":"0x6e2f50","include_decompile":true,"include_proto":true},{"addr":"0x6e2f70","include_decompile":true,"include_proto":true},{"addr":"0x6e30a0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0109', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0109: empty response'); return; }
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
      console.log('Batch 0109: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0109 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0109 conn error:', e.message));
req.write(body);
req.end();
