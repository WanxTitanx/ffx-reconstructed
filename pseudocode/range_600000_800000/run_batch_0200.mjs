
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7e5c60","include_decompile":true,"include_proto":true},{"addr":"0x7e5e40","include_decompile":true,"include_proto":true},{"addr":"0x7e5e90","include_decompile":true,"include_proto":true},{"addr":"0x7e6020","include_decompile":true,"include_proto":true},{"addr":"0x7e62b0","include_decompile":true,"include_proto":true},{"addr":"0x7e62c0","include_decompile":true,"include_proto":true},{"addr":"0x7e6350","include_decompile":true,"include_proto":true},{"addr":"0x7e6380","include_decompile":true,"include_proto":true},{"addr":"0x7e6390","include_decompile":true,"include_proto":true},{"addr":"0x7e63c0","include_decompile":true,"include_proto":true},{"addr":"0x7e63e0","include_decompile":true,"include_proto":true},{"addr":"0x7e6470","include_decompile":true,"include_proto":true},{"addr":"0x7e64f0","include_decompile":true,"include_proto":true},{"addr":"0x7e6520","include_decompile":true,"include_proto":true},{"addr":"0x7e65a0","include_decompile":true,"include_proto":true},{"addr":"0x7e6610","include_decompile":true,"include_proto":true},{"addr":"0x7e6690","include_decompile":true,"include_proto":true},{"addr":"0x7e6700","include_decompile":true,"include_proto":true},{"addr":"0x7e6910","include_decompile":true,"include_proto":true},{"addr":"0x7e6970","include_decompile":true,"include_proto":true},{"addr":"0x7e6a30","include_decompile":true,"include_proto":true},{"addr":"0x7e6a40","include_decompile":true,"include_proto":true},{"addr":"0x7e6a50","include_decompile":true,"include_proto":true},{"addr":"0x7e6a60","include_decompile":true,"include_proto":true},{"addr":"0x7e6b40","include_decompile":true,"include_proto":true},{"addr":"0x7e6b70","include_decompile":true,"include_proto":true},{"addr":"0x7e6bd0","include_decompile":true,"include_proto":true},{"addr":"0x7e6c90","include_decompile":true,"include_proto":true},{"addr":"0x7e6d60","include_decompile":true,"include_proto":true},{"addr":"0x7e7030","include_decompile":true,"include_proto":true},{"addr":"0x7e7240","include_decompile":true,"include_proto":true},{"addr":"0x7e7360","include_decompile":true,"include_proto":true},{"addr":"0x7e75f0","include_decompile":true,"include_proto":true},{"addr":"0x7e76e0","include_decompile":true,"include_proto":true},{"addr":"0x7e78b0","include_decompile":true,"include_proto":true},{"addr":"0x7e7af0","include_decompile":true,"include_proto":true},{"addr":"0x7e7bc0","include_decompile":true,"include_proto":true},{"addr":"0x7e7d90","include_decompile":true,"include_proto":true},{"addr":"0x7e7de0","include_decompile":true,"include_proto":true},{"addr":"0x7e7e70","include_decompile":true,"include_proto":true},{"addr":"0x7e7ed0","include_decompile":true,"include_proto":true},{"addr":"0x7e7f20","include_decompile":true,"include_proto":true},{"addr":"0x7e7f40","include_decompile":true,"include_proto":true},{"addr":"0x7e82c0","include_decompile":true,"include_proto":true},{"addr":"0x7e8a10","include_decompile":true,"include_proto":true},{"addr":"0x7e8ee0","include_decompile":true,"include_proto":true},{"addr":"0x7e9440","include_decompile":true,"include_proto":true},{"addr":"0x7e9490","include_decompile":true,"include_proto":true},{"addr":"0x7e9580","include_decompile":true,"include_proto":true},{"addr":"0x7e9670","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0200', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0200: empty response'); return; }
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
      console.log('Batch 0200: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0200 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0200 conn error:', e.message));
req.write(body);
req.end();
