
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x741c40","include_decompile":true,"include_proto":true},{"addr":"0x741c50","include_decompile":true,"include_proto":true},{"addr":"0x742810","include_decompile":true,"include_proto":true},{"addr":"0x742a40","include_decompile":true,"include_proto":true},{"addr":"0x742c10","include_decompile":true,"include_proto":true},{"addr":"0x742c90","include_decompile":true,"include_proto":true},{"addr":"0x742d80","include_decompile":true,"include_proto":true},{"addr":"0x742fe0","include_decompile":true,"include_proto":true},{"addr":"0x7430f0","include_decompile":true,"include_proto":true},{"addr":"0x743330","include_decompile":true,"include_proto":true},{"addr":"0x743340","include_decompile":true,"include_proto":true},{"addr":"0x743c20","include_decompile":true,"include_proto":true},{"addr":"0x743e60","include_decompile":true,"include_proto":true},{"addr":"0x743fc0","include_decompile":true,"include_proto":true},{"addr":"0x744040","include_decompile":true,"include_proto":true},{"addr":"0x744100","include_decompile":true,"include_proto":true},{"addr":"0x744320","include_decompile":true,"include_proto":true},{"addr":"0x744550","include_decompile":true,"include_proto":true},{"addr":"0x744560","include_decompile":true,"include_proto":true},{"addr":"0x744e40","include_decompile":true,"include_proto":true},{"addr":"0x745020","include_decompile":true,"include_proto":true},{"addr":"0x745160","include_decompile":true,"include_proto":true},{"addr":"0x7451f0","include_decompile":true,"include_proto":true},{"addr":"0x7452d0","include_decompile":true,"include_proto":true},{"addr":"0x745560","include_decompile":true,"include_proto":true},{"addr":"0x7456d0","include_decompile":true,"include_proto":true},{"addr":"0x7457f0","include_decompile":true,"include_proto":true},{"addr":"0x745800","include_decompile":true,"include_proto":true},{"addr":"0x746030","include_decompile":true,"include_proto":true},{"addr":"0x746170","include_decompile":true,"include_proto":true},{"addr":"0x7462c0","include_decompile":true,"include_proto":true},{"addr":"0x746340","include_decompile":true,"include_proto":true},{"addr":"0x7463e0","include_decompile":true,"include_proto":true},{"addr":"0x746600","include_decompile":true,"include_proto":true},{"addr":"0x746860","include_decompile":true,"include_proto":true},{"addr":"0x746870","include_decompile":true,"include_proto":true},{"addr":"0x747150","include_decompile":true,"include_proto":true},{"addr":"0x747370","include_decompile":true,"include_proto":true},{"addr":"0x7474d0","include_decompile":true,"include_proto":true},{"addr":"0x747550","include_decompile":true,"include_proto":true},{"addr":"0x747600","include_decompile":true,"include_proto":true},{"addr":"0x747820","include_decompile":true,"include_proto":true},{"addr":"0x747a80","include_decompile":true,"include_proto":true},{"addr":"0x747aa0","include_decompile":true,"include_proto":true},{"addr":"0x7483b0","include_decompile":true,"include_proto":true},{"addr":"0x7485d0","include_decompile":true,"include_proto":true},{"addr":"0x748730","include_decompile":true,"include_proto":true},{"addr":"0x7487b0","include_decompile":true,"include_proto":true},{"addr":"0x748860","include_decompile":true,"include_proto":true},{"addr":"0x748a80","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0138', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0138: empty response'); return; }
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
      console.log('Batch 0138: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0138 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0138 conn error:', e.message));
req.write(body);
req.end();
