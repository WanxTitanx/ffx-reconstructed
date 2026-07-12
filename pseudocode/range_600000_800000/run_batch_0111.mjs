
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6e5880","include_decompile":true,"include_proto":true},{"addr":"0x6e58d0","include_decompile":true,"include_proto":true},{"addr":"0x6e58e0","include_decompile":true,"include_proto":true},{"addr":"0x6e5af0","include_decompile":true,"include_proto":true},{"addr":"0x6e5b70","include_decompile":true,"include_proto":true},{"addr":"0x6e5d00","include_decompile":true,"include_proto":true},{"addr":"0x6e5db0","include_decompile":true,"include_proto":true},{"addr":"0x6e5dc0","include_decompile":true,"include_proto":true},{"addr":"0x6e6010","include_decompile":true,"include_proto":true},{"addr":"0x6e6200","include_decompile":true,"include_proto":true},{"addr":"0x6e6460","include_decompile":true,"include_proto":true},{"addr":"0x6e64d0","include_decompile":true,"include_proto":true},{"addr":"0x6e6580","include_decompile":true,"include_proto":true},{"addr":"0x6e6590","include_decompile":true,"include_proto":true},{"addr":"0x6e6780","include_decompile":true,"include_proto":true},{"addr":"0x6e6790","include_decompile":true,"include_proto":true},{"addr":"0x6e67a0","include_decompile":true,"include_proto":true},{"addr":"0x6e6860","include_decompile":true,"include_proto":true},{"addr":"0x6e69c0","include_decompile":true,"include_proto":true},{"addr":"0x6e6b10","include_decompile":true,"include_proto":true},{"addr":"0x6e6b80","include_decompile":true,"include_proto":true},{"addr":"0x6e6ee0","include_decompile":true,"include_proto":true},{"addr":"0x6e7050","include_decompile":true,"include_proto":true},{"addr":"0x6e7180","include_decompile":true,"include_proto":true},{"addr":"0x6e7430","include_decompile":true,"include_proto":true},{"addr":"0x6e75a0","include_decompile":true,"include_proto":true},{"addr":"0x6e77f0","include_decompile":true,"include_proto":true},{"addr":"0x6e7820","include_decompile":true,"include_proto":true},{"addr":"0x6e7840","include_decompile":true,"include_proto":true},{"addr":"0x6e7850","include_decompile":true,"include_proto":true},{"addr":"0x6e7900","include_decompile":true,"include_proto":true},{"addr":"0x6e79d0","include_decompile":true,"include_proto":true},{"addr":"0x6e79f0","include_decompile":true,"include_proto":true},{"addr":"0x6e7a10","include_decompile":true,"include_proto":true},{"addr":"0x6e7a70","include_decompile":true,"include_proto":true},{"addr":"0x6e8040","include_decompile":true,"include_proto":true},{"addr":"0x6e8160","include_decompile":true,"include_proto":true},{"addr":"0x6e8280","include_decompile":true,"include_proto":true},{"addr":"0x6e8330","include_decompile":true,"include_proto":true},{"addr":"0x6e84d0","include_decompile":true,"include_proto":true},{"addr":"0x6e8680","include_decompile":true,"include_proto":true},{"addr":"0x6e8730","include_decompile":true,"include_proto":true},{"addr":"0x6e87d0","include_decompile":true,"include_proto":true},{"addr":"0x6e8840","include_decompile":true,"include_proto":true},{"addr":"0x6e8890","include_decompile":true,"include_proto":true},{"addr":"0x6e88a0","include_decompile":true,"include_proto":true},{"addr":"0x6e88b0","include_decompile":true,"include_proto":true},{"addr":"0x6e8950","include_decompile":true,"include_proto":true},{"addr":"0x6e8ab0","include_decompile":true,"include_proto":true},{"addr":"0x6e8b90","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0111', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0111: empty response'); return; }
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
      console.log('Batch 0111: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0111 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0111 conn error:', e.message));
req.write(body);
req.end();
