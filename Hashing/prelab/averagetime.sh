#!/bin/bash
#averagetime.sh
#Paolo Vicencio, pjv7nd, 4/31/21

#takes in dictionary file
echo Input dictionary file here: 
read dictionary

#takes in grid file
echo Input grid file here: 
read grid


#running through the times
run1=`./a.out $dictionary $grid | tail -1`
run2=`./a.out $dictionary $grid | tail -1`
run3=`./a.out $dictionary $grid | tail -1`
run4=`./a.out $dictionary $grid | tail -1`
run5=`./a.out $dictionary $grid | tail -1`

#summing all of the different times into one variable
runningTotal=$((run1 + run2))
runningTotal=$((runningTotal + run3))
runningTotal=$((runningTotal + run4))
runningTotal=$((runningTotal + run5))

#printing out the total time taken to run
echo Total Time: $runningTotal
