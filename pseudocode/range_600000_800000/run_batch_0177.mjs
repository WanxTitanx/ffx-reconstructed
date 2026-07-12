
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x79e5b0","include_decompile":true,"include_proto":true},{"addr":"0x79e600","include_decompile":true,"include_proto":true},{"addr":"0x79e650","include_decompile":true,"include_proto":true},{"addr":"0x79e690","include_decompile":true,"include_proto":true},{"addr":"0x79e6c0","include_decompile":true,"include_proto":true},{"addr":"0x79e7c0","include_decompile":true,"include_proto":true},{"addr":"0x79e7d0","include_decompile":true,"include_proto":true},{"addr":"0x79e7e0","include_decompile":true,"include_proto":true},{"addr":"0x79e850","include_decompile":true,"include_proto":true},{"addr":"0x79e8b0","include_decompile":true,"include_proto":true},{"addr":"0x79e8e0","include_decompile":true,"include_proto":true},{"addr":"0x79ea60","include_decompile":true,"include_proto":true},{"addr":"0x79eab0","include_decompile":true,"include_proto":true},{"addr":"0x79eaf0","include_decompile":true,"include_proto":true},{"addr":"0x79eb00","include_decompile":true,"include_proto":true},{"addr":"0x79eb30","include_decompile":true,"include_proto":true},{"addr":"0x79ebc0","include_decompile":true,"include_proto":true},{"addr":"0x79ec00","include_decompile":true,"include_proto":true},{"addr":"0x79ec60","include_decompile":true,"include_proto":true},{"addr":"0x79ecc0","include_decompile":true,"include_proto":true},{"addr":"0x79ed20","include_decompile":true,"include_proto":true},{"addr":"0x79ed40","include_decompile":true,"include_proto":true},{"addr":"0x79ed60","include_decompile":true,"include_proto":true},{"addr":"0x79ee40","include_decompile":true,"include_proto":true},{"addr":"0x79ef60","include_decompile":true,"include_proto":true},{"addr":"0x79f010","include_decompile":true,"include_proto":true},{"addr":"0x79f130","include_decompile":true,"include_proto":true},{"addr":"0x79f180","include_decompile":true,"include_proto":true},{"addr":"0x79f1e0","include_decompile":true,"include_proto":true},{"addr":"0x79f230","include_decompile":true,"include_proto":true},{"addr":"0x79f250","include_decompile":true,"include_proto":true},{"addr":"0x79f280","include_decompile":true,"include_proto":true},{"addr":"0x79f3a0","include_decompile":true,"include_proto":true},{"addr":"0x79f600","include_decompile":true,"include_proto":true},{"addr":"0x79f680","include_decompile":true,"include_proto":true},{"addr":"0x79f9b0","include_decompile":true,"include_proto":true},{"addr":"0x79f9d0","include_decompile":true,"include_proto":true},{"addr":"0x79fa10","include_decompile":true,"include_proto":true},{"addr":"0x79fa20","include_decompile":true,"include_proto":true},{"addr":"0x79fc20","include_decompile":true,"include_proto":true},{"addr":"0x79fc80","include_decompile":true,"include_proto":true},{"addr":"0x79fd10","include_decompile":true,"include_proto":true},{"addr":"0x79fd40","include_decompile":true,"include_proto":true},{"addr":"0x79fd60","include_decompile":true,"include_proto":true},{"addr":"0x79fdc0","include_decompile":true,"include_proto":true},{"addr":"0x79fe10","include_decompile":true,"include_proto":true},{"addr":"0x79fe50","include_decompile":true,"include_proto":true},{"addr":"0x79fea0","include_decompile":true,"include_proto":true},{"addr":"0x7a0010","include_decompile":true,"include_proto":true},{"addr":"0x7a0060","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0177', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0177: empty response'); return; }
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
      console.log('Batch 0177: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0177 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0177 conn error:', e.message));
req.write(body);
req.end();
