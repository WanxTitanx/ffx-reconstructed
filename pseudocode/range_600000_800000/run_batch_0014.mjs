
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6196d0","include_decompile":true,"include_proto":true},{"addr":"0x619700","include_decompile":true,"include_proto":true},{"addr":"0x619760","include_decompile":true,"include_proto":true},{"addr":"0x6198a0","include_decompile":true,"include_proto":true},{"addr":"0x619aa0","include_decompile":true,"include_proto":true},{"addr":"0x619b40","include_decompile":true,"include_proto":true},{"addr":"0x619bc0","include_decompile":true,"include_proto":true},{"addr":"0x619ca0","include_decompile":true,"include_proto":true},{"addr":"0x619cb0","include_decompile":true,"include_proto":true},{"addr":"0x619cc0","include_decompile":true,"include_proto":true},{"addr":"0x619cd0","include_decompile":true,"include_proto":true},{"addr":"0x619ce0","include_decompile":true,"include_proto":true},{"addr":"0x619d50","include_decompile":true,"include_proto":true},{"addr":"0x619d60","include_decompile":true,"include_proto":true},{"addr":"0x619d70","include_decompile":true,"include_proto":true},{"addr":"0x619d80","include_decompile":true,"include_proto":true},{"addr":"0x619d90","include_decompile":true,"include_proto":true},{"addr":"0x619da0","include_decompile":true,"include_proto":true},{"addr":"0x619db0","include_decompile":true,"include_proto":true},{"addr":"0x619dc0","include_decompile":true,"include_proto":true},{"addr":"0x619dd0","include_decompile":true,"include_proto":true},{"addr":"0x619de0","include_decompile":true,"include_proto":true},{"addr":"0x619e80","include_decompile":true,"include_proto":true},{"addr":"0x61a040","include_decompile":true,"include_proto":true},{"addr":"0x61a050","include_decompile":true,"include_proto":true},{"addr":"0x61a260","include_decompile":true,"include_proto":true},{"addr":"0x61a270","include_decompile":true,"include_proto":true},{"addr":"0x61a290","include_decompile":true,"include_proto":true},{"addr":"0x61a2b0","include_decompile":true,"include_proto":true},{"addr":"0x61a2d0","include_decompile":true,"include_proto":true},{"addr":"0x61a2e0","include_decompile":true,"include_proto":true},{"addr":"0x61a300","include_decompile":true,"include_proto":true},{"addr":"0x61a310","include_decompile":true,"include_proto":true},{"addr":"0x61a320","include_decompile":true,"include_proto":true},{"addr":"0x61a340","include_decompile":true,"include_proto":true},{"addr":"0x61a350","include_decompile":true,"include_proto":true},{"addr":"0x61a390","include_decompile":true,"include_proto":true},{"addr":"0x61a410","include_decompile":true,"include_proto":true},{"addr":"0x61a430","include_decompile":true,"include_proto":true},{"addr":"0x61a460","include_decompile":true,"include_proto":true},{"addr":"0x61a850","include_decompile":true,"include_proto":true},{"addr":"0x61a8f0","include_decompile":true,"include_proto":true},{"addr":"0x61a900","include_decompile":true,"include_proto":true},{"addr":"0x61a930","include_decompile":true,"include_proto":true},{"addr":"0x61a9b0","include_decompile":true,"include_proto":true},{"addr":"0x61a9d0","include_decompile":true,"include_proto":true},{"addr":"0x61aa10","include_decompile":true,"include_proto":true},{"addr":"0x61aa20","include_decompile":true,"include_proto":true},{"addr":"0x61ab20","include_decompile":true,"include_proto":true},{"addr":"0x61abd0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0014', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0014: empty response'); return; }
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
      console.log('Batch 0014: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0014 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0014 conn error:', e.message));
req.write(body);
req.end();
