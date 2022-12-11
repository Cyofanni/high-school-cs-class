#!/bin/bash

sed -i $'s/\t/    /g' $1
sed -i 's/[ \t]*$//' $1
