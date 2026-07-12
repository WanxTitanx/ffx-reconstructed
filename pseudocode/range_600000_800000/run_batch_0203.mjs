
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7fadf0","include_decompile":true,"include_proto":true},{"addr":"0x7faf20","include_decompile":true,"include_proto":true},{"addr":"0x7fafc0","include_decompile":true,"include_proto":true},{"addr":"0x7fb090","include_decompile":true,"include_proto":true},{"addr":"0x7fb100","include_decompile":true,"include_proto":true},{"addr":"0x7fb160","include_decompile":true,"include_proto":true},{"addr":"0x7fb170","include_decompile":true,"include_proto":true},{"addr":"0x7fb1b0","include_decompile":true,"include_proto":true},{"addr":"0x7fb280","include_decompile":true,"include_proto":true},{"addr":"0x7fb390","include_decompile":true,"include_proto":true},{"addr":"0x7fb3e0","include_decompile":true,"include_proto":true},{"addr":"0x7fb430","include_decompile":true,"include_proto":true},{"addr":"0x7fb440","include_decompile":true,"include_proto":true},{"addr":"0x7fb450","include_decompile":true,"include_proto":true},{"addr":"0x7fb4c0","include_decompile":true,"include_proto":true},{"addr":"0x7fb5a0","include_decompile":true,"include_proto":true},{"addr":"0x7fb5b0","include_decompile":true,"include_proto":true},{"addr":"0x7fb5f0","include_decompile":true,"include_proto":true},{"addr":"0x7fb640","include_decompile":true,"include_proto":true},{"addr":"0x7fb650","include_decompile":true,"include_proto":true},{"addr":"0x7fb660","include_decompile":true,"include_proto":true},{"addr":"0x7fb710","include_decompile":true,"include_proto":true},{"addr":"0x7fb750","include_decompile":true,"include_proto":true},{"addr":"0x7fb790","include_decompile":true,"include_proto":true},{"addr":"0x7fb7b0","include_decompile":true,"include_proto":true},{"addr":"0x7fb800","include_decompile":true,"include_proto":true},{"addr":"0x7fb860","include_decompile":true,"include_proto":true},{"addr":"0x7fb960","include_decompile":true,"include_proto":true},{"addr":"0x7fb9d0","include_decompile":true,"include_proto":true},{"addr":"0x7fbab0","include_decompile":true,"include_proto":true},{"addr":"0x7fbb40","include_decompile":true,"include_proto":true},{"addr":"0x7fbbf0","include_decompile":true,"include_proto":true},{"addr":"0x7fbd10","include_decompile":true,"include_proto":true},{"addr":"0x7fbe10","include_decompile":true,"include_proto":true},{"addr":"0x7fbf20","include_decompile":true,"include_proto":true},{"addr":"0x7fbf80","include_decompile":true,"include_proto":true},{"addr":"0x7fc000","include_decompile":true,"include_proto":true},{"addr":"0x7fc050","include_decompile":true,"include_proto":true},{"addr":"0x7fc0b0","include_decompile":true,"include_proto":true},{"addr":"0x7fc1b0","include_decompile":true,"include_proto":true},{"addr":"0x7fc200","include_decompile":true,"include_proto":true},{"addr":"0x7fc360","include_decompile":true,"include_proto":true},{"addr":"0x7fc370","include_decompile":true,"include_proto":true},{"addr":"0x7fc470","include_decompile":true,"include_proto":true},{"addr":"0x7fc4b0","include_decompile":true,"include_proto":true},{"addr":"0x7fc510","include_decompile":true,"include_proto":true},{"addr":"0x7fc540","include_decompile":true,"include_proto":true},{"addr":"0x7fc570","include_decompile":true,"include_proto":true},{"addr":"0x7fc690","include_decompile":true,"include_proto":true},{"addr":"0x7fc6a0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0203', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0203: empty response'); return; }
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
      console.log('Batch 0203: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0203 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0203 conn error:', e.message));
req.write(body);
req.end();
