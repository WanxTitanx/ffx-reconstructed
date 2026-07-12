
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x605080","include_decompile":true,"include_proto":true},{"addr":"0x6050f0","include_decompile":true,"include_proto":true},{"addr":"0x605120","include_decompile":true,"include_proto":true},{"addr":"0x605150","include_decompile":true,"include_proto":true},{"addr":"0x605180","include_decompile":true,"include_proto":true},{"addr":"0x6051f0","include_decompile":true,"include_proto":true},{"addr":"0x605260","include_decompile":true,"include_proto":true},{"addr":"0x6052d0","include_decompile":true,"include_proto":true},{"addr":"0x605340","include_decompile":true,"include_proto":true},{"addr":"0x6053b0","include_decompile":true,"include_proto":true},{"addr":"0x605420","include_decompile":true,"include_proto":true},{"addr":"0x605490","include_decompile":true,"include_proto":true},{"addr":"0x605500","include_decompile":true,"include_proto":true},{"addr":"0x605530","include_decompile":true,"include_proto":true},{"addr":"0x605560","include_decompile":true,"include_proto":true},{"addr":"0x605590","include_decompile":true,"include_proto":true},{"addr":"0x6055e0","include_decompile":true,"include_proto":true},{"addr":"0x605660","include_decompile":true,"include_proto":true},{"addr":"0x605820","include_decompile":true,"include_proto":true},{"addr":"0x6058e0","include_decompile":true,"include_proto":true},{"addr":"0x6058f0","include_decompile":true,"include_proto":true},{"addr":"0x605a10","include_decompile":true,"include_proto":true},{"addr":"0x605a20","include_decompile":true,"include_proto":true},{"addr":"0x605a70","include_decompile":true,"include_proto":true},{"addr":"0x605aa0","include_decompile":true,"include_proto":true},{"addr":"0x6064a0","include_decompile":true,"include_proto":true},{"addr":"0x6067a0","include_decompile":true,"include_proto":true},{"addr":"0x606820","include_decompile":true,"include_proto":true},{"addr":"0x606ac0","include_decompile":true,"include_proto":true},{"addr":"0x607010","include_decompile":true,"include_proto":true},{"addr":"0x6070b0","include_decompile":true,"include_proto":true},{"addr":"0x6075a0","include_decompile":true,"include_proto":true},{"addr":"0x607600","include_decompile":true,"include_proto":true},{"addr":"0x607680","include_decompile":true,"include_proto":true},{"addr":"0x6076d0","include_decompile":true,"include_proto":true},{"addr":"0x607720","include_decompile":true,"include_proto":true},{"addr":"0x607770","include_decompile":true,"include_proto":true},{"addr":"0x6077a0","include_decompile":true,"include_proto":true},{"addr":"0x6077f0","include_decompile":true,"include_proto":true},{"addr":"0x607830","include_decompile":true,"include_proto":true},{"addr":"0x607880","include_decompile":true,"include_proto":true},{"addr":"0x6078a0","include_decompile":true,"include_proto":true},{"addr":"0x6078d0","include_decompile":true,"include_proto":true},{"addr":"0x607900","include_decompile":true,"include_proto":true},{"addr":"0x607950","include_decompile":true,"include_proto":true},{"addr":"0x6079c0","include_decompile":true,"include_proto":true},{"addr":"0x607a40","include_decompile":true,"include_proto":true},{"addr":"0x607ac0","include_decompile":true,"include_proto":true},{"addr":"0x607b50","include_decompile":true,"include_proto":true},{"addr":"0x607bc0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0003', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0003: empty response'); return; }
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
      console.log('Batch 0003: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0003 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0003 conn error:', e.message));
req.write(body);
req.end();
