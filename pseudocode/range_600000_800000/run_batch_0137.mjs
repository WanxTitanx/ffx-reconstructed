
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x73b8f0","include_decompile":true,"include_proto":true},{"addr":"0x73ba70","include_decompile":true,"include_proto":true},{"addr":"0x73c9a0","include_decompile":true,"include_proto":true},{"addr":"0x73cee0","include_decompile":true,"include_proto":true},{"addr":"0x73cef0","include_decompile":true,"include_proto":true},{"addr":"0x73cf40","include_decompile":true,"include_proto":true},{"addr":"0x73cf70","include_decompile":true,"include_proto":true},{"addr":"0x73d070","include_decompile":true,"include_proto":true},{"addr":"0x73d0a0","include_decompile":true,"include_proto":true},{"addr":"0x73d0d0","include_decompile":true,"include_proto":true},{"addr":"0x73d130","include_decompile":true,"include_proto":true},{"addr":"0x73d590","include_decompile":true,"include_proto":true},{"addr":"0x73d880","include_decompile":true,"include_proto":true},{"addr":"0x73d980","include_decompile":true,"include_proto":true},{"addr":"0x73d9b0","include_decompile":true,"include_proto":true},{"addr":"0x73d9e0","include_decompile":true,"include_proto":true},{"addr":"0x73d9f0","include_decompile":true,"include_proto":true},{"addr":"0x73e0a0","include_decompile":true,"include_proto":true},{"addr":"0x73e200","include_decompile":true,"include_proto":true},{"addr":"0x73e300","include_decompile":true,"include_proto":true},{"addr":"0x73e330","include_decompile":true,"include_proto":true},{"addr":"0x73e360","include_decompile":true,"include_proto":true},{"addr":"0x73e370","include_decompile":true,"include_proto":true},{"addr":"0x73ea90","include_decompile":true,"include_proto":true},{"addr":"0x73eac0","include_decompile":true,"include_proto":true},{"addr":"0x73eaf0","include_decompile":true,"include_proto":true},{"addr":"0x73eb00","include_decompile":true,"include_proto":true},{"addr":"0x73f280","include_decompile":true,"include_proto":true},{"addr":"0x73f2b0","include_decompile":true,"include_proto":true},{"addr":"0x73f2e0","include_decompile":true,"include_proto":true},{"addr":"0x73f2f0","include_decompile":true,"include_proto":true},{"addr":"0x73faa0","include_decompile":true,"include_proto":true},{"addr":"0x73fad0","include_decompile":true,"include_proto":true},{"addr":"0x73fb00","include_decompile":true,"include_proto":true},{"addr":"0x73fb10","include_decompile":true,"include_proto":true},{"addr":"0x7401b0","include_decompile":true,"include_proto":true},{"addr":"0x740290","include_decompile":true,"include_proto":true},{"addr":"0x7404b0","include_decompile":true,"include_proto":true},{"addr":"0x7404d0","include_decompile":true,"include_proto":true},{"addr":"0x740a20","include_decompile":true,"include_proto":true},{"addr":"0x740aa0","include_decompile":true,"include_proto":true},{"addr":"0x740b30","include_decompile":true,"include_proto":true},{"addr":"0x740f70","include_decompile":true,"include_proto":true},{"addr":"0x740f90","include_decompile":true,"include_proto":true},{"addr":"0x741020","include_decompile":true,"include_proto":true},{"addr":"0x741510","include_decompile":true,"include_proto":true},{"addr":"0x741530","include_decompile":true,"include_proto":true},{"addr":"0x741630","include_decompile":true,"include_proto":true},{"addr":"0x741660","include_decompile":true,"include_proto":true},{"addr":"0x741aa0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0137', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0137: empty response'); return; }
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
      console.log('Batch 0137: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0137 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0137 conn error:', e.message));
req.write(body);
req.end();
