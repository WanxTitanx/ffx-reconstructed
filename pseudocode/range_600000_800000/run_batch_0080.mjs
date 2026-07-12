
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6981a0","include_decompile":true,"include_proto":true},{"addr":"0x6981e0","include_decompile":true,"include_proto":true},{"addr":"0x698250","include_decompile":true,"include_proto":true},{"addr":"0x698520","include_decompile":true,"include_proto":true},{"addr":"0x698530","include_decompile":true,"include_proto":true},{"addr":"0x698540","include_decompile":true,"include_proto":true},{"addr":"0x6985c0","include_decompile":true,"include_proto":true},{"addr":"0x6985d0","include_decompile":true,"include_proto":true},{"addr":"0x6985e0","include_decompile":true,"include_proto":true},{"addr":"0x6985f0","include_decompile":true,"include_proto":true},{"addr":"0x698630","include_decompile":true,"include_proto":true},{"addr":"0x698690","include_decompile":true,"include_proto":true},{"addr":"0x6986f0","include_decompile":true,"include_proto":true},{"addr":"0x698710","include_decompile":true,"include_proto":true},{"addr":"0x698870","include_decompile":true,"include_proto":true},{"addr":"0x698890","include_decompile":true,"include_proto":true},{"addr":"0x698a40","include_decompile":true,"include_proto":true},{"addr":"0x698aa0","include_decompile":true,"include_proto":true},{"addr":"0x698b00","include_decompile":true,"include_proto":true},{"addr":"0x698b70","include_decompile":true,"include_proto":true},{"addr":"0x698bf0","include_decompile":true,"include_proto":true},{"addr":"0x699050","include_decompile":true,"include_proto":true},{"addr":"0x6990a0","include_decompile":true,"include_proto":true},{"addr":"0x6990b0","include_decompile":true,"include_proto":true},{"addr":"0x6990e0","include_decompile":true,"include_proto":true},{"addr":"0x6991c0","include_decompile":true,"include_proto":true},{"addr":"0x699330","include_decompile":true,"include_proto":true},{"addr":"0x699440","include_decompile":true,"include_proto":true},{"addr":"0x699480","include_decompile":true,"include_proto":true},{"addr":"0x6994f0","include_decompile":true,"include_proto":true},{"addr":"0x699510","include_decompile":true,"include_proto":true},{"addr":"0x699720","include_decompile":true,"include_proto":true},{"addr":"0x699840","include_decompile":true,"include_proto":true},{"addr":"0x699850","include_decompile":true,"include_proto":true},{"addr":"0x699860","include_decompile":true,"include_proto":true},{"addr":"0x699870","include_decompile":true,"include_proto":true},{"addr":"0x699880","include_decompile":true,"include_proto":true},{"addr":"0x6998a0","include_decompile":true,"include_proto":true},{"addr":"0x6998c0","include_decompile":true,"include_proto":true},{"addr":"0x6998e0","include_decompile":true,"include_proto":true},{"addr":"0x699900","include_decompile":true,"include_proto":true},{"addr":"0x699920","include_decompile":true,"include_proto":true},{"addr":"0x699940","include_decompile":true,"include_proto":true},{"addr":"0x699950","include_decompile":true,"include_proto":true},{"addr":"0x699960","include_decompile":true,"include_proto":true},{"addr":"0x699970","include_decompile":true,"include_proto":true},{"addr":"0x699980","include_decompile":true,"include_proto":true},{"addr":"0x699990","include_decompile":true,"include_proto":true},{"addr":"0x6999a0","include_decompile":true,"include_proto":true},{"addr":"0x6999b0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0080', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0080: empty response'); return; }
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
      console.log('Batch 0080: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0080 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0080 conn error:', e.message));
req.write(body);
req.end();
