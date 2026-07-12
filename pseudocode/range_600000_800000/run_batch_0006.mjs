
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x60df40","include_decompile":true,"include_proto":true},{"addr":"0x60e0c0","include_decompile":true,"include_proto":true},{"addr":"0x60e110","include_decompile":true,"include_proto":true},{"addr":"0x60e120","include_decompile":true,"include_proto":true},{"addr":"0x60e140","include_decompile":true,"include_proto":true},{"addr":"0x60e180","include_decompile":true,"include_proto":true},{"addr":"0x60e320","include_decompile":true,"include_proto":true},{"addr":"0x60e3e0","include_decompile":true,"include_proto":true},{"addr":"0x60e460","include_decompile":true,"include_proto":true},{"addr":"0x60e550","include_decompile":true,"include_proto":true},{"addr":"0x60e7c0","include_decompile":true,"include_proto":true},{"addr":"0x60e8f0","include_decompile":true,"include_proto":true},{"addr":"0x60e990","include_decompile":true,"include_proto":true},{"addr":"0x60ea50","include_decompile":true,"include_proto":true},{"addr":"0x60ea60","include_decompile":true,"include_proto":true},{"addr":"0x60ea90","include_decompile":true,"include_proto":true},{"addr":"0x60eaa0","include_decompile":true,"include_proto":true},{"addr":"0x60eb70","include_decompile":true,"include_proto":true},{"addr":"0x60ec10","include_decompile":true,"include_proto":true},{"addr":"0x60ecc0","include_decompile":true,"include_proto":true},{"addr":"0x60ece0","include_decompile":true,"include_proto":true},{"addr":"0x60ed80","include_decompile":true,"include_proto":true},{"addr":"0x60edf0","include_decompile":true,"include_proto":true},{"addr":"0x60ee30","include_decompile":true,"include_proto":true},{"addr":"0x60ef00","include_decompile":true,"include_proto":true},{"addr":"0x60ef10","include_decompile":true,"include_proto":true},{"addr":"0x60ef30","include_decompile":true,"include_proto":true},{"addr":"0x60efa0","include_decompile":true,"include_proto":true},{"addr":"0x60efc0","include_decompile":true,"include_proto":true},{"addr":"0x60efd0","include_decompile":true,"include_proto":true},{"addr":"0x60f000","include_decompile":true,"include_proto":true},{"addr":"0x60f210","include_decompile":true,"include_proto":true},{"addr":"0x60f280","include_decompile":true,"include_proto":true},{"addr":"0x60f2c0","include_decompile":true,"include_proto":true},{"addr":"0x60f300","include_decompile":true,"include_proto":true},{"addr":"0x60f600","include_decompile":true,"include_proto":true},{"addr":"0x60f6d0","include_decompile":true,"include_proto":true},{"addr":"0x60f740","include_decompile":true,"include_proto":true},{"addr":"0x60fa60","include_decompile":true,"include_proto":true},{"addr":"0x60faf0","include_decompile":true,"include_proto":true},{"addr":"0x60fb30","include_decompile":true,"include_proto":true},{"addr":"0x60fba0","include_decompile":true,"include_proto":true},{"addr":"0x60fcc0","include_decompile":true,"include_proto":true},{"addr":"0x60fe60","include_decompile":true,"include_proto":true},{"addr":"0x60ff90","include_decompile":true,"include_proto":true},{"addr":"0x60fff0","include_decompile":true,"include_proto":true},{"addr":"0x610000","include_decompile":true,"include_proto":true},{"addr":"0x6100a0","include_decompile":true,"include_proto":true},{"addr":"0x6100c0","include_decompile":true,"include_proto":true},{"addr":"0x610130","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0006', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0006: empty response'); return; }
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
      console.log('Batch 0006: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0006 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0006 conn error:', e.message));
req.write(body);
req.end();
