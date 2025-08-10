param(
  [string]$Src = "src\bfs_grid.c",
  [string]$CaseDir = "tests\bfs_grid"
)

gcc -O2 -Wall -Wextra -std=c11 $Src -o a.exe

$pass = 0; $fail = 0
Get-ChildItem "$CaseDir\*.in" | ForEach-Object {
  $infile = $_.FullName
  $outfile = $infile -replace '\.in$','.out'
  $got = Get-Content $infile | .\a.exe
  $exp = Get-Content $outfile
  if ($got -join "`n" -eq $exp -join "`n") {
    Write-Host "[OK] $($_.Name)"
    $pass++
  } else {
    Write-Host "[NG] $($_.Name)"
    Write-Host " expected: $($exp -join ' ')" 
    Write-Host "      got: $($got -join ' ')"
    # 실패 자동 기록
    $today = Get-Date -Format "yyyy-MM-dd"
    Add-Content notes\REGRESSION_LOG.md ("| {0} | {1} | C | 출력불일치 | 케이스:{2} | 재현: .\run.ps1 -Src {1} -In {3} |" -f $today, $Src, $_.Name, $infile)
    $fail++
  }
}

Write-Host "PASS:$pass FAIL:$fail"
exit $fail
