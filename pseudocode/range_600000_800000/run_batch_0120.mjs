
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6fa990","include_decompile":true,"include_proto":true},{"addr":"0x6fa9a0","include_decompile":true,"include_proto":true},{"addr":"0x6fa9b0","include_decompile":true,"include_proto":true},{"addr":"0x6fab10","include_decompile":true,"include_proto":true},{"addr":"0x6fac80","include_decompile":true,"include_proto":true},{"addr":"0x6fadd0","include_decompile":true,"include_proto":true},{"addr":"0x6fae70","include_decompile":true,"include_proto":true},{"addr":"0x6fafc0","include_decompile":true,"include_proto":true},{"addr":"0x6fb070","include_decompile":true,"include_proto":true},{"addr":"0x6fb160","include_decompile":true,"include_proto":true},{"addr":"0x6fb210","include_decompile":true,"include_proto":true},{"addr":"0x6fb240","include_decompile":true,"include_proto":true},{"addr":"0x6fb2f0","include_decompile":true,"include_proto":true},{"addr":"0x6fb400","include_decompile":true,"include_proto":true},{"addr":"0x6fb460","include_decompile":true,"include_proto":true},{"addr":"0x6fb4f0","include_decompile":true,"include_proto":true},{"addr":"0x6fb580","include_decompile":true,"include_proto":true},{"addr":"0x6fb630","include_decompile":true,"include_proto":true},{"addr":"0x6fb6b0","include_decompile":true,"include_proto":true},{"addr":"0x6fb720","include_decompile":true,"include_proto":true},{"addr":"0x6fb7a0","include_decompile":true,"include_proto":true},{"addr":"0x6fb850","include_decompile":true,"include_proto":true},{"addr":"0x6fb900","include_decompile":true,"include_proto":true},{"addr":"0x6fb990","include_decompile":true,"include_proto":true},{"addr":"0x6fb9f0","include_decompile":true,"include_proto":true},{"addr":"0x6fba90","include_decompile":true,"include_proto":true},{"addr":"0x6fbb70","include_decompile":true,"include_proto":true},{"addr":"0x6fbbe0","include_decompile":true,"include_proto":true},{"addr":"0x6fbce0","include_decompile":true,"include_proto":true},{"addr":"0x6fbcf0","include_decompile":true,"include_proto":true},{"addr":"0x6fbdb0","include_decompile":true,"include_proto":true},{"addr":"0x6fbde0","include_decompile":true,"include_proto":true},{"addr":"0x6fbe90","include_decompile":true,"include_proto":true},{"addr":"0x6fbea0","include_decompile":true,"include_proto":true},{"addr":"0x6fbfc0","include_decompile":true,"include_proto":true},{"addr":"0x6fc0c0","include_decompile":true,"include_proto":true},{"addr":"0x6fc0d0","include_decompile":true,"include_proto":true},{"addr":"0x6fc180","include_decompile":true,"include_proto":true},{"addr":"0x6fc290","include_decompile":true,"include_proto":true},{"addr":"0x6fc470","include_decompile":true,"include_proto":true},{"addr":"0x6fc4d0","include_decompile":true,"include_proto":true},{"addr":"0x6fc890","include_decompile":true,"include_proto":true},{"addr":"0x6fca50","include_decompile":true,"include_proto":true},{"addr":"0x6fca90","include_decompile":true,"include_proto":true},{"addr":"0x6fcb30","include_decompile":true,"include_proto":true},{"addr":"0x6fcbd0","include_decompile":true,"include_proto":true},{"addr":"0x6fcca0","include_decompile":true,"include_proto":true},{"addr":"0x6fcd70","include_decompile":true,"include_proto":true},{"addr":"0x6fcd80","include_decompile":true,"include_proto":true},{"addr":"0x6fee00","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0120', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0120: empty response'); return; }
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
      console.log('Batch 0120: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0120 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0120 conn error:', e.message));
req.write(body);
req.end();
