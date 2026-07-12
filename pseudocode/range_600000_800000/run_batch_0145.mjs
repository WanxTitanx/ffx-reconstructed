
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x75efc0","include_decompile":true,"include_proto":true},{"addr":"0x75fa10","include_decompile":true,"include_proto":true},{"addr":"0x75fc40","include_decompile":true,"include_proto":true},{"addr":"0x75fce0","include_decompile":true,"include_proto":true},{"addr":"0x75fdc0","include_decompile":true,"include_proto":true},{"addr":"0x75fe90","include_decompile":true,"include_proto":true},{"addr":"0x75fed0","include_decompile":true,"include_proto":true},{"addr":"0x75ff60","include_decompile":true,"include_proto":true},{"addr":"0x75ffd0","include_decompile":true,"include_proto":true},{"addr":"0x75fff0","include_decompile":true,"include_proto":true},{"addr":"0x760170","include_decompile":true,"include_proto":true},{"addr":"0x7606c0","include_decompile":true,"include_proto":true},{"addr":"0x760700","include_decompile":true,"include_proto":true},{"addr":"0x760730","include_decompile":true,"include_proto":true},{"addr":"0x7607e0","include_decompile":true,"include_proto":true},{"addr":"0x760920","include_decompile":true,"include_proto":true},{"addr":"0x760ce0","include_decompile":true,"include_proto":true},{"addr":"0x760dd0","include_decompile":true,"include_proto":true},{"addr":"0x760f20","include_decompile":true,"include_proto":true},{"addr":"0x761020","include_decompile":true,"include_proto":true},{"addr":"0x761260","include_decompile":true,"include_proto":true},{"addr":"0x761340","include_decompile":true,"include_proto":true},{"addr":"0x761440","include_decompile":true,"include_proto":true},{"addr":"0x761590","include_decompile":true,"include_proto":true},{"addr":"0x761d30","include_decompile":true,"include_proto":true},{"addr":"0x761d70","include_decompile":true,"include_proto":true},{"addr":"0x761e50","include_decompile":true,"include_proto":true},{"addr":"0x761f10","include_decompile":true,"include_proto":true},{"addr":"0x762330","include_decompile":true,"include_proto":true},{"addr":"0x762550","include_decompile":true,"include_proto":true},{"addr":"0x762640","include_decompile":true,"include_proto":true},{"addr":"0x762690","include_decompile":true,"include_proto":true},{"addr":"0x7627c0","include_decompile":true,"include_proto":true},{"addr":"0x762900","include_decompile":true,"include_proto":true},{"addr":"0x7629b0","include_decompile":true,"include_proto":true},{"addr":"0x762ad0","include_decompile":true,"include_proto":true},{"addr":"0x763040","include_decompile":true,"include_proto":true},{"addr":"0x763090","include_decompile":true,"include_proto":true},{"addr":"0x763120","include_decompile":true,"include_proto":true},{"addr":"0x7631f0","include_decompile":true,"include_proto":true},{"addr":"0x7637b0","include_decompile":true,"include_proto":true},{"addr":"0x7638e0","include_decompile":true,"include_proto":true},{"addr":"0x7645c0","include_decompile":true,"include_proto":true},{"addr":"0x7646d0","include_decompile":true,"include_proto":true},{"addr":"0x7648f0","include_decompile":true,"include_proto":true},{"addr":"0x764a90","include_decompile":true,"include_proto":true},{"addr":"0x764ca0","include_decompile":true,"include_proto":true},{"addr":"0x764d30","include_decompile":true,"include_proto":true},{"addr":"0x764ed0","include_decompile":true,"include_proto":true},{"addr":"0x7659a0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0145', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0145: empty response'); return; }
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
      console.log('Batch 0145: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0145 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0145 conn error:', e.message));
req.write(body);
req.end();
