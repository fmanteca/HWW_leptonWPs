#!/bin/bash


printf "List of failed jobs: \n"
echo " "

for fn in `ls jobs_ouput/LSFJOB_*/STDOUT`; do

    export ISDONE=`cat $fn | grep Done | wc -l`
	
    if [ $ISDONE -ne 1 ]; then
	
	printf " %s\n" $fn
	
	echo " "
	
    fi
done


