
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x702e00","include_decompile":true,"include_proto":true},{"addr":"0x702e70","include_decompile":true,"include_proto":true},{"addr":"0x702f70","include_decompile":true,"include_proto":true},{"addr":"0x702fe0","include_decompile":true,"include_proto":true},{"addr":"0x703070","include_decompile":true,"include_proto":true},{"addr":"0x703090","include_decompile":true,"include_proto":true},{"addr":"0x7030e0","include_decompile":true,"include_proto":true},{"addr":"0x703160","include_decompile":true,"include_proto":true},{"addr":"0x7031d0","include_decompile":true,"include_proto":true},{"addr":"0x703320","include_decompile":true,"include_proto":true},{"addr":"0x703560","include_decompile":true,"include_proto":true},{"addr":"0x703570","include_decompile":true,"include_proto":true},{"addr":"0x7036e0","include_decompile":true,"include_proto":true},{"addr":"0x703700","include_decompile":true,"include_proto":true},{"addr":"0x7037e0","include_decompile":true,"include_proto":true},{"addr":"0x703840","include_decompile":true,"include_proto":true},{"addr":"0x703870","include_decompile":true,"include_proto":true},{"addr":"0x7038d0","include_decompile":true,"include_proto":true},{"addr":"0x703910","include_decompile":true,"include_proto":true},{"addr":"0x7039e0","include_decompile":true,"include_proto":true},{"addr":"0x7039f0","include_decompile":true,"include_proto":true},{"addr":"0x703a00","include_decompile":true,"include_proto":true},{"addr":"0x703a50","include_decompile":true,"include_proto":true},{"addr":"0x703a80","include_decompile":true,"include_proto":true},{"addr":"0x703ac0","include_decompile":true,"include_proto":true},{"addr":"0x703b10","include_decompile":true,"include_proto":true},{"addr":"0x703b40","include_decompile":true,"include_proto":true},{"addr":"0x703b80","include_decompile":true,"include_proto":true},{"addr":"0x703bb0","include_decompile":true,"include_proto":true},{"addr":"0x703cb0","include_decompile":true,"include_proto":true},{"addr":"0x703d20","include_decompile":true,"include_proto":true},{"addr":"0x704090","include_decompile":true,"include_proto":true},{"addr":"0x704130","include_decompile":true,"include_proto":true},{"addr":"0x7041d0","include_decompile":true,"include_proto":true},{"addr":"0x7042f0","include_decompile":true,"include_proto":true},{"addr":"0x7045b0","include_decompile":true,"include_proto":true},{"addr":"0x7045f0","include_decompile":true,"include_proto":true},{"addr":"0x704af0","include_decompile":true,"include_proto":true},{"addr":"0x704e20","include_decompile":true,"include_proto":true},{"addr":"0x704e30","include_decompile":true,"include_proto":true},{"addr":"0x704e40","include_decompile":true,"include_proto":true},{"addr":"0x704e50","include_decompile":true,"include_proto":true},{"addr":"0x704e60","include_decompile":true,"include_proto":true},{"addr":"0x704e70","include_decompile":true,"include_proto":true},{"addr":"0x704e80","include_decompile":true,"include_proto":true},{"addr":"0x704e90","include_decompile":true,"include_proto":true},{"addr":"0x704ec0","include_decompile":true,"include_proto":true},{"addr":"0x705940","include_decompile":true,"include_proto":true},{"addr":"0x7059e0","include_decompile":true,"include_proto":true},{"addr":"0x705aa0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0122', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0122: empty response'); return; }
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
      console.log('Batch 0122: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0122 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0122 conn error:', e.message));
req.write(body);
req.end();
