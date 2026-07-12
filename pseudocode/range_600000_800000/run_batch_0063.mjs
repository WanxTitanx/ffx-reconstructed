
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x673340","include_decompile":true,"include_proto":true},{"addr":"0x673380","include_decompile":true,"include_proto":true},{"addr":"0x6733c0","include_decompile":true,"include_proto":true},{"addr":"0x673430","include_decompile":true,"include_proto":true},{"addr":"0x673440","include_decompile":true,"include_proto":true},{"addr":"0x673540","include_decompile":true,"include_proto":true},{"addr":"0x673570","include_decompile":true,"include_proto":true},{"addr":"0x6736a0","include_decompile":true,"include_proto":true},{"addr":"0x673790","include_decompile":true,"include_proto":true},{"addr":"0x6737b0","include_decompile":true,"include_proto":true},{"addr":"0x6737d0","include_decompile":true,"include_proto":true},{"addr":"0x6737e0","include_decompile":true,"include_proto":true},{"addr":"0x6737f0","include_decompile":true,"include_proto":true},{"addr":"0x673820","include_decompile":true,"include_proto":true},{"addr":"0x673850","include_decompile":true,"include_proto":true},{"addr":"0x673880","include_decompile":true,"include_proto":true},{"addr":"0x6738b0","include_decompile":true,"include_proto":true},{"addr":"0x6738d0","include_decompile":true,"include_proto":true},{"addr":"0x673950","include_decompile":true,"include_proto":true},{"addr":"0x673a30","include_decompile":true,"include_proto":true},{"addr":"0x673a40","include_decompile":true,"include_proto":true},{"addr":"0x673b70","include_decompile":true,"include_proto":true},{"addr":"0x673b90","include_decompile":true,"include_proto":true},{"addr":"0x673c10","include_decompile":true,"include_proto":true},{"addr":"0x673c40","include_decompile":true,"include_proto":true},{"addr":"0x673c50","include_decompile":true,"include_proto":true},{"addr":"0x673c60","include_decompile":true,"include_proto":true},{"addr":"0x673c80","include_decompile":true,"include_proto":true},{"addr":"0x673c90","include_decompile":true,"include_proto":true},{"addr":"0x673cb0","include_decompile":true,"include_proto":true},{"addr":"0x673cc0","include_decompile":true,"include_proto":true},{"addr":"0x673ce0","include_decompile":true,"include_proto":true},{"addr":"0x673d20","include_decompile":true,"include_proto":true},{"addr":"0x673d50","include_decompile":true,"include_proto":true},{"addr":"0x673dd0","include_decompile":true,"include_proto":true},{"addr":"0x673de0","include_decompile":true,"include_proto":true},{"addr":"0x673df0","include_decompile":true,"include_proto":true},{"addr":"0x673e90","include_decompile":true,"include_proto":true},{"addr":"0x673fc0","include_decompile":true,"include_proto":true},{"addr":"0x674040","include_decompile":true,"include_proto":true},{"addr":"0x674140","include_decompile":true,"include_proto":true},{"addr":"0x674150","include_decompile":true,"include_proto":true},{"addr":"0x674170","include_decompile":true,"include_proto":true},{"addr":"0x6741c0","include_decompile":true,"include_proto":true},{"addr":"0x6741f0","include_decompile":true,"include_proto":true},{"addr":"0x674220","include_decompile":true,"include_proto":true},{"addr":"0x674250","include_decompile":true,"include_proto":true},{"addr":"0x674280","include_decompile":true,"include_proto":true},{"addr":"0x6742a0","include_decompile":true,"include_proto":true},{"addr":"0x674380","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0063', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0063: empty response'); return; }
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
      console.log('Batch 0063: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0063 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0063 conn error:', e.message));
req.write(body);
req.end();
