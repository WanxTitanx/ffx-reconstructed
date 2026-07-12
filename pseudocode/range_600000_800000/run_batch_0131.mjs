
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x715b20","include_decompile":true,"include_proto":true},{"addr":"0x715bd0","include_decompile":true,"include_proto":true},{"addr":"0x715ea0","include_decompile":true,"include_proto":true},{"addr":"0x716130","include_decompile":true,"include_proto":true},{"addr":"0x7161f0","include_decompile":true,"include_proto":true},{"addr":"0x7162d0","include_decompile":true,"include_proto":true},{"addr":"0x7164c0","include_decompile":true,"include_proto":true},{"addr":"0x716630","include_decompile":true,"include_proto":true},{"addr":"0x716650","include_decompile":true,"include_proto":true},{"addr":"0x716700","include_decompile":true,"include_proto":true},{"addr":"0x716790","include_decompile":true,"include_proto":true},{"addr":"0x7167a0","include_decompile":true,"include_proto":true},{"addr":"0x7167f0","include_decompile":true,"include_proto":true},{"addr":"0x716850","include_decompile":true,"include_proto":true},{"addr":"0x7169d0","include_decompile":true,"include_proto":true},{"addr":"0x716ab0","include_decompile":true,"include_proto":true},{"addr":"0x716b10","include_decompile":true,"include_proto":true},{"addr":"0x716b70","include_decompile":true,"include_proto":true},{"addr":"0x716ba0","include_decompile":true,"include_proto":true},{"addr":"0x716c50","include_decompile":true,"include_proto":true},{"addr":"0x716c80","include_decompile":true,"include_proto":true},{"addr":"0x716cc0","include_decompile":true,"include_proto":true},{"addr":"0x716d20","include_decompile":true,"include_proto":true},{"addr":"0x7170f0","include_decompile":true,"include_proto":true},{"addr":"0x7174e0","include_decompile":true,"include_proto":true},{"addr":"0x7174f0","include_decompile":true,"include_proto":true},{"addr":"0x7176d0","include_decompile":true,"include_proto":true},{"addr":"0x7176e0","include_decompile":true,"include_proto":true},{"addr":"0x7176f0","include_decompile":true,"include_proto":true},{"addr":"0x717700","include_decompile":true,"include_proto":true},{"addr":"0x717c80","include_decompile":true,"include_proto":true},{"addr":"0x7186c0","include_decompile":true,"include_proto":true},{"addr":"0x7186f0","include_decompile":true,"include_proto":true},{"addr":"0x7197d0","include_decompile":true,"include_proto":true},{"addr":"0x71a1a0","include_decompile":true,"include_proto":true},{"addr":"0x71a410","include_decompile":true,"include_proto":true},{"addr":"0x71a5c0","include_decompile":true,"include_proto":true},{"addr":"0x71b980","include_decompile":true,"include_proto":true},{"addr":"0x71c190","include_decompile":true,"include_proto":true},{"addr":"0x71cf00","include_decompile":true,"include_proto":true},{"addr":"0x71d070","include_decompile":true,"include_proto":true},{"addr":"0x71d600","include_decompile":true,"include_proto":true},{"addr":"0x71dcb0","include_decompile":true,"include_proto":true},{"addr":"0x71e410","include_decompile":true,"include_proto":true},{"addr":"0x71e540","include_decompile":true,"include_proto":true},{"addr":"0x71e6f0","include_decompile":true,"include_proto":true},{"addr":"0x71e7d0","include_decompile":true,"include_proto":true},{"addr":"0x71e800","include_decompile":true,"include_proto":true},{"addr":"0x71e8f0","include_decompile":true,"include_proto":true},{"addr":"0x71e900","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0131', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0131: empty response'); return; }
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
      console.log('Batch 0131: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0131 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0131 conn error:', e.message));
req.write(body);
req.end();
