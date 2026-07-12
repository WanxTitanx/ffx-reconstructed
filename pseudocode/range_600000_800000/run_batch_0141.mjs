
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x756360","include_decompile":true,"include_proto":true},{"addr":"0x7563b0","include_decompile":true,"include_proto":true},{"addr":"0x756410","include_decompile":true,"include_proto":true},{"addr":"0x7566f0","include_decompile":true,"include_proto":true},{"addr":"0x756790","include_decompile":true,"include_proto":true},{"addr":"0x7567c0","include_decompile":true,"include_proto":true},{"addr":"0x7567d0","include_decompile":true,"include_proto":true},{"addr":"0x756830","include_decompile":true,"include_proto":true},{"addr":"0x756e10","include_decompile":true,"include_proto":true},{"addr":"0x757300","include_decompile":true,"include_proto":true},{"addr":"0x757330","include_decompile":true,"include_proto":true},{"addr":"0x757340","include_decompile":true,"include_proto":true},{"addr":"0x757370","include_decompile":true,"include_proto":true},{"addr":"0x757460","include_decompile":true,"include_proto":true},{"addr":"0x7574b0","include_decompile":true,"include_proto":true},{"addr":"0x757560","include_decompile":true,"include_proto":true},{"addr":"0x757580","include_decompile":true,"include_proto":true},{"addr":"0x757840","include_decompile":true,"include_proto":true},{"addr":"0x757860","include_decompile":true,"include_proto":true},{"addr":"0x757930","include_decompile":true,"include_proto":true},{"addr":"0x757c20","include_decompile":true,"include_proto":true},{"addr":"0x757c40","include_decompile":true,"include_proto":true},{"addr":"0x757d20","include_decompile":true,"include_proto":true},{"addr":"0x757f80","include_decompile":true,"include_proto":true},{"addr":"0x757fa0","include_decompile":true,"include_proto":true},{"addr":"0x757fb0","include_decompile":true,"include_proto":true},{"addr":"0x757fc0","include_decompile":true,"include_proto":true},{"addr":"0x7580e0","include_decompile":true,"include_proto":true},{"addr":"0x758340","include_decompile":true,"include_proto":true},{"addr":"0x758360","include_decompile":true,"include_proto":true},{"addr":"0x7583d0","include_decompile":true,"include_proto":true},{"addr":"0x7585a0","include_decompile":true,"include_proto":true},{"addr":"0x7585c0","include_decompile":true,"include_proto":true},{"addr":"0x758880","include_decompile":true,"include_proto":true},{"addr":"0x7588a0","include_decompile":true,"include_proto":true},{"addr":"0x758910","include_decompile":true,"include_proto":true},{"addr":"0x758930","include_decompile":true,"include_proto":true},{"addr":"0x758a50","include_decompile":true,"include_proto":true},{"addr":"0x758ac0","include_decompile":true,"include_proto":true},{"addr":"0x758ae0","include_decompile":true,"include_proto":true},{"addr":"0x758bd0","include_decompile":true,"include_proto":true},{"addr":"0x758ec0","include_decompile":true,"include_proto":true},{"addr":"0x758ee0","include_decompile":true,"include_proto":true},{"addr":"0x759010","include_decompile":true,"include_proto":true},{"addr":"0x759080","include_decompile":true,"include_proto":true},{"addr":"0x7590b0","include_decompile":true,"include_proto":true},{"addr":"0x7591d0","include_decompile":true,"include_proto":true},{"addr":"0x7592f0","include_decompile":true,"include_proto":true},{"addr":"0x759360","include_decompile":true,"include_proto":true},{"addr":"0x759390","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0141', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0141: empty response'); return; }
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
      console.log('Batch 0141: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0141 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0141 conn error:', e.message));
req.write(body);
req.end();
