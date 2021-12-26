#!/bin/bash
#averagetime.sh
# Paolo Vicencio, pjv7nd, 4/31/21

echo "hi there"

# takes in dictionary file
echo “Input dictionary file here: “
read dictionary

# takes in grid file
echo “input grid file here: “
read grid


# running through the times
first=`./a.out $dictionary $grid | tail -1`
second=`./a.out $dictionary $grid | tail -1`
third=`./a.out $dictionary $grid | tail -1`
fourth=`./a.out $dictionary $grid | tail -1`
fifth=`./a.out $dictionary $grid | tail -1`

# summing all of the different times into one variable
runningTotal=`expr $first + $second`
runningTotal=`expr $runningTotal + $third`
runningTotal=`expr $runningTotal + $fourth`
runningTotal=`expr $runningTotal + $fifth`

# printing out the total time taken to run
echo “Total Time: "
echo $runningTotal