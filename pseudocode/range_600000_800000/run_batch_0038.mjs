
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x63c6c0","include_decompile":true,"include_proto":true},{"addr":"0x63c700","include_decompile":true,"include_proto":true},{"addr":"0x63cba0","include_decompile":true,"include_proto":true},{"addr":"0x63cc10","include_decompile":true,"include_proto":true},{"addr":"0x63ccc0","include_decompile":true,"include_proto":true},{"addr":"0x63cd10","include_decompile":true,"include_proto":true},{"addr":"0x63cd40","include_decompile":true,"include_proto":true},{"addr":"0x63cee0","include_decompile":true,"include_proto":true},{"addr":"0x63cf90","include_decompile":true,"include_proto":true},{"addr":"0x63d080","include_decompile":true,"include_proto":true},{"addr":"0x63d200","include_decompile":true,"include_proto":true},{"addr":"0x63d2f0","include_decompile":true,"include_proto":true},{"addr":"0x63d410","include_decompile":true,"include_proto":true},{"addr":"0x63d520","include_decompile":true,"include_proto":true},{"addr":"0x63d5b0","include_decompile":true,"include_proto":true},{"addr":"0x63d700","include_decompile":true,"include_proto":true},{"addr":"0x63d8c0","include_decompile":true,"include_proto":true},{"addr":"0x63d9c0","include_decompile":true,"include_proto":true},{"addr":"0x63da20","include_decompile":true,"include_proto":true},{"addr":"0x63da30","include_decompile":true,"include_proto":true},{"addr":"0x63da90","include_decompile":true,"include_proto":true},{"addr":"0x63daf0","include_decompile":true,"include_proto":true},{"addr":"0x63db50","include_decompile":true,"include_proto":true},{"addr":"0x63db60","include_decompile":true,"include_proto":true},{"addr":"0x63db70","include_decompile":true,"include_proto":true},{"addr":"0x63dc20","include_decompile":true,"include_proto":true},{"addr":"0x63dc30","include_decompile":true,"include_proto":true},{"addr":"0x63dc60","include_decompile":true,"include_proto":true},{"addr":"0x63dc70","include_decompile":true,"include_proto":true},{"addr":"0x63dc80","include_decompile":true,"include_proto":true},{"addr":"0x63df70","include_decompile":true,"include_proto":true},{"addr":"0x63dff0","include_decompile":true,"include_proto":true},{"addr":"0x63e0e0","include_decompile":true,"include_proto":true},{"addr":"0x63e100","include_decompile":true,"include_proto":true},{"addr":"0x63e110","include_decompile":true,"include_proto":true},{"addr":"0x63e120","include_decompile":true,"include_proto":true},{"addr":"0x63ead0","include_decompile":true,"include_proto":true},{"addr":"0x63eae0","include_decompile":true,"include_proto":true},{"addr":"0x63f090","include_decompile":true,"include_proto":true},{"addr":"0x63fdc0","include_decompile":true,"include_proto":true},{"addr":"0x63fde0","include_decompile":true,"include_proto":true},{"addr":"0x63fdf0","include_decompile":true,"include_proto":true},{"addr":"0x63fe00","include_decompile":true,"include_proto":true},{"addr":"0x63fe20","include_decompile":true,"include_proto":true},{"addr":"0x63fe30","include_decompile":true,"include_proto":true},{"addr":"0x63fe40","include_decompile":true,"include_proto":true},{"addr":"0x63fe50","include_decompile":true,"include_proto":true},{"addr":"0x63fe60","include_decompile":true,"include_proto":true},{"addr":"0x63fe70","include_decompile":true,"include_proto":true},{"addr":"0x63fe80","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0038', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0038: empty response'); return; }
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
      console.log('Batch 0038: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0038 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0038 conn error:', e.message));
req.write(body);
req.end();
