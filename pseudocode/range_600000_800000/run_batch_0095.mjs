
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6b7280","include_decompile":true,"include_proto":true},{"addr":"0x6b7420","include_decompile":true,"include_proto":true},{"addr":"0x6b7710","include_decompile":true,"include_proto":true},{"addr":"0x6b94a0","include_decompile":true,"include_proto":true},{"addr":"0x6b95e0","include_decompile":true,"include_proto":true},{"addr":"0x6b9740","include_decompile":true,"include_proto":true},{"addr":"0x6b9930","include_decompile":true,"include_proto":true},{"addr":"0x6b9ab0","include_decompile":true,"include_proto":true},{"addr":"0x6b9be0","include_decompile":true,"include_proto":true},{"addr":"0x6b9e10","include_decompile":true,"include_proto":true},{"addr":"0x6b9f60","include_decompile":true,"include_proto":true},{"addr":"0x6ba210","include_decompile":true,"include_proto":true},{"addr":"0x6ba220","include_decompile":true,"include_proto":true},{"addr":"0x6ba230","include_decompile":true,"include_proto":true},{"addr":"0x6ba240","include_decompile":true,"include_proto":true},{"addr":"0x6ba250","include_decompile":true,"include_proto":true},{"addr":"0x6ba2e0","include_decompile":true,"include_proto":true},{"addr":"0x6ba380","include_decompile":true,"include_proto":true},{"addr":"0x6ba420","include_decompile":true,"include_proto":true},{"addr":"0x6ba4d0","include_decompile":true,"include_proto":true},{"addr":"0x6ba570","include_decompile":true,"include_proto":true},{"addr":"0x6ba610","include_decompile":true,"include_proto":true},{"addr":"0x6ba6b0","include_decompile":true,"include_proto":true},{"addr":"0x6ba750","include_decompile":true,"include_proto":true},{"addr":"0x6baa00","include_decompile":true,"include_proto":true},{"addr":"0x6baaf0","include_decompile":true,"include_proto":true},{"addr":"0x6babe0","include_decompile":true,"include_proto":true},{"addr":"0x6bacd0","include_decompile":true,"include_proto":true},{"addr":"0x6bada0","include_decompile":true,"include_proto":true},{"addr":"0x6bae70","include_decompile":true,"include_proto":true},{"addr":"0x6baf40","include_decompile":true,"include_proto":true},{"addr":"0x6bb030","include_decompile":true,"include_proto":true},{"addr":"0x6bb0a0","include_decompile":true,"include_proto":true},{"addr":"0x6bb4f0","include_decompile":true,"include_proto":true},{"addr":"0x6bb5c0","include_decompile":true,"include_proto":true},{"addr":"0x6bb730","include_decompile":true,"include_proto":true},{"addr":"0x6bb7b0","include_decompile":true,"include_proto":true},{"addr":"0x6bb810","include_decompile":true,"include_proto":true},{"addr":"0x6bb900","include_decompile":true,"include_proto":true},{"addr":"0x6bb9c0","include_decompile":true,"include_proto":true},{"addr":"0x6bbab0","include_decompile":true,"include_proto":true},{"addr":"0x6bbbd0","include_decompile":true,"include_proto":true},{"addr":"0x6bbc50","include_decompile":true,"include_proto":true},{"addr":"0x6bbc70","include_decompile":true,"include_proto":true},{"addr":"0x6bbf10","include_decompile":true,"include_proto":true},{"addr":"0x6bbf30","include_decompile":true,"include_proto":true},{"addr":"0x6bc030","include_decompile":true,"include_proto":true},{"addr":"0x6bc230","include_decompile":true,"include_proto":true},{"addr":"0x6bc270","include_decompile":true,"include_proto":true},{"addr":"0x6bc350","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0095', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0095: empty response'); return; }
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
      console.log('Batch 0095: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0095 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0095 conn error:', e.message));
req.write(body);
req.end();
