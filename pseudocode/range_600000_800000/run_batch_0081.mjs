
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6999c0","include_decompile":true,"include_proto":true},{"addr":"0x6999d0","include_decompile":true,"include_proto":true},{"addr":"0x6999e0","include_decompile":true,"include_proto":true},{"addr":"0x6999f0","include_decompile":true,"include_proto":true},{"addr":"0x699a00","include_decompile":true,"include_proto":true},{"addr":"0x699a90","include_decompile":true,"include_proto":true},{"addr":"0x699aa0","include_decompile":true,"include_proto":true},{"addr":"0x699ab0","include_decompile":true,"include_proto":true},{"addr":"0x699b40","include_decompile":true,"include_proto":true},{"addr":"0x699b50","include_decompile":true,"include_proto":true},{"addr":"0x699b60","include_decompile":true,"include_proto":true},{"addr":"0x699b70","include_decompile":true,"include_proto":true},{"addr":"0x699b80","include_decompile":true,"include_proto":true},{"addr":"0x699b90","include_decompile":true,"include_proto":true},{"addr":"0x699ba0","include_decompile":true,"include_proto":true},{"addr":"0x699bf0","include_decompile":true,"include_proto":true},{"addr":"0x699cb0","include_decompile":true,"include_proto":true},{"addr":"0x699d20","include_decompile":true,"include_proto":true},{"addr":"0x699e30","include_decompile":true,"include_proto":true},{"addr":"0x699ea0","include_decompile":true,"include_proto":true},{"addr":"0x699f60","include_decompile":true,"include_proto":true},{"addr":"0x69a020","include_decompile":true,"include_proto":true},{"addr":"0x69a090","include_decompile":true,"include_proto":true},{"addr":"0x69a1a0","include_decompile":true,"include_proto":true},{"addr":"0x69a220","include_decompile":true,"include_proto":true},{"addr":"0x69a270","include_decompile":true,"include_proto":true},{"addr":"0x69a2b0","include_decompile":true,"include_proto":true},{"addr":"0x69a2c0","include_decompile":true,"include_proto":true},{"addr":"0x69a2d0","include_decompile":true,"include_proto":true},{"addr":"0x69a2e0","include_decompile":true,"include_proto":true},{"addr":"0x69a2f0","include_decompile":true,"include_proto":true},{"addr":"0x69a320","include_decompile":true,"include_proto":true},{"addr":"0x69a390","include_decompile":true,"include_proto":true},{"addr":"0x69a410","include_decompile":true,"include_proto":true},{"addr":"0x69a490","include_decompile":true,"include_proto":true},{"addr":"0x69a4a0","include_decompile":true,"include_proto":true},{"addr":"0x69a4d0","include_decompile":true,"include_proto":true},{"addr":"0x69a510","include_decompile":true,"include_proto":true},{"addr":"0x69a520","include_decompile":true,"include_proto":true},{"addr":"0x69a530","include_decompile":true,"include_proto":true},{"addr":"0x69a590","include_decompile":true,"include_proto":true},{"addr":"0x69a5b0","include_decompile":true,"include_proto":true},{"addr":"0x69a5d0","include_decompile":true,"include_proto":true},{"addr":"0x69a630","include_decompile":true,"include_proto":true},{"addr":"0x69a7f0","include_decompile":true,"include_proto":true},{"addr":"0x69aab0","include_decompile":true,"include_proto":true},{"addr":"0x69ab00","include_decompile":true,"include_proto":true},{"addr":"0x69ace0","include_decompile":true,"include_proto":true},{"addr":"0x69ad50","include_decompile":true,"include_proto":true},{"addr":"0x69af60","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0081', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0081: empty response'); return; }
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
      console.log('Batch 0081: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0081 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0081 conn error:', e.message));
req.write(body);
req.end();
