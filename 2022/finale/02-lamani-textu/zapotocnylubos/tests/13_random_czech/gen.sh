#!/bin/bash

WORDS=(
  "zelí"
  "řetízek"
  "kraťasy"
  "zákazník"
  "liška"
  "lednička"
  "pěna"
  "opalovací"
  "táta"
  "máma"
  "jarní"
  "Lorem"
  "ipsum"
  "dolor"
  "sit"
  "amet,"
  "consectetur"
  "adipiscing"
  "elit."
  "Maecenas"
  "mollis"
  "vitae"
  "erat"
  "nec"
  "fringilla."
  "Nullam"
  "vitae"
  "metus"
  "lacinia"
  "felis"
  "vestibulum"
  "lacinia."
  "In"
  "ultrices,"
  "velit"
  "ac"
  "mollis"
  "tristique,"
  "felis"
  "ipsum"
  "luctus"
  "risus,"
  "et"
  "vulputate"
  "massa"
  "quam"
  "vitae"
  "nisi."
  "Morbi"
  "ullamcorper"
  "eu"
  "erat"
  "ac"
  "mollis."
  "Nam"
  "condimentum"
  "leo"
  "tortor,"
  "vitae"
  "interdum"
  "eros"
  "iaculis"
  "nec."
  "Phasellus"
  "porta"
  "est"
  "eget"
  "dolor"
  "commodo,"
  "sed"
  "eleifend"
  "turpis"
  "euismod."
  "Pellentesque"
  "vitae"
  "pharetra"
  "mauris."
  "Vivamus"
  "non"
  "orci"
  "neque."
  "Nam"
  "risus"
  "orci,"
  "commodo"
  "nec"
  "risus"
  "eget,"
  "scelerisque"
  "laoreet"
  "arcu."
  "Duis"
  "id"
  "dui"
  "interdum,"
  "imperdiet"
  "lectus"
  "eu,"
  "mattis"
  "arcu."
  "Nullam"
  "eget"
  "lacinia"
  "lacus,"
  "a"
  "ornare"
  "lectus."
  "In"
  "hac"
  "habitasse"
  "platea"
  "dictumst."
  "Vivamus"
  "porttitor,"
  "lorem"
  "at"
  "ultricies"
  "interdum,"
  "ante"
  "erat"
  "rhoncus"
  "ipsum,"
  "sed"
  "ultricies"
  "purus"
  "quam"
  "non"
  "magna."
  "Nunc"
  "vestibulum"
  "sem"
  "feugiat"
  "lorem"
  "interdum,"
  "sed"
  "luctus"
  "quam"
  "facilisis."
  # custom words
  "Supercalifragilisticexpialidocious"
  "k"
  "s"
  "v"
  "z"
)


LAST_KSVZ=0
LAST_NEWLINE=0

generate_word() {
  WORDS_LENGTH=${#WORDS[@]}

  WORD_RANDOM_INDEX=$((RANDOM % WORDS_LENGTH))
  WORD=${WORDS[$WORD_RANDOM_INDEX]}

  while [ $LAST_KSVZ -eq 1 ]; do
    WORD_RANDOM_INDEX=$((RANDOM % WORDS_LENGTH))
    WORD=${WORDS[$WORD_RANDOM_INDEX]}
    case $WORD in
      "k" | "s" | "v" | "z")
        LAST_KSVZ=1
        ;;
      *)
        LAST_KSVZ=0
        ;;
    esac
  done

  case $WORD in
    "k" | "s" | "v" | "z")
      LAST_KSVZ=1
      ;;
    *)
      LAST_KSVZ=0
      ;;
  esac

  printf $WORD
}

WORDS_PER_LINE_MIN=5
WORDS_PER_LINE_MAX=20

generate() {
  LIMIT=30
  LINES=100000

  echo $LIMIT >in.txt
  echo $LINES >>in.txt
  echo >>in.txt

  for ((i = 0; i < $LINES; i++)); do
    if ((i % 1000 == 0)); then
      echo "D: $i"
    fi

    if [ $i -ne $((LINES - 1)) ] && [ "$LAST_NEWLINE" -eq "0" ] && [ $(( ( RANDOM % 10 )  + 1 )) -eq 4 ]; then
      LAST_NEWLINE=1
      echo >>in.txt
      continue
    fi

    LAST_NEWLINE=0

    WORDS_PER_LINE=$(((RANDOM % (WORDS_PER_LINE_MAX - WORDS_PER_LINE_MIN + 1)) + WORDS_PER_LINE_MIN))

    for ((w = 0; w < $((WORDS_PER_LINE - 1)); w++)); do
        generate_word >>in.txt
        printf " " >>in.txt
    done

    LAST_KSVZ=1
    generate_word >>in.txt

    echo >>in.txt

  done
}

generate
