
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x655940","include_decompile":true,"include_proto":true},{"addr":"0x655950","include_decompile":true,"include_proto":true},{"addr":"0x655a30","include_decompile":true,"include_proto":true},{"addr":"0x655a40","include_decompile":true,"include_proto":true},{"addr":"0x655a50","include_decompile":true,"include_proto":true},{"addr":"0x655a60","include_decompile":true,"include_proto":true},{"addr":"0x655a70","include_decompile":true,"include_proto":true},{"addr":"0x655a80","include_decompile":true,"include_proto":true},{"addr":"0x655a90","include_decompile":true,"include_proto":true},{"addr":"0x655aa0","include_decompile":true,"include_proto":true},{"addr":"0x655ab0","include_decompile":true,"include_proto":true},{"addr":"0x655ac0","include_decompile":true,"include_proto":true},{"addr":"0x655ad0","include_decompile":true,"include_proto":true},{"addr":"0x655b50","include_decompile":true,"include_proto":true},{"addr":"0x655bd0","include_decompile":true,"include_proto":true},{"addr":"0x655cd0","include_decompile":true,"include_proto":true},{"addr":"0x655e10","include_decompile":true,"include_proto":true},{"addr":"0x655e80","include_decompile":true,"include_proto":true},{"addr":"0x655ef0","include_decompile":true,"include_proto":true},{"addr":"0x655f90","include_decompile":true,"include_proto":true},{"addr":"0x656030","include_decompile":true,"include_proto":true},{"addr":"0x6560b0","include_decompile":true,"include_proto":true},{"addr":"0x6560c0","include_decompile":true,"include_proto":true},{"addr":"0x656120","include_decompile":true,"include_proto":true},{"addr":"0x656130","include_decompile":true,"include_proto":true},{"addr":"0x656160","include_decompile":true,"include_proto":true},{"addr":"0x656270","include_decompile":true,"include_proto":true},{"addr":"0x6564a0","include_decompile":true,"include_proto":true},{"addr":"0x656500","include_decompile":true,"include_proto":true},{"addr":"0x656650","include_decompile":true,"include_proto":true},{"addr":"0x656740","include_decompile":true,"include_proto":true},{"addr":"0x656790","include_decompile":true,"include_proto":true},{"addr":"0x656870","include_decompile":true,"include_proto":true},{"addr":"0x656930","include_decompile":true,"include_proto":true},{"addr":"0x656990","include_decompile":true,"include_proto":true},{"addr":"0x656a50","include_decompile":true,"include_proto":true},{"addr":"0x656af0","include_decompile":true,"include_proto":true},{"addr":"0x656b40","include_decompile":true,"include_proto":true},{"addr":"0x656bb0","include_decompile":true,"include_proto":true},{"addr":"0x656c90","include_decompile":true,"include_proto":true},{"addr":"0x656d40","include_decompile":true,"include_proto":true},{"addr":"0x656dc0","include_decompile":true,"include_proto":true},{"addr":"0x6572f0","include_decompile":true,"include_proto":true},{"addr":"0x657730","include_decompile":true,"include_proto":true},{"addr":"0x657860","include_decompile":true,"include_proto":true},{"addr":"0x6579b0","include_decompile":true,"include_proto":true},{"addr":"0x6579e0","include_decompile":true,"include_proto":true},{"addr":"0x657a10","include_decompile":true,"include_proto":true},{"addr":"0x657a40","include_decompile":true,"include_proto":true},{"addr":"0x657a70","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0054', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0054: empty response'); return; }
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
      console.log('Batch 0054: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0054 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0054 conn error:', e.message));
req.write(body);
req.end();
