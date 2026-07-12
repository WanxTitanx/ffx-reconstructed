
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x64ca80","include_decompile":true,"include_proto":true},{"addr":"0x64caf0","include_decompile":true,"include_proto":true},{"addr":"0x64cb60","include_decompile":true,"include_proto":true},{"addr":"0x64cbd0","include_decompile":true,"include_proto":true},{"addr":"0x64ccb0","include_decompile":true,"include_proto":true},{"addr":"0x64cd50","include_decompile":true,"include_proto":true},{"addr":"0x64cf50","include_decompile":true,"include_proto":true},{"addr":"0x64cfb0","include_decompile":true,"include_proto":true},{"addr":"0x64d010","include_decompile":true,"include_proto":true},{"addr":"0x64d070","include_decompile":true,"include_proto":true},{"addr":"0x64d120","include_decompile":true,"include_proto":true},{"addr":"0x64d130","include_decompile":true,"include_proto":true},{"addr":"0x64d1a0","include_decompile":true,"include_proto":true},{"addr":"0x64d1b0","include_decompile":true,"include_proto":true},{"addr":"0x64d1c0","include_decompile":true,"include_proto":true},{"addr":"0x64d1d0","include_decompile":true,"include_proto":true},{"addr":"0x64d1e0","include_decompile":true,"include_proto":true},{"addr":"0x64d1f0","include_decompile":true,"include_proto":true},{"addr":"0x64d200","include_decompile":true,"include_proto":true},{"addr":"0x64d380","include_decompile":true,"include_proto":true},{"addr":"0x64d390","include_decompile":true,"include_proto":true},{"addr":"0x64d3a0","include_decompile":true,"include_proto":true},{"addr":"0x64d3b0","include_decompile":true,"include_proto":true},{"addr":"0x64d3c0","include_decompile":true,"include_proto":true},{"addr":"0x64d3d0","include_decompile":true,"include_proto":true},{"addr":"0x64d3f0","include_decompile":true,"include_proto":true},{"addr":"0x64d410","include_decompile":true,"include_proto":true},{"addr":"0x64d430","include_decompile":true,"include_proto":true},{"addr":"0x64d450","include_decompile":true,"include_proto":true},{"addr":"0x64d470","include_decompile":true,"include_proto":true},{"addr":"0x64d480","include_decompile":true,"include_proto":true},{"addr":"0x64d490","include_decompile":true,"include_proto":true},{"addr":"0x64d4a0","include_decompile":true,"include_proto":true},{"addr":"0x64d4b0","include_decompile":true,"include_proto":true},{"addr":"0x64d4c0","include_decompile":true,"include_proto":true},{"addr":"0x64d4d0","include_decompile":true,"include_proto":true},{"addr":"0x64d4f0","include_decompile":true,"include_proto":true},{"addr":"0x64d510","include_decompile":true,"include_proto":true},{"addr":"0x64d530","include_decompile":true,"include_proto":true},{"addr":"0x64d550","include_decompile":true,"include_proto":true},{"addr":"0x64d570","include_decompile":true,"include_proto":true},{"addr":"0x64d580","include_decompile":true,"include_proto":true},{"addr":"0x64d590","include_decompile":true,"include_proto":true},{"addr":"0x64d5a0","include_decompile":true,"include_proto":true},{"addr":"0x64d5b0","include_decompile":true,"include_proto":true},{"addr":"0x64d5c0","include_decompile":true,"include_proto":true},{"addr":"0x64d5d0","include_decompile":true,"include_proto":true},{"addr":"0x64d5e0","include_decompile":true,"include_proto":true},{"addr":"0x64d5f0","include_decompile":true,"include_proto":true},{"addr":"0x64d600","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0050', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0050: empty response'); return; }
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
      console.log('Batch 0050: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0050 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0050 conn error:', e.message));
req.write(body);
req.end();
