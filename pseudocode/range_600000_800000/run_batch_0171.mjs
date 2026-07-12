
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7921c0","include_decompile":true,"include_proto":true},{"addr":"0x792210","include_decompile":true,"include_proto":true},{"addr":"0x792250","include_decompile":true,"include_proto":true},{"addr":"0x792260","include_decompile":true,"include_proto":true},{"addr":"0x7928a0","include_decompile":true,"include_proto":true},{"addr":"0x7928f0","include_decompile":true,"include_proto":true},{"addr":"0x7929d0","include_decompile":true,"include_proto":true},{"addr":"0x792a60","include_decompile":true,"include_proto":true},{"addr":"0x792ab0","include_decompile":true,"include_proto":true},{"addr":"0x792d70","include_decompile":true,"include_proto":true},{"addr":"0x792df0","include_decompile":true,"include_proto":true},{"addr":"0x792e60","include_decompile":true,"include_proto":true},{"addr":"0x792e80","include_decompile":true,"include_proto":true},{"addr":"0x792e90","include_decompile":true,"include_proto":true},{"addr":"0x792ef0","include_decompile":true,"include_proto":true},{"addr":"0x792f30","include_decompile":true,"include_proto":true},{"addr":"0x793270","include_decompile":true,"include_proto":true},{"addr":"0x7932a0","include_decompile":true,"include_proto":true},{"addr":"0x7932c0","include_decompile":true,"include_proto":true},{"addr":"0x793340","include_decompile":true,"include_proto":true},{"addr":"0x793420","include_decompile":true,"include_proto":true},{"addr":"0x793490","include_decompile":true,"include_proto":true},{"addr":"0x793510","include_decompile":true,"include_proto":true},{"addr":"0x793540","include_decompile":true,"include_proto":true},{"addr":"0x793580","include_decompile":true,"include_proto":true},{"addr":"0x793660","include_decompile":true,"include_proto":true},{"addr":"0x793680","include_decompile":true,"include_proto":true},{"addr":"0x7938f0","include_decompile":true,"include_proto":true},{"addr":"0x793bb0","include_decompile":true,"include_proto":true},{"addr":"0x793cc0","include_decompile":true,"include_proto":true},{"addr":"0x793d00","include_decompile":true,"include_proto":true},{"addr":"0x793da0","include_decompile":true,"include_proto":true},{"addr":"0x793dd0","include_decompile":true,"include_proto":true},{"addr":"0x793e10","include_decompile":true,"include_proto":true},{"addr":"0x793f00","include_decompile":true,"include_proto":true},{"addr":"0x793f20","include_decompile":true,"include_proto":true},{"addr":"0x794030","include_decompile":true,"include_proto":true},{"addr":"0x794070","include_decompile":true,"include_proto":true},{"addr":"0x794250","include_decompile":true,"include_proto":true},{"addr":"0x794290","include_decompile":true,"include_proto":true},{"addr":"0x794340","include_decompile":true,"include_proto":true},{"addr":"0x794800","include_decompile":true,"include_proto":true},{"addr":"0x794840","include_decompile":true,"include_proto":true},{"addr":"0x7948b0","include_decompile":true,"include_proto":true},{"addr":"0x7948f0","include_decompile":true,"include_proto":true},{"addr":"0x7949a0","include_decompile":true,"include_proto":true},{"addr":"0x794a40","include_decompile":true,"include_proto":true},{"addr":"0x794a80","include_decompile":true,"include_proto":true},{"addr":"0x794ac0","include_decompile":true,"include_proto":true},{"addr":"0x794b80","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0171', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0171: empty response'); return; }
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
      console.log('Batch 0171: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0171 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0171 conn error:', e.message));
req.write(body);
req.end();
