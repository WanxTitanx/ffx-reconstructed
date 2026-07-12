
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7c0930","include_decompile":true,"include_proto":true},{"addr":"0x7c09b0","include_decompile":true,"include_proto":true},{"addr":"0x7c0a30","include_decompile":true,"include_proto":true},{"addr":"0x7c0a60","include_decompile":true,"include_proto":true},{"addr":"0x7c0cc0","include_decompile":true,"include_proto":true},{"addr":"0x7c0de0","include_decompile":true,"include_proto":true},{"addr":"0x7c0f80","include_decompile":true,"include_proto":true},{"addr":"0x7c1090","include_decompile":true,"include_proto":true},{"addr":"0x7c1140","include_decompile":true,"include_proto":true},{"addr":"0x7c1340","include_decompile":true,"include_proto":true},{"addr":"0x7c1400","include_decompile":true,"include_proto":true},{"addr":"0x7c14d0","include_decompile":true,"include_proto":true},{"addr":"0x7c1b70","include_decompile":true,"include_proto":true},{"addr":"0x7c24b0","include_decompile":true,"include_proto":true},{"addr":"0x7c2570","include_decompile":true,"include_proto":true},{"addr":"0x7c2700","include_decompile":true,"include_proto":true},{"addr":"0x7c2da0","include_decompile":true,"include_proto":true},{"addr":"0x7c2e50","include_decompile":true,"include_proto":true},{"addr":"0x7c2fd0","include_decompile":true,"include_proto":true},{"addr":"0x7c3110","include_decompile":true,"include_proto":true},{"addr":"0x7c3420","include_decompile":true,"include_proto":true},{"addr":"0x7c3730","include_decompile":true,"include_proto":true},{"addr":"0x7c3d00","include_decompile":true,"include_proto":true},{"addr":"0x7c4050","include_decompile":true,"include_proto":true},{"addr":"0x7c4120","include_decompile":true,"include_proto":true},{"addr":"0x7c4220","include_decompile":true,"include_proto":true},{"addr":"0x7c4340","include_decompile":true,"include_proto":true},{"addr":"0x7c4440","include_decompile":true,"include_proto":true},{"addr":"0x7c4580","include_decompile":true,"include_proto":true},{"addr":"0x7c4760","include_decompile":true,"include_proto":true},{"addr":"0x7c4930","include_decompile":true,"include_proto":true},{"addr":"0x7c4ce0","include_decompile":true,"include_proto":true},{"addr":"0x7c4eb0","include_decompile":true,"include_proto":true},{"addr":"0x7c4ef0","include_decompile":true,"include_proto":true},{"addr":"0x7c4f50","include_decompile":true,"include_proto":true},{"addr":"0x7c5080","include_decompile":true,"include_proto":true},{"addr":"0x7c5610","include_decompile":true,"include_proto":true},{"addr":"0x7c5650","include_decompile":true,"include_proto":true},{"addr":"0x7c5680","include_decompile":true,"include_proto":true},{"addr":"0x7c5740","include_decompile":true,"include_proto":true},{"addr":"0x7c5870","include_decompile":true,"include_proto":true},{"addr":"0x7c5bf0","include_decompile":true,"include_proto":true},{"addr":"0x7c5d60","include_decompile":true,"include_proto":true},{"addr":"0x7c5ee0","include_decompile":true,"include_proto":true},{"addr":"0x7c5ef0","include_decompile":true,"include_proto":true},{"addr":"0x7c5f30","include_decompile":true,"include_proto":true},{"addr":"0x7c6010","include_decompile":true,"include_proto":true},{"addr":"0x7c6080","include_decompile":true,"include_proto":true},{"addr":"0x7c6cf0","include_decompile":true,"include_proto":true},{"addr":"0x7c6d10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0195', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0195: empty response'); return; }
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
      console.log('Batch 0195: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0195 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0195 conn error:', e.message));
req.write(body);
req.end();
