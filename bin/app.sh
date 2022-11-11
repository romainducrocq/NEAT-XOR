#!/bin/bash

./make.sh
./build.sh -R
./compile.sh
./run.sh -m train -g 300 -p 150 -l plt -s sav
./run.sh -m eval -s sav
