
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x676310","include_decompile":true,"include_proto":true},{"addr":"0x6763f0","include_decompile":true,"include_proto":true},{"addr":"0x676400","include_decompile":true,"include_proto":true},{"addr":"0x676530","include_decompile":true,"include_proto":true},{"addr":"0x676550","include_decompile":true,"include_proto":true},{"addr":"0x6765b0","include_decompile":true,"include_proto":true},{"addr":"0x676630","include_decompile":true,"include_proto":true},{"addr":"0x676660","include_decompile":true,"include_proto":true},{"addr":"0x676740","include_decompile":true,"include_proto":true},{"addr":"0x676770","include_decompile":true,"include_proto":true},{"addr":"0x676780","include_decompile":true,"include_proto":true},{"addr":"0x676790","include_decompile":true,"include_proto":true},{"addr":"0x6767b0","include_decompile":true,"include_proto":true},{"addr":"0x6767d0","include_decompile":true,"include_proto":true},{"addr":"0x676830","include_decompile":true,"include_proto":true},{"addr":"0x676990","include_decompile":true,"include_proto":true},{"addr":"0x6769d0","include_decompile":true,"include_proto":true},{"addr":"0x676a00","include_decompile":true,"include_proto":true},{"addr":"0x676a70","include_decompile":true,"include_proto":true},{"addr":"0x676a90","include_decompile":true,"include_proto":true},{"addr":"0x676aa0","include_decompile":true,"include_proto":true},{"addr":"0x676ab0","include_decompile":true,"include_proto":true},{"addr":"0x676b00","include_decompile":true,"include_proto":true},{"addr":"0x676c30","include_decompile":true,"include_proto":true},{"addr":"0x676d20","include_decompile":true,"include_proto":true},{"addr":"0x676d40","include_decompile":true,"include_proto":true},{"addr":"0x676d60","include_decompile":true,"include_proto":true},{"addr":"0x676d70","include_decompile":true,"include_proto":true},{"addr":"0x676d80","include_decompile":true,"include_proto":true},{"addr":"0x676db0","include_decompile":true,"include_proto":true},{"addr":"0x676de0","include_decompile":true,"include_proto":true},{"addr":"0x676e10","include_decompile":true,"include_proto":true},{"addr":"0x676e40","include_decompile":true,"include_proto":true},{"addr":"0x676e60","include_decompile":true,"include_proto":true},{"addr":"0x676ee0","include_decompile":true,"include_proto":true},{"addr":"0x676fc0","include_decompile":true,"include_proto":true},{"addr":"0x676fd0","include_decompile":true,"include_proto":true},{"addr":"0x676fe0","include_decompile":true,"include_proto":true},{"addr":"0x676ff0","include_decompile":true,"include_proto":true},{"addr":"0x677000","include_decompile":true,"include_proto":true},{"addr":"0x677010","include_decompile":true,"include_proto":true},{"addr":"0x677140","include_decompile":true,"include_proto":true},{"addr":"0x677160","include_decompile":true,"include_proto":true},{"addr":"0x6771e0","include_decompile":true,"include_proto":true},{"addr":"0x677210","include_decompile":true,"include_proto":true},{"addr":"0x677220","include_decompile":true,"include_proto":true},{"addr":"0x677230","include_decompile":true,"include_proto":true},{"addr":"0x677240","include_decompile":true,"include_proto":true},{"addr":"0x677260","include_decompile":true,"include_proto":true},{"addr":"0x677270","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0066', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0066: empty response'); return; }
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
      console.log('Batch 0066: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0066 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0066 conn error:', e.message));
req.write(body);
req.end();
