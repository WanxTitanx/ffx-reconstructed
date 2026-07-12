
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x623dd0","include_decompile":true,"include_proto":true},{"addr":"0x623de0","include_decompile":true,"include_proto":true},{"addr":"0x623df0","include_decompile":true,"include_proto":true},{"addr":"0x623e00","include_decompile":true,"include_proto":true},{"addr":"0x623e10","include_decompile":true,"include_proto":true},{"addr":"0x623e20","include_decompile":true,"include_proto":true},{"addr":"0x623e30","include_decompile":true,"include_proto":true},{"addr":"0x623e40","include_decompile":true,"include_proto":true},{"addr":"0x623e50","include_decompile":true,"include_proto":true},{"addr":"0x623eb0","include_decompile":true,"include_proto":true},{"addr":"0x623ec0","include_decompile":true,"include_proto":true},{"addr":"0x623ee0","include_decompile":true,"include_proto":true},{"addr":"0x623ef0","include_decompile":true,"include_proto":true},{"addr":"0x623f00","include_decompile":true,"include_proto":true},{"addr":"0x623f10","include_decompile":true,"include_proto":true},{"addr":"0x623f40","include_decompile":true,"include_proto":true},{"addr":"0x623f50","include_decompile":true,"include_proto":true},{"addr":"0x623f60","include_decompile":true,"include_proto":true},{"addr":"0x623fa0","include_decompile":true,"include_proto":true},{"addr":"0x623fb0","include_decompile":true,"include_proto":true},{"addr":"0x623fc0","include_decompile":true,"include_proto":true},{"addr":"0x623fd0","include_decompile":true,"include_proto":true},{"addr":"0x624030","include_decompile":true,"include_proto":true},{"addr":"0x624050","include_decompile":true,"include_proto":true},{"addr":"0x624060","include_decompile":true,"include_proto":true},{"addr":"0x624070","include_decompile":true,"include_proto":true},{"addr":"0x624080","include_decompile":true,"include_proto":true},{"addr":"0x624090","include_decompile":true,"include_proto":true},{"addr":"0x6240a0","include_decompile":true,"include_proto":true},{"addr":"0x6240b0","include_decompile":true,"include_proto":true},{"addr":"0x6240c0","include_decompile":true,"include_proto":true},{"addr":"0x6240d0","include_decompile":true,"include_proto":true},{"addr":"0x6240e0","include_decompile":true,"include_proto":true},{"addr":"0x6240f0","include_decompile":true,"include_proto":true},{"addr":"0x624150","include_decompile":true,"include_proto":true},{"addr":"0x624160","include_decompile":true,"include_proto":true},{"addr":"0x6241e0","include_decompile":true,"include_proto":true},{"addr":"0x6242a0","include_decompile":true,"include_proto":true},{"addr":"0x624500","include_decompile":true,"include_proto":true},{"addr":"0x624510","include_decompile":true,"include_proto":true},{"addr":"0x6245d0","include_decompile":true,"include_proto":true},{"addr":"0x6246b0","include_decompile":true,"include_proto":true},{"addr":"0x6249d0","include_decompile":true,"include_proto":true},{"addr":"0x624a10","include_decompile":true,"include_proto":true},{"addr":"0x624a50","include_decompile":true,"include_proto":true},{"addr":"0x624ac0","include_decompile":true,"include_proto":true},{"addr":"0x624ad0","include_decompile":true,"include_proto":true},{"addr":"0x624b70","include_decompile":true,"include_proto":true},{"addr":"0x624e40","include_decompile":true,"include_proto":true},{"addr":"0x624ef0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0021', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0021: empty response'); return; }
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
      console.log('Batch 0021: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0021 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0021 conn error:', e.message));
req.write(body);
req.end();
