
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x705ea0","include_decompile":true,"include_proto":true},{"addr":"0x705fc0","include_decompile":true,"include_proto":true},{"addr":"0x706090","include_decompile":true,"include_proto":true},{"addr":"0x706160","include_decompile":true,"include_proto":true},{"addr":"0x706230","include_decompile":true,"include_proto":true},{"addr":"0x7064e0","include_decompile":true,"include_proto":true},{"addr":"0x706580","include_decompile":true,"include_proto":true},{"addr":"0x706680","include_decompile":true,"include_proto":true},{"addr":"0x7067c0","include_decompile":true,"include_proto":true},{"addr":"0x706800","include_decompile":true,"include_proto":true},{"addr":"0x706820","include_decompile":true,"include_proto":true},{"addr":"0x7068a0","include_decompile":true,"include_proto":true},{"addr":"0x7068b0","include_decompile":true,"include_proto":true},{"addr":"0x7068d0","include_decompile":true,"include_proto":true},{"addr":"0x706910","include_decompile":true,"include_proto":true},{"addr":"0x706a10","include_decompile":true,"include_proto":true},{"addr":"0x706a50","include_decompile":true,"include_proto":true},{"addr":"0x706a60","include_decompile":true,"include_proto":true},{"addr":"0x706ad0","include_decompile":true,"include_proto":true},{"addr":"0x706ae0","include_decompile":true,"include_proto":true},{"addr":"0x706af0","include_decompile":true,"include_proto":true},{"addr":"0x706b10","include_decompile":true,"include_proto":true},{"addr":"0x706b30","include_decompile":true,"include_proto":true},{"addr":"0x706b50","include_decompile":true,"include_proto":true},{"addr":"0x706b60","include_decompile":true,"include_proto":true},{"addr":"0x706b70","include_decompile":true,"include_proto":true},{"addr":"0x706b90","include_decompile":true,"include_proto":true},{"addr":"0x706ba0","include_decompile":true,"include_proto":true},{"addr":"0x706bb0","include_decompile":true,"include_proto":true},{"addr":"0x706bc0","include_decompile":true,"include_proto":true},{"addr":"0x706bd0","include_decompile":true,"include_proto":true},{"addr":"0x706bf0","include_decompile":true,"include_proto":true},{"addr":"0x706c20","include_decompile":true,"include_proto":true},{"addr":"0x706c40","include_decompile":true,"include_proto":true},{"addr":"0x706c60","include_decompile":true,"include_proto":true},{"addr":"0x706c70","include_decompile":true,"include_proto":true},{"addr":"0x706c80","include_decompile":true,"include_proto":true},{"addr":"0x706c90","include_decompile":true,"include_proto":true},{"addr":"0x706ca0","include_decompile":true,"include_proto":true},{"addr":"0x706cb0","include_decompile":true,"include_proto":true},{"addr":"0x706ce0","include_decompile":true,"include_proto":true},{"addr":"0x706cf0","include_decompile":true,"include_proto":true},{"addr":"0x706d00","include_decompile":true,"include_proto":true},{"addr":"0x706d10","include_decompile":true,"include_proto":true},{"addr":"0x706d30","include_decompile":true,"include_proto":true},{"addr":"0x706d40","include_decompile":true,"include_proto":true},{"addr":"0x706ea0","include_decompile":true,"include_proto":true},{"addr":"0x706ec0","include_decompile":true,"include_proto":true},{"addr":"0x706ee0","include_decompile":true,"include_proto":true},{"addr":"0x706f10","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0123', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0123: empty response'); return; }
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
      console.log('Batch 0123: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0123 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0123 conn error:', e.message));
req.write(body);
req.end();
