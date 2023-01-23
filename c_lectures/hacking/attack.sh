#!/bin/bash
param_offset=-128
while [ $param_offset -le 128 ]
do
  echo $param_offset
  ./param_addresses $param_offset 20 21
  param_offset=$(( $param_offset + 1 ))
  printf "\n\n"
done
