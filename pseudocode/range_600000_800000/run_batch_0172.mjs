
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x794c30","include_decompile":true,"include_proto":true},{"addr":"0x794cb0","include_decompile":true,"include_proto":true},{"addr":"0x794d30","include_decompile":true,"include_proto":true},{"addr":"0x794d80","include_decompile":true,"include_proto":true},{"addr":"0x794dc0","include_decompile":true,"include_proto":true},{"addr":"0x794e10","include_decompile":true,"include_proto":true},{"addr":"0x794e90","include_decompile":true,"include_proto":true},{"addr":"0x794ed0","include_decompile":true,"include_proto":true},{"addr":"0x794f30","include_decompile":true,"include_proto":true},{"addr":"0x794f80","include_decompile":true,"include_proto":true},{"addr":"0x794fc0","include_decompile":true,"include_proto":true},{"addr":"0x795000","include_decompile":true,"include_proto":true},{"addr":"0x795050","include_decompile":true,"include_proto":true},{"addr":"0x795090","include_decompile":true,"include_proto":true},{"addr":"0x7950c0","include_decompile":true,"include_proto":true},{"addr":"0x795100","include_decompile":true,"include_proto":true},{"addr":"0x795180","include_decompile":true,"include_proto":true},{"addr":"0x795260","include_decompile":true,"include_proto":true},{"addr":"0x795560","include_decompile":true,"include_proto":true},{"addr":"0x7955a0","include_decompile":true,"include_proto":true},{"addr":"0x795620","include_decompile":true,"include_proto":true},{"addr":"0x795650","include_decompile":true,"include_proto":true},{"addr":"0x795670","include_decompile":true,"include_proto":true},{"addr":"0x7956b0","include_decompile":true,"include_proto":true},{"addr":"0x7956f0","include_decompile":true,"include_proto":true},{"addr":"0x795730","include_decompile":true,"include_proto":true},{"addr":"0x795790","include_decompile":true,"include_proto":true},{"addr":"0x7957d0","include_decompile":true,"include_proto":true},{"addr":"0x795810","include_decompile":true,"include_proto":true},{"addr":"0x795850","include_decompile":true,"include_proto":true},{"addr":"0x795890","include_decompile":true,"include_proto":true},{"addr":"0x7958d0","include_decompile":true,"include_proto":true},{"addr":"0x795930","include_decompile":true,"include_proto":true},{"addr":"0x795980","include_decompile":true,"include_proto":true},{"addr":"0x795990","include_decompile":true,"include_proto":true},{"addr":"0x795a30","include_decompile":true,"include_proto":true},{"addr":"0x795a70","include_decompile":true,"include_proto":true},{"addr":"0x795ab0","include_decompile":true,"include_proto":true},{"addr":"0x795ad0","include_decompile":true,"include_proto":true},{"addr":"0x795b20","include_decompile":true,"include_proto":true},{"addr":"0x795b50","include_decompile":true,"include_proto":true},{"addr":"0x795bc0","include_decompile":true,"include_proto":true},{"addr":"0x795c10","include_decompile":true,"include_proto":true},{"addr":"0x795c50","include_decompile":true,"include_proto":true},{"addr":"0x795c80","include_decompile":true,"include_proto":true},{"addr":"0x795ca0","include_decompile":true,"include_proto":true},{"addr":"0x795d50","include_decompile":true,"include_proto":true},{"addr":"0x795db0","include_decompile":true,"include_proto":true},{"addr":"0x795de0","include_decompile":true,"include_proto":true},{"addr":"0x795e30","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0172', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0172: empty response'); return; }
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
      console.log('Batch 0172: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0172 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0172 conn error:', e.message));
req.write(body);
req.end();
