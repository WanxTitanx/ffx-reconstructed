
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6168b0","include_decompile":true,"include_proto":true},{"addr":"0x616900","include_decompile":true,"include_proto":true},{"addr":"0x616960","include_decompile":true,"include_proto":true},{"addr":"0x616a30","include_decompile":true,"include_proto":true},{"addr":"0x616a60","include_decompile":true,"include_proto":true},{"addr":"0x616af0","include_decompile":true,"include_proto":true},{"addr":"0x616b70","include_decompile":true,"include_proto":true},{"addr":"0x616b80","include_decompile":true,"include_proto":true},{"addr":"0x616b90","include_decompile":true,"include_proto":true},{"addr":"0x616ba0","include_decompile":true,"include_proto":true},{"addr":"0x616be0","include_decompile":true,"include_proto":true},{"addr":"0x616bf0","include_decompile":true,"include_proto":true},{"addr":"0x616c00","include_decompile":true,"include_proto":true},{"addr":"0x616c60","include_decompile":true,"include_proto":true},{"addr":"0x616cc0","include_decompile":true,"include_proto":true},{"addr":"0x616d50","include_decompile":true,"include_proto":true},{"addr":"0x616df0","include_decompile":true,"include_proto":true},{"addr":"0x616e70","include_decompile":true,"include_proto":true},{"addr":"0x616ed0","include_decompile":true,"include_proto":true},{"addr":"0x616f10","include_decompile":true,"include_proto":true},{"addr":"0x616f20","include_decompile":true,"include_proto":true},{"addr":"0x616f80","include_decompile":true,"include_proto":true},{"addr":"0x617070","include_decompile":true,"include_proto":true},{"addr":"0x6170a0","include_decompile":true,"include_proto":true},{"addr":"0x617190","include_decompile":true,"include_proto":true},{"addr":"0x6172a0","include_decompile":true,"include_proto":true},{"addr":"0x617330","include_decompile":true,"include_proto":true},{"addr":"0x617420","include_decompile":true,"include_proto":true},{"addr":"0x6174d0","include_decompile":true,"include_proto":true},{"addr":"0x617510","include_decompile":true,"include_proto":true},{"addr":"0x617660","include_decompile":true,"include_proto":true},{"addr":"0x617670","include_decompile":true,"include_proto":true},{"addr":"0x617730","include_decompile":true,"include_proto":true},{"addr":"0x617770","include_decompile":true,"include_proto":true},{"addr":"0x617780","include_decompile":true,"include_proto":true},{"addr":"0x617800","include_decompile":true,"include_proto":true},{"addr":"0x617810","include_decompile":true,"include_proto":true},{"addr":"0x617830","include_decompile":true,"include_proto":true},{"addr":"0x6178f0","include_decompile":true,"include_proto":true},{"addr":"0x617900","include_decompile":true,"include_proto":true},{"addr":"0x617a10","include_decompile":true,"include_proto":true},{"addr":"0x617a20","include_decompile":true,"include_proto":true},{"addr":"0x617a30","include_decompile":true,"include_proto":true},{"addr":"0x617a50","include_decompile":true,"include_proto":true},{"addr":"0x617a60","include_decompile":true,"include_proto":true},{"addr":"0x617a90","include_decompile":true,"include_proto":true},{"addr":"0x617ac0","include_decompile":true,"include_proto":true},{"addr":"0x617af0","include_decompile":true,"include_proto":true},{"addr":"0x617b20","include_decompile":true,"include_proto":true},{"addr":"0x617c10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0011', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0011: empty response'); return; }
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
      console.log('Batch 0011: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0011 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0011 conn error:', e.message));
req.write(body);
req.end();
