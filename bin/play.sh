#!/bin/bash

DEFAULT="-e 10"

#---------------------------------------------------

BUILD_T="-R"

args=""
for ARG in $( echo "${@}" | sed 's/ / /g' )
do
    args="${args} ${ARG}"
done

if [ "$1" = "-R" ] || [ "$1" = "--Release" ] ; then
    BUILD_T="-R"
    args=$(echo ${args} | cut -d'R' -f2-)
elif [ "$1" = "-D" ] || [ "$1" = "--Debug" ] ; then
    BUILD_T="-D"
    args=$(echo ${args} | cut -d'D' -f2-)
fi

./build.sh ${BUILD_T}
./compile.sh

if [[ ${#args} > 0 ]] ; then
    ./run.sh -m play ${args}
else
    ./run.sh -m play ${DEFAULT}
fi
