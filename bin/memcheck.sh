#!/bin/sh

# https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks

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
