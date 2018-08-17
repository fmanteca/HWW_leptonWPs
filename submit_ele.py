import os
import sys

SAMPLES={"GluGluHToWWTo2L2NuPowheg_M125_private","DYJetsToLL_M-50__part0","DYJetsToLL_M-50__part1","DYJetsToLL_M-50__part2","DYJetsToLL_M-50__part3","DYJetsToLL_M-50__part4","DYJetsToLL_M-50__part5","DYJetsToLL_M-50__part6","DYJetsToLL_M-50__part7","DYJetsToLL_M-50__part8","DYJetsToLL_M-50__part9","DYJetsToLL_M-50__part10","DYJetsToLL_M-50__part11","DYJetsToLL_M-50__part12","DYJetsToLL_M-50__part13","DYJetsToLL_M-50__part14","DYJetsToLL_M-50__part15","DYJetsToLL_M-50__part16","DYJetsToLL_M-50__part17","DYJetsToLL_M-50__part18","DYJetsToLL_M-50__part19","DYJetsToLL_M-50__part20","ST_tW_top","TTTo2L2Nu__part0","TTTo2L2Nu__part1","TTTo2L2Nu__part2","TTToSemileptonic__part0","TTToSemileptonic__part1","WJetsToLNu-LO__part0","WJetsToLNu-LO__part1","WJetsToLNu-LO__part2","WWTo2L2Nu"}

#SAMPLES={"GluGluHToWWTo2L2NuPowheg_M125_private"}

#WPS={"Medium","Medium_HWW","Tight","Tight_HWW"}

WPS={"Tight_HWW", "mvaFall17noIso_WPL", "mvaFall17Iso_WPL", "mvaFall17noIso_WP80", "mvaFall17Iso_WP80", "mvaFall17noIso_WP90", "mvaFall17Iso_WP90"}

#CH = {"em","mm"}
CH = {"em"}


P2 = {"high","low"}
#P2 = {"high"}

JET = {"0j","1j","Incl"}
#JET = {"0j"}


for s in SAMPLES:
    for wp in WPS:
        for ch in CH:
            for pt in P2:
                for j in JET:
                    print 'bsub -q 2nd -u pipo12345 submit_Higgs_eleWP.sh ' + s + ' ' + wp + ' ' + ch + ' ' + pt + ' ' + j

                    


