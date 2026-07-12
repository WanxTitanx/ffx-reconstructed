
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x68a330","include_decompile":true,"include_proto":true},{"addr":"0x68a3d0","include_decompile":true,"include_proto":true},{"addr":"0x68a540","include_decompile":true,"include_proto":true},{"addr":"0x68a5c0","include_decompile":true,"include_proto":true},{"addr":"0x68a800","include_decompile":true,"include_proto":true},{"addr":"0x68acd0","include_decompile":true,"include_proto":true},{"addr":"0x68b610","include_decompile":true,"include_proto":true},{"addr":"0x68b870","include_decompile":true,"include_proto":true},{"addr":"0x68b960","include_decompile":true,"include_proto":true},{"addr":"0x68b970","include_decompile":true,"include_proto":true},{"addr":"0x68ba00","include_decompile":true,"include_proto":true},{"addr":"0x68bab0","include_decompile":true,"include_proto":true},{"addr":"0x68bb90","include_decompile":true,"include_proto":true},{"addr":"0x68bbc0","include_decompile":true,"include_proto":true},{"addr":"0x68bc80","include_decompile":true,"include_proto":true},{"addr":"0x68bd40","include_decompile":true,"include_proto":true},{"addr":"0x68bdd0","include_decompile":true,"include_proto":true},{"addr":"0x68bde0","include_decompile":true,"include_proto":true},{"addr":"0x68bdf0","include_decompile":true,"include_proto":true},{"addr":"0x68be00","include_decompile":true,"include_proto":true},{"addr":"0x68bea0","include_decompile":true,"include_proto":true},{"addr":"0x68bfb0","include_decompile":true,"include_proto":true},{"addr":"0x68c0e0","include_decompile":true,"include_proto":true},{"addr":"0x68c140","include_decompile":true,"include_proto":true},{"addr":"0x68c190","include_decompile":true,"include_proto":true},{"addr":"0x68c1f0","include_decompile":true,"include_proto":true},{"addr":"0x68c200","include_decompile":true,"include_proto":true},{"addr":"0x68c210","include_decompile":true,"include_proto":true},{"addr":"0x68c220","include_decompile":true,"include_proto":true},{"addr":"0x68c2f0","include_decompile":true,"include_proto":true},{"addr":"0x68c300","include_decompile":true,"include_proto":true},{"addr":"0x68c310","include_decompile":true,"include_proto":true},{"addr":"0x68c320","include_decompile":true,"include_proto":true},{"addr":"0x68c370","include_decompile":true,"include_proto":true},{"addr":"0x68c380","include_decompile":true,"include_proto":true},{"addr":"0x68c550","include_decompile":true,"include_proto":true},{"addr":"0x68c570","include_decompile":true,"include_proto":true},{"addr":"0x68c590","include_decompile":true,"include_proto":true},{"addr":"0x68c5b0","include_decompile":true,"include_proto":true},{"addr":"0x68c5c0","include_decompile":true,"include_proto":true},{"addr":"0x68c5d0","include_decompile":true,"include_proto":true},{"addr":"0x68c5e0","include_decompile":true,"include_proto":true},{"addr":"0x68c5f0","include_decompile":true,"include_proto":true},{"addr":"0x68c600","include_decompile":true,"include_proto":true},{"addr":"0x68c610","include_decompile":true,"include_proto":true},{"addr":"0x68c620","include_decompile":true,"include_proto":true},{"addr":"0x68c630","include_decompile":true,"include_proto":true},{"addr":"0x68c640","include_decompile":true,"include_proto":true},{"addr":"0x68c650","include_decompile":true,"include_proto":true},{"addr":"0x68c660","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0075', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0075: empty response'); return; }
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
      console.log('Batch 0075: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0075 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0075 conn error:', e.message));
req.write(body);
req.end();
