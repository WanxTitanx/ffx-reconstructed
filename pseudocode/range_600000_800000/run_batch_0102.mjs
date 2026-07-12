
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6d3fc0","include_decompile":true,"include_proto":true},{"addr":"0x6d4060","include_decompile":true,"include_proto":true},{"addr":"0x6d4070","include_decompile":true,"include_proto":true},{"addr":"0x6d4080","include_decompile":true,"include_proto":true},{"addr":"0x6d40a0","include_decompile":true,"include_proto":true},{"addr":"0x6d40b0","include_decompile":true,"include_proto":true},{"addr":"0x6d40c0","include_decompile":true,"include_proto":true},{"addr":"0x6d40d0","include_decompile":true,"include_proto":true},{"addr":"0x6d40e0","include_decompile":true,"include_proto":true},{"addr":"0x6d4280","include_decompile":true,"include_proto":true},{"addr":"0x6d42e0","include_decompile":true,"include_proto":true},{"addr":"0x6d45f0","include_decompile":true,"include_proto":true},{"addr":"0x6d4670","include_decompile":true,"include_proto":true},{"addr":"0x6d4750","include_decompile":true,"include_proto":true},{"addr":"0x6d47d0","include_decompile":true,"include_proto":true},{"addr":"0x6d4840","include_decompile":true,"include_proto":true},{"addr":"0x6d48b0","include_decompile":true,"include_proto":true},{"addr":"0x6d4b20","include_decompile":true,"include_proto":true},{"addr":"0x6d4bc0","include_decompile":true,"include_proto":true},{"addr":"0x6d4cd0","include_decompile":true,"include_proto":true},{"addr":"0x6d4dd0","include_decompile":true,"include_proto":true},{"addr":"0x6d4e50","include_decompile":true,"include_proto":true},{"addr":"0x6d4e60","include_decompile":true,"include_proto":true},{"addr":"0x6d4ee0","include_decompile":true,"include_proto":true},{"addr":"0x6d4f10","include_decompile":true,"include_proto":true},{"addr":"0x6d4f50","include_decompile":true,"include_proto":true},{"addr":"0x6d5180","include_decompile":true,"include_proto":true},{"addr":"0x6d52c0","include_decompile":true,"include_proto":true},{"addr":"0x6d5300","include_decompile":true,"include_proto":true},{"addr":"0x6d55f0","include_decompile":true,"include_proto":true},{"addr":"0x6d56e0","include_decompile":true,"include_proto":true},{"addr":"0x6d5790","include_decompile":true,"include_proto":true},{"addr":"0x6d57a0","include_decompile":true,"include_proto":true},{"addr":"0x6d57b0","include_decompile":true,"include_proto":true},{"addr":"0x6d5aa0","include_decompile":true,"include_proto":true},{"addr":"0x6d5af0","include_decompile":true,"include_proto":true},{"addr":"0x6d5b10","include_decompile":true,"include_proto":true},{"addr":"0x6d5b30","include_decompile":true,"include_proto":true},{"addr":"0x6d5ba0","include_decompile":true,"include_proto":true},{"addr":"0x6d5d90","include_decompile":true,"include_proto":true},{"addr":"0x6d5dd0","include_decompile":true,"include_proto":true},{"addr":"0x6d5ef0","include_decompile":true,"include_proto":true},{"addr":"0x6d6120","include_decompile":true,"include_proto":true},{"addr":"0x6d6260","include_decompile":true,"include_proto":true},{"addr":"0x6d6270","include_decompile":true,"include_proto":true},{"addr":"0x6d6280","include_decompile":true,"include_proto":true},{"addr":"0x6d6290","include_decompile":true,"include_proto":true},{"addr":"0x6d62a0","include_decompile":true,"include_proto":true},{"addr":"0x6d62b0","include_decompile":true,"include_proto":true},{"addr":"0x6d62d0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0102', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0102: empty response'); return; }
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
      console.log('Batch 0102: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0102 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0102 conn error:', e.message));
req.write(body);
req.end();
