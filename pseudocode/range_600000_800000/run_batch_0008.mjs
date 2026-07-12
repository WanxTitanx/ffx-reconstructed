
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x611aa0","include_decompile":true,"include_proto":true},{"addr":"0x611b00","include_decompile":true,"include_proto":true},{"addr":"0x611ba0","include_decompile":true,"include_proto":true},{"addr":"0x611c10","include_decompile":true,"include_proto":true},{"addr":"0x611c20","include_decompile":true,"include_proto":true},{"addr":"0x611c30","include_decompile":true,"include_proto":true},{"addr":"0x611c40","include_decompile":true,"include_proto":true},{"addr":"0x611c50","include_decompile":true,"include_proto":true},{"addr":"0x611c60","include_decompile":true,"include_proto":true},{"addr":"0x611c70","include_decompile":true,"include_proto":true},{"addr":"0x611d80","include_decompile":true,"include_proto":true},{"addr":"0x611e10","include_decompile":true,"include_proto":true},{"addr":"0x611ef0","include_decompile":true,"include_proto":true},{"addr":"0x611f20","include_decompile":true,"include_proto":true},{"addr":"0x612030","include_decompile":true,"include_proto":true},{"addr":"0x612040","include_decompile":true,"include_proto":true},{"addr":"0x612050","include_decompile":true,"include_proto":true},{"addr":"0x612060","include_decompile":true,"include_proto":true},{"addr":"0x612080","include_decompile":true,"include_proto":true},{"addr":"0x6120b0","include_decompile":true,"include_proto":true},{"addr":"0x612120","include_decompile":true,"include_proto":true},{"addr":"0x612130","include_decompile":true,"include_proto":true},{"addr":"0x612240","include_decompile":true,"include_proto":true},{"addr":"0x612370","include_decompile":true,"include_proto":true},{"addr":"0x612450","include_decompile":true,"include_proto":true},{"addr":"0x612660","include_decompile":true,"include_proto":true},{"addr":"0x612680","include_decompile":true,"include_proto":true},{"addr":"0x612810","include_decompile":true,"include_proto":true},{"addr":"0x612b60","include_decompile":true,"include_proto":true},{"addr":"0x612b70","include_decompile":true,"include_proto":true},{"addr":"0x612b80","include_decompile":true,"include_proto":true},{"addr":"0x612df0","include_decompile":true,"include_proto":true},{"addr":"0x612e00","include_decompile":true,"include_proto":true},{"addr":"0x612e10","include_decompile":true,"include_proto":true},{"addr":"0x612ed0","include_decompile":true,"include_proto":true},{"addr":"0x612ee0","include_decompile":true,"include_proto":true},{"addr":"0x612f20","include_decompile":true,"include_proto":true},{"addr":"0x612fa0","include_decompile":true,"include_proto":true},{"addr":"0x612ff0","include_decompile":true,"include_proto":true},{"addr":"0x613060","include_decompile":true,"include_proto":true},{"addr":"0x613100","include_decompile":true,"include_proto":true},{"addr":"0x6132e0","include_decompile":true,"include_proto":true},{"addr":"0x6132f0","include_decompile":true,"include_proto":true},{"addr":"0x613300","include_decompile":true,"include_proto":true},{"addr":"0x613310","include_decompile":true,"include_proto":true},{"addr":"0x613320","include_decompile":true,"include_proto":true},{"addr":"0x6133a0","include_decompile":true,"include_proto":true},{"addr":"0x6133b0","include_decompile":true,"include_proto":true},{"addr":"0x6133c0","include_decompile":true,"include_proto":true},{"addr":"0x6133d0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0008', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0008: empty response'); return; }
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
      console.log('Batch 0008: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0008 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0008 conn error:', e.message));
req.write(body);
req.end();
