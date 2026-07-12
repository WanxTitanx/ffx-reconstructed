
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x771300","include_decompile":true,"include_proto":true},{"addr":"0x771320","include_decompile":true,"include_proto":true},{"addr":"0x771350","include_decompile":true,"include_proto":true},{"addr":"0x771370","include_decompile":true,"include_proto":true},{"addr":"0x771390","include_decompile":true,"include_proto":true},{"addr":"0x7713c0","include_decompile":true,"include_proto":true},{"addr":"0x7713e0","include_decompile":true,"include_proto":true},{"addr":"0x771410","include_decompile":true,"include_proto":true},{"addr":"0x771430","include_decompile":true,"include_proto":true},{"addr":"0x771460","include_decompile":true,"include_proto":true},{"addr":"0x771480","include_decompile":true,"include_proto":true},{"addr":"0x7714b0","include_decompile":true,"include_proto":true},{"addr":"0x7714d0","include_decompile":true,"include_proto":true},{"addr":"0x771500","include_decompile":true,"include_proto":true},{"addr":"0x771520","include_decompile":true,"include_proto":true},{"addr":"0x771540","include_decompile":true,"include_proto":true},{"addr":"0x771570","include_decompile":true,"include_proto":true},{"addr":"0x771590","include_decompile":true,"include_proto":true},{"addr":"0x7715c0","include_decompile":true,"include_proto":true},{"addr":"0x7715e0","include_decompile":true,"include_proto":true},{"addr":"0x771610","include_decompile":true,"include_proto":true},{"addr":"0x771630","include_decompile":true,"include_proto":true},{"addr":"0x771660","include_decompile":true,"include_proto":true},{"addr":"0x771680","include_decompile":true,"include_proto":true},{"addr":"0x7716b0","include_decompile":true,"include_proto":true},{"addr":"0x7716d0","include_decompile":true,"include_proto":true},{"addr":"0x7716f0","include_decompile":true,"include_proto":true},{"addr":"0x771720","include_decompile":true,"include_proto":true},{"addr":"0x771740","include_decompile":true,"include_proto":true},{"addr":"0x771770","include_decompile":true,"include_proto":true},{"addr":"0x771790","include_decompile":true,"include_proto":true},{"addr":"0x7717c0","include_decompile":true,"include_proto":true},{"addr":"0x7717e0","include_decompile":true,"include_proto":true},{"addr":"0x771810","include_decompile":true,"include_proto":true},{"addr":"0x771830","include_decompile":true,"include_proto":true},{"addr":"0x771860","include_decompile":true,"include_proto":true},{"addr":"0x771880","include_decompile":true,"include_proto":true},{"addr":"0x7718a0","include_decompile":true,"include_proto":true},{"addr":"0x7718d0","include_decompile":true,"include_proto":true},{"addr":"0x7718f0","include_decompile":true,"include_proto":true},{"addr":"0x771920","include_decompile":true,"include_proto":true},{"addr":"0x771940","include_decompile":true,"include_proto":true},{"addr":"0x771970","include_decompile":true,"include_proto":true},{"addr":"0x771990","include_decompile":true,"include_proto":true},{"addr":"0x7719c0","include_decompile":true,"include_proto":true},{"addr":"0x7719e0","include_decompile":true,"include_proto":true},{"addr":"0x771a10","include_decompile":true,"include_proto":true},{"addr":"0x771a30","include_decompile":true,"include_proto":true},{"addr":"0x771a50","include_decompile":true,"include_proto":true},{"addr":"0x771a80","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0151', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0151: empty response'); return; }
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
      console.log('Batch 0151: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0151 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0151 conn error:', e.message));
req.write(body);
req.end();
