
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6d70b0","include_decompile":true,"include_proto":true},{"addr":"0x6d70e0","include_decompile":true,"include_proto":true},{"addr":"0x6d7120","include_decompile":true,"include_proto":true},{"addr":"0x6d7190","include_decompile":true,"include_proto":true},{"addr":"0x6d7260","include_decompile":true,"include_proto":true},{"addr":"0x6d72e0","include_decompile":true,"include_proto":true},{"addr":"0x6d74a0","include_decompile":true,"include_proto":true},{"addr":"0x6d74d0","include_decompile":true,"include_proto":true},{"addr":"0x6d7560","include_decompile":true,"include_proto":true},{"addr":"0x6d76a0","include_decompile":true,"include_proto":true},{"addr":"0x6d77b0","include_decompile":true,"include_proto":true},{"addr":"0x6d79f0","include_decompile":true,"include_proto":true},{"addr":"0x6d7a20","include_decompile":true,"include_proto":true},{"addr":"0x6d7a60","include_decompile":true,"include_proto":true},{"addr":"0x6d7ab0","include_decompile":true,"include_proto":true},{"addr":"0x6d7af0","include_decompile":true,"include_proto":true},{"addr":"0x6d7bd0","include_decompile":true,"include_proto":true},{"addr":"0x6d7be0","include_decompile":true,"include_proto":true},{"addr":"0x6d7bf0","include_decompile":true,"include_proto":true},{"addr":"0x6d7c50","include_decompile":true,"include_proto":true},{"addr":"0x6d7c90","include_decompile":true,"include_proto":true},{"addr":"0x6d7ca0","include_decompile":true,"include_proto":true},{"addr":"0x6d7cb0","include_decompile":true,"include_proto":true},{"addr":"0x6d7d10","include_decompile":true,"include_proto":true},{"addr":"0x6d7d30","include_decompile":true,"include_proto":true},{"addr":"0x6d7d50","include_decompile":true,"include_proto":true},{"addr":"0x6d7d60","include_decompile":true,"include_proto":true},{"addr":"0x6d7d90","include_decompile":true,"include_proto":true},{"addr":"0x6d7df0","include_decompile":true,"include_proto":true},{"addr":"0x6d7eb0","include_decompile":true,"include_proto":true},{"addr":"0x6d7ec0","include_decompile":true,"include_proto":true},{"addr":"0x6d7f40","include_decompile":true,"include_proto":true},{"addr":"0x6d80e0","include_decompile":true,"include_proto":true},{"addr":"0x6d8420","include_decompile":true,"include_proto":true},{"addr":"0x6d8810","include_decompile":true,"include_proto":true},{"addr":"0x6d8a50","include_decompile":true,"include_proto":true},{"addr":"0x6d8a60","include_decompile":true,"include_proto":true},{"addr":"0x6d8a70","include_decompile":true,"include_proto":true},{"addr":"0x6d8b30","include_decompile":true,"include_proto":true},{"addr":"0x6d8de0","include_decompile":true,"include_proto":true},{"addr":"0x6d9060","include_decompile":true,"include_proto":true},{"addr":"0x6d90b0","include_decompile":true,"include_proto":true},{"addr":"0x6d90f0","include_decompile":true,"include_proto":true},{"addr":"0x6d92b0","include_decompile":true,"include_proto":true},{"addr":"0x6d92e0","include_decompile":true,"include_proto":true},{"addr":"0x6d92f0","include_decompile":true,"include_proto":true},{"addr":"0x6d9300","include_decompile":true,"include_proto":true},{"addr":"0x6d9350","include_decompile":true,"include_proto":true},{"addr":"0x6d9360","include_decompile":true,"include_proto":true},{"addr":"0x6d9510","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0104', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0104: empty response'); return; }
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
      console.log('Batch 0104: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0104 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0104 conn error:', e.message));
req.write(body);
req.end();
