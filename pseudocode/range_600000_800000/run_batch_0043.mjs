
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6439e0","include_decompile":true,"include_proto":true},{"addr":"0x643a10","include_decompile":true,"include_proto":true},{"addr":"0x643a40","include_decompile":true,"include_proto":true},{"addr":"0x643a70","include_decompile":true,"include_proto":true},{"addr":"0x643a90","include_decompile":true,"include_proto":true},{"addr":"0x643ab0","include_decompile":true,"include_proto":true},{"addr":"0x643af0","include_decompile":true,"include_proto":true},{"addr":"0x643b30","include_decompile":true,"include_proto":true},{"addr":"0x643b60","include_decompile":true,"include_proto":true},{"addr":"0x643bb0","include_decompile":true,"include_proto":true},{"addr":"0x643bd0","include_decompile":true,"include_proto":true},{"addr":"0x643bf0","include_decompile":true,"include_proto":true},{"addr":"0x643c50","include_decompile":true,"include_proto":true},{"addr":"0x643ca0","include_decompile":true,"include_proto":true},{"addr":"0x643cc0","include_decompile":true,"include_proto":true},{"addr":"0x643ce0","include_decompile":true,"include_proto":true},{"addr":"0x643d30","include_decompile":true,"include_proto":true},{"addr":"0x643e70","include_decompile":true,"include_proto":true},{"addr":"0x643f60","include_decompile":true,"include_proto":true},{"addr":"0x643f70","include_decompile":true,"include_proto":true},{"addr":"0x643f80","include_decompile":true,"include_proto":true},{"addr":"0x643fa0","include_decompile":true,"include_proto":true},{"addr":"0x643fc0","include_decompile":true,"include_proto":true},{"addr":"0x643fd0","include_decompile":true,"include_proto":true},{"addr":"0x644000","include_decompile":true,"include_proto":true},{"addr":"0x644010","include_decompile":true,"include_proto":true},{"addr":"0x644020","include_decompile":true,"include_proto":true},{"addr":"0x644030","include_decompile":true,"include_proto":true},{"addr":"0x644060","include_decompile":true,"include_proto":true},{"addr":"0x644290","include_decompile":true,"include_proto":true},{"addr":"0x6442d0","include_decompile":true,"include_proto":true},{"addr":"0x644300","include_decompile":true,"include_proto":true},{"addr":"0x644430","include_decompile":true,"include_proto":true},{"addr":"0x644470","include_decompile":true,"include_proto":true},{"addr":"0x644480","include_decompile":true,"include_proto":true},{"addr":"0x6444a0","include_decompile":true,"include_proto":true},{"addr":"0x6444d0","include_decompile":true,"include_proto":true},{"addr":"0x644970","include_decompile":true,"include_proto":true},{"addr":"0x644990","include_decompile":true,"include_proto":true},{"addr":"0x6449b0","include_decompile":true,"include_proto":true},{"addr":"0x6449d0","include_decompile":true,"include_proto":true},{"addr":"0x644a80","include_decompile":true,"include_proto":true},{"addr":"0x644ac0","include_decompile":true,"include_proto":true},{"addr":"0x644af0","include_decompile":true,"include_proto":true},{"addr":"0x644b40","include_decompile":true,"include_proto":true},{"addr":"0x644b70","include_decompile":true,"include_proto":true},{"addr":"0x644b80","include_decompile":true,"include_proto":true},{"addr":"0x644bb0","include_decompile":true,"include_proto":true},{"addr":"0x644c60","include_decompile":true,"include_proto":true},{"addr":"0x644c70","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0043', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0043: empty response'); return; }
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
      console.log('Batch 0043: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0043 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0043 conn error:', e.message));
req.write(body);
req.end();
