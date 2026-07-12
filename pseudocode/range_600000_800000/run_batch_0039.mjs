
import http from 'http';
import fs from 'fs';
const queries = [{"addr":"0x63fe90","include_decompile":true,"include_proto":true},{"addr":"0x63fea0","include_decompile":true,"include_proto":true},{"addr":"0x63feb0","include_decompile":true,"include_proto":true},{"addr":"0x63fec0","include_decompile":true,"include_proto":true},{"addr":"0x63fed0","include_decompile":true,"include_proto":true},{"addr":"0x63fee0","include_decompile":true,"include_proto":true},{"addr":"0x63ff00","include_decompile":true,"include_proto":true},{"addr":"0x63ff20","include_decompile":true,"include_proto":true},{"addr":"0x63ff30","include_decompile":true,"include_proto":true},{"addr":"0x63ff60","include_decompile":true,"include_proto":true},{"addr":"0x640100","include_decompile":true,"include_proto":true},{"addr":"0x640110","include_decompile":true,"include_proto":true},{"addr":"0x640120","include_decompile":true,"include_proto":true},{"addr":"0x640200","include_decompile":true,"include_proto":true},{"addr":"0x640210","include_decompile":true,"include_proto":true},{"addr":"0x640240","include_decompile":true,"include_proto":true},{"addr":"0x6402b0","include_decompile":true,"include_proto":true},{"addr":"0x640360","include_decompile":true,"include_proto":true},{"addr":"0x640370","include_decompile":true,"include_proto":true},{"addr":"0x640390","include_decompile":true,"include_proto":true},{"addr":"0x6403b0","include_decompile":true,"include_proto":true},{"addr":"0x6403c0","include_decompile":true,"include_proto":true},{"addr":"0x640560","include_decompile":true,"include_proto":true},{"addr":"0x640570","include_decompile":true,"include_proto":true},{"addr":"0x640590","include_decompile":true,"include_proto":true},{"addr":"0x640810","include_decompile":true,"include_proto":true},{"addr":"0x640f20","include_decompile":true,"include_proto":true},{"addr":"0x640f60","include_decompile":true,"include_proto":true},{"addr":"0x640f80","include_decompile":true,"include_proto":true},{"addr":"0x640fa0","include_decompile":true,"include_proto":true},{"addr":"0x640fb0","include_decompile":true,"include_proto":true},{"addr":"0x640fd0","include_decompile":true,"include_proto":true},{"addr":"0x641020","include_decompile":true,"include_proto":true},{"addr":"0x641210","include_decompile":true,"include_proto":true},{"addr":"0x641230","include_decompile":true,"include_proto":true},{"addr":"0x641250","include_decompile":true,"include_proto":true},{"addr":"0x641280","include_decompile":true,"include_proto":true},{"addr":"0x641290","include_decompile":true,"include_proto":true},{"addr":"0x6412b0","include_decompile":true,"include_proto":true},{"addr":"0x6412e0","include_decompile":true,"include_proto":true},{"addr":"0x641300","include_decompile":true,"include_proto":true},{"addr":"0x641310","include_decompile":true,"include_proto":true},{"addr":"0x641350","include_decompile":true,"include_proto":true},{"addr":"0x641360","include_decompile":true,"include_proto":true},{"addr":"0x641370","include_decompile":true,"include_proto":true},{"addr":"0x641380","include_decompile":true,"include_proto":true},{"addr":"0x641390","include_decompile":true,"include_proto":true},{"addr":"0x6413e0","include_decompile":true,"include_proto":true},{"addr":"0x641420","include_decompile":true,"include_proto":true},{"addr":"0x641430","include_decompile":true,"include_proto":true}];
const body = JSON.stringify({jsonrpc:'2.0', id:'b0039', method:'tools/call', params:{name:'analyze_batch', arguments:{queries}}});
const req = http.request({hostname:'127.0.0.1', port:52029, path:'/mcp', method:'POST', headers:{'Content-Type':'application/json'}}, res => {
  let data = '';
  res.on('data', chunk => data += chunk);
  res.on('end', () => {
    try {
      const parsed = JSON.parse(data);
      const text = parsed.result?.content?.[0]?.text;
      if (!text) { console.log('Batch 0039: empty response'); return; }
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
      console.log('Batch 0039: ' + count + '/' + results.length + ' saved');
    } catch(e) { console.log('Batch 0039 error:', e.message); }
  });
});
req.on('error', e => console.log('Batch 0039 conn error:', e.message));
req.write(body);
req.end();
