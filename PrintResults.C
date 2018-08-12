//root -l -q -b "PrintResults.C(\"Tight\", \"mm\")"

#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>

void PrintResults(TString muonWP, TString channel, TString pt2_cut, TString njet)
{
  TH1::SetDefaultSumw2();
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
 
  TFile* file_HWW = new TFile("jobs_output/01_HWW_" + muonWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_WW = new TFile("jobs_output/02_WW_" + muonWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_DY = new TFile("jobs_output/03_DY_" + muonWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_TTTo2L2Nu = new TFile("jobs_output/04_TTTo2L2Nu_" + muonWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_TTToSemileptonic = new TFile("jobs_output/05_TTToSemileptonic_" + muonWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_ST = new TFile("jobs_output/06_ST_" + muonWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_WJets = new TFile("jobs_output/07_WJets_" + muonWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
 

  TH1F* h_counter_HWW_pass_1 = (TH1F*)file_HWW->Get("h_counter_pass_1"); 
  TH1F* h_counter_WW_pass_1 = (TH1F*)file_WW->Get("h_counter_pass_1"); 
  TH1F* h_counter_DY_pass_1 = (TH1F*)file_DY->Get("h_counter_pass_1"); 
  TH1F* h_counter_TTTo2L2Nu_pass_1 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_1"); 
  TH1F* h_counter_TTToSemileptonic_pass_1 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_1"); 
  TH1F* h_counter_ST_pass_1 = (TH1F*)file_ST->Get("h_counter_pass_1"); 
  TH1F* h_counter_WJets_pass_1 = (TH1F*)file_WJets->Get("h_counter_pass_1"); 

  
  Float_t sum_bkg_1 = h_counter_WW_pass_1->Integral() + h_counter_DY_pass_1->Integral() + h_counter_TTTo2L2Nu_pass_1->Integral() + h_counter_TTToSemileptonic_pass_1->Integral() + h_counter_ST_pass_1->Integral() + h_counter_WJets_pass_1->Integral();

  Float_t significance_sqrt_sb_1 = h_counter_HWW_pass_1->Integral() / TMath::Sqrt(h_counter_HWW_pass_1->Integral() + sum_bkg_1);
  Float_t significance_sqrt_b_1 = h_counter_HWW_pass_1->Integral() / TMath::Sqrt(sum_bkg_1);
  Float_t significance_b_1 = h_counter_HWW_pass_1->Integral() / sum_bkg_1;





  TH1F* h_counter_HWW_pass_2 = (TH1F*)file_HWW->Get("h_counter_pass_2"); 
  TH1F* h_counter_WW_pass_2 = (TH1F*)file_WW->Get("h_counter_pass_2"); 
  TH1F* h_counter_DY_pass_2 = (TH1F*)file_DY->Get("h_counter_pass_2"); 
  TH1F* h_counter_TTTo2L2Nu_pass_2 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_2"); 
  TH1F* h_counter_TTToSemileptonic_pass_2 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_2"); 
  TH1F* h_counter_ST_pass_2 = (TH1F*)file_ST->Get("h_counter_pass_2"); 
  TH1F* h_counter_WJets_pass_2 = (TH1F*)file_WJets->Get("h_counter_pass_2"); 

  
  Float_t sum_bkg_2 = h_counter_WW_pass_2->Integral() + h_counter_DY_pass_2->Integral() + h_counter_TTTo2L2Nu_pass_2->Integral() + h_counter_TTToSemileptonic_pass_2->Integral() + h_counter_ST_pass_2->Integral() + h_counter_WJets_pass_2->Integral();

  Float_t significance_sqrt_sb_2 = h_counter_HWW_pass_2->Integral() / TMath::Sqrt(h_counter_HWW_pass_2->Integral() + sum_bkg_2);
  Float_t significance_sqrt_b_2 = h_counter_HWW_pass_2->Integral() / TMath::Sqrt(sum_bkg_2);
  Float_t significance_b_2 = h_counter_HWW_pass_2->Integral() / sum_bkg_2;



  TH1F* h_counter_HWW_pass_3 = (TH1F*)file_HWW->Get("h_counter_pass_3"); 
  TH1F* h_counter_WW_pass_3 = (TH1F*)file_WW->Get("h_counter_pass_3"); 
  TH1F* h_counter_DY_pass_3 = (TH1F*)file_DY->Get("h_counter_pass_3"); 
  TH1F* h_counter_TTTo2L2Nu_pass_3 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_3"); 
  TH1F* h_counter_TTToSemileptonic_pass_3 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_3"); 
  TH1F* h_counter_ST_pass_3 = (TH1F*)file_ST->Get("h_counter_pass_3"); 
  TH1F* h_counter_WJets_pass_3 = (TH1F*)file_WJets->Get("h_counter_pass_3"); 

  
  Float_t sum_bkg_3 = h_counter_WW_pass_3->Integral() + h_counter_DY_pass_3->Integral() + h_counter_TTTo2L2Nu_pass_3->Integral() + h_counter_TTToSemileptonic_pass_3->Integral() + h_counter_ST_pass_3->Integral() + h_counter_WJets_pass_3->Integral();

  Float_t significance_sqrt_sb_3 = h_counter_HWW_pass_3->Integral() / TMath::Sqrt(h_counter_HWW_pass_3->Integral() + sum_bkg_3);
  Float_t significance_sqrt_b_3 = h_counter_HWW_pass_3->Integral() / TMath::Sqrt(sum_bkg_3);
  Float_t significance_b_3 = h_counter_HWW_pass_3->Integral() / sum_bkg_3;



  TH1F* h_counter_HWW_pass_4 = (TH1F*)file_HWW->Get("h_counter_pass_4"); 
  TH1F* h_counter_WW_pass_4 = (TH1F*)file_WW->Get("h_counter_pass_4"); 
  TH1F* h_counter_DY_pass_4 = (TH1F*)file_DY->Get("h_counter_pass_4"); 
  TH1F* h_counter_TTTo2L2Nu_pass_4 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_4"); 
  TH1F* h_counter_TTToSemileptonic_pass_4 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_4"); 
  TH1F* h_counter_ST_pass_4 = (TH1F*)file_ST->Get("h_counter_pass_4"); 
  TH1F* h_counter_WJets_pass_4 = (TH1F*)file_WJets->Get("h_counter_pass_4"); 

  
  Float_t sum_bkg_4 = h_counter_WW_pass_4->Integral() + h_counter_DY_pass_4->Integral() + h_counter_TTTo2L2Nu_pass_4->Integral() + h_counter_TTToSemileptonic_pass_4->Integral() + h_counter_ST_pass_4->Integral() + h_counter_WJets_pass_4->Integral();

  Float_t significance_sqrt_sb_4 = h_counter_HWW_pass_4->Integral() / TMath::Sqrt(h_counter_HWW_pass_4->Integral() + sum_bkg_4);
  Float_t significance_sqrt_b_4 = h_counter_HWW_pass_4->Integral() / TMath::Sqrt(sum_bkg_4);
  Float_t significance_b_4 = h_counter_HWW_pass_4->Integral() / sum_bkg_4;





  TH1F* h_counter_HWW_pass_5 = (TH1F*)file_HWW->Get("h_counter_pass_5"); 
  TH1F* h_counter_WW_pass_5 = (TH1F*)file_WW->Get("h_counter_pass_5"); 
  TH1F* h_counter_DY_pass_5 = (TH1F*)file_DY->Get("h_counter_pass_5"); 
  TH1F* h_counter_TTTo2L2Nu_pass_5 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_5"); 
  TH1F* h_counter_TTToSemileptonic_pass_5 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_5"); 
  TH1F* h_counter_ST_pass_5 = (TH1F*)file_ST->Get("h_counter_pass_5"); 
  TH1F* h_counter_WJets_pass_5 = (TH1F*)file_WJets->Get("h_counter_pass_5"); 

  
  Float_t sum_bkg_5 = h_counter_WW_pass_5->Integral() + h_counter_DY_pass_5->Integral() + h_counter_TTTo2L2Nu_pass_5->Integral() + h_counter_TTToSemileptonic_pass_5->Integral() + h_counter_ST_pass_5->Integral() + h_counter_WJets_pass_5->Integral();

  Float_t significance_sqrt_sb_5 = h_counter_HWW_pass_5->Integral() / TMath::Sqrt(h_counter_HWW_pass_5->Integral() + sum_bkg_5);
  Float_t significance_sqrt_b_5 = h_counter_HWW_pass_5->Integral() / TMath::Sqrt(sum_bkg_5);
  Float_t significance_b_5 = h_counter_HWW_pass_5->Integral() / sum_bkg_5;





  TH1F* h_counter_HWW_pass_6 = (TH1F*)file_HWW->Get("h_counter_pass_6"); 
  TH1F* h_counter_WW_pass_6 = (TH1F*)file_WW->Get("h_counter_pass_6"); 
  TH1F* h_counter_DY_pass_6 = (TH1F*)file_DY->Get("h_counter_pass_6"); 
  TH1F* h_counter_TTTo2L2Nu_pass_6 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_6"); 
  TH1F* h_counter_TTToSemileptonic_pass_6 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_6"); 
  TH1F* h_counter_ST_pass_6 = (TH1F*)file_ST->Get("h_counter_pass_6"); 
  TH1F* h_counter_WJets_pass_6 = (TH1F*)file_WJets->Get("h_counter_pass_6"); 

  
  Float_t sum_bkg_6 = h_counter_WW_pass_6->Integral() + h_counter_DY_pass_6->Integral() + h_counter_TTTo2L2Nu_pass_6->Integral() + h_counter_TTToSemileptonic_pass_6->Integral() + h_counter_ST_pass_6->Integral() + h_counter_WJets_pass_6->Integral();

  Float_t significance_sqrt_sb_6 = h_counter_HWW_pass_6->Integral() / TMath::Sqrt(h_counter_HWW_pass_6->Integral() + sum_bkg_6);
  Float_t significance_sqrt_b_6 = h_counter_HWW_pass_6->Integral() / TMath::Sqrt(sum_bkg_6);
  Float_t significance_b_6 = h_counter_HWW_pass_6->Integral() / sum_bkg_6;



  TH1F* h_counter_HWW_pass_7 = (TH1F*)file_HWW->Get("h_counter_pass_7"); 
  TH1F* h_counter_WW_pass_7 = (TH1F*)file_WW->Get("h_counter_pass_7"); 
  TH1F* h_counter_DY_pass_7 = (TH1F*)file_DY->Get("h_counter_pass_7"); 
  TH1F* h_counter_TTTo2L2Nu_pass_7 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_7"); 
  TH1F* h_counter_TTToSemileptonic_pass_7 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_7"); 
  TH1F* h_counter_ST_pass_7 = (TH1F*)file_ST->Get("h_counter_pass_7"); 
  TH1F* h_counter_WJets_pass_7 = (TH1F*)file_WJets->Get("h_counter_pass_7"); 

  
  Float_t sum_bkg_7 = h_counter_WW_pass_7->Integral() + h_counter_DY_pass_7->Integral() + h_counter_TTTo2L2Nu_pass_7->Integral() + h_counter_TTToSemileptonic_pass_7->Integral() + h_counter_ST_pass_7->Integral() + h_counter_WJets_pass_7->Integral();

  Float_t significance_sqrt_sb_7 = h_counter_HWW_pass_7->Integral() / TMath::Sqrt(h_counter_HWW_pass_7->Integral() + sum_bkg_7);
  Float_t significance_sqrt_b_7 = h_counter_HWW_pass_7->Integral() / TMath::Sqrt(sum_bkg_7);
  Float_t significance_b_7 = h_counter_HWW_pass_7->Integral() / sum_bkg_7;



  TH1F* h_counter_HWW_pass_8 = (TH1F*)file_HWW->Get("h_counter_pass_8"); 
  TH1F* h_counter_WW_pass_8 = (TH1F*)file_WW->Get("h_counter_pass_8"); 
  TH1F* h_counter_DY_pass_8 = (TH1F*)file_DY->Get("h_counter_pass_8"); 
  TH1F* h_counter_TTTo2L2Nu_pass_8 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_8"); 
  TH1F* h_counter_TTToSemileptonic_pass_8 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_8"); 
  TH1F* h_counter_ST_pass_8 = (TH1F*)file_ST->Get("h_counter_pass_8"); 
  TH1F* h_counter_WJets_pass_8 = (TH1F*)file_WJets->Get("h_counter_pass_8"); 

  
  Float_t sum_bkg_8 = h_counter_WW_pass_8->Integral() + h_counter_DY_pass_8->Integral() + h_counter_TTTo2L2Nu_pass_8->Integral() + h_counter_TTToSemileptonic_pass_8->Integral() + h_counter_ST_pass_8->Integral() + h_counter_WJets_pass_8->Integral();

  Float_t significance_sqrt_sb_8 = h_counter_HWW_pass_8->Integral() / TMath::Sqrt(h_counter_HWW_pass_8->Integral() + sum_bkg_8);
  Float_t significance_sqrt_b_8 = h_counter_HWW_pass_8->Integral() / TMath::Sqrt(sum_bkg_8);
  Float_t significance_b_8 = h_counter_HWW_pass_8->Integral() / sum_bkg_8;




  TH1F* h_counter_HWW_pass_9 = (TH1F*)file_HWW->Get("h_counter_pass_9"); 
  TH1F* h_counter_WW_pass_9 = (TH1F*)file_WW->Get("h_counter_pass_9"); 
  TH1F* h_counter_DY_pass_9 = (TH1F*)file_DY->Get("h_counter_pass_9"); 
  TH1F* h_counter_TTTo2L2Nu_pass_9 = (TH1F*)file_TTTo2L2Nu->Get("h_counter_pass_9"); 
  TH1F* h_counter_TTToSemileptonic_pass_9 = (TH1F*)file_TTToSemileptonic->Get("h_counter_pass_9"); 
  TH1F* h_counter_ST_pass_9 = (TH1F*)file_ST->Get("h_counter_pass_9"); 
  TH1F* h_counter_WJets_pass_9 = (TH1F*)file_WJets->Get("h_counter_pass_9"); 

  
  Float_t sum_bkg_9 = h_counter_WW_pass_9->Integral() + h_counter_DY_pass_9->Integral() + h_counter_TTTo2L2Nu_pass_9->Integral() + h_counter_TTToSemileptonic_pass_9->Integral() + h_counter_ST_pass_9->Integral() + h_counter_WJets_pass_9->Integral();

  Float_t significance_sqrt_sb_9 = h_counter_HWW_pass_9->Integral() / TMath::Sqrt(h_counter_HWW_pass_9->Integral() + sum_bkg_9);
  Float_t significance_sqrt_b_9 = h_counter_HWW_pass_9->Integral() / TMath::Sqrt(sum_bkg_9);
  Float_t significance_b_9 = h_counter_HWW_pass_9->Integral() / sum_bkg_9;


  


  Float_t counter_HWW_pass_1 = h_counter_HWW_pass_1->Integral();
  Float_t counter_HWW_pass_2 = h_counter_HWW_pass_2->Integral();
  Float_t counter_HWW_pass_3 = h_counter_HWW_pass_3->Integral();
  Float_t counter_HWW_pass_4 = h_counter_HWW_pass_4->Integral();
  Float_t counter_HWW_pass_5 = h_counter_HWW_pass_5->Integral();
  Float_t counter_HWW_pass_6 = h_counter_HWW_pass_6->Integral();
  Float_t counter_HWW_pass_7 = h_counter_HWW_pass_7->Integral();
  Float_t counter_HWW_pass_8 = h_counter_HWW_pass_8->Integral();
  Float_t counter_HWW_pass_9 = h_counter_HWW_pass_9->Integral();

  Float_t counter_WW_pass_1 = h_counter_WW_pass_1->Integral();
  Float_t counter_WW_pass_2 = h_counter_WW_pass_2->Integral();
  Float_t counter_WW_pass_3 = h_counter_WW_pass_3->Integral();
  Float_t counter_WW_pass_4 = h_counter_WW_pass_4->Integral();
  Float_t counter_WW_pass_5 = h_counter_WW_pass_5->Integral();
  Float_t counter_WW_pass_6 = h_counter_WW_pass_6->Integral();
  Float_t counter_WW_pass_7 = h_counter_WW_pass_7->Integral();
  Float_t counter_WW_pass_8 = h_counter_WW_pass_8->Integral();
  Float_t counter_WW_pass_9 = h_counter_WW_pass_9->Integral();

  Float_t counter_DY_pass_1 = h_counter_DY_pass_1->Integral();
  Float_t counter_DY_pass_2 = h_counter_DY_pass_2->Integral();
  Float_t counter_DY_pass_3 = h_counter_DY_pass_3->Integral();
  Float_t counter_DY_pass_4 = h_counter_DY_pass_4->Integral();
  Float_t counter_DY_pass_5 = h_counter_DY_pass_5->Integral();
  Float_t counter_DY_pass_6 = h_counter_DY_pass_6->Integral();
  Float_t counter_DY_pass_7 = h_counter_DY_pass_7->Integral();
  Float_t counter_DY_pass_8 = h_counter_DY_pass_8->Integral();
  Float_t counter_DY_pass_9 = h_counter_DY_pass_9->Integral();

  Float_t counter_TTTo2L2Nu_pass_1 = h_counter_TTTo2L2Nu_pass_1->Integral();
  Float_t counter_TTTo2L2Nu_pass_2 = h_counter_TTTo2L2Nu_pass_2->Integral();
  Float_t counter_TTTo2L2Nu_pass_3 = h_counter_TTTo2L2Nu_pass_3->Integral();
  Float_t counter_TTTo2L2Nu_pass_4 = h_counter_TTTo2L2Nu_pass_4->Integral();
  Float_t counter_TTTo2L2Nu_pass_5 = h_counter_TTTo2L2Nu_pass_5->Integral();
  Float_t counter_TTTo2L2Nu_pass_6 = h_counter_TTTo2L2Nu_pass_6->Integral();
  Float_t counter_TTTo2L2Nu_pass_7 = h_counter_TTTo2L2Nu_pass_7->Integral();
  Float_t counter_TTTo2L2Nu_pass_8 = h_counter_TTTo2L2Nu_pass_8->Integral();
  Float_t counter_TTTo2L2Nu_pass_9 = h_counter_TTTo2L2Nu_pass_9->Integral();

  Float_t counter_TTToSemileptonic_pass_1 = h_counter_TTToSemileptonic_pass_1->Integral();
  Float_t counter_TTToSemileptonic_pass_2 = h_counter_TTToSemileptonic_pass_2->Integral();
  Float_t counter_TTToSemileptonic_pass_3 = h_counter_TTToSemileptonic_pass_3->Integral();
  Float_t counter_TTToSemileptonic_pass_4 = h_counter_TTToSemileptonic_pass_4->Integral();
  Float_t counter_TTToSemileptonic_pass_5 = h_counter_TTToSemileptonic_pass_5->Integral();
  Float_t counter_TTToSemileptonic_pass_6 = h_counter_TTToSemileptonic_pass_6->Integral();
  Float_t counter_TTToSemileptonic_pass_7 = h_counter_TTToSemileptonic_pass_7->Integral();
  Float_t counter_TTToSemileptonic_pass_8 = h_counter_TTToSemileptonic_pass_8->Integral();
  Float_t counter_TTToSemileptonic_pass_9 = h_counter_TTToSemileptonic_pass_9->Integral();

  Float_t counter_ST_pass_1 = h_counter_ST_pass_1->Integral();
  Float_t counter_ST_pass_2 = h_counter_ST_pass_2->Integral();
  Float_t counter_ST_pass_3 = h_counter_ST_pass_3->Integral();
  Float_t counter_ST_pass_4 = h_counter_ST_pass_4->Integral();
  Float_t counter_ST_pass_5 = h_counter_ST_pass_5->Integral();
  Float_t counter_ST_pass_6 = h_counter_ST_pass_6->Integral();
  Float_t counter_ST_pass_7 = h_counter_ST_pass_7->Integral();
  Float_t counter_ST_pass_8 = h_counter_ST_pass_8->Integral();
  Float_t counter_ST_pass_9 = h_counter_ST_pass_9->Integral();

  Float_t counter_WJets_pass_1 = h_counter_WJets_pass_1->Integral();
  Float_t counter_WJets_pass_2 = h_counter_WJets_pass_2->Integral();
  Float_t counter_WJets_pass_3 = h_counter_WJets_pass_3->Integral();
  Float_t counter_WJets_pass_4 = h_counter_WJets_pass_4->Integral();
  Float_t counter_WJets_pass_5 = h_counter_WJets_pass_5->Integral();
  Float_t counter_WJets_pass_6 = h_counter_WJets_pass_6->Integral();
  Float_t counter_WJets_pass_7 = h_counter_WJets_pass_7->Integral();
  Float_t counter_WJets_pass_8 = h_counter_WJets_pass_8->Integral();
  Float_t counter_WJets_pass_9 = h_counter_WJets_pass_9->Integral();




  cout <<"\\documentclass[10pt]{article}"<<endl;
  cout <<"\\usepackage[margin=0.3in,footskip=0.25in]{geometry}"<<endl;

  cout<<"\\begin{document}"<<endl;
  cout<<"\\begin{table}[htbp]"<<endl;
  cout<<"\\begin{tabular}{lcccccccc}"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"Cut Level          &  HWW  &  WW  &  DY  &  TTTo2L2Nu  &  TTToSemileptonic  &  ST  &  Wjets  &  Significance" << "\\" << "\\" << endl;
  cout<<"\\hline"<<endl;
  cout<<"pT $>$ 25/20, pT3 $<$ 10 [GeV] & " << counter_HWW_pass_1  << " & " << counter_WW_pass_1 <<  " & " << counter_DY_pass_1 << " & " << counter_TTTo2L2Nu_pass_1 << " & " << counter_TTToSemileptonic_pass_1 << " & " << counter_ST_pass_1 << " & " << counter_WJets_pass_1 << " & " << significance_sqrt_sb_1 << "\\" << "\\" << endl;
  cout<<"mll $>$ 12 GeV           & " << counter_HWW_pass_2  << " & " << counter_WW_pass_2 <<  " & " << counter_DY_pass_2 << " & " << counter_TTTo2L2Nu_pass_2 << " & " << counter_TTToSemileptonic_pass_2 << " & " << counter_ST_pass_2 << " & " << counter_WJets_pass_2 << " & " << significance_sqrt_sb_2 << "\\" << "\\" << endl;
  cout<<"bVeto CSVV2L           & " << counter_HWW_pass_3  << " & " << counter_WW_pass_3 <<  " & " << counter_DY_pass_3 << " & " << counter_TTTo2L2Nu_pass_3 << " & " << counter_TTToSemileptonic_pass_3 << " & " << counter_ST_pass_3 << " & " << counter_WJets_pass_3 << " & " << significance_sqrt_sb_3 << "\\" << "\\" << endl;
  cout<<"ZVeto (15 GeV)           & " << counter_HWW_pass_4  << " & " << counter_WW_pass_4 <<  " & " << counter_DY_pass_4 << " & " << counter_TTTo2L2Nu_pass_4 << " & " << counter_TTToSemileptonic_pass_4 << " & " << counter_ST_pass_4 << " & " << counter_WJets_pass_4 << " & " << significance_sqrt_sb_4 << "\\" << "\\" << endl;
  cout<<"pTll $>$ 30 GeV          & " << counter_HWW_pass_5  << " & " << counter_WW_pass_5 <<  " & " << counter_DY_pass_5 << " & " << counter_TTTo2L2Nu_pass_5 << " & " << counter_TTToSemileptonic_pass_5 << " & " << counter_ST_pass_5 << " & " << counter_WJets_pass_5 << " & " << significance_sqrt_sb_5 << "\\" << "\\" << endl;
  cout<<"PFMET $>$ 20 GeV         & " << counter_HWW_pass_6  << " & " << counter_WW_pass_6 <<  " & " << counter_DY_pass_6 << " & " << counter_TTTo2L2Nu_pass_6 << " & " << counter_TTToSemileptonic_pass_6 << " & " << counter_ST_pass_6 << " & " << counter_WJets_pass_6 << " & " << significance_sqrt_sb_6 << "\\" << "\\" << endl;
  cout<<"mpmet $>$ 20 GeV         & " << counter_HWW_pass_7  << " & " << counter_WW_pass_7 <<  " & " << counter_DY_pass_7 << " & " << counter_TTTo2L2Nu_pass_7 << " & " << counter_TTToSemileptonic_pass_7 << " & " << counter_ST_pass_7 << " & " << counter_WJets_pass_7 << " & " << significance_sqrt_sb_7 << "\\" << "\\" << endl;
  cout<<"mth $>$ 60 GeV           & " << counter_HWW_pass_8  << " & " << counter_WW_pass_8 <<  " & " << counter_DY_pass_8 << " & " << counter_TTTo2L2Nu_pass_8 << " & " << counter_TTToSemileptonic_pass_8 << " & " << counter_ST_pass_8 << " & " << counter_WJets_pass_8 << " & " << significance_sqrt_sb_8 << "\\" << "\\" << endl;
  cout<<"mtw2 $>$ 30 GeV          & " << counter_HWW_pass_9  << " & " << counter_WW_pass_9 <<  " & " << counter_DY_pass_9 << " & " << counter_TTTo2L2Nu_pass_9 << " & " << counter_TTToSemileptonic_pass_9 << " & " << counter_ST_pass_9 << " & " << counter_WJets_pass_9 << " & " << significance_sqrt_sb_9 << "\\" << "\\" << endl;
  cout<<"\\hline"<<endl;
  cout<<"\\end{tabular}"<<endl;
  cout<<"\\caption{" << muonWP << " muon working point, " << channel << " channel, " << pt2_cut << " pT2 cut, " << njet << " jet bin" << "}"<<endl;
  cout<<"\\end{table}"<<endl;
  cout<<"\\end{document}"<<endl;

}
