
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x6388d0","include_decompile":true,"include_proto":true},{"addr":"0x638930","include_decompile":true,"include_proto":true},{"addr":"0x6389f0","include_decompile":true,"include_proto":true},{"addr":"0x638a60","include_decompile":true,"include_proto":true},{"addr":"0x638a70","include_decompile":true,"include_proto":true},{"addr":"0x638b70","include_decompile":true,"include_proto":true},{"addr":"0x638b80","include_decompile":true,"include_proto":true},{"addr":"0x638b90","include_decompile":true,"include_proto":true},{"addr":"0x638ba0","include_decompile":true,"include_proto":true},{"addr":"0x638bb0","include_decompile":true,"include_proto":true},{"addr":"0x638c50","include_decompile":true,"include_proto":true},{"addr":"0x638ed0","include_decompile":true,"include_proto":true},{"addr":"0x638ef0","include_decompile":true,"include_proto":true},{"addr":"0x638f40","include_decompile":true,"include_proto":true},{"addr":"0x638f60","include_decompile":true,"include_proto":true},{"addr":"0x638f70","include_decompile":true,"include_proto":true},{"addr":"0x638f80","include_decompile":true,"include_proto":true},{"addr":"0x638f90","include_decompile":true,"include_proto":true},{"addr":"0x638fa0","include_decompile":true,"include_proto":true},{"addr":"0x638fb0","include_decompile":true,"include_proto":true},{"addr":"0x638fc0","include_decompile":true,"include_proto":true},{"addr":"0x638fd0","include_decompile":true,"include_proto":true},{"addr":"0x638fe0","include_decompile":true,"include_proto":true},{"addr":"0x639010","include_decompile":true,"include_proto":true},{"addr":"0x639020","include_decompile":true,"include_proto":true},{"addr":"0x639040","include_decompile":true,"include_proto":true},{"addr":"0x6390e0","include_decompile":true,"include_proto":true},{"addr":"0x639110","include_decompile":true,"include_proto":true},{"addr":"0x639140","include_decompile":true,"include_proto":true},{"addr":"0x639160","include_decompile":true,"include_proto":true},{"addr":"0x639180","include_decompile":true,"include_proto":true},{"addr":"0x639270","include_decompile":true,"include_proto":true},{"addr":"0x639280","include_decompile":true,"include_proto":true},{"addr":"0x6392a0","include_decompile":true,"include_proto":true},{"addr":"0x6392c0","include_decompile":true,"include_proto":true},{"addr":"0x6392e0","include_decompile":true,"include_proto":true},{"addr":"0x6392f0","include_decompile":true,"include_proto":true},{"addr":"0x639300","include_decompile":true,"include_proto":true},{"addr":"0x639320","include_decompile":true,"include_proto":true},{"addr":"0x6393f0","include_decompile":true,"include_proto":true},{"addr":"0x639430","include_decompile":true,"include_proto":true},{"addr":"0x639470","include_decompile":true,"include_proto":true},{"addr":"0x6394b0","include_decompile":true,"include_proto":true},{"addr":"0x6394c0","include_decompile":true,"include_proto":true},{"addr":"0x6394e0","include_decompile":true,"include_proto":true},{"addr":"0x639500","include_decompile":true,"include_proto":true},{"addr":"0x639510","include_decompile":true,"include_proto":true},{"addr":"0x639520","include_decompile":true,"include_proto":true},{"addr":"0x639530","include_decompile":true,"include_proto":true},{"addr":"0x639540","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0036', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0036: empty response'); return; }
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
      console.log('Batch 0036: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0036 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0036 conn error:', e.message));
req.write(body);
req.end();
