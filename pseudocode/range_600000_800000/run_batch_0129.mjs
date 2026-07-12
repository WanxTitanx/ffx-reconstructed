
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x70f060","include_decompile":true,"include_proto":true},{"addr":"0x70f0e0","include_decompile":true,"include_proto":true},{"addr":"0x70f1e0","include_decompile":true,"include_proto":true},{"addr":"0x70f220","include_decompile":true,"include_proto":true},{"addr":"0x70f280","include_decompile":true,"include_proto":true},{"addr":"0x70f2f0","include_decompile":true,"include_proto":true},{"addr":"0x70f3f0","include_decompile":true,"include_proto":true},{"addr":"0x70f570","include_decompile":true,"include_proto":true},{"addr":"0x70f6a0","include_decompile":true,"include_proto":true},{"addr":"0x70f7d0","include_decompile":true,"include_proto":true},{"addr":"0x70f7f0","include_decompile":true,"include_proto":true},{"addr":"0x70f840","include_decompile":true,"include_proto":true},{"addr":"0x70fa10","include_decompile":true,"include_proto":true},{"addr":"0x70fb60","include_decompile":true,"include_proto":true},{"addr":"0x70fc00","include_decompile":true,"include_proto":true},{"addr":"0x70fcd0","include_decompile":true,"include_proto":true},{"addr":"0x70fdb0","include_decompile":true,"include_proto":true},{"addr":"0x70fe00","include_decompile":true,"include_proto":true},{"addr":"0x70fe80","include_decompile":true,"include_proto":true},{"addr":"0x70ff20","include_decompile":true,"include_proto":true},{"addr":"0x70ff90","include_decompile":true,"include_proto":true},{"addr":"0x710030","include_decompile":true,"include_proto":true},{"addr":"0x7100f0","include_decompile":true,"include_proto":true},{"addr":"0x710150","include_decompile":true,"include_proto":true},{"addr":"0x7101d0","include_decompile":true,"include_proto":true},{"addr":"0x710250","include_decompile":true,"include_proto":true},{"addr":"0x710260","include_decompile":true,"include_proto":true},{"addr":"0x710320","include_decompile":true,"include_proto":true},{"addr":"0x710370","include_decompile":true,"include_proto":true},{"addr":"0x7103c0","include_decompile":true,"include_proto":true},{"addr":"0x710450","include_decompile":true,"include_proto":true},{"addr":"0x7105a0","include_decompile":true,"include_proto":true},{"addr":"0x710620","include_decompile":true,"include_proto":true},{"addr":"0x7106a0","include_decompile":true,"include_proto":true},{"addr":"0x710710","include_decompile":true,"include_proto":true},{"addr":"0x710780","include_decompile":true,"include_proto":true},{"addr":"0x710860","include_decompile":true,"include_proto":true},{"addr":"0x710920","include_decompile":true,"include_proto":true},{"addr":"0x710980","include_decompile":true,"include_proto":true},{"addr":"0x710990","include_decompile":true,"include_proto":true},{"addr":"0x710a40","include_decompile":true,"include_proto":true},{"addr":"0x710ac0","include_decompile":true,"include_proto":true},{"addr":"0x710b50","include_decompile":true,"include_proto":true},{"addr":"0x710bc0","include_decompile":true,"include_proto":true},{"addr":"0x710c70","include_decompile":true,"include_proto":true},{"addr":"0x710c80","include_decompile":true,"include_proto":true},{"addr":"0x710d30","include_decompile":true,"include_proto":true},{"addr":"0x710f10","include_decompile":true,"include_proto":true},{"addr":"0x710f50","include_decompile":true,"include_proto":true},{"addr":"0x710f80","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0129', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0129: empty response'); return; }
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
      console.log('Batch 0129: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0129 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0129 conn error:', e.message));
req.write(body);
req.end();
