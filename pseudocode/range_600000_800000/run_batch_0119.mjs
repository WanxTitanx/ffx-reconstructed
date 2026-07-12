
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6f9970","include_decompile":true,"include_proto":true},{"addr":"0x6f99f0","include_decompile":true,"include_proto":true},{"addr":"0x6f9a20","include_decompile":true,"include_proto":true},{"addr":"0x6f9a30","include_decompile":true,"include_proto":true},{"addr":"0x6f9a40","include_decompile":true,"include_proto":true},{"addr":"0x6f9a50","include_decompile":true,"include_proto":true},{"addr":"0x6f9a60","include_decompile":true,"include_proto":true},{"addr":"0x6f9a70","include_decompile":true,"include_proto":true},{"addr":"0x6f9a80","include_decompile":true,"include_proto":true},{"addr":"0x6f9aa0","include_decompile":true,"include_proto":true},{"addr":"0x6f9ab0","include_decompile":true,"include_proto":true},{"addr":"0x6f9ac0","include_decompile":true,"include_proto":true},{"addr":"0x6f9ae0","include_decompile":true,"include_proto":true},{"addr":"0x6f9af0","include_decompile":true,"include_proto":true},{"addr":"0x6f9b00","include_decompile":true,"include_proto":true},{"addr":"0x6f9b10","include_decompile":true,"include_proto":true},{"addr":"0x6f9b60","include_decompile":true,"include_proto":true},{"addr":"0x6f9ba0","include_decompile":true,"include_proto":true},{"addr":"0x6f9bd0","include_decompile":true,"include_proto":true},{"addr":"0x6f9c40","include_decompile":true,"include_proto":true},{"addr":"0x6f9c50","include_decompile":true,"include_proto":true},{"addr":"0x6f9c60","include_decompile":true,"include_proto":true},{"addr":"0x6f9c80","include_decompile":true,"include_proto":true},{"addr":"0x6f9ca0","include_decompile":true,"include_proto":true},{"addr":"0x6f9da0","include_decompile":true,"include_proto":true},{"addr":"0x6f9df0","include_decompile":true,"include_proto":true},{"addr":"0x6f9e00","include_decompile":true,"include_proto":true},{"addr":"0x6f9e30","include_decompile":true,"include_proto":true},{"addr":"0x6f9e50","include_decompile":true,"include_proto":true},{"addr":"0x6f9e60","include_decompile":true,"include_proto":true},{"addr":"0x6f9ec0","include_decompile":true,"include_proto":true},{"addr":"0x6fa050","include_decompile":true,"include_proto":true},{"addr":"0x6fa120","include_decompile":true,"include_proto":true},{"addr":"0x6fa190","include_decompile":true,"include_proto":true},{"addr":"0x6fa270","include_decompile":true,"include_proto":true},{"addr":"0x6fa290","include_decompile":true,"include_proto":true},{"addr":"0x6fa2e0","include_decompile":true,"include_proto":true},{"addr":"0x6fa360","include_decompile":true,"include_proto":true},{"addr":"0x6fa380","include_decompile":true,"include_proto":true},{"addr":"0x6fa3a0","include_decompile":true,"include_proto":true},{"addr":"0x6fa3c0","include_decompile":true,"include_proto":true},{"addr":"0x6fa3e0","include_decompile":true,"include_proto":true},{"addr":"0x6fa560","include_decompile":true,"include_proto":true},{"addr":"0x6fa580","include_decompile":true,"include_proto":true},{"addr":"0x6fa5e0","include_decompile":true,"include_proto":true},{"addr":"0x6fa770","include_decompile":true,"include_proto":true},{"addr":"0x6fa7a0","include_decompile":true,"include_proto":true},{"addr":"0x6fa7e0","include_decompile":true,"include_proto":true},{"addr":"0x6fa8c0","include_decompile":true,"include_proto":true},{"addr":"0x6fa960","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0119', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0119: empty response'); return; }
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
      console.log('Batch 0119: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0119 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0119 conn error:', e.message));
req.write(body);
req.end();
