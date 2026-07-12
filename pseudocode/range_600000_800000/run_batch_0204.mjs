
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7fc820","include_decompile":true,"include_proto":true},{"addr":"0x7fc830","include_decompile":true,"include_proto":true},{"addr":"0x7fc840","include_decompile":true,"include_proto":true},{"addr":"0x7fc8b0","include_decompile":true,"include_proto":true},{"addr":"0x7fc8c0","include_decompile":true,"include_proto":true},{"addr":"0x7fc8d0","include_decompile":true,"include_proto":true},{"addr":"0x7fc960","include_decompile":true,"include_proto":true},{"addr":"0x7fc9a0","include_decompile":true,"include_proto":true},{"addr":"0x7fc9b0","include_decompile":true,"include_proto":true},{"addr":"0x7fca10","include_decompile":true,"include_proto":true},{"addr":"0x7fca80","include_decompile":true,"include_proto":true},{"addr":"0x7fcaf0","include_decompile":true,"include_proto":true},{"addr":"0x7fcb00","include_decompile":true,"include_proto":true},{"addr":"0x7fcb10","include_decompile":true,"include_proto":true},{"addr":"0x7fcb40","include_decompile":true,"include_proto":true},{"addr":"0x7fcb60","include_decompile":true,"include_proto":true},{"addr":"0x7fcb80","include_decompile":true,"include_proto":true},{"addr":"0x7fcba0","include_decompile":true,"include_proto":true},{"addr":"0x7fcbe0","include_decompile":true,"include_proto":true},{"addr":"0x7fcc30","include_decompile":true,"include_proto":true},{"addr":"0x7fcc80","include_decompile":true,"include_proto":true},{"addr":"0x7fccf0","include_decompile":true,"include_proto":true},{"addr":"0x7fcd30","include_decompile":true,"include_proto":true},{"addr":"0x7fcd40","include_decompile":true,"include_proto":true},{"addr":"0x7fcd50","include_decompile":true,"include_proto":true},{"addr":"0x7fce30","include_decompile":true,"include_proto":true},{"addr":"0x7fce80","include_decompile":true,"include_proto":true},{"addr":"0x7fced0","include_decompile":true,"include_proto":true},{"addr":"0x7fd640","include_decompile":true,"include_proto":true},{"addr":"0x7fd680","include_decompile":true,"include_proto":true},{"addr":"0x7fd710","include_decompile":true,"include_proto":true},{"addr":"0x7fd9a0","include_decompile":true,"include_proto":true},{"addr":"0x7fdb90","include_decompile":true,"include_proto":true},{"addr":"0x7fdba0","include_decompile":true,"include_proto":true},{"addr":"0x7fdd50","include_decompile":true,"include_proto":true},{"addr":"0x7fde90","include_decompile":true,"include_proto":true},{"addr":"0x7fe010","include_decompile":true,"include_proto":true},{"addr":"0x7fe0c0","include_decompile":true,"include_proto":true},{"addr":"0x7fe120","include_decompile":true,"include_proto":true},{"addr":"0x7fe1a0","include_decompile":true,"include_proto":true},{"addr":"0x7fe260","include_decompile":true,"include_proto":true},{"addr":"0x7fe370","include_decompile":true,"include_proto":true},{"addr":"0x7fe400","include_decompile":true,"include_proto":true},{"addr":"0x7fe460","include_decompile":true,"include_proto":true},{"addr":"0x7fe490","include_decompile":true,"include_proto":true},{"addr":"0x7fe5e0","include_decompile":true,"include_proto":true},{"addr":"0x7fe7b0","include_decompile":true,"include_proto":true},{"addr":"0x7fe840","include_decompile":true,"include_proto":true},{"addr":"0x7fe890","include_decompile":true,"include_proto":true},{"addr":"0x7fe9c0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0204', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0204: empty response'); return; }
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
      console.log('Batch 0204: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0204 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0204 conn error:', e.message));
req.write(body);
req.end();
