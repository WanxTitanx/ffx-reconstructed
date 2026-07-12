
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6524c0","include_decompile":true,"include_proto":true},{"addr":"0x652590","include_decompile":true,"include_proto":true},{"addr":"0x6525b0","include_decompile":true,"include_proto":true},{"addr":"0x652620","include_decompile":true,"include_proto":true},{"addr":"0x6527b0","include_decompile":true,"include_proto":true},{"addr":"0x652850","include_decompile":true,"include_proto":true},{"addr":"0x652a80","include_decompile":true,"include_proto":true},{"addr":"0x652ac0","include_decompile":true,"include_proto":true},{"addr":"0x652bc0","include_decompile":true,"include_proto":true},{"addr":"0x653210","include_decompile":true,"include_proto":true},{"addr":"0x653360","include_decompile":true,"include_proto":true},{"addr":"0x6533e0","include_decompile":true,"include_proto":true},{"addr":"0x653760","include_decompile":true,"include_proto":true},{"addr":"0x6537b0","include_decompile":true,"include_proto":true},{"addr":"0x653a80","include_decompile":true,"include_proto":true},{"addr":"0x653b10","include_decompile":true,"include_proto":true},{"addr":"0x654220","include_decompile":true,"include_proto":true},{"addr":"0x654460","include_decompile":true,"include_proto":true},{"addr":"0x654700","include_decompile":true,"include_proto":true},{"addr":"0x654720","include_decompile":true,"include_proto":true},{"addr":"0x654800","include_decompile":true,"include_proto":true},{"addr":"0x654ae4","include_decompile":true,"include_proto":true},{"addr":"0x654af4","include_decompile":true,"include_proto":true},{"addr":"0x654b00","include_decompile":true,"include_proto":true},{"addr":"0x654b10","include_decompile":true,"include_proto":true},{"addr":"0x654cd0","include_decompile":true,"include_proto":true},{"addr":"0x654ef0","include_decompile":true,"include_proto":true},{"addr":"0x654f60","include_decompile":true,"include_proto":true},{"addr":"0x654fd0","include_decompile":true,"include_proto":true},{"addr":"0x655050","include_decompile":true,"include_proto":true},{"addr":"0x655080","include_decompile":true,"include_proto":true},{"addr":"0x6550b0","include_decompile":true,"include_proto":true},{"addr":"0x6550f0","include_decompile":true,"include_proto":true},{"addr":"0x655130","include_decompile":true,"include_proto":true},{"addr":"0x655170","include_decompile":true,"include_proto":true},{"addr":"0x655230","include_decompile":true,"include_proto":true},{"addr":"0x655240","include_decompile":true,"include_proto":true},{"addr":"0x655250","include_decompile":true,"include_proto":true},{"addr":"0x655260","include_decompile":true,"include_proto":true},{"addr":"0x655270","include_decompile":true,"include_proto":true},{"addr":"0x655280","include_decompile":true,"include_proto":true},{"addr":"0x655290","include_decompile":true,"include_proto":true},{"addr":"0x6552d0","include_decompile":true,"include_proto":true},{"addr":"0x655380","include_decompile":true,"include_proto":true},{"addr":"0x655390","include_decompile":true,"include_proto":true},{"addr":"0x6553a0","include_decompile":true,"include_proto":true},{"addr":"0x6553b0","include_decompile":true,"include_proto":true},{"addr":"0x6553c0","include_decompile":true,"include_proto":true},{"addr":"0x655610","include_decompile":true,"include_proto":true},{"addr":"0x655930","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0053', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0053: empty response'); return; }
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
      console.log('Batch 0053: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0053 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0053 conn error:', e.message));
req.write(body);
req.end();
