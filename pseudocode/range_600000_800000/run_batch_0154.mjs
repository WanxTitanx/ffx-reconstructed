
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x772940","include_decompile":true,"include_proto":true},{"addr":"0x772970","include_decompile":true,"include_proto":true},{"addr":"0x7729a0","include_decompile":true,"include_proto":true},{"addr":"0x7729c0","include_decompile":true,"include_proto":true},{"addr":"0x7729f0","include_decompile":true,"include_proto":true},{"addr":"0x772a10","include_decompile":true,"include_proto":true},{"addr":"0x772a30","include_decompile":true,"include_proto":true},{"addr":"0x772a60","include_decompile":true,"include_proto":true},{"addr":"0x772a80","include_decompile":true,"include_proto":true},{"addr":"0x772a90","include_decompile":true,"include_proto":true},{"addr":"0x772ac0","include_decompile":true,"include_proto":true},{"addr":"0x772ae0","include_decompile":true,"include_proto":true},{"addr":"0x772af0","include_decompile":true,"include_proto":true},{"addr":"0x772b10","include_decompile":true,"include_proto":true},{"addr":"0x772b40","include_decompile":true,"include_proto":true},{"addr":"0x772b60","include_decompile":true,"include_proto":true},{"addr":"0x772b80","include_decompile":true,"include_proto":true},{"addr":"0x772ba0","include_decompile":true,"include_proto":true},{"addr":"0x772bd0","include_decompile":true,"include_proto":true},{"addr":"0x772bf0","include_decompile":true,"include_proto":true},{"addr":"0x772c10","include_decompile":true,"include_proto":true},{"addr":"0x772c40","include_decompile":true,"include_proto":true},{"addr":"0x772c60","include_decompile":true,"include_proto":true},{"addr":"0x772c80","include_decompile":true,"include_proto":true},{"addr":"0x772cb0","include_decompile":true,"include_proto":true},{"addr":"0x772cd0","include_decompile":true,"include_proto":true},{"addr":"0x772cf0","include_decompile":true,"include_proto":true},{"addr":"0x772d20","include_decompile":true,"include_proto":true},{"addr":"0x772d40","include_decompile":true,"include_proto":true},{"addr":"0x772d60","include_decompile":true,"include_proto":true},{"addr":"0x772d80","include_decompile":true,"include_proto":true},{"addr":"0x772db0","include_decompile":true,"include_proto":true},{"addr":"0x772dd0","include_decompile":true,"include_proto":true},{"addr":"0x772df0","include_decompile":true,"include_proto":true},{"addr":"0x772e10","include_decompile":true,"include_proto":true},{"addr":"0x772e40","include_decompile":true,"include_proto":true},{"addr":"0x772e60","include_decompile":true,"include_proto":true},{"addr":"0x772e80","include_decompile":true,"include_proto":true},{"addr":"0x772eb0","include_decompile":true,"include_proto":true},{"addr":"0x772ed0","include_decompile":true,"include_proto":true},{"addr":"0x772f00","include_decompile":true,"include_proto":true},{"addr":"0x772f30","include_decompile":true,"include_proto":true},{"addr":"0x772f50","include_decompile":true,"include_proto":true},{"addr":"0x772f80","include_decompile":true,"include_proto":true},{"addr":"0x772fb0","include_decompile":true,"include_proto":true},{"addr":"0x772fd0","include_decompile":true,"include_proto":true},{"addr":"0x772ff0","include_decompile":true,"include_proto":true},{"addr":"0x773010","include_decompile":true,"include_proto":true},{"addr":"0x773040","include_decompile":true,"include_proto":true},{"addr":"0x773060","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0154', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0154: empty response'); return; }
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
      console.log('Batch 0154: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0154 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0154 conn error:', e.message));
req.write(body);
req.end();
