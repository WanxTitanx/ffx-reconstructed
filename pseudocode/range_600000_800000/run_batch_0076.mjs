
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x68c670","include_decompile":true,"include_proto":true},{"addr":"0x68c680","include_decompile":true,"include_proto":true},{"addr":"0x68c890","include_decompile":true,"include_proto":true},{"addr":"0x68c8c0","include_decompile":true,"include_proto":true},{"addr":"0x68c8f0","include_decompile":true,"include_proto":true},{"addr":"0x68c900","include_decompile":true,"include_proto":true},{"addr":"0x68c910","include_decompile":true,"include_proto":true},{"addr":"0x68c920","include_decompile":true,"include_proto":true},{"addr":"0x68c9d0","include_decompile":true,"include_proto":true},{"addr":"0x68cb30","include_decompile":true,"include_proto":true},{"addr":"0x68cb40","include_decompile":true,"include_proto":true},{"addr":"0x68cb90","include_decompile":true,"include_proto":true},{"addr":"0x68cba0","include_decompile":true,"include_proto":true},{"addr":"0x68cbb0","include_decompile":true,"include_proto":true},{"addr":"0x68cbc0","include_decompile":true,"include_proto":true},{"addr":"0x68cbd0","include_decompile":true,"include_proto":true},{"addr":"0x68cbe0","include_decompile":true,"include_proto":true},{"addr":"0x68cc80","include_decompile":true,"include_proto":true},{"addr":"0x68cdb0","include_decompile":true,"include_proto":true},{"addr":"0x68ce70","include_decompile":true,"include_proto":true},{"addr":"0x68d0a0","include_decompile":true,"include_proto":true},{"addr":"0x68d0b0","include_decompile":true,"include_proto":true},{"addr":"0x68d0f0","include_decompile":true,"include_proto":true},{"addr":"0x68d100","include_decompile":true,"include_proto":true},{"addr":"0x68d280","include_decompile":true,"include_proto":true},{"addr":"0x68d400","include_decompile":true,"include_proto":true},{"addr":"0x68d470","include_decompile":true,"include_proto":true},{"addr":"0x68d4d0","include_decompile":true,"include_proto":true},{"addr":"0x68d750","include_decompile":true,"include_proto":true},{"addr":"0x68d770","include_decompile":true,"include_proto":true},{"addr":"0x68d790","include_decompile":true,"include_proto":true},{"addr":"0x68d7a0","include_decompile":true,"include_proto":true},{"addr":"0x68d8e0","include_decompile":true,"include_proto":true},{"addr":"0x68dac0","include_decompile":true,"include_proto":true},{"addr":"0x68dad0","include_decompile":true,"include_proto":true},{"addr":"0x68dae0","include_decompile":true,"include_proto":true},{"addr":"0x68daf0","include_decompile":true,"include_proto":true},{"addr":"0x68db00","include_decompile":true,"include_proto":true},{"addr":"0x68db90","include_decompile":true,"include_proto":true},{"addr":"0x68dc20","include_decompile":true,"include_proto":true},{"addr":"0x68dca0","include_decompile":true,"include_proto":true},{"addr":"0x68dd20","include_decompile":true,"include_proto":true},{"addr":"0x68ddb0","include_decompile":true,"include_proto":true},{"addr":"0x68ddc0","include_decompile":true,"include_proto":true},{"addr":"0x68dee0","include_decompile":true,"include_proto":true},{"addr":"0x68df20","include_decompile":true,"include_proto":true},{"addr":"0x68df70","include_decompile":true,"include_proto":true},{"addr":"0x68dff0","include_decompile":true,"include_proto":true},{"addr":"0x68e090","include_decompile":true,"include_proto":true},{"addr":"0x68e140","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0076', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0076: empty response'); return; }
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
      console.log('Batch 0076: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0076 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0076 conn error:', e.message));
req.write(body);
req.end();
