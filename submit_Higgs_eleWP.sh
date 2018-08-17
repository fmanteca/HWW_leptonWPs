#!/bin/sh

cd `dirname $0`
eval `scramv1 runtime -sh`

SAMPLE=$1
WP=$2
CHANNEL=$3
PT2=$4
NJET=$5


root -l -q -b "/afs/cern.ch/work/f/fernanpe/CMSSW_10_1_0/src/Higgs_eleWP.C(\"$SAMPLE\",\"$WP\", \"$CHANNEL\", \"$PT2\", \"$NJET\")"
