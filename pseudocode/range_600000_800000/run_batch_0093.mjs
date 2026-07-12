
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6b31b0","include_decompile":true,"include_proto":true},{"addr":"0x6b3510","include_decompile":true,"include_proto":true},{"addr":"0x6b3750","include_decompile":true,"include_proto":true},{"addr":"0x6b37a0","include_decompile":true,"include_proto":true},{"addr":"0x6b37b0","include_decompile":true,"include_proto":true},{"addr":"0x6b3f60","include_decompile":true,"include_proto":true},{"addr":"0x6b4090","include_decompile":true,"include_proto":true},{"addr":"0x6b4130","include_decompile":true,"include_proto":true},{"addr":"0x6b4410","include_decompile":true,"include_proto":true},{"addr":"0x6b4480","include_decompile":true,"include_proto":true},{"addr":"0x6b45a0","include_decompile":true,"include_proto":true},{"addr":"0x6b45f0","include_decompile":true,"include_proto":true},{"addr":"0x6b4930","include_decompile":true,"include_proto":true},{"addr":"0x6b4a50","include_decompile":true,"include_proto":true},{"addr":"0x6b4a60","include_decompile":true,"include_proto":true},{"addr":"0x6b4a70","include_decompile":true,"include_proto":true},{"addr":"0x6b4aa0","include_decompile":true,"include_proto":true},{"addr":"0x6b4ae0","include_decompile":true,"include_proto":true},{"addr":"0x6b4b00","include_decompile":true,"include_proto":true},{"addr":"0x6b4b10","include_decompile":true,"include_proto":true},{"addr":"0x6b4bc0","include_decompile":true,"include_proto":true},{"addr":"0x6b4bd0","include_decompile":true,"include_proto":true},{"addr":"0x6b4e60","include_decompile":true,"include_proto":true},{"addr":"0x6b5070","include_decompile":true,"include_proto":true},{"addr":"0x6b5080","include_decompile":true,"include_proto":true},{"addr":"0x6b5090","include_decompile":true,"include_proto":true},{"addr":"0x6b50d0","include_decompile":true,"include_proto":true},{"addr":"0x6b5150","include_decompile":true,"include_proto":true},{"addr":"0x6b52b0","include_decompile":true,"include_proto":true},{"addr":"0x6b52c0","include_decompile":true,"include_proto":true},{"addr":"0x6b52d0","include_decompile":true,"include_proto":true},{"addr":"0x6b52e0","include_decompile":true,"include_proto":true},{"addr":"0x6b52f0","include_decompile":true,"include_proto":true},{"addr":"0x6b5300","include_decompile":true,"include_proto":true},{"addr":"0x6b5310","include_decompile":true,"include_proto":true},{"addr":"0x6b5330","include_decompile":true,"include_proto":true},{"addr":"0x6b5350","include_decompile":true,"include_proto":true},{"addr":"0x6b5370","include_decompile":true,"include_proto":true},{"addr":"0x6b5390","include_decompile":true,"include_proto":true},{"addr":"0x6b53a0","include_decompile":true,"include_proto":true},{"addr":"0x6b53b0","include_decompile":true,"include_proto":true},{"addr":"0x6b53d0","include_decompile":true,"include_proto":true},{"addr":"0x6b53f0","include_decompile":true,"include_proto":true},{"addr":"0x6b5500","include_decompile":true,"include_proto":true},{"addr":"0x6b5590","include_decompile":true,"include_proto":true},{"addr":"0x6b5670","include_decompile":true,"include_proto":true},{"addr":"0x6b5720","include_decompile":true,"include_proto":true},{"addr":"0x6b57c0","include_decompile":true,"include_proto":true},{"addr":"0x6b5880","include_decompile":true,"include_proto":true},{"addr":"0x6b5920","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0093', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0093: empty response'); return; }
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
      console.log('Batch 0093: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0093 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0093 conn error:', e.message));
req.write(body);
req.end();
