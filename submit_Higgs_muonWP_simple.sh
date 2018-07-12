#!/bin/bash                                                                                                                            
mkdir jobs_ouput
filelist="../listsamples.txt"
cp Higgs_muonWP.C jobs_ouput
cd jobs_ouput

eval `scramv1 runtime -sh`
begin='Higgs_muonWP.C("'
comma='","'
end='")'

filelines=`cat $filelist`

for line in $filelines ; do   
    echo $line
    for muonWP in {"Medium","Medium_HWW","Tight","Tight_HWW"}
    do
	for channel in {"em","mm"}
	do
	    mystring=$begin$line$comma$muonWP$comma$channel$end
	    echo $mystring
	    root -l -q -b $mystring
	done
    done
done
