
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x765ae0","include_decompile":true,"include_proto":true},{"addr":"0x765af0","include_decompile":true,"include_proto":true},{"addr":"0x765b00","include_decompile":true,"include_proto":true},{"addr":"0x766000","include_decompile":true,"include_proto":true},{"addr":"0x766070","include_decompile":true,"include_proto":true},{"addr":"0x7666b0","include_decompile":true,"include_proto":true},{"addr":"0x766860","include_decompile":true,"include_proto":true},{"addr":"0x766ab0","include_decompile":true,"include_proto":true},{"addr":"0x766bd0","include_decompile":true,"include_proto":true},{"addr":"0x766c70","include_decompile":true,"include_proto":true},{"addr":"0x766c80","include_decompile":true,"include_proto":true},{"addr":"0x767000","include_decompile":true,"include_proto":true},{"addr":"0x767060","include_decompile":true,"include_proto":true},{"addr":"0x7670d0","include_decompile":true,"include_proto":true},{"addr":"0x767610","include_decompile":true,"include_proto":true},{"addr":"0x7677a0","include_decompile":true,"include_proto":true},{"addr":"0x767800","include_decompile":true,"include_proto":true},{"addr":"0x767870","include_decompile":true,"include_proto":true},{"addr":"0x768e40","include_decompile":true,"include_proto":true},{"addr":"0x769340","include_decompile":true,"include_proto":true},{"addr":"0x769450","include_decompile":true,"include_proto":true},{"addr":"0x7697a0","include_decompile":true,"include_proto":true},{"addr":"0x7697d0","include_decompile":true,"include_proto":true},{"addr":"0x769db0","include_decompile":true,"include_proto":true},{"addr":"0x769de0","include_decompile":true,"include_proto":true},{"addr":"0x769e80","include_decompile":true,"include_proto":true},{"addr":"0x76a280","include_decompile":true,"include_proto":true},{"addr":"0x76a2b0","include_decompile":true,"include_proto":true},{"addr":"0x76a300","include_decompile":true,"include_proto":true},{"addr":"0x76a750","include_decompile":true,"include_proto":true},{"addr":"0x76a780","include_decompile":true,"include_proto":true},{"addr":"0x76a7a0","include_decompile":true,"include_proto":true},{"addr":"0x76acf0","include_decompile":true,"include_proto":true},{"addr":"0x76ada0","include_decompile":true,"include_proto":true},{"addr":"0x76adc0","include_decompile":true,"include_proto":true},{"addr":"0x76ade0","include_decompile":true,"include_proto":true},{"addr":"0x76ae00","include_decompile":true,"include_proto":true},{"addr":"0x76ae20","include_decompile":true,"include_proto":true},{"addr":"0x76b140","include_decompile":true,"include_proto":true},{"addr":"0x76b200","include_decompile":true,"include_proto":true},{"addr":"0x76b230","include_decompile":true,"include_proto":true},{"addr":"0x76b2f0","include_decompile":true,"include_proto":true},{"addr":"0x76b310","include_decompile":true,"include_proto":true},{"addr":"0x76b320","include_decompile":true,"include_proto":true},{"addr":"0x76b3e0","include_decompile":true,"include_proto":true},{"addr":"0x76b4e0","include_decompile":true,"include_proto":true},{"addr":"0x76b5b0","include_decompile":true,"include_proto":true},{"addr":"0x76b600","include_decompile":true,"include_proto":true},{"addr":"0x76b7e0","include_decompile":true,"include_proto":true},{"addr":"0x76b800","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0146', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0146: empty response'); return; }
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
      console.log('Batch 0146: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0146 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0146 conn error:', e.message));
req.write(body);
req.end();
