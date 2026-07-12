
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7c6d20","include_decompile":true,"include_proto":true},{"addr":"0x7c6d30","include_decompile":true,"include_proto":true},{"addr":"0x7c6d60","include_decompile":true,"include_proto":true},{"addr":"0x7c6d90","include_decompile":true,"include_proto":true},{"addr":"0x7c8620","include_decompile":true,"include_proto":true},{"addr":"0x7c8630","include_decompile":true,"include_proto":true},{"addr":"0x7c8640","include_decompile":true,"include_proto":true},{"addr":"0x7c8650","include_decompile":true,"include_proto":true},{"addr":"0x7c88a0","include_decompile":true,"include_proto":true},{"addr":"0x7c88c0","include_decompile":true,"include_proto":true},{"addr":"0x7c8910","include_decompile":true,"include_proto":true},{"addr":"0x7c89f0","include_decompile":true,"include_proto":true},{"addr":"0x7c8a50","include_decompile":true,"include_proto":true},{"addr":"0x7c8a60","include_decompile":true,"include_proto":true},{"addr":"0x7c8a70","include_decompile":true,"include_proto":true},{"addr":"0x7c8ac0","include_decompile":true,"include_proto":true},{"addr":"0x7c8b20","include_decompile":true,"include_proto":true},{"addr":"0x7c8b80","include_decompile":true,"include_proto":true},{"addr":"0x7c9020","include_decompile":true,"include_proto":true},{"addr":"0x7c9140","include_decompile":true,"include_proto":true},{"addr":"0x7c9300","include_decompile":true,"include_proto":true},{"addr":"0x7c9380","include_decompile":true,"include_proto":true},{"addr":"0x7c9af0","include_decompile":true,"include_proto":true},{"addr":"0x7c9bd0","include_decompile":true,"include_proto":true},{"addr":"0x7ca3d0","include_decompile":true,"include_proto":true},{"addr":"0x7ca4b0","include_decompile":true,"include_proto":true},{"addr":"0x7cb570","include_decompile":true,"include_proto":true},{"addr":"0x7cc120","include_decompile":true,"include_proto":true},{"addr":"0x7cc180","include_decompile":true,"include_proto":true},{"addr":"0x7cc350","include_decompile":true,"include_proto":true},{"addr":"0x7cd020","include_decompile":true,"include_proto":true},{"addr":"0x7cd0a0","include_decompile":true,"include_proto":true},{"addr":"0x7cd290","include_decompile":true,"include_proto":true},{"addr":"0x7cd350","include_decompile":true,"include_proto":true},{"addr":"0x7cd410","include_decompile":true,"include_proto":true},{"addr":"0x7cd4d0","include_decompile":true,"include_proto":true},{"addr":"0x7cd5b0","include_decompile":true,"include_proto":true},{"addr":"0x7cd680","include_decompile":true,"include_proto":true},{"addr":"0x7cd730","include_decompile":true,"include_proto":true},{"addr":"0x7ce380","include_decompile":true,"include_proto":true},{"addr":"0x7ce840","include_decompile":true,"include_proto":true},{"addr":"0x7ce920","include_decompile":true,"include_proto":true},{"addr":"0x7cede0","include_decompile":true,"include_proto":true},{"addr":"0x7ceee0","include_decompile":true,"include_proto":true},{"addr":"0x7cf070","include_decompile":true,"include_proto":true},{"addr":"0x7cf0b0","include_decompile":true,"include_proto":true},{"addr":"0x7cf190","include_decompile":true,"include_proto":true},{"addr":"0x7cf260","include_decompile":true,"include_proto":true},{"addr":"0x7cf2b0","include_decompile":true,"include_proto":true},{"addr":"0x7cf340","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0196', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0196: empty response'); return; }
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
      console.log('Batch 0196: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0196 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0196 conn error:', e.message));
req.write(body);
req.end();
