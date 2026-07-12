
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x60b950","include_decompile":true,"include_proto":true},{"addr":"0x60ba10","include_decompile":true,"include_proto":true},{"addr":"0x60ba20","include_decompile":true,"include_proto":true},{"addr":"0x60bd20","include_decompile":true,"include_proto":true},{"addr":"0x60bd30","include_decompile":true,"include_proto":true},{"addr":"0x60bd40","include_decompile":true,"include_proto":true},{"addr":"0x60bdc0","include_decompile":true,"include_proto":true},{"addr":"0x60be50","include_decompile":true,"include_proto":true},{"addr":"0x60bf40","include_decompile":true,"include_proto":true},{"addr":"0x60c090","include_decompile":true,"include_proto":true},{"addr":"0x60c120","include_decompile":true,"include_proto":true},{"addr":"0x60c1d0","include_decompile":true,"include_proto":true},{"addr":"0x60c1e0","include_decompile":true,"include_proto":true},{"addr":"0x60c1f0","include_decompile":true,"include_proto":true},{"addr":"0x60c550","include_decompile":true,"include_proto":true},{"addr":"0x60c870","include_decompile":true,"include_proto":true},{"addr":"0x60c8c0","include_decompile":true,"include_proto":true},{"addr":"0x60c8d0","include_decompile":true,"include_proto":true},{"addr":"0x60c8e0","include_decompile":true,"include_proto":true},{"addr":"0x60c8f0","include_decompile":true,"include_proto":true},{"addr":"0x60ca30","include_decompile":true,"include_proto":true},{"addr":"0x60ca40","include_decompile":true,"include_proto":true},{"addr":"0x60caa0","include_decompile":true,"include_proto":true},{"addr":"0x60cab0","include_decompile":true,"include_proto":true},{"addr":"0x60cb50","include_decompile":true,"include_proto":true},{"addr":"0x60cbd0","include_decompile":true,"include_proto":true},{"addr":"0x60cc30","include_decompile":true,"include_proto":true},{"addr":"0x60cc80","include_decompile":true,"include_proto":true},{"addr":"0x60cd30","include_decompile":true,"include_proto":true},{"addr":"0x60cde0","include_decompile":true,"include_proto":true},{"addr":"0x60cf10","include_decompile":true,"include_proto":true},{"addr":"0x60d030","include_decompile":true,"include_proto":true},{"addr":"0x60d100","include_decompile":true,"include_proto":true},{"addr":"0x60d1c0","include_decompile":true,"include_proto":true},{"addr":"0x60d240","include_decompile":true,"include_proto":true},{"addr":"0x60d2d0","include_decompile":true,"include_proto":true},{"addr":"0x60d340","include_decompile":true,"include_proto":true},{"addr":"0x60d3d0","include_decompile":true,"include_proto":true},{"addr":"0x60d440","include_decompile":true,"include_proto":true},{"addr":"0x60d510","include_decompile":true,"include_proto":true},{"addr":"0x60d530","include_decompile":true,"include_proto":true},{"addr":"0x60d620","include_decompile":true,"include_proto":true},{"addr":"0x60d680","include_decompile":true,"include_proto":true},{"addr":"0x60d700","include_decompile":true,"include_proto":true},{"addr":"0x60d710","include_decompile":true,"include_proto":true},{"addr":"0x60d790","include_decompile":true,"include_proto":true},{"addr":"0x60d860","include_decompile":true,"include_proto":true},{"addr":"0x60dc80","include_decompile":true,"include_proto":true},{"addr":"0x60dce0","include_decompile":true,"include_proto":true},{"addr":"0x60de20","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0005', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0005: empty response'); return; }
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
      console.log('Batch 0005: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0005 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0005 conn error:', e.message));
req.write(body);
req.end();
