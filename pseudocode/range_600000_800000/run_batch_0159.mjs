
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x777520","include_decompile":true,"include_proto":true},{"addr":"0x777540","include_decompile":true,"include_proto":true},{"addr":"0x7776e0","include_decompile":true,"include_proto":true},{"addr":"0x777710","include_decompile":true,"include_proto":true},{"addr":"0x777780","include_decompile":true,"include_proto":true},{"addr":"0x7777a0","include_decompile":true,"include_proto":true},{"addr":"0x777a40","include_decompile":true,"include_proto":true},{"addr":"0x777a70","include_decompile":true,"include_proto":true},{"addr":"0x777a80","include_decompile":true,"include_proto":true},{"addr":"0x777f80","include_decompile":true,"include_proto":true},{"addr":"0x777f90","include_decompile":true,"include_proto":true},{"addr":"0x777fb0","include_decompile":true,"include_proto":true},{"addr":"0x777ff0","include_decompile":true,"include_proto":true},{"addr":"0x778640","include_decompile":true,"include_proto":true},{"addr":"0x7786d0","include_decompile":true,"include_proto":true},{"addr":"0x778700","include_decompile":true,"include_proto":true},{"addr":"0x7787e0","include_decompile":true,"include_proto":true},{"addr":"0x7788a0","include_decompile":true,"include_proto":true},{"addr":"0x7788b0","include_decompile":true,"include_proto":true},{"addr":"0x778a50","include_decompile":true,"include_proto":true},{"addr":"0x778a70","include_decompile":true,"include_proto":true},{"addr":"0x778a90","include_decompile":true,"include_proto":true},{"addr":"0x778ac0","include_decompile":true,"include_proto":true},{"addr":"0x778ad0","include_decompile":true,"include_proto":true},{"addr":"0x778b00","include_decompile":true,"include_proto":true},{"addr":"0x778e60","include_decompile":true,"include_proto":true},{"addr":"0x779050","include_decompile":true,"include_proto":true},{"addr":"0x7790a0","include_decompile":true,"include_proto":true},{"addr":"0x7790f0","include_decompile":true,"include_proto":true},{"addr":"0x779210","include_decompile":true,"include_proto":true},{"addr":"0x779290","include_decompile":true,"include_proto":true},{"addr":"0x779380","include_decompile":true,"include_proto":true},{"addr":"0x7793b0","include_decompile":true,"include_proto":true},{"addr":"0x7793d0","include_decompile":true,"include_proto":true},{"addr":"0x779490","include_decompile":true,"include_proto":true},{"addr":"0x7794a0","include_decompile":true,"include_proto":true},{"addr":"0x7794b0","include_decompile":true,"include_proto":true},{"addr":"0x779540","include_decompile":true,"include_proto":true},{"addr":"0x779580","include_decompile":true,"include_proto":true},{"addr":"0x779650","include_decompile":true,"include_proto":true},{"addr":"0x779660","include_decompile":true,"include_proto":true},{"addr":"0x779680","include_decompile":true,"include_proto":true},{"addr":"0x7796a0","include_decompile":true,"include_proto":true},{"addr":"0x779820","include_decompile":true,"include_proto":true},{"addr":"0x779970","include_decompile":true,"include_proto":true},{"addr":"0x7799a0","include_decompile":true,"include_proto":true},{"addr":"0x779b70","include_decompile":true,"include_proto":true},{"addr":"0x779bc0","include_decompile":true,"include_proto":true},{"addr":"0x779cd0","include_decompile":true,"include_proto":true},{"addr":"0x779d90","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0159', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0159: empty response'); return; }
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
      console.log('Batch 0159: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0159 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0159 conn error:', e.message));
req.write(body);
req.end();
