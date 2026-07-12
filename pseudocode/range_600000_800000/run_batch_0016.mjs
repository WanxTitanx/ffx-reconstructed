
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x61ce40","include_decompile":true,"include_proto":true},{"addr":"0x61ce90","include_decompile":true,"include_proto":true},{"addr":"0x61cea0","include_decompile":true,"include_proto":true},{"addr":"0x61ced0","include_decompile":true,"include_proto":true},{"addr":"0x61cf80","include_decompile":true,"include_proto":true},{"addr":"0x61cff0","include_decompile":true,"include_proto":true},{"addr":"0x61d000","include_decompile":true,"include_proto":true},{"addr":"0x61d020","include_decompile":true,"include_proto":true},{"addr":"0x61d0e0","include_decompile":true,"include_proto":true},{"addr":"0x61d1f0","include_decompile":true,"include_proto":true},{"addr":"0x61d270","include_decompile":true,"include_proto":true},{"addr":"0x61d290","include_decompile":true,"include_proto":true},{"addr":"0x61d300","include_decompile":true,"include_proto":true},{"addr":"0x61d3d0","include_decompile":true,"include_proto":true},{"addr":"0x61d4d0","include_decompile":true,"include_proto":true},{"addr":"0x61d540","include_decompile":true,"include_proto":true},{"addr":"0x61d620","include_decompile":true,"include_proto":true},{"addr":"0x61d6f0","include_decompile":true,"include_proto":true},{"addr":"0x61d710","include_decompile":true,"include_proto":true},{"addr":"0x61d770","include_decompile":true,"include_proto":true},{"addr":"0x61d780","include_decompile":true,"include_proto":true},{"addr":"0x61d810","include_decompile":true,"include_proto":true},{"addr":"0x61d820","include_decompile":true,"include_proto":true},{"addr":"0x61d830","include_decompile":true,"include_proto":true},{"addr":"0x61d890","include_decompile":true,"include_proto":true},{"addr":"0x61d8a0","include_decompile":true,"include_proto":true},{"addr":"0x61d8f0","include_decompile":true,"include_proto":true},{"addr":"0x61da70","include_decompile":true,"include_proto":true},{"addr":"0x61da90","include_decompile":true,"include_proto":true},{"addr":"0x61daa0","include_decompile":true,"include_proto":true},{"addr":"0x61dad0","include_decompile":true,"include_proto":true},{"addr":"0x61db70","include_decompile":true,"include_proto":true},{"addr":"0x61db80","include_decompile":true,"include_proto":true},{"addr":"0x61dc70","include_decompile":true,"include_proto":true},{"addr":"0x61dc80","include_decompile":true,"include_proto":true},{"addr":"0x61dff0","include_decompile":true,"include_proto":true},{"addr":"0x61e080","include_decompile":true,"include_proto":true},{"addr":"0x61e0d0","include_decompile":true,"include_proto":true},{"addr":"0x61e130","include_decompile":true,"include_proto":true},{"addr":"0x61e210","include_decompile":true,"include_proto":true},{"addr":"0x61e220","include_decompile":true,"include_proto":true},{"addr":"0x61e230","include_decompile":true,"include_proto":true},{"addr":"0x61e2a0","include_decompile":true,"include_proto":true},{"addr":"0x61e2b0","include_decompile":true,"include_proto":true},{"addr":"0x61e2c0","include_decompile":true,"include_proto":true},{"addr":"0x61e3f0","include_decompile":true,"include_proto":true},{"addr":"0x61e550","include_decompile":true,"include_proto":true},{"addr":"0x61e570","include_decompile":true,"include_proto":true},{"addr":"0x61e5a0","include_decompile":true,"include_proto":true},{"addr":"0x61e630","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0016', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0016: empty response'); return; }
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
      console.log('Batch 0016: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0016 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0016 conn error:', e.message));
req.write(body);
req.end();
