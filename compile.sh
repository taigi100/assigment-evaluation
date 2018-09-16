#!/bin/bash
# $1 = problem name
SOURCES=./sources/*
EXES=./exes
results=./results
if [ ! -d "$EXES" ]; then
	mkdir $EXES
fi
if [ ! -d "$results/$1" ]; then
	mkdir $results
fi
if [ ! -d "$results/$1" ]; then
	mkdir $results/$1
fi
> $results/$1/results.txt
> $results/$1/compile_errors.txt
for folder in $SOURCES; do
  name=${folder##*/}
  echo "Compiling $folder folder"
  exespath=./exes/$name
  if [ ! -d "$exespath" ]; then
	mkdir $exespath
  fi
  echo $name: >> $results/$1/compile_errors.txt
  retVal= $(gcc $folder/*.c -Wall -o $exespath/a.o 2>> $results/$1/compile_errors.txt)
  if [ $? -eq 0 ]; then
	echo -e "Folder $name compiled succesfully!" >> $results/$1/results.txt
  else
	echo -e "Folder $name failed!" >> $results/$1/results.txt
  fi
done