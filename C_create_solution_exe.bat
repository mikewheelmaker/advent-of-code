@echo off
IF "%2" == "lssl" (
    IF "%3" == "lcrypto" (
        gcc "%1/functions.c" "%1/main.c" -%2 -%3 -o "%1/solution.exe"
    )
) ELSE (
    gcc "%1/functions.c" "%1/main.c" -o "%1/solution.exe"
)
cd %1
solution.exe
cd ..
del new_*.txt
cd ../..