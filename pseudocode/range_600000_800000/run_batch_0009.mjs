
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6133e0","include_decompile":true,"include_proto":true},{"addr":"0x6133f0","include_decompile":true,"include_proto":true},{"addr":"0x613400","include_decompile":true,"include_proto":true},{"addr":"0x613470","include_decompile":true,"include_proto":true},{"addr":"0x613480","include_decompile":true,"include_proto":true},{"addr":"0x613490","include_decompile":true,"include_proto":true},{"addr":"0x6134a0","include_decompile":true,"include_proto":true},{"addr":"0x6134b0","include_decompile":true,"include_proto":true},{"addr":"0x6134c0","include_decompile":true,"include_proto":true},{"addr":"0x6134d0","include_decompile":true,"include_proto":true},{"addr":"0x613550","include_decompile":true,"include_proto":true},{"addr":"0x613640","include_decompile":true,"include_proto":true},{"addr":"0x613760","include_decompile":true,"include_proto":true},{"addr":"0x613870","include_decompile":true,"include_proto":true},{"addr":"0x613880","include_decompile":true,"include_proto":true},{"addr":"0x613890","include_decompile":true,"include_proto":true},{"addr":"0x6138a0","include_decompile":true,"include_proto":true},{"addr":"0x6138c0","include_decompile":true,"include_proto":true},{"addr":"0x6139c0","include_decompile":true,"include_proto":true},{"addr":"0x613b20","include_decompile":true,"include_proto":true},{"addr":"0x613c30","include_decompile":true,"include_proto":true},{"addr":"0x613cb0","include_decompile":true,"include_proto":true},{"addr":"0x613d30","include_decompile":true,"include_proto":true},{"addr":"0x613e40","include_decompile":true,"include_proto":true},{"addr":"0x613f10","include_decompile":true,"include_proto":true},{"addr":"0x613f50","include_decompile":true,"include_proto":true},{"addr":"0x613f90","include_decompile":true,"include_proto":true},{"addr":"0x613fd0","include_decompile":true,"include_proto":true},{"addr":"0x614040","include_decompile":true,"include_proto":true},{"addr":"0x614070","include_decompile":true,"include_proto":true},{"addr":"0x6140c0","include_decompile":true,"include_proto":true},{"addr":"0x614110","include_decompile":true,"include_proto":true},{"addr":"0x614120","include_decompile":true,"include_proto":true},{"addr":"0x614130","include_decompile":true,"include_proto":true},{"addr":"0x614170","include_decompile":true,"include_proto":true},{"addr":"0x614180","include_decompile":true,"include_proto":true},{"addr":"0x6141d0","include_decompile":true,"include_proto":true},{"addr":"0x614360","include_decompile":true,"include_proto":true},{"addr":"0x6143c0","include_decompile":true,"include_proto":true},{"addr":"0x6143d0","include_decompile":true,"include_proto":true},{"addr":"0x6143e0","include_decompile":true,"include_proto":true},{"addr":"0x6144b0","include_decompile":true,"include_proto":true},{"addr":"0x6144c0","include_decompile":true,"include_proto":true},{"addr":"0x6145d0","include_decompile":true,"include_proto":true},{"addr":"0x6146b0","include_decompile":true,"include_proto":true},{"addr":"0x6147d0","include_decompile":true,"include_proto":true},{"addr":"0x6148c0","include_decompile":true,"include_proto":true},{"addr":"0x6148d0","include_decompile":true,"include_proto":true},{"addr":"0x6148e0","include_decompile":true,"include_proto":true},{"addr":"0x614970","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0009', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0009: empty response'); return; }
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
      console.log('Batch 0009: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0009 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0009 conn error:', e.message));
req.write(body);
req.end();
