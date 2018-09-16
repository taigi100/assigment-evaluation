#!/bin/bash
teste=./teste/*
for folder in $teste; do
  name=${folder##*/}
  echo "Processing problem: $name"
  testcount=$(find $folder -maxdepth 1 -type f | wc -l)
  echo "TestCount: $testcount"
  ./compile.sh $name
  ./runtests.sh $name testcount
  rm ./$name.in
  rm ./$name.out
done