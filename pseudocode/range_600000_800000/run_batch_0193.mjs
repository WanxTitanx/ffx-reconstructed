
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7bab10","include_decompile":true,"include_proto":true},{"addr":"0x7babc0","include_decompile":true,"include_proto":true},{"addr":"0x7bac90","include_decompile":true,"include_proto":true},{"addr":"0x7bad30","include_decompile":true,"include_proto":true},{"addr":"0x7bb190","include_decompile":true,"include_proto":true},{"addr":"0x7bb230","include_decompile":true,"include_proto":true},{"addr":"0x7bb2f0","include_decompile":true,"include_proto":true},{"addr":"0x7bb390","include_decompile":true,"include_proto":true},{"addr":"0x7bb4a0","include_decompile":true,"include_proto":true},{"addr":"0x7bb550","include_decompile":true,"include_proto":true},{"addr":"0x7bb620","include_decompile":true,"include_proto":true},{"addr":"0x7bb7c0","include_decompile":true,"include_proto":true},{"addr":"0x7bb840","include_decompile":true,"include_proto":true},{"addr":"0x7bb8f0","include_decompile":true,"include_proto":true},{"addr":"0x7bb9d0","include_decompile":true,"include_proto":true},{"addr":"0x7bb9f0","include_decompile":true,"include_proto":true},{"addr":"0x7bba80","include_decompile":true,"include_proto":true},{"addr":"0x7bba90","include_decompile":true,"include_proto":true},{"addr":"0x7bbbb0","include_decompile":true,"include_proto":true},{"addr":"0x7bbc80","include_decompile":true,"include_proto":true},{"addr":"0x7bbcf0","include_decompile":true,"include_proto":true},{"addr":"0x7bbd20","include_decompile":true,"include_proto":true},{"addr":"0x7bbd50","include_decompile":true,"include_proto":true},{"addr":"0x7bbd70","include_decompile":true,"include_proto":true},{"addr":"0x7bbe30","include_decompile":true,"include_proto":true},{"addr":"0x7bbf40","include_decompile":true,"include_proto":true},{"addr":"0x7bbf90","include_decompile":true,"include_proto":true},{"addr":"0x7bc040","include_decompile":true,"include_proto":true},{"addr":"0x7bc060","include_decompile":true,"include_proto":true},{"addr":"0x7bc090","include_decompile":true,"include_proto":true},{"addr":"0x7bc6a0","include_decompile":true,"include_proto":true},{"addr":"0x7bc6d0","include_decompile":true,"include_proto":true},{"addr":"0x7bc770","include_decompile":true,"include_proto":true},{"addr":"0x7bc7f0","include_decompile":true,"include_proto":true},{"addr":"0x7bc810","include_decompile":true,"include_proto":true},{"addr":"0x7bc8b0","include_decompile":true,"include_proto":true},{"addr":"0x7bc8d0","include_decompile":true,"include_proto":true},{"addr":"0x7bc900","include_decompile":true,"include_proto":true},{"addr":"0x7bca30","include_decompile":true,"include_proto":true},{"addr":"0x7bcb00","include_decompile":true,"include_proto":true},{"addr":"0x7bccb0","include_decompile":true,"include_proto":true},{"addr":"0x7bcd50","include_decompile":true,"include_proto":true},{"addr":"0x7bce00","include_decompile":true,"include_proto":true},{"addr":"0x7bcea0","include_decompile":true,"include_proto":true},{"addr":"0x7bced0","include_decompile":true,"include_proto":true},{"addr":"0x7bcf80","include_decompile":true,"include_proto":true},{"addr":"0x7bd090","include_decompile":true,"include_proto":true},{"addr":"0x7bd250","include_decompile":true,"include_proto":true},{"addr":"0x7bd280","include_decompile":true,"include_proto":true},{"addr":"0x7bd2c0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0193', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0193: empty response'); return; }
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
      console.log('Batch 0193: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0193 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0193 conn error:', e.message));
req.write(body);
req.end();
