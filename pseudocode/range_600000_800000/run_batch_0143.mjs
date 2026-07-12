
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x75b180","include_decompile":true,"include_proto":true},{"addr":"0x75b200","include_decompile":true,"include_proto":true},{"addr":"0x75b220","include_decompile":true,"include_proto":true},{"addr":"0x75b250","include_decompile":true,"include_proto":true},{"addr":"0x75b320","include_decompile":true,"include_proto":true},{"addr":"0x75b770","include_decompile":true,"include_proto":true},{"addr":"0x75b780","include_decompile":true,"include_proto":true},{"addr":"0x75b7a0","include_decompile":true,"include_proto":true},{"addr":"0x75b7b0","include_decompile":true,"include_proto":true},{"addr":"0x75b7c0","include_decompile":true,"include_proto":true},{"addr":"0x75b7d0","include_decompile":true,"include_proto":true},{"addr":"0x75b7e0","include_decompile":true,"include_proto":true},{"addr":"0x75b7f0","include_decompile":true,"include_proto":true},{"addr":"0x75b800","include_decompile":true,"include_proto":true},{"addr":"0x75b810","include_decompile":true,"include_proto":true},{"addr":"0x75b820","include_decompile":true,"include_proto":true},{"addr":"0x75b830","include_decompile":true,"include_proto":true},{"addr":"0x75b900","include_decompile":true,"include_proto":true},{"addr":"0x75b940","include_decompile":true,"include_proto":true},{"addr":"0x75b9b0","include_decompile":true,"include_proto":true},{"addr":"0x75b9f0","include_decompile":true,"include_proto":true},{"addr":"0x75bac0","include_decompile":true,"include_proto":true},{"addr":"0x75bb30","include_decompile":true,"include_proto":true},{"addr":"0x75bbb0","include_decompile":true,"include_proto":true},{"addr":"0x75bbf0","include_decompile":true,"include_proto":true},{"addr":"0x75bc20","include_decompile":true,"include_proto":true},{"addr":"0x75bed0","include_decompile":true,"include_proto":true},{"addr":"0x75bfa0","include_decompile":true,"include_proto":true},{"addr":"0x75bfe0","include_decompile":true,"include_proto":true},{"addr":"0x75c050","include_decompile":true,"include_proto":true},{"addr":"0x75c090","include_decompile":true,"include_proto":true},{"addr":"0x75c160","include_decompile":true,"include_proto":true},{"addr":"0x75c1a0","include_decompile":true,"include_proto":true},{"addr":"0x75c240","include_decompile":true,"include_proto":true},{"addr":"0x75c270","include_decompile":true,"include_proto":true},{"addr":"0x75c2a0","include_decompile":true,"include_proto":true},{"addr":"0x75c300","include_decompile":true,"include_proto":true},{"addr":"0x75c340","include_decompile":true,"include_proto":true},{"addr":"0x75c380","include_decompile":true,"include_proto":true},{"addr":"0x75c420","include_decompile":true,"include_proto":true},{"addr":"0x75c450","include_decompile":true,"include_proto":true},{"addr":"0x75c480","include_decompile":true,"include_proto":true},{"addr":"0x75c500","include_decompile":true,"include_proto":true},{"addr":"0x75c540","include_decompile":true,"include_proto":true},{"addr":"0x75c5b0","include_decompile":true,"include_proto":true},{"addr":"0x75c5f0","include_decompile":true,"include_proto":true},{"addr":"0x75c690","include_decompile":true,"include_proto":true},{"addr":"0x75c6c0","include_decompile":true,"include_proto":true},{"addr":"0x75c750","include_decompile":true,"include_proto":true},{"addr":"0x75ce20","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0143', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0143: empty response'); return; }
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
      console.log('Batch 0143: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0143 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0143 conn error:', e.message));
req.write(body);
req.end();
