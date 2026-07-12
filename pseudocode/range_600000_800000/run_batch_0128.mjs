
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x70c9d0","include_decompile":true,"include_proto":true},{"addr":"0x70cd10","include_decompile":true,"include_proto":true},{"addr":"0x70cdb0","include_decompile":true,"include_proto":true},{"addr":"0x70ce00","include_decompile":true,"include_proto":true},{"addr":"0x70ce10","include_decompile":true,"include_proto":true},{"addr":"0x70ce20","include_decompile":true,"include_proto":true},{"addr":"0x70ce30","include_decompile":true,"include_proto":true},{"addr":"0x70ce40","include_decompile":true,"include_proto":true},{"addr":"0x70cec0","include_decompile":true,"include_proto":true},{"addr":"0x70cf70","include_decompile":true,"include_proto":true},{"addr":"0x70cff0","include_decompile":true,"include_proto":true},{"addr":"0x70d1a0","include_decompile":true,"include_proto":true},{"addr":"0x70d270","include_decompile":true,"include_proto":true},{"addr":"0x70d480","include_decompile":true,"include_proto":true},{"addr":"0x70d5e0","include_decompile":true,"include_proto":true},{"addr":"0x70d720","include_decompile":true,"include_proto":true},{"addr":"0x70d770","include_decompile":true,"include_proto":true},{"addr":"0x70d7c0","include_decompile":true,"include_proto":true},{"addr":"0x70d810","include_decompile":true,"include_proto":true},{"addr":"0x70d860","include_decompile":true,"include_proto":true},{"addr":"0x70d970","include_decompile":true,"include_proto":true},{"addr":"0x70d9d0","include_decompile":true,"include_proto":true},{"addr":"0x70da10","include_decompile":true,"include_proto":true},{"addr":"0x70dac0","include_decompile":true,"include_proto":true},{"addr":"0x70db70","include_decompile":true,"include_proto":true},{"addr":"0x70dc70","include_decompile":true,"include_proto":true},{"addr":"0x70dc90","include_decompile":true,"include_proto":true},{"addr":"0x70ddf0","include_decompile":true,"include_proto":true},{"addr":"0x70dfa0","include_decompile":true,"include_proto":true},{"addr":"0x70e370","include_decompile":true,"include_proto":true},{"addr":"0x70e390","include_decompile":true,"include_proto":true},{"addr":"0x70e3b0","include_decompile":true,"include_proto":true},{"addr":"0x70e4e0","include_decompile":true,"include_proto":true},{"addr":"0x70e530","include_decompile":true,"include_proto":true},{"addr":"0x70e560","include_decompile":true,"include_proto":true},{"addr":"0x70e740","include_decompile":true,"include_proto":true},{"addr":"0x70e760","include_decompile":true,"include_proto":true},{"addr":"0x70e780","include_decompile":true,"include_proto":true},{"addr":"0x70e7f0","include_decompile":true,"include_proto":true},{"addr":"0x70e920","include_decompile":true,"include_proto":true},{"addr":"0x70e930","include_decompile":true,"include_proto":true},{"addr":"0x70eb00","include_decompile":true,"include_proto":true},{"addr":"0x70eba0","include_decompile":true,"include_proto":true},{"addr":"0x70ec00","include_decompile":true,"include_proto":true},{"addr":"0x70ec10","include_decompile":true,"include_proto":true},{"addr":"0x70ed20","include_decompile":true,"include_proto":true},{"addr":"0x70ee10","include_decompile":true,"include_proto":true},{"addr":"0x70ee90","include_decompile":true,"include_proto":true},{"addr":"0x70ef70","include_decompile":true,"include_proto":true},{"addr":"0x70ef90","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0128', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0128: empty response'); return; }
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
      console.log('Batch 0128: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0128 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0128 conn error:', e.message));
req.write(body);
req.end();
