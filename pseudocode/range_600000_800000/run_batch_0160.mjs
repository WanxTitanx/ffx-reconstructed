
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x779e10","include_decompile":true,"include_proto":true},{"addr":"0x77a060","include_decompile":true,"include_proto":true},{"addr":"0x77a070","include_decompile":true,"include_proto":true},{"addr":"0x77a090","include_decompile":true,"include_proto":true},{"addr":"0x77a0b0","include_decompile":true,"include_proto":true},{"addr":"0x77a0d0","include_decompile":true,"include_proto":true},{"addr":"0x77a0f0","include_decompile":true,"include_proto":true},{"addr":"0x77a110","include_decompile":true,"include_proto":true},{"addr":"0x77a130","include_decompile":true,"include_proto":true},{"addr":"0x77a150","include_decompile":true,"include_proto":true},{"addr":"0x77a180","include_decompile":true,"include_proto":true},{"addr":"0x77a190","include_decompile":true,"include_proto":true},{"addr":"0x77a1a0","include_decompile":true,"include_proto":true},{"addr":"0x77a1b0","include_decompile":true,"include_proto":true},{"addr":"0x77a1c0","include_decompile":true,"include_proto":true},{"addr":"0x77a1d0","include_decompile":true,"include_proto":true},{"addr":"0x77a1e0","include_decompile":true,"include_proto":true},{"addr":"0x77a200","include_decompile":true,"include_proto":true},{"addr":"0x77a210","include_decompile":true,"include_proto":true},{"addr":"0x77a220","include_decompile":true,"include_proto":true},{"addr":"0x77a230","include_decompile":true,"include_proto":true},{"addr":"0x77a240","include_decompile":true,"include_proto":true},{"addr":"0x77a250","include_decompile":true,"include_proto":true},{"addr":"0x77a260","include_decompile":true,"include_proto":true},{"addr":"0x77a270","include_decompile":true,"include_proto":true},{"addr":"0x77a290","include_decompile":true,"include_proto":true},{"addr":"0x77a2c0","include_decompile":true,"include_proto":true},{"addr":"0x77a3b0","include_decompile":true,"include_proto":true},{"addr":"0x77a410","include_decompile":true,"include_proto":true},{"addr":"0x77a480","include_decompile":true,"include_proto":true},{"addr":"0x77a4e0","include_decompile":true,"include_proto":true},{"addr":"0x77a510","include_decompile":true,"include_proto":true},{"addr":"0x77a570","include_decompile":true,"include_proto":true},{"addr":"0x77a580","include_decompile":true,"include_proto":true},{"addr":"0x77a590","include_decompile":true,"include_proto":true},{"addr":"0x77a5a0","include_decompile":true,"include_proto":true},{"addr":"0x77a5b0","include_decompile":true,"include_proto":true},{"addr":"0x77a5c0","include_decompile":true,"include_proto":true},{"addr":"0x77a5d0","include_decompile":true,"include_proto":true},{"addr":"0x77a9d0","include_decompile":true,"include_proto":true},{"addr":"0x77aa20","include_decompile":true,"include_proto":true},{"addr":"0x77aea0","include_decompile":true,"include_proto":true},{"addr":"0x77aed0","include_decompile":true,"include_proto":true},{"addr":"0x77b0b0","include_decompile":true,"include_proto":true},{"addr":"0x77b150","include_decompile":true,"include_proto":true},{"addr":"0x77b1c0","include_decompile":true,"include_proto":true},{"addr":"0x77b260","include_decompile":true,"include_proto":true},{"addr":"0x77b2e0","include_decompile":true,"include_proto":true},{"addr":"0x77b360","include_decompile":true,"include_proto":true},{"addr":"0x77b3f0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0160', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0160: empty response'); return; }
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
      console.log('Batch 0160: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0160 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0160 conn error:', e.message));
req.write(body);
req.end();
