
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x679db0","include_decompile":true,"include_proto":true},{"addr":"0x679e10","include_decompile":true,"include_proto":true},{"addr":"0x679e60","include_decompile":true,"include_proto":true},{"addr":"0x679f60","include_decompile":true,"include_proto":true},{"addr":"0x67a010","include_decompile":true,"include_proto":true},{"addr":"0x67a0d0","include_decompile":true,"include_proto":true},{"addr":"0x67a130","include_decompile":true,"include_proto":true},{"addr":"0x67a150","include_decompile":true,"include_proto":true},{"addr":"0x67a160","include_decompile":true,"include_proto":true},{"addr":"0x67a170","include_decompile":true,"include_proto":true},{"addr":"0x67a190","include_decompile":true,"include_proto":true},{"addr":"0x67a1c0","include_decompile":true,"include_proto":true},{"addr":"0x67a1e0","include_decompile":true,"include_proto":true},{"addr":"0x67a1f0","include_decompile":true,"include_proto":true},{"addr":"0x67a210","include_decompile":true,"include_proto":true},{"addr":"0x67a240","include_decompile":true,"include_proto":true},{"addr":"0x67a260","include_decompile":true,"include_proto":true},{"addr":"0x67a280","include_decompile":true,"include_proto":true},{"addr":"0x67a2a0","include_decompile":true,"include_proto":true},{"addr":"0x67a2e0","include_decompile":true,"include_proto":true},{"addr":"0x67a300","include_decompile":true,"include_proto":true},{"addr":"0x67a320","include_decompile":true,"include_proto":true},{"addr":"0x67a340","include_decompile":true,"include_proto":true},{"addr":"0x67a360","include_decompile":true,"include_proto":true},{"addr":"0x67a390","include_decompile":true,"include_proto":true},{"addr":"0x67a3c0","include_decompile":true,"include_proto":true},{"addr":"0x67a3e0","include_decompile":true,"include_proto":true},{"addr":"0x67a3f0","include_decompile":true,"include_proto":true},{"addr":"0x67a400","include_decompile":true,"include_proto":true},{"addr":"0x67a420","include_decompile":true,"include_proto":true},{"addr":"0x67a440","include_decompile":true,"include_proto":true},{"addr":"0x67a460","include_decompile":true,"include_proto":true},{"addr":"0x67a480","include_decompile":true,"include_proto":true},{"addr":"0x67a4a0","include_decompile":true,"include_proto":true},{"addr":"0x67a4c0","include_decompile":true,"include_proto":true},{"addr":"0x67a4e0","include_decompile":true,"include_proto":true},{"addr":"0x67a4f0","include_decompile":true,"include_proto":true},{"addr":"0x67a510","include_decompile":true,"include_proto":true},{"addr":"0x67a530","include_decompile":true,"include_proto":true},{"addr":"0x67a550","include_decompile":true,"include_proto":true},{"addr":"0x67a570","include_decompile":true,"include_proto":true},{"addr":"0x67a590","include_decompile":true,"include_proto":true},{"addr":"0x67a5b0","include_decompile":true,"include_proto":true},{"addr":"0x67a5d0","include_decompile":true,"include_proto":true},{"addr":"0x67a5f0","include_decompile":true,"include_proto":true},{"addr":"0x67a610","include_decompile":true,"include_proto":true},{"addr":"0x67a630","include_decompile":true,"include_proto":true},{"addr":"0x67a650","include_decompile":true,"include_proto":true},{"addr":"0x67a670","include_decompile":true,"include_proto":true},{"addr":"0x67a680","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0069', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0069: empty response'); return; }
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
      console.log('Batch 0069: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0069 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0069 conn error:', e.message));
req.write(body);
req.end();
