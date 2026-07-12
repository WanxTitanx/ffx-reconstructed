
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6189c0","include_decompile":true,"include_proto":true},{"addr":"0x618a10","include_decompile":true,"include_proto":true},{"addr":"0x618a70","include_decompile":true,"include_proto":true},{"addr":"0x618ab0","include_decompile":true,"include_proto":true},{"addr":"0x618b00","include_decompile":true,"include_proto":true},{"addr":"0x618bb0","include_decompile":true,"include_proto":true},{"addr":"0x618bc0","include_decompile":true,"include_proto":true},{"addr":"0x618bf0","include_decompile":true,"include_proto":true},{"addr":"0x618c00","include_decompile":true,"include_proto":true},{"addr":"0x618c50","include_decompile":true,"include_proto":true},{"addr":"0x618ca0","include_decompile":true,"include_proto":true},{"addr":"0x618cf0","include_decompile":true,"include_proto":true},{"addr":"0x618d40","include_decompile":true,"include_proto":true},{"addr":"0x618d90","include_decompile":true,"include_proto":true},{"addr":"0x618de0","include_decompile":true,"include_proto":true},{"addr":"0x618e30","include_decompile":true,"include_proto":true},{"addr":"0x618ec0","include_decompile":true,"include_proto":true},{"addr":"0x618f10","include_decompile":true,"include_proto":true},{"addr":"0x618f60","include_decompile":true,"include_proto":true},{"addr":"0x618fb0","include_decompile":true,"include_proto":true},{"addr":"0x618fc0","include_decompile":true,"include_proto":true},{"addr":"0x618fd0","include_decompile":true,"include_proto":true},{"addr":"0x618fe0","include_decompile":true,"include_proto":true},{"addr":"0x618ff0","include_decompile":true,"include_proto":true},{"addr":"0x619000","include_decompile":true,"include_proto":true},{"addr":"0x619010","include_decompile":true,"include_proto":true},{"addr":"0x619020","include_decompile":true,"include_proto":true},{"addr":"0x619030","include_decompile":true,"include_proto":true},{"addr":"0x619040","include_decompile":true,"include_proto":true},{"addr":"0x619050","include_decompile":true,"include_proto":true},{"addr":"0x619060","include_decompile":true,"include_proto":true},{"addr":"0x619090","include_decompile":true,"include_proto":true},{"addr":"0x6190b0","include_decompile":true,"include_proto":true},{"addr":"0x6190d0","include_decompile":true,"include_proto":true},{"addr":"0x619120","include_decompile":true,"include_proto":true},{"addr":"0x619140","include_decompile":true,"include_proto":true},{"addr":"0x619220","include_decompile":true,"include_proto":true},{"addr":"0x619230","include_decompile":true,"include_proto":true},{"addr":"0x619320","include_decompile":true,"include_proto":true},{"addr":"0x619330","include_decompile":true,"include_proto":true},{"addr":"0x619350","include_decompile":true,"include_proto":true},{"addr":"0x619430","include_decompile":true,"include_proto":true},{"addr":"0x619570","include_decompile":true,"include_proto":true},{"addr":"0x619580","include_decompile":true,"include_proto":true},{"addr":"0x6195a0","include_decompile":true,"include_proto":true},{"addr":"0x6195b0","include_decompile":true,"include_proto":true},{"addr":"0x6195c0","include_decompile":true,"include_proto":true},{"addr":"0x619660","include_decompile":true,"include_proto":true},{"addr":"0x619670","include_decompile":true,"include_proto":true},{"addr":"0x6196a0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0013', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0013: empty response'); return; }
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
      console.log('Batch 0013: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0013 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0013 conn error:', e.message));
req.write(body);
req.end();
