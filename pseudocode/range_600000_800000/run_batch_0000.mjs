
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x600920","include_decompile":true,"include_proto":true},{"addr":"0x600960","include_decompile":true,"include_proto":true},{"addr":"0x6009a0","include_decompile":true,"include_proto":true},{"addr":"0x6009e0","include_decompile":true,"include_proto":true},{"addr":"0x600a20","include_decompile":true,"include_proto":true},{"addr":"0x600a60","include_decompile":true,"include_proto":true},{"addr":"0x600aa0","include_decompile":true,"include_proto":true},{"addr":"0x600ae0","include_decompile":true,"include_proto":true},{"addr":"0x600b20","include_decompile":true,"include_proto":true},{"addr":"0x600b60","include_decompile":true,"include_proto":true},{"addr":"0x600ba0","include_decompile":true,"include_proto":true},{"addr":"0x600be0","include_decompile":true,"include_proto":true},{"addr":"0x600c20","include_decompile":true,"include_proto":true},{"addr":"0x600c60","include_decompile":true,"include_proto":true},{"addr":"0x600ca0","include_decompile":true,"include_proto":true},{"addr":"0x600ce0","include_decompile":true,"include_proto":true},{"addr":"0x600d20","include_decompile":true,"include_proto":true},{"addr":"0x600d60","include_decompile":true,"include_proto":true},{"addr":"0x600da0","include_decompile":true,"include_proto":true},{"addr":"0x600de0","include_decompile":true,"include_proto":true},{"addr":"0x600e20","include_decompile":true,"include_proto":true},{"addr":"0x600e60","include_decompile":true,"include_proto":true},{"addr":"0x600ea0","include_decompile":true,"include_proto":true},{"addr":"0x600ee0","include_decompile":true,"include_proto":true},{"addr":"0x600f20","include_decompile":true,"include_proto":true},{"addr":"0x600f60","include_decompile":true,"include_proto":true},{"addr":"0x600fa0","include_decompile":true,"include_proto":true},{"addr":"0x600fe0","include_decompile":true,"include_proto":true},{"addr":"0x601020","include_decompile":true,"include_proto":true},{"addr":"0x601060","include_decompile":true,"include_proto":true},{"addr":"0x6010a0","include_decompile":true,"include_proto":true},{"addr":"0x6010e0","include_decompile":true,"include_proto":true},{"addr":"0x601120","include_decompile":true,"include_proto":true},{"addr":"0x601160","include_decompile":true,"include_proto":true},{"addr":"0x6011a0","include_decompile":true,"include_proto":true},{"addr":"0x6011c0","include_decompile":true,"include_proto":true},{"addr":"0x6011f0","include_decompile":true,"include_proto":true},{"addr":"0x601220","include_decompile":true,"include_proto":true},{"addr":"0x601250","include_decompile":true,"include_proto":true},{"addr":"0x601270","include_decompile":true,"include_proto":true},{"addr":"0x6012a0","include_decompile":true,"include_proto":true},{"addr":"0x6012d0","include_decompile":true,"include_proto":true},{"addr":"0x601300","include_decompile":true,"include_proto":true},{"addr":"0x601330","include_decompile":true,"include_proto":true},{"addr":"0x601350","include_decompile":true,"include_proto":true},{"addr":"0x601370","include_decompile":true,"include_proto":true},{"addr":"0x601390","include_decompile":true,"include_proto":true},{"addr":"0x6013c0","include_decompile":true,"include_proto":true},{"addr":"0x6013f0","include_decompile":true,"include_proto":true},{"addr":"0x601420","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0000', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0000: empty response'); return; }
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
      console.log('Batch 0000: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0000 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0000 conn error:', e.message));
req.write(body);
req.end();
