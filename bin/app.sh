#!/bin/bash

./build.sh -R
./compile.sh
./run.sh -m train -g 300 -t 0 -n 0 -p plt -s sav
./run.sh -m eval -e 10 -t 0 -n 0 -s sav
