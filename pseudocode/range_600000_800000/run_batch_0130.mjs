
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x710fb0","include_decompile":true,"include_proto":true},{"addr":"0x7110b0","include_decompile":true,"include_proto":true},{"addr":"0x711110","include_decompile":true,"include_proto":true},{"addr":"0x7111b0","include_decompile":true,"include_proto":true},{"addr":"0x711260","include_decompile":true,"include_proto":true},{"addr":"0x7112c0","include_decompile":true,"include_proto":true},{"addr":"0x7113b0","include_decompile":true,"include_proto":true},{"addr":"0x711430","include_decompile":true,"include_proto":true},{"addr":"0x7114b0","include_decompile":true,"include_proto":true},{"addr":"0x711540","include_decompile":true,"include_proto":true},{"addr":"0x7115e0","include_decompile":true,"include_proto":true},{"addr":"0x711760","include_decompile":true,"include_proto":true},{"addr":"0x7117a0","include_decompile":true,"include_proto":true},{"addr":"0x7117b0","include_decompile":true,"include_proto":true},{"addr":"0x711830","include_decompile":true,"include_proto":true},{"addr":"0x7118a0","include_decompile":true,"include_proto":true},{"addr":"0x711910","include_decompile":true,"include_proto":true},{"addr":"0x7119f0","include_decompile":true,"include_proto":true},{"addr":"0x711ab0","include_decompile":true,"include_proto":true},{"addr":"0x712000","include_decompile":true,"include_proto":true},{"addr":"0x712080","include_decompile":true,"include_proto":true},{"addr":"0x7121d0","include_decompile":true,"include_proto":true},{"addr":"0x712330","include_decompile":true,"include_proto":true},{"addr":"0x7123d0","include_decompile":true,"include_proto":true},{"addr":"0x7124a0","include_decompile":true,"include_proto":true},{"addr":"0x712640","include_decompile":true,"include_proto":true},{"addr":"0x712770","include_decompile":true,"include_proto":true},{"addr":"0x7129b0","include_decompile":true,"include_proto":true},{"addr":"0x712c60","include_decompile":true,"include_proto":true},{"addr":"0x712cb0","include_decompile":true,"include_proto":true},{"addr":"0x712d10","include_decompile":true,"include_proto":true},{"addr":"0x712de0","include_decompile":true,"include_proto":true},{"addr":"0x712e00","include_decompile":true,"include_proto":true},{"addr":"0x712e70","include_decompile":true,"include_proto":true},{"addr":"0x712ee0","include_decompile":true,"include_proto":true},{"addr":"0x712f20","include_decompile":true,"include_proto":true},{"addr":"0x712f60","include_decompile":true,"include_proto":true},{"addr":"0x712fa0","include_decompile":true,"include_proto":true},{"addr":"0x713240","include_decompile":true,"include_proto":true},{"addr":"0x713370","include_decompile":true,"include_proto":true},{"addr":"0x713400","include_decompile":true,"include_proto":true},{"addr":"0x7134c0","include_decompile":true,"include_proto":true},{"addr":"0x713690","include_decompile":true,"include_proto":true},{"addr":"0x713870","include_decompile":true,"include_proto":true},{"addr":"0x714890","include_decompile":true,"include_proto":true},{"addr":"0x714c40","include_decompile":true,"include_proto":true},{"addr":"0x714d30","include_decompile":true,"include_proto":true},{"addr":"0x714e20","include_decompile":true,"include_proto":true},{"addr":"0x715250","include_decompile":true,"include_proto":true},{"addr":"0x7158f0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0130', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0130: empty response'); return; }
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
      console.log('Batch 0130: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0130 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0130 conn error:', e.message));
req.write(body);
req.end();
