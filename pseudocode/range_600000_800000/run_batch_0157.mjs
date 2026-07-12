
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x773de0","include_decompile":true,"include_proto":true},{"addr":"0x773e00","include_decompile":true,"include_proto":true},{"addr":"0x773e20","include_decompile":true,"include_proto":true},{"addr":"0x773e40","include_decompile":true,"include_proto":true},{"addr":"0x773e60","include_decompile":true,"include_proto":true},{"addr":"0x773e80","include_decompile":true,"include_proto":true},{"addr":"0x773ea0","include_decompile":true,"include_proto":true},{"addr":"0x773ec0","include_decompile":true,"include_proto":true},{"addr":"0x773ee0","include_decompile":true,"include_proto":true},{"addr":"0x773f00","include_decompile":true,"include_proto":true},{"addr":"0x773f20","include_decompile":true,"include_proto":true},{"addr":"0x773f40","include_decompile":true,"include_proto":true},{"addr":"0x773f60","include_decompile":true,"include_proto":true},{"addr":"0x773f80","include_decompile":true,"include_proto":true},{"addr":"0x773fa0","include_decompile":true,"include_proto":true},{"addr":"0x773fc0","include_decompile":true,"include_proto":true},{"addr":"0x773fe0","include_decompile":true,"include_proto":true},{"addr":"0x774000","include_decompile":true,"include_proto":true},{"addr":"0x774020","include_decompile":true,"include_proto":true},{"addr":"0x774040","include_decompile":true,"include_proto":true},{"addr":"0x774060","include_decompile":true,"include_proto":true},{"addr":"0x774080","include_decompile":true,"include_proto":true},{"addr":"0x7740a0","include_decompile":true,"include_proto":true},{"addr":"0x7740c0","include_decompile":true,"include_proto":true},{"addr":"0x7740e0","include_decompile":true,"include_proto":true},{"addr":"0x774100","include_decompile":true,"include_proto":true},{"addr":"0x774120","include_decompile":true,"include_proto":true},{"addr":"0x774140","include_decompile":true,"include_proto":true},{"addr":"0x774160","include_decompile":true,"include_proto":true},{"addr":"0x774180","include_decompile":true,"include_proto":true},{"addr":"0x7741a0","include_decompile":true,"include_proto":true},{"addr":"0x7741c0","include_decompile":true,"include_proto":true},{"addr":"0x7741e0","include_decompile":true,"include_proto":true},{"addr":"0x774200","include_decompile":true,"include_proto":true},{"addr":"0x774220","include_decompile":true,"include_proto":true},{"addr":"0x774240","include_decompile":true,"include_proto":true},{"addr":"0x774260","include_decompile":true,"include_proto":true},{"addr":"0x774280","include_decompile":true,"include_proto":true},{"addr":"0x7742a0","include_decompile":true,"include_proto":true},{"addr":"0x7742c0","include_decompile":true,"include_proto":true},{"addr":"0x7742e0","include_decompile":true,"include_proto":true},{"addr":"0x774300","include_decompile":true,"include_proto":true},{"addr":"0x774320","include_decompile":true,"include_proto":true},{"addr":"0x774340","include_decompile":true,"include_proto":true},{"addr":"0x774360","include_decompile":true,"include_proto":true},{"addr":"0x774380","include_decompile":true,"include_proto":true},{"addr":"0x7743a0","include_decompile":true,"include_proto":true},{"addr":"0x7743c0","include_decompile":true,"include_proto":true},{"addr":"0x7743e0","include_decompile":true,"include_proto":true},{"addr":"0x774400","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0157', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0157: empty response'); return; }
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
      console.log('Batch 0157: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0157 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0157 conn error:', e.message));
req.write(body);
req.end();
