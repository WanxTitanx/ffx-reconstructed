
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x657ab0","include_decompile":true,"include_proto":true},{"addr":"0x657b10","include_decompile":true,"include_proto":true},{"addr":"0x657b20","include_decompile":true,"include_proto":true},{"addr":"0x657b30","include_decompile":true,"include_proto":true},{"addr":"0x657b40","include_decompile":true,"include_proto":true},{"addr":"0x657b50","include_decompile":true,"include_proto":true},{"addr":"0x657b60","include_decompile":true,"include_proto":true},{"addr":"0x657be0","include_decompile":true,"include_proto":true},{"addr":"0x6583b0","include_decompile":true,"include_proto":true},{"addr":"0x6583c0","include_decompile":true,"include_proto":true},{"addr":"0x6583d0","include_decompile":true,"include_proto":true},{"addr":"0x658400","include_decompile":true,"include_proto":true},{"addr":"0x658470","include_decompile":true,"include_proto":true},{"addr":"0x6584e0","include_decompile":true,"include_proto":true},{"addr":"0x658700","include_decompile":true,"include_proto":true},{"addr":"0x658960","include_decompile":true,"include_proto":true},{"addr":"0x658b70","include_decompile":true,"include_proto":true},{"addr":"0x658c70","include_decompile":true,"include_proto":true},{"addr":"0x658e30","include_decompile":true,"include_proto":true},{"addr":"0x658e40","include_decompile":true,"include_proto":true},{"addr":"0x659090","include_decompile":true,"include_proto":true},{"addr":"0x6590d0","include_decompile":true,"include_proto":true},{"addr":"0x659190","include_decompile":true,"include_proto":true},{"addr":"0x659260","include_decompile":true,"include_proto":true},{"addr":"0x6592d0","include_decompile":true,"include_proto":true},{"addr":"0x659330","include_decompile":true,"include_proto":true},{"addr":"0x659350","include_decompile":true,"include_proto":true},{"addr":"0x659390","include_decompile":true,"include_proto":true},{"addr":"0x6593b0","include_decompile":true,"include_proto":true},{"addr":"0x659420","include_decompile":true,"include_proto":true},{"addr":"0x659560","include_decompile":true,"include_proto":true},{"addr":"0x659650","include_decompile":true,"include_proto":true},{"addr":"0x659760","include_decompile":true,"include_proto":true},{"addr":"0x6598a0","include_decompile":true,"include_proto":true},{"addr":"0x6599f0","include_decompile":true,"include_proto":true},{"addr":"0x659aa0","include_decompile":true,"include_proto":true},{"addr":"0x659b50","include_decompile":true,"include_proto":true},{"addr":"0x659d90","include_decompile":true,"include_proto":true},{"addr":"0x659dc0","include_decompile":true,"include_proto":true},{"addr":"0x659ea0","include_decompile":true,"include_proto":true},{"addr":"0x659eb0","include_decompile":true,"include_proto":true},{"addr":"0x65a360","include_decompile":true,"include_proto":true},{"addr":"0x65a3e0","include_decompile":true,"include_proto":true},{"addr":"0x65a450","include_decompile":true,"include_proto":true},{"addr":"0x65a530","include_decompile":true,"include_proto":true},{"addr":"0x65a5c0","include_decompile":true,"include_proto":true},{"addr":"0x65a650","include_decompile":true,"include_proto":true},{"addr":"0x65a720","include_decompile":true,"include_proto":true},{"addr":"0x65a7b0","include_decompile":true,"include_proto":true},{"addr":"0x65a850","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0055', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0055: empty response'); return; }
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
      console.log('Batch 0055: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0055 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0055 conn error:', e.message));
req.write(body);
req.end();
