import http from 'http';
import fs from 'fs';
import path from 'path';

const __dirname = path.dirname(new URL(import.meta.url).pathname);
const PORT = 52029;
const BATCH = 50;
const OUT = 'C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\pseudocode\\range_600000_800000';

const funcs = JSON.parse(fs.readFileSync(path.join(OUT, 'filtered_funcs.json'), 'utf8'));

const SANITIZE_RE = /[<>:"\\\/|?*@&$!#(){}]/g;

function sanitize(n) {
  return n.replace(SANITIZE_RE, '_').replace(/__+/g, '_');
}

function callMCP(queries) {
  return new Promise((resolve, reject) => {
    const body = JSON.stringify({
      jsonrpc: '2.0',
      id: Math.random().toString(36).slice(2, 10),
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
          const text = parsed.result?.content?.[0]?.text;
          if (!text) { reject(new Error('No text in response')); return; }
          resolve(JSON.parse(text));
        } catch(e) { reject(e); }
      });
    });
    req.on('error', reject);
    req.write(body);
    req.end();
  });
}

async function main() {
  let total = 0;
  let totalFailed = 0;
  const totalFuncs = funcs.length;

  for (let i = 0; i < totalFuncs; i += BATCH) {
    const batch = funcs.slice(i, Math.min(i + BATCH, totalFuncs));
    const queries = batch.map(f => ({ addr: f.addr, include_decompile: true, include_proto: true }));

    try {
      const results = await callMCP(queries);
      let saved = 0;
      for (const r of results) {
        if (!r || !r.addr) continue;
        const addr = r.addr.replace('0x', '');
        const name = r.name || 'unknown';
        const sname = sanitize(name);
        const proto = r.analysis?.prototype || '';
        const size = r.analysis?.size || '0';
        let decomp = r.analysis?.decompile || '';
        
        let content = `// Function: ${name}\n// Address: ${r.addr}\n// Size: ${size}\n`;
        if (proto) content += `// Prototype: ${proto}\n`;
        content += '\n';
        if (decomp) { content += decomp; if (!decomp.endsWith('\n')) content += '\n'; }
        else { content += '// No decompilation available\n'; }
        
        const fpath = path.join(OUT, addr + '_' + sname + '.c');
        try {
          fs.writeFileSync(fpath, content);
          saved++;
        } catch(e) {
          console.log(`\nWrite error for ${addr}_${sname}.c: ${e.message}`);
        }
      }
      total += batch.length;
      if (saved !== batch.length) totalFailed += (batch.length - saved);
    } catch (err) {
      for (const f of batch) {
        const sname = sanitize(f.name);
        fs.writeFileSync(
          path.join(OUT, f.addr.replace('0x','') + '_' + sname + '.c'),
          `// Function: ${f.name}\n// Address: ${f.addr}\n// Size: ${f.size}\n\n// ERROR: ${err.message}\n`
        );
      }
      total += batch.length;
      totalFailed += batch.length;
    }

    const pct = ((total / totalFuncs) * 100).toFixed(1);
    process.stdout.write(`\rProgress: ${total}/${totalFuncs} (${pct}%)  Failed: ${totalFailed}`);
    
    // Brief pause
    await new Promise(r => setTimeout(r, 20));
  }

  process.stdout.write('\n');
  console.log(`Complete! Processed: ${total}, Failed: ${totalFailed}`);

  // Generate INDEX.md
  let index = `# Pseudocode Index: 0x600000 - 0x800000\n\n`;
  index += `- **Total functions:** ${funcs.length}\n`;
  index += `- **Failed:** ${totalFailed}\n\n`;
  index += `## Function List\n\n`;
  index += `| # | Address | Name | Size | Status |\n`;
  index += `|---|---------|------|------|--------|\n`;

  for (let i = 0; i < funcs.length; i++) {
    const f = funcs[i];
    const fname = f.addr.replace('0x','') + '_' + sanitize(f.name) + '.c';
    const fpath = path.join(OUT, fname);
    let status = '?';
    if (fs.existsSync(fpath)) {
      const content = fs.readFileSync(fpath, 'utf8');
      if (content.includes('ERROR:')) status = 'ERR';
      else if (content.includes('No decompilation')) status = 'EMP';
      else status = 'OK';
    } else {
      status = 'MISS';
    }
    index += `| ${i+1} | ${f.addr} | ${f.name} | ${f.size} | ${status} |\n`;
  }

  fs.writeFileSync(path.join(OUT, 'INDEX.md'), index);
  console.log('INDEX.md written with ' + funcs.length + ' entries');
}

main().catch(e => { console.error('\nFATAL:', e.message); process.exit(1); });
