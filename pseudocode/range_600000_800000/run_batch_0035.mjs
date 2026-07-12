
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x637790","include_decompile":true,"include_proto":true},{"addr":"0x6377b0","include_decompile":true,"include_proto":true},{"addr":"0x6377c0","include_decompile":true,"include_proto":true},{"addr":"0x6377d0","include_decompile":true,"include_proto":true},{"addr":"0x6377e0","include_decompile":true,"include_proto":true},{"addr":"0x637800","include_decompile":true,"include_proto":true},{"addr":"0x637810","include_decompile":true,"include_proto":true},{"addr":"0x637820","include_decompile":true,"include_proto":true},{"addr":"0x637830","include_decompile":true,"include_proto":true},{"addr":"0x637840","include_decompile":true,"include_proto":true},{"addr":"0x637850","include_decompile":true,"include_proto":true},{"addr":"0x637860","include_decompile":true,"include_proto":true},{"addr":"0x637870","include_decompile":true,"include_proto":true},{"addr":"0x637880","include_decompile":true,"include_proto":true},{"addr":"0x6378b0","include_decompile":true,"include_proto":true},{"addr":"0x6378c0","include_decompile":true,"include_proto":true},{"addr":"0x6378d0","include_decompile":true,"include_proto":true},{"addr":"0x6378e0","include_decompile":true,"include_proto":true},{"addr":"0x637950","include_decompile":true,"include_proto":true},{"addr":"0x637a10","include_decompile":true,"include_proto":true},{"addr":"0x637a30","include_decompile":true,"include_proto":true},{"addr":"0x637a60","include_decompile":true,"include_proto":true},{"addr":"0x637b30","include_decompile":true,"include_proto":true},{"addr":"0x637ce0","include_decompile":true,"include_proto":true},{"addr":"0x637dc0","include_decompile":true,"include_proto":true},{"addr":"0x637e00","include_decompile":true,"include_proto":true},{"addr":"0x637e30","include_decompile":true,"include_proto":true},{"addr":"0x637ef0","include_decompile":true,"include_proto":true},{"addr":"0x637fc0","include_decompile":true,"include_proto":true},{"addr":"0x637fd0","include_decompile":true,"include_proto":true},{"addr":"0x637fe0","include_decompile":true,"include_proto":true},{"addr":"0x638070","include_decompile":true,"include_proto":true},{"addr":"0x638120","include_decompile":true,"include_proto":true},{"addr":"0x638130","include_decompile":true,"include_proto":true},{"addr":"0x638160","include_decompile":true,"include_proto":true},{"addr":"0x638170","include_decompile":true,"include_proto":true},{"addr":"0x638180","include_decompile":true,"include_proto":true},{"addr":"0x6381a0","include_decompile":true,"include_proto":true},{"addr":"0x6381b0","include_decompile":true,"include_proto":true},{"addr":"0x6381c0","include_decompile":true,"include_proto":true},{"addr":"0x638220","include_decompile":true,"include_proto":true},{"addr":"0x638230","include_decompile":true,"include_proto":true},{"addr":"0x6382c0","include_decompile":true,"include_proto":true},{"addr":"0x6383f0","include_decompile":true,"include_proto":true},{"addr":"0x6384f0","include_decompile":true,"include_proto":true},{"addr":"0x638590","include_decompile":true,"include_proto":true},{"addr":"0x6385a0","include_decompile":true,"include_proto":true},{"addr":"0x638630","include_decompile":true,"include_proto":true},{"addr":"0x638720","include_decompile":true,"include_proto":true},{"addr":"0x638870","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0035', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0035: empty response'); return; }
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
      console.log('Batch 0035: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0035 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0035 conn error:', e.message));
req.write(body);
req.end();
