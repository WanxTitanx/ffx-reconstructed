
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7b2920","include_decompile":true,"include_proto":true},{"addr":"0x7b2960","include_decompile":true,"include_proto":true},{"addr":"0x7b2990","include_decompile":true,"include_proto":true},{"addr":"0x7b2ae0","include_decompile":true,"include_proto":true},{"addr":"0x7b2b10","include_decompile":true,"include_proto":true},{"addr":"0x7b2b30","include_decompile":true,"include_proto":true},{"addr":"0x7b2b40","include_decompile":true,"include_proto":true},{"addr":"0x7b2b50","include_decompile":true,"include_proto":true},{"addr":"0x7b2b60","include_decompile":true,"include_proto":true},{"addr":"0x7b2b70","include_decompile":true,"include_proto":true},{"addr":"0x7b2b80","include_decompile":true,"include_proto":true},{"addr":"0x7b2bb0","include_decompile":true,"include_proto":true},{"addr":"0x7b2bf0","include_decompile":true,"include_proto":true},{"addr":"0x7b2c10","include_decompile":true,"include_proto":true},{"addr":"0x7b2c20","include_decompile":true,"include_proto":true},{"addr":"0x7b2ca0","include_decompile":true,"include_proto":true},{"addr":"0x7b2dd0","include_decompile":true,"include_proto":true},{"addr":"0x7b4a80","include_decompile":true,"include_proto":true},{"addr":"0x7b4aa0","include_decompile":true,"include_proto":true},{"addr":"0x7b4b80","include_decompile":true,"include_proto":true},{"addr":"0x7b6bd0","include_decompile":true,"include_proto":true},{"addr":"0x7b6e90","include_decompile":true,"include_proto":true},{"addr":"0x7b6f30","include_decompile":true,"include_proto":true},{"addr":"0x7b7010","include_decompile":true,"include_proto":true},{"addr":"0x7b70f0","include_decompile":true,"include_proto":true},{"addr":"0x7b7200","include_decompile":true,"include_proto":true},{"addr":"0x7b7240","include_decompile":true,"include_proto":true},{"addr":"0x7b73c0","include_decompile":true,"include_proto":true},{"addr":"0x7b7450","include_decompile":true,"include_proto":true},{"addr":"0x7b7540","include_decompile":true,"include_proto":true},{"addr":"0x7b75d0","include_decompile":true,"include_proto":true},{"addr":"0x7b7600","include_decompile":true,"include_proto":true},{"addr":"0x7b7740","include_decompile":true,"include_proto":true},{"addr":"0x7b7840","include_decompile":true,"include_proto":true},{"addr":"0x7b7c00","include_decompile":true,"include_proto":true},{"addr":"0x7b7c70","include_decompile":true,"include_proto":true},{"addr":"0x7b7c80","include_decompile":true,"include_proto":true},{"addr":"0x7b7cf0","include_decompile":true,"include_proto":true},{"addr":"0x7b7da0","include_decompile":true,"include_proto":true},{"addr":"0x7b7e00","include_decompile":true,"include_proto":true},{"addr":"0x7b7e30","include_decompile":true,"include_proto":true},{"addr":"0x7b7e50","include_decompile":true,"include_proto":true},{"addr":"0x7b7e70","include_decompile":true,"include_proto":true},{"addr":"0x7b7ea0","include_decompile":true,"include_proto":true},{"addr":"0x7b7eb0","include_decompile":true,"include_proto":true},{"addr":"0x7b7ed0","include_decompile":true,"include_proto":true},{"addr":"0x7b7ef0","include_decompile":true,"include_proto":true},{"addr":"0x7b7f60","include_decompile":true,"include_proto":true},{"addr":"0x7b7fd0","include_decompile":true,"include_proto":true},{"addr":"0x7b8040","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0189', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0189: empty response'); return; }
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
      console.log('Batch 0189: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0189 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0189 conn error:', e.message));
req.write(body);
req.end();
