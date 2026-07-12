
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x7997a0","include_decompile":true,"include_proto":true},{"addr":"0x799830","include_decompile":true,"include_proto":true},{"addr":"0x799920","include_decompile":true,"include_proto":true},{"addr":"0x799a20","include_decompile":true,"include_proto":true},{"addr":"0x799ac0","include_decompile":true,"include_proto":true},{"addr":"0x799ad0","include_decompile":true,"include_proto":true},{"addr":"0x799b50","include_decompile":true,"include_proto":true},{"addr":"0x799ce0","include_decompile":true,"include_proto":true},{"addr":"0x799d60","include_decompile":true,"include_proto":true},{"addr":"0x799ed0","include_decompile":true,"include_proto":true},{"addr":"0x799ef0","include_decompile":true,"include_proto":true},{"addr":"0x799f10","include_decompile":true,"include_proto":true},{"addr":"0x799f30","include_decompile":true,"include_proto":true},{"addr":"0x799f80","include_decompile":true,"include_proto":true},{"addr":"0x799fc0","include_decompile":true,"include_proto":true},{"addr":"0x79a010","include_decompile":true,"include_proto":true},{"addr":"0x79a030","include_decompile":true,"include_proto":true},{"addr":"0x79a090","include_decompile":true,"include_proto":true},{"addr":"0x79a0d0","include_decompile":true,"include_proto":true},{"addr":"0x79a0f0","include_decompile":true,"include_proto":true},{"addr":"0x79a180","include_decompile":true,"include_proto":true},{"addr":"0x79a1a0","include_decompile":true,"include_proto":true},{"addr":"0x79a210","include_decompile":true,"include_proto":true},{"addr":"0x79a450","include_decompile":true,"include_proto":true},{"addr":"0x79a4c0","include_decompile":true,"include_proto":true},{"addr":"0x79a5c0","include_decompile":true,"include_proto":true},{"addr":"0x79a690","include_decompile":true,"include_proto":true},{"addr":"0x79a770","include_decompile":true,"include_proto":true},{"addr":"0x79a870","include_decompile":true,"include_proto":true},{"addr":"0x79a930","include_decompile":true,"include_proto":true},{"addr":"0x79aa60","include_decompile":true,"include_proto":true},{"addr":"0x79ad20","include_decompile":true,"include_proto":true},{"addr":"0x79ad40","include_decompile":true,"include_proto":true},{"addr":"0x79ada0","include_decompile":true,"include_proto":true},{"addr":"0x79adc0","include_decompile":true,"include_proto":true},{"addr":"0x79ade0","include_decompile":true,"include_proto":true},{"addr":"0x79ae00","include_decompile":true,"include_proto":true},{"addr":"0x79ae20","include_decompile":true,"include_proto":true},{"addr":"0x79ae40","include_decompile":true,"include_proto":true},{"addr":"0x79ae60","include_decompile":true,"include_proto":true},{"addr":"0x79ae80","include_decompile":true,"include_proto":true},{"addr":"0x79aea0","include_decompile":true,"include_proto":true},{"addr":"0x79aee0","include_decompile":true,"include_proto":true},{"addr":"0x79af00","include_decompile":true,"include_proto":true},{"addr":"0x79af20","include_decompile":true,"include_proto":true},{"addr":"0x79af40","include_decompile":true,"include_proto":true},{"addr":"0x79af50","include_decompile":true,"include_proto":true},{"addr":"0x79af70","include_decompile":true,"include_proto":true},{"addr":"0x79afd0","include_decompile":true,"include_proto":true},{"addr":"0x79b000","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0175', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0175: empty response'); return; }
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
      console.log('Batch 0175: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0175 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0175 conn error:', e.message));
req.write(body);
req.end();
