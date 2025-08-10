#!/usr/bin/env bash
set -e

# 예시: BFS 테스트 자동화
PROG="src/queue/bfs_grid.c"
gcc -O2 -Wall -Wextra -std=c11 "$PROG" -Iinclude -o build_bfs

pass=0; fail=0
for infile in tests/bfs_grid/*.in; do
  outfile="${infile%.in}.out"
  got=$(./build_bfs < "$infile")
  exp=$(cat "$outfile")
  if [ "$got" = "$exp" ]; then
    echo "[OK] $infile"
    pass=$((pass+1))
  else
    echo "[NG] $infile"
    echo " expected: $exp"
    echo "      got: $got"
    fail=$((fail+1))
    # 실패를 notes/REGRESSION_LOG.md에 자동 기록(간단 버전)
    printf "| %(%Y-%m-%d)T | bfs_grid | C | 출력불일치 | 케이스:%s | 재현:%s |\n" -1 "$(basename "$infile")" "make run SRC=$PROG IN=$infile" >> notes/REGRESSION_LOG.md
  fi
done

echo "PASS:$pass FAIL:$fail"
exit $fail
