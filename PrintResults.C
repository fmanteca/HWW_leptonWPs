//root -l -q -b "PrintResults.C(\"Tight\", \"mm\")"

#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>

void PrintResults(TString muonWP, TString channel, TString cutLevel)
{
  TH1::SetDefaultSumw2();
 
  TFile* file_HWW = new TFile("nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private_" + muonWP + "_" + channel + "_cutLevel_" + cutLevel + ".root"); 
  TFile* file_WW = new TFile("nanoLatino_WWTo2L2Nu_" + muonWP + "_" + channel + "_cutLevel_" + cutLevel + ".root"); 
  TFile* file_DY = new TFile("nanoLatino_DYJetsToLL_M-50_" + muonWP + "_" + channel + "_cutLevel_" + cutLevel + ".root"); 
  TFile* file_TTTo2L2Nu = new TFile("nanoLatino_TTTo2L2Nu_" + muonWP + "_" + channel + "_cutLevel_" + cutLevel + ".root"); 
  TFile* file_TTToSemileptonic = new TFile("nanoLatino_TTToSemileptonic_" + muonWP + "_" + channel + "_cutLevel_" + cutLevel + ".root"); 
  TFile* file_ST = new TFile("nanoLatino_ST_tW_top_" + muonWP + "_" + channel + "_cutLevel_" + cutLevel + ".root"); 
  TFile* file_WJets = new TFile("nanoLatino_WJetsToLNu-LO_" + muonWP + "_" + channel + "_cutLevel_" + cutLevel + ".root"); 


  TH1F* h_counter_HWW_pass2Leploose = (TH1F*)file_HWW->Get("h_counter_pass2Leploose"); 
  TH1F* h_counter_HWW_passWP = (TH1F*)file_HWW->Get("h_counter_passWP"); 
  TH1F* h_counter_WW_pass2Leploose = (TH1F*)file_WW->Get("h_counter_pass2Leploose"); 
  TH1F* h_counter_WW_passWP = (TH1F*)file_WW->Get("h_counter_passWP"); 
  TH1F* h_counter_DY_pass2Leploose = (TH1F*)file_DY->Get("h_counter_pass2Leploose"); 
  TH1F* h_counter_DY_passWP = (TH1F*)file_DY->Get("h_counter_passWP"); 
  TH1F* h_counter_TTTo2L2Nu_pass2Leploose = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass2Leploose"); 
  TH1F* h_counter_TTTo2L2Nu_passWP = (TH1F*)file_TTTo2L2Nu->Get("h_counter_passWP"); 
  TH1F* h_counter_TTToSemileptonic_pass2Leploose = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass2Leploose"); 
  TH1F* h_counter_TTToSemileptonic_passWP = (TH1F*)file_TTToSemileptonic->Get("h_counter_passWP"); 
  TH1F* h_counter_ST_pass2Leploose = (TH1F*)file_ST->Get("h_counter_pass2Leploose"); 
  TH1F* h_counter_ST_passWP = (TH1F*)file_ST->Get("h_counter_passWP"); 
  TH1F* h_counter_WJets_pass2Leploose = (TH1F*)file_WJets->Get("h_counter_pass2Leploose"); 
  TH1F* h_counter_WJets_passWP = (TH1F*)file_WJets->Get("h_counter_passWP"); 


  Float_t eff_HWW  = h_counter_HWW_passWP->Integral() / h_counter_HWW_pass2Leploose->Integral();
  Float_t eff_WW  = h_counter_WW_passWP->Integral() / h_counter_WW_pass2Leploose->Integral();
  Float_t eff_DY  = h_counter_DY_passWP->Integral() / h_counter_DY_pass2Leploose->Integral();
  Float_t eff_TTTo2L2Nu  = h_counter_TTTo2L2Nu_passWP->Integral() / h_counter_TTTo2L2Nu_pass2Leploose->Integral();
  Float_t eff_TTToSemileptonic  = h_counter_TTToSemileptonic_passWP->Integral() / h_counter_TTToSemileptonic_pass2Leploose->Integral();
  Float_t eff_ST  = h_counter_ST_passWP->Integral() / h_counter_ST_pass2Leploose->Integral();
  Float_t eff_WJets  = h_counter_WJets_passWP->Integral() / h_counter_WJets_pass2Leploose->Integral();
  
  Float_t sum_bkg = h_counter_WW_passWP->Integral() + h_counter_DY_passWP->Integral() + h_counter_TTTo2L2Nu_passWP->Integral() + h_counter_TTToSemileptonic_passWP->Integral() + h_counter_ST_passWP->Integral() + h_counter_WJets_passWP->Integral();

  Float_t significance_sqrt_sb = h_counter_HWW_passWP->Integral() / TMath::Sqrt(h_counter_HWW_passWP->Integral() + sum_bkg);
  Float_t significance_sqrt_b = h_counter_HWW_passWP->Integral() / TMath::Sqrt(sum_bkg);
  Float_t significance_b = h_counter_HWW_passWP->Integral() / sum_bkg;



  //----------------------------------------------------------------------------------------------------------------------------------
  //Print the results

  string samples [7] = {"HWW           ", "WW            ", "DY            ", "TTDileptonic  ", "TTSemileptonic", "SingleTop     ", "WJets         "};
  Float_t efficiencies[7] = {eff_HWW, eff_WW, eff_DY, eff_TTTo2L2Nu, eff_TTToSemileptonic, eff_ST, eff_WJets};

  printf("\n");
  cout << "------------------------------------------------------------------------------------------------";
  printf("\n");
  cout << "Results for " + muonWP + " muon WP, " + channel + "channel,  cutLevel " + cutLevel << endl;
  cout << "------------------------------------------------------------------------------------------------";
  printf("\n");
  for (int i=0; i<=6; i++){
    printf(" Sample: %s   Efficiency: %5.3f",
	   samples[i].c_str(),
	   efficiencies[i]);
    printf("\n");
  }
  printf("\n");
  cout << "------------------------------------------------------------------------------------------------";
  printf("\n");
  
  cout << "Significance S/sqrt(S+B) = " << significance_sqrt_sb << endl;
  cout << "Significance S/sqrt(B)   = " << significance_sqrt_b << endl;
  cout << "Significance S/B         = " << significance_b << endl;

  cout << "------------------------------------------------------------------------------------------------";
  printf("\n");

}
