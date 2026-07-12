
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6339d0","include_decompile":true,"include_proto":true},{"addr":"0x633a30","include_decompile":true,"include_proto":true},{"addr":"0x633a90","include_decompile":true,"include_proto":true},{"addr":"0x633aa0","include_decompile":true,"include_proto":true},{"addr":"0x633ab0","include_decompile":true,"include_proto":true},{"addr":"0x633ac0","include_decompile":true,"include_proto":true},{"addr":"0x633ad0","include_decompile":true,"include_proto":true},{"addr":"0x633ae0","include_decompile":true,"include_proto":true},{"addr":"0x633af0","include_decompile":true,"include_proto":true},{"addr":"0x633b00","include_decompile":true,"include_proto":true},{"addr":"0x633b10","include_decompile":true,"include_proto":true},{"addr":"0x633b20","include_decompile":true,"include_proto":true},{"addr":"0x633b30","include_decompile":true,"include_proto":true},{"addr":"0x633b40","include_decompile":true,"include_proto":true},{"addr":"0x633b50","include_decompile":true,"include_proto":true},{"addr":"0x633b60","include_decompile":true,"include_proto":true},{"addr":"0x633b70","include_decompile":true,"include_proto":true},{"addr":"0x633b80","include_decompile":true,"include_proto":true},{"addr":"0x633b90","include_decompile":true,"include_proto":true},{"addr":"0x633ba0","include_decompile":true,"include_proto":true},{"addr":"0x633bb0","include_decompile":true,"include_proto":true},{"addr":"0x633bc0","include_decompile":true,"include_proto":true},{"addr":"0x633bd0","include_decompile":true,"include_proto":true},{"addr":"0x633be0","include_decompile":true,"include_proto":true},{"addr":"0x633bf0","include_decompile":true,"include_proto":true},{"addr":"0x633c00","include_decompile":true,"include_proto":true},{"addr":"0x633c10","include_decompile":true,"include_proto":true},{"addr":"0x633c70","include_decompile":true,"include_proto":true},{"addr":"0x633d90","include_decompile":true,"include_proto":true},{"addr":"0x633f70","include_decompile":true,"include_proto":true},{"addr":"0x633fd0","include_decompile":true,"include_proto":true},{"addr":"0x634030","include_decompile":true,"include_proto":true},{"addr":"0x634090","include_decompile":true,"include_proto":true},{"addr":"0x6340a0","include_decompile":true,"include_proto":true},{"addr":"0x634120","include_decompile":true,"include_proto":true},{"addr":"0x634190","include_decompile":true,"include_proto":true},{"addr":"0x634230","include_decompile":true,"include_proto":true},{"addr":"0x6342b0","include_decompile":true,"include_proto":true},{"addr":"0x634330","include_decompile":true,"include_proto":true},{"addr":"0x634340","include_decompile":true,"include_proto":true},{"addr":"0x6343d0","include_decompile":true,"include_proto":true},{"addr":"0x634510","include_decompile":true,"include_proto":true},{"addr":"0x634560","include_decompile":true,"include_proto":true},{"addr":"0x634590","include_decompile":true,"include_proto":true},{"addr":"0x6346f0","include_decompile":true,"include_proto":true},{"addr":"0x634700","include_decompile":true,"include_proto":true},{"addr":"0x634710","include_decompile":true,"include_proto":true},{"addr":"0x634720","include_decompile":true,"include_proto":true},{"addr":"0x634730","include_decompile":true,"include_proto":true},{"addr":"0x634740","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0032', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0032: empty response'); return; }
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
      console.log('Batch 0032: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0032 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0032 conn error:', e.message));
req.write(body);
req.end();
