
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x69f580","include_decompile":true,"include_proto":true},{"addr":"0x69f600","include_decompile":true,"include_proto":true},{"addr":"0x69f680","include_decompile":true,"include_proto":true},{"addr":"0x69f6c0","include_decompile":true,"include_proto":true},{"addr":"0x69f700","include_decompile":true,"include_proto":true},{"addr":"0x69f760","include_decompile":true,"include_proto":true},{"addr":"0x69f7d0","include_decompile":true,"include_proto":true},{"addr":"0x69f7e0","include_decompile":true,"include_proto":true},{"addr":"0x69f7f0","include_decompile":true,"include_proto":true},{"addr":"0x69f800","include_decompile":true,"include_proto":true},{"addr":"0x69f810","include_decompile":true,"include_proto":true},{"addr":"0x69f820","include_decompile":true,"include_proto":true},{"addr":"0x69f890","include_decompile":true,"include_proto":true},{"addr":"0x69f930","include_decompile":true,"include_proto":true},{"addr":"0x69f9d0","include_decompile":true,"include_proto":true},{"addr":"0x69fa40","include_decompile":true,"include_proto":true},{"addr":"0x69fb10","include_decompile":true,"include_proto":true},{"addr":"0x69fd50","include_decompile":true,"include_proto":true},{"addr":"0x69ff90","include_decompile":true,"include_proto":true},{"addr":"0x6a01b0","include_decompile":true,"include_proto":true},{"addr":"0x6a0240","include_decompile":true,"include_proto":true},{"addr":"0x6a04a0","include_decompile":true,"include_proto":true},{"addr":"0x6a04d0","include_decompile":true,"include_proto":true},{"addr":"0x6a0500","include_decompile":true,"include_proto":true},{"addr":"0x6a0540","include_decompile":true,"include_proto":true},{"addr":"0x6a05a0","include_decompile":true,"include_proto":true},{"addr":"0x6a05b0","include_decompile":true,"include_proto":true},{"addr":"0x6a05c0","include_decompile":true,"include_proto":true},{"addr":"0x6a0620","include_decompile":true,"include_proto":true},{"addr":"0x6a0680","include_decompile":true,"include_proto":true},{"addr":"0x6a0740","include_decompile":true,"include_proto":true},{"addr":"0x6a0750","include_decompile":true,"include_proto":true},{"addr":"0x6a0760","include_decompile":true,"include_proto":true},{"addr":"0x6a0770","include_decompile":true,"include_proto":true},{"addr":"0x6a0780","include_decompile":true,"include_proto":true},{"addr":"0x6a0810","include_decompile":true,"include_proto":true},{"addr":"0x6a0820","include_decompile":true,"include_proto":true},{"addr":"0x6a0830","include_decompile":true,"include_proto":true},{"addr":"0x6a0950","include_decompile":true,"include_proto":true},{"addr":"0x6a0960","include_decompile":true,"include_proto":true},{"addr":"0x6a0970","include_decompile":true,"include_proto":true},{"addr":"0x6a09d0","include_decompile":true,"include_proto":true},{"addr":"0x6a0a30","include_decompile":true,"include_proto":true},{"addr":"0x6a0a40","include_decompile":true,"include_proto":true},{"addr":"0x6a0a60","include_decompile":true,"include_proto":true},{"addr":"0x6a0a80","include_decompile":true,"include_proto":true},{"addr":"0x6a0aa0","include_decompile":true,"include_proto":true},{"addr":"0x6a0ab0","include_decompile":true,"include_proto":true},{"addr":"0x6a0ad0","include_decompile":true,"include_proto":true},{"addr":"0x6a0af0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0085', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0085: empty response'); return; }
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
      console.log('Batch 0085: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0085 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0085 conn error:', e.message));
req.write(body);
req.end();
