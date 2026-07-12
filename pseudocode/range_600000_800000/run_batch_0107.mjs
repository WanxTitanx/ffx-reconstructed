
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6de990","include_decompile":true,"include_proto":true},{"addr":"0x6dea30","include_decompile":true,"include_proto":true},{"addr":"0x6dea60","include_decompile":true,"include_proto":true},{"addr":"0x6dea70","include_decompile":true,"include_proto":true},{"addr":"0x6deb20","include_decompile":true,"include_proto":true},{"addr":"0x6deb30","include_decompile":true,"include_proto":true},{"addr":"0x6deb90","include_decompile":true,"include_proto":true},{"addr":"0x6dec30","include_decompile":true,"include_proto":true},{"addr":"0x6decc0","include_decompile":true,"include_proto":true},{"addr":"0x6ded50","include_decompile":true,"include_proto":true},{"addr":"0x6dedc0","include_decompile":true,"include_proto":true},{"addr":"0x6dee70","include_decompile":true,"include_proto":true},{"addr":"0x6def00","include_decompile":true,"include_proto":true},{"addr":"0x6def80","include_decompile":true,"include_proto":true},{"addr":"0x6df020","include_decompile":true,"include_proto":true},{"addr":"0x6df090","include_decompile":true,"include_proto":true},{"addr":"0x6df1b0","include_decompile":true,"include_proto":true},{"addr":"0x6df210","include_decompile":true,"include_proto":true},{"addr":"0x6df290","include_decompile":true,"include_proto":true},{"addr":"0x6df310","include_decompile":true,"include_proto":true},{"addr":"0x6df320","include_decompile":true,"include_proto":true},{"addr":"0x6df340","include_decompile":true,"include_proto":true},{"addr":"0x6df3f0","include_decompile":true,"include_proto":true},{"addr":"0x6df440","include_decompile":true,"include_proto":true},{"addr":"0x6df450","include_decompile":true,"include_proto":true},{"addr":"0x6df460","include_decompile":true,"include_proto":true},{"addr":"0x6df470","include_decompile":true,"include_proto":true},{"addr":"0x6df4f0","include_decompile":true,"include_proto":true},{"addr":"0x6df500","include_decompile":true,"include_proto":true},{"addr":"0x6df5a0","include_decompile":true,"include_proto":true},{"addr":"0x6df640","include_decompile":true,"include_proto":true},{"addr":"0x6df750","include_decompile":true,"include_proto":true},{"addr":"0x6df800","include_decompile":true,"include_proto":true},{"addr":"0x6df9f0","include_decompile":true,"include_proto":true},{"addr":"0x6dfa80","include_decompile":true,"include_proto":true},{"addr":"0x6dfb60","include_decompile":true,"include_proto":true},{"addr":"0x6dfc00","include_decompile":true,"include_proto":true},{"addr":"0x6dff00","include_decompile":true,"include_proto":true},{"addr":"0x6e0020","include_decompile":true,"include_proto":true},{"addr":"0x6e0090","include_decompile":true,"include_proto":true},{"addr":"0x6e00a0","include_decompile":true,"include_proto":true},{"addr":"0x6e00b0","include_decompile":true,"include_proto":true},{"addr":"0x6e00c0","include_decompile":true,"include_proto":true},{"addr":"0x6e00d0","include_decompile":true,"include_proto":true},{"addr":"0x6e00e0","include_decompile":true,"include_proto":true},{"addr":"0x6e0230","include_decompile":true,"include_proto":true},{"addr":"0x6e0240","include_decompile":true,"include_proto":true},{"addr":"0x6e0250","include_decompile":true,"include_proto":true},{"addr":"0x6e05d0","include_decompile":true,"include_proto":true},{"addr":"0x6e0650","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0107', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0107: empty response'); return; }
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
      console.log('Batch 0107: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0107 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0107 conn error:', e.message));
req.write(body);
req.end();
