
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x620c50","include_decompile":true,"include_proto":true},{"addr":"0x620c60","include_decompile":true,"include_proto":true},{"addr":"0x620c70","include_decompile":true,"include_proto":true},{"addr":"0x620c80","include_decompile":true,"include_proto":true},{"addr":"0x620c90","include_decompile":true,"include_proto":true},{"addr":"0x620ca0","include_decompile":true,"include_proto":true},{"addr":"0x620cb0","include_decompile":true,"include_proto":true},{"addr":"0x620cc0","include_decompile":true,"include_proto":true},{"addr":"0x620cd0","include_decompile":true,"include_proto":true},{"addr":"0x620ce0","include_decompile":true,"include_proto":true},{"addr":"0x620d80","include_decompile":true,"include_proto":true},{"addr":"0x620ec0","include_decompile":true,"include_proto":true},{"addr":"0x620f40","include_decompile":true,"include_proto":true},{"addr":"0x620ff0","include_decompile":true,"include_proto":true},{"addr":"0x621070","include_decompile":true,"include_proto":true},{"addr":"0x621080","include_decompile":true,"include_proto":true},{"addr":"0x6210a0","include_decompile":true,"include_proto":true},{"addr":"0x621110","include_decompile":true,"include_proto":true},{"addr":"0x621120","include_decompile":true,"include_proto":true},{"addr":"0x6211b0","include_decompile":true,"include_proto":true},{"addr":"0x621210","include_decompile":true,"include_proto":true},{"addr":"0x621290","include_decompile":true,"include_proto":true},{"addr":"0x6212f0","include_decompile":true,"include_proto":true},{"addr":"0x621350","include_decompile":true,"include_proto":true},{"addr":"0x621360","include_decompile":true,"include_proto":true},{"addr":"0x621370","include_decompile":true,"include_proto":true},{"addr":"0x6213f0","include_decompile":true,"include_proto":true},{"addr":"0x6214f0","include_decompile":true,"include_proto":true},{"addr":"0x621550","include_decompile":true,"include_proto":true},{"addr":"0x621560","include_decompile":true,"include_proto":true},{"addr":"0x621570","include_decompile":true,"include_proto":true},{"addr":"0x6215b0","include_decompile":true,"include_proto":true},{"addr":"0x6215c0","include_decompile":true,"include_proto":true},{"addr":"0x621600","include_decompile":true,"include_proto":true},{"addr":"0x621610","include_decompile":true,"include_proto":true},{"addr":"0x621670","include_decompile":true,"include_proto":true},{"addr":"0x621740","include_decompile":true,"include_proto":true},{"addr":"0x621800","include_decompile":true,"include_proto":true},{"addr":"0x621830","include_decompile":true,"include_proto":true},{"addr":"0x621860","include_decompile":true,"include_proto":true},{"addr":"0x621890","include_decompile":true,"include_proto":true},{"addr":"0x6218c0","include_decompile":true,"include_proto":true},{"addr":"0x6218f0","include_decompile":true,"include_proto":true},{"addr":"0x621920","include_decompile":true,"include_proto":true},{"addr":"0x621950","include_decompile":true,"include_proto":true},{"addr":"0x621980","include_decompile":true,"include_proto":true},{"addr":"0x6219b0","include_decompile":true,"include_proto":true},{"addr":"0x6219e0","include_decompile":true,"include_proto":true},{"addr":"0x621a10","include_decompile":true,"include_proto":true},{"addr":"0x621a40","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0019', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0019: empty response'); return; }
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
      console.log('Batch 0019: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0019 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0019 conn error:', e.message));
req.write(body);
req.end();
