param(
  [string]$Src = "src\main.c",
  [string]$In = ""
)

# build
gcc -O2 -Wall -Wextra -std=c11 $Src -o a.exe

# run (입력파일 있으면 리다이렉트)
if ($In -ne "") {
  Get-Content $In | .\a.exe
} else {
  .\a.exe
}
