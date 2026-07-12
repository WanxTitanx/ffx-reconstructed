
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x708430","include_decompile":true,"include_proto":true},{"addr":"0x708450","include_decompile":true,"include_proto":true},{"addr":"0x708470","include_decompile":true,"include_proto":true},{"addr":"0x708490","include_decompile":true,"include_proto":true},{"addr":"0x7084b0","include_decompile":true,"include_proto":true},{"addr":"0x7084c0","include_decompile":true,"include_proto":true},{"addr":"0x7084f0","include_decompile":true,"include_proto":true},{"addr":"0x708520","include_decompile":true,"include_proto":true},{"addr":"0x708550","include_decompile":true,"include_proto":true},{"addr":"0x7085c0","include_decompile":true,"include_proto":true},{"addr":"0x708600","include_decompile":true,"include_proto":true},{"addr":"0x708690","include_decompile":true,"include_proto":true},{"addr":"0x7086d0","include_decompile":true,"include_proto":true},{"addr":"0x708700","include_decompile":true,"include_proto":true},{"addr":"0x708710","include_decompile":true,"include_proto":true},{"addr":"0x708720","include_decompile":true,"include_proto":true},{"addr":"0x7087a0","include_decompile":true,"include_proto":true},{"addr":"0x708810","include_decompile":true,"include_proto":true},{"addr":"0x708900","include_decompile":true,"include_proto":true},{"addr":"0x7089f0","include_decompile":true,"include_proto":true},{"addr":"0x708af0","include_decompile":true,"include_proto":true},{"addr":"0x708be0","include_decompile":true,"include_proto":true},{"addr":"0x708cd0","include_decompile":true,"include_proto":true},{"addr":"0x708cf0","include_decompile":true,"include_proto":true},{"addr":"0x708e20","include_decompile":true,"include_proto":true},{"addr":"0x708e30","include_decompile":true,"include_proto":true},{"addr":"0x708f40","include_decompile":true,"include_proto":true},{"addr":"0x7090f0","include_decompile":true,"include_proto":true},{"addr":"0x709170","include_decompile":true,"include_proto":true},{"addr":"0x7092a0","include_decompile":true,"include_proto":true},{"addr":"0x709360","include_decompile":true,"include_proto":true},{"addr":"0x7094d0","include_decompile":true,"include_proto":true},{"addr":"0x709610","include_decompile":true,"include_proto":true},{"addr":"0x709730","include_decompile":true,"include_proto":true},{"addr":"0x7097e0","include_decompile":true,"include_proto":true},{"addr":"0x709a90","include_decompile":true,"include_proto":true},{"addr":"0x709c00","include_decompile":true,"include_proto":true},{"addr":"0x709d70","include_decompile":true,"include_proto":true},{"addr":"0x709e70","include_decompile":true,"include_proto":true},{"addr":"0x709ec0","include_decompile":true,"include_proto":true},{"addr":"0x709fa0","include_decompile":true,"include_proto":true},{"addr":"0x70a010","include_decompile":true,"include_proto":true},{"addr":"0x70a0e0","include_decompile":true,"include_proto":true},{"addr":"0x70a230","include_decompile":true,"include_proto":true},{"addr":"0x70a290","include_decompile":true,"include_proto":true},{"addr":"0x70a420","include_decompile":true,"include_proto":true},{"addr":"0x70a590","include_decompile":true,"include_proto":true},{"addr":"0x70a680","include_decompile":true,"include_proto":true},{"addr":"0x70a720","include_decompile":true,"include_proto":true},{"addr":"0x70ab20","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0126', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0126: empty response'); return; }
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
      console.log('Batch 0126: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0126 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0126 conn error:', e.message));
req.write(body);
req.end();
