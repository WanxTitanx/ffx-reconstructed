const fs = require('fs');
const path = require('path');

const OUT = 'C:\\Users\\wande\\Documents\\ffx-editor-main\\ffx_reconstructed\\pseudocode\\range_600000_800000';
const funcs = JSON.parse(fs.readFileSync(path.join(OUT, 'filtered_funcs.json'), 'utf8'));
const S = /[<>:"\\\/|?*@&$!#(){}]/g;

function sanitize(n) { return n.replace(S, '_').replace(/__+/g, '_'); }

// Count existing files
let existing = 0;
let withDecompile = 0;
let withError = 0;

// Create missing placeholder files and generate INDEX
let idx = 0;
for (const f of funcs) {
  const fname = f.addr.replace('0x', '') + '_' + sanitize(f.name) + '.c';
  const fp = path.join(OUT, fname);
  
  if (fs.existsSync(fp)) {
    existing++;
    const content = fs.readFileSync(fp, 'utf8');
    if (content.includes('// ERROR:')) withError++;
    else if (content.includes('// Function:')) withDecompile++;
  } else {
    // Create placeholder with metadata
    const content = `// Function: ${f.name}\n// Address: ${f.addr}\n// Size: ${f.size}\n// Status: NOT EXTRACTED - decompile in a future session\n`;
    fs.writeFileSync(fp, content);
  }
  idx++;
}

console.log(`Existing files: ${existing}`);
console.log(`With decompilation: ${withDecompile}`);
console.log(`With errors: ${withError}`);
console.log(`Created placeholders: ${funcs.length - existing}`);

// Generate INDEX.md
let index = `# Pseudocode Index: 0x600000 - 0x800000\n\n`;
index += `- **Total functions:** ${funcs.length}\n`;
index += `- **Extracted:** ${withDecompile}\n`;
index += `- **Not extracted (placeholder):** ${funcs.length - existing}\n\n`;

index += `## Function List\n\n`;
index += `| # | Address | Name | Size | Status |\n`;
index += `|---|---------|------|------|--------|\n`;

for (let i = 0; i < funcs.length; i++) {
  const f = funcs[i];
  const fname = f.addr.replace('0x', '') + '_' + sanitize(f.name) + '.c';
  const fp = path.join(OUT, fname);
  let status = 'PLACEHOLDER';
  if (fs.existsSync(fp)) {
    const c = fs.readFileSync(fp, 'utf8');
    if (c.includes('// ERROR:')) status = 'ERROR';
    else if (c.includes('NOT EXTRACTED')) status = 'PLACEHOLDER';
    else if (c.includes('decompile')) status = 'EXTRACTED';
    else status = 'PARTIAL';
  }
  index += `| ${i+1} | ${f.addr} | ${f.name} | ${f.size} | ${status} |\n`;
}

fs.writeFileSync(path.join(OUT, 'INDEX.md'), index);
console.log('INDEX.md written with ' + funcs.length + ' entries');
