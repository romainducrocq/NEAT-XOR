#!/bin/sh

args=""
for ARG in $( echo "${@}" | sed 's/ / /g' )
do
    args="${args} ${ARG}"
done

if [ "$1" = "-V" ] || [ "$1" = "--Verbose" ] ; then
    $(echo ${args} | cut -d' ' -f2-) > ../log/logs/out.txt
    cat ../log/logs/out.txt
else
    ${args} > ../log/logs/out.txt
    cat ../log/logs/out.txt | grep -e FATAL -e ERROR -e WARN -e INFO -e DEBUG -e TRACE
fi
