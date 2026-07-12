
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7a2cf0","include_decompile":true,"include_proto":true},{"addr":"0x7a2d00","include_decompile":true,"include_proto":true},{"addr":"0x7a2d20","include_decompile":true,"include_proto":true},{"addr":"0x7a2d50","include_decompile":true,"include_proto":true},{"addr":"0x7a2da0","include_decompile":true,"include_proto":true},{"addr":"0x7a2de0","include_decompile":true,"include_proto":true},{"addr":"0x7a2e10","include_decompile":true,"include_proto":true},{"addr":"0x7a2e80","include_decompile":true,"include_proto":true},{"addr":"0x7a2ed0","include_decompile":true,"include_proto":true},{"addr":"0x7a2f00","include_decompile":true,"include_proto":true},{"addr":"0x7a2f60","include_decompile":true,"include_proto":true},{"addr":"0x7a2fa0","include_decompile":true,"include_proto":true},{"addr":"0x7a3000","include_decompile":true,"include_proto":true},{"addr":"0x7a3060","include_decompile":true,"include_proto":true},{"addr":"0x7a30c0","include_decompile":true,"include_proto":true},{"addr":"0x7a3110","include_decompile":true,"include_proto":true},{"addr":"0x7a3190","include_decompile":true,"include_proto":true},{"addr":"0x7a31f0","include_decompile":true,"include_proto":true},{"addr":"0x7a32c0","include_decompile":true,"include_proto":true},{"addr":"0x7a3320","include_decompile":true,"include_proto":true},{"addr":"0x7a3350","include_decompile":true,"include_proto":true},{"addr":"0x7a3420","include_decompile":true,"include_proto":true},{"addr":"0x7a3440","include_decompile":true,"include_proto":true},{"addr":"0x7a3460","include_decompile":true,"include_proto":true},{"addr":"0x7a3470","include_decompile":true,"include_proto":true},{"addr":"0x7a3480","include_decompile":true,"include_proto":true},{"addr":"0x7a3500","include_decompile":true,"include_proto":true},{"addr":"0x7a3520","include_decompile":true,"include_proto":true},{"addr":"0x7a3550","include_decompile":true,"include_proto":true},{"addr":"0x7a3580","include_decompile":true,"include_proto":true},{"addr":"0x7a35c0","include_decompile":true,"include_proto":true},{"addr":"0x7a35e0","include_decompile":true,"include_proto":true},{"addr":"0x7a35f0","include_decompile":true,"include_proto":true},{"addr":"0x7a3670","include_decompile":true,"include_proto":true},{"addr":"0x7a36e0","include_decompile":true,"include_proto":true},{"addr":"0x7a3700","include_decompile":true,"include_proto":true},{"addr":"0x7a3730","include_decompile":true,"include_proto":true},{"addr":"0x7a3750","include_decompile":true,"include_proto":true},{"addr":"0x7a37a0","include_decompile":true,"include_proto":true},{"addr":"0x7a3800","include_decompile":true,"include_proto":true},{"addr":"0x7a38a0","include_decompile":true,"include_proto":true},{"addr":"0x7a3920","include_decompile":true,"include_proto":true},{"addr":"0x7a3940","include_decompile":true,"include_proto":true},{"addr":"0x7a3970","include_decompile":true,"include_proto":true},{"addr":"0x7a3990","include_decompile":true,"include_proto":true},{"addr":"0x7a39a0","include_decompile":true,"include_proto":true},{"addr":"0x7a39f0","include_decompile":true,"include_proto":true},{"addr":"0x7a3a10","include_decompile":true,"include_proto":true},{"addr":"0x7a3a30","include_decompile":true,"include_proto":true},{"addr":"0x7a3aa0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0179', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0179: empty response'); return; }
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
      console.log('Batch 0179: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0179 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0179 conn error:', e.message));
req.write(body);
req.end();
