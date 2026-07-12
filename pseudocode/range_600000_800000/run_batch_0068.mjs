
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6786e0","include_decompile":true,"include_proto":true},{"addr":"0x678710","include_decompile":true,"include_proto":true},{"addr":"0x678730","include_decompile":true,"include_proto":true},{"addr":"0x678810","include_decompile":true,"include_proto":true},{"addr":"0x6788f0","include_decompile":true,"include_proto":true},{"addr":"0x678900","include_decompile":true,"include_proto":true},{"addr":"0x678910","include_decompile":true,"include_proto":true},{"addr":"0x678920","include_decompile":true,"include_proto":true},{"addr":"0x678930","include_decompile":true,"include_proto":true},{"addr":"0x678940","include_decompile":true,"include_proto":true},{"addr":"0x678a70","include_decompile":true,"include_proto":true},{"addr":"0x678a90","include_decompile":true,"include_proto":true},{"addr":"0x678af0","include_decompile":true,"include_proto":true},{"addr":"0x678b70","include_decompile":true,"include_proto":true},{"addr":"0x678ba0","include_decompile":true,"include_proto":true},{"addr":"0x678cc0","include_decompile":true,"include_proto":true},{"addr":"0x678cf0","include_decompile":true,"include_proto":true},{"addr":"0x678d00","include_decompile":true,"include_proto":true},{"addr":"0x678d10","include_decompile":true,"include_proto":true},{"addr":"0x678d30","include_decompile":true,"include_proto":true},{"addr":"0x678d50","include_decompile":true,"include_proto":true},{"addr":"0x678d80","include_decompile":true,"include_proto":true},{"addr":"0x678f20","include_decompile":true,"include_proto":true},{"addr":"0x678f60","include_decompile":true,"include_proto":true},{"addr":"0x678f90","include_decompile":true,"include_proto":true},{"addr":"0x679000","include_decompile":true,"include_proto":true},{"addr":"0x679010","include_decompile":true,"include_proto":true},{"addr":"0x679270","include_decompile":true,"include_proto":true},{"addr":"0x6794c0","include_decompile":true,"include_proto":true},{"addr":"0x679510","include_decompile":true,"include_proto":true},{"addr":"0x679560","include_decompile":true,"include_proto":true},{"addr":"0x679570","include_decompile":true,"include_proto":true},{"addr":"0x679580","include_decompile":true,"include_proto":true},{"addr":"0x679590","include_decompile":true,"include_proto":true},{"addr":"0x6796a0","include_decompile":true,"include_proto":true},{"addr":"0x6796b0","include_decompile":true,"include_proto":true},{"addr":"0x6796c0","include_decompile":true,"include_proto":true},{"addr":"0x679710","include_decompile":true,"include_proto":true},{"addr":"0x679720","include_decompile":true,"include_proto":true},{"addr":"0x679740","include_decompile":true,"include_proto":true},{"addr":"0x679760","include_decompile":true,"include_proto":true},{"addr":"0x6798a0","include_decompile":true,"include_proto":true},{"addr":"0x6798c0","include_decompile":true,"include_proto":true},{"addr":"0x6798e0","include_decompile":true,"include_proto":true},{"addr":"0x6799b0","include_decompile":true,"include_proto":true},{"addr":"0x6799d0","include_decompile":true,"include_proto":true},{"addr":"0x679bb0","include_decompile":true,"include_proto":true},{"addr":"0x679bc0","include_decompile":true,"include_proto":true},{"addr":"0x679c80","include_decompile":true,"include_proto":true},{"addr":"0x679d60","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0068', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0068: empty response'); return; }
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
      console.log('Batch 0068: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0068 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0068 conn error:', e.message));
req.write(body);
req.end();
