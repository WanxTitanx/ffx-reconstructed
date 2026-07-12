
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x771aa0","include_decompile":true,"include_proto":true},{"addr":"0x771ad0","include_decompile":true,"include_proto":true},{"addr":"0x771af0","include_decompile":true,"include_proto":true},{"addr":"0x771b20","include_decompile":true,"include_proto":true},{"addr":"0x771b40","include_decompile":true,"include_proto":true},{"addr":"0x771b70","include_decompile":true,"include_proto":true},{"addr":"0x771b90","include_decompile":true,"include_proto":true},{"addr":"0x771bc0","include_decompile":true,"include_proto":true},{"addr":"0x771be0","include_decompile":true,"include_proto":true},{"addr":"0x771c00","include_decompile":true,"include_proto":true},{"addr":"0x771c30","include_decompile":true,"include_proto":true},{"addr":"0x771c50","include_decompile":true,"include_proto":true},{"addr":"0x771c80","include_decompile":true,"include_proto":true},{"addr":"0x771ca0","include_decompile":true,"include_proto":true},{"addr":"0x771cd0","include_decompile":true,"include_proto":true},{"addr":"0x771cf0","include_decompile":true,"include_proto":true},{"addr":"0x771d20","include_decompile":true,"include_proto":true},{"addr":"0x771d40","include_decompile":true,"include_proto":true},{"addr":"0x771d70","include_decompile":true,"include_proto":true},{"addr":"0x771d90","include_decompile":true,"include_proto":true},{"addr":"0x771db0","include_decompile":true,"include_proto":true},{"addr":"0x771de0","include_decompile":true,"include_proto":true},{"addr":"0x771e00","include_decompile":true,"include_proto":true},{"addr":"0x771e30","include_decompile":true,"include_proto":true},{"addr":"0x771e50","include_decompile":true,"include_proto":true},{"addr":"0x771e80","include_decompile":true,"include_proto":true},{"addr":"0x771ea0","include_decompile":true,"include_proto":true},{"addr":"0x771ed0","include_decompile":true,"include_proto":true},{"addr":"0x771ef0","include_decompile":true,"include_proto":true},{"addr":"0x771f20","include_decompile":true,"include_proto":true},{"addr":"0x771f40","include_decompile":true,"include_proto":true},{"addr":"0x771f60","include_decompile":true,"include_proto":true},{"addr":"0x771f90","include_decompile":true,"include_proto":true},{"addr":"0x771fb0","include_decompile":true,"include_proto":true},{"addr":"0x771fe0","include_decompile":true,"include_proto":true},{"addr":"0x772000","include_decompile":true,"include_proto":true},{"addr":"0x772030","include_decompile":true,"include_proto":true},{"addr":"0x772050","include_decompile":true,"include_proto":true},{"addr":"0x772080","include_decompile":true,"include_proto":true},{"addr":"0x7720a0","include_decompile":true,"include_proto":true},{"addr":"0x7720d0","include_decompile":true,"include_proto":true},{"addr":"0x7720f0","include_decompile":true,"include_proto":true},{"addr":"0x772110","include_decompile":true,"include_proto":true},{"addr":"0x772140","include_decompile":true,"include_proto":true},{"addr":"0x772160","include_decompile":true,"include_proto":true},{"addr":"0x772190","include_decompile":true,"include_proto":true},{"addr":"0x7721b0","include_decompile":true,"include_proto":true},{"addr":"0x7721e0","include_decompile":true,"include_proto":true},{"addr":"0x772200","include_decompile":true,"include_proto":true},{"addr":"0x772230","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0152', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0152: empty response'); return; }
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
      console.log('Batch 0152: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0152 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0152 conn error:', e.message));
req.write(body);
req.end();
