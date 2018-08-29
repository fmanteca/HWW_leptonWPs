# README:


## 0. Set the CMSSW release

```
export SCRAM_ARCH=slc6_amd64_gcc630
cmsrel CMSSW_10_1_0
cd CMSSW_10_1_0/src
cmsenv
```



## 1. Submit the jobs to the lxplus batch:

```
python submit.py >> launch.sh

./launch.sh
```



## 2. check the jobs status

```
./check-jobs.sh
```

re-submit the jobs that failed... or just run them interactively: 
```
root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium_HWW\", \"em\", \"high\", \"0j\")"
```



## 3. Merge the rootfiles

```
./merge.sh
```



## 4. Get the results as .tex tables

```
root -l -q -b "PrintResults.C(\"Medium_HWW\", \"em\", \"high\", \"0j\")" >> Medium_HWW_em_high_0j.tex
```



## 5. Plot the stored distributions 

```
root -l -q -b "PlotVariables.C(\"Medium_HWW\", \"em\", \"high\", \"0j\")"
```



