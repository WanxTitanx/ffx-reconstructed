
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7b98e0","include_decompile":true,"include_proto":true},{"addr":"0x7b9900","include_decompile":true,"include_proto":true},{"addr":"0x7b9920","include_decompile":true,"include_proto":true},{"addr":"0x7b9980","include_decompile":true,"include_proto":true},{"addr":"0x7b99a0","include_decompile":true,"include_proto":true},{"addr":"0x7b9a00","include_decompile":true,"include_proto":true},{"addr":"0x7b9a20","include_decompile":true,"include_proto":true},{"addr":"0x7b9a40","include_decompile":true,"include_proto":true},{"addr":"0x7b9aa0","include_decompile":true,"include_proto":true},{"addr":"0x7b9ac0","include_decompile":true,"include_proto":true},{"addr":"0x7b9b60","include_decompile":true,"include_proto":true},{"addr":"0x7b9c20","include_decompile":true,"include_proto":true},{"addr":"0x7b9c80","include_decompile":true,"include_proto":true},{"addr":"0x7b9ca0","include_decompile":true,"include_proto":true},{"addr":"0x7b9cc0","include_decompile":true,"include_proto":true},{"addr":"0x7b9ce0","include_decompile":true,"include_proto":true},{"addr":"0x7b9d00","include_decompile":true,"include_proto":true},{"addr":"0x7b9d20","include_decompile":true,"include_proto":true},{"addr":"0x7b9d90","include_decompile":true,"include_proto":true},{"addr":"0x7b9db0","include_decompile":true,"include_proto":true},{"addr":"0x7b9e10","include_decompile":true,"include_proto":true},{"addr":"0x7b9e30","include_decompile":true,"include_proto":true},{"addr":"0x7b9ea0","include_decompile":true,"include_proto":true},{"addr":"0x7b9ec0","include_decompile":true,"include_proto":true},{"addr":"0x7b9f20","include_decompile":true,"include_proto":true},{"addr":"0x7b9f40","include_decompile":true,"include_proto":true},{"addr":"0x7b9f60","include_decompile":true,"include_proto":true},{"addr":"0x7b9f80","include_decompile":true,"include_proto":true},{"addr":"0x7b9fa0","include_decompile":true,"include_proto":true},{"addr":"0x7ba060","include_decompile":true,"include_proto":true},{"addr":"0x7ba080","include_decompile":true,"include_proto":true},{"addr":"0x7ba150","include_decompile":true,"include_proto":true},{"addr":"0x7ba170","include_decompile":true,"include_proto":true},{"addr":"0x7ba190","include_decompile":true,"include_proto":true},{"addr":"0x7ba250","include_decompile":true,"include_proto":true},{"addr":"0x7ba270","include_decompile":true,"include_proto":true},{"addr":"0x7ba2d0","include_decompile":true,"include_proto":true},{"addr":"0x7ba340","include_decompile":true,"include_proto":true},{"addr":"0x7ba3e0","include_decompile":true,"include_proto":true},{"addr":"0x7ba530","include_decompile":true,"include_proto":true},{"addr":"0x7ba5d0","include_decompile":true,"include_proto":true},{"addr":"0x7ba650","include_decompile":true,"include_proto":true},{"addr":"0x7ba700","include_decompile":true,"include_proto":true},{"addr":"0x7ba7e0","include_decompile":true,"include_proto":true},{"addr":"0x7ba8d0","include_decompile":true,"include_proto":true},{"addr":"0x7ba920","include_decompile":true,"include_proto":true},{"addr":"0x7ba940","include_decompile":true,"include_proto":true},{"addr":"0x7ba9d0","include_decompile":true,"include_proto":true},{"addr":"0x7baa20","include_decompile":true,"include_proto":true},{"addr":"0x7baa40","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0192', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0192: empty response'); return; }
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
      console.log('Batch 0192: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0192 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0192 conn error:', e.message));
req.write(body);
req.end();
