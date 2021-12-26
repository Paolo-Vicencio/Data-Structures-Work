#!/bin/bash
#Paolo Vicencio, pjv7nd, 4/6/21

echo enter the exponent for counter.cpp:
read exponent

if [[ $exponent == quit ]];
then 
	exit 
fi

counter=1
accumu=0

while [[ $counter -lt 6 ]];
do 
	run=`./a.out $exponent  | tail -1`
	echo Running iteration $counter ...
	echo time taken: $run ms
	accumu=$((accumu + run))
	counter=$((counter + 1))
done

echo 5 iterations took $accumu ms
echo Average time was $((accumu/5)) ms