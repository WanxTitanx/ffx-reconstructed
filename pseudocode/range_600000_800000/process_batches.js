const fs = require('fs');
const path = require('path');
const http = require('http');

const OUT_DIR = __dirname;
const FUNC_LIST = path.join(OUT_DIR, 'filtered_funcs.json');
const INDEX_PATH = path.join(OUT_DIR, 'INDEX.md');
const MCP_PORT = 60000;

const ALL_FUNCS = JSON.parse(fs.readFileSync(FUNC_LIST, 'utf8'));
const BATCH_SIZE = 50;
let totalDone = 0;
let failed = [];
const errors = [];

function callMCP(queries) {
  return new Promise((resolve, reject) => {
    const data = JSON.stringify({
      jsonrpc: '2.0',
      id: Math.random().toString(36).slice(2),
      method: 'tools/call',
      params: {
        name: 'analyze_batch',
        arguments: { queries }
      }
    });
    const req = http.request({
      hostname: '127.0.0.1',
      port: MCP_PORT,
      path: '/mcp',
      method: 'POST',
      headers: { 'Content-Type': 'application/json' }
    }, res => {
      let body = '';
      res.on('data', chunk => body += chunk);
      res.on('end', () => {
        try {
          const parsed = JSON.parse(body);
          if (parsed.error) {
            reject(new Error(parsed.error.message));
          } else if (parsed.result && parsed.result.content) {
            const text = parsed.result.content.map(c => c.text).join('');
            resolve(JSON.parse(text));
          } else {
            resolve(null);
          }
        } catch (e) {
          reject(e);
        }
      });
    });
    req.on('error', reject);
    req.write(data);
    req.end();
  });
}

async function processBatch(funcs, batchIdx) {
  const queries = funcs.map(f => ({
    addr: f.addr,
    include_decompile: true,
    include_proto: true
  }));

  let results;
  try {
    results = await callMCP(queries);
  } catch (err) {
    for (const f of funcs) {
      failed.push(f);
      fs.writeFileSync(
        path.join(OUT_DIR, `${f.addr.replace('0x', '')}_${sanitizeName(f.name)}.c`),
        `// Function: ${f.name}\n// Address: ${f.addr}\n// Size: ${f.size}\n// ERROR: Failed to decompile - ${err.message}\n`
      );
    }
    return;
  }

  for (const r of results) {
    if (!r) continue;
    const addr = r.addr || '0x000000';
    const name = r.name || 'unknown';
    const analysis = r.analysis || {};
    const proto = analysis.prototype || '(void)';
    const decompile = analysis.decompile || null;
    const decompileError = analysis.decompile_error || null;
    const size = analysis.size || '0';

    let content = `// Function: ${name}\n// Address: ${addr}\n// Size: ${size}\n`;
    if (proto) content += `// Prototype: ${proto}\n`;
    content += '\n';

    if (decompile) {
      content += decompile;
      if (!decompile.endsWith('\n')) content += '\n';
    } else if (decompilerror) {
      content += `// DECOMPILE FAILED: ${decompileError}\n`;
    } else {
      content += `// No decompilation available\n`;
    }

    fs.writeFileSync(
      path.join(OUT_DIR, `${addr.replace('0x', '')}_${sanitizeName(name)}.c`),
      content
    );

    if (decompileError) {
      errors.push({ addr, name, error: decompileError });
    }
  }

  totalDone += funcs.length;
  const pct = ((totalDone / ALL_FUNCS.length) * 100).toFixed(1);
  process.stdout.write(`\rProgress: ${totalDone}/${ALL_FUNCS.length} (${pct}%) - Batch ${batchIdx}`);
}

function sanitizeName(name) {
  return name.replace(/[<>:"/\\|?*@&$!#(){}]/g, '_').replace(/__+/g, '_');
}

async function main() {
  // Create output if already exists
  console.log(`Starting batch processing of ${ALL_FUNCS.length} functions...\n`);

  for (let i = 0; i < ALL_FUNCS.length; i += BATCH_SIZE) {
    const batch = ALL_FUNCS.slice(i, Math.min(i + BATCH_SIZE, ALL_FUNCS.length));
    const batchIdx = Math.floor(i / BATCH_SIZE);
    await processBatch(batch, batchIdx);
    // Small delay to avoid overwhelming the server
    await new Promise(r => setTimeout(r, 50));
  }

  process.stdout.write('\n\n');

  // Write INDEX.md
  const total = ALL_FUNCS.length;
  const success = total - failed.length - errors.length;
  let index = `# Pseudocode Index: 0x600000 - 0x800000\n\n`;
  index += `- **Total functions:** ${total}\n`;
  index += `- **Decompiled:** ${success}\n`;
  index += `- **Failed:** ${failed.length}\n`;
  index += `- **Decompile errors:** ${errors.length}\n\n`;
  index += `## Function List\n\n`;
  index += `| Address | Name | Size | Prototype | Status |\n`;
  index += `|---------|------|------|-----------|--------|\n`;

  // We need to read the actual status from files
  for (const f of ALL_FUNCS) {
    const baseName = `${f.addr.replace('0x', '')}_${sanitizeName(f.name)}.c`;
    const filePath = path.join(OUT_DIR, baseName);
    let status = '✅';
    
    if (!fs.existsSync(filePath)) {
      status = '❌';
    } else {
      const content = fs.readFileSync(filePath, 'utf8');
      if (content.includes('DECOMPILE FAILED') || content.includes('Failed to decompile')) {
        status = '⚠️';
      } else if (content.includes('No decompilation')) {
        status = '⬜';
      }
    }

    index += `| ${f.addr} | ${f.name} | ${f.size} | | ${status} |\n`;
  }

  fs.writeFileSync(INDEX_PATH, index);
  console.log(`INDEX.md written with ${ALL_FUNCS.length} entries`);
  console.log(`Done! Processed ${totalDone} functions. Failed: ${failed.length}`);
}

main().catch(console.error);
