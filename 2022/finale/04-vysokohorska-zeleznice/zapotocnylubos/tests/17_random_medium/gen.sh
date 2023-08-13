#!/bin/bash

# use this to generate non empty testcase
# while [ ! -s tests/17_random_medium/out.txt ]; do cd tests/17_random_medium && ./gen.sh && cd ../../ && ./solution <tests/17_random_medium/in.txt >tests/17_random_medium/out.txt; done

# use this to generate non empty testcase with at least 10 lines of output
# while [ ! -s tests/17_random_medium/out.txt ] || [ $(wc -l < tests/17_random_medium/out.txt) -le 10 ] ; do cd tests/17_random_medium && ./gen.sh && cd ../../ && ./solution <tests/17_random_medium/in.txt >tests/17_random_medium/out.txt; done

RANGE=5

generate_spot() {
  printf $(($RANDOM % RANGE))
}

generate() {
  MND=3

  ROWS=30
  COLUMNS=30

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