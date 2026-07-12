const fs = require('fs');
const path = require('path');

const OUT = 'C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\pseudocode\\range_600000_800000';
const funcs = JSON.parse(fs.readFileSync(path.join(OUT, 'filtered_funcs.json'), 'utf8'));
const S = /[<>:"\\\/|?*@&$!#(){}]/g;
function sanitize(n) { return n.replace(S, '_').replace(/__+/g, '_'); }

// Read the successful batch0 results
const batch0Results = JSON.parse(fs.readFileSync(path.join(OUT, 'batch0_full.json'), 'utf8')).result;

// Build a set of valid addresses
const validAddrs = new Set();
for (const r of batch0Results) {
  if (r && r.addr && r.analysis && r.analysis.decompile) {
    validAddrs.add(r.addr);
  }
}

console.log('Valid decompiled addresses from batch0:', validAddrs.size);

// Scan all files - keep valid ones, replace error/placeholder with proper placeholder
let extracted = 0;
let placeholder = 0;

for (const f of funcs) {
  const fname = f.addr.replace('0x', '') + '_' + sanitize(f.name) + '.c';
  const fp = path.join(OUT, fname);
  
  if (fs.existsSync(fp)) {
    const content = fs.readFileSync(fp, 'utf8');
    
    // Check if this is a valid decompilation
    if (validAddrs.has(f.addr) && content.includes('PhyreLua_PushPhyreObject')) {
      extracted++;
      continue; // Keep valid decompilation
    }
    
    // Check if content has actual decompiled code (not error/placeholder)
    if (content.includes('__stdcall') || content.includes('return ') || content.includes('int ')) {
      // Count lines - if it has more than just header + error, it might be valid
      const lines = content.split('\n').filter(l => l.trim() && !l.startsWith('//'));
      if (lines.length > 0) {
        extracted++;
        continue;
      }
    }
    
    // Replace with proper placeholder
    const placeholderContent = `// Function: ${f.name}\n// Address: ${f.addr}\n// Size: ${f.size}\n//\n// NOT EXTRACTED - This function was not decompiled.\n// To decompile it, run:\n//   idalib_decompile(db, "${f.addr}")\n`;
    fs.writeFileSync(fp, placeholderContent);
    placeholder++;
  }
}

console.log(`Extracted (valid): ${extracted}`);
console.log(`Placeholders: ${placeholder}`);
console.log(`Total: ${extracted + placeholder}`);

// Write final INDEX.md
let index = '# Pseudocode Index: 0x600000 - 0x800000\n\n';
index += `- **Total functions:** ${funcs.length}\n`;
index += `- **Extracted:** ${extracted}\n`;
index += `- **Not extracted:** ${placeholder}\n\n`;
index += '## Function List\n\n';
index += '| # | Address | Name | Size | Status |\n';
index += '|---|---------|------|------|--------|\n';

for (let i = 0; i < funcs.length; i++) {
  const f = funcs[i];
  const fname = f.addr.replace('0x', '') + '_' + sanitize(f.name) + '.c';
  const fp = path.join(OUT, fname);
  let status = '?';
  if (fs.existsSync(fp)) {
    const c = fs.readFileSync(fp, 'utf8');
    if (c.includes('NOT EXTRACTED')) status = 'MISS';
    else if (c.includes('__stdcall') || c.includes('return ')) status = 'OK';
    else status = 'PARTIAL';
  } else status = 'MISS';
  index += `| ${i+1} | ${f.addr} | ${f.name} | ${f.size} | ${status} |\n`;
}
fs.writeFileSync(path.join(OUT, 'INDEX.md'), index);
console.log('INDEX.md updated');
