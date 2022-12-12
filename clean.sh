#!/bin/bash
 
# clean sub dir exec file
for file in $(ls ./); do
    if [  -d "./"$file ]; then
        cmd1="cd "$file
        cmd2="make clean"
        cmd3="cd .."
        ${cmd1}
        echo ${cmd1}
        ${cmd2}
        echo ${cmd2}
        ${cmd3}
        echo ${cmd3}
    fi
done