
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x601450","include_decompile":true,"include_proto":true},{"addr":"0x601480","include_decompile":true,"include_proto":true},{"addr":"0x6014b0","include_decompile":true,"include_proto":true},{"addr":"0x6014d0","include_decompile":true,"include_proto":true},{"addr":"0x601500","include_decompile":true,"include_proto":true},{"addr":"0x601530","include_decompile":true,"include_proto":true},{"addr":"0x601560","include_decompile":true,"include_proto":true},{"addr":"0x601580","include_decompile":true,"include_proto":true},{"addr":"0x6015b0","include_decompile":true,"include_proto":true},{"addr":"0x6015e0","include_decompile":true,"include_proto":true},{"addr":"0x601610","include_decompile":true,"include_proto":true},{"addr":"0x601630","include_decompile":true,"include_proto":true},{"addr":"0x601650","include_decompile":true,"include_proto":true},{"addr":"0x601670","include_decompile":true,"include_proto":true},{"addr":"0x6016a0","include_decompile":true,"include_proto":true},{"addr":"0x6016d0","include_decompile":true,"include_proto":true},{"addr":"0x601700","include_decompile":true,"include_proto":true},{"addr":"0x601730","include_decompile":true,"include_proto":true},{"addr":"0x601760","include_decompile":true,"include_proto":true},{"addr":"0x601790","include_decompile":true,"include_proto":true},{"addr":"0x6017c0","include_decompile":true,"include_proto":true},{"addr":"0x6017f0","include_decompile":true,"include_proto":true},{"addr":"0x601810","include_decompile":true,"include_proto":true},{"addr":"0x601830","include_decompile":true,"include_proto":true},{"addr":"0x601850","include_decompile":true,"include_proto":true},{"addr":"0x601880","include_decompile":true,"include_proto":true},{"addr":"0x601910","include_decompile":true,"include_proto":true},{"addr":"0x601a00","include_decompile":true,"include_proto":true},{"addr":"0x601a60","include_decompile":true,"include_proto":true},{"addr":"0x601a70","include_decompile":true,"include_proto":true},{"addr":"0x601b70","include_decompile":true,"include_proto":true},{"addr":"0x601be0","include_decompile":true,"include_proto":true},{"addr":"0x601c20","include_decompile":true,"include_proto":true},{"addr":"0x601cf0","include_decompile":true,"include_proto":true},{"addr":"0x601e20","include_decompile":true,"include_proto":true},{"addr":"0x602040","include_decompile":true,"include_proto":true},{"addr":"0x602050","include_decompile":true,"include_proto":true},{"addr":"0x602500","include_decompile":true,"include_proto":true},{"addr":"0x6028e0","include_decompile":true,"include_proto":true},{"addr":"0x602960","include_decompile":true,"include_proto":true},{"addr":"0x6029d0","include_decompile":true,"include_proto":true},{"addr":"0x602ac0","include_decompile":true,"include_proto":true},{"addr":"0x602b60","include_decompile":true,"include_proto":true},{"addr":"0x602c20","include_decompile":true,"include_proto":true},{"addr":"0x602cc0","include_decompile":true,"include_proto":true},{"addr":"0x602d50","include_decompile":true,"include_proto":true},{"addr":"0x602e30","include_decompile":true,"include_proto":true},{"addr":"0x602fd0","include_decompile":true,"include_proto":true},{"addr":"0x6030a0","include_decompile":true,"include_proto":true},{"addr":"0x603110","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0001', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0001: empty response'); return; }
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
      console.log('Batch 0001: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0001 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0001 conn error:', e.message));
req.write(body);
req.end();
