#!/bin/bash

function cleanup {
  if [[ -f a.out ]]; then rm ./a.out; fi
}
trap cleanup EXIT

if [[ $# -ne 2 ]]; then
  echo "Usage: run.sh <chapter> <exercise>"
  exit -1
fi

filename="$1-$2.c"
if [[ ! -f $filename ]]; then
  echo -e "Cannot find file $filename\nExiting..."
  exit -1
fi

gcc $filename
./a.out
