#!/bin/bash

VALUE_START=-1000000
VALUE_END=1000000

generate() {
  COUNT=500000

  echo $COUNT >>in.txt
  echo >>in.txt

  for ((i = 0; i < $COUNT; i++)); do
    if ((i % 1000 == 0)); then
      echo "D: $i"
    fi

    VALUE=$(((RANDOM % (VALUE_END - VALUE_START + 1)) + VALUE_START))
    echo $VALUE >>in.txt
  done
}

generate
