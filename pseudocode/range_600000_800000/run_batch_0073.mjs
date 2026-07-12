
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x680780","include_decompile":true,"include_proto":true},{"addr":"0x6807a0","include_decompile":true,"include_proto":true},{"addr":"0x6807c0","include_decompile":true,"include_proto":true},{"addr":"0x680830","include_decompile":true,"include_proto":true},{"addr":"0x6808a0","include_decompile":true,"include_proto":true},{"addr":"0x680910","include_decompile":true,"include_proto":true},{"addr":"0x680920","include_decompile":true,"include_proto":true},{"addr":"0x680930","include_decompile":true,"include_proto":true},{"addr":"0x6809d0","include_decompile":true,"include_proto":true},{"addr":"0x6809e0","include_decompile":true,"include_proto":true},{"addr":"0x680a50","include_decompile":true,"include_proto":true},{"addr":"0x680a60","include_decompile":true,"include_proto":true},{"addr":"0x680a70","include_decompile":true,"include_proto":true},{"addr":"0x680a80","include_decompile":true,"include_proto":true},{"addr":"0x680a90","include_decompile":true,"include_proto":true},{"addr":"0x680aa0","include_decompile":true,"include_proto":true},{"addr":"0x680ab0","include_decompile":true,"include_proto":true},{"addr":"0x680ac0","include_decompile":true,"include_proto":true},{"addr":"0x680ad0","include_decompile":true,"include_proto":true},{"addr":"0x680ae0","include_decompile":true,"include_proto":true},{"addr":"0x680af0","include_decompile":true,"include_proto":true},{"addr":"0x680b20","include_decompile":true,"include_proto":true},{"addr":"0x681940","include_decompile":true,"include_proto":true},{"addr":"0x6819a0","include_decompile":true,"include_proto":true},{"addr":"0x681a20","include_decompile":true,"include_proto":true},{"addr":"0x681a70","include_decompile":true,"include_proto":true},{"addr":"0x681a80","include_decompile":true,"include_proto":true},{"addr":"0x681b20","include_decompile":true,"include_proto":true},{"addr":"0x681c80","include_decompile":true,"include_proto":true},{"addr":"0x681db0","include_decompile":true,"include_proto":true},{"addr":"0x684540","include_decompile":true,"include_proto":true},{"addr":"0x684c00","include_decompile":true,"include_proto":true},{"addr":"0x684ca0","include_decompile":true,"include_proto":true},{"addr":"0x684e40","include_decompile":true,"include_proto":true},{"addr":"0x684e70","include_decompile":true,"include_proto":true},{"addr":"0x685090","include_decompile":true,"include_proto":true},{"addr":"0x685370","include_decompile":true,"include_proto":true},{"addr":"0x685960","include_decompile":true,"include_proto":true},{"addr":"0x6859e0","include_decompile":true,"include_proto":true},{"addr":"0x686d50","include_decompile":true,"include_proto":true},{"addr":"0x686df0","include_decompile":true,"include_proto":true},{"addr":"0x686e30","include_decompile":true,"include_proto":true},{"addr":"0x686e50","include_decompile":true,"include_proto":true},{"addr":"0x686e70","include_decompile":true,"include_proto":true},{"addr":"0x686e80","include_decompile":true,"include_proto":true},{"addr":"0x686f40","include_decompile":true,"include_proto":true},{"addr":"0x687020","include_decompile":true,"include_proto":true},{"addr":"0x687030","include_decompile":true,"include_proto":true},{"addr":"0x687040","include_decompile":true,"include_proto":true},{"addr":"0x687050","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0073', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0073: empty response'); return; }
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
      console.log('Batch 0073: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0073 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0073 conn error:', e.message));
req.write(body);
req.end();
