
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x78df40","include_decompile":true,"include_proto":true},{"addr":"0x78df70","include_decompile":true,"include_proto":true},{"addr":"0x78df90","include_decompile":true,"include_proto":true},{"addr":"0x78e160","include_decompile":true,"include_proto":true},{"addr":"0x78e1b0","include_decompile":true,"include_proto":true},{"addr":"0x78e210","include_decompile":true,"include_proto":true},{"addr":"0x78e2a0","include_decompile":true,"include_proto":true},{"addr":"0x78e2f0","include_decompile":true,"include_proto":true},{"addr":"0x78e400","include_decompile":true,"include_proto":true},{"addr":"0x78e460","include_decompile":true,"include_proto":true},{"addr":"0x78e4b0","include_decompile":true,"include_proto":true},{"addr":"0x78e5f0","include_decompile":true,"include_proto":true},{"addr":"0x78e670","include_decompile":true,"include_proto":true},{"addr":"0x78e680","include_decompile":true,"include_proto":true},{"addr":"0x78eed0","include_decompile":true,"include_proto":true},{"addr":"0x78ef40","include_decompile":true,"include_proto":true},{"addr":"0x78f050","include_decompile":true,"include_proto":true},{"addr":"0x78f090","include_decompile":true,"include_proto":true},{"addr":"0x78f0b0","include_decompile":true,"include_proto":true},{"addr":"0x78f6f0","include_decompile":true,"include_proto":true},{"addr":"0x78f750","include_decompile":true,"include_proto":true},{"addr":"0x78f810","include_decompile":true,"include_proto":true},{"addr":"0x78f940","include_decompile":true,"include_proto":true},{"addr":"0x78f960","include_decompile":true,"include_proto":true},{"addr":"0x78f980","include_decompile":true,"include_proto":true},{"addr":"0x78f9a0","include_decompile":true,"include_proto":true},{"addr":"0x78f9c0","include_decompile":true,"include_proto":true},{"addr":"0x78f9e0","include_decompile":true,"include_proto":true},{"addr":"0x78fa30","include_decompile":true,"include_proto":true},{"addr":"0x78fa80","include_decompile":true,"include_proto":true},{"addr":"0x78fad0","include_decompile":true,"include_proto":true},{"addr":"0x78faf0","include_decompile":true,"include_proto":true},{"addr":"0x78fb10","include_decompile":true,"include_proto":true},{"addr":"0x78fb30","include_decompile":true,"include_proto":true},{"addr":"0x78fb50","include_decompile":true,"include_proto":true},{"addr":"0x78fbb0","include_decompile":true,"include_proto":true},{"addr":"0x78fbd0","include_decompile":true,"include_proto":true},{"addr":"0x78fc00","include_decompile":true,"include_proto":true},{"addr":"0x78fd40","include_decompile":true,"include_proto":true},{"addr":"0x78fe90","include_decompile":true,"include_proto":true},{"addr":"0x78feb0","include_decompile":true,"include_proto":true},{"addr":"0x78fed0","include_decompile":true,"include_proto":true},{"addr":"0x78fef0","include_decompile":true,"include_proto":true},{"addr":"0x78ff20","include_decompile":true,"include_proto":true},{"addr":"0x78ff40","include_decompile":true,"include_proto":true},{"addr":"0x790250","include_decompile":true,"include_proto":true},{"addr":"0x790270","include_decompile":true,"include_proto":true},{"addr":"0x790290","include_decompile":true,"include_proto":true},{"addr":"0x7902b0","include_decompile":true,"include_proto":true},{"addr":"0x7902e0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0169', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0169: empty response'); return; }
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
      console.log('Batch 0169: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0169 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0169 conn error:', e.message));
req.write(body);
req.end();
