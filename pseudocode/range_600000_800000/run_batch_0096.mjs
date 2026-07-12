
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6bc480","include_decompile":true,"include_proto":true},{"addr":"0x6bc550","include_decompile":true,"include_proto":true},{"addr":"0x6bc5c0","include_decompile":true,"include_proto":true},{"addr":"0x6bc890","include_decompile":true,"include_proto":true},{"addr":"0x6bc990","include_decompile":true,"include_proto":true},{"addr":"0x6bcaa0","include_decompile":true,"include_proto":true},{"addr":"0x6bcab0","include_decompile":true,"include_proto":true},{"addr":"0x6bcad0","include_decompile":true,"include_proto":true},{"addr":"0x6bcb70","include_decompile":true,"include_proto":true},{"addr":"0x6bcb80","include_decompile":true,"include_proto":true},{"addr":"0x6bcb90","include_decompile":true,"include_proto":true},{"addr":"0x6bcbd0","include_decompile":true,"include_proto":true},{"addr":"0x6bccf0","include_decompile":true,"include_proto":true},{"addr":"0x6bcd00","include_decompile":true,"include_proto":true},{"addr":"0x6bcd10","include_decompile":true,"include_proto":true},{"addr":"0x6bcd80","include_decompile":true,"include_proto":true},{"addr":"0x6bcdb0","include_decompile":true,"include_proto":true},{"addr":"0x6bcdd0","include_decompile":true,"include_proto":true},{"addr":"0x6bcde0","include_decompile":true,"include_proto":true},{"addr":"0x6bcdf0","include_decompile":true,"include_proto":true},{"addr":"0x6bcea0","include_decompile":true,"include_proto":true},{"addr":"0x6bceb0","include_decompile":true,"include_proto":true},{"addr":"0x6bcec0","include_decompile":true,"include_proto":true},{"addr":"0x6bcf40","include_decompile":true,"include_proto":true},{"addr":"0x6bd290","include_decompile":true,"include_proto":true},{"addr":"0x6bd2a0","include_decompile":true,"include_proto":true},{"addr":"0x6bd320","include_decompile":true,"include_proto":true},{"addr":"0x6bd3d0","include_decompile":true,"include_proto":true},{"addr":"0x6bd5a0","include_decompile":true,"include_proto":true},{"addr":"0x6bd610","include_decompile":true,"include_proto":true},{"addr":"0x6bdae0","include_decompile":true,"include_proto":true},{"addr":"0x6bdf70","include_decompile":true,"include_proto":true},{"addr":"0x6be530","include_decompile":true,"include_proto":true},{"addr":"0x6be840","include_decompile":true,"include_proto":true},{"addr":"0x6be890","include_decompile":true,"include_proto":true},{"addr":"0x6beaa0","include_decompile":true,"include_proto":true},{"addr":"0x6beb20","include_decompile":true,"include_proto":true},{"addr":"0x6bec50","include_decompile":true,"include_proto":true},{"addr":"0x6bede0","include_decompile":true,"include_proto":true},{"addr":"0x6bee70","include_decompile":true,"include_proto":true},{"addr":"0x6beee0","include_decompile":true,"include_proto":true},{"addr":"0x6bef50","include_decompile":true,"include_proto":true},{"addr":"0x6befc0","include_decompile":true,"include_proto":true},{"addr":"0x6bf140","include_decompile":true,"include_proto":true},{"addr":"0x6bf1b0","include_decompile":true,"include_proto":true},{"addr":"0x6bf2b0","include_decompile":true,"include_proto":true},{"addr":"0x6bf3e0","include_decompile":true,"include_proto":true},{"addr":"0x6bf4a0","include_decompile":true,"include_proto":true},{"addr":"0x6bf570","include_decompile":true,"include_proto":true},{"addr":"0x6bf5e0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0096', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0096: empty response'); return; }
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
      console.log('Batch 0096: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0096 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0096 conn error:', e.message));
req.write(body);
req.end();
