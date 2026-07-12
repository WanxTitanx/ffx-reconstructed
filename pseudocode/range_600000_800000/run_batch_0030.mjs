
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x630a10","include_decompile":true,"include_proto":true},{"addr":"0x630a20","include_decompile":true,"include_proto":true},{"addr":"0x630ad0","include_decompile":true,"include_proto":true},{"addr":"0x630b50","include_decompile":true,"include_proto":true},{"addr":"0x630c10","include_decompile":true,"include_proto":true},{"addr":"0x630ce0","include_decompile":true,"include_proto":true},{"addr":"0x630dd0","include_decompile":true,"include_proto":true},{"addr":"0x630de0","include_decompile":true,"include_proto":true},{"addr":"0x630df0","include_decompile":true,"include_proto":true},{"addr":"0x630e00","include_decompile":true,"include_proto":true},{"addr":"0x630e10","include_decompile":true,"include_proto":true},{"addr":"0x630e30","include_decompile":true,"include_proto":true},{"addr":"0x630e40","include_decompile":true,"include_proto":true},{"addr":"0x630e50","include_decompile":true,"include_proto":true},{"addr":"0x630e60","include_decompile":true,"include_proto":true},{"addr":"0x630e80","include_decompile":true,"include_proto":true},{"addr":"0x630ea0","include_decompile":true,"include_proto":true},{"addr":"0x630ec0","include_decompile":true,"include_proto":true},{"addr":"0x630ee0","include_decompile":true,"include_proto":true},{"addr":"0x630f90","include_decompile":true,"include_proto":true},{"addr":"0x630fa0","include_decompile":true,"include_proto":true},{"addr":"0x630fd0","include_decompile":true,"include_proto":true},{"addr":"0x631030","include_decompile":true,"include_proto":true},{"addr":"0x631070","include_decompile":true,"include_proto":true},{"addr":"0x631090","include_decompile":true,"include_proto":true},{"addr":"0x6310b0","include_decompile":true,"include_proto":true},{"addr":"0x6310d0","include_decompile":true,"include_proto":true},{"addr":"0x6310f0","include_decompile":true,"include_proto":true},{"addr":"0x6311c0","include_decompile":true,"include_proto":true},{"addr":"0x6311e0","include_decompile":true,"include_proto":true},{"addr":"0x631200","include_decompile":true,"include_proto":true},{"addr":"0x631210","include_decompile":true,"include_proto":true},{"addr":"0x631220","include_decompile":true,"include_proto":true},{"addr":"0x631230","include_decompile":true,"include_proto":true},{"addr":"0x6312c0","include_decompile":true,"include_proto":true},{"addr":"0x631360","include_decompile":true,"include_proto":true},{"addr":"0x631410","include_decompile":true,"include_proto":true},{"addr":"0x631420","include_decompile":true,"include_proto":true},{"addr":"0x6314a0","include_decompile":true,"include_proto":true},{"addr":"0x6314b0","include_decompile":true,"include_proto":true},{"addr":"0x6314d0","include_decompile":true,"include_proto":true},{"addr":"0x6314e0","include_decompile":true,"include_proto":true},{"addr":"0x6314f0","include_decompile":true,"include_proto":true},{"addr":"0x631510","include_decompile":true,"include_proto":true},{"addr":"0x631530","include_decompile":true,"include_proto":true},{"addr":"0x631550","include_decompile":true,"include_proto":true},{"addr":"0x631600","include_decompile":true,"include_proto":true},{"addr":"0x631700","include_decompile":true,"include_proto":true},{"addr":"0x631770","include_decompile":true,"include_proto":true},{"addr":"0x632ae0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0030', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0030: empty response'); return; }
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
      console.log('Batch 0030: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0030 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0030 conn error:', e.message));
req.write(body);
req.end();
