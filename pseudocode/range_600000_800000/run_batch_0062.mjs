
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x670cc0","include_decompile":true,"include_proto":true},{"addr":"0x671040","include_decompile":true,"include_proto":true},{"addr":"0x6710a0","include_decompile":true,"include_proto":true},{"addr":"0x671180","include_decompile":true,"include_proto":true},{"addr":"0x671240","include_decompile":true,"include_proto":true},{"addr":"0x671280","include_decompile":true,"include_proto":true},{"addr":"0x6712c0","include_decompile":true,"include_proto":true},{"addr":"0x6712e0","include_decompile":true,"include_proto":true},{"addr":"0x671320","include_decompile":true,"include_proto":true},{"addr":"0x671360","include_decompile":true,"include_proto":true},{"addr":"0x6713a0","include_decompile":true,"include_proto":true},{"addr":"0x6713e0","include_decompile":true,"include_proto":true},{"addr":"0x671420","include_decompile":true,"include_proto":true},{"addr":"0x6714a0","include_decompile":true,"include_proto":true},{"addr":"0x671f40","include_decompile":true,"include_proto":true},{"addr":"0x6721a0","include_decompile":true,"include_proto":true},{"addr":"0x672210","include_decompile":true,"include_proto":true},{"addr":"0x672260","include_decompile":true,"include_proto":true},{"addr":"0x672350","include_decompile":true,"include_proto":true},{"addr":"0x6724d0","include_decompile":true,"include_proto":true},{"addr":"0x672520","include_decompile":true,"include_proto":true},{"addr":"0x6725c0","include_decompile":true,"include_proto":true},{"addr":"0x6726f0","include_decompile":true,"include_proto":true},{"addr":"0x6727d0","include_decompile":true,"include_proto":true},{"addr":"0x6727f0","include_decompile":true,"include_proto":true},{"addr":"0x672800","include_decompile":true,"include_proto":true},{"addr":"0x672820","include_decompile":true,"include_proto":true},{"addr":"0x672870","include_decompile":true,"include_proto":true},{"addr":"0x6728a0","include_decompile":true,"include_proto":true},{"addr":"0x6728d0","include_decompile":true,"include_proto":true},{"addr":"0x672900","include_decompile":true,"include_proto":true},{"addr":"0x672930","include_decompile":true,"include_proto":true},{"addr":"0x672950","include_decompile":true,"include_proto":true},{"addr":"0x672a30","include_decompile":true,"include_proto":true},{"addr":"0x672b10","include_decompile":true,"include_proto":true},{"addr":"0x672b20","include_decompile":true,"include_proto":true},{"addr":"0x672c50","include_decompile":true,"include_proto":true},{"addr":"0x672c70","include_decompile":true,"include_proto":true},{"addr":"0x672cd0","include_decompile":true,"include_proto":true},{"addr":"0x672cf0","include_decompile":true,"include_proto":true},{"addr":"0x672d20","include_decompile":true,"include_proto":true},{"addr":"0x6730c0","include_decompile":true,"include_proto":true},{"addr":"0x6730f0","include_decompile":true,"include_proto":true},{"addr":"0x673100","include_decompile":true,"include_proto":true},{"addr":"0x673110","include_decompile":true,"include_proto":true},{"addr":"0x673130","include_decompile":true,"include_proto":true},{"addr":"0x673140","include_decompile":true,"include_proto":true},{"addr":"0x673150","include_decompile":true,"include_proto":true},{"addr":"0x673170","include_decompile":true,"include_proto":true},{"addr":"0x6731d0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0062', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0062: empty response'); return; }
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
      console.log('Batch 0062: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0062 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0062 conn error:', e.message));
req.write(body);
req.end();
