#!/bin/bash

./build.sh -R
./compile.sh
./run.sh -m train -g 300 -c 0 -n 0 -p plt -s sav
