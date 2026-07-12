
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x773080","include_decompile":true,"include_proto":true},{"addr":"0x7730b0","include_decompile":true,"include_proto":true},{"addr":"0x7730d0","include_decompile":true,"include_proto":true},{"addr":"0x7730f0","include_decompile":true,"include_proto":true},{"addr":"0x773120","include_decompile":true,"include_proto":true},{"addr":"0x773140","include_decompile":true,"include_proto":true},{"addr":"0x773160","include_decompile":true,"include_proto":true},{"addr":"0x773190","include_decompile":true,"include_proto":true},{"addr":"0x7731b0","include_decompile":true,"include_proto":true},{"addr":"0x7731d0","include_decompile":true,"include_proto":true},{"addr":"0x7731f0","include_decompile":true,"include_proto":true},{"addr":"0x773220","include_decompile":true,"include_proto":true},{"addr":"0x773240","include_decompile":true,"include_proto":true},{"addr":"0x773260","include_decompile":true,"include_proto":true},{"addr":"0x773280","include_decompile":true,"include_proto":true},{"addr":"0x7732b0","include_decompile":true,"include_proto":true},{"addr":"0x7732d0","include_decompile":true,"include_proto":true},{"addr":"0x7732f0","include_decompile":true,"include_proto":true},{"addr":"0x773320","include_decompile":true,"include_proto":true},{"addr":"0x773340","include_decompile":true,"include_proto":true},{"addr":"0x773360","include_decompile":true,"include_proto":true},{"addr":"0x773390","include_decompile":true,"include_proto":true},{"addr":"0x7733b0","include_decompile":true,"include_proto":true},{"addr":"0x7733d0","include_decompile":true,"include_proto":true},{"addr":"0x773400","include_decompile":true,"include_proto":true},{"addr":"0x773420","include_decompile":true,"include_proto":true},{"addr":"0x773440","include_decompile":true,"include_proto":true},{"addr":"0x773460","include_decompile":true,"include_proto":true},{"addr":"0x773490","include_decompile":true,"include_proto":true},{"addr":"0x7734b0","include_decompile":true,"include_proto":true},{"addr":"0x7734d0","include_decompile":true,"include_proto":true},{"addr":"0x7734f0","include_decompile":true,"include_proto":true},{"addr":"0x773520","include_decompile":true,"include_proto":true},{"addr":"0x773540","include_decompile":true,"include_proto":true},{"addr":"0x773560","include_decompile":true,"include_proto":true},{"addr":"0x773590","include_decompile":true,"include_proto":true},{"addr":"0x7735b0","include_decompile":true,"include_proto":true},{"addr":"0x7735d0","include_decompile":true,"include_proto":true},{"addr":"0x773600","include_decompile":true,"include_proto":true},{"addr":"0x773620","include_decompile":true,"include_proto":true},{"addr":"0x773640","include_decompile":true,"include_proto":true},{"addr":"0x773650","include_decompile":true,"include_proto":true},{"addr":"0x773670","include_decompile":true,"include_proto":true},{"addr":"0x773690","include_decompile":true,"include_proto":true},{"addr":"0x7736b0","include_decompile":true,"include_proto":true},{"addr":"0x7736d0","include_decompile":true,"include_proto":true},{"addr":"0x7736f0","include_decompile":true,"include_proto":true},{"addr":"0x773710","include_decompile":true,"include_proto":true},{"addr":"0x773730","include_decompile":true,"include_proto":true},{"addr":"0x773750","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0155', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0155: empty response'); return; }
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
      console.log('Batch 0155: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0155 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0155 conn error:', e.message));
req.write(body);
req.end();
