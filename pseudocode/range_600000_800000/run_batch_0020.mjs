
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x621a70","include_decompile":true,"include_proto":true},{"addr":"0x621aa0","include_decompile":true,"include_proto":true},{"addr":"0x621ad0","include_decompile":true,"include_proto":true},{"addr":"0x621b00","include_decompile":true,"include_proto":true},{"addr":"0x621b30","include_decompile":true,"include_proto":true},{"addr":"0x621b60","include_decompile":true,"include_proto":true},{"addr":"0x621bc0","include_decompile":true,"include_proto":true},{"addr":"0x621bf0","include_decompile":true,"include_proto":true},{"addr":"0x621c90","include_decompile":true,"include_proto":true},{"addr":"0x621cc0","include_decompile":true,"include_proto":true},{"addr":"0x621d60","include_decompile":true,"include_proto":true},{"addr":"0x621d90","include_decompile":true,"include_proto":true},{"addr":"0x621dc0","include_decompile":true,"include_proto":true},{"addr":"0x621e40","include_decompile":true,"include_proto":true},{"addr":"0x621e70","include_decompile":true,"include_proto":true},{"addr":"0x621f10","include_decompile":true,"include_proto":true},{"addr":"0x621f90","include_decompile":true,"include_proto":true},{"addr":"0x622030","include_decompile":true,"include_proto":true},{"addr":"0x6220b0","include_decompile":true,"include_proto":true},{"addr":"0x622210","include_decompile":true,"include_proto":true},{"addr":"0x622970","include_decompile":true,"include_proto":true},{"addr":"0x622d20","include_decompile":true,"include_proto":true},{"addr":"0x622f00","include_decompile":true,"include_proto":true},{"addr":"0x623090","include_decompile":true,"include_proto":true},{"addr":"0x623220","include_decompile":true,"include_proto":true},{"addr":"0x623380","include_decompile":true,"include_proto":true},{"addr":"0x623390","include_decompile":true,"include_proto":true},{"addr":"0x6233a0","include_decompile":true,"include_proto":true},{"addr":"0x6233e0","include_decompile":true,"include_proto":true},{"addr":"0x6234d0","include_decompile":true,"include_proto":true},{"addr":"0x6234f0","include_decompile":true,"include_proto":true},{"addr":"0x623560","include_decompile":true,"include_proto":true},{"addr":"0x623620","include_decompile":true,"include_proto":true},{"addr":"0x623630","include_decompile":true,"include_proto":true},{"addr":"0x623740","include_decompile":true,"include_proto":true},{"addr":"0x623790","include_decompile":true,"include_proto":true},{"addr":"0x623820","include_decompile":true,"include_proto":true},{"addr":"0x6239a0","include_decompile":true,"include_proto":true},{"addr":"0x623a70","include_decompile":true,"include_proto":true},{"addr":"0x623b50","include_decompile":true,"include_proto":true},{"addr":"0x623c30","include_decompile":true,"include_proto":true},{"addr":"0x623d10","include_decompile":true,"include_proto":true},{"addr":"0x623d20","include_decompile":true,"include_proto":true},{"addr":"0x623d30","include_decompile":true,"include_proto":true},{"addr":"0x623d40","include_decompile":true,"include_proto":true},{"addr":"0x623d50","include_decompile":true,"include_proto":true},{"addr":"0x623d60","include_decompile":true,"include_proto":true},{"addr":"0x623da0","include_decompile":true,"include_proto":true},{"addr":"0x623db0","include_decompile":true,"include_proto":true},{"addr":"0x623dc0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0020', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0020: empty response'); return; }
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
      console.log('Batch 0020: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0020 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0020 conn error:', e.message));
req.write(body);
req.end();
