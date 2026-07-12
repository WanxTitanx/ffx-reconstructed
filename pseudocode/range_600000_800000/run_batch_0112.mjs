
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6e8dc0","include_decompile":true,"include_proto":true},{"addr":"0x6e9060","include_decompile":true,"include_proto":true},{"addr":"0x6e9070","include_decompile":true,"include_proto":true},{"addr":"0x6e9100","include_decompile":true,"include_proto":true},{"addr":"0x6e9190","include_decompile":true,"include_proto":true},{"addr":"0x6e9220","include_decompile":true,"include_proto":true},{"addr":"0x6e9230","include_decompile":true,"include_proto":true},{"addr":"0x6e9240","include_decompile":true,"include_proto":true},{"addr":"0x6e9250","include_decompile":true,"include_proto":true},{"addr":"0x6e9260","include_decompile":true,"include_proto":true},{"addr":"0x6e9270","include_decompile":true,"include_proto":true},{"addr":"0x6e9330","include_decompile":true,"include_proto":true},{"addr":"0x6e9390","include_decompile":true,"include_proto":true},{"addr":"0x6e9530","include_decompile":true,"include_proto":true},{"addr":"0x6e9650","include_decompile":true,"include_proto":true},{"addr":"0x6e96b0","include_decompile":true,"include_proto":true},{"addr":"0x6e96d0","include_decompile":true,"include_proto":true},{"addr":"0x6e97f0","include_decompile":true,"include_proto":true},{"addr":"0x6e9800","include_decompile":true,"include_proto":true},{"addr":"0x6e9840","include_decompile":true,"include_proto":true},{"addr":"0x6e9970","include_decompile":true,"include_proto":true},{"addr":"0x6e99b0","include_decompile":true,"include_proto":true},{"addr":"0x6e9a50","include_decompile":true,"include_proto":true},{"addr":"0x6e9a60","include_decompile":true,"include_proto":true},{"addr":"0x6e9bd0","include_decompile":true,"include_proto":true},{"addr":"0x6e9be0","include_decompile":true,"include_proto":true},{"addr":"0x6e9bf0","include_decompile":true,"include_proto":true},{"addr":"0x6e9c00","include_decompile":true,"include_proto":true},{"addr":"0x6e9c10","include_decompile":true,"include_proto":true},{"addr":"0x6e9c20","include_decompile":true,"include_proto":true},{"addr":"0x6e9f40","include_decompile":true,"include_proto":true},{"addr":"0x6ea190","include_decompile":true,"include_proto":true},{"addr":"0x6ea280","include_decompile":true,"include_proto":true},{"addr":"0x6ea2c0","include_decompile":true,"include_proto":true},{"addr":"0x6ea3c0","include_decompile":true,"include_proto":true},{"addr":"0x6ea730","include_decompile":true,"include_proto":true},{"addr":"0x6ea940","include_decompile":true,"include_proto":true},{"addr":"0x6eab70","include_decompile":true,"include_proto":true},{"addr":"0x6eac10","include_decompile":true,"include_proto":true},{"addr":"0x6eac50","include_decompile":true,"include_proto":true},{"addr":"0x6eafb0","include_decompile":true,"include_proto":true},{"addr":"0x6eb2e0","include_decompile":true,"include_proto":true},{"addr":"0x6eb310","include_decompile":true,"include_proto":true},{"addr":"0x6eb520","include_decompile":true,"include_proto":true},{"addr":"0x6eb680","include_decompile":true,"include_proto":true},{"addr":"0x6eba90","include_decompile":true,"include_proto":true},{"addr":"0x6ebe70","include_decompile":true,"include_proto":true},{"addr":"0x6ebee0","include_decompile":true,"include_proto":true},{"addr":"0x6ec020","include_decompile":true,"include_proto":true},{"addr":"0x6ec700","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0112', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0112: empty response'); return; }
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
      console.log('Batch 0112: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0112 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0112 conn error:', e.message));
req.write(body);
req.end();
