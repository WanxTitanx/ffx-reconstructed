
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x617ce0","include_decompile":true,"include_proto":true},{"addr":"0x617dc0","include_decompile":true,"include_proto":true},{"addr":"0x617dd0","include_decompile":true,"include_proto":true},{"addr":"0x617de0","include_decompile":true,"include_proto":true},{"addr":"0x617df0","include_decompile":true,"include_proto":true},{"addr":"0x617e00","include_decompile":true,"include_proto":true},{"addr":"0x617e50","include_decompile":true,"include_proto":true},{"addr":"0x617e60","include_decompile":true,"include_proto":true},{"addr":"0x617f10","include_decompile":true,"include_proto":true},{"addr":"0x617f20","include_decompile":true,"include_proto":true},{"addr":"0x617f30","include_decompile":true,"include_proto":true},{"addr":"0x617fa0","include_decompile":true,"include_proto":true},{"addr":"0x617fb0","include_decompile":true,"include_proto":true},{"addr":"0x617fc0","include_decompile":true,"include_proto":true},{"addr":"0x617fd0","include_decompile":true,"include_proto":true},{"addr":"0x618000","include_decompile":true,"include_proto":true},{"addr":"0x618050","include_decompile":true,"include_proto":true},{"addr":"0x618060","include_decompile":true,"include_proto":true},{"addr":"0x618080","include_decompile":true,"include_proto":true},{"addr":"0x618090","include_decompile":true,"include_proto":true},{"addr":"0x6180b0","include_decompile":true,"include_proto":true},{"addr":"0x6180f0","include_decompile":true,"include_proto":true},{"addr":"0x618120","include_decompile":true,"include_proto":true},{"addr":"0x618160","include_decompile":true,"include_proto":true},{"addr":"0x618180","include_decompile":true,"include_proto":true},{"addr":"0x6181b0","include_decompile":true,"include_proto":true},{"addr":"0x618200","include_decompile":true,"include_proto":true},{"addr":"0x618210","include_decompile":true,"include_proto":true},{"addr":"0x618220","include_decompile":true,"include_proto":true},{"addr":"0x618230","include_decompile":true,"include_proto":true},{"addr":"0x618240","include_decompile":true,"include_proto":true},{"addr":"0x618250","include_decompile":true,"include_proto":true},{"addr":"0x618260","include_decompile":true,"include_proto":true},{"addr":"0x618290","include_decompile":true,"include_proto":true},{"addr":"0x6182c0","include_decompile":true,"include_proto":true},{"addr":"0x6182f0","include_decompile":true,"include_proto":true},{"addr":"0x618310","include_decompile":true,"include_proto":true},{"addr":"0x6184f0","include_decompile":true,"include_proto":true},{"addr":"0x618650","include_decompile":true,"include_proto":true},{"addr":"0x618760","include_decompile":true,"include_proto":true},{"addr":"0x618790","include_decompile":true,"include_proto":true},{"addr":"0x6187b0","include_decompile":true,"include_proto":true},{"addr":"0x6187c0","include_decompile":true,"include_proto":true},{"addr":"0x6187f0","include_decompile":true,"include_proto":true},{"addr":"0x618830","include_decompile":true,"include_proto":true},{"addr":"0x618870","include_decompile":true,"include_proto":true},{"addr":"0x6188b0","include_decompile":true,"include_proto":true},{"addr":"0x6188f0","include_decompile":true,"include_proto":true},{"addr":"0x618930","include_decompile":true,"include_proto":true},{"addr":"0x618970","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0012', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0012: empty response'); return; }
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
      console.log('Batch 0012: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0012 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0012 conn error:', e.message));
req.write(body);
req.end();
