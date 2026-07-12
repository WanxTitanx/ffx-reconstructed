
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x736b40","include_decompile":true,"include_proto":true},{"addr":"0x736b70","include_decompile":true,"include_proto":true},{"addr":"0x736ba0","include_decompile":true,"include_proto":true},{"addr":"0x736bd0","include_decompile":true,"include_proto":true},{"addr":"0x736c00","include_decompile":true,"include_proto":true},{"addr":"0x736c30","include_decompile":true,"include_proto":true},{"addr":"0x736c60","include_decompile":true,"include_proto":true},{"addr":"0x736c90","include_decompile":true,"include_proto":true},{"addr":"0x736cc0","include_decompile":true,"include_proto":true},{"addr":"0x736cf0","include_decompile":true,"include_proto":true},{"addr":"0x736d20","include_decompile":true,"include_proto":true},{"addr":"0x736d50","include_decompile":true,"include_proto":true},{"addr":"0x736d80","include_decompile":true,"include_proto":true},{"addr":"0x736db0","include_decompile":true,"include_proto":true},{"addr":"0x736de0","include_decompile":true,"include_proto":true},{"addr":"0x736e10","include_decompile":true,"include_proto":true},{"addr":"0x736e40","include_decompile":true,"include_proto":true},{"addr":"0x736ef0","include_decompile":true,"include_proto":true},{"addr":"0x736f20","include_decompile":true,"include_proto":true},{"addr":"0x736f50","include_decompile":true,"include_proto":true},{"addr":"0x7371f0","include_decompile":true,"include_proto":true},{"addr":"0x737280","include_decompile":true,"include_proto":true},{"addr":"0x737370","include_decompile":true,"include_proto":true},{"addr":"0x737380","include_decompile":true,"include_proto":true},{"addr":"0x737390","include_decompile":true,"include_proto":true},{"addr":"0x7374d0","include_decompile":true,"include_proto":true},{"addr":"0x737510","include_decompile":true,"include_proto":true},{"addr":"0x7375a0","include_decompile":true,"include_proto":true},{"addr":"0x737690","include_decompile":true,"include_proto":true},{"addr":"0x737760","include_decompile":true,"include_proto":true},{"addr":"0x7377c0","include_decompile":true,"include_proto":true},{"addr":"0x737830","include_decompile":true,"include_proto":true},{"addr":"0x737be0","include_decompile":true,"include_proto":true},{"addr":"0x738000","include_decompile":true,"include_proto":true},{"addr":"0x7385b0","include_decompile":true,"include_proto":true},{"addr":"0x7385f0","include_decompile":true,"include_proto":true},{"addr":"0x738b00","include_decompile":true,"include_proto":true},{"addr":"0x738f80","include_decompile":true,"include_proto":true},{"addr":"0x739540","include_decompile":true,"include_proto":true},{"addr":"0x739580","include_decompile":true,"include_proto":true},{"addr":"0x739df0","include_decompile":true,"include_proto":true},{"addr":"0x73a430","include_decompile":true,"include_proto":true},{"addr":"0x73ab80","include_decompile":true,"include_proto":true},{"addr":"0x73abc0","include_decompile":true,"include_proto":true},{"addr":"0x73ac00","include_decompile":true,"include_proto":true},{"addr":"0x73ac30","include_decompile":true,"include_proto":true},{"addr":"0x73aca0","include_decompile":true,"include_proto":true},{"addr":"0x73b680","include_decompile":true,"include_proto":true},{"addr":"0x73b870","include_decompile":true,"include_proto":true},{"addr":"0x73b8c0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0136', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0136: empty response'); return; }
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
      console.log('Batch 0136: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0136 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0136 conn error:', e.message));
req.write(body);
req.end();
