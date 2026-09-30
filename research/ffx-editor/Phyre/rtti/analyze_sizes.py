import json, collections, sys

with open(r"C:\Users\wande\Documents\ffx-editor-main\work\phyre_rtti\PHYRE_RTTI_CATALOG_20260731.json", encoding="utf-8-sig") as f:
    cat = json.load(f)

sizes = collections.Counter()
type_size = collections.defaultdict(collections.Counter)
off_size = collections.Counter()
examples = {}
total = 0
for cname, c in cat["classes"].items():
    for m in c["members"]:
        total += 1
        sz = m["size"]
        t = m["type_expr"].replace("Phyre_PType_Get", "").replace("()", "").strip()
        sizes[sz] += 1
        type_size[t][sz] += 1
        off_size[(m["offset"], sz)] += 1
        key = (t, sz)
        if key not in examples:
            examples[key] = (cname, m["name"], m["offset"], sz)

print(f"TOTAL members: {total}")
print("\nDistribuicao de arg6 (size no catalogo):")
for sz, n in sorted(sizes.items()):
    print(f"  arg6={sz}: {n}")

print("\nPor tipo_expr:")
for t, cnt in sorted(type_size.items()):
    print(f"  {t}: {dict(cnt)}")

print("\nExemplos (tipo, arg6) -> (classe, member, offset):")
for k, v in sorted(examples.items()):
    print(f"  {k}: {v}")
