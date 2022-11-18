#!/bin/bash

source utils.sh --source-specific assert get_default_args

echo -n "" > README.md

while IFS="" read -r LINE || [ -n "$LINE" ]
do
    TAG=false
    if [[ "${LINE}" == *"how_to_run"* ]] ; then 
        echo "${LINE}" >> README.md
        echo '```' >> README.md
        echo '$ ./build.sh -R' >> README.md
        echo '$ ./compile.sh' >> README.md
        echo '$ ./run.sh -m train '"$(get_default_args 'TRAIN')" >> README.md
        echo '$ ./run.sh -m eval '"$(get_default_args 'EVAL')" >> README.md
        echo '```' >> README.md
        TAG=true
    elif [[ "${LINE}" == *"how_to_train"* ]] ; then
        echo "${LINE}" >> README.md
        echo '```' >> README.md
        echo '* Debug   : $ ./train.sh -D '"$(get_default_args 'TRAIN')" >> README.md
        echo '* Release : $ ./train.sh -R '"$(get_default_args 'TRAIN')" >> README.md
        echo '```' >> README.md
        TAG=true
    elif [[ "${LINE}" == *"how_to_eval"* ]] ; then
        echo "${LINE}" >> README.md
        echo '```' >> README.md
        echo '* Debug   : $ ./eval.sh -D '"$(get_default_args 'EVAL')" >> README.md
        echo '* Release : $ ./eval.sh -R '"$(get_default_args 'EVAL')" >> README.md
        echo '```' >> README.md
        TAG=true
    elif [[ "${LINE}" == *"how_to_play"* ]] ; then
        echo "${LINE}" >> README.md
        echo '```' >> README.md
        echo '* Debug   : $ ./play.sh -D '"$(get_default_args 'PLAY')" >> README.md
        echo '* Release : $ ./play.sh -R '"$(get_default_args 'PLAY')" >> README.md
        echo '```' >> README.md
        TAG=true
    elif [[ "${LINE}" == *"how_to_test"* ]] ; then
        echo "${LINE}" >> README.md
        echo '```' >> README.md
        echo '* Debug   : $ ./test.sh -D '"$(get_default_args 'TEST')" >> README.md
        echo '* Release : $ ./test.sh -R '"$(get_default_args 'TEST')" >> README.md
        echo '```' >> README.md
        TAG=true
    fi

    if [ ${TAG} = true ] ; then
        for i in $(seq 1 $(echo "${LINE}" | cut -d'"' -f 4))
        do
            assert $(IFS="" read -r LINE)
        done
    else
        echo "${LINE}" >> README.md
    fi

done < ../README.md

mv README.md ..
