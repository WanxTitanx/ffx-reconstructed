
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7902f0","include_decompile":true,"include_proto":true},{"addr":"0x790320","include_decompile":true,"include_proto":true},{"addr":"0x790340","include_decompile":true,"include_proto":true},{"addr":"0x790390","include_decompile":true,"include_proto":true},{"addr":"0x790470","include_decompile":true,"include_proto":true},{"addr":"0x790480","include_decompile":true,"include_proto":true},{"addr":"0x7904f0","include_decompile":true,"include_proto":true},{"addr":"0x790500","include_decompile":true,"include_proto":true},{"addr":"0x790550","include_decompile":true,"include_proto":true},{"addr":"0x790560","include_decompile":true,"include_proto":true},{"addr":"0x790580","include_decompile":true,"include_proto":true},{"addr":"0x7905a0","include_decompile":true,"include_proto":true},{"addr":"0x7906c0","include_decompile":true,"include_proto":true},{"addr":"0x7906f0","include_decompile":true,"include_proto":true},{"addr":"0x7907e0","include_decompile":true,"include_proto":true},{"addr":"0x7907f0","include_decompile":true,"include_proto":true},{"addr":"0x790850","include_decompile":true,"include_proto":true},{"addr":"0x790890","include_decompile":true,"include_proto":true},{"addr":"0x7908b0","include_decompile":true,"include_proto":true},{"addr":"0x7908f0","include_decompile":true,"include_proto":true},{"addr":"0x790910","include_decompile":true,"include_proto":true},{"addr":"0x790980","include_decompile":true,"include_proto":true},{"addr":"0x7909c0","include_decompile":true,"include_proto":true},{"addr":"0x7909e0","include_decompile":true,"include_proto":true},{"addr":"0x790a10","include_decompile":true,"include_proto":true},{"addr":"0x790a40","include_decompile":true,"include_proto":true},{"addr":"0x790a60","include_decompile":true,"include_proto":true},{"addr":"0x790aa0","include_decompile":true,"include_proto":true},{"addr":"0x790ac0","include_decompile":true,"include_proto":true},{"addr":"0x790ae0","include_decompile":true,"include_proto":true},{"addr":"0x790b00","include_decompile":true,"include_proto":true},{"addr":"0x790b40","include_decompile":true,"include_proto":true},{"addr":"0x790b60","include_decompile":true,"include_proto":true},{"addr":"0x790b70","include_decompile":true,"include_proto":true},{"addr":"0x790b80","include_decompile":true,"include_proto":true},{"addr":"0x790be0","include_decompile":true,"include_proto":true},{"addr":"0x790c30","include_decompile":true,"include_proto":true},{"addr":"0x790c60","include_decompile":true,"include_proto":true},{"addr":"0x791000","include_decompile":true,"include_proto":true},{"addr":"0x7911c0","include_decompile":true,"include_proto":true},{"addr":"0x7911e0","include_decompile":true,"include_proto":true},{"addr":"0x791230","include_decompile":true,"include_proto":true},{"addr":"0x791640","include_decompile":true,"include_proto":true},{"addr":"0x791680","include_decompile":true,"include_proto":true},{"addr":"0x7916e0","include_decompile":true,"include_proto":true},{"addr":"0x7917b0","include_decompile":true,"include_proto":true},{"addr":"0x7917d0","include_decompile":true,"include_proto":true},{"addr":"0x791820","include_decompile":true,"include_proto":true},{"addr":"0x791ff0","include_decompile":true,"include_proto":true},{"addr":"0x792170","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0170', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0170: empty response'); return; }
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
      console.log('Batch 0170: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0170 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0170 conn error:', e.message));
req.write(body);
req.end();
