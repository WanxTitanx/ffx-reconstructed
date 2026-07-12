
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x677290","include_decompile":true,"include_proto":true},{"addr":"0x6772a0","include_decompile":true,"include_proto":true},{"addr":"0x677300","include_decompile":true,"include_proto":true},{"addr":"0x677340","include_decompile":true,"include_proto":true},{"addr":"0x677370","include_decompile":true,"include_proto":true},{"addr":"0x6773f0","include_decompile":true,"include_proto":true},{"addr":"0x677470","include_decompile":true,"include_proto":true},{"addr":"0x6775a0","include_decompile":true,"include_proto":true},{"addr":"0x677620","include_decompile":true,"include_proto":true},{"addr":"0x677720","include_decompile":true,"include_proto":true},{"addr":"0x677730","include_decompile":true,"include_proto":true},{"addr":"0x677750","include_decompile":true,"include_proto":true},{"addr":"0x6777b0","include_decompile":true,"include_proto":true},{"addr":"0x6777e0","include_decompile":true,"include_proto":true},{"addr":"0x677810","include_decompile":true,"include_proto":true},{"addr":"0x677840","include_decompile":true,"include_proto":true},{"addr":"0x677870","include_decompile":true,"include_proto":true},{"addr":"0x677890","include_decompile":true,"include_proto":true},{"addr":"0x677970","include_decompile":true,"include_proto":true},{"addr":"0x677a50","include_decompile":true,"include_proto":true},{"addr":"0x677a60","include_decompile":true,"include_proto":true},{"addr":"0x677b90","include_decompile":true,"include_proto":true},{"addr":"0x677bb0","include_decompile":true,"include_proto":true},{"addr":"0x677c10","include_decompile":true,"include_proto":true},{"addr":"0x677c90","include_decompile":true,"include_proto":true},{"addr":"0x677cc0","include_decompile":true,"include_proto":true},{"addr":"0x677da0","include_decompile":true,"include_proto":true},{"addr":"0x677dd0","include_decompile":true,"include_proto":true},{"addr":"0x677de0","include_decompile":true,"include_proto":true},{"addr":"0x677df0","include_decompile":true,"include_proto":true},{"addr":"0x677e10","include_decompile":true,"include_proto":true},{"addr":"0x677e30","include_decompile":true,"include_proto":true},{"addr":"0x677e90","include_decompile":true,"include_proto":true},{"addr":"0x677ff0","include_decompile":true,"include_proto":true},{"addr":"0x678030","include_decompile":true,"include_proto":true},{"addr":"0x678060","include_decompile":true,"include_proto":true},{"addr":"0x6780d0","include_decompile":true,"include_proto":true},{"addr":"0x6780f0","include_decompile":true,"include_proto":true},{"addr":"0x678100","include_decompile":true,"include_proto":true},{"addr":"0x678110","include_decompile":true,"include_proto":true},{"addr":"0x6781b0","include_decompile":true,"include_proto":true},{"addr":"0x6782e0","include_decompile":true,"include_proto":true},{"addr":"0x678360","include_decompile":true,"include_proto":true},{"addr":"0x678480","include_decompile":true,"include_proto":true},{"addr":"0x678490","include_decompile":true,"include_proto":true},{"addr":"0x6784b0","include_decompile":true,"include_proto":true},{"addr":"0x6784c0","include_decompile":true,"include_proto":true},{"addr":"0x678650","include_decompile":true,"include_proto":true},{"addr":"0x678680","include_decompile":true,"include_proto":true},{"addr":"0x6786b0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0067', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0067: empty response'); return; }
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
      console.log('Batch 0067: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0067 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0067 conn error:', e.message));
req.write(body);
req.end();
