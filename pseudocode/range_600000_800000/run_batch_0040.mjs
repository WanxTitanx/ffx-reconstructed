
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x641440","include_decompile":true,"include_proto":true},{"addr":"0x641450","include_decompile":true,"include_proto":true},{"addr":"0x641460","include_decompile":true,"include_proto":true},{"addr":"0x641480","include_decompile":true,"include_proto":true},{"addr":"0x6414a0","include_decompile":true,"include_proto":true},{"addr":"0x6414c0","include_decompile":true,"include_proto":true},{"addr":"0x6414d0","include_decompile":true,"include_proto":true},{"addr":"0x6414e0","include_decompile":true,"include_proto":true},{"addr":"0x641500","include_decompile":true,"include_proto":true},{"addr":"0x641510","include_decompile":true,"include_proto":true},{"addr":"0x641520","include_decompile":true,"include_proto":true},{"addr":"0x641540","include_decompile":true,"include_proto":true},{"addr":"0x641590","include_decompile":true,"include_proto":true},{"addr":"0x6415a0","include_decompile":true,"include_proto":true},{"addr":"0x6415b0","include_decompile":true,"include_proto":true},{"addr":"0x6415c0","include_decompile":true,"include_proto":true},{"addr":"0x6415d0","include_decompile":true,"include_proto":true},{"addr":"0x641640","include_decompile":true,"include_proto":true},{"addr":"0x6416a0","include_decompile":true,"include_proto":true},{"addr":"0x6416c0","include_decompile":true,"include_proto":true},{"addr":"0x641810","include_decompile":true,"include_proto":true},{"addr":"0x641820","include_decompile":true,"include_proto":true},{"addr":"0x641830","include_decompile":true,"include_proto":true},{"addr":"0x641840","include_decompile":true,"include_proto":true},{"addr":"0x641870","include_decompile":true,"include_proto":true},{"addr":"0x641b80","include_decompile":true,"include_proto":true},{"addr":"0x641d40","include_decompile":true,"include_proto":true},{"addr":"0x641d50","include_decompile":true,"include_proto":true},{"addr":"0x641d60","include_decompile":true,"include_proto":true},{"addr":"0x641d70","include_decompile":true,"include_proto":true},{"addr":"0x641d80","include_decompile":true,"include_proto":true},{"addr":"0x641da0","include_decompile":true,"include_proto":true},{"addr":"0x641db0","include_decompile":true,"include_proto":true},{"addr":"0x641dc0","include_decompile":true,"include_proto":true},{"addr":"0x641dd0","include_decompile":true,"include_proto":true},{"addr":"0x641df0","include_decompile":true,"include_proto":true},{"addr":"0x641e10","include_decompile":true,"include_proto":true},{"addr":"0x641e20","include_decompile":true,"include_proto":true},{"addr":"0x641e60","include_decompile":true,"include_proto":true},{"addr":"0x641e70","include_decompile":true,"include_proto":true},{"addr":"0x641e90","include_decompile":true,"include_proto":true},{"addr":"0x641ea0","include_decompile":true,"include_proto":true},{"addr":"0x641eb0","include_decompile":true,"include_proto":true},{"addr":"0x641f40","include_decompile":true,"include_proto":true},{"addr":"0x641f50","include_decompile":true,"include_proto":true},{"addr":"0x641f60","include_decompile":true,"include_proto":true},{"addr":"0x641fd0","include_decompile":true,"include_proto":true},{"addr":"0x641fe0","include_decompile":true,"include_proto":true},{"addr":"0x641ff0","include_decompile":true,"include_proto":true},{"addr":"0x642010","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0040', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0040: empty response'); return; }
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
      console.log('Batch 0040: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0040 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0040 conn error:', e.message));
req.write(body);
req.end();
