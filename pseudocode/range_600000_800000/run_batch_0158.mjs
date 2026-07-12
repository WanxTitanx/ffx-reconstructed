
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x774420","include_decompile":true,"include_proto":true},{"addr":"0x774440","include_decompile":true,"include_proto":true},{"addr":"0x774460","include_decompile":true,"include_proto":true},{"addr":"0x774480","include_decompile":true,"include_proto":true},{"addr":"0x7744a0","include_decompile":true,"include_proto":true},{"addr":"0x7744d0","include_decompile":true,"include_proto":true},{"addr":"0x7744f0","include_decompile":true,"include_proto":true},{"addr":"0x774520","include_decompile":true,"include_proto":true},{"addr":"0x774540","include_decompile":true,"include_proto":true},{"addr":"0x774560","include_decompile":true,"include_proto":true},{"addr":"0x774590","include_decompile":true,"include_proto":true},{"addr":"0x7745b0","include_decompile":true,"include_proto":true},{"addr":"0x7745e0","include_decompile":true,"include_proto":true},{"addr":"0x774600","include_decompile":true,"include_proto":true},{"addr":"0x774630","include_decompile":true,"include_proto":true},{"addr":"0x774780","include_decompile":true,"include_proto":true},{"addr":"0x774790","include_decompile":true,"include_proto":true},{"addr":"0x774830","include_decompile":true,"include_proto":true},{"addr":"0x774850","include_decompile":true,"include_proto":true},{"addr":"0x774970","include_decompile":true,"include_proto":true},{"addr":"0x774b60","include_decompile":true,"include_proto":true},{"addr":"0x774bb0","include_decompile":true,"include_proto":true},{"addr":"0x774bf0","include_decompile":true,"include_proto":true},{"addr":"0x774d10","include_decompile":true,"include_proto":true},{"addr":"0x774dc0","include_decompile":true,"include_proto":true},{"addr":"0x775100","include_decompile":true,"include_proto":true},{"addr":"0x775440","include_decompile":true,"include_proto":true},{"addr":"0x775640","include_decompile":true,"include_proto":true},{"addr":"0x775830","include_decompile":true,"include_proto":true},{"addr":"0x775910","include_decompile":true,"include_proto":true},{"addr":"0x775920","include_decompile":true,"include_proto":true},{"addr":"0x775930","include_decompile":true,"include_proto":true},{"addr":"0x775b30","include_decompile":true,"include_proto":true},{"addr":"0x775df0","include_decompile":true,"include_proto":true},{"addr":"0x775fe0","include_decompile":true,"include_proto":true},{"addr":"0x776220","include_decompile":true,"include_proto":true},{"addr":"0x7768b0","include_decompile":true,"include_proto":true},{"addr":"0x7768e0","include_decompile":true,"include_proto":true},{"addr":"0x776a20","include_decompile":true,"include_proto":true},{"addr":"0x776a50","include_decompile":true,"include_proto":true},{"addr":"0x777010","include_decompile":true,"include_proto":true},{"addr":"0x777060","include_decompile":true,"include_proto":true},{"addr":"0x777070","include_decompile":true,"include_proto":true},{"addr":"0x777100","include_decompile":true,"include_proto":true},{"addr":"0x777180","include_decompile":true,"include_proto":true},{"addr":"0x777330","include_decompile":true,"include_proto":true},{"addr":"0x777340","include_decompile":true,"include_proto":true},{"addr":"0x777410","include_decompile":true,"include_proto":true},{"addr":"0x777420","include_decompile":true,"include_proto":true},{"addr":"0x777480","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0158', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0158: empty response'); return; }
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
      console.log('Batch 0158: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0158 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0158 conn error:', e.message));
req.write(body);
req.end();
