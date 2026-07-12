
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x707d80","include_decompile":true,"include_proto":true},{"addr":"0x707de0","include_decompile":true,"include_proto":true},{"addr":"0x707e00","include_decompile":true,"include_proto":true},{"addr":"0x707e60","include_decompile":true,"include_proto":true},{"addr":"0x707e90","include_decompile":true,"include_proto":true},{"addr":"0x707eb0","include_decompile":true,"include_proto":true},{"addr":"0x707ed0","include_decompile":true,"include_proto":true},{"addr":"0x707ee0","include_decompile":true,"include_proto":true},{"addr":"0x707ef0","include_decompile":true,"include_proto":true},{"addr":"0x707f00","include_decompile":true,"include_proto":true},{"addr":"0x707f10","include_decompile":true,"include_proto":true},{"addr":"0x707f30","include_decompile":true,"include_proto":true},{"addr":"0x707f50","include_decompile":true,"include_proto":true},{"addr":"0x707f70","include_decompile":true,"include_proto":true},{"addr":"0x707f90","include_decompile":true,"include_proto":true},{"addr":"0x707fa0","include_decompile":true,"include_proto":true},{"addr":"0x707fc0","include_decompile":true,"include_proto":true},{"addr":"0x707fe0","include_decompile":true,"include_proto":true},{"addr":"0x708000","include_decompile":true,"include_proto":true},{"addr":"0x708060","include_decompile":true,"include_proto":true},{"addr":"0x708080","include_decompile":true,"include_proto":true},{"addr":"0x7080a0","include_decompile":true,"include_proto":true},{"addr":"0x7080c0","include_decompile":true,"include_proto":true},{"addr":"0x7080e0","include_decompile":true,"include_proto":true},{"addr":"0x708140","include_decompile":true,"include_proto":true},{"addr":"0x708170","include_decompile":true,"include_proto":true},{"addr":"0x708190","include_decompile":true,"include_proto":true},{"addr":"0x7081b0","include_decompile":true,"include_proto":true},{"addr":"0x7081d0","include_decompile":true,"include_proto":true},{"addr":"0x7081f0","include_decompile":true,"include_proto":true},{"addr":"0x708210","include_decompile":true,"include_proto":true},{"addr":"0x708220","include_decompile":true,"include_proto":true},{"addr":"0x708230","include_decompile":true,"include_proto":true},{"addr":"0x708240","include_decompile":true,"include_proto":true},{"addr":"0x708250","include_decompile":true,"include_proto":true},{"addr":"0x708260","include_decompile":true,"include_proto":true},{"addr":"0x708280","include_decompile":true,"include_proto":true},{"addr":"0x7082a0","include_decompile":true,"include_proto":true},{"addr":"0x7082c0","include_decompile":true,"include_proto":true},{"addr":"0x7082d0","include_decompile":true,"include_proto":true},{"addr":"0x7082f0","include_decompile":true,"include_proto":true},{"addr":"0x708310","include_decompile":true,"include_proto":true},{"addr":"0x708330","include_decompile":true,"include_proto":true},{"addr":"0x708350","include_decompile":true,"include_proto":true},{"addr":"0x708370","include_decompile":true,"include_proto":true},{"addr":"0x7083a0","include_decompile":true,"include_proto":true},{"addr":"0x7083c0","include_decompile":true,"include_proto":true},{"addr":"0x7083e0","include_decompile":true,"include_proto":true},{"addr":"0x7083f0","include_decompile":true,"include_proto":true},{"addr":"0x708410","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0125', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0125: empty response'); return; }
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
      console.log('Batch 0125: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0125 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0125 conn error:', e.message));
req.write(body);
req.end();
