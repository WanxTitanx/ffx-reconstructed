
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x603220","include_decompile":true,"include_proto":true},{"addr":"0x603410","include_decompile":true,"include_proto":true},{"addr":"0x603420","include_decompile":true,"include_proto":true},{"addr":"0x603440","include_decompile":true,"include_proto":true},{"addr":"0x6035c0","include_decompile":true,"include_proto":true},{"addr":"0x603600","include_decompile":true,"include_proto":true},{"addr":"0x603630","include_decompile":true,"include_proto":true},{"addr":"0x603790","include_decompile":true,"include_proto":true},{"addr":"0x603870","include_decompile":true,"include_proto":true},{"addr":"0x603940","include_decompile":true,"include_proto":true},{"addr":"0x603950","include_decompile":true,"include_proto":true},{"addr":"0x603c20","include_decompile":true,"include_proto":true},{"addr":"0x603c50","include_decompile":true,"include_proto":true},{"addr":"0x603d90","include_decompile":true,"include_proto":true},{"addr":"0x603f80","include_decompile":true,"include_proto":true},{"addr":"0x604010","include_decompile":true,"include_proto":true},{"addr":"0x604060","include_decompile":true,"include_proto":true},{"addr":"0x604090","include_decompile":true,"include_proto":true},{"addr":"0x6041e0","include_decompile":true,"include_proto":true},{"addr":"0x6043a0","include_decompile":true,"include_proto":true},{"addr":"0x604440","include_decompile":true,"include_proto":true},{"addr":"0x604450","include_decompile":true,"include_proto":true},{"addr":"0x604460","include_decompile":true,"include_proto":true},{"addr":"0x604470","include_decompile":true,"include_proto":true},{"addr":"0x604550","include_decompile":true,"include_proto":true},{"addr":"0x604750","include_decompile":true,"include_proto":true},{"addr":"0x604780","include_decompile":true,"include_proto":true},{"addr":"0x6047f0","include_decompile":true,"include_proto":true},{"addr":"0x604860","include_decompile":true,"include_proto":true},{"addr":"0x6048d0","include_decompile":true,"include_proto":true},{"addr":"0x604900","include_decompile":true,"include_proto":true},{"addr":"0x604970","include_decompile":true,"include_proto":true},{"addr":"0x6049e0","include_decompile":true,"include_proto":true},{"addr":"0x604a50","include_decompile":true,"include_proto":true},{"addr":"0x604ac0","include_decompile":true,"include_proto":true},{"addr":"0x604af0","include_decompile":true,"include_proto":true},{"addr":"0x604b20","include_decompile":true,"include_proto":true},{"addr":"0x604b50","include_decompile":true,"include_proto":true},{"addr":"0x604bc0","include_decompile":true,"include_proto":true},{"addr":"0x604c30","include_decompile":true,"include_proto":true},{"addr":"0x604ca0","include_decompile":true,"include_proto":true},{"addr":"0x604d10","include_decompile":true,"include_proto":true},{"addr":"0x604d80","include_decompile":true,"include_proto":true},{"addr":"0x604df0","include_decompile":true,"include_proto":true},{"addr":"0x604e20","include_decompile":true,"include_proto":true},{"addr":"0x604e90","include_decompile":true,"include_proto":true},{"addr":"0x604f00","include_decompile":true,"include_proto":true},{"addr":"0x604f70","include_decompile":true,"include_proto":true},{"addr":"0x604fa0","include_decompile":true,"include_proto":true},{"addr":"0x605010","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0002', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0002: empty response'); return; }
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
      console.log('Batch 0002: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0002 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0002 conn error:', e.message));
req.write(body);
req.end();
