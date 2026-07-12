
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x787270","include_decompile":true,"include_proto":true},{"addr":"0x7872b0","include_decompile":true,"include_proto":true},{"addr":"0x7872e0","include_decompile":true,"include_proto":true},{"addr":"0x7872f0","include_decompile":true,"include_proto":true},{"addr":"0x7873e0","include_decompile":true,"include_proto":true},{"addr":"0x787400","include_decompile":true,"include_proto":true},{"addr":"0x787410","include_decompile":true,"include_proto":true},{"addr":"0x787420","include_decompile":true,"include_proto":true},{"addr":"0x787430","include_decompile":true,"include_proto":true},{"addr":"0x787450","include_decompile":true,"include_proto":true},{"addr":"0x787460","include_decompile":true,"include_proto":true},{"addr":"0x787490","include_decompile":true,"include_proto":true},{"addr":"0x787530","include_decompile":true,"include_proto":true},{"addr":"0x7876d0","include_decompile":true,"include_proto":true},{"addr":"0x7876e0","include_decompile":true,"include_proto":true},{"addr":"0x787710","include_decompile":true,"include_proto":true},{"addr":"0x7877a0","include_decompile":true,"include_proto":true},{"addr":"0x787800","include_decompile":true,"include_proto":true},{"addr":"0x787820","include_decompile":true,"include_proto":true},{"addr":"0x787890","include_decompile":true,"include_proto":true},{"addr":"0x7878d0","include_decompile":true,"include_proto":true},{"addr":"0x787900","include_decompile":true,"include_proto":true},{"addr":"0x787960","include_decompile":true,"include_proto":true},{"addr":"0x7879c0","include_decompile":true,"include_proto":true},{"addr":"0x787a10","include_decompile":true,"include_proto":true},{"addr":"0x787b00","include_decompile":true,"include_proto":true},{"addr":"0x787b20","include_decompile":true,"include_proto":true},{"addr":"0x787b30","include_decompile":true,"include_proto":true},{"addr":"0x787b70","include_decompile":true,"include_proto":true},{"addr":"0x787bb0","include_decompile":true,"include_proto":true},{"addr":"0x787ca0","include_decompile":true,"include_proto":true},{"addr":"0x787cb0","include_decompile":true,"include_proto":true},{"addr":"0x787cd0","include_decompile":true,"include_proto":true},{"addr":"0x787cf0","include_decompile":true,"include_proto":true},{"addr":"0x787d60","include_decompile":true,"include_proto":true},{"addr":"0x787e30","include_decompile":true,"include_proto":true},{"addr":"0x787ec0","include_decompile":true,"include_proto":true},{"addr":"0x787fe0","include_decompile":true,"include_proto":true},{"addr":"0x7881d0","include_decompile":true,"include_proto":true},{"addr":"0x788270","include_decompile":true,"include_proto":true},{"addr":"0x788280","include_decompile":true,"include_proto":true},{"addr":"0x7882c0","include_decompile":true,"include_proto":true},{"addr":"0x788330","include_decompile":true,"include_proto":true},{"addr":"0x788370","include_decompile":true,"include_proto":true},{"addr":"0x788380","include_decompile":true,"include_proto":true},{"addr":"0x7884b0","include_decompile":true,"include_proto":true},{"addr":"0x7884f0","include_decompile":true,"include_proto":true},{"addr":"0x788540","include_decompile":true,"include_proto":true},{"addr":"0x7889e0","include_decompile":true,"include_proto":true},{"addr":"0x788be0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0166', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0166: empty response'); return; }
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
      console.log('Batch 0166: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0166 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0166 conn error:', e.message));
req.write(body);
req.end();
