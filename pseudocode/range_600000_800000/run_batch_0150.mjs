
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x770b50","include_decompile":true,"include_proto":true},{"addr":"0x770b70","include_decompile":true,"include_proto":true},{"addr":"0x770ba0","include_decompile":true,"include_proto":true},{"addr":"0x770bc0","include_decompile":true,"include_proto":true},{"addr":"0x770bf0","include_decompile":true,"include_proto":true},{"addr":"0x770c10","include_decompile":true,"include_proto":true},{"addr":"0x770c40","include_decompile":true,"include_proto":true},{"addr":"0x770c60","include_decompile":true,"include_proto":true},{"addr":"0x770c90","include_decompile":true,"include_proto":true},{"addr":"0x770cb0","include_decompile":true,"include_proto":true},{"addr":"0x770cd0","include_decompile":true,"include_proto":true},{"addr":"0x770d00","include_decompile":true,"include_proto":true},{"addr":"0x770d20","include_decompile":true,"include_proto":true},{"addr":"0x770d50","include_decompile":true,"include_proto":true},{"addr":"0x770d70","include_decompile":true,"include_proto":true},{"addr":"0x770da0","include_decompile":true,"include_proto":true},{"addr":"0x770dc0","include_decompile":true,"include_proto":true},{"addr":"0x770df0","include_decompile":true,"include_proto":true},{"addr":"0x770e10","include_decompile":true,"include_proto":true},{"addr":"0x770e40","include_decompile":true,"include_proto":true},{"addr":"0x770e60","include_decompile":true,"include_proto":true},{"addr":"0x770e80","include_decompile":true,"include_proto":true},{"addr":"0x770eb0","include_decompile":true,"include_proto":true},{"addr":"0x770ed0","include_decompile":true,"include_proto":true},{"addr":"0x770f00","include_decompile":true,"include_proto":true},{"addr":"0x770f20","include_decompile":true,"include_proto":true},{"addr":"0x770f50","include_decompile":true,"include_proto":true},{"addr":"0x770f70","include_decompile":true,"include_proto":true},{"addr":"0x770fa0","include_decompile":true,"include_proto":true},{"addr":"0x770fc0","include_decompile":true,"include_proto":true},{"addr":"0x770ff0","include_decompile":true,"include_proto":true},{"addr":"0x771010","include_decompile":true,"include_proto":true},{"addr":"0x771030","include_decompile":true,"include_proto":true},{"addr":"0x771060","include_decompile":true,"include_proto":true},{"addr":"0x771080","include_decompile":true,"include_proto":true},{"addr":"0x7710b0","include_decompile":true,"include_proto":true},{"addr":"0x7710d0","include_decompile":true,"include_proto":true},{"addr":"0x771100","include_decompile":true,"include_proto":true},{"addr":"0x771120","include_decompile":true,"include_proto":true},{"addr":"0x771150","include_decompile":true,"include_proto":true},{"addr":"0x771170","include_decompile":true,"include_proto":true},{"addr":"0x7711a0","include_decompile":true,"include_proto":true},{"addr":"0x7711c0","include_decompile":true,"include_proto":true},{"addr":"0x7711e0","include_decompile":true,"include_proto":true},{"addr":"0x771210","include_decompile":true,"include_proto":true},{"addr":"0x771230","include_decompile":true,"include_proto":true},{"addr":"0x771260","include_decompile":true,"include_proto":true},{"addr":"0x771280","include_decompile":true,"include_proto":true},{"addr":"0x7712b0","include_decompile":true,"include_proto":true},{"addr":"0x7712d0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0150', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0150: empty response'); return; }
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
      console.log('Batch 0150: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0150 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0150 conn error:', e.message));
req.write(body);
req.end();
