
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x75cee0","include_decompile":true,"include_proto":true},{"addr":"0x75cf10","include_decompile":true,"include_proto":true},{"addr":"0x75cf20","include_decompile":true,"include_proto":true},{"addr":"0x75cf70","include_decompile":true,"include_proto":true},{"addr":"0x75cfb0","include_decompile":true,"include_proto":true},{"addr":"0x75d030","include_decompile":true,"include_proto":true},{"addr":"0x75d060","include_decompile":true,"include_proto":true},{"addr":"0x75d0d0","include_decompile":true,"include_proto":true},{"addr":"0x75d140","include_decompile":true,"include_proto":true},{"addr":"0x75d180","include_decompile":true,"include_proto":true},{"addr":"0x75d220","include_decompile":true,"include_proto":true},{"addr":"0x75d250","include_decompile":true,"include_proto":true},{"addr":"0x75d2e0","include_decompile":true,"include_proto":true},{"addr":"0x75d330","include_decompile":true,"include_proto":true},{"addr":"0x75d370","include_decompile":true,"include_proto":true},{"addr":"0x75d430","include_decompile":true,"include_proto":true},{"addr":"0x75d540","include_decompile":true,"include_proto":true},{"addr":"0x75d680","include_decompile":true,"include_proto":true},{"addr":"0x75d6c0","include_decompile":true,"include_proto":true},{"addr":"0x75d7b0","include_decompile":true,"include_proto":true},{"addr":"0x75d7f0","include_decompile":true,"include_proto":true},{"addr":"0x75d8b0","include_decompile":true,"include_proto":true},{"addr":"0x75d8e0","include_decompile":true,"include_proto":true},{"addr":"0x75da00","include_decompile":true,"include_proto":true},{"addr":"0x75da10","include_decompile":true,"include_proto":true},{"addr":"0x75da20","include_decompile":true,"include_proto":true},{"addr":"0x75dc00","include_decompile":true,"include_proto":true},{"addr":"0x75dc10","include_decompile":true,"include_proto":true},{"addr":"0x75dc20","include_decompile":true,"include_proto":true},{"addr":"0x75de40","include_decompile":true,"include_proto":true},{"addr":"0x75de50","include_decompile":true,"include_proto":true},{"addr":"0x75de60","include_decompile":true,"include_proto":true},{"addr":"0x75e060","include_decompile":true,"include_proto":true},{"addr":"0x75e070","include_decompile":true,"include_proto":true},{"addr":"0x75e080","include_decompile":true,"include_proto":true},{"addr":"0x75e2c0","include_decompile":true,"include_proto":true},{"addr":"0x75e2d0","include_decompile":true,"include_proto":true},{"addr":"0x75e2e0","include_decompile":true,"include_proto":true},{"addr":"0x75e400","include_decompile":true,"include_proto":true},{"addr":"0x75e520","include_decompile":true,"include_proto":true},{"addr":"0x75e560","include_decompile":true,"include_proto":true},{"addr":"0x75e5a0","include_decompile":true,"include_proto":true},{"addr":"0x75e760","include_decompile":true,"include_proto":true},{"addr":"0x75e7c0","include_decompile":true,"include_proto":true},{"addr":"0x75e8b0","include_decompile":true,"include_proto":true},{"addr":"0x75e8c0","include_decompile":true,"include_proto":true},{"addr":"0x75e960","include_decompile":true,"include_proto":true},{"addr":"0x75e9e0","include_decompile":true,"include_proto":true},{"addr":"0x75ed90","include_decompile":true,"include_proto":true},{"addr":"0x75eed0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0144', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0144: empty response'); return; }
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
      console.log('Batch 0144: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0144 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0144 conn error:', e.message));
req.write(body);
req.end();
