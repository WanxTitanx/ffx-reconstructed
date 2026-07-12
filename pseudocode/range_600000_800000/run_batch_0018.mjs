
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x61f320","include_decompile":true,"include_proto":true},{"addr":"0x61f350","include_decompile":true,"include_proto":true},{"addr":"0x61f360","include_decompile":true,"include_proto":true},{"addr":"0x61f370","include_decompile":true,"include_proto":true},{"addr":"0x61f380","include_decompile":true,"include_proto":true},{"addr":"0x61f390","include_decompile":true,"include_proto":true},{"addr":"0x61f430","include_decompile":true,"include_proto":true},{"addr":"0x61f4d0","include_decompile":true,"include_proto":true},{"addr":"0x61f7d0","include_decompile":true,"include_proto":true},{"addr":"0x61f7e0","include_decompile":true,"include_proto":true},{"addr":"0x61f7f0","include_decompile":true,"include_proto":true},{"addr":"0x61f800","include_decompile":true,"include_proto":true},{"addr":"0x61f810","include_decompile":true,"include_proto":true},{"addr":"0x61f820","include_decompile":true,"include_proto":true},{"addr":"0x61f950","include_decompile":true,"include_proto":true},{"addr":"0x61f960","include_decompile":true,"include_proto":true},{"addr":"0x61f970","include_decompile":true,"include_proto":true},{"addr":"0x61f980","include_decompile":true,"include_proto":true},{"addr":"0x61f990","include_decompile":true,"include_proto":true},{"addr":"0x61f9a0","include_decompile":true,"include_proto":true},{"addr":"0x61f9d0","include_decompile":true,"include_proto":true},{"addr":"0x61fc80","include_decompile":true,"include_proto":true},{"addr":"0x61fd60","include_decompile":true,"include_proto":true},{"addr":"0x61fde0","include_decompile":true,"include_proto":true},{"addr":"0x61feb0","include_decompile":true,"include_proto":true},{"addr":"0x61ff10","include_decompile":true,"include_proto":true},{"addr":"0x61ff90","include_decompile":true,"include_proto":true},{"addr":"0x620000","include_decompile":true,"include_proto":true},{"addr":"0x620010","include_decompile":true,"include_proto":true},{"addr":"0x620030","include_decompile":true,"include_proto":true},{"addr":"0x620080","include_decompile":true,"include_proto":true},{"addr":"0x6200d0","include_decompile":true,"include_proto":true},{"addr":"0x6201b0","include_decompile":true,"include_proto":true},{"addr":"0x620290","include_decompile":true,"include_proto":true},{"addr":"0x620360","include_decompile":true,"include_proto":true},{"addr":"0x620570","include_decompile":true,"include_proto":true},{"addr":"0x620700","include_decompile":true,"include_proto":true},{"addr":"0x620750","include_decompile":true,"include_proto":true},{"addr":"0x620920","include_decompile":true,"include_proto":true},{"addr":"0x620940","include_decompile":true,"include_proto":true},{"addr":"0x620a40","include_decompile":true,"include_proto":true},{"addr":"0x620a70","include_decompile":true,"include_proto":true},{"addr":"0x620b50","include_decompile":true,"include_proto":true},{"addr":"0x620bc0","include_decompile":true,"include_proto":true},{"addr":"0x620bd0","include_decompile":true,"include_proto":true},{"addr":"0x620be0","include_decompile":true,"include_proto":true},{"addr":"0x620bf0","include_decompile":true,"include_proto":true},{"addr":"0x620c00","include_decompile":true,"include_proto":true},{"addr":"0x620c30","include_decompile":true,"include_proto":true},{"addr":"0x620c40","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0018', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0018: empty response'); return; }
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
      console.log('Batch 0018: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0018 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0018 conn error:', e.message));
req.write(body);
req.end();
