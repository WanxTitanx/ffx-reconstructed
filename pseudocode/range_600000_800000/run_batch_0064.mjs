
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x674460","include_decompile":true,"include_proto":true},{"addr":"0x674470","include_decompile":true,"include_proto":true},{"addr":"0x674480","include_decompile":true,"include_proto":true},{"addr":"0x674490","include_decompile":true,"include_proto":true},{"addr":"0x6744a0","include_decompile":true,"include_proto":true},{"addr":"0x6744b0","include_decompile":true,"include_proto":true},{"addr":"0x6745e0","include_decompile":true,"include_proto":true},{"addr":"0x674600","include_decompile":true,"include_proto":true},{"addr":"0x674660","include_decompile":true,"include_proto":true},{"addr":"0x6746e0","include_decompile":true,"include_proto":true},{"addr":"0x674710","include_decompile":true,"include_proto":true},{"addr":"0x6747f0","include_decompile":true,"include_proto":true},{"addr":"0x674820","include_decompile":true,"include_proto":true},{"addr":"0x674830","include_decompile":true,"include_proto":true},{"addr":"0x674840","include_decompile":true,"include_proto":true},{"addr":"0x674860","include_decompile":true,"include_proto":true},{"addr":"0x674880","include_decompile":true,"include_proto":true},{"addr":"0x6748e0","include_decompile":true,"include_proto":true},{"addr":"0x674a40","include_decompile":true,"include_proto":true},{"addr":"0x674a80","include_decompile":true,"include_proto":true},{"addr":"0x674ab0","include_decompile":true,"include_proto":true},{"addr":"0x674b20","include_decompile":true,"include_proto":true},{"addr":"0x674b40","include_decompile":true,"include_proto":true},{"addr":"0x674b70","include_decompile":true,"include_proto":true},{"addr":"0x674ca0","include_decompile":true,"include_proto":true},{"addr":"0x674d90","include_decompile":true,"include_proto":true},{"addr":"0x674db0","include_decompile":true,"include_proto":true},{"addr":"0x674dd0","include_decompile":true,"include_proto":true},{"addr":"0x674de0","include_decompile":true,"include_proto":true},{"addr":"0x674df0","include_decompile":true,"include_proto":true},{"addr":"0x674e20","include_decompile":true,"include_proto":true},{"addr":"0x674e50","include_decompile":true,"include_proto":true},{"addr":"0x674e80","include_decompile":true,"include_proto":true},{"addr":"0x674eb0","include_decompile":true,"include_proto":true},{"addr":"0x674ed0","include_decompile":true,"include_proto":true},{"addr":"0x674f60","include_decompile":true,"include_proto":true},{"addr":"0x675040","include_decompile":true,"include_proto":true},{"addr":"0x675050","include_decompile":true,"include_proto":true},{"addr":"0x675180","include_decompile":true,"include_proto":true},{"addr":"0x6751a0","include_decompile":true,"include_proto":true},{"addr":"0x675220","include_decompile":true,"include_proto":true},{"addr":"0x675250","include_decompile":true,"include_proto":true},{"addr":"0x675260","include_decompile":true,"include_proto":true},{"addr":"0x675270","include_decompile":true,"include_proto":true},{"addr":"0x675290","include_decompile":true,"include_proto":true},{"addr":"0x6752a0","include_decompile":true,"include_proto":true},{"addr":"0x6752c0","include_decompile":true,"include_proto":true},{"addr":"0x6752d0","include_decompile":true,"include_proto":true},{"addr":"0x675340","include_decompile":true,"include_proto":true},{"addr":"0x675380","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0064', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0064: empty response'); return; }
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
      console.log('Batch 0064: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0064 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0064 conn error:', e.message));
req.write(body);
req.end();
