
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x77ea30","include_decompile":true,"include_proto":true},{"addr":"0x77ea90","include_decompile":true,"include_proto":true},{"addr":"0x77eae0","include_decompile":true,"include_proto":true},{"addr":"0x77eb00","include_decompile":true,"include_proto":true},{"addr":"0x77eb30","include_decompile":true,"include_proto":true},{"addr":"0x77eb90","include_decompile":true,"include_proto":true},{"addr":"0x77ebc0","include_decompile":true,"include_proto":true},{"addr":"0x77ebf0","include_decompile":true,"include_proto":true},{"addr":"0x77ec60","include_decompile":true,"include_proto":true},{"addr":"0x77ecb0","include_decompile":true,"include_proto":true},{"addr":"0x77ecd0","include_decompile":true,"include_proto":true},{"addr":"0x77ed10","include_decompile":true,"include_proto":true},{"addr":"0x77ef30","include_decompile":true,"include_proto":true},{"addr":"0x77f0e0","include_decompile":true,"include_proto":true},{"addr":"0x77f1d0","include_decompile":true,"include_proto":true},{"addr":"0x77f1f0","include_decompile":true,"include_proto":true},{"addr":"0x77f230","include_decompile":true,"include_proto":true},{"addr":"0x77f250","include_decompile":true,"include_proto":true},{"addr":"0x77f2c0","include_decompile":true,"include_proto":true},{"addr":"0x77f2d0","include_decompile":true,"include_proto":true},{"addr":"0x77f2e0","include_decompile":true,"include_proto":true},{"addr":"0x77f2f0","include_decompile":true,"include_proto":true},{"addr":"0x77f300","include_decompile":true,"include_proto":true},{"addr":"0x77f450","include_decompile":true,"include_proto":true},{"addr":"0x77fa40","include_decompile":true,"include_proto":true},{"addr":"0x77fa90","include_decompile":true,"include_proto":true},{"addr":"0x77fcc0","include_decompile":true,"include_proto":true},{"addr":"0x77fd60","include_decompile":true,"include_proto":true},{"addr":"0x77fdb0","include_decompile":true,"include_proto":true},{"addr":"0x77fe70","include_decompile":true,"include_proto":true},{"addr":"0x77ff00","include_decompile":true,"include_proto":true},{"addr":"0x77ff20","include_decompile":true,"include_proto":true},{"addr":"0x77ffd0","include_decompile":true,"include_proto":true},{"addr":"0x780470","include_decompile":true,"include_proto":true},{"addr":"0x7804c0","include_decompile":true,"include_proto":true},{"addr":"0x780820","include_decompile":true,"include_proto":true},{"addr":"0x780890","include_decompile":true,"include_proto":true},{"addr":"0x7809c0","include_decompile":true,"include_proto":true},{"addr":"0x780c10","include_decompile":true,"include_proto":true},{"addr":"0x780d40","include_decompile":true,"include_proto":true},{"addr":"0x780d60","include_decompile":true,"include_proto":true},{"addr":"0x780d80","include_decompile":true,"include_proto":true},{"addr":"0x780d90","include_decompile":true,"include_proto":true},{"addr":"0x780db0","include_decompile":true,"include_proto":true},{"addr":"0x780dc0","include_decompile":true,"include_proto":true},{"addr":"0x780dd0","include_decompile":true,"include_proto":true},{"addr":"0x780de0","include_decompile":true,"include_proto":true},{"addr":"0x7810b0","include_decompile":true,"include_proto":true},{"addr":"0x7810c0","include_decompile":true,"include_proto":true},{"addr":"0x7810f0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0162', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0162: empty response'); return; }
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
      console.log('Batch 0162: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0162 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0162 conn error:', e.message));
req.write(body);
req.end();
