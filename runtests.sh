#!/bin/bash
# First param - name of problem, second - number of tests.
EXES=./exes
results=./results
if [ ! -d "$EXES" ]; then
	echo "No executables found"; exit
fi
if [ ! $1 ]; then
	echo "No params found, please insert problem name ( case sensitive )"; exit
fi
if [ ! -d "$results/$1" ]; then
	mkdir $results
fi
if [ ! -d "$results/$1" ]; then
	mkdir $results/$1
fi
> $results/$1/raport_teste.txt
function ProcessFolder {
	exefolder=$1
	exe=$1/a.o
	testpath=./teste/$2/
	for ((i=0;i<=$3;i++)); do
		infile=$testpath$i-$2.in
		okfile=$testpath$i-$2.ok
	
		if [ -f $infile ]; then
		#make auxiliary file for input
		cat $infile > $2.in
		#run program and send output to $2.out
		if [ -f $exe ]
		then
			$($exe > $2.out)
		fi
		#debug
		#echo "out file: "
		#cat $2.out
		#echo "ok file: "
		#cat $okfile
		#echo ""
		#check out if output == ok
			if result="$(diff -w --ignore-all-space $2.out $okfile)"
			then
				echo "Source: $1 test $i succeded" >> $results/$2/teste.txt
				tests[$i]=`expr ${tests[$i]} + 1`
			else
				echo "Source: $1 test $i failed" >> $results/$2/teste.txt
			fi
		fi
	done
}

> $results/$1/teste.txt
cnt=0

for((i=0;i<=$2;i++)); do
	tests[i]=`expr 0`;
done

for folder in $EXES/*; do
  name=${folder##*/}
  cnt=`expr $cnt + 1`
  echo "Testing $folder folder"
  ProcessFolder ./exes/$name $1 $2
done

for ((i=0;i<=$2;i++)); do
	aux=`expr 100 \* ${tests[$i]} / $cnt`
	echo "Testul $i: $aux%" >> $results/$1/raport_teste.txt
done