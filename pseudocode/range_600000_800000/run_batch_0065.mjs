
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6753b0","include_decompile":true,"include_proto":true},{"addr":"0x675430","include_decompile":true,"include_proto":true},{"addr":"0x675440","include_decompile":true,"include_proto":true},{"addr":"0x675450","include_decompile":true,"include_proto":true},{"addr":"0x6754a0","include_decompile":true,"include_proto":true},{"addr":"0x6755d0","include_decompile":true,"include_proto":true},{"addr":"0x6756c0","include_decompile":true,"include_proto":true},{"addr":"0x6756e0","include_decompile":true,"include_proto":true},{"addr":"0x675700","include_decompile":true,"include_proto":true},{"addr":"0x675710","include_decompile":true,"include_proto":true},{"addr":"0x675720","include_decompile":true,"include_proto":true},{"addr":"0x675750","include_decompile":true,"include_proto":true},{"addr":"0x675780","include_decompile":true,"include_proto":true},{"addr":"0x6757b0","include_decompile":true,"include_proto":true},{"addr":"0x6757e0","include_decompile":true,"include_proto":true},{"addr":"0x675800","include_decompile":true,"include_proto":true},{"addr":"0x675880","include_decompile":true,"include_proto":true},{"addr":"0x675960","include_decompile":true,"include_proto":true},{"addr":"0x675970","include_decompile":true,"include_proto":true},{"addr":"0x675980","include_decompile":true,"include_proto":true},{"addr":"0x675990","include_decompile":true,"include_proto":true},{"addr":"0x6759a0","include_decompile":true,"include_proto":true},{"addr":"0x6759b0","include_decompile":true,"include_proto":true},{"addr":"0x675ae0","include_decompile":true,"include_proto":true},{"addr":"0x675b00","include_decompile":true,"include_proto":true},{"addr":"0x675b80","include_decompile":true,"include_proto":true},{"addr":"0x675bb0","include_decompile":true,"include_proto":true},{"addr":"0x675bc0","include_decompile":true,"include_proto":true},{"addr":"0x675bd0","include_decompile":true,"include_proto":true},{"addr":"0x675bf0","include_decompile":true,"include_proto":true},{"addr":"0x675c00","include_decompile":true,"include_proto":true},{"addr":"0x675c10","include_decompile":true,"include_proto":true},{"addr":"0x675c30","include_decompile":true,"include_proto":true},{"addr":"0x675c40","include_decompile":true,"include_proto":true},{"addr":"0x675ca0","include_decompile":true,"include_proto":true},{"addr":"0x675ce0","include_decompile":true,"include_proto":true},{"addr":"0x675d10","include_decompile":true,"include_proto":true},{"addr":"0x675d90","include_decompile":true,"include_proto":true},{"addr":"0x675e10","include_decompile":true,"include_proto":true},{"addr":"0x675f40","include_decompile":true,"include_proto":true},{"addr":"0x675fc0","include_decompile":true,"include_proto":true},{"addr":"0x6760c0","include_decompile":true,"include_proto":true},{"addr":"0x6760d0","include_decompile":true,"include_proto":true},{"addr":"0x6760f0","include_decompile":true,"include_proto":true},{"addr":"0x676150","include_decompile":true,"include_proto":true},{"addr":"0x676180","include_decompile":true,"include_proto":true},{"addr":"0x6761b0","include_decompile":true,"include_proto":true},{"addr":"0x6761e0","include_decompile":true,"include_proto":true},{"addr":"0x676210","include_decompile":true,"include_proto":true},{"addr":"0x676230","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0065', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0065: empty response'); return; }
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
      console.log('Batch 0065: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0065 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0065 conn error:', e.message));
req.write(body);
req.end();
