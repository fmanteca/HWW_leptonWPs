# README:


## 0. Set the CMSSW release

export SCRAM_ARCH=slc6_amd64_gcc630
cmsrel CMSSW_10_1_0
cd CMSSW_10_1_0/src
cmsenv




## 1. Submit the jobs to the lxplus batch:

./submit_Higgs_muonWP.sh




## 2. check the jobs status

./check-jobs.sh

re-submit the jobs that failed... or just run them interactively: 
root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium\", \"mm\", \"1\")"




## 3. Print the results

root -l -q -b "PrintResults.C(\"Tight\", \"mm\")"




