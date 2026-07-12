
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6d62f0","include_decompile":true,"include_proto":true},{"addr":"0x6d6310","include_decompile":true,"include_proto":true},{"addr":"0x6d6330","include_decompile":true,"include_proto":true},{"addr":"0x6d6350","include_decompile":true,"include_proto":true},{"addr":"0x6d6370","include_decompile":true,"include_proto":true},{"addr":"0x6d6400","include_decompile":true,"include_proto":true},{"addr":"0x6d6490","include_decompile":true,"include_proto":true},{"addr":"0x6d65a0","include_decompile":true,"include_proto":true},{"addr":"0x6d65b0","include_decompile":true,"include_proto":true},{"addr":"0x6d65c0","include_decompile":true,"include_proto":true},{"addr":"0x6d65d0","include_decompile":true,"include_proto":true},{"addr":"0x6d65e0","include_decompile":true,"include_proto":true},{"addr":"0x6d65f0","include_decompile":true,"include_proto":true},{"addr":"0x6d6690","include_decompile":true,"include_proto":true},{"addr":"0x6d66a0","include_decompile":true,"include_proto":true},{"addr":"0x6d66b0","include_decompile":true,"include_proto":true},{"addr":"0x6d66c0","include_decompile":true,"include_proto":true},{"addr":"0x6d66d0","include_decompile":true,"include_proto":true},{"addr":"0x6d66e0","include_decompile":true,"include_proto":true},{"addr":"0x6d66f0","include_decompile":true,"include_proto":true},{"addr":"0x6d6700","include_decompile":true,"include_proto":true},{"addr":"0x6d6710","include_decompile":true,"include_proto":true},{"addr":"0x6d6720","include_decompile":true,"include_proto":true},{"addr":"0x6d6730","include_decompile":true,"include_proto":true},{"addr":"0x6d6740","include_decompile":true,"include_proto":true},{"addr":"0x6d6750","include_decompile":true,"include_proto":true},{"addr":"0x6d6860","include_decompile":true,"include_proto":true},{"addr":"0x6d6870","include_decompile":true,"include_proto":true},{"addr":"0x6d6880","include_decompile":true,"include_proto":true},{"addr":"0x6d6890","include_decompile":true,"include_proto":true},{"addr":"0x6d68a0","include_decompile":true,"include_proto":true},{"addr":"0x6d68b0","include_decompile":true,"include_proto":true},{"addr":"0x6d68c0","include_decompile":true,"include_proto":true},{"addr":"0x6d68d0","include_decompile":true,"include_proto":true},{"addr":"0x6d6960","include_decompile":true,"include_proto":true},{"addr":"0x6d6970","include_decompile":true,"include_proto":true},{"addr":"0x6d6980","include_decompile":true,"include_proto":true},{"addr":"0x6d6990","include_decompile":true,"include_proto":true},{"addr":"0x6d69a0","include_decompile":true,"include_proto":true},{"addr":"0x6d69b0","include_decompile":true,"include_proto":true},{"addr":"0x6d69c0","include_decompile":true,"include_proto":true},{"addr":"0x6d69d0","include_decompile":true,"include_proto":true},{"addr":"0x6d69e0","include_decompile":true,"include_proto":true},{"addr":"0x6d69f0","include_decompile":true,"include_proto":true},{"addr":"0x6d6a40","include_decompile":true,"include_proto":true},{"addr":"0x6d6aa0","include_decompile":true,"include_proto":true},{"addr":"0x6d6da0","include_decompile":true,"include_proto":true},{"addr":"0x6d6e30","include_decompile":true,"include_proto":true},{"addr":"0x6d7010","include_decompile":true,"include_proto":true},{"addr":"0x6d7030","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0103', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0103: empty response'); return; }
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
      console.log('Batch 0103: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0103 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0103 conn error:', e.message));
req.write(body);
req.end();
