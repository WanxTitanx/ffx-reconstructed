
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x72eec0","include_decompile":true,"include_proto":true},{"addr":"0x72ef00","include_decompile":true,"include_proto":true},{"addr":"0x72ef30","include_decompile":true,"include_proto":true},{"addr":"0x72f4a0","include_decompile":true,"include_proto":true},{"addr":"0x72f500","include_decompile":true,"include_proto":true},{"addr":"0x72f590","include_decompile":true,"include_proto":true},{"addr":"0x72f760","include_decompile":true,"include_proto":true},{"addr":"0x72f930","include_decompile":true,"include_proto":true},{"addr":"0x72fb00","include_decompile":true,"include_proto":true},{"addr":"0x72fcd0","include_decompile":true,"include_proto":true},{"addr":"0x72feb0","include_decompile":true,"include_proto":true},{"addr":"0x730090","include_decompile":true,"include_proto":true},{"addr":"0x730260","include_decompile":true,"include_proto":true},{"addr":"0x730430","include_decompile":true,"include_proto":true},{"addr":"0x730610","include_decompile":true,"include_proto":true},{"addr":"0x7307f0","include_decompile":true,"include_proto":true},{"addr":"0x7309c0","include_decompile":true,"include_proto":true},{"addr":"0x730ba0","include_decompile":true,"include_proto":true},{"addr":"0x730dd0","include_decompile":true,"include_proto":true},{"addr":"0x730fd0","include_decompile":true,"include_proto":true},{"addr":"0x7311e0","include_decompile":true,"include_proto":true},{"addr":"0x731430","include_decompile":true,"include_proto":true},{"addr":"0x731640","include_decompile":true,"include_proto":true},{"addr":"0x731860","include_decompile":true,"include_proto":true},{"addr":"0x731ad0","include_decompile":true,"include_proto":true},{"addr":"0x731d30","include_decompile":true,"include_proto":true},{"addr":"0x731f90","include_decompile":true,"include_proto":true},{"addr":"0x732200","include_decompile":true,"include_proto":true},{"addr":"0x732460","include_decompile":true,"include_proto":true},{"addr":"0x7326c0","include_decompile":true,"include_proto":true},{"addr":"0x7327b0","include_decompile":true,"include_proto":true},{"addr":"0x732980","include_decompile":true,"include_proto":true},{"addr":"0x732a40","include_decompile":true,"include_proto":true},{"addr":"0x732c10","include_decompile":true,"include_proto":true},{"addr":"0x732cd0","include_decompile":true,"include_proto":true},{"addr":"0x732ea0","include_decompile":true,"include_proto":true},{"addr":"0x733000","include_decompile":true,"include_proto":true},{"addr":"0x7331b0","include_decompile":true,"include_proto":true},{"addr":"0x733300","include_decompile":true,"include_proto":true},{"addr":"0x7334b0","include_decompile":true,"include_proto":true},{"addr":"0x733600","include_decompile":true,"include_proto":true},{"addr":"0x7337b0","include_decompile":true,"include_proto":true},{"addr":"0x7338f0","include_decompile":true,"include_proto":true},{"addr":"0x733ad0","include_decompile":true,"include_proto":true},{"addr":"0x733c00","include_decompile":true,"include_proto":true},{"addr":"0x733de0","include_decompile":true,"include_proto":true},{"addr":"0x733f10","include_decompile":true,"include_proto":true},{"addr":"0x7340f0","include_decompile":true,"include_proto":true},{"addr":"0x7341c0","include_decompile":true,"include_proto":true},{"addr":"0x734200","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0134', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0134: empty response'); return; }
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
      console.log('Batch 0134: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0134 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0134 conn error:', e.message));
req.write(body);
req.end();
