const http = require('http');
const fs = require('fs');
const path = require('path');

const OUT = __dirname; // 'C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\pseudocode\\range_600000_800000'
const PORT = 58727;
const BATCH_SIZE = 50;

const funcs = JSON.parse(fs.readFileSync(path.join(OUT, 'filtered_funcs.json'), 'utf8'));
console.log('Processing', funcs.length, 'functions in batches of', BATCH_SIZE);

function callMCP(queries) {
  return new Promise((resolve, reject) => {
    const body = JSON.stringify({
      jsonrpc: '2.0', id: Math.random().toString(36).slice(2, 8),
      method: 'tools/call',
      params: { name: 'analyze_batch', arguments: { queries } }
    });
    const req = http.request({
      hostname: '127.0.0.1', port: PORT, path: '/mcp',
      method: 'POST', headers: { 'Content-Type': 'application/json' }
    }, res => {
      let data = '';
      res.on('data', chunk => data += chunk);
      res.on('end', () => {
        try {
          const parsed = JSON.parse(data);
          if (parsed.error) { reject(new Error(parsed.error.message)); return; }
          const text = parsed.result.content[0].text;
          resolve(JSON.parse(text));
        } catch (e) { reject(e); }
      });
    });
    req.on('error', reject);
    req.write(body);
    req.end();
  });
}

function sanitize(n) { return n.replace(/[<>:"\\\/|?*@&$!#(){}]/g,'_').replace(/__+/g,'_'); }

function saveResult(r) {
  const addr = r.addr || '0x0';
  const name = r.name || 'unknown';
  const analysis = r.analysis || {};
  const proto = analysis.prototype || '';
  const decompile = analysis.decompile || '';
  const decompileError = analysis.decompile_error || '';
  const size = analysis.size || '0';
  const sname = sanitize(name);
  let content = '// Function: ' + name + '\n// Address: ' + addr + '\n// Size: ' + size + '\n';
  if (proto) content += '// Prototype: ' + proto + '\n';
  content += '\n';
  if (decompile) { content += decompile; if (!decompile.endsWith('\n')) content += '\n'; }
  else if (decompileError) content += '// DECOMPILE FAILED: ' + decompileError + '\n';
  else content += '// No decompilation available\n';
  fs.writeFileSync(path.join(OUT, addr.replace('0x','') + '_' + sname + '.c'), content);
}

async function main() {
  let total = 0;
  let failed = 0;
  const totalFuncs = funcs.length;
  let lastPct = '';
  
  for (let i = 0; i < totalFuncs; i += BATCH_SIZE) {
    const batch = funcs.slice(i, Math.min(i + BATCH_SIZE, totalFuncs));
    const queries = batch.map(f => ({addr: f.addr, include_decompile: true, include_proto: true}));
    
    try {
      const results = await callMCP(queries);
      for (const r of results) saveResult(r);
      total += batch.length;
    } catch (err) {
      for (const f of batch) {
        const sname = sanitize(f.name);
        fs.writeFileSync(path.join(OUT, f.addr.replace('0x','') + '_' + sname + '.c'),
          '// Function: ' + f.name + '\n// Address: ' + f.addr + '\n// Size: ' + f.size + '\n\n// ERROR: ' + err.message + '\n');
      }
      failed += batch.length;
      total += batch.length;
    }
    
    const pct = ((total / totalFuncs) * 100).toFixed(1);
    if (pct !== lastPct) {
      process.stdout.write('\rProgress: ' + total + '/' + totalFuncs + ' (' + pct + '%)  Failed: ' + failed);
      lastPct = pct;
    }
    
    await new Promise(r => setTimeout(r, 30));
  }
  
  process.stdout.write('\n');
  console.log('Complete! Total:', total, 'Failed:', failed);
  
  // Write INDEX.md
  let index = '# Pseudocode Index: 0x600000 - 0x800000\n\n';
  index += '- **Total functions:** ' + funcs.length + '\n';
  index += '- **Failed:** ' + failed + '\n\n';
  index += '## Function List\n\n';
  index += '| # | Address | Name | Size | Status |\n';
  index += '|---|---------|------|------|--------|\n';
  
  for (let i = 0; i < funcs.length; i++) {
    const f = funcs[i];
    const baseName = f.addr.replace('0x','') + '_' + sanitize(f.name) + '.c';
    const filePath = path.join(OUT, baseName);
    let status = '';
    if (!fs.existsSync(filePath)) status = 'ERROR';
    else {
      const content = fs.readFileSync(filePath, 'utf8');
      if (content.includes('ERROR:') || content.includes('DECOMPILE FAILED')) status = 'ERROR';
      else if (content.includes('No decompilation')) status = 'EMPTY';
      else status = 'OK';
    }
    index += '| ' + (i+1) + ' | ' + f.addr + ' | ' + f.name + ' | ' + f.size + ' | ' + status + ' |\n';
  }
  
  fs.writeFileSync(path.join(OUT, 'INDEX.md'), index);
  console.log('INDEX.md written with ' + funcs.length + ' entries');
}

main().catch(err => { console.error('FATAL:', err.message); process.exit(1); });
