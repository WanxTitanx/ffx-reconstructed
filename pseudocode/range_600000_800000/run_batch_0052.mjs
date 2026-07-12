
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x64f4e0","include_decompile":true,"include_proto":true},{"addr":"0x64f510","include_decompile":true,"include_proto":true},{"addr":"0x64f590","include_decompile":true,"include_proto":true},{"addr":"0x64f5f0","include_decompile":true,"include_proto":true},{"addr":"0x64f700","include_decompile":true,"include_proto":true},{"addr":"0x64f790","include_decompile":true,"include_proto":true},{"addr":"0x64f9a0","include_decompile":true,"include_proto":true},{"addr":"0x64fa10","include_decompile":true,"include_proto":true},{"addr":"0x64fa80","include_decompile":true,"include_proto":true},{"addr":"0x64fb20","include_decompile":true,"include_proto":true},{"addr":"0x64fc00","include_decompile":true,"include_proto":true},{"addr":"0x64fc20","include_decompile":true,"include_proto":true},{"addr":"0x64fc50","include_decompile":true,"include_proto":true},{"addr":"0x64fd60","include_decompile":true,"include_proto":true},{"addr":"0x6504f0","include_decompile":true,"include_proto":true},{"addr":"0x650820","include_decompile":true,"include_proto":true},{"addr":"0x650980","include_decompile":true,"include_proto":true},{"addr":"0x650e60","include_decompile":true,"include_proto":true},{"addr":"0x651050","include_decompile":true,"include_proto":true},{"addr":"0x651130","include_decompile":true,"include_proto":true},{"addr":"0x651220","include_decompile":true,"include_proto":true},{"addr":"0x6515a0","include_decompile":true,"include_proto":true},{"addr":"0x6515b0","include_decompile":true,"include_proto":true},{"addr":"0x651610","include_decompile":true,"include_proto":true},{"addr":"0x651690","include_decompile":true,"include_proto":true},{"addr":"0x6516d0","include_decompile":true,"include_proto":true},{"addr":"0x651720","include_decompile":true,"include_proto":true},{"addr":"0x651730","include_decompile":true,"include_proto":true},{"addr":"0x651740","include_decompile":true,"include_proto":true},{"addr":"0x651750","include_decompile":true,"include_proto":true},{"addr":"0x651760","include_decompile":true,"include_proto":true},{"addr":"0x651780","include_decompile":true,"include_proto":true},{"addr":"0x651790","include_decompile":true,"include_proto":true},{"addr":"0x6517a0","include_decompile":true,"include_proto":true},{"addr":"0x6517b0","include_decompile":true,"include_proto":true},{"addr":"0x6517c0","include_decompile":true,"include_proto":true},{"addr":"0x6517d0","include_decompile":true,"include_proto":true},{"addr":"0x6517e0","include_decompile":true,"include_proto":true},{"addr":"0x6517f0","include_decompile":true,"include_proto":true},{"addr":"0x651800","include_decompile":true,"include_proto":true},{"addr":"0x651980","include_decompile":true,"include_proto":true},{"addr":"0x651990","include_decompile":true,"include_proto":true},{"addr":"0x6519a0","include_decompile":true,"include_proto":true},{"addr":"0x6519b0","include_decompile":true,"include_proto":true},{"addr":"0x651a70","include_decompile":true,"include_proto":true},{"addr":"0x651ba0","include_decompile":true,"include_proto":true},{"addr":"0x651d90","include_decompile":true,"include_proto":true},{"addr":"0x651f90","include_decompile":true,"include_proto":true},{"addr":"0x652460","include_decompile":true,"include_proto":true},{"addr":"0x652470","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0052', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0052: empty response'); return; }
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
      console.log('Batch 0052: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0052 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0052 conn error:', e.message));
req.write(body);
req.end();
