
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x632b70","include_decompile":true,"include_proto":true},{"addr":"0x632be0","include_decompile":true,"include_proto":true},{"addr":"0x633290","include_decompile":true,"include_proto":true},{"addr":"0x633370","include_decompile":true,"include_proto":true},{"addr":"0x633380","include_decompile":true,"include_proto":true},{"addr":"0x633390","include_decompile":true,"include_proto":true},{"addr":"0x6333a0","include_decompile":true,"include_proto":true},{"addr":"0x6333b0","include_decompile":true,"include_proto":true},{"addr":"0x6333c0","include_decompile":true,"include_proto":true},{"addr":"0x6333d0","include_decompile":true,"include_proto":true},{"addr":"0x6333f0","include_decompile":true,"include_proto":true},{"addr":"0x633430","include_decompile":true,"include_proto":true},{"addr":"0x633440","include_decompile":true,"include_proto":true},{"addr":"0x633450","include_decompile":true,"include_proto":true},{"addr":"0x633460","include_decompile":true,"include_proto":true},{"addr":"0x633470","include_decompile":true,"include_proto":true},{"addr":"0x633480","include_decompile":true,"include_proto":true},{"addr":"0x633490","include_decompile":true,"include_proto":true},{"addr":"0x6334a0","include_decompile":true,"include_proto":true},{"addr":"0x6334b0","include_decompile":true,"include_proto":true},{"addr":"0x6334c0","include_decompile":true,"include_proto":true},{"addr":"0x6334d0","include_decompile":true,"include_proto":true},{"addr":"0x6334e0","include_decompile":true,"include_proto":true},{"addr":"0x6334f0","include_decompile":true,"include_proto":true},{"addr":"0x633500","include_decompile":true,"include_proto":true},{"addr":"0x633510","include_decompile":true,"include_proto":true},{"addr":"0x633520","include_decompile":true,"include_proto":true},{"addr":"0x633530","include_decompile":true,"include_proto":true},{"addr":"0x633540","include_decompile":true,"include_proto":true},{"addr":"0x633550","include_decompile":true,"include_proto":true},{"addr":"0x633560","include_decompile":true,"include_proto":true},{"addr":"0x633570","include_decompile":true,"include_proto":true},{"addr":"0x633580","include_decompile":true,"include_proto":true},{"addr":"0x633590","include_decompile":true,"include_proto":true},{"addr":"0x6335a0","include_decompile":true,"include_proto":true},{"addr":"0x6336d0","include_decompile":true,"include_proto":true},{"addr":"0x6336e0","include_decompile":true,"include_proto":true},{"addr":"0x6336f0","include_decompile":true,"include_proto":true},{"addr":"0x633700","include_decompile":true,"include_proto":true},{"addr":"0x633710","include_decompile":true,"include_proto":true},{"addr":"0x633720","include_decompile":true,"include_proto":true},{"addr":"0x633730","include_decompile":true,"include_proto":true},{"addr":"0x633740","include_decompile":true,"include_proto":true},{"addr":"0x633750","include_decompile":true,"include_proto":true},{"addr":"0x633820","include_decompile":true,"include_proto":true},{"addr":"0x633910","include_decompile":true,"include_proto":true},{"addr":"0x633920","include_decompile":true,"include_proto":true},{"addr":"0x633970","include_decompile":true,"include_proto":true},{"addr":"0x633980","include_decompile":true,"include_proto":true},{"addr":"0x633990","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0031', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0031: empty response'); return; }
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
      console.log('Batch 0031: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0031 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0031 conn error:', e.message));
req.write(body);
req.end();
