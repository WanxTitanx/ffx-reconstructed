
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x785280","include_decompile":true,"include_proto":true},{"addr":"0x785290","include_decompile":true,"include_proto":true},{"addr":"0x7852b0","include_decompile":true,"include_proto":true},{"addr":"0x7852d0","include_decompile":true,"include_proto":true},{"addr":"0x7852f0","include_decompile":true,"include_proto":true},{"addr":"0x785300","include_decompile":true,"include_proto":true},{"addr":"0x785310","include_decompile":true,"include_proto":true},{"addr":"0x785320","include_decompile":true,"include_proto":true},{"addr":"0x785330","include_decompile":true,"include_proto":true},{"addr":"0x785350","include_decompile":true,"include_proto":true},{"addr":"0x785360","include_decompile":true,"include_proto":true},{"addr":"0x785370","include_decompile":true,"include_proto":true},{"addr":"0x785390","include_decompile":true,"include_proto":true},{"addr":"0x7853b0","include_decompile":true,"include_proto":true},{"addr":"0x7853f0","include_decompile":true,"include_proto":true},{"addr":"0x785420","include_decompile":true,"include_proto":true},{"addr":"0x785440","include_decompile":true,"include_proto":true},{"addr":"0x785460","include_decompile":true,"include_proto":true},{"addr":"0x785480","include_decompile":true,"include_proto":true},{"addr":"0x7854a0","include_decompile":true,"include_proto":true},{"addr":"0x7854c0","include_decompile":true,"include_proto":true},{"addr":"0x7854d0","include_decompile":true,"include_proto":true},{"addr":"0x785a20","include_decompile":true,"include_proto":true},{"addr":"0x785a50","include_decompile":true,"include_proto":true},{"addr":"0x785a60","include_decompile":true,"include_proto":true},{"addr":"0x785a90","include_decompile":true,"include_proto":true},{"addr":"0x785ac0","include_decompile":true,"include_proto":true},{"addr":"0x785ba0","include_decompile":true,"include_proto":true},{"addr":"0x785bd0","include_decompile":true,"include_proto":true},{"addr":"0x785c20","include_decompile":true,"include_proto":true},{"addr":"0x785ce0","include_decompile":true,"include_proto":true},{"addr":"0x785d10","include_decompile":true,"include_proto":true},{"addr":"0x785e00","include_decompile":true,"include_proto":true},{"addr":"0x785ec0","include_decompile":true,"include_proto":true},{"addr":"0x785f50","include_decompile":true,"include_proto":true},{"addr":"0x785f90","include_decompile":true,"include_proto":true},{"addr":"0x786000","include_decompile":true,"include_proto":true},{"addr":"0x786080","include_decompile":true,"include_proto":true},{"addr":"0x786170","include_decompile":true,"include_proto":true},{"addr":"0x7861b0","include_decompile":true,"include_proto":true},{"addr":"0x7869c0","include_decompile":true,"include_proto":true},{"addr":"0x7869f0","include_decompile":true,"include_proto":true},{"addr":"0x786a10","include_decompile":true,"include_proto":true},{"addr":"0x786a70","include_decompile":true,"include_proto":true},{"addr":"0x786b60","include_decompile":true,"include_proto":true},{"addr":"0x786bc0","include_decompile":true,"include_proto":true},{"addr":"0x786fb0","include_decompile":true,"include_proto":true},{"addr":"0x787010","include_decompile":true,"include_proto":true},{"addr":"0x787190","include_decompile":true,"include_proto":true},{"addr":"0x7871c0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0165', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0165: empty response'); return; }
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
      console.log('Batch 0165: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0165 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0165 conn error:', e.message));
req.write(body);
req.end();
