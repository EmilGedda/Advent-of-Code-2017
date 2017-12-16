#!/bin/bash
set -e
inp="${1%%_*}"
OBJ="bin/$1"
make "../$OBJ" -C src
echo "./$OBJ < ./input/$inp.txt"
/usr/bin/time -p ./$OBJ < ./input/$inp.txt
