
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6eca10","include_decompile":true,"include_proto":true},{"addr":"0x6ecc70","include_decompile":true,"include_proto":true},{"addr":"0x6ecd20","include_decompile":true,"include_proto":true},{"addr":"0x6ecd70","include_decompile":true,"include_proto":true},{"addr":"0x6ecd80","include_decompile":true,"include_proto":true},{"addr":"0x6ecfa0","include_decompile":true,"include_proto":true},{"addr":"0x6ed350","include_decompile":true,"include_proto":true},{"addr":"0x6ed370","include_decompile":true,"include_proto":true},{"addr":"0x6ed390","include_decompile":true,"include_proto":true},{"addr":"0x6ed3b0","include_decompile":true,"include_proto":true},{"addr":"0x6ed3d0","include_decompile":true,"include_proto":true},{"addr":"0x6ed420","include_decompile":true,"include_proto":true},{"addr":"0x6ed4a0","include_decompile":true,"include_proto":true},{"addr":"0x6ed4b0","include_decompile":true,"include_proto":true},{"addr":"0x6ed4e0","include_decompile":true,"include_proto":true},{"addr":"0x6ed560","include_decompile":true,"include_proto":true},{"addr":"0x6ed590","include_decompile":true,"include_proto":true},{"addr":"0x6ed5a0","include_decompile":true,"include_proto":true},{"addr":"0x6ed630","include_decompile":true,"include_proto":true},{"addr":"0x6ed700","include_decompile":true,"include_proto":true},{"addr":"0x6ed710","include_decompile":true,"include_proto":true},{"addr":"0x6ed760","include_decompile":true,"include_proto":true},{"addr":"0x6ed830","include_decompile":true,"include_proto":true},{"addr":"0x6ed860","include_decompile":true,"include_proto":true},{"addr":"0x6ed8c0","include_decompile":true,"include_proto":true},{"addr":"0x6ed900","include_decompile":true,"include_proto":true},{"addr":"0x6ed940","include_decompile":true,"include_proto":true},{"addr":"0x6ed980","include_decompile":true,"include_proto":true},{"addr":"0x6eda30","include_decompile":true,"include_proto":true},{"addr":"0x6eda80","include_decompile":true,"include_proto":true},{"addr":"0x6edad0","include_decompile":true,"include_proto":true},{"addr":"0x6edae0","include_decompile":true,"include_proto":true},{"addr":"0x6edaf0","include_decompile":true,"include_proto":true},{"addr":"0x6edb20","include_decompile":true,"include_proto":true},{"addr":"0x6ee3b0","include_decompile":true,"include_proto":true},{"addr":"0x6ee6b0","include_decompile":true,"include_proto":true},{"addr":"0x6eef80","include_decompile":true,"include_proto":true},{"addr":"0x6ef410","include_decompile":true,"include_proto":true},{"addr":"0x6ef450","include_decompile":true,"include_proto":true},{"addr":"0x6ef460","include_decompile":true,"include_proto":true},{"addr":"0x6ef770","include_decompile":true,"include_proto":true},{"addr":"0x6ef830","include_decompile":true,"include_proto":true},{"addr":"0x6efe50","include_decompile":true,"include_proto":true},{"addr":"0x6efff0","include_decompile":true,"include_proto":true},{"addr":"0x6f01b0","include_decompile":true,"include_proto":true},{"addr":"0x6f0310","include_decompile":true,"include_proto":true},{"addr":"0x6f03d0","include_decompile":true,"include_proto":true},{"addr":"0x6f0470","include_decompile":true,"include_proto":true},{"addr":"0x6f0650","include_decompile":true,"include_proto":true},{"addr":"0x6f07b0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0113', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0113: empty response'); return; }
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
      console.log('Batch 0113: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0113 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0113 conn error:', e.message));
req.write(body);
req.end();
