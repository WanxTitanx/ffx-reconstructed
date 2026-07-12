
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x648210","include_decompile":true,"include_proto":true},{"addr":"0x648220","include_decompile":true,"include_proto":true},{"addr":"0x648240","include_decompile":true,"include_proto":true},{"addr":"0x648250","include_decompile":true,"include_proto":true},{"addr":"0x648270","include_decompile":true,"include_proto":true},{"addr":"0x648280","include_decompile":true,"include_proto":true},{"addr":"0x648290","include_decompile":true,"include_proto":true},{"addr":"0x6482a0","include_decompile":true,"include_proto":true},{"addr":"0x6482b0","include_decompile":true,"include_proto":true},{"addr":"0x648300","include_decompile":true,"include_proto":true},{"addr":"0x6484b0","include_decompile":true,"include_proto":true},{"addr":"0x648520","include_decompile":true,"include_proto":true},{"addr":"0x648630","include_decompile":true,"include_proto":true},{"addr":"0x648680","include_decompile":true,"include_proto":true},{"addr":"0x6486e0","include_decompile":true,"include_proto":true},{"addr":"0x6486f0","include_decompile":true,"include_proto":true},{"addr":"0x6487d0","include_decompile":true,"include_proto":true},{"addr":"0x6487e0","include_decompile":true,"include_proto":true},{"addr":"0x6487f0","include_decompile":true,"include_proto":true},{"addr":"0x648860","include_decompile":true,"include_proto":true},{"addr":"0x648870","include_decompile":true,"include_proto":true},{"addr":"0x648890","include_decompile":true,"include_proto":true},{"addr":"0x6488c0","include_decompile":true,"include_proto":true},{"addr":"0x648910","include_decompile":true,"include_proto":true},{"addr":"0x648950","include_decompile":true,"include_proto":true},{"addr":"0x648a00","include_decompile":true,"include_proto":true},{"addr":"0x648a70","include_decompile":true,"include_proto":true},{"addr":"0x648ac0","include_decompile":true,"include_proto":true},{"addr":"0x648ad0","include_decompile":true,"include_proto":true},{"addr":"0x6490d0","include_decompile":true,"include_proto":true},{"addr":"0x649110","include_decompile":true,"include_proto":true},{"addr":"0x6491a0","include_decompile":true,"include_proto":true},{"addr":"0x6491c0","include_decompile":true,"include_proto":true},{"addr":"0x6491f0","include_decompile":true,"include_proto":true},{"addr":"0x649460","include_decompile":true,"include_proto":true},{"addr":"0x649470","include_decompile":true,"include_proto":true},{"addr":"0x649490","include_decompile":true,"include_proto":true},{"addr":"0x6495d0","include_decompile":true,"include_proto":true},{"addr":"0x6495e0","include_decompile":true,"include_proto":true},{"addr":"0x649670","include_decompile":true,"include_proto":true},{"addr":"0x649680","include_decompile":true,"include_proto":true},{"addr":"0x6496f0","include_decompile":true,"include_proto":true},{"addr":"0x649760","include_decompile":true,"include_proto":true},{"addr":"0x649880","include_decompile":true,"include_proto":true},{"addr":"0x6499d0","include_decompile":true,"include_proto":true},{"addr":"0x6499e0","include_decompile":true,"include_proto":true},{"addr":"0x649c10","include_decompile":true,"include_proto":true},{"addr":"0x649cc0","include_decompile":true,"include_proto":true},{"addr":"0x649ce0","include_decompile":true,"include_proto":true},{"addr":"0x649d80","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0046', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0046: empty response'); return; }
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
      console.log('Batch 0046: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0046 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0046 conn error:', e.message));
req.write(body);
req.end();
