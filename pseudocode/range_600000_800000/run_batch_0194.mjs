
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7bd3a0","include_decompile":true,"include_proto":true},{"addr":"0x7bd3f0","include_decompile":true,"include_proto":true},{"addr":"0x7bd430","include_decompile":true,"include_proto":true},{"addr":"0x7bd480","include_decompile":true,"include_proto":true},{"addr":"0x7bd490","include_decompile":true,"include_proto":true},{"addr":"0x7bd4e0","include_decompile":true,"include_proto":true},{"addr":"0x7bd550","include_decompile":true,"include_proto":true},{"addr":"0x7bd7e0","include_decompile":true,"include_proto":true},{"addr":"0x7bda00","include_decompile":true,"include_proto":true},{"addr":"0x7bdca0","include_decompile":true,"include_proto":true},{"addr":"0x7bdd60","include_decompile":true,"include_proto":true},{"addr":"0x7bddd0","include_decompile":true,"include_proto":true},{"addr":"0x7bdf10","include_decompile":true,"include_proto":true},{"addr":"0x7be020","include_decompile":true,"include_proto":true},{"addr":"0x7be080","include_decompile":true,"include_proto":true},{"addr":"0x7be090","include_decompile":true,"include_proto":true},{"addr":"0x7bea60","include_decompile":true,"include_proto":true},{"addr":"0x7bec10","include_decompile":true,"include_proto":true},{"addr":"0x7bec90","include_decompile":true,"include_proto":true},{"addr":"0x7bece0","include_decompile":true,"include_proto":true},{"addr":"0x7bee30","include_decompile":true,"include_proto":true},{"addr":"0x7bef40","include_decompile":true,"include_proto":true},{"addr":"0x7bf030","include_decompile":true,"include_proto":true},{"addr":"0x7bf120","include_decompile":true,"include_proto":true},{"addr":"0x7bf170","include_decompile":true,"include_proto":true},{"addr":"0x7bf200","include_decompile":true,"include_proto":true},{"addr":"0x7bf2b0","include_decompile":true,"include_proto":true},{"addr":"0x7bf3a0","include_decompile":true,"include_proto":true},{"addr":"0x7bf4a0","include_decompile":true,"include_proto":true},{"addr":"0x7bf580","include_decompile":true,"include_proto":true},{"addr":"0x7bf680","include_decompile":true,"include_proto":true},{"addr":"0x7bf770","include_decompile":true,"include_proto":true},{"addr":"0x7bf8c0","include_decompile":true,"include_proto":true},{"addr":"0x7bfa00","include_decompile":true,"include_proto":true},{"addr":"0x7bfb50","include_decompile":true,"include_proto":true},{"addr":"0x7bfc20","include_decompile":true,"include_proto":true},{"addr":"0x7bfd10","include_decompile":true,"include_proto":true},{"addr":"0x7bfdf0","include_decompile":true,"include_proto":true},{"addr":"0x7bfe90","include_decompile":true,"include_proto":true},{"addr":"0x7bff90","include_decompile":true,"include_proto":true},{"addr":"0x7bfff0","include_decompile":true,"include_proto":true},{"addr":"0x7c00a0","include_decompile":true,"include_proto":true},{"addr":"0x7c0430","include_decompile":true,"include_proto":true},{"addr":"0x7c0440","include_decompile":true,"include_proto":true},{"addr":"0x7c04c0","include_decompile":true,"include_proto":true},{"addr":"0x7c04e0","include_decompile":true,"include_proto":true},{"addr":"0x7c05d0","include_decompile":true,"include_proto":true},{"addr":"0x7c0650","include_decompile":true,"include_proto":true},{"addr":"0x7c0710","include_decompile":true,"include_proto":true},{"addr":"0x7c0890","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0194', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0194: empty response'); return; }
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
      console.log('Batch 0194: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0194 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0194 conn error:', e.message));
req.write(body);
req.end();
