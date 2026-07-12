
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x61ac10","include_decompile":true,"include_proto":true},{"addr":"0x61ac20","include_decompile":true,"include_proto":true},{"addr":"0x61ac50","include_decompile":true,"include_proto":true},{"addr":"0x61adf0","include_decompile":true,"include_proto":true},{"addr":"0x61ae70","include_decompile":true,"include_proto":true},{"addr":"0x61ae80","include_decompile":true,"include_proto":true},{"addr":"0x61aeb0","include_decompile":true,"include_proto":true},{"addr":"0x61aed0","include_decompile":true,"include_proto":true},{"addr":"0x61aef0","include_decompile":true,"include_proto":true},{"addr":"0x61af30","include_decompile":true,"include_proto":true},{"addr":"0x61af90","include_decompile":true,"include_proto":true},{"addr":"0x61b0d0","include_decompile":true,"include_proto":true},{"addr":"0x61b0e0","include_decompile":true,"include_proto":true},{"addr":"0x61b160","include_decompile":true,"include_proto":true},{"addr":"0x61b1f0","include_decompile":true,"include_proto":true},{"addr":"0x61b280","include_decompile":true,"include_proto":true},{"addr":"0x61b2b0","include_decompile":true,"include_proto":true},{"addr":"0x61b390","include_decompile":true,"include_proto":true},{"addr":"0x61b430","include_decompile":true,"include_proto":true},{"addr":"0x61b4f0","include_decompile":true,"include_proto":true},{"addr":"0x61b580","include_decompile":true,"include_proto":true},{"addr":"0x61b5f0","include_decompile":true,"include_proto":true},{"addr":"0x61b660","include_decompile":true,"include_proto":true},{"addr":"0x61b750","include_decompile":true,"include_proto":true},{"addr":"0x61b7e0","include_decompile":true,"include_proto":true},{"addr":"0x61b850","include_decompile":true,"include_proto":true},{"addr":"0x61b900","include_decompile":true,"include_proto":true},{"addr":"0x61b9a0","include_decompile":true,"include_proto":true},{"addr":"0x61ba90","include_decompile":true,"include_proto":true},{"addr":"0x61bc40","include_decompile":true,"include_proto":true},{"addr":"0x61bf70","include_decompile":true,"include_proto":true},{"addr":"0x61bf90","include_decompile":true,"include_proto":true},{"addr":"0x61c000","include_decompile":true,"include_proto":true},{"addr":"0x61c0d0","include_decompile":true,"include_proto":true},{"addr":"0x61c1a0","include_decompile":true,"include_proto":true},{"addr":"0x61c310","include_decompile":true,"include_proto":true},{"addr":"0x61c420","include_decompile":true,"include_proto":true},{"addr":"0x61c430","include_decompile":true,"include_proto":true},{"addr":"0x61c480","include_decompile":true,"include_proto":true},{"addr":"0x61c560","include_decompile":true,"include_proto":true},{"addr":"0x61c5c0","include_decompile":true,"include_proto":true},{"addr":"0x61ca30","include_decompile":true,"include_proto":true},{"addr":"0x61ca50","include_decompile":true,"include_proto":true},{"addr":"0x61cb10","include_decompile":true,"include_proto":true},{"addr":"0x61cb60","include_decompile":true,"include_proto":true},{"addr":"0x61cbd0","include_decompile":true,"include_proto":true},{"addr":"0x61cc40","include_decompile":true,"include_proto":true},{"addr":"0x61cc50","include_decompile":true,"include_proto":true},{"addr":"0x61cc60","include_decompile":true,"include_proto":true},{"addr":"0x61ce10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0015', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0015: empty response'); return; }
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
      console.log('Batch 0015: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0015 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0015 conn error:', e.message));
req.write(body);
req.end();
