
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x781600","include_decompile":true,"include_proto":true},{"addr":"0x781620","include_decompile":true,"include_proto":true},{"addr":"0x781660","include_decompile":true,"include_proto":true},{"addr":"0x781700","include_decompile":true,"include_proto":true},{"addr":"0x781720","include_decompile":true,"include_proto":true},{"addr":"0x781750","include_decompile":true,"include_proto":true},{"addr":"0x781770","include_decompile":true,"include_proto":true},{"addr":"0x781780","include_decompile":true,"include_proto":true},{"addr":"0x7817c0","include_decompile":true,"include_proto":true},{"addr":"0x7817d0","include_decompile":true,"include_proto":true},{"addr":"0x781d20","include_decompile":true,"include_proto":true},{"addr":"0x781d60","include_decompile":true,"include_proto":true},{"addr":"0x781dd0","include_decompile":true,"include_proto":true},{"addr":"0x781e00","include_decompile":true,"include_proto":true},{"addr":"0x782110","include_decompile":true,"include_proto":true},{"addr":"0x782150","include_decompile":true,"include_proto":true},{"addr":"0x7822a0","include_decompile":true,"include_proto":true},{"addr":"0x7822b0","include_decompile":true,"include_proto":true},{"addr":"0x7825a0","include_decompile":true,"include_proto":true},{"addr":"0x782700","include_decompile":true,"include_proto":true},{"addr":"0x782730","include_decompile":true,"include_proto":true},{"addr":"0x782760","include_decompile":true,"include_proto":true},{"addr":"0x782800","include_decompile":true,"include_proto":true},{"addr":"0x782810","include_decompile":true,"include_proto":true},{"addr":"0x782830","include_decompile":true,"include_proto":true},{"addr":"0x7828b0","include_decompile":true,"include_proto":true},{"addr":"0x782960","include_decompile":true,"include_proto":true},{"addr":"0x782a00","include_decompile":true,"include_proto":true},{"addr":"0x782a30","include_decompile":true,"include_proto":true},{"addr":"0x782a60","include_decompile":true,"include_proto":true},{"addr":"0x782a70","include_decompile":true,"include_proto":true},{"addr":"0x782ad0","include_decompile":true,"include_proto":true},{"addr":"0x782ae0","include_decompile":true,"include_proto":true},{"addr":"0x782ba0","include_decompile":true,"include_proto":true},{"addr":"0x782c00","include_decompile":true,"include_proto":true},{"addr":"0x782c30","include_decompile":true,"include_proto":true},{"addr":"0x782c60","include_decompile":true,"include_proto":true},{"addr":"0x782cc0","include_decompile":true,"include_proto":true},{"addr":"0x782e20","include_decompile":true,"include_proto":true},{"addr":"0x782eb0","include_decompile":true,"include_proto":true},{"addr":"0x783030","include_decompile":true,"include_proto":true},{"addr":"0x783040","include_decompile":true,"include_proto":true},{"addr":"0x783060","include_decompile":true,"include_proto":true},{"addr":"0x783090","include_decompile":true,"include_proto":true},{"addr":"0x7830a0","include_decompile":true,"include_proto":true},{"addr":"0x7830b0","include_decompile":true,"include_proto":true},{"addr":"0x7830d0","include_decompile":true,"include_proto":true},{"addr":"0x783730","include_decompile":true,"include_proto":true},{"addr":"0x783a40","include_decompile":true,"include_proto":true},{"addr":"0x783a60","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0163', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0163: empty response'); return; }
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
      console.log('Batch 0163: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0163 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0163 conn error:', e.message));
req.write(body);
req.end();
