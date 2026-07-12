
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x62fd30","include_decompile":true,"include_proto":true},{"addr":"0x62fd40","include_decompile":true,"include_proto":true},{"addr":"0x62fd50","include_decompile":true,"include_proto":true},{"addr":"0x62fd60","include_decompile":true,"include_proto":true},{"addr":"0x62fd70","include_decompile":true,"include_proto":true},{"addr":"0x62fd80","include_decompile":true,"include_proto":true},{"addr":"0x62fd90","include_decompile":true,"include_proto":true},{"addr":"0x62fda0","include_decompile":true,"include_proto":true},{"addr":"0x62fdb0","include_decompile":true,"include_proto":true},{"addr":"0x62fdd0","include_decompile":true,"include_proto":true},{"addr":"0x62fde0","include_decompile":true,"include_proto":true},{"addr":"0x62fe10","include_decompile":true,"include_proto":true},{"addr":"0x62fe20","include_decompile":true,"include_proto":true},{"addr":"0x62fe30","include_decompile":true,"include_proto":true},{"addr":"0x62fe40","include_decompile":true,"include_proto":true},{"addr":"0x62fe50","include_decompile":true,"include_proto":true},{"addr":"0x62fe70","include_decompile":true,"include_proto":true},{"addr":"0x62fe80","include_decompile":true,"include_proto":true},{"addr":"0x62fe90","include_decompile":true,"include_proto":true},{"addr":"0x62fec0","include_decompile":true,"include_proto":true},{"addr":"0x62ff20","include_decompile":true,"include_proto":true},{"addr":"0x62ff70","include_decompile":true,"include_proto":true},{"addr":"0x62ff90","include_decompile":true,"include_proto":true},{"addr":"0x62ffa0","include_decompile":true,"include_proto":true},{"addr":"0x630000","include_decompile":true,"include_proto":true},{"addr":"0x630080","include_decompile":true,"include_proto":true},{"addr":"0x630120","include_decompile":true,"include_proto":true},{"addr":"0x630190","include_decompile":true,"include_proto":true},{"addr":"0x630310","include_decompile":true,"include_proto":true},{"addr":"0x630370","include_decompile":true,"include_proto":true},{"addr":"0x6303f0","include_decompile":true,"include_proto":true},{"addr":"0x630470","include_decompile":true,"include_proto":true},{"addr":"0x630480","include_decompile":true,"include_proto":true},{"addr":"0x6304c0","include_decompile":true,"include_proto":true},{"addr":"0x630540","include_decompile":true,"include_proto":true},{"addr":"0x630590","include_decompile":true,"include_proto":true},{"addr":"0x6305a0","include_decompile":true,"include_proto":true},{"addr":"0x630610","include_decompile":true,"include_proto":true},{"addr":"0x630670","include_decompile":true,"include_proto":true},{"addr":"0x6306f0","include_decompile":true,"include_proto":true},{"addr":"0x630750","include_decompile":true,"include_proto":true},{"addr":"0x630760","include_decompile":true,"include_proto":true},{"addr":"0x630770","include_decompile":true,"include_proto":true},{"addr":"0x6307b0","include_decompile":true,"include_proto":true},{"addr":"0x6307c0","include_decompile":true,"include_proto":true},{"addr":"0x6307d0","include_decompile":true,"include_proto":true},{"addr":"0x6307e0","include_decompile":true,"include_proto":true},{"addr":"0x6308b0","include_decompile":true,"include_proto":true},{"addr":"0x6308e0","include_decompile":true,"include_proto":true},{"addr":"0x630a00","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0029', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0029: empty response'); return; }
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
      console.log('Batch 0029: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0029 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0029 conn error:', e.message));
req.write(body);
req.end();
