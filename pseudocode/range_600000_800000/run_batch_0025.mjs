
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x628ee0","include_decompile":true,"include_proto":true},{"addr":"0x628ef0","include_decompile":true,"include_proto":true},{"addr":"0x628f00","include_decompile":true,"include_proto":true},{"addr":"0x628f10","include_decompile":true,"include_proto":true},{"addr":"0x628f20","include_decompile":true,"include_proto":true},{"addr":"0x628f30","include_decompile":true,"include_proto":true},{"addr":"0x628f40","include_decompile":true,"include_proto":true},{"addr":"0x628f50","include_decompile":true,"include_proto":true},{"addr":"0x628f60","include_decompile":true,"include_proto":true},{"addr":"0x628f70","include_decompile":true,"include_proto":true},{"addr":"0x628f80","include_decompile":true,"include_proto":true},{"addr":"0x628fa0","include_decompile":true,"include_proto":true},{"addr":"0x628ff0","include_decompile":true,"include_proto":true},{"addr":"0x629070","include_decompile":true,"include_proto":true},{"addr":"0x629080","include_decompile":true,"include_proto":true},{"addr":"0x6290b0","include_decompile":true,"include_proto":true},{"addr":"0x6297d0","include_decompile":true,"include_proto":true},{"addr":"0x629860","include_decompile":true,"include_proto":true},{"addr":"0x629880","include_decompile":true,"include_proto":true},{"addr":"0x6298a0","include_decompile":true,"include_proto":true},{"addr":"0x6298c0","include_decompile":true,"include_proto":true},{"addr":"0x6298f0","include_decompile":true,"include_proto":true},{"addr":"0x629900","include_decompile":true,"include_proto":true},{"addr":"0x629920","include_decompile":true,"include_proto":true},{"addr":"0x629930","include_decompile":true,"include_proto":true},{"addr":"0x629940","include_decompile":true,"include_proto":true},{"addr":"0x629950","include_decompile":true,"include_proto":true},{"addr":"0x629960","include_decompile":true,"include_proto":true},{"addr":"0x629970","include_decompile":true,"include_proto":true},{"addr":"0x629980","include_decompile":true,"include_proto":true},{"addr":"0x629990","include_decompile":true,"include_proto":true},{"addr":"0x6299a0","include_decompile":true,"include_proto":true},{"addr":"0x6299b0","include_decompile":true,"include_proto":true},{"addr":"0x6299c0","include_decompile":true,"include_proto":true},{"addr":"0x6299d0","include_decompile":true,"include_proto":true},{"addr":"0x6299e0","include_decompile":true,"include_proto":true},{"addr":"0x6299f0","include_decompile":true,"include_proto":true},{"addr":"0x629a20","include_decompile":true,"include_proto":true},{"addr":"0x629bf0","include_decompile":true,"include_proto":true},{"addr":"0x629c60","include_decompile":true,"include_proto":true},{"addr":"0x629d40","include_decompile":true,"include_proto":true},{"addr":"0x629e40","include_decompile":true,"include_proto":true},{"addr":"0x629e50","include_decompile":true,"include_proto":true},{"addr":"0x629f00","include_decompile":true,"include_proto":true},{"addr":"0x629ff0","include_decompile":true,"include_proto":true},{"addr":"0x62a240","include_decompile":true,"include_proto":true},{"addr":"0x62a250","include_decompile":true,"include_proto":true},{"addr":"0x62a260","include_decompile":true,"include_proto":true},{"addr":"0x62a270","include_decompile":true,"include_proto":true},{"addr":"0x62a280","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0025', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0025: empty response'); return; }
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
      console.log('Batch 0025: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0025 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0025 conn error:', e.message));
req.write(body);
req.end();
