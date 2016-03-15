#!/bin/bash

function cleanup {
  if [[ -f a.out ]]; then rm ./a.out; fi
}
trap cleanup EXIT

if [[ $# -eq 2 ]]; then
  filename="$1-$2.c"
fi

if [[ $# -eq 3 ]]; then
  filename="$1-$2-$3.c"
fi

if [[ -z $filename ]]; then
  echo "Usage: run.sh <chapter> <exercise> [version]"
  exit -1
fi

if [[ ! -f $filename ]]; then
  echo -e "Cannot find file $filename\nExiting..."
  exit -1
fi

clang -Weverything -std=c11 -lm $filename
./a.out
