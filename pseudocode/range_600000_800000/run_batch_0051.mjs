
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x64d610","include_decompile":true,"include_proto":true},{"addr":"0x64d620","include_decompile":true,"include_proto":true},{"addr":"0x64d630","include_decompile":true,"include_proto":true},{"addr":"0x64d640","include_decompile":true,"include_proto":true},{"addr":"0x64d720","include_decompile":true,"include_proto":true},{"addr":"0x64d7d0","include_decompile":true,"include_proto":true},{"addr":"0x64d880","include_decompile":true,"include_proto":true},{"addr":"0x64d8a0","include_decompile":true,"include_proto":true},{"addr":"0x64d8c0","include_decompile":true,"include_proto":true},{"addr":"0x64d8e0","include_decompile":true,"include_proto":true},{"addr":"0x64d990","include_decompile":true,"include_proto":true},{"addr":"0x64d9b0","include_decompile":true,"include_proto":true},{"addr":"0x64d9d0","include_decompile":true,"include_proto":true},{"addr":"0x64da20","include_decompile":true,"include_proto":true},{"addr":"0x64da40","include_decompile":true,"include_proto":true},{"addr":"0x64da60","include_decompile":true,"include_proto":true},{"addr":"0x64dab0","include_decompile":true,"include_proto":true},{"addr":"0x64dad0","include_decompile":true,"include_proto":true},{"addr":"0x64daf0","include_decompile":true,"include_proto":true},{"addr":"0x64db10","include_decompile":true,"include_proto":true},{"addr":"0x64db30","include_decompile":true,"include_proto":true},{"addr":"0x64db50","include_decompile":true,"include_proto":true},{"addr":"0x64db70","include_decompile":true,"include_proto":true},{"addr":"0x64db90","include_decompile":true,"include_proto":true},{"addr":"0x64dc40","include_decompile":true,"include_proto":true},{"addr":"0x64dc50","include_decompile":true,"include_proto":true},{"addr":"0x64dc70","include_decompile":true,"include_proto":true},{"addr":"0x64dc90","include_decompile":true,"include_proto":true},{"addr":"0x64dd80","include_decompile":true,"include_proto":true},{"addr":"0x64ddb0","include_decompile":true,"include_proto":true},{"addr":"0x64ec80","include_decompile":true,"include_proto":true},{"addr":"0x64ecd0","include_decompile":true,"include_proto":true},{"addr":"0x64edc0","include_decompile":true,"include_proto":true},{"addr":"0x64ede0","include_decompile":true,"include_proto":true},{"addr":"0x64ee00","include_decompile":true,"include_proto":true},{"addr":"0x64ee20","include_decompile":true,"include_proto":true},{"addr":"0x64ee40","include_decompile":true,"include_proto":true},{"addr":"0x64efb0","include_decompile":true,"include_proto":true},{"addr":"0x64efc0","include_decompile":true,"include_proto":true},{"addr":"0x64f0c0","include_decompile":true,"include_proto":true},{"addr":"0x64f0d0","include_decompile":true,"include_proto":true},{"addr":"0x64f180","include_decompile":true,"include_proto":true},{"addr":"0x64f190","include_decompile":true,"include_proto":true},{"addr":"0x64f220","include_decompile":true,"include_proto":true},{"addr":"0x64f230","include_decompile":true,"include_proto":true},{"addr":"0x64f240","include_decompile":true,"include_proto":true},{"addr":"0x64f250","include_decompile":true,"include_proto":true},{"addr":"0x64f350","include_decompile":true,"include_proto":true},{"addr":"0x64f410","include_decompile":true,"include_proto":true},{"addr":"0x64f420","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0051', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0051: empty response'); return; }
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
      console.log('Batch 0051: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0051 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0051 conn error:', e.message));
req.write(body);
req.end();
