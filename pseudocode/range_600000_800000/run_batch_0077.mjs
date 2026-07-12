
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x68e170","include_decompile":true,"include_proto":true},{"addr":"0x68e2f0","include_decompile":true,"include_proto":true},{"addr":"0x68e300","include_decompile":true,"include_proto":true},{"addr":"0x68e360","include_decompile":true,"include_proto":true},{"addr":"0x68e370","include_decompile":true,"include_proto":true},{"addr":"0x68e3e0","include_decompile":true,"include_proto":true},{"addr":"0x68e3f0","include_decompile":true,"include_proto":true},{"addr":"0x68e430","include_decompile":true,"include_proto":true},{"addr":"0x68e4b0","include_decompile":true,"include_proto":true},{"addr":"0x68e4c0","include_decompile":true,"include_proto":true},{"addr":"0x68e4d0","include_decompile":true,"include_proto":true},{"addr":"0x68e540","include_decompile":true,"include_proto":true},{"addr":"0x68e580","include_decompile":true,"include_proto":true},{"addr":"0x68e620","include_decompile":true,"include_proto":true},{"addr":"0x68e6b0","include_decompile":true,"include_proto":true},{"addr":"0x68e6e0","include_decompile":true,"include_proto":true},{"addr":"0x68e730","include_decompile":true,"include_proto":true},{"addr":"0x68e870","include_decompile":true,"include_proto":true},{"addr":"0x68f580","include_decompile":true,"include_proto":true},{"addr":"0x68f780","include_decompile":true,"include_proto":true},{"addr":"0x68f790","include_decompile":true,"include_proto":true},{"addr":"0x68f830","include_decompile":true,"include_proto":true},{"addr":"0x68f850","include_decompile":true,"include_proto":true},{"addr":"0x68f870","include_decompile":true,"include_proto":true},{"addr":"0x68f890","include_decompile":true,"include_proto":true},{"addr":"0x68fa70","include_decompile":true,"include_proto":true},{"addr":"0x68fac0","include_decompile":true,"include_proto":true},{"addr":"0x68fb30","include_decompile":true,"include_proto":true},{"addr":"0x68fb60","include_decompile":true,"include_proto":true},{"addr":"0x68fc80","include_decompile":true,"include_proto":true},{"addr":"0x68fca0","include_decompile":true,"include_proto":true},{"addr":"0x68fe70","include_decompile":true,"include_proto":true},{"addr":"0x68fec0","include_decompile":true,"include_proto":true},{"addr":"0x68ffe0","include_decompile":true,"include_proto":true},{"addr":"0x690090","include_decompile":true,"include_proto":true},{"addr":"0x6900e0","include_decompile":true,"include_proto":true},{"addr":"0x690130","include_decompile":true,"include_proto":true},{"addr":"0x6905a0","include_decompile":true,"include_proto":true},{"addr":"0x6905d0","include_decompile":true,"include_proto":true},{"addr":"0x6905f0","include_decompile":true,"include_proto":true},{"addr":"0x6906c0","include_decompile":true,"include_proto":true},{"addr":"0x690730","include_decompile":true,"include_proto":true},{"addr":"0x690740","include_decompile":true,"include_proto":true},{"addr":"0x690760","include_decompile":true,"include_proto":true},{"addr":"0x690770","include_decompile":true,"include_proto":true},{"addr":"0x690790","include_decompile":true,"include_proto":true},{"addr":"0x6907e0","include_decompile":true,"include_proto":true},{"addr":"0x690800","include_decompile":true,"include_proto":true},{"addr":"0x690890","include_decompile":true,"include_proto":true},{"addr":"0x690920","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0077', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0077: empty response'); return; }
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
      console.log('Batch 0077: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0077 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0077 conn error:', e.message));
req.write(body);
req.end();
