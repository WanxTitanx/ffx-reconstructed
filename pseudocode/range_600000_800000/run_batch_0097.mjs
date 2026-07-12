
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6bf6d0","include_decompile":true,"include_proto":true},{"addr":"0x6bf730","include_decompile":true,"include_proto":true},{"addr":"0x6bf790","include_decompile":true,"include_proto":true},{"addr":"0x6bf7f0","include_decompile":true,"include_proto":true},{"addr":"0x6bf870","include_decompile":true,"include_proto":true},{"addr":"0x6bf8e0","include_decompile":true,"include_proto":true},{"addr":"0x6bf950","include_decompile":true,"include_proto":true},{"addr":"0x6bf9d0","include_decompile":true,"include_proto":true},{"addr":"0x6bfa40","include_decompile":true,"include_proto":true},{"addr":"0x6bfab0","include_decompile":true,"include_proto":true},{"addr":"0x6bfb00","include_decompile":true,"include_proto":true},{"addr":"0x6bfb70","include_decompile":true,"include_proto":true},{"addr":"0x6bfbe0","include_decompile":true,"include_proto":true},{"addr":"0x6bfd10","include_decompile":true,"include_proto":true},{"addr":"0x6bfd20","include_decompile":true,"include_proto":true},{"addr":"0x6bfd30","include_decompile":true,"include_proto":true},{"addr":"0x6bfd40","include_decompile":true,"include_proto":true},{"addr":"0x6bfe50","include_decompile":true,"include_proto":true},{"addr":"0x6bfed0","include_decompile":true,"include_proto":true},{"addr":"0x6bffb0","include_decompile":true,"include_proto":true},{"addr":"0x6bffc0","include_decompile":true,"include_proto":true},{"addr":"0x6bffd0","include_decompile":true,"include_proto":true},{"addr":"0x6c05d0","include_decompile":true,"include_proto":true},{"addr":"0x6c05e0","include_decompile":true,"include_proto":true},{"addr":"0x6c05f0","include_decompile":true,"include_proto":true},{"addr":"0x6c0620","include_decompile":true,"include_proto":true},{"addr":"0x6c0660","include_decompile":true,"include_proto":true},{"addr":"0x6c06a0","include_decompile":true,"include_proto":true},{"addr":"0x6c07e0","include_decompile":true,"include_proto":true},{"addr":"0x6c07f0","include_decompile":true,"include_proto":true},{"addr":"0x6c0800","include_decompile":true,"include_proto":true},{"addr":"0x6c0810","include_decompile":true,"include_proto":true},{"addr":"0x6c0820","include_decompile":true,"include_proto":true},{"addr":"0x6c0950","include_decompile":true,"include_proto":true},{"addr":"0x6c09d0","include_decompile":true,"include_proto":true},{"addr":"0x6c0ac0","include_decompile":true,"include_proto":true},{"addr":"0x6c0bb0","include_decompile":true,"include_proto":true},{"addr":"0x6c10e0","include_decompile":true,"include_proto":true},{"addr":"0x6c10f0","include_decompile":true,"include_proto":true},{"addr":"0x6c1100","include_decompile":true,"include_proto":true},{"addr":"0x6c13c0","include_decompile":true,"include_proto":true},{"addr":"0x6c1460","include_decompile":true,"include_proto":true},{"addr":"0x6c1520","include_decompile":true,"include_proto":true},{"addr":"0x6c1560","include_decompile":true,"include_proto":true},{"addr":"0x6c15e0","include_decompile":true,"include_proto":true},{"addr":"0x6c1600","include_decompile":true,"include_proto":true},{"addr":"0x6c1610","include_decompile":true,"include_proto":true},{"addr":"0x6c1660","include_decompile":true,"include_proto":true},{"addr":"0x6c1af0","include_decompile":true,"include_proto":true},{"addr":"0x6c1d90","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0097', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0097: empty response'); return; }
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
      console.log('Batch 0097: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0097 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0097 conn error:', e.message));
req.write(body);
req.end();
