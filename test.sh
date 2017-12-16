#!/bin/zsh
set -e
OBJ="bin/$1"
make "../$OBJ" -C src
echo "./$OBJ < ./input/$1.txt"
/usr/bin/time -p ./$OBJ < ./input/$1.txt
