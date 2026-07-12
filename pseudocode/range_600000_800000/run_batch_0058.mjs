
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x65fcd0","include_decompile":true,"include_proto":true},{"addr":"0x65fd60","include_decompile":true,"include_proto":true},{"addr":"0x65fe20","include_decompile":true,"include_proto":true},{"addr":"0x65fed0","include_decompile":true,"include_proto":true},{"addr":"0x65ff50","include_decompile":true,"include_proto":true},{"addr":"0x660350","include_decompile":true,"include_proto":true},{"addr":"0x660360","include_decompile":true,"include_proto":true},{"addr":"0x6603a0","include_decompile":true,"include_proto":true},{"addr":"0x6603b0","include_decompile":true,"include_proto":true},{"addr":"0x6603c0","include_decompile":true,"include_proto":true},{"addr":"0x6603f0","include_decompile":true,"include_proto":true},{"addr":"0x660420","include_decompile":true,"include_proto":true},{"addr":"0x660450","include_decompile":true,"include_proto":true},{"addr":"0x660480","include_decompile":true,"include_proto":true},{"addr":"0x6604b0","include_decompile":true,"include_proto":true},{"addr":"0x660510","include_decompile":true,"include_proto":true},{"addr":"0x660520","include_decompile":true,"include_proto":true},{"addr":"0x660530","include_decompile":true,"include_proto":true},{"addr":"0x660540","include_decompile":true,"include_proto":true},{"addr":"0x660580","include_decompile":true,"include_proto":true},{"addr":"0x660590","include_decompile":true,"include_proto":true},{"addr":"0x6605a0","include_decompile":true,"include_proto":true},{"addr":"0x660650","include_decompile":true,"include_proto":true},{"addr":"0x661e10","include_decompile":true,"include_proto":true},{"addr":"0x663bc0","include_decompile":true,"include_proto":true},{"addr":"0x663e50","include_decompile":true,"include_proto":true},{"addr":"0x663ec0","include_decompile":true,"include_proto":true},{"addr":"0x663ed0","include_decompile":true,"include_proto":true},{"addr":"0x663fb0","include_decompile":true,"include_proto":true},{"addr":"0x664090","include_decompile":true,"include_proto":true},{"addr":"0x6640b0","include_decompile":true,"include_proto":true},{"addr":"0x664480","include_decompile":true,"include_proto":true},{"addr":"0x6644f0","include_decompile":true,"include_proto":true},{"addr":"0x6645d0","include_decompile":true,"include_proto":true},{"addr":"0x6646e0","include_decompile":true,"include_proto":true},{"addr":"0x664ea0","include_decompile":true,"include_proto":true},{"addr":"0x664f10","include_decompile":true,"include_proto":true},{"addr":"0x6650f0","include_decompile":true,"include_proto":true},{"addr":"0x6651a0","include_decompile":true,"include_proto":true},{"addr":"0x665280","include_decompile":true,"include_proto":true},{"addr":"0x665360","include_decompile":true,"include_proto":true},{"addr":"0x665390","include_decompile":true,"include_proto":true},{"addr":"0x665470","include_decompile":true,"include_proto":true},{"addr":"0x665550","include_decompile":true,"include_proto":true},{"addr":"0x665630","include_decompile":true,"include_proto":true},{"addr":"0x665710","include_decompile":true,"include_proto":true},{"addr":"0x6657f0","include_decompile":true,"include_proto":true},{"addr":"0x665870","include_decompile":true,"include_proto":true},{"addr":"0x665900","include_decompile":true,"include_proto":true},{"addr":"0x6660f0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0058', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0058: empty response'); return; }
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
      console.log('Batch 0058: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0058 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0058 conn error:', e.message));
req.write(body);
req.end();
