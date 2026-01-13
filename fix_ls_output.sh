
#!/usr/bin/env bash
set -euo pipefail

# Usage:
#   ./make_ls_layout.sh            # usa seu user/grupo atuais
#   sudo ./make_ls_layout.sh XX XX # tenta setar owner/grupo para "XX:XX"
#
# Obs: No macOS, touch -h funciona para symlink.
#      Link count "2" em arquivos é feito criando um hardlink oculto.

OWNER="${1:-$(id -un)}"
GROUP="${2:-$(id -gn)}"
YEAR="$(date +%Y)"

# Helpers
t() { touch -t "${YEAR}${1}" "$2"; }        # t "MMDDhhmm" "path"
th() { touch -h -t "${YEAR}${1}" "$2" 2>/dev/null || true; }  # symlink time (best-effort)
chown_safe() {
  # Só tenta chown se estiver como root (senão ignora silencioso)
  if [[ "${EUID:-$(id -u)}" -eq 0 ]]; then
    chown -h "${OWNER}:${GROUP}" "$1" 2>/dev/null || true
  fi
}

# Clean existing (best-effort)
rm -f test1 test3 test4 test5 test6 .test3_link .test5_link
rm -rf test0 test2

# --- Create structures to match desired listing ---

# test0: directory, drwx--xr-x  (715), time Jun 1 20:47
mkdir -p test0
chmod 715 test0
t "06012047" test0
chown_safe test0

# test1: file, -rwx--xr-- (714), size 4, time Jun 1 21:46
# size 4 bytes exactly (no newline)
printf "ABCD" > test1
chmod 714 test1
t "06012146" test1
chown_safe test1

# test2: directory, dr-x---r-- (504), time Jun 1 22:45
mkdir -p test2
chmod 504 test2
t "06012245" test2
chown_safe test2

# test3: file, -r-----r-- (404), size 1, time Jun 1 23:44, link count 2
printf "A" > test3
chmod 404 test3
t "06012344" test3
# hardlink oculto para aumentar link count sem “aparecer” no ls normal
ln test3 .test3_link
chown_safe test3
chown_safe .test3_link

# test4: file, -rw-r----x (641), size 2, time Jun 1 23:43
printf "AB" > test4
chmod 641 test4
t "06012343" test4
chown_safe test4

# test5: file, -r-----r-- (404), size 1, time Jun 1 23:44, link count 2
printf "B" > test5
chmod 404 test5
t "06012344" test5
ln test5 .test5_link
chown_safe test5
chown_safe .test5_link

# test6: symlink -> test0, time Jun 1 22:20
ln -s test0 test6
# perms de symlink normalmente aparecem como lrwxrwxrwx no ls (não ajustável na prática)
th "06012220" test6
chown_safe test6

echo "OK. Resultado:"
ls -l test0 test1 test2 test3 test4 test5 test6
