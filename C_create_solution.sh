#!/bin/bash
gcc "$1/functions.c" "$1/main.c" -o "$1/solution"
cd $1
./solution
cd ../../..