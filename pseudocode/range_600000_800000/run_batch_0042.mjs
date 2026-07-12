
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x642ef0","include_decompile":true,"include_proto":true},{"addr":"0x642f10","include_decompile":true,"include_proto":true},{"addr":"0x642f40","include_decompile":true,"include_proto":true},{"addr":"0x642f50","include_decompile":true,"include_proto":true},{"addr":"0x642fb0","include_decompile":true,"include_proto":true},{"addr":"0x642ff0","include_decompile":true,"include_proto":true},{"addr":"0x643040","include_decompile":true,"include_proto":true},{"addr":"0x643070","include_decompile":true,"include_proto":true},{"addr":"0x6430a0","include_decompile":true,"include_proto":true},{"addr":"0x6430c0","include_decompile":true,"include_proto":true},{"addr":"0x6430e0","include_decompile":true,"include_proto":true},{"addr":"0x643100","include_decompile":true,"include_proto":true},{"addr":"0x643130","include_decompile":true,"include_proto":true},{"addr":"0x643150","include_decompile":true,"include_proto":true},{"addr":"0x643160","include_decompile":true,"include_proto":true},{"addr":"0x643190","include_decompile":true,"include_proto":true},{"addr":"0x643290","include_decompile":true,"include_proto":true},{"addr":"0x6432a0","include_decompile":true,"include_proto":true},{"addr":"0x643300","include_decompile":true,"include_proto":true},{"addr":"0x643330","include_decompile":true,"include_proto":true},{"addr":"0x643350","include_decompile":true,"include_proto":true},{"addr":"0x643370","include_decompile":true,"include_proto":true},{"addr":"0x643390","include_decompile":true,"include_proto":true},{"addr":"0x6433b0","include_decompile":true,"include_proto":true},{"addr":"0x643410","include_decompile":true,"include_proto":true},{"addr":"0x643420","include_decompile":true,"include_proto":true},{"addr":"0x643470","include_decompile":true,"include_proto":true},{"addr":"0x643490","include_decompile":true,"include_proto":true},{"addr":"0x6434b0","include_decompile":true,"include_proto":true},{"addr":"0x6434d0","include_decompile":true,"include_proto":true},{"addr":"0x6434f0","include_decompile":true,"include_proto":true},{"addr":"0x643600","include_decompile":true,"include_proto":true},{"addr":"0x643620","include_decompile":true,"include_proto":true},{"addr":"0x643640","include_decompile":true,"include_proto":true},{"addr":"0x6436b0","include_decompile":true,"include_proto":true},{"addr":"0x643790","include_decompile":true,"include_proto":true},{"addr":"0x6437c0","include_decompile":true,"include_proto":true},{"addr":"0x6437e0","include_decompile":true,"include_proto":true},{"addr":"0x643820","include_decompile":true,"include_proto":true},{"addr":"0x643850","include_decompile":true,"include_proto":true},{"addr":"0x643890","include_decompile":true,"include_proto":true},{"addr":"0x6438b0","include_decompile":true,"include_proto":true},{"addr":"0x6438d0","include_decompile":true,"include_proto":true},{"addr":"0x6438e0","include_decompile":true,"include_proto":true},{"addr":"0x643900","include_decompile":true,"include_proto":true},{"addr":"0x643920","include_decompile":true,"include_proto":true},{"addr":"0x643970","include_decompile":true,"include_proto":true},{"addr":"0x643990","include_decompile":true,"include_proto":true},{"addr":"0x6439a0","include_decompile":true,"include_proto":true},{"addr":"0x6439c0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0042', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0042: empty response'); return; }
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
      console.log('Batch 0042: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0042 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0042 conn error:', e.message));
req.write(body);
req.end();
