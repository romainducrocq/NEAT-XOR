#!/bin/bash

./build.sh -R
./compile.sh
./run.sh -m train -g 300 -p plt -s sav
./run.sh -m eval -e 10 -s sav
