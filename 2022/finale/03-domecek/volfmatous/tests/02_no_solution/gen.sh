#!/bin/bash

I=50000
while [ -s tests/01_no_solution/out.txt ] || [ ! -f tests/01_no_solution/out.txt ]; do
  echo testing $I
  ./a.out <<<$I >tests/01_no_solution/out.txt
  ((I=I+1))
done
