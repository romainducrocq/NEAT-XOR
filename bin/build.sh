#!/bin/sh

BUILD_T="Debug"

if [ "$1" = "-R" ] || [ "$1" = "--Release" ] ; then
    BUILD_T="Release"
elif [ "$1" = "-D" ] || [ "$1" = "--Debug" ] ; then
    BUILD_T="Debug"
fi

cmake -G "Unix Makefiles" -S ../build/ -B ../build/out/ -DCMAKE_BUILD_TYPE=${BUILD_T}
