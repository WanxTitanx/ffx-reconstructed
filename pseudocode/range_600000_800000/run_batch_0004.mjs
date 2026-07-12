
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x607c50","include_decompile":true,"include_proto":true},{"addr":"0x607cf0","include_decompile":true,"include_proto":true},{"addr":"0x607d00","include_decompile":true,"include_proto":true},{"addr":"0x607d10","include_decompile":true,"include_proto":true},{"addr":"0x607d20","include_decompile":true,"include_proto":true},{"addr":"0x607d30","include_decompile":true,"include_proto":true},{"addr":"0x607d40","include_decompile":true,"include_proto":true},{"addr":"0x607d50","include_decompile":true,"include_proto":true},{"addr":"0x607d80","include_decompile":true,"include_proto":true},{"addr":"0x607dc0","include_decompile":true,"include_proto":true},{"addr":"0x607dd0","include_decompile":true,"include_proto":true},{"addr":"0x607e00","include_decompile":true,"include_proto":true},{"addr":"0x607ef0","include_decompile":true,"include_proto":true},{"addr":"0x607f00","include_decompile":true,"include_proto":true},{"addr":"0x607f10","include_decompile":true,"include_proto":true},{"addr":"0x607f40","include_decompile":true,"include_proto":true},{"addr":"0x607f80","include_decompile":true,"include_proto":true},{"addr":"0x607fc0","include_decompile":true,"include_proto":true},{"addr":"0x6080e0","include_decompile":true,"include_proto":true},{"addr":"0x608100","include_decompile":true,"include_proto":true},{"addr":"0x608250","include_decompile":true,"include_proto":true},{"addr":"0x6082a0","include_decompile":true,"include_proto":true},{"addr":"0x6082e0","include_decompile":true,"include_proto":true},{"addr":"0x608320","include_decompile":true,"include_proto":true},{"addr":"0x6084a0","include_decompile":true,"include_proto":true},{"addr":"0x609270","include_decompile":true,"include_proto":true},{"addr":"0x60a500","include_decompile":true,"include_proto":true},{"addr":"0x60a910","include_decompile":true,"include_proto":true},{"addr":"0x60ad00","include_decompile":true,"include_proto":true},{"addr":"0x60ad10","include_decompile":true,"include_proto":true},{"addr":"0x60ad20","include_decompile":true,"include_proto":true},{"addr":"0x60ad60","include_decompile":true,"include_proto":true},{"addr":"0x60adc0","include_decompile":true,"include_proto":true},{"addr":"0x60ae10","include_decompile":true,"include_proto":true},{"addr":"0x60aec0","include_decompile":true,"include_proto":true},{"addr":"0x60af90","include_decompile":true,"include_proto":true},{"addr":"0x60afc0","include_decompile":true,"include_proto":true},{"addr":"0x60aff0","include_decompile":true,"include_proto":true},{"addr":"0x60b000","include_decompile":true,"include_proto":true},{"addr":"0x60b010","include_decompile":true,"include_proto":true},{"addr":"0x60b050","include_decompile":true,"include_proto":true},{"addr":"0x60b070","include_decompile":true,"include_proto":true},{"addr":"0x60b180","include_decompile":true,"include_proto":true},{"addr":"0x60b2b0","include_decompile":true,"include_proto":true},{"addr":"0x60b3b0","include_decompile":true,"include_proto":true},{"addr":"0x60b4d0","include_decompile":true,"include_proto":true},{"addr":"0x60b5e0","include_decompile":true,"include_proto":true},{"addr":"0x60b710","include_decompile":true,"include_proto":true},{"addr":"0x60b800","include_decompile":true,"include_proto":true},{"addr":"0x60b8b0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0004', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0004: empty response'); return; }
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
      console.log('Batch 0004: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0004 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0004 conn error:', e.message));
req.write(body);
req.end();
