
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x666220","include_decompile":true,"include_proto":true},{"addr":"0x666230","include_decompile":true,"include_proto":true},{"addr":"0x666240","include_decompile":true,"include_proto":true},{"addr":"0x666250","include_decompile":true,"include_proto":true},{"addr":"0x666260","include_decompile":true,"include_proto":true},{"addr":"0x666270","include_decompile":true,"include_proto":true},{"addr":"0x666280","include_decompile":true,"include_proto":true},{"addr":"0x666290","include_decompile":true,"include_proto":true},{"addr":"0x6662a0","include_decompile":true,"include_proto":true},{"addr":"0x6662b0","include_decompile":true,"include_proto":true},{"addr":"0x6662c0","include_decompile":true,"include_proto":true},{"addr":"0x6662d0","include_decompile":true,"include_proto":true},{"addr":"0x6662e0","include_decompile":true,"include_proto":true},{"addr":"0x6662f0","include_decompile":true,"include_proto":true},{"addr":"0x666300","include_decompile":true,"include_proto":true},{"addr":"0x666310","include_decompile":true,"include_proto":true},{"addr":"0x666320","include_decompile":true,"include_proto":true},{"addr":"0x666330","include_decompile":true,"include_proto":true},{"addr":"0x666340","include_decompile":true,"include_proto":true},{"addr":"0x666350","include_decompile":true,"include_proto":true},{"addr":"0x666360","include_decompile":true,"include_proto":true},{"addr":"0x666370","include_decompile":true,"include_proto":true},{"addr":"0x666380","include_decompile":true,"include_proto":true},{"addr":"0x666390","include_decompile":true,"include_proto":true},{"addr":"0x6663a0","include_decompile":true,"include_proto":true},{"addr":"0x6663b0","include_decompile":true,"include_proto":true},{"addr":"0x6663c0","include_decompile":true,"include_proto":true},{"addr":"0x6663d0","include_decompile":true,"include_proto":true},{"addr":"0x6663e0","include_decompile":true,"include_proto":true},{"addr":"0x6663f0","include_decompile":true,"include_proto":true},{"addr":"0x666400","include_decompile":true,"include_proto":true},{"addr":"0x666410","include_decompile":true,"include_proto":true},{"addr":"0x666420","include_decompile":true,"include_proto":true},{"addr":"0x666430","include_decompile":true,"include_proto":true},{"addr":"0x666460","include_decompile":true,"include_proto":true},{"addr":"0x666480","include_decompile":true,"include_proto":true},{"addr":"0x666560","include_decompile":true,"include_proto":true},{"addr":"0x6667a0","include_decompile":true,"include_proto":true},{"addr":"0x6667c0","include_decompile":true,"include_proto":true},{"addr":"0x666830","include_decompile":true,"include_proto":true},{"addr":"0x6668d0","include_decompile":true,"include_proto":true},{"addr":"0x666a10","include_decompile":true,"include_proto":true},{"addr":"0x666a80","include_decompile":true,"include_proto":true},{"addr":"0x666aa0","include_decompile":true,"include_proto":true},{"addr":"0x666ab0","include_decompile":true,"include_proto":true},{"addr":"0x666c30","include_decompile":true,"include_proto":true},{"addr":"0x666db0","include_decompile":true,"include_proto":true},{"addr":"0x666fd0","include_decompile":true,"include_proto":true},{"addr":"0x667540","include_decompile":true,"include_proto":true},{"addr":"0x6677b0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0059', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0059: empty response'); return; }
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
      console.log('Batch 0059: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0059 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0059 conn error:', e.message));
req.write(body);
req.end();
