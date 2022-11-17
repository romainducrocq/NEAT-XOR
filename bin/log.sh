#!/bin/bash

source utils.sh --source-specific get_args

args=$(get_args " ${@}")

if [ "$1" = "-V" ] || [ "$1" = "--Verbose" ] ; then
    echo -n "" > ../log/logs/out.txt
    $(echo ${args} | cut -d'V' -f2-) 2>&1 | tee -a ../log/logs/out.txt
else
    ${args} > ../log/logs/out.txt
    cat ../log/logs/out.txt | grep -e FATAL -e ERROR -e WARN -e INFO -e DEBUG -e TRACE
fi
