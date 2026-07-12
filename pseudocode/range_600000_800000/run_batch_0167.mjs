
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x788bf0","include_decompile":true,"include_proto":true},{"addr":"0x788c30","include_decompile":true,"include_proto":true},{"addr":"0x788c50","include_decompile":true,"include_proto":true},{"addr":"0x788c90","include_decompile":true,"include_proto":true},{"addr":"0x788ca0","include_decompile":true,"include_proto":true},{"addr":"0x788cc0","include_decompile":true,"include_proto":true},{"addr":"0x788d20","include_decompile":true,"include_proto":true},{"addr":"0x788dd0","include_decompile":true,"include_proto":true},{"addr":"0x788e20","include_decompile":true,"include_proto":true},{"addr":"0x788e90","include_decompile":true,"include_proto":true},{"addr":"0x788ea0","include_decompile":true,"include_proto":true},{"addr":"0x788eb0","include_decompile":true,"include_proto":true},{"addr":"0x788ed0","include_decompile":true,"include_proto":true},{"addr":"0x788ef0","include_decompile":true,"include_proto":true},{"addr":"0x788f20","include_decompile":true,"include_proto":true},{"addr":"0x788f50","include_decompile":true,"include_proto":true},{"addr":"0x788fb0","include_decompile":true,"include_proto":true},{"addr":"0x788ff0","include_decompile":true,"include_proto":true},{"addr":"0x789050","include_decompile":true,"include_proto":true},{"addr":"0x7890f0","include_decompile":true,"include_proto":true},{"addr":"0x789220","include_decompile":true,"include_proto":true},{"addr":"0x789270","include_decompile":true,"include_proto":true},{"addr":"0x7892a0","include_decompile":true,"include_proto":true},{"addr":"0x789350","include_decompile":true,"include_proto":true},{"addr":"0x7893a0","include_decompile":true,"include_proto":true},{"addr":"0x789670","include_decompile":true,"include_proto":true},{"addr":"0x789750","include_decompile":true,"include_proto":true},{"addr":"0x789800","include_decompile":true,"include_proto":true},{"addr":"0x789990","include_decompile":true,"include_proto":true},{"addr":"0x789cb0","include_decompile":true,"include_proto":true},{"addr":"0x78a2c0","include_decompile":true,"include_proto":true},{"addr":"0x78a300","include_decompile":true,"include_proto":true},{"addr":"0x78a420","include_decompile":true,"include_proto":true},{"addr":"0x78a840","include_decompile":true,"include_proto":true},{"addr":"0x78a890","include_decompile":true,"include_proto":true},{"addr":"0x78a8f0","include_decompile":true,"include_proto":true},{"addr":"0x78a950","include_decompile":true,"include_proto":true},{"addr":"0x78ab80","include_decompile":true,"include_proto":true},{"addr":"0x78abe0","include_decompile":true,"include_proto":true},{"addr":"0x78ace0","include_decompile":true,"include_proto":true},{"addr":"0x78ae00","include_decompile":true,"include_proto":true},{"addr":"0x78ae40","include_decompile":true,"include_proto":true},{"addr":"0x78ae80","include_decompile":true,"include_proto":true},{"addr":"0x78aec0","include_decompile":true,"include_proto":true},{"addr":"0x78b5a0","include_decompile":true,"include_proto":true},{"addr":"0x78b820","include_decompile":true,"include_proto":true},{"addr":"0x78b9e0","include_decompile":true,"include_proto":true},{"addr":"0x78baf0","include_decompile":true,"include_proto":true},{"addr":"0x78bb30","include_decompile":true,"include_proto":true},{"addr":"0x78be10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0167', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0167: empty response'); return; }
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
      console.log('Batch 0167: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0167 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0167 conn error:', e.message));
req.write(body);
req.end();
