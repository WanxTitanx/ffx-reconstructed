
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6cca80","include_decompile":true,"include_proto":true},{"addr":"0x6ccab0","include_decompile":true,"include_proto":true},{"addr":"0x6ccbe0","include_decompile":true,"include_proto":true},{"addr":"0x6ccbf0","include_decompile":true,"include_proto":true},{"addr":"0x6ccc00","include_decompile":true,"include_proto":true},{"addr":"0x6cce30","include_decompile":true,"include_proto":true},{"addr":"0x6cce40","include_decompile":true,"include_proto":true},{"addr":"0x6ce1f0","include_decompile":true,"include_proto":true},{"addr":"0x6ce230","include_decompile":true,"include_proto":true},{"addr":"0x6ce260","include_decompile":true,"include_proto":true},{"addr":"0x6ce510","include_decompile":true,"include_proto":true},{"addr":"0x6ce620","include_decompile":true,"include_proto":true},{"addr":"0x6ce700","include_decompile":true,"include_proto":true},{"addr":"0x6ce820","include_decompile":true,"include_proto":true},{"addr":"0x6ce990","include_decompile":true,"include_proto":true},{"addr":"0x6ceb00","include_decompile":true,"include_proto":true},{"addr":"0x6cebb0","include_decompile":true,"include_proto":true},{"addr":"0x6cebd0","include_decompile":true,"include_proto":true},{"addr":"0x6cec30","include_decompile":true,"include_proto":true},{"addr":"0x6cec40","include_decompile":true,"include_proto":true},{"addr":"0x6ced00","include_decompile":true,"include_proto":true},{"addr":"0x6d0200","include_decompile":true,"include_proto":true},{"addr":"0x6d1420","include_decompile":true,"include_proto":true},{"addr":"0x6d1660","include_decompile":true,"include_proto":true},{"addr":"0x6d1900","include_decompile":true,"include_proto":true},{"addr":"0x6d1930","include_decompile":true,"include_proto":true},{"addr":"0x6d19e0","include_decompile":true,"include_proto":true},{"addr":"0x6d1bf0","include_decompile":true,"include_proto":true},{"addr":"0x6d1c70","include_decompile":true,"include_proto":true},{"addr":"0x6d2410","include_decompile":true,"include_proto":true},{"addr":"0x6d2420","include_decompile":true,"include_proto":true},{"addr":"0x6d2430","include_decompile":true,"include_proto":true},{"addr":"0x6d24b0","include_decompile":true,"include_proto":true},{"addr":"0x6d24c0","include_decompile":true,"include_proto":true},{"addr":"0x6d24d0","include_decompile":true,"include_proto":true},{"addr":"0x6d2500","include_decompile":true,"include_proto":true},{"addr":"0x6d2640","include_decompile":true,"include_proto":true},{"addr":"0x6d2650","include_decompile":true,"include_proto":true},{"addr":"0x6d2660","include_decompile":true,"include_proto":true},{"addr":"0x6d2800","include_decompile":true,"include_proto":true},{"addr":"0x6d2890","include_decompile":true,"include_proto":true},{"addr":"0x6d2910","include_decompile":true,"include_proto":true},{"addr":"0x6d2c80","include_decompile":true,"include_proto":true},{"addr":"0x6d2d40","include_decompile":true,"include_proto":true},{"addr":"0x6d2f20","include_decompile":true,"include_proto":true},{"addr":"0x6d3130","include_decompile":true,"include_proto":true},{"addr":"0x6d3690","include_decompile":true,"include_proto":true},{"addr":"0x6d3730","include_decompile":true,"include_proto":true},{"addr":"0x6d3780","include_decompile":true,"include_proto":true},{"addr":"0x6d3f30","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0101', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0101: empty response'); return; }
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
      console.log('Batch 0101: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0101 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0101 conn error:', e.message));
req.write(body);
req.end();
