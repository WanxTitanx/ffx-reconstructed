
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x635fc0","include_decompile":true,"include_proto":true},{"addr":"0x635fd0","include_decompile":true,"include_proto":true},{"addr":"0x636010","include_decompile":true,"include_proto":true},{"addr":"0x636020","include_decompile":true,"include_proto":true},{"addr":"0x636030","include_decompile":true,"include_proto":true},{"addr":"0x636040","include_decompile":true,"include_proto":true},{"addr":"0x636050","include_decompile":true,"include_proto":true},{"addr":"0x636060","include_decompile":true,"include_proto":true},{"addr":"0x636070","include_decompile":true,"include_proto":true},{"addr":"0x6360d0","include_decompile":true,"include_proto":true},{"addr":"0x636130","include_decompile":true,"include_proto":true},{"addr":"0x636150","include_decompile":true,"include_proto":true},{"addr":"0x636170","include_decompile":true,"include_proto":true},{"addr":"0x636190","include_decompile":true,"include_proto":true},{"addr":"0x6361b0","include_decompile":true,"include_proto":true},{"addr":"0x6361d0","include_decompile":true,"include_proto":true},{"addr":"0x6361e0","include_decompile":true,"include_proto":true},{"addr":"0x636230","include_decompile":true,"include_proto":true},{"addr":"0x6362f0","include_decompile":true,"include_proto":true},{"addr":"0x636350","include_decompile":true,"include_proto":true},{"addr":"0x636430","include_decompile":true,"include_proto":true},{"addr":"0x6364c0","include_decompile":true,"include_proto":true},{"addr":"0x6365c0","include_decompile":true,"include_proto":true},{"addr":"0x6365e0","include_decompile":true,"include_proto":true},{"addr":"0x6367a0","include_decompile":true,"include_proto":true},{"addr":"0x636a90","include_decompile":true,"include_proto":true},{"addr":"0x636aa0","include_decompile":true,"include_proto":true},{"addr":"0x636ab0","include_decompile":true,"include_proto":true},{"addr":"0x636b20","include_decompile":true,"include_proto":true},{"addr":"0x636ea0","include_decompile":true,"include_proto":true},{"addr":"0x636ee0","include_decompile":true,"include_proto":true},{"addr":"0x636ef0","include_decompile":true,"include_proto":true},{"addr":"0x636f00","include_decompile":true,"include_proto":true},{"addr":"0x636f10","include_decompile":true,"include_proto":true},{"addr":"0x636fd0","include_decompile":true,"include_proto":true},{"addr":"0x637280","include_decompile":true,"include_proto":true},{"addr":"0x637340","include_decompile":true,"include_proto":true},{"addr":"0x637610","include_decompile":true,"include_proto":true},{"addr":"0x637620","include_decompile":true,"include_proto":true},{"addr":"0x637630","include_decompile":true,"include_proto":true},{"addr":"0x6376b0","include_decompile":true,"include_proto":true},{"addr":"0x6376d0","include_decompile":true,"include_proto":true},{"addr":"0x6376e0","include_decompile":true,"include_proto":true},{"addr":"0x6376f0","include_decompile":true,"include_proto":true},{"addr":"0x637700","include_decompile":true,"include_proto":true},{"addr":"0x637710","include_decompile":true,"include_proto":true},{"addr":"0x637720","include_decompile":true,"include_proto":true},{"addr":"0x637730","include_decompile":true,"include_proto":true},{"addr":"0x637750","include_decompile":true,"include_proto":true},{"addr":"0x637780","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0034', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0034: empty response'); return; }
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
      console.log('Batch 0034: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0034 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0034 conn error:', e.message));
req.write(body);
req.end();
