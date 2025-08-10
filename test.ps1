param(
  [string]$Src = "src\valid_brackets.c",
  [string]$CaseDir = "tests\valid_brackets"
)

$srcPath  = Resolve-Path $Src
$casePath = Resolve-Path $CaseDir

gcc -O2 -Wall -Wextra -std=c11 $srcPath -o a.exe

$pass = 0; $fail = 0
Get-ChildItem -Path $casePath -Filter *.in | ForEach-Object {
  $infile  = $_.FullName
  $outfile = [System.IO.Path]::ChangeExtension($infile, "out")

  # 프로그램 출력 수집 (STDIN 파이프 → STDOUT 문자열)
  $got = (Get-Content -Raw -Encoding UTF8 $infile) | & .\a.exe | Out-String
  $exp = Get-Content -Raw -Encoding UTF8 $outfile

  # 줄끝/개행 정규화
  $got = $got -replace "\r\n", "`n"
  $exp = $exp -replace "\r\n", "`n"
  $got = $got.TrimEnd("`r","`n")
  $exp = $exp.TrimEnd("`r","`n")

  if ($got -ceq $exp) {
    Write-Host "[OK] $($_.Name)"
    $pass++
  } else {
    Write-Host "[NG] $($_.Name)"
    Write-Host " expected: <$exp>"
    Write-Host "      got: <$got>"
    $today = Get-Date -Format "yyyy-MM-dd"
    Add-Content notes\REGRESSION_LOG.md ("| {0} | {1} | C | 출력불일치 | 케이스:{2} | 재현: .\run.ps1 -Src {1} -In {3} |" -f $today, $Src, $_.Name, $infile)
    $fail++
  }
}

Write-Host "PASS:$pass FAIL:$fail"
exit $fail
