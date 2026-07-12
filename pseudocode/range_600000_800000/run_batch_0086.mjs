
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6a0b70","include_decompile":true,"include_proto":true},{"addr":"0x6a0c30","include_decompile":true,"include_proto":true},{"addr":"0x6a0c90","include_decompile":true,"include_proto":true},{"addr":"0x6a0d60","include_decompile":true,"include_proto":true},{"addr":"0x6a0e40","include_decompile":true,"include_proto":true},{"addr":"0x6a0e80","include_decompile":true,"include_proto":true},{"addr":"0x6a1060","include_decompile":true,"include_proto":true},{"addr":"0x6a1070","include_decompile":true,"include_proto":true},{"addr":"0x6a1090","include_decompile":true,"include_proto":true},{"addr":"0x6a10b0","include_decompile":true,"include_proto":true},{"addr":"0x6a10c0","include_decompile":true,"include_proto":true},{"addr":"0x6a1120","include_decompile":true,"include_proto":true},{"addr":"0x6a1170","include_decompile":true,"include_proto":true},{"addr":"0x6a1180","include_decompile":true,"include_proto":true},{"addr":"0x6a1310","include_decompile":true,"include_proto":true},{"addr":"0x6a1340","include_decompile":true,"include_proto":true},{"addr":"0x6a1370","include_decompile":true,"include_proto":true},{"addr":"0x6a1440","include_decompile":true,"include_proto":true},{"addr":"0x6a1460","include_decompile":true,"include_proto":true},{"addr":"0x6a1690","include_decompile":true,"include_proto":true},{"addr":"0x6a16b0","include_decompile":true,"include_proto":true},{"addr":"0x6a16d0","include_decompile":true,"include_proto":true},{"addr":"0x6a1720","include_decompile":true,"include_proto":true},{"addr":"0x6a1780","include_decompile":true,"include_proto":true},{"addr":"0x6a1790","include_decompile":true,"include_proto":true},{"addr":"0x6a17a0","include_decompile":true,"include_proto":true},{"addr":"0x6a1860","include_decompile":true,"include_proto":true},{"addr":"0x6a1b10","include_decompile":true,"include_proto":true},{"addr":"0x6a1bb0","include_decompile":true,"include_proto":true},{"addr":"0x6a1e50","include_decompile":true,"include_proto":true},{"addr":"0x6a1ed0","include_decompile":true,"include_proto":true},{"addr":"0x6a1fc0","include_decompile":true,"include_proto":true},{"addr":"0x6a20a0","include_decompile":true,"include_proto":true},{"addr":"0x6a2120","include_decompile":true,"include_proto":true},{"addr":"0x6a2130","include_decompile":true,"include_proto":true},{"addr":"0x6a2140","include_decompile":true,"include_proto":true},{"addr":"0x6a2150","include_decompile":true,"include_proto":true},{"addr":"0x6a2170","include_decompile":true,"include_proto":true},{"addr":"0x6a21a0","include_decompile":true,"include_proto":true},{"addr":"0x6a2230","include_decompile":true,"include_proto":true},{"addr":"0x6a2240","include_decompile":true,"include_proto":true},{"addr":"0x6a2250","include_decompile":true,"include_proto":true},{"addr":"0x6a2340","include_decompile":true,"include_proto":true},{"addr":"0x6a2350","include_decompile":true,"include_proto":true},{"addr":"0x6a2360","include_decompile":true,"include_proto":true},{"addr":"0x6a2370","include_decompile":true,"include_proto":true},{"addr":"0x6a2380","include_decompile":true,"include_proto":true},{"addr":"0x6a2390","include_decompile":true,"include_proto":true},{"addr":"0x6a23a0","include_decompile":true,"include_proto":true},{"addr":"0x6a2410","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0086', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0086: empty response'); return; }
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
      console.log('Batch 0086: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0086 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0086 conn error:', e.message));
req.write(body);
req.end();
