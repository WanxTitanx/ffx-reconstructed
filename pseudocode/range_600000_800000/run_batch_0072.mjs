
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x67e000","include_decompile":true,"include_proto":true},{"addr":"0x67e4b0","include_decompile":true,"include_proto":true},{"addr":"0x67e550","include_decompile":true,"include_proto":true},{"addr":"0x67e640","include_decompile":true,"include_proto":true},{"addr":"0x67e670","include_decompile":true,"include_proto":true},{"addr":"0x67e680","include_decompile":true,"include_proto":true},{"addr":"0x67e690","include_decompile":true,"include_proto":true},{"addr":"0x67e840","include_decompile":true,"include_proto":true},{"addr":"0x67e860","include_decompile":true,"include_proto":true},{"addr":"0x67e990","include_decompile":true,"include_proto":true},{"addr":"0x67eaf0","include_decompile":true,"include_proto":true},{"addr":"0x67eb70","include_decompile":true,"include_proto":true},{"addr":"0x67ed60","include_decompile":true,"include_proto":true},{"addr":"0x67ee90","include_decompile":true,"include_proto":true},{"addr":"0x67ef60","include_decompile":true,"include_proto":true},{"addr":"0x67eff0","include_decompile":true,"include_proto":true},{"addr":"0x67f020","include_decompile":true,"include_proto":true},{"addr":"0x67f150","include_decompile":true,"include_proto":true},{"addr":"0x67f1e0","include_decompile":true,"include_proto":true},{"addr":"0x67f3e0","include_decompile":true,"include_proto":true},{"addr":"0x67f570","include_decompile":true,"include_proto":true},{"addr":"0x67f590","include_decompile":true,"include_proto":true},{"addr":"0x67f7c0","include_decompile":true,"include_proto":true},{"addr":"0x67f9e0","include_decompile":true,"include_proto":true},{"addr":"0x67fad0","include_decompile":true,"include_proto":true},{"addr":"0x67fb50","include_decompile":true,"include_proto":true},{"addr":"0x67fbd0","include_decompile":true,"include_proto":true},{"addr":"0x67fcc0","include_decompile":true,"include_proto":true},{"addr":"0x67fcd0","include_decompile":true,"include_proto":true},{"addr":"0x67fce0","include_decompile":true,"include_proto":true},{"addr":"0x67fd60","include_decompile":true,"include_proto":true},{"addr":"0x67fd70","include_decompile":true,"include_proto":true},{"addr":"0x67fd80","include_decompile":true,"include_proto":true},{"addr":"0x67fd90","include_decompile":true,"include_proto":true},{"addr":"0x67fda0","include_decompile":true,"include_proto":true},{"addr":"0x67fdb0","include_decompile":true,"include_proto":true},{"addr":"0x67fdc0","include_decompile":true,"include_proto":true},{"addr":"0x67fdd0","include_decompile":true,"include_proto":true},{"addr":"0x67ff50","include_decompile":true,"include_proto":true},{"addr":"0x680020","include_decompile":true,"include_proto":true},{"addr":"0x6800c0","include_decompile":true,"include_proto":true},{"addr":"0x6801b0","include_decompile":true,"include_proto":true},{"addr":"0x6801e0","include_decompile":true,"include_proto":true},{"addr":"0x6804d0","include_decompile":true,"include_proto":true},{"addr":"0x680550","include_decompile":true,"include_proto":true},{"addr":"0x6805c0","include_decompile":true,"include_proto":true},{"addr":"0x680640","include_decompile":true,"include_proto":true},{"addr":"0x680740","include_decompile":true,"include_proto":true},{"addr":"0x680750","include_decompile":true,"include_proto":true},{"addr":"0x680760","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0072', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0072: empty response'); return; }
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
      console.log('Batch 0072: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0072 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0072 conn error:', e.message));
req.write(body);
req.end();
