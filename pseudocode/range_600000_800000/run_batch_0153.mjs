
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x772250","include_decompile":true,"include_proto":true},{"addr":"0x772280","include_decompile":true,"include_proto":true},{"addr":"0x7722a0","include_decompile":true,"include_proto":true},{"addr":"0x7722c0","include_decompile":true,"include_proto":true},{"addr":"0x7722f0","include_decompile":true,"include_proto":true},{"addr":"0x772310","include_decompile":true,"include_proto":true},{"addr":"0x772340","include_decompile":true,"include_proto":true},{"addr":"0x772360","include_decompile":true,"include_proto":true},{"addr":"0x772390","include_decompile":true,"include_proto":true},{"addr":"0x7723d0","include_decompile":true,"include_proto":true},{"addr":"0x772400","include_decompile":true,"include_proto":true},{"addr":"0x772420","include_decompile":true,"include_proto":true},{"addr":"0x772430","include_decompile":true,"include_proto":true},{"addr":"0x772460","include_decompile":true,"include_proto":true},{"addr":"0x772480","include_decompile":true,"include_proto":true},{"addr":"0x7724a0","include_decompile":true,"include_proto":true},{"addr":"0x7724c0","include_decompile":true,"include_proto":true},{"addr":"0x7724f0","include_decompile":true,"include_proto":true},{"addr":"0x772510","include_decompile":true,"include_proto":true},{"addr":"0x772530","include_decompile":true,"include_proto":true},{"addr":"0x772560","include_decompile":true,"include_proto":true},{"addr":"0x772580","include_decompile":true,"include_proto":true},{"addr":"0x7725a0","include_decompile":true,"include_proto":true},{"addr":"0x7725d0","include_decompile":true,"include_proto":true},{"addr":"0x7725e0","include_decompile":true,"include_proto":true},{"addr":"0x772600","include_decompile":true,"include_proto":true},{"addr":"0x772610","include_decompile":true,"include_proto":true},{"addr":"0x772640","include_decompile":true,"include_proto":true},{"addr":"0x772660","include_decompile":true,"include_proto":true},{"addr":"0x772670","include_decompile":true,"include_proto":true},{"addr":"0x7726a0","include_decompile":true,"include_proto":true},{"addr":"0x7726c0","include_decompile":true,"include_proto":true},{"addr":"0x7726e0","include_decompile":true,"include_proto":true},{"addr":"0x772700","include_decompile":true,"include_proto":true},{"addr":"0x772730","include_decompile":true,"include_proto":true},{"addr":"0x772770","include_decompile":true,"include_proto":true},{"addr":"0x772790","include_decompile":true,"include_proto":true},{"addr":"0x7727c0","include_decompile":true,"include_proto":true},{"addr":"0x7727e0","include_decompile":true,"include_proto":true},{"addr":"0x7727f0","include_decompile":true,"include_proto":true},{"addr":"0x772820","include_decompile":true,"include_proto":true},{"addr":"0x772840","include_decompile":true,"include_proto":true},{"addr":"0x772850","include_decompile":true,"include_proto":true},{"addr":"0x772880","include_decompile":true,"include_proto":true},{"addr":"0x7728a0","include_decompile":true,"include_proto":true},{"addr":"0x7728b0","include_decompile":true,"include_proto":true},{"addr":"0x7728e0","include_decompile":true,"include_proto":true},{"addr":"0x772900","include_decompile":true,"include_proto":true},{"addr":"0x772910","include_decompile":true,"include_proto":true},{"addr":"0x772920","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0153', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0153: empty response'); return; }
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
      console.log('Batch 0153: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0153 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0153 conn error:', e.message));
req.write(body);
req.end();
