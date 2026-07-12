
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7e9760","include_decompile":true,"include_proto":true},{"addr":"0x7e97c0","include_decompile":true,"include_proto":true},{"addr":"0x7e9880","include_decompile":true,"include_proto":true},{"addr":"0x7e98e0","include_decompile":true,"include_proto":true},{"addr":"0x7e9940","include_decompile":true,"include_proto":true},{"addr":"0x7e99a0","include_decompile":true,"include_proto":true},{"addr":"0x7e9a00","include_decompile":true,"include_proto":true},{"addr":"0x7e9a60","include_decompile":true,"include_proto":true},{"addr":"0x7e9d30","include_decompile":true,"include_proto":true},{"addr":"0x7e9e30","include_decompile":true,"include_proto":true},{"addr":"0x7ea030","include_decompile":true,"include_proto":true},{"addr":"0x7ea1e0","include_decompile":true,"include_proto":true},{"addr":"0x7ea460","include_decompile":true,"include_proto":true},{"addr":"0x7ea5e0","include_decompile":true,"include_proto":true},{"addr":"0x7ea610","include_decompile":true,"include_proto":true},{"addr":"0x7ea640","include_decompile":true,"include_proto":true},{"addr":"0x7ea670","include_decompile":true,"include_proto":true},{"addr":"0x7ea760","include_decompile":true,"include_proto":true},{"addr":"0x7ea800","include_decompile":true,"include_proto":true},{"addr":"0x7ea8e0","include_decompile":true,"include_proto":true},{"addr":"0x7ea9d0","include_decompile":true,"include_proto":true},{"addr":"0x7ea9e0","include_decompile":true,"include_proto":true},{"addr":"0x7eacc0","include_decompile":true,"include_proto":true},{"addr":"0x7eacd0","include_decompile":true,"include_proto":true},{"addr":"0x7eb210","include_decompile":true,"include_proto":true},{"addr":"0x7eb230","include_decompile":true,"include_proto":true},{"addr":"0x7eb260","include_decompile":true,"include_proto":true},{"addr":"0x7eb280","include_decompile":true,"include_proto":true},{"addr":"0x7eb2b0","include_decompile":true,"include_proto":true},{"addr":"0x7eb2d0","include_decompile":true,"include_proto":true},{"addr":"0x7eb320","include_decompile":true,"include_proto":true},{"addr":"0x7eb340","include_decompile":true,"include_proto":true},{"addr":"0x7eb3b0","include_decompile":true,"include_proto":true},{"addr":"0x7eb410","include_decompile":true,"include_proto":true},{"addr":"0x7eb480","include_decompile":true,"include_proto":true},{"addr":"0x7eb490","include_decompile":true,"include_proto":true},{"addr":"0x7eb660","include_decompile":true,"include_proto":true},{"addr":"0x7eb670","include_decompile":true,"include_proto":true},{"addr":"0x7ec330","include_decompile":true,"include_proto":true},{"addr":"0x7ec340","include_decompile":true,"include_proto":true},{"addr":"0x7ec350","include_decompile":true,"include_proto":true},{"addr":"0x7ec360","include_decompile":true,"include_proto":true},{"addr":"0x7ec370","include_decompile":true,"include_proto":true},{"addr":"0x7ec380","include_decompile":true,"include_proto":true},{"addr":"0x7ec390","include_decompile":true,"include_proto":true},{"addr":"0x7ec400","include_decompile":true,"include_proto":true},{"addr":"0x7ec410","include_decompile":true,"include_proto":true},{"addr":"0x7ec420","include_decompile":true,"include_proto":true},{"addr":"0x7ec6b0","include_decompile":true,"include_proto":true},{"addr":"0x7ec6f0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0201', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0201: empty response'); return; }
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
      console.log('Batch 0201: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0201 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0201 conn error:', e.message));
req.write(body);
req.end();
