#!/bin/bash

# use this to generate empty testcase
# while [ -s tests/22_random_extreme_no_path/out.txt ] || [ ! -f tests/22_random_extreme_no_path/out.txt ]; do cd tests/22_random_extreme_no_path && ./gen.sh && cd ../../ && ./solution <tests/22_random_extreme_no_path/in.txt >tests/22_random_extreme_no_path/out.txt ; done

RANGE=4

generate_spot() {
  printf $(($RANDOM % RANGE))
}

generate() {
  MND=4

  ROWS=1000
  COLUMNS=1000

  START_COLUMN=$(($RANDOM % COLUMNS))
  START_ROW=$(($RANDOM % ROWS))

  END_COLUMN=$(($RANDOM % COLUMNS))
  END_ROW=$(($RANDOM % ROWS))

  echo $MND > in.txt
  echo $START_COLUMN $START_ROW >>in.txt
  echo $END_COLUMN $END_ROW >>in.txt
  echo $COLUMNS $ROWS >>in.txt
  echo >>in.txt

  for ((i = 0; i < $ROWS; i++)); do
    if ((i % 100 == 0)); then
      echo "R $i"
    fi

    generate_spot >>in.txt
    for ((j = 0; j < $((COLUMNS - 2)); j++)); do
      printf '   ' >>in.txt
      generate_spot >>in.txt
    done
    printf '   ' >>in.txt
    generate_spot >>in.txt
    printf '\n' >>in.txt
  done
}

generate