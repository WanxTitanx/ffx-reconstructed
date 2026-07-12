
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x70ac80","include_decompile":true,"include_proto":true},{"addr":"0x70add0","include_decompile":true,"include_proto":true},{"addr":"0x70ade0","include_decompile":true,"include_proto":true},{"addr":"0x70aec0","include_decompile":true,"include_proto":true},{"addr":"0x70b1a0","include_decompile":true,"include_proto":true},{"addr":"0x70b250","include_decompile":true,"include_proto":true},{"addr":"0x70b3a0","include_decompile":true,"include_proto":true},{"addr":"0x70b420","include_decompile":true,"include_proto":true},{"addr":"0x70b460","include_decompile":true,"include_proto":true},{"addr":"0x70b4e0","include_decompile":true,"include_proto":true},{"addr":"0x70b520","include_decompile":true,"include_proto":true},{"addr":"0x70b570","include_decompile":true,"include_proto":true},{"addr":"0x70b660","include_decompile":true,"include_proto":true},{"addr":"0x70b6b0","include_decompile":true,"include_proto":true},{"addr":"0x70b7a0","include_decompile":true,"include_proto":true},{"addr":"0x70b840","include_decompile":true,"include_proto":true},{"addr":"0x70b8e0","include_decompile":true,"include_proto":true},{"addr":"0x70b970","include_decompile":true,"include_proto":true},{"addr":"0x70bb10","include_decompile":true,"include_proto":true},{"addr":"0x70bb60","include_decompile":true,"include_proto":true},{"addr":"0x70bc10","include_decompile":true,"include_proto":true},{"addr":"0x70bc90","include_decompile":true,"include_proto":true},{"addr":"0x70bd10","include_decompile":true,"include_proto":true},{"addr":"0x70bd30","include_decompile":true,"include_proto":true},{"addr":"0x70bd50","include_decompile":true,"include_proto":true},{"addr":"0x70bda0","include_decompile":true,"include_proto":true},{"addr":"0x70be00","include_decompile":true,"include_proto":true},{"addr":"0x70be70","include_decompile":true,"include_proto":true},{"addr":"0x70bee0","include_decompile":true,"include_proto":true},{"addr":"0x70bf50","include_decompile":true,"include_proto":true},{"addr":"0x70c030","include_decompile":true,"include_proto":true},{"addr":"0x70c080","include_decompile":true,"include_proto":true},{"addr":"0x70c0a0","include_decompile":true,"include_proto":true},{"addr":"0x70c2d0","include_decompile":true,"include_proto":true},{"addr":"0x70c330","include_decompile":true,"include_proto":true},{"addr":"0x70c390","include_decompile":true,"include_proto":true},{"addr":"0x70c410","include_decompile":true,"include_proto":true},{"addr":"0x70c420","include_decompile":true,"include_proto":true},{"addr":"0x70c4a0","include_decompile":true,"include_proto":true},{"addr":"0x70c540","include_decompile":true,"include_proto":true},{"addr":"0x70c560","include_decompile":true,"include_proto":true},{"addr":"0x70c570","include_decompile":true,"include_proto":true},{"addr":"0x70c580","include_decompile":true,"include_proto":true},{"addr":"0x70c6a0","include_decompile":true,"include_proto":true},{"addr":"0x70c730","include_decompile":true,"include_proto":true},{"addr":"0x70c740","include_decompile":true,"include_proto":true},{"addr":"0x70c840","include_decompile":true,"include_proto":true},{"addr":"0x70c8b0","include_decompile":true,"include_proto":true},{"addr":"0x70c920","include_decompile":true,"include_proto":true},{"addr":"0x70c930","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0127', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0127: empty response'); return; }
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
      console.log('Batch 0127: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0127 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0127 conn error:', e.message));
req.write(body);
req.end();
