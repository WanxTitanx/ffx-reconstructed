
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6ae490","include_decompile":true,"include_proto":true},{"addr":"0x6ae5a0","include_decompile":true,"include_proto":true},{"addr":"0x6ae680","include_decompile":true,"include_proto":true},{"addr":"0x6ae6d0","include_decompile":true,"include_proto":true},{"addr":"0x6ae6e0","include_decompile":true,"include_proto":true},{"addr":"0x6ae6f0","include_decompile":true,"include_proto":true},{"addr":"0x6ae700","include_decompile":true,"include_proto":true},{"addr":"0x6ae7a0","include_decompile":true,"include_proto":true},{"addr":"0x6ae880","include_decompile":true,"include_proto":true},{"addr":"0x6aead0","include_decompile":true,"include_proto":true},{"addr":"0x6aeb10","include_decompile":true,"include_proto":true},{"addr":"0x6aec70","include_decompile":true,"include_proto":true},{"addr":"0x6aee40","include_decompile":true,"include_proto":true},{"addr":"0x6aee90","include_decompile":true,"include_proto":true},{"addr":"0x6aeea0","include_decompile":true,"include_proto":true},{"addr":"0x6aeeb0","include_decompile":true,"include_proto":true},{"addr":"0x6aef00","include_decompile":true,"include_proto":true},{"addr":"0x6aef70","include_decompile":true,"include_proto":true},{"addr":"0x6af030","include_decompile":true,"include_proto":true},{"addr":"0x6af1c0","include_decompile":true,"include_proto":true},{"addr":"0x6af200","include_decompile":true,"include_proto":true},{"addr":"0x6af220","include_decompile":true,"include_proto":true},{"addr":"0x6af310","include_decompile":true,"include_proto":true},{"addr":"0x6af3c0","include_decompile":true,"include_proto":true},{"addr":"0x6af4c0","include_decompile":true,"include_proto":true},{"addr":"0x6af570","include_decompile":true,"include_proto":true},{"addr":"0x6af660","include_decompile":true,"include_proto":true},{"addr":"0x6af720","include_decompile":true,"include_proto":true},{"addr":"0x6af780","include_decompile":true,"include_proto":true},{"addr":"0x6af7e0","include_decompile":true,"include_proto":true},{"addr":"0x6af8b0","include_decompile":true,"include_proto":true},{"addr":"0x6af940","include_decompile":true,"include_proto":true},{"addr":"0x6af9f0","include_decompile":true,"include_proto":true},{"addr":"0x6afbc0","include_decompile":true,"include_proto":true},{"addr":"0x6afc40","include_decompile":true,"include_proto":true},{"addr":"0x6afeb0","include_decompile":true,"include_proto":true},{"addr":"0x6aff50","include_decompile":true,"include_proto":true},{"addr":"0x6aff80","include_decompile":true,"include_proto":true},{"addr":"0x6b0110","include_decompile":true,"include_proto":true},{"addr":"0x6b0160","include_decompile":true,"include_proto":true},{"addr":"0x6b01f0","include_decompile":true,"include_proto":true},{"addr":"0x6b0270","include_decompile":true,"include_proto":true},{"addr":"0x6b0340","include_decompile":true,"include_proto":true},{"addr":"0x6b0380","include_decompile":true,"include_proto":true},{"addr":"0x6b03c0","include_decompile":true,"include_proto":true},{"addr":"0x6b03d0","include_decompile":true,"include_proto":true},{"addr":"0x6b03e0","include_decompile":true,"include_proto":true},{"addr":"0x6b03f0","include_decompile":true,"include_proto":true},{"addr":"0x6b0400","include_decompile":true,"include_proto":true},{"addr":"0x6b0410","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0091', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0091: empty response'); return; }
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
      console.log('Batch 0091: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0091 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0091 conn error:', e.message));
req.write(body);
req.end();
