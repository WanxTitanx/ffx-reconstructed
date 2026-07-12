
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x62d890","include_decompile":true,"include_proto":true},{"addr":"0x62d8a0","include_decompile":true,"include_proto":true},{"addr":"0x62db80","include_decompile":true,"include_proto":true},{"addr":"0x62dd50","include_decompile":true,"include_proto":true},{"addr":"0x62e000","include_decompile":true,"include_proto":true},{"addr":"0x62e1f0","include_decompile":true,"include_proto":true},{"addr":"0x62e4f0","include_decompile":true,"include_proto":true},{"addr":"0x62e550","include_decompile":true,"include_proto":true},{"addr":"0x62ebe0","include_decompile":true,"include_proto":true},{"addr":"0x62ec30","include_decompile":true,"include_proto":true},{"addr":"0x62ec80","include_decompile":true,"include_proto":true},{"addr":"0x62ecd0","include_decompile":true,"include_proto":true},{"addr":"0x62ed20","include_decompile":true,"include_proto":true},{"addr":"0x62ed80","include_decompile":true,"include_proto":true},{"addr":"0x62ede0","include_decompile":true,"include_proto":true},{"addr":"0x62ee30","include_decompile":true,"include_proto":true},{"addr":"0x62ee80","include_decompile":true,"include_proto":true},{"addr":"0x62eed0","include_decompile":true,"include_proto":true},{"addr":"0x62ef30","include_decompile":true,"include_proto":true},{"addr":"0x62ef84","include_decompile":true,"include_proto":true},{"addr":"0x62f000","include_decompile":true,"include_proto":true},{"addr":"0x62f670","include_decompile":true,"include_proto":true},{"addr":"0x62f680","include_decompile":true,"include_proto":true},{"addr":"0x62f690","include_decompile":true,"include_proto":true},{"addr":"0x62f6b0","include_decompile":true,"include_proto":true},{"addr":"0x62f6c0","include_decompile":true,"include_proto":true},{"addr":"0x62f6d0","include_decompile":true,"include_proto":true},{"addr":"0x62f6e0","include_decompile":true,"include_proto":true},{"addr":"0x62f700","include_decompile":true,"include_proto":true},{"addr":"0x62f710","include_decompile":true,"include_proto":true},{"addr":"0x62f720","include_decompile":true,"include_proto":true},{"addr":"0x62f730","include_decompile":true,"include_proto":true},{"addr":"0x62f760","include_decompile":true,"include_proto":true},{"addr":"0x62f7c0","include_decompile":true,"include_proto":true},{"addr":"0x62f7e0","include_decompile":true,"include_proto":true},{"addr":"0x62f7f0","include_decompile":true,"include_proto":true},{"addr":"0x62f800","include_decompile":true,"include_proto":true},{"addr":"0x62f810","include_decompile":true,"include_proto":true},{"addr":"0x62f820","include_decompile":true,"include_proto":true},{"addr":"0x62f830","include_decompile":true,"include_proto":true},{"addr":"0x62f840","include_decompile":true,"include_proto":true},{"addr":"0x62f850","include_decompile":true,"include_proto":true},{"addr":"0x62f860","include_decompile":true,"include_proto":true},{"addr":"0x62f870","include_decompile":true,"include_proto":true},{"addr":"0x62f880","include_decompile":true,"include_proto":true},{"addr":"0x62f890","include_decompile":true,"include_proto":true},{"addr":"0x62f8a0","include_decompile":true,"include_proto":true},{"addr":"0x62f8b0","include_decompile":true,"include_proto":true},{"addr":"0x62f8c0","include_decompile":true,"include_proto":true},{"addr":"0x62f8d0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0027', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0027: empty response'); return; }
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
      console.log('Batch 0027: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0027 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0027 conn error:', e.message));
req.write(body);
req.end();
