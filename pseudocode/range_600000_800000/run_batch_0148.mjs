
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x76de20","include_decompile":true,"include_proto":true},{"addr":"0x76df80","include_decompile":true,"include_proto":true},{"addr":"0x76dfa0","include_decompile":true,"include_proto":true},{"addr":"0x76dfc0","include_decompile":true,"include_proto":true},{"addr":"0x76e240","include_decompile":true,"include_proto":true},{"addr":"0x76e2d0","include_decompile":true,"include_proto":true},{"addr":"0x76e5c0","include_decompile":true,"include_proto":true},{"addr":"0x76e6f0","include_decompile":true,"include_proto":true},{"addr":"0x76e740","include_decompile":true,"include_proto":true},{"addr":"0x76e750","include_decompile":true,"include_proto":true},{"addr":"0x76e770","include_decompile":true,"include_proto":true},{"addr":"0x76e890","include_decompile":true,"include_proto":true},{"addr":"0x76e9a0","include_decompile":true,"include_proto":true},{"addr":"0x76ea20","include_decompile":true,"include_proto":true},{"addr":"0x76ea90","include_decompile":true,"include_proto":true},{"addr":"0x76eaa0","include_decompile":true,"include_proto":true},{"addr":"0x76eac0","include_decompile":true,"include_proto":true},{"addr":"0x76ead0","include_decompile":true,"include_proto":true},{"addr":"0x76eb00","include_decompile":true,"include_proto":true},{"addr":"0x76eb40","include_decompile":true,"include_proto":true},{"addr":"0x76eb50","include_decompile":true,"include_proto":true},{"addr":"0x76eb60","include_decompile":true,"include_proto":true},{"addr":"0x76eb70","include_decompile":true,"include_proto":true},{"addr":"0x76ebd0","include_decompile":true,"include_proto":true},{"addr":"0x76ebe0","include_decompile":true,"include_proto":true},{"addr":"0x76ebf0","include_decompile":true,"include_proto":true},{"addr":"0x76ec00","include_decompile":true,"include_proto":true},{"addr":"0x76ec10","include_decompile":true,"include_proto":true},{"addr":"0x76ec20","include_decompile":true,"include_proto":true},{"addr":"0x76ec30","include_decompile":true,"include_proto":true},{"addr":"0x76ec40","include_decompile":true,"include_proto":true},{"addr":"0x76ec50","include_decompile":true,"include_proto":true},{"addr":"0x76ec70","include_decompile":true,"include_proto":true},{"addr":"0x76ec90","include_decompile":true,"include_proto":true},{"addr":"0x76ecf0","include_decompile":true,"include_proto":true},{"addr":"0x76ed0e","include_decompile":true,"include_proto":true},{"addr":"0x76ed20","include_decompile":true,"include_proto":true},{"addr":"0x76ed30","include_decompile":true,"include_proto":true},{"addr":"0x76ed40","include_decompile":true,"include_proto":true},{"addr":"0x76ed50","include_decompile":true,"include_proto":true},{"addr":"0x76eda0","include_decompile":true,"include_proto":true},{"addr":"0x76edc0","include_decompile":true,"include_proto":true},{"addr":"0x76edd0","include_decompile":true,"include_proto":true},{"addr":"0x76ede0","include_decompile":true,"include_proto":true},{"addr":"0x76edf0","include_decompile":true,"include_proto":true},{"addr":"0x76ee20","include_decompile":true,"include_proto":true},{"addr":"0x76ee80","include_decompile":true,"include_proto":true},{"addr":"0x76ee90","include_decompile":true,"include_proto":true},{"addr":"0x76eea0","include_decompile":true,"include_proto":true},{"addr":"0x76eeb0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0148', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0148: empty response'); return; }
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
      console.log('Batch 0148: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0148 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0148 conn error:', e.message));
req.write(body);
req.end();
