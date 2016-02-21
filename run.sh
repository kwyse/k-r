#!/bin/bash

command="gcc ${1}.c && ./a.out && rm ./a.out"
eval $command
