
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x734240","include_decompile":true,"include_proto":true},{"addr":"0x7342b0","include_decompile":true,"include_proto":true},{"addr":"0x7344d0","include_decompile":true,"include_proto":true},{"addr":"0x734710","include_decompile":true,"include_proto":true},{"addr":"0x734950","include_decompile":true,"include_proto":true},{"addr":"0x7349e0","include_decompile":true,"include_proto":true},{"addr":"0x734a80","include_decompile":true,"include_proto":true},{"addr":"0x734b00","include_decompile":true,"include_proto":true},{"addr":"0x734b70","include_decompile":true,"include_proto":true},{"addr":"0x734bc0","include_decompile":true,"include_proto":true},{"addr":"0x734c40","include_decompile":true,"include_proto":true},{"addr":"0x734c70","include_decompile":true,"include_proto":true},{"addr":"0x734ca0","include_decompile":true,"include_proto":true},{"addr":"0x734d20","include_decompile":true,"include_proto":true},{"addr":"0x734dc0","include_decompile":true,"include_proto":true},{"addr":"0x734e60","include_decompile":true,"include_proto":true},{"addr":"0x734f80","include_decompile":true,"include_proto":true},{"addr":"0x734fc0","include_decompile":true,"include_proto":true},{"addr":"0x735050","include_decompile":true,"include_proto":true},{"addr":"0x7350f0","include_decompile":true,"include_proto":true},{"addr":"0x7351d0","include_decompile":true,"include_proto":true},{"addr":"0x735230","include_decompile":true,"include_proto":true},{"addr":"0x735590","include_decompile":true,"include_proto":true},{"addr":"0x735fa0","include_decompile":true,"include_proto":true},{"addr":"0x736110","include_decompile":true,"include_proto":true},{"addr":"0x736520","include_decompile":true,"include_proto":true},{"addr":"0x7365a0","include_decompile":true,"include_proto":true},{"addr":"0x736630","include_decompile":true,"include_proto":true},{"addr":"0x736640","include_decompile":true,"include_proto":true},{"addr":"0x736750","include_decompile":true,"include_proto":true},{"addr":"0x736780","include_decompile":true,"include_proto":true},{"addr":"0x7367b0","include_decompile":true,"include_proto":true},{"addr":"0x7367e0","include_decompile":true,"include_proto":true},{"addr":"0x736810","include_decompile":true,"include_proto":true},{"addr":"0x736840","include_decompile":true,"include_proto":true},{"addr":"0x736870","include_decompile":true,"include_proto":true},{"addr":"0x7368a0","include_decompile":true,"include_proto":true},{"addr":"0x7368d0","include_decompile":true,"include_proto":true},{"addr":"0x736900","include_decompile":true,"include_proto":true},{"addr":"0x736930","include_decompile":true,"include_proto":true},{"addr":"0x736960","include_decompile":true,"include_proto":true},{"addr":"0x736990","include_decompile":true,"include_proto":true},{"addr":"0x7369c0","include_decompile":true,"include_proto":true},{"addr":"0x7369f0","include_decompile":true,"include_proto":true},{"addr":"0x736a20","include_decompile":true,"include_proto":true},{"addr":"0x736a50","include_decompile":true,"include_proto":true},{"addr":"0x736a80","include_decompile":true,"include_proto":true},{"addr":"0x736ab0","include_decompile":true,"include_proto":true},{"addr":"0x736ae0","include_decompile":true,"include_proto":true},{"addr":"0x736b10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0135', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0135: empty response'); return; }
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
      console.log('Batch 0135: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0135 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0135 conn error:', e.message));
req.write(body);
req.end();
