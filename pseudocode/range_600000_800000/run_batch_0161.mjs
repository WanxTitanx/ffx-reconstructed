
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x77b430","include_decompile":true,"include_proto":true},{"addr":"0x77b530","include_decompile":true,"include_proto":true},{"addr":"0x77b570","include_decompile":true,"include_proto":true},{"addr":"0x77b720","include_decompile":true,"include_proto":true},{"addr":"0x77baa0","include_decompile":true,"include_proto":true},{"addr":"0x77bb60","include_decompile":true,"include_proto":true},{"addr":"0x77c450","include_decompile":true,"include_proto":true},{"addr":"0x77c4b0","include_decompile":true,"include_proto":true},{"addr":"0x77c560","include_decompile":true,"include_proto":true},{"addr":"0x77c5b0","include_decompile":true,"include_proto":true},{"addr":"0x77c7c0","include_decompile":true,"include_proto":true},{"addr":"0x77c860","include_decompile":true,"include_proto":true},{"addr":"0x77c920","include_decompile":true,"include_proto":true},{"addr":"0x77c960","include_decompile":true,"include_proto":true},{"addr":"0x77c9c0","include_decompile":true,"include_proto":true},{"addr":"0x77c9f0","include_decompile":true,"include_proto":true},{"addr":"0x77ca40","include_decompile":true,"include_proto":true},{"addr":"0x77cb00","include_decompile":true,"include_proto":true},{"addr":"0x77cb70","include_decompile":true,"include_proto":true},{"addr":"0x77cdb0","include_decompile":true,"include_proto":true},{"addr":"0x77ce90","include_decompile":true,"include_proto":true},{"addr":"0x77cea0","include_decompile":true,"include_proto":true},{"addr":"0x77cf00","include_decompile":true,"include_proto":true},{"addr":"0x77d070","include_decompile":true,"include_proto":true},{"addr":"0x77d090","include_decompile":true,"include_proto":true},{"addr":"0x77d320","include_decompile":true,"include_proto":true},{"addr":"0x77d370","include_decompile":true,"include_proto":true},{"addr":"0x77d6d0","include_decompile":true,"include_proto":true},{"addr":"0x77d860","include_decompile":true,"include_proto":true},{"addr":"0x77db60","include_decompile":true,"include_proto":true},{"addr":"0x77db80","include_decompile":true,"include_proto":true},{"addr":"0x77db90","include_decompile":true,"include_proto":true},{"addr":"0x77dba0","include_decompile":true,"include_proto":true},{"addr":"0x77dd40","include_decompile":true,"include_proto":true},{"addr":"0x77df30","include_decompile":true,"include_proto":true},{"addr":"0x77df80","include_decompile":true,"include_proto":true},{"addr":"0x77e080","include_decompile":true,"include_proto":true},{"addr":"0x77e200","include_decompile":true,"include_proto":true},{"addr":"0x77e250","include_decompile":true,"include_proto":true},{"addr":"0x77e300","include_decompile":true,"include_proto":true},{"addr":"0x77e550","include_decompile":true,"include_proto":true},{"addr":"0x77e820","include_decompile":true,"include_proto":true},{"addr":"0x77e860","include_decompile":true,"include_proto":true},{"addr":"0x77e8b0","include_decompile":true,"include_proto":true},{"addr":"0x77e8f0","include_decompile":true,"include_proto":true},{"addr":"0x77e920","include_decompile":true,"include_proto":true},{"addr":"0x77e970","include_decompile":true,"include_proto":true},{"addr":"0x77e9a0","include_decompile":true,"include_proto":true},{"addr":"0x77e9d0","include_decompile":true,"include_proto":true},{"addr":"0x77ea10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0161', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0161: empty response'); return; }
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
      console.log('Batch 0161: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0161 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0161 conn error:', e.message));
req.write(body);
req.end();
