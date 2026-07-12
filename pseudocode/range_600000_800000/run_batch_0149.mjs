
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x76eed0","include_decompile":true,"include_proto":true},{"addr":"0x76f090","include_decompile":true,"include_proto":true},{"addr":"0x76f0a0","include_decompile":true,"include_proto":true},{"addr":"0x76f0b0","include_decompile":true,"include_proto":true},{"addr":"0x76f0c0","include_decompile":true,"include_proto":true},{"addr":"0x76f0d0","include_decompile":true,"include_proto":true},{"addr":"0x76f100","include_decompile":true,"include_proto":true},{"addr":"0x76f120","include_decompile":true,"include_proto":true},{"addr":"0x76f130","include_decompile":true,"include_proto":true},{"addr":"0x76f140","include_decompile":true,"include_proto":true},{"addr":"0x76f150","include_decompile":true,"include_proto":true},{"addr":"0x76f170","include_decompile":true,"include_proto":true},{"addr":"0x76f180","include_decompile":true,"include_proto":true},{"addr":"0x76f190","include_decompile":true,"include_proto":true},{"addr":"0x76f1a0","include_decompile":true,"include_proto":true},{"addr":"0x76f1b0","include_decompile":true,"include_proto":true},{"addr":"0x76f1c0","include_decompile":true,"include_proto":true},{"addr":"0x76f1d0","include_decompile":true,"include_proto":true},{"addr":"0x76f200","include_decompile":true,"include_proto":true},{"addr":"0x76f210","include_decompile":true,"include_proto":true},{"addr":"0x76f280","include_decompile":true,"include_proto":true},{"addr":"0x76f290","include_decompile":true,"include_proto":true},{"addr":"0x76f2b0","include_decompile":true,"include_proto":true},{"addr":"0x76f2e0","include_decompile":true,"include_proto":true},{"addr":"0x76f300","include_decompile":true,"include_proto":true},{"addr":"0x76f330","include_decompile":true,"include_proto":true},{"addr":"0x76f350","include_decompile":true,"include_proto":true},{"addr":"0x76f370","include_decompile":true,"include_proto":true},{"addr":"0x76f3a0","include_decompile":true,"include_proto":true},{"addr":"0x76f3c0","include_decompile":true,"include_proto":true},{"addr":"0x76f3f0","include_decompile":true,"include_proto":true},{"addr":"0x76f410","include_decompile":true,"include_proto":true},{"addr":"0x76f440","include_decompile":true,"include_proto":true},{"addr":"0x76f460","include_decompile":true,"include_proto":true},{"addr":"0x76f480","include_decompile":true,"include_proto":true},{"addr":"0x76f4a0","include_decompile":true,"include_proto":true},{"addr":"0x76f560","include_decompile":true,"include_proto":true},{"addr":"0x76f580","include_decompile":true,"include_proto":true},{"addr":"0x76f960","include_decompile":true,"include_proto":true},{"addr":"0x770430","include_decompile":true,"include_proto":true},{"addr":"0x770450","include_decompile":true,"include_proto":true},{"addr":"0x770540","include_decompile":true,"include_proto":true},{"addr":"0x770a30","include_decompile":true,"include_proto":true},{"addr":"0x770a60","include_decompile":true,"include_proto":true},{"addr":"0x770a80","include_decompile":true,"include_proto":true},{"addr":"0x770aa0","include_decompile":true,"include_proto":true},{"addr":"0x770ac0","include_decompile":true,"include_proto":true},{"addr":"0x770ae0","include_decompile":true,"include_proto":true},{"addr":"0x770b00","include_decompile":true,"include_proto":true},{"addr":"0x770b20","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0149', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0149: empty response'); return; }
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
      console.log('Batch 0149: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0149 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0149 conn error:', e.message));
req.write(body);
req.end();
