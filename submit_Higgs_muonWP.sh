#!/bin/bash                                                                                                                            
mkdir jobs_ouput
cp Higgs_muonWP.C jobs_ouput
cd jobs_ouput

eval `scramv1 runtime -sh`

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Medium_HWW\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight_HWW\", \"mm\", \"6\")"









bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Medium_HWW\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WWTo2L2Nu\",\"Tight_HWW\", \"mm\", \"6\")"










bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Medium_HWW\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_DYJetsToLL_M-50\",\"Tight_HWW\", \"mm\", \"6\")"








bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Medium_HWW\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTTo2L2Nu\",\"Tight_HWW\", \"mm\", \"6\")"







bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Medium_HWW\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_ST_tW_top\",\"Tight_HWW\", \"mm\", \"6\")"









bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Medium_HWW\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_TTToSemileptonic\",\"Tight_HWW\", \"mm\", \"6\")"










bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Medium_HWW\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight\", \"mm\", \"6\")"

bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight_HWW\", \"mm\", \"1\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight_HWW\", \"mm\", \"2\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight_HWW\", \"mm\", \"3\")"
bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight_HWW\", \"mm\", \"4\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight_HWW\", \"mm\", \"5\")"
# bsub -q 8nh -u pippo1234 root -l -q -b "Higgs_muonWP.C(\"nanoLatino_WJetsToLNu-LO\",\"Tight_HWW\", \"mm\", \"6\")"

