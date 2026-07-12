
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7a3ac0","include_decompile":true,"include_proto":true},{"addr":"0x7a3ae0","include_decompile":true,"include_proto":true},{"addr":"0x7a3b00","include_decompile":true,"include_proto":true},{"addr":"0x7a3b40","include_decompile":true,"include_proto":true},{"addr":"0x7a3ba0","include_decompile":true,"include_proto":true},{"addr":"0x7a3c20","include_decompile":true,"include_proto":true},{"addr":"0x7a3c40","include_decompile":true,"include_proto":true},{"addr":"0x7a3c70","include_decompile":true,"include_proto":true},{"addr":"0x7a3cb0","include_decompile":true,"include_proto":true},{"addr":"0x7a3ce0","include_decompile":true,"include_proto":true},{"addr":"0x7a3d20","include_decompile":true,"include_proto":true},{"addr":"0x7a3d50","include_decompile":true,"include_proto":true},{"addr":"0x7a3db0","include_decompile":true,"include_proto":true},{"addr":"0x7a3df0","include_decompile":true,"include_proto":true},{"addr":"0x7a3e10","include_decompile":true,"include_proto":true},{"addr":"0x7a3ed0","include_decompile":true,"include_proto":true},{"addr":"0x7a3f10","include_decompile":true,"include_proto":true},{"addr":"0x7a3f60","include_decompile":true,"include_proto":true},{"addr":"0x7a3f70","include_decompile":true,"include_proto":true},{"addr":"0x7a3fd0","include_decompile":true,"include_proto":true},{"addr":"0x7a4010","include_decompile":true,"include_proto":true},{"addr":"0x7a4070","include_decompile":true,"include_proto":true},{"addr":"0x7a40c0","include_decompile":true,"include_proto":true},{"addr":"0x7a4120","include_decompile":true,"include_proto":true},{"addr":"0x7a4180","include_decompile":true,"include_proto":true},{"addr":"0x7a4200","include_decompile":true,"include_proto":true},{"addr":"0x7a4240","include_decompile":true,"include_proto":true},{"addr":"0x7a42a0","include_decompile":true,"include_proto":true},{"addr":"0x7a42c0","include_decompile":true,"include_proto":true},{"addr":"0x7a4330","include_decompile":true,"include_proto":true},{"addr":"0x7a4350","include_decompile":true,"include_proto":true},{"addr":"0x7a43a0","include_decompile":true,"include_proto":true},{"addr":"0x7a43c0","include_decompile":true,"include_proto":true},{"addr":"0x7a43f0","include_decompile":true,"include_proto":true},{"addr":"0x7a4450","include_decompile":true,"include_proto":true},{"addr":"0x7a4460","include_decompile":true,"include_proto":true},{"addr":"0x7a4490","include_decompile":true,"include_proto":true},{"addr":"0x7a44d0","include_decompile":true,"include_proto":true},{"addr":"0x7a4570","include_decompile":true,"include_proto":true},{"addr":"0x7a4580","include_decompile":true,"include_proto":true},{"addr":"0x7a45a0","include_decompile":true,"include_proto":true},{"addr":"0x7a45e0","include_decompile":true,"include_proto":true},{"addr":"0x7a4930","include_decompile":true,"include_proto":true},{"addr":"0x7a4960","include_decompile":true,"include_proto":true},{"addr":"0x7a49e0","include_decompile":true,"include_proto":true},{"addr":"0x7a4a10","include_decompile":true,"include_proto":true},{"addr":"0x7a4a80","include_decompile":true,"include_proto":true},{"addr":"0x7a4ab0","include_decompile":true,"include_proto":true},{"addr":"0x7a4b20","include_decompile":true,"include_proto":true},{"addr":"0x7a4bb0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0180', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0180: empty response'); return; }
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
      console.log('Batch 0180: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0180 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0180 conn error:', e.message));
req.write(body);
req.end();
