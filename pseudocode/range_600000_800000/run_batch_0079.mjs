
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6927b0","include_decompile":true,"include_proto":true},{"addr":"0x692810","include_decompile":true,"include_proto":true},{"addr":"0x692870","include_decompile":true,"include_proto":true},{"addr":"0x6928d0","include_decompile":true,"include_proto":true},{"addr":"0x692930","include_decompile":true,"include_proto":true},{"addr":"0x692940","include_decompile":true,"include_proto":true},{"addr":"0x692950","include_decompile":true,"include_proto":true},{"addr":"0x692a80","include_decompile":true,"include_proto":true},{"addr":"0x692b90","include_decompile":true,"include_proto":true},{"addr":"0x692bc0","include_decompile":true,"include_proto":true},{"addr":"0x692c40","include_decompile":true,"include_proto":true},{"addr":"0x692cc0","include_decompile":true,"include_proto":true},{"addr":"0x692cf0","include_decompile":true,"include_proto":true},{"addr":"0x692d10","include_decompile":true,"include_proto":true},{"addr":"0x692d20","include_decompile":true,"include_proto":true},{"addr":"0x692d30","include_decompile":true,"include_proto":true},{"addr":"0x692d40","include_decompile":true,"include_proto":true},{"addr":"0x692d70","include_decompile":true,"include_proto":true},{"addr":"0x692fc0","include_decompile":true,"include_proto":true},{"addr":"0x6932d0","include_decompile":true,"include_proto":true},{"addr":"0x693660","include_decompile":true,"include_proto":true},{"addr":"0x693670","include_decompile":true,"include_proto":true},{"addr":"0x693720","include_decompile":true,"include_proto":true},{"addr":"0x693800","include_decompile":true,"include_proto":true},{"addr":"0x693810","include_decompile":true,"include_proto":true},{"addr":"0x693820","include_decompile":true,"include_proto":true},{"addr":"0x693830","include_decompile":true,"include_proto":true},{"addr":"0x693840","include_decompile":true,"include_proto":true},{"addr":"0x6939f0","include_decompile":true,"include_proto":true},{"addr":"0x693a00","include_decompile":true,"include_proto":true},{"addr":"0x693d10","include_decompile":true,"include_proto":true},{"addr":"0x693d70","include_decompile":true,"include_proto":true},{"addr":"0x693d80","include_decompile":true,"include_proto":true},{"addr":"0x693e50","include_decompile":true,"include_proto":true},{"addr":"0x693ea0","include_decompile":true,"include_proto":true},{"addr":"0x694d50","include_decompile":true,"include_proto":true},{"addr":"0x694d90","include_decompile":true,"include_proto":true},{"addr":"0x695040","include_decompile":true,"include_proto":true},{"addr":"0x6954d0","include_decompile":true,"include_proto":true},{"addr":"0x695570","include_decompile":true,"include_proto":true},{"addr":"0x695800","include_decompile":true,"include_proto":true},{"addr":"0x695870","include_decompile":true,"include_proto":true},{"addr":"0x6958c0","include_decompile":true,"include_proto":true},{"addr":"0x695b00","include_decompile":true,"include_proto":true},{"addr":"0x695ce0","include_decompile":true,"include_proto":true},{"addr":"0x696c30","include_decompile":true,"include_proto":true},{"addr":"0x6975d0","include_decompile":true,"include_proto":true},{"addr":"0x6977b0","include_decompile":true,"include_proto":true},{"addr":"0x697f50","include_decompile":true,"include_proto":true},{"addr":"0x698060","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0079', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0079: empty response'); return; }
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
      console.log('Batch 0079: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0079 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0079 conn error:', e.message));
req.write(body);
req.end();
