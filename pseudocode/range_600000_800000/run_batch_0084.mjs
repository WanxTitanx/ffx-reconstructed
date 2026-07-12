
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x69e010","include_decompile":true,"include_proto":true},{"addr":"0x69e020","include_decompile":true,"include_proto":true},{"addr":"0x69e030","include_decompile":true,"include_proto":true},{"addr":"0x69e050","include_decompile":true,"include_proto":true},{"addr":"0x69e060","include_decompile":true,"include_proto":true},{"addr":"0x69e070","include_decompile":true,"include_proto":true},{"addr":"0x69e090","include_decompile":true,"include_proto":true},{"addr":"0x69e0a0","include_decompile":true,"include_proto":true},{"addr":"0x69e0b0","include_decompile":true,"include_proto":true},{"addr":"0x69e0c0","include_decompile":true,"include_proto":true},{"addr":"0x69e0d0","include_decompile":true,"include_proto":true},{"addr":"0x69e0e0","include_decompile":true,"include_proto":true},{"addr":"0x69e0f0","include_decompile":true,"include_proto":true},{"addr":"0x69e100","include_decompile":true,"include_proto":true},{"addr":"0x69e150","include_decompile":true,"include_proto":true},{"addr":"0x69e170","include_decompile":true,"include_proto":true},{"addr":"0x69e200","include_decompile":true,"include_proto":true},{"addr":"0x69e280","include_decompile":true,"include_proto":true},{"addr":"0x69e3f0","include_decompile":true,"include_proto":true},{"addr":"0x69e460","include_decompile":true,"include_proto":true},{"addr":"0x69e520","include_decompile":true,"include_proto":true},{"addr":"0x69e640","include_decompile":true,"include_proto":true},{"addr":"0x69e6a0","include_decompile":true,"include_proto":true},{"addr":"0x69e720","include_decompile":true,"include_proto":true},{"addr":"0x69e7a0","include_decompile":true,"include_proto":true},{"addr":"0x69e7b0","include_decompile":true,"include_proto":true},{"addr":"0x69e8b0","include_decompile":true,"include_proto":true},{"addr":"0x69e970","include_decompile":true,"include_proto":true},{"addr":"0x69ea00","include_decompile":true,"include_proto":true},{"addr":"0x69ea40","include_decompile":true,"include_proto":true},{"addr":"0x69eb30","include_decompile":true,"include_proto":true},{"addr":"0x69eb40","include_decompile":true,"include_proto":true},{"addr":"0x69eb50","include_decompile":true,"include_proto":true},{"addr":"0x69eb80","include_decompile":true,"include_proto":true},{"addr":"0x69ebf0","include_decompile":true,"include_proto":true},{"addr":"0x69ec30","include_decompile":true,"include_proto":true},{"addr":"0x69ec40","include_decompile":true,"include_proto":true},{"addr":"0x69ed10","include_decompile":true,"include_proto":true},{"addr":"0x69ede0","include_decompile":true,"include_proto":true},{"addr":"0x69ee40","include_decompile":true,"include_proto":true},{"addr":"0x69eee0","include_decompile":true,"include_proto":true},{"addr":"0x69ef10","include_decompile":true,"include_proto":true},{"addr":"0x69efd0","include_decompile":true,"include_proto":true},{"addr":"0x69f040","include_decompile":true,"include_proto":true},{"addr":"0x69f0e0","include_decompile":true,"include_proto":true},{"addr":"0x69f110","include_decompile":true,"include_proto":true},{"addr":"0x69f140","include_decompile":true,"include_proto":true},{"addr":"0x69f250","include_decompile":true,"include_proto":true},{"addr":"0x69f3f0","include_decompile":true,"include_proto":true},{"addr":"0x69f4e0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0084', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0084: empty response'); return; }
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
      console.log('Batch 0084: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0084 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0084 conn error:', e.message));
req.write(body);
req.end();
