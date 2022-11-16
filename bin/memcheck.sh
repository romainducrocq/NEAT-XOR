#!/bin/sh

./build.sh -D
./compile.sh

args=""
for ARG in $( echo "${@}" | sed 's/ / /g' )
do
    args="${args} ${ARG}"
done

cd apps/
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=$(dirname $(dirname $(pwd)))/log/valgrind/out.txt \
         ./exec${args}

cat ../../log/valgrind/out.txt
