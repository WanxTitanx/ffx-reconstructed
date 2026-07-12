
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x639550","include_decompile":true,"include_proto":true},{"addr":"0x639570","include_decompile":true,"include_proto":true},{"addr":"0x639600","include_decompile":true,"include_proto":true},{"addr":"0x639620","include_decompile":true,"include_proto":true},{"addr":"0x639640","include_decompile":true,"include_proto":true},{"addr":"0x639650","include_decompile":true,"include_proto":true},{"addr":"0x639660","include_decompile":true,"include_proto":true},{"addr":"0x639690","include_decompile":true,"include_proto":true},{"addr":"0x6396b0","include_decompile":true,"include_proto":true},{"addr":"0x6396f0","include_decompile":true,"include_proto":true},{"addr":"0x639720","include_decompile":true,"include_proto":true},{"addr":"0x639740","include_decompile":true,"include_proto":true},{"addr":"0x639770","include_decompile":true,"include_proto":true},{"addr":"0x639790","include_decompile":true,"include_proto":true},{"addr":"0x639a10","include_decompile":true,"include_proto":true},{"addr":"0x639ce0","include_decompile":true,"include_proto":true},{"addr":"0x639ec0","include_decompile":true,"include_proto":true},{"addr":"0x639ed0","include_decompile":true,"include_proto":true},{"addr":"0x639ef0","include_decompile":true,"include_proto":true},{"addr":"0x639f10","include_decompile":true,"include_proto":true},{"addr":"0x639f40","include_decompile":true,"include_proto":true},{"addr":"0x639f70","include_decompile":true,"include_proto":true},{"addr":"0x63a1b0","include_decompile":true,"include_proto":true},{"addr":"0x63a1d0","include_decompile":true,"include_proto":true},{"addr":"0x63a1f0","include_decompile":true,"include_proto":true},{"addr":"0x63a320","include_decompile":true,"include_proto":true},{"addr":"0x63a470","include_decompile":true,"include_proto":true},{"addr":"0x63a5d0","include_decompile":true,"include_proto":true},{"addr":"0x63a7d0","include_decompile":true,"include_proto":true},{"addr":"0x63a9d0","include_decompile":true,"include_proto":true},{"addr":"0x63b370","include_decompile":true,"include_proto":true},{"addr":"0x63b3e0","include_decompile":true,"include_proto":true},{"addr":"0x63b3f0","include_decompile":true,"include_proto":true},{"addr":"0x63b450","include_decompile":true,"include_proto":true},{"addr":"0x63b790","include_decompile":true,"include_proto":true},{"addr":"0x63b900","include_decompile":true,"include_proto":true},{"addr":"0x63b990","include_decompile":true,"include_proto":true},{"addr":"0x63b9b0","include_decompile":true,"include_proto":true},{"addr":"0x63b9d0","include_decompile":true,"include_proto":true},{"addr":"0x63bba0","include_decompile":true,"include_proto":true},{"addr":"0x63bcf0","include_decompile":true,"include_proto":true},{"addr":"0x63be10","include_decompile":true,"include_proto":true},{"addr":"0x63be40","include_decompile":true,"include_proto":true},{"addr":"0x63bfb0","include_decompile":true,"include_proto":true},{"addr":"0x63c020","include_decompile":true,"include_proto":true},{"addr":"0x63c180","include_decompile":true,"include_proto":true},{"addr":"0x63c280","include_decompile":true,"include_proto":true},{"addr":"0x63c550","include_decompile":true,"include_proto":true},{"addr":"0x63c5a0","include_decompile":true,"include_proto":true},{"addr":"0x63c5f0","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0037', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0037: empty response'); return; }
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
      console.log('Batch 0037: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0037 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0037 conn error:', e.message));
req.write(body);
req.end();
