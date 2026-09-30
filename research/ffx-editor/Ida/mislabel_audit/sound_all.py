import sys, json, re
funcs = json.load(open("work/_mislabel_audit/ffx_funcs_all.json"))
all_snd = [f for f in funcs if f["name"].startswith(("FFX_Sound","FFX_Fmod","FFX_Music","FFX_Spu","FFX_Se","FFX_Arai","FFX_Sfx","FFX_Stream","FFX_Voice"))]
print("soundish names total:", len(all_snd))
byband={}
for f in all_snd:
    a=int(f["addr"],16)
    b = f"{a>>16:04x}xxxx"
    byband.setdefault(b,[]).append(f)
for b in sorted(byband):
    print(f"  {b}: {len(byband[b])}")
