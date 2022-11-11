#!/bin/bash

./make.sh
./build.sh -R
./compile.sh
./run.sh -g 300 -p 150 -l plt -s sav
