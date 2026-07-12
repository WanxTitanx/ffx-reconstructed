
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x687060","include_decompile":true,"include_proto":true},{"addr":"0x687070","include_decompile":true,"include_proto":true},{"addr":"0x687080","include_decompile":true,"include_proto":true},{"addr":"0x687090","include_decompile":true,"include_proto":true},{"addr":"0x6870a0","include_decompile":true,"include_proto":true},{"addr":"0x6870e0","include_decompile":true,"include_proto":true},{"addr":"0x6870f0","include_decompile":true,"include_proto":true},{"addr":"0x687100","include_decompile":true,"include_proto":true},{"addr":"0x687110","include_decompile":true,"include_proto":true},{"addr":"0x687120","include_decompile":true,"include_proto":true},{"addr":"0x687180","include_decompile":true,"include_proto":true},{"addr":"0x687190","include_decompile":true,"include_proto":true},{"addr":"0x6871b0","include_decompile":true,"include_proto":true},{"addr":"0x6871c0","include_decompile":true,"include_proto":true},{"addr":"0x6871e0","include_decompile":true,"include_proto":true},{"addr":"0x6871f0","include_decompile":true,"include_proto":true},{"addr":"0x687200","include_decompile":true,"include_proto":true},{"addr":"0x687210","include_decompile":true,"include_proto":true},{"addr":"0x687250","include_decompile":true,"include_proto":true},{"addr":"0x687330","include_decompile":true,"include_proto":true},{"addr":"0x6873b0","include_decompile":true,"include_proto":true},{"addr":"0x687480","include_decompile":true,"include_proto":true},{"addr":"0x687510","include_decompile":true,"include_proto":true},{"addr":"0x687650","include_decompile":true,"include_proto":true},{"addr":"0x687830","include_decompile":true,"include_proto":true},{"addr":"0x6879f0","include_decompile":true,"include_proto":true},{"addr":"0x687db0","include_decompile":true,"include_proto":true},{"addr":"0x688030","include_decompile":true,"include_proto":true},{"addr":"0x6883f0","include_decompile":true,"include_proto":true},{"addr":"0x688440","include_decompile":true,"include_proto":true},{"addr":"0x688610","include_decompile":true,"include_proto":true},{"addr":"0x688680","include_decompile":true,"include_proto":true},{"addr":"0x688780","include_decompile":true,"include_proto":true},{"addr":"0x688790","include_decompile":true,"include_proto":true},{"addr":"0x689510","include_decompile":true,"include_proto":true},{"addr":"0x689570","include_decompile":true,"include_proto":true},{"addr":"0x689580","include_decompile":true,"include_proto":true},{"addr":"0x6896b0","include_decompile":true,"include_proto":true},{"addr":"0x6897c0","include_decompile":true,"include_proto":true},{"addr":"0x689970","include_decompile":true,"include_proto":true},{"addr":"0x6899d0","include_decompile":true,"include_proto":true},{"addr":"0x689a40","include_decompile":true,"include_proto":true},{"addr":"0x689a50","include_decompile":true,"include_proto":true},{"addr":"0x689a60","include_decompile":true,"include_proto":true},{"addr":"0x689a70","include_decompile":true,"include_proto":true},{"addr":"0x689bb0","include_decompile":true,"include_proto":true},{"addr":"0x689eb0","include_decompile":true,"include_proto":true},{"addr":"0x68a0d0","include_decompile":true,"include_proto":true},{"addr":"0x68a310","include_decompile":true,"include_proto":true},{"addr":"0x68a320","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0074', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0074: empty response'); return; }
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
      console.log('Batch 0074: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0074 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0074 conn error:', e.message));
req.write(body);
req.end();
