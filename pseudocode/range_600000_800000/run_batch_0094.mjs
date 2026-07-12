
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6b59c0","include_decompile":true,"include_proto":true},{"addr":"0x6b5a80","include_decompile":true,"include_proto":true},{"addr":"0x6b5bc0","include_decompile":true,"include_proto":true},{"addr":"0x6b5d90","include_decompile":true,"include_proto":true},{"addr":"0x6b5e00","include_decompile":true,"include_proto":true},{"addr":"0x6b5e80","include_decompile":true,"include_proto":true},{"addr":"0x6b5f00","include_decompile":true,"include_proto":true},{"addr":"0x6b5f80","include_decompile":true,"include_proto":true},{"addr":"0x6b6000","include_decompile":true,"include_proto":true},{"addr":"0x6b6080","include_decompile":true,"include_proto":true},{"addr":"0x6b6100","include_decompile":true,"include_proto":true},{"addr":"0x6b6180","include_decompile":true,"include_proto":true},{"addr":"0x6b6200","include_decompile":true,"include_proto":true},{"addr":"0x6b6230","include_decompile":true,"include_proto":true},{"addr":"0x6b62c0","include_decompile":true,"include_proto":true},{"addr":"0x6b62f0","include_decompile":true,"include_proto":true},{"addr":"0x6b6320","include_decompile":true,"include_proto":true},{"addr":"0x6b6350","include_decompile":true,"include_proto":true},{"addr":"0x6b6380","include_decompile":true,"include_proto":true},{"addr":"0x6b63b0","include_decompile":true,"include_proto":true},{"addr":"0x6b63e0","include_decompile":true,"include_proto":true},{"addr":"0x6b6410","include_decompile":true,"include_proto":true},{"addr":"0x6b6430","include_decompile":true,"include_proto":true},{"addr":"0x6b6440","include_decompile":true,"include_proto":true},{"addr":"0x6b6450","include_decompile":true,"include_proto":true},{"addr":"0x6b6460","include_decompile":true,"include_proto":true},{"addr":"0x6b6470","include_decompile":true,"include_proto":true},{"addr":"0x6b6480","include_decompile":true,"include_proto":true},{"addr":"0x6b6490","include_decompile":true,"include_proto":true},{"addr":"0x6b64a0","include_decompile":true,"include_proto":true},{"addr":"0x6b64b0","include_decompile":true,"include_proto":true},{"addr":"0x6b64c0","include_decompile":true,"include_proto":true},{"addr":"0x6b64d0","include_decompile":true,"include_proto":true},{"addr":"0x6b6540","include_decompile":true,"include_proto":true},{"addr":"0x6b6550","include_decompile":true,"include_proto":true},{"addr":"0x6b6640","include_decompile":true,"include_proto":true},{"addr":"0x6b6810","include_decompile":true,"include_proto":true},{"addr":"0x6b6870","include_decompile":true,"include_proto":true},{"addr":"0x6b68d0","include_decompile":true,"include_proto":true},{"addr":"0x6b6940","include_decompile":true,"include_proto":true},{"addr":"0x6b6a00","include_decompile":true,"include_proto":true},{"addr":"0x6b6aa0","include_decompile":true,"include_proto":true},{"addr":"0x6b6ab0","include_decompile":true,"include_proto":true},{"addr":"0x6b6ac0","include_decompile":true,"include_proto":true},{"addr":"0x6b6ad0","include_decompile":true,"include_proto":true},{"addr":"0x6b6ae0","include_decompile":true,"include_proto":true},{"addr":"0x6b6cf0","include_decompile":true,"include_proto":true},{"addr":"0x6b7030","include_decompile":true,"include_proto":true},{"addr":"0x6b7140","include_decompile":true,"include_proto":true},{"addr":"0x6b7220","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0094', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0094: empty response'); return; }
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
      console.log('Batch 0094: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0094 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0094 conn error:', e.message));
req.write(body);
req.end();
