#!/bin/bash

./build.sh -R
./compile.sh
./run.sh -m eval -e 10 -t 0 -n 0 -s sav
