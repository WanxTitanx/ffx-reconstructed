
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6abf90","include_decompile":true,"include_proto":true},{"addr":"0x6ac000","include_decompile":true,"include_proto":true},{"addr":"0x6ac070","include_decompile":true,"include_proto":true},{"addr":"0x6ac080","include_decompile":true,"include_proto":true},{"addr":"0x6ac090","include_decompile":true,"include_proto":true},{"addr":"0x6ac0d0","include_decompile":true,"include_proto":true},{"addr":"0x6ac110","include_decompile":true,"include_proto":true},{"addr":"0x6ac200","include_decompile":true,"include_proto":true},{"addr":"0x6ac2a0","include_decompile":true,"include_proto":true},{"addr":"0x6ac2b0","include_decompile":true,"include_proto":true},{"addr":"0x6ac2c0","include_decompile":true,"include_proto":true},{"addr":"0x6ac2d0","include_decompile":true,"include_proto":true},{"addr":"0x6ac2e0","include_decompile":true,"include_proto":true},{"addr":"0x6ac2f0","include_decompile":true,"include_proto":true},{"addr":"0x6ac300","include_decompile":true,"include_proto":true},{"addr":"0x6ac4d0","include_decompile":true,"include_proto":true},{"addr":"0x6ac570","include_decompile":true,"include_proto":true},{"addr":"0x6ac5f0","include_decompile":true,"include_proto":true},{"addr":"0x6ac680","include_decompile":true,"include_proto":true},{"addr":"0x6aca50","include_decompile":true,"include_proto":true},{"addr":"0x6acb60","include_decompile":true,"include_proto":true},{"addr":"0x6acd20","include_decompile":true,"include_proto":true},{"addr":"0x6ace70","include_decompile":true,"include_proto":true},{"addr":"0x6ad1f0","include_decompile":true,"include_proto":true},{"addr":"0x6ad200","include_decompile":true,"include_proto":true},{"addr":"0x6ad220","include_decompile":true,"include_proto":true},{"addr":"0x6ad2d0","include_decompile":true,"include_proto":true},{"addr":"0x6ad3a0","include_decompile":true,"include_proto":true},{"addr":"0x6ad420","include_decompile":true,"include_proto":true},{"addr":"0x6ad4d0","include_decompile":true,"include_proto":true},{"addr":"0x6ad580","include_decompile":true,"include_proto":true},{"addr":"0x6ad630","include_decompile":true,"include_proto":true},{"addr":"0x6ad6e0","include_decompile":true,"include_proto":true},{"addr":"0x6ad750","include_decompile":true,"include_proto":true},{"addr":"0x6ad800","include_decompile":true,"include_proto":true},{"addr":"0x6ad8b0","include_decompile":true,"include_proto":true},{"addr":"0x6ad960","include_decompile":true,"include_proto":true},{"addr":"0x6ada10","include_decompile":true,"include_proto":true},{"addr":"0x6adac0","include_decompile":true,"include_proto":true},{"addr":"0x6adb70","include_decompile":true,"include_proto":true},{"addr":"0x6adc20","include_decompile":true,"include_proto":true},{"addr":"0x6adcd0","include_decompile":true,"include_proto":true},{"addr":"0x6add80","include_decompile":true,"include_proto":true},{"addr":"0x6adde0","include_decompile":true,"include_proto":true},{"addr":"0x6adee0","include_decompile":true,"include_proto":true},{"addr":"0x6adf70","include_decompile":true,"include_proto":true},{"addr":"0x6ae0c0","include_decompile":true,"include_proto":true},{"addr":"0x6ae210","include_decompile":true,"include_proto":true},{"addr":"0x6ae2f0","include_decompile":true,"include_proto":true},{"addr":"0x6ae390","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0090', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0090: empty response'); return; }
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
      console.log('Batch 0090: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0090 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0090 conn error:', e.message));
req.write(body);
req.end();
