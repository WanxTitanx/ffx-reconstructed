#!/usr/bin/env bash
set -euo pipefail

# ── Cloud-backup readback gate ──
# This script only proves a fresh MEGA download against the local manifests;
# it intentionally never undefines a libvirt guest or unlinks a source disk.

stage_vm=/mnt/nvme-samsung/ffx-vm-archive-staging/2026-09-12/windows11-dev-legacy
stage_wsl=/mnt/nvme-samsung/ffx-wsl-archive-staging/2026-09-12/debian-bookworm-174
readback_root=/mnt/disco-velho/.ffx-vm-wsl-mega-readback-20260912
remote_root='/Spira Reforge Studio/Backups/FFX Editor'
remote_vm="$remote_root/Windows VMs/2026-09-12/windows11-dev-legacy"
remote_wsl="$remote_root/WSL/2026-09-12/debian-bookworm-174"
mega_root=/tmp/megacmd-portable-GI9ful/root

export PATH="$mega_root/usr/bin:$PATH"
export LD_LIBRARY_PATH="/opt/megasync/lib:$mega_root/usr/lib/x86_64-linux-gnu"

[[ -s "$stage_vm/SHA256SUMS" ]] || { echo 'VM manifest missing' >&2; exit 50; }
[[ -s "$stage_wsl/SHA256SUMS" ]] || { echo 'WSL manifest missing' >&2; exit 51; }
[[ ! -e "$readback_root" ]] || { echo 'Readback root already exists; inspect before reuse' >&2; exit 52; }
mkdir -p "$readback_root"

mega-get "$remote_vm" "$readback_root" | tee "$readback_root/vm-download.log"
mega-get "$remote_wsl" "$readback_root" | tee "$readback_root/wsl-download.log"

vm_readback="$readback_root/windows11-dev-legacy"
wsl_readback="$readback_root/debian-bookworm-174"
[[ -d "$vm_readback" && -d "$wsl_readback" ]] || { echo 'Remote folders did not materialise' >&2; exit 53; }

(cd "$vm_readback" && sha256sum -c SHA256SUMS) | tee "$readback_root/vm-sha256.log"
(cd "$wsl_readback" && sha256sum -c SHA256SUMS) | tee "$readback_root/wsl-sha256.log"
zstd -t "$vm_readback/windows11-dev-legacy.qcow2.zst" 2>&1 | tee "$readback_root/vm-zstd.log"
zstd -t "$wsl_readback/debian-bookworm-174-ext4.vhdx.zst" 2>&1 | tee "$readback_root/wsl-zstd.log"

grep -Fq 'windows11-dev-legacy.qcow2.zst: OK' "$readback_root/vm-sha256.log"
grep -Fq 'debian-bookworm-174-ext4.vhdx.zst: OK' "$readback_root/wsl-sha256.log"
printf 'REMOTE_READBACK_VERIFIED=YES\nVM_REMOTE=%s\nWSL_REMOTE=%s\nVM_MANIFEST_SHA256=%s\nWSL_MANIFEST_SHA256=%s\nVERIFIED_AT=%s\n' \
  "$remote_vm" "$remote_wsl" \
  "$(sha256sum "$stage_vm/SHA256SUMS" | cut -d' ' -f1)" \
  "$(sha256sum "$stage_wsl/SHA256SUMS" | cut -d' ' -f1)" \
  "$(date --iso-8601=seconds)" \
  | tee "$readback_root/REMOTE_READBACK_VERIFIED"

mega-put "$readback_root/REMOTE_READBACK_VERIFIED" "$remote_root/Windows VMs/2026-09-12"
