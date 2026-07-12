
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x783bb0","include_decompile":true,"include_proto":true},{"addr":"0x783c40","include_decompile":true,"include_proto":true},{"addr":"0x783c70","include_decompile":true,"include_proto":true},{"addr":"0x783e30","include_decompile":true,"include_proto":true},{"addr":"0x783eb0","include_decompile":true,"include_proto":true},{"addr":"0x783ed0","include_decompile":true,"include_proto":true},{"addr":"0x784070","include_decompile":true,"include_proto":true},{"addr":"0x7840b0","include_decompile":true,"include_proto":true},{"addr":"0x784120","include_decompile":true,"include_proto":true},{"addr":"0x7841d0","include_decompile":true,"include_proto":true},{"addr":"0x7842d0","include_decompile":true,"include_proto":true},{"addr":"0x784310","include_decompile":true,"include_proto":true},{"addr":"0x7843a0","include_decompile":true,"include_proto":true},{"addr":"0x7844d0","include_decompile":true,"include_proto":true},{"addr":"0x784570","include_decompile":true,"include_proto":true},{"addr":"0x7845b0","include_decompile":true,"include_proto":true},{"addr":"0x784660","include_decompile":true,"include_proto":true},{"addr":"0x784690","include_decompile":true,"include_proto":true},{"addr":"0x7846c0","include_decompile":true,"include_proto":true},{"addr":"0x784790","include_decompile":true,"include_proto":true},{"addr":"0x7847d0","include_decompile":true,"include_proto":true},{"addr":"0x784960","include_decompile":true,"include_proto":true},{"addr":"0x784a80","include_decompile":true,"include_proto":true},{"addr":"0x784a90","include_decompile":true,"include_proto":true},{"addr":"0x784b80","include_decompile":true,"include_proto":true},{"addr":"0x784ba0","include_decompile":true,"include_proto":true},{"addr":"0x784bc0","include_decompile":true,"include_proto":true},{"addr":"0x784c20","include_decompile":true,"include_proto":true},{"addr":"0x784c40","include_decompile":true,"include_proto":true},{"addr":"0x784c80","include_decompile":true,"include_proto":true},{"addr":"0x784ce0","include_decompile":true,"include_proto":true},{"addr":"0x784d00","include_decompile":true,"include_proto":true},{"addr":"0x784d40","include_decompile":true,"include_proto":true},{"addr":"0x784d90","include_decompile":true,"include_proto":true},{"addr":"0x784dc0","include_decompile":true,"include_proto":true},{"addr":"0x784f00","include_decompile":true,"include_proto":true},{"addr":"0x784f20","include_decompile":true,"include_proto":true},{"addr":"0x784f40","include_decompile":true,"include_proto":true},{"addr":"0x784f50","include_decompile":true,"include_proto":true},{"addr":"0x785000","include_decompile":true,"include_proto":true},{"addr":"0x785010","include_decompile":true,"include_proto":true},{"addr":"0x785020","include_decompile":true,"include_proto":true},{"addr":"0x785050","include_decompile":true,"include_proto":true},{"addr":"0x785070","include_decompile":true,"include_proto":true},{"addr":"0x7850a0","include_decompile":true,"include_proto":true},{"addr":"0x7850b0","include_decompile":true,"include_proto":true},{"addr":"0x7850e0","include_decompile":true,"include_proto":true},{"addr":"0x785170","include_decompile":true,"include_proto":true},{"addr":"0x785200","include_decompile":true,"include_proto":true},{"addr":"0x785270","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0164', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0164: empty response'); return; }
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
      console.log('Batch 0164: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0164 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0164 conn error:', e.message));
req.write(body);
req.end();
