#!/bin/bash

VALUE_START=-50
VALUE_END=50

generate() {
  COUNT=500000

  for ((i = 0; i < $COUNT; i++)); do
    if ((i % 1000 == 0)); then
      echo "D: $i"
    fi

    VALUE=$(((RANDOM % (VALUE_END - VALUE_START + 1)) + VALUE_START))
    echo $VALUE >>in.txt
  done
}

generate