#!/bin/bash
if [ "$2" == "lssl" ]; then
    if [ "$3" == "lcrypto" ]; then
        gcc "$1/functions.c" "$1/main.c" -$2 -$3 -o "$1/solution"
    fi
else
    gcc "$1/functions.c" "$1/main.c" -o "$1/solution"
fi
cd $1
./solution
if [ "$1" == "2015/07/C" ]; then
    cd ..
    rm new_*.txt
    cd ../..
else
    cd ../../..
fi
