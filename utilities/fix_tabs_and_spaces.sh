#!/bin/bash
#usage: ./fix_tabs_and_spaces.sh file_name

sed -i $'s/\t/    /g' $1
sed -i 's/[ \t]*$//' $1
