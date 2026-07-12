
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6dbfb0","include_decompile":true,"include_proto":true},{"addr":"0x6dc060","include_decompile":true,"include_proto":true},{"addr":"0x6dc080","include_decompile":true,"include_proto":true},{"addr":"0x6dc140","include_decompile":true,"include_proto":true},{"addr":"0x6dc270","include_decompile":true,"include_proto":true},{"addr":"0x6dc3c0","include_decompile":true,"include_proto":true},{"addr":"0x6dc430","include_decompile":true,"include_proto":true},{"addr":"0x6dc4d0","include_decompile":true,"include_proto":true},{"addr":"0x6dc580","include_decompile":true,"include_proto":true},{"addr":"0x6dc640","include_decompile":true,"include_proto":true},{"addr":"0x6dc6a0","include_decompile":true,"include_proto":true},{"addr":"0x6dc700","include_decompile":true,"include_proto":true},{"addr":"0x6dc770","include_decompile":true,"include_proto":true},{"addr":"0x6dc800","include_decompile":true,"include_proto":true},{"addr":"0x6dc880","include_decompile":true,"include_proto":true},{"addr":"0x6dc8a0","include_decompile":true,"include_proto":true},{"addr":"0x6dc930","include_decompile":true,"include_proto":true},{"addr":"0x6dc9a0","include_decompile":true,"include_proto":true},{"addr":"0x6dc9d0","include_decompile":true,"include_proto":true},{"addr":"0x6dca00","include_decompile":true,"include_proto":true},{"addr":"0x6dcb90","include_decompile":true,"include_proto":true},{"addr":"0x6dcba0","include_decompile":true,"include_proto":true},{"addr":"0x6dce80","include_decompile":true,"include_proto":true},{"addr":"0x6dcef0","include_decompile":true,"include_proto":true},{"addr":"0x6dcf80","include_decompile":true,"include_proto":true},{"addr":"0x6dd110","include_decompile":true,"include_proto":true},{"addr":"0x6dd330","include_decompile":true,"include_proto":true},{"addr":"0x6dd360","include_decompile":true,"include_proto":true},{"addr":"0x6dd4e0","include_decompile":true,"include_proto":true},{"addr":"0x6dd5e0","include_decompile":true,"include_proto":true},{"addr":"0x6dd6d0","include_decompile":true,"include_proto":true},{"addr":"0x6dd980","include_decompile":true,"include_proto":true},{"addr":"0x6ddd20","include_decompile":true,"include_proto":true},{"addr":"0x6dddb0","include_decompile":true,"include_proto":true},{"addr":"0x6dde90","include_decompile":true,"include_proto":true},{"addr":"0x6ddfe0","include_decompile":true,"include_proto":true},{"addr":"0x6de000","include_decompile":true,"include_proto":true},{"addr":"0x6de070","include_decompile":true,"include_proto":true},{"addr":"0x6de0d0","include_decompile":true,"include_proto":true},{"addr":"0x6de100","include_decompile":true,"include_proto":true},{"addr":"0x6de140","include_decompile":true,"include_proto":true},{"addr":"0x6de2f0","include_decompile":true,"include_proto":true},{"addr":"0x6de300","include_decompile":true,"include_proto":true},{"addr":"0x6de380","include_decompile":true,"include_proto":true},{"addr":"0x6de3f0","include_decompile":true,"include_proto":true},{"addr":"0x6de500","include_decompile":true,"include_proto":true},{"addr":"0x6de550","include_decompile":true,"include_proto":true},{"addr":"0x6de660","include_decompile":true,"include_proto":true},{"addr":"0x6de750","include_decompile":true,"include_proto":true},{"addr":"0x6de850","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0106', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0106: empty response'); return; }
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
      console.log('Batch 0106: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0106 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0106 conn error:', e.message));
req.write(body);
req.end();
