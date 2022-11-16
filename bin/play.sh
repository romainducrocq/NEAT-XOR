#!/bin/bash

BUILD_T="-R"

if [ "$1" = "-R" ] || [ "$1" = "--Release" ] ; then
    BUILD_T="-R"
elif [ "$1" = "-D" ] || [ "$1" = "--Debug" ] ; then
    BUILD_T="-D"
fi

./build.sh ${BUILD_T}
./compile.sh
./run.sh -m play -e 10
