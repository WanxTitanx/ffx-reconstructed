
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x65e050","include_decompile":true,"include_proto":true},{"addr":"0x65e070","include_decompile":true,"include_proto":true},{"addr":"0x65e080","include_decompile":true,"include_proto":true},{"addr":"0x65e090","include_decompile":true,"include_proto":true},{"addr":"0x65e0d0","include_decompile":true,"include_proto":true},{"addr":"0x65e140","include_decompile":true,"include_proto":true},{"addr":"0x65e170","include_decompile":true,"include_proto":true},{"addr":"0x65e190","include_decompile":true,"include_proto":true},{"addr":"0x65e1a0","include_decompile":true,"include_proto":true},{"addr":"0x65e1b0","include_decompile":true,"include_proto":true},{"addr":"0x65e1d0","include_decompile":true,"include_proto":true},{"addr":"0x65e380","include_decompile":true,"include_proto":true},{"addr":"0x65e400","include_decompile":true,"include_proto":true},{"addr":"0x65e420","include_decompile":true,"include_proto":true},{"addr":"0x65e430","include_decompile":true,"include_proto":true},{"addr":"0x65e440","include_decompile":true,"include_proto":true},{"addr":"0x65e450","include_decompile":true,"include_proto":true},{"addr":"0x65e460","include_decompile":true,"include_proto":true},{"addr":"0x65e470","include_decompile":true,"include_proto":true},{"addr":"0x65e4a0","include_decompile":true,"include_proto":true},{"addr":"0x65e570","include_decompile":true,"include_proto":true},{"addr":"0x65e620","include_decompile":true,"include_proto":true},{"addr":"0x65e6e0","include_decompile":true,"include_proto":true},{"addr":"0x65e780","include_decompile":true,"include_proto":true},{"addr":"0x65e790","include_decompile":true,"include_proto":true},{"addr":"0x65e7a0","include_decompile":true,"include_proto":true},{"addr":"0x65e7b0","include_decompile":true,"include_proto":true},{"addr":"0x65e7c0","include_decompile":true,"include_proto":true},{"addr":"0x65e7d0","include_decompile":true,"include_proto":true},{"addr":"0x65e7e0","include_decompile":true,"include_proto":true},{"addr":"0x65eb60","include_decompile":true,"include_proto":true},{"addr":"0x65ec60","include_decompile":true,"include_proto":true},{"addr":"0x65ec70","include_decompile":true,"include_proto":true},{"addr":"0x65ece0","include_decompile":true,"include_proto":true},{"addr":"0x65ed50","include_decompile":true,"include_proto":true},{"addr":"0x65edc0","include_decompile":true,"include_proto":true},{"addr":"0x65ee30","include_decompile":true,"include_proto":true},{"addr":"0x65eea0","include_decompile":true,"include_proto":true},{"addr":"0x65ef00","include_decompile":true,"include_proto":true},{"addr":"0x65ef60","include_decompile":true,"include_proto":true},{"addr":"0x65efc0","include_decompile":true,"include_proto":true},{"addr":"0x65f120","include_decompile":true,"include_proto":true},{"addr":"0x65f150","include_decompile":true,"include_proto":true},{"addr":"0x65f1d0","include_decompile":true,"include_proto":true},{"addr":"0x65f260","include_decompile":true,"include_proto":true},{"addr":"0x65f360","include_decompile":true,"include_proto":true},{"addr":"0x65f370","include_decompile":true,"include_proto":true},{"addr":"0x65f410","include_decompile":true,"include_proto":true},{"addr":"0x65f5d0","include_decompile":true,"include_proto":true},{"addr":"0x65fc40","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0057', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0057: empty response'); return; }
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
      console.log('Batch 0057: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0057 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0057 conn error:', e.message));
req.write(body);
req.end();
