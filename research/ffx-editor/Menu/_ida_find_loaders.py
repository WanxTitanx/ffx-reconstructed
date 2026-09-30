import idautils, idc, ida_bytes, ida_name

targets = ["menu.clp", ".clp", ".fmt", ".sps2", "macrodic", "%smenu/%s", "menu_script", "help/%s"]
results = {}
for s in idautils.Strings():
    st = str(s)
    for t in targets:
        if t in st:
            results.setdefault(t, []).append((hex(s.ea), st))
            break

for t, hits in results.items():
    print("=== '%s' ===" % t)
    for ea, st in hits[:15]:
        print("  %s: %s" % (ea, st))
