
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x79b180","include_decompile":true,"include_proto":true},{"addr":"0x79b1b0","include_decompile":true,"include_proto":true},{"addr":"0x79b2a0","include_decompile":true,"include_proto":true},{"addr":"0x79b480","include_decompile":true,"include_proto":true},{"addr":"0x79b500","include_decompile":true,"include_proto":true},{"addr":"0x79bb70","include_decompile":true,"include_proto":true},{"addr":"0x79c090","include_decompile":true,"include_proto":true},{"addr":"0x79c130","include_decompile":true,"include_proto":true},{"addr":"0x79c610","include_decompile":true,"include_proto":true},{"addr":"0x79caa0","include_decompile":true,"include_proto":true},{"addr":"0x79cb30","include_decompile":true,"include_proto":true},{"addr":"0x79cb60","include_decompile":true,"include_proto":true},{"addr":"0x79cc90","include_decompile":true,"include_proto":true},{"addr":"0x79cca0","include_decompile":true,"include_proto":true},{"addr":"0x79ccc0","include_decompile":true,"include_proto":true},{"addr":"0x79ccf0","include_decompile":true,"include_proto":true},{"addr":"0x79cd10","include_decompile":true,"include_proto":true},{"addr":"0x79cda0","include_decompile":true,"include_proto":true},{"addr":"0x79cdf0","include_decompile":true,"include_proto":true},{"addr":"0x79ce10","include_decompile":true,"include_proto":true},{"addr":"0x79cff0","include_decompile":true,"include_proto":true},{"addr":"0x79d070","include_decompile":true,"include_proto":true},{"addr":"0x79d0b0","include_decompile":true,"include_proto":true},{"addr":"0x79d100","include_decompile":true,"include_proto":true},{"addr":"0x79d190","include_decompile":true,"include_proto":true},{"addr":"0x79d1b0","include_decompile":true,"include_proto":true},{"addr":"0x79d1e0","include_decompile":true,"include_proto":true},{"addr":"0x79d230","include_decompile":true,"include_proto":true},{"addr":"0x79d270","include_decompile":true,"include_proto":true},{"addr":"0x79d2b0","include_decompile":true,"include_proto":true},{"addr":"0x79d2c0","include_decompile":true,"include_proto":true},{"addr":"0x79d310","include_decompile":true,"include_proto":true},{"addr":"0x79d450","include_decompile":true,"include_proto":true},{"addr":"0x79dd90","include_decompile":true,"include_proto":true},{"addr":"0x79ddb0","include_decompile":true,"include_proto":true},{"addr":"0x79ddd0","include_decompile":true,"include_proto":true},{"addr":"0x79de00","include_decompile":true,"include_proto":true},{"addr":"0x79de80","include_decompile":true,"include_proto":true},{"addr":"0x79dfb0","include_decompile":true,"include_proto":true},{"addr":"0x79e000","include_decompile":true,"include_proto":true},{"addr":"0x79e050","include_decompile":true,"include_proto":true},{"addr":"0x79e1d0","include_decompile":true,"include_proto":true},{"addr":"0x79e2c0","include_decompile":true,"include_proto":true},{"addr":"0x79e330","include_decompile":true,"include_proto":true},{"addr":"0x79e340","include_decompile":true,"include_proto":true},{"addr":"0x79e350","include_decompile":true,"include_proto":true},{"addr":"0x79e360","include_decompile":true,"include_proto":true},{"addr":"0x79e3f0","include_decompile":true,"include_proto":true},{"addr":"0x79e510","include_decompile":true,"include_proto":true},{"addr":"0x79e530","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0176', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0176: empty response'); return; }
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
      console.log('Batch 0176: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0176 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0176 conn error:', e.message));
req.write(body);
req.end();
