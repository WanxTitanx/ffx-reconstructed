
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7594f0","include_decompile":true,"include_proto":true},{"addr":"0x7596d0","include_decompile":true,"include_proto":true},{"addr":"0x759710","include_decompile":true,"include_proto":true},{"addr":"0x759740","include_decompile":true,"include_proto":true},{"addr":"0x759890","include_decompile":true,"include_proto":true},{"addr":"0x7598a0","include_decompile":true,"include_proto":true},{"addr":"0x7598f0","include_decompile":true,"include_proto":true},{"addr":"0x759920","include_decompile":true,"include_proto":true},{"addr":"0x759970","include_decompile":true,"include_proto":true},{"addr":"0x759980","include_decompile":true,"include_proto":true},{"addr":"0x759a80","include_decompile":true,"include_proto":true},{"addr":"0x759aa0","include_decompile":true,"include_proto":true},{"addr":"0x759cb0","include_decompile":true,"include_proto":true},{"addr":"0x759ce0","include_decompile":true,"include_proto":true},{"addr":"0x759e60","include_decompile":true,"include_proto":true},{"addr":"0x759e70","include_decompile":true,"include_proto":true},{"addr":"0x75a000","include_decompile":true,"include_proto":true},{"addr":"0x75a020","include_decompile":true,"include_proto":true},{"addr":"0x75a0a0","include_decompile":true,"include_proto":true},{"addr":"0x75a0c0","include_decompile":true,"include_proto":true},{"addr":"0x75a0e0","include_decompile":true,"include_proto":true},{"addr":"0x75a1e0","include_decompile":true,"include_proto":true},{"addr":"0x75a230","include_decompile":true,"include_proto":true},{"addr":"0x75a280","include_decompile":true,"include_proto":true},{"addr":"0x75a340","include_decompile":true,"include_proto":true},{"addr":"0x75a3c0","include_decompile":true,"include_proto":true},{"addr":"0x75a460","include_decompile":true,"include_proto":true},{"addr":"0x75a490","include_decompile":true,"include_proto":true},{"addr":"0x75a590","include_decompile":true,"include_proto":true},{"addr":"0x75a5e0","include_decompile":true,"include_proto":true},{"addr":"0x75a630","include_decompile":true,"include_proto":true},{"addr":"0x75a700","include_decompile":true,"include_proto":true},{"addr":"0x75a790","include_decompile":true,"include_proto":true},{"addr":"0x75a830","include_decompile":true,"include_proto":true},{"addr":"0x75a850","include_decompile":true,"include_proto":true},{"addr":"0x75a960","include_decompile":true,"include_proto":true},{"addr":"0x75a9a0","include_decompile":true,"include_proto":true},{"addr":"0x75a9f0","include_decompile":true,"include_proto":true},{"addr":"0x75aad0","include_decompile":true,"include_proto":true},{"addr":"0x75aba0","include_decompile":true,"include_proto":true},{"addr":"0x75ac20","include_decompile":true,"include_proto":true},{"addr":"0x75ac40","include_decompile":true,"include_proto":true},{"addr":"0x75ad50","include_decompile":true,"include_proto":true},{"addr":"0x75ada0","include_decompile":true,"include_proto":true},{"addr":"0x75adf0","include_decompile":true,"include_proto":true},{"addr":"0x75aed0","include_decompile":true,"include_proto":true},{"addr":"0x75af80","include_decompile":true,"include_proto":true},{"addr":"0x75b020","include_decompile":true,"include_proto":true},{"addr":"0x75b050","include_decompile":true,"include_proto":true},{"addr":"0x75b070","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0142', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0142: empty response'); return; }
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
      console.log('Batch 0142: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0142 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0142 conn error:', e.message));
req.write(body);
req.end();
