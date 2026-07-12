
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x78be50","include_decompile":true,"include_proto":true},{"addr":"0x78be90","include_decompile":true,"include_proto":true},{"addr":"0x78bfc0","include_decompile":true,"include_proto":true},{"addr":"0x78c010","include_decompile":true,"include_proto":true},{"addr":"0x78c070","include_decompile":true,"include_proto":true},{"addr":"0x78c170","include_decompile":true,"include_proto":true},{"addr":"0x78c1b0","include_decompile":true,"include_proto":true},{"addr":"0x78c210","include_decompile":true,"include_proto":true},{"addr":"0x78c240","include_decompile":true,"include_proto":true},{"addr":"0x78c290","include_decompile":true,"include_proto":true},{"addr":"0x78c330","include_decompile":true,"include_proto":true},{"addr":"0x78c540","include_decompile":true,"include_proto":true},{"addr":"0x78c580","include_decompile":true,"include_proto":true},{"addr":"0x78c5f0","include_decompile":true,"include_proto":true},{"addr":"0x78c640","include_decompile":true,"include_proto":true},{"addr":"0x78c6b0","include_decompile":true,"include_proto":true},{"addr":"0x78c700","include_decompile":true,"include_proto":true},{"addr":"0x78c730","include_decompile":true,"include_proto":true},{"addr":"0x78c750","include_decompile":true,"include_proto":true},{"addr":"0x78c800","include_decompile":true,"include_proto":true},{"addr":"0x78cae0","include_decompile":true,"include_proto":true},{"addr":"0x78cd60","include_decompile":true,"include_proto":true},{"addr":"0x78cda0","include_decompile":true,"include_proto":true},{"addr":"0x78cdf0","include_decompile":true,"include_proto":true},{"addr":"0x78cf10","include_decompile":true,"include_proto":true},{"addr":"0x78d030","include_decompile":true,"include_proto":true},{"addr":"0x78d100","include_decompile":true,"include_proto":true},{"addr":"0x78d150","include_decompile":true,"include_proto":true},{"addr":"0x78d210","include_decompile":true,"include_proto":true},{"addr":"0x78d290","include_decompile":true,"include_proto":true},{"addr":"0x78d2d0","include_decompile":true,"include_proto":true},{"addr":"0x78d330","include_decompile":true,"include_proto":true},{"addr":"0x78d460","include_decompile":true,"include_proto":true},{"addr":"0x78d4a0","include_decompile":true,"include_proto":true},{"addr":"0x78d570","include_decompile":true,"include_proto":true},{"addr":"0x78d580","include_decompile":true,"include_proto":true},{"addr":"0x78d5a0","include_decompile":true,"include_proto":true},{"addr":"0x78d5f0","include_decompile":true,"include_proto":true},{"addr":"0x78d6e0","include_decompile":true,"include_proto":true},{"addr":"0x78d740","include_decompile":true,"include_proto":true},{"addr":"0x78d7f0","include_decompile":true,"include_proto":true},{"addr":"0x78d850","include_decompile":true,"include_proto":true},{"addr":"0x78d8b0","include_decompile":true,"include_proto":true},{"addr":"0x78d990","include_decompile":true,"include_proto":true},{"addr":"0x78da40","include_decompile":true,"include_proto":true},{"addr":"0x78dba0","include_decompile":true,"include_proto":true},{"addr":"0x78dc30","include_decompile":true,"include_proto":true},{"addr":"0x78dcf0","include_decompile":true,"include_proto":true},{"addr":"0x78de80","include_decompile":true,"include_proto":true},{"addr":"0x78df00","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0168', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0168: empty response'); return; }
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
      console.log('Batch 0168: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0168 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0168 conn error:', e.message));
req.write(body);
req.end();
