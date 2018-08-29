//root -l -q -b "PlotVariables_ele.C(\"Tight\", \"mm\",\"high\",\"0j\")"

#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include "TLegend.h"
#include <iostream>
#include <fstream>

void PlotVariables_ele(TString electronWP, TString channel, TString pt2_cut, TString njet)
{
  TH1::SetDefaultSumw2();
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
 
  TFile* file_HWW = new TFile("../jobs_output_ele/01_HWW_" + electronWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_WW = new TFile("../jobs_output_ele/02_WW_" + electronWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_DY = new TFile("../jobs_output_ele/03_DY_" + electronWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_TTTo2L2Nu = new TFile("../jobs_output_ele/04_TTTo2L2Nu_" + electronWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_TTToSemileptonic = new TFile("../jobs_output_ele/05_TTToSemileptonic_" + electronWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_ST = new TFile("../jobs_output_ele/06_ST_" + electronWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 
  TFile* file_WJets = new TFile("../jobs_output_ele/07_WJets_" + electronWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root"); 

  //TFile* root_output = new TFile("/afs/cern.ch/work/a/alvareza/public/CMSSW_10_1_0/src/myMacros/for_Adrian/variables_electronWP_"+electronWP+"_"+channel+"_pt2_cut_"+pt2_cut+"_"+njet+".root", "recreate");
 
  TH1F* h_HWW_pt1 = (TH1F*)file_HWW->Get("h_pt1"); 
  TH1F* h_WW_pt1 = (TH1F*)file_WW->Get("h_pt1"); 
  TH1F* h_DY_pt1 = (TH1F*)file_DY->Get("h_pt1"); 
  TH1F* h_TTTo2L2Nu_pt1 = (TH1F*)file_TTTo2L2Nu->Get("h_pt1"); 
  TH1F* h_TTToSemileptonic_pt1 = (TH1F*)file_TTToSemileptonic->Get("h_pt1"); 
  TH1F* h_ST_pt1 = (TH1F*)file_ST->Get("h_pt1"); 
  TH1F* h_WJets_pt1 = (TH1F*)file_WJets->Get("h_pt1"); 

  TH1F* h_HWW_pt2 = (TH1F*)file_HWW->Get("h_pt2"); 
  TH1F* h_WW_pt2 = (TH1F*)file_WW->Get("h_pt2"); 
  TH1F* h_DY_pt2 = (TH1F*)file_DY->Get("h_pt2"); 
  TH1F* h_TTTo2L2Nu_pt2 = (TH1F*)file_TTTo2L2Nu->Get("h_pt2"); 
  TH1F* h_TTToSemileptonic_pt2 = (TH1F*)file_TTToSemileptonic->Get("h_pt2"); 
  TH1F* h_ST_pt2 = (TH1F*)file_ST->Get("h_pt2"); 
  TH1F* h_WJets_pt2 = (TH1F*)file_WJets->Get("h_pt2"); 

  TH1F* h_HWW_eta1 = (TH1F*)file_HWW->Get("h_eta1"); 
  TH1F* h_WW_eta1 = (TH1F*)file_WW->Get("h_eta1"); 
  TH1F* h_DY_eta1 = (TH1F*)file_DY->Get("h_eta1"); 
  TH1F* h_TTTo2L2Nu_eta1 = (TH1F*)file_TTTo2L2Nu->Get("h_eta1"); 
  TH1F* h_TTToSemileptonic_eta1 = (TH1F*)file_TTToSemileptonic->Get("h_eta1"); 
  TH1F* h_ST_eta1 = (TH1F*)file_ST->Get("h_eta1"); 
  TH1F* h_WJets_eta1 = (TH1F*)file_WJets->Get("h_eta1"); 

  TH1F* h_HWW_eta2 = (TH1F*)file_HWW->Get("h_eta2"); 
  TH1F* h_WW_eta2 = (TH1F*)file_WW->Get("h_eta2"); 
  TH1F* h_DY_eta2 = (TH1F*)file_DY->Get("h_eta2"); 
  TH1F* h_TTTo2L2Nu_eta2 = (TH1F*)file_TTTo2L2Nu->Get("h_eta2"); 
  TH1F* h_TTToSemileptonic_eta2 = (TH1F*)file_TTToSemileptonic->Get("h_eta2"); 
  TH1F* h_ST_eta2 = (TH1F*)file_ST->Get("h_eta2"); 
  TH1F* h_WJets_eta2 = (TH1F*)file_WJets->Get("h_eta2"); 

  TH1F* h_HWW_MET_pt = (TH1F*)file_HWW->Get("h_MET_pt"); 
  TH1F* h_WW_MET_pt = (TH1F*)file_WW->Get("h_MET_pt"); 
  TH1F* h_DY_MET_pt = (TH1F*)file_DY->Get("h_MET_pt"); 
  TH1F* h_TTTo2L2Nu_MET_pt = (TH1F*)file_TTTo2L2Nu->Get("h_MET_pt"); 
  TH1F* h_TTToSemileptonic_MET_pt = (TH1F*)file_TTToSemileptonic->Get("h_MET_pt"); 
  TH1F* h_ST_MET_pt = (TH1F*)file_ST->Get("h_MET_pt"); 
  TH1F* h_WJets_MET_pt = (TH1F*)file_WJets->Get("h_MET_pt"); 

  TH1F* h_HWW_mpmet = (TH1F*)file_HWW->Get("h_mpmet"); 
  TH1F* h_WW_mpmet = (TH1F*)file_WW->Get("h_mpmet"); 
  TH1F* h_DY_mpmet = (TH1F*)file_DY->Get("h_mpmet"); 
  TH1F* h_TTTo2L2Nu_mpmet = (TH1F*)file_TTTo2L2Nu->Get("h_mpmet"); 
  TH1F* h_TTToSemileptonic_mpmet = (TH1F*)file_TTToSemileptonic->Get("h_mpmet"); 
  TH1F* h_ST_mpmet = (TH1F*)file_ST->Get("h_mpmet"); 
  TH1F* h_WJets_mpmet = (TH1F*)file_WJets->Get("h_mpmet"); 

  TH1F* h_HWW_mth = (TH1F*)file_HWW->Get("h_mth"); 
  TH1F* h_WW_mth = (TH1F*)file_WW->Get("h_mth"); 
  TH1F* h_DY_mth = (TH1F*)file_DY->Get("h_mth"); 
  TH1F* h_TTTo2L2Nu_mth = (TH1F*)file_TTTo2L2Nu->Get("h_mth"); 
  TH1F* h_TTToSemileptonic_mth = (TH1F*)file_TTToSemileptonic->Get("h_mth"); 
  TH1F* h_ST_mth = (TH1F*)file_ST->Get("h_mth"); 
  TH1F* h_WJets_mth = (TH1F*)file_WJets->Get("h_mth"); 

  TH1F* h_HWW_mtw2 = (TH1F*)file_HWW->Get("h_mtw2"); 
  TH1F* h_WW_mtw2 = (TH1F*)file_WW->Get("h_mtw2"); 
  TH1F* h_DY_mtw2 = (TH1F*)file_DY->Get("h_mtw2"); 
  TH1F* h_TTTo2L2Nu_mtw2 = (TH1F*)file_TTTo2L2Nu->Get("h_mtw2"); 
  TH1F* h_TTToSemileptonic_mtw2 = (TH1F*)file_TTToSemileptonic->Get("h_mtw2"); 
  TH1F* h_ST_mtw2 = (TH1F*)file_ST->Get("h_mtw2"); 
  TH1F* h_WJets_mtw2 = (TH1F*)file_WJets->Get("h_mtw2"); 

  TH1F* h_HWW_mll = (TH1F*)file_HWW->Get("h_mll"); 
  TH1F* h_WW_mll = (TH1F*)file_WW->Get("h_mll"); 
  TH1F* h_DY_mll = (TH1F*)file_DY->Get("h_mll"); 
  TH1F* h_TTTo2L2Nu_mll = (TH1F*)file_TTTo2L2Nu->Get("h_mll"); 
  TH1F* h_TTToSemileptonic_mll = (TH1F*)file_TTToSemileptonic->Get("h_mll"); 
  TH1F* h_ST_mll = (TH1F*)file_ST->Get("h_mll"); 
  TH1F* h_WJets_mll = (TH1F*)file_WJets->Get("h_mll");

  TH1F* h_HWW_ptll = (TH1F*)file_HWW->Get("h_ptll"); 
  TH1F* h_WW_ptll = (TH1F*)file_WW->Get("h_ptll"); 
  TH1F* h_DY_ptll = (TH1F*)file_DY->Get("h_ptll"); 
  TH1F* h_TTTo2L2Nu_ptll = (TH1F*)file_TTTo2L2Nu->Get("h_ptll"); 
  TH1F* h_TTToSemileptonic_ptll = (TH1F*)file_TTToSemileptonic->Get("h_ptll"); 
  TH1F* h_ST_ptll = (TH1F*)file_ST->Get("h_ptll"); 
  TH1F* h_WJets_ptll = (TH1F*)file_WJets->Get("h_ptll");

  TH1F* h_HWW_dphill = (TH1F*)file_HWW->Get("h_dphill"); 
  TH1F* h_WW_dphill = (TH1F*)file_WW->Get("h_dphill"); 
  TH1F* h_DY_dphill = (TH1F*)file_DY->Get("h_dphill"); 
  TH1F* h_TTTo2L2Nu_dphill = (TH1F*)file_TTTo2L2Nu->Get("h_dphill"); 
  TH1F* h_TTToSemileptonic_dphill = (TH1F*)file_TTToSemileptonic->Get("h_dphill"); 
  TH1F* h_ST_dphill = (TH1F*)file_ST->Get("h_dphill"); 
  TH1F* h_WJets_dphill = (TH1F*)file_WJets->Get("h_dphill"); 

  TCanvas *can[11]; 
  TLegend *leg[11];
  for(int a=0;a<11;a++){ can[a]= new TCanvas(); 
    if(a==10){ leg[a]= new TLegend(0.2,0.65,0.4,0.85); leg[a]->SetHeader("SAMPLES","C");}
    else if(a==2||a==3){ leg[a]= new TLegend(0.4,0.65,0.6,0.85); leg[a]->SetHeader("SAMPLES","C");}
    else{ leg[a]= new TLegend(0.6,0.65,0.8,0.85); leg[a]->SetHeader("SAMPLES","C");}
  }

  THStack h_pt1("h_pt1","pt1"); can[0]->cd();
  h_HWW_pt1->SetFillColor(632); h_pt1.Add(h_HWW_pt1);h_WW_pt1->SetFillColor(851); h_pt1.Add(h_WW_pt1);h_DY_pt1->SetFillColor(418);  h_pt1.Add(h_DY_pt1);h_TTTo2L2Nu_pt1->SetFillColor(400);  h_pt1.Add(h_TTTo2L2Nu_pt1);h_TTToSemileptonic_pt1->SetFillColor(401);  h_pt1.Add(h_TTToSemileptonic_pt1);h_ST_pt1->SetFillColor(402);  h_pt1.Add(h_ST_pt1);h_WJets_pt1->SetFillColor(921);  h_pt1.Add(h_WJets_pt1);
  h_pt1.Draw("histo");  h_pt1.GetXaxis()->SetTitle("pt1 [GeV]");h_pt1.GetYaxis()->SetTitle("Entries");
  leg[0]->AddEntry(h_HWW_pt1,"HWW","f");leg[0]->AddEntry(h_WW_pt1,"WW","f");leg[0]->AddEntry(h_DY_pt1,"DY","f");leg[0]->AddEntry(h_TTTo2L2Nu_pt1,"TTTo2L2Nu","f");leg[0]->AddEntry(h_TTToSemileptonic_pt1,"TTToSemileptonic","f");leg[0]->AddEntry(h_ST_pt1,"ST","f");leg[0]->AddEntry(h_WJets_pt1,"WJets","f");leg[0]->Draw();
  can[0]->SaveAs("histogram_pt1_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");  
  THStack h_pt2("h_pt2","pt2"); can[1]->cd();
  h_HWW_pt2->SetFillColor(632); h_pt2.Add(h_HWW_pt2);h_WW_pt2->SetFillColor(851); h_pt2.Add(h_WW_pt2);h_DY_pt2->SetFillColor(418);  h_pt2.Add(h_DY_pt2);h_TTTo2L2Nu_pt2->SetFillColor(400);  h_pt2.Add(h_TTTo2L2Nu_pt2);h_TTToSemileptonic_pt2->SetFillColor(401);  h_pt2.Add(h_TTToSemileptonic_pt2);h_ST_pt2->SetFillColor(402);  h_pt2.Add(h_ST_pt2);h_WJets_pt2->SetFillColor(921);  h_pt2.Add(h_WJets_pt2);
  h_pt2.Draw("histo");  h_pt2.GetXaxis()->SetTitle("pt2 [GeV]");h_pt2.GetYaxis()->SetTitle("Entries");
  leg[1]->AddEntry(h_HWW_pt2,"HWW","f");leg[1]->AddEntry(h_WW_pt2,"WW","f");leg[1]->AddEntry(h_DY_pt2,"DY","f");leg[1]->AddEntry(h_TTTo2L2Nu_pt2,"TTTo2L2Nu","f");leg[1]->AddEntry(h_TTToSemileptonic_pt2,"TTToSemileptonic","f");leg[1]->AddEntry(h_ST_pt2,"ST","f");leg[1]->AddEntry(h_WJets_pt2,"WJets","f");leg[1]->Draw();
  can[1]->SaveAs("histogram_pt2_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
 THStack h_eta1("h_eta1","eta1"); can[2]->cd();
  h_HWW_eta1->SetFillColor(632); h_eta1.Add(h_HWW_eta1);h_WW_eta1->SetFillColor(851); h_eta1.Add(h_WW_eta1);h_DY_eta1->SetFillColor(418);  h_eta1.Add(h_DY_eta1);h_TTTo2L2Nu_eta1->SetFillColor(400);  h_eta1.Add(h_TTTo2L2Nu_eta1);h_TTToSemileptonic_eta1->SetFillColor(401);  h_eta1.Add(h_TTToSemileptonic_eta1);h_ST_eta1->SetFillColor(402);  h_eta1.Add(h_ST_eta1);h_WJets_eta1->SetFillColor(921);  h_eta1.Add(h_WJets_eta1);  
  h_eta1.Draw("histo");  h_eta1.GetXaxis()->SetTitle("eta1");h_eta1.GetYaxis()->SetTitle("Entries");
  leg[2]->AddEntry(h_HWW_eta1,"HWW","f");leg[2]->AddEntry(h_WW_eta1,"WW","f");leg[2]->AddEntry(h_DY_eta1,"DY","f");leg[2]->AddEntry(h_TTTo2L2Nu_eta1,"TTTo2L2Nu","f");leg[2]->AddEntry(h_TTToSemileptonic_eta1,"TTToSemileptonic","f");leg[2]->AddEntry(h_ST_eta1,"ST","f");leg[2]->AddEntry(h_WJets_eta1,"WJets","f");leg[2]->Draw();
  can[2]->SaveAs("histogram_eta1_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
  THStack h_eta2("h_eta2","eta2"); can[3]->cd();
  h_HWW_eta2->SetFillColor(632); h_eta2.Add(h_HWW_eta2);h_WW_eta2->SetFillColor(851); h_eta2.Add(h_WW_eta2);h_DY_eta2->SetFillColor(418);  h_eta2.Add(h_DY_eta2);h_TTTo2L2Nu_eta2->SetFillColor(400);  h_eta2.Add(h_TTTo2L2Nu_eta2);h_TTToSemileptonic_eta2->SetFillColor(401);  h_eta2.Add(h_TTToSemileptonic_eta2);h_ST_eta2->SetFillColor(402);  h_eta2.Add(h_ST_eta2);h_WJets_eta2->SetFillColor(921);  h_eta2.Add(h_WJets_eta2);  
  h_eta2.Draw("histo");  h_eta2.GetXaxis()->SetTitle("eta2");h_eta2.GetYaxis()->SetTitle("Entries");
  leg[3]->AddEntry(h_HWW_eta2,"HWW","f");leg[3]->AddEntry(h_WW_eta2,"WW","f");leg[3]->AddEntry(h_DY_eta2,"DY","f");leg[3]->AddEntry(h_TTTo2L2Nu_eta2,"TTTo2L2Nu","f");leg[3]->AddEntry(h_TTToSemileptonic_eta2,"TTToSemileptonic","f");leg[3]->AddEntry(h_ST_eta2,"ST","f");leg[3]->AddEntry(h_WJets_eta2,"WJets","f");leg[3]->Draw();
  can[3]->SaveAs("histogram_eta2_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
  THStack h_MET_pt("h_MET_pt","MET_pt"); can[4]->cd();
  h_HWW_MET_pt->SetFillColor(632); h_MET_pt.Add(h_HWW_MET_pt);h_WW_MET_pt->SetFillColor(851); h_MET_pt.Add(h_WW_MET_pt);h_DY_MET_pt->SetFillColor(418);  h_MET_pt.Add(h_DY_MET_pt);h_TTTo2L2Nu_MET_pt->SetFillColor(400);  h_MET_pt.Add(h_TTTo2L2Nu_MET_pt);h_TTToSemileptonic_MET_pt->SetFillColor(401);  h_MET_pt.Add(h_TTToSemileptonic_MET_pt);h_ST_MET_pt->SetFillColor(402);  h_MET_pt.Add(h_ST_MET_pt);h_WJets_MET_pt->SetFillColor(921);  h_MET_pt.Add(h_WJets_MET_pt);
  h_MET_pt.Draw("histo");  h_MET_pt.GetXaxis()->SetTitle("MET_pt [GeV]");h_MET_pt.GetYaxis()->SetTitle("Entries");
  leg[4]->AddEntry(h_HWW_MET_pt,"HWW","f");leg[4]->AddEntry(h_WW_MET_pt,"WW","f");leg[4]->AddEntry(h_DY_MET_pt,"DY","f");leg[4]->AddEntry(h_TTTo2L2Nu_MET_pt,"TTTo2L2Nu","f");leg[4]->AddEntry(h_TTToSemileptonic_MET_pt,"TTToSemileptonic","f");leg[4]->AddEntry(h_ST_MET_pt,"ST","f");leg[4]->AddEntry(h_WJets_MET_pt,"WJets","f");leg[4]->Draw();
  can[4]->SaveAs("histogram_MET_pt_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
  THStack h_mpmet("h_mpmet","mpmet"); can[5]->cd();
  h_HWW_mpmet->SetFillColor(632); h_mpmet.Add(h_HWW_mpmet);h_WW_mpmet->SetFillColor(851); h_mpmet.Add(h_WW_mpmet);h_DY_mpmet->SetFillColor(418);  h_mpmet.Add(h_DY_mpmet);h_TTTo2L2Nu_mpmet->SetFillColor(400);  h_mpmet.Add(h_TTTo2L2Nu_mpmet);h_TTToSemileptonic_mpmet->SetFillColor(401);  h_mpmet.Add(h_TTToSemileptonic_mpmet);h_ST_mpmet->SetFillColor(402);  h_mpmet.Add(h_ST_mpmet);h_WJets_mpmet->SetFillColor(921);  h_mpmet.Add(h_WJets_mpmet);
  h_mpmet.Draw("histo");  h_mpmet.GetXaxis()->SetTitle("mpmet [GeV]");h_mpmet.GetYaxis()->SetTitle("Entries");
  leg[5]->AddEntry(h_HWW_mpmet,"HWW","f");leg[5]->AddEntry(h_WW_mpmet,"WW","f");leg[5]->AddEntry(h_DY_mpmet,"DY","f");leg[5]->AddEntry(h_TTTo2L2Nu_mpmet,"TTTo2L2Nu","f");leg[5]->AddEntry(h_TTToSemileptonic_mpmet,"TTToSemileptonic","f");leg[5]->AddEntry(h_ST_mpmet,"ST","f");leg[5]->AddEntry(h_WJets_mpmet,"WJets","f");leg[5]->Draw();
  can[5]->SaveAs("histogram_mpmet_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
  THStack h_mth("h_mth","mth"); can[6]->cd();
  h_HWW_mth->SetFillColor(632); h_mth.Add(h_HWW_mth);h_WW_mth->SetFillColor(851); h_mth.Add(h_WW_mth);h_DY_mth->SetFillColor(418);  h_mth.Add(h_DY_mth);h_TTTo2L2Nu_mth->SetFillColor(400);  h_mth.Add(h_TTTo2L2Nu_mth);h_TTToSemileptonic_mth->SetFillColor(401);  h_mth.Add(h_TTToSemileptonic_mth);h_ST_mth->SetFillColor(402);  h_mth.Add(h_ST_mth);h_WJets_mth->SetFillColor(921);  h_mth.Add(h_WJets_mth);
  h_mth.Draw("histo");  h_mth.GetXaxis()->SetTitle("mth [GeV]");h_mth.GetYaxis()->SetTitle("Entries");
  leg[6]->AddEntry(h_HWW_mth,"HWW","f");leg[6]->AddEntry(h_WW_mth,"WW","f");leg[6]->AddEntry(h_DY_mth,"DY","f");leg[6]->AddEntry(h_TTTo2L2Nu_mth,"TTTo2L2Nu","f");leg[6]->AddEntry(h_TTToSemileptonic_mth,"TTToSemileptonic","f");leg[6]->AddEntry(h_ST_mth,"ST","f");leg[6]->AddEntry(h_WJets_mth,"WJets","f");leg[6]->Draw();
  can[6]->SaveAs("histogram_mth_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
  THStack h_mtw2("h_mtw2","mtw2"); can[7]->cd();
  h_HWW_mtw2->SetFillColor(632); h_mtw2.Add(h_HWW_mtw2);h_WW_mtw2->SetFillColor(851); h_mtw2.Add(h_WW_mtw2);h_DY_mtw2->SetFillColor(418);  h_mtw2.Add(h_DY_mtw2);h_TTTo2L2Nu_mtw2->SetFillColor(400);  h_mtw2.Add(h_TTTo2L2Nu_mtw2);h_TTToSemileptonic_mtw2->SetFillColor(401);  h_mtw2.Add(h_TTToSemileptonic_mtw2);h_ST_mtw2->SetFillColor(402);  h_mtw2.Add(h_ST_mtw2);h_WJets_mtw2->SetFillColor(921);  h_mtw2.Add(h_WJets_mtw2);
  h_mtw2.Draw("histo");  h_mtw2.GetXaxis()->SetTitle("mtw2 [GeV]");h_mtw2.GetYaxis()->SetTitle("Entries");
  leg[7]->AddEntry(h_HWW_mtw2,"HWW","f");leg[7]->AddEntry(h_WW_mtw2,"WW","f");leg[7]->AddEntry(h_DY_mtw2,"DY","f");leg[7]->AddEntry(h_TTTo2L2Nu_mtw2,"TTTo2L2Nu","f");leg[7]->AddEntry(h_TTToSemileptonic_mtw2,"TTToSemileptonic","f");leg[7]->AddEntry(h_ST_mtw2,"ST","f");leg[7]->AddEntry(h_WJets_mtw2,"WJets","f");leg[7]->Draw();
  can[7]->SaveAs("histogram_mtw2_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
  THStack h_mll("h_mll","mll"); can[8]->cd();
  h_HWW_mll->SetFillColor(632); h_mll.Add(h_HWW_mll);h_WW_mll->SetFillColor(851); h_mll.Add(h_WW_mll);h_DY_mll->SetFillColor(418);  h_mll.Add(h_DY_mll);h_TTTo2L2Nu_mll->SetFillColor(400);  h_mll.Add(h_TTTo2L2Nu_mll);h_TTToSemileptonic_mll->SetFillColor(401);  h_mll.Add(h_TTToSemileptonic_mll);h_ST_mll->SetFillColor(402);  h_mll.Add(h_ST_mll);h_WJets_mll->SetFillColor(921);  h_mll.Add(h_WJets_mll);
  h_mll.Draw("histo");  h_mll.GetXaxis()->SetTitle("m_ll [GeV]");h_mll.GetYaxis()->SetTitle("Entries");
  leg[8]->AddEntry(h_HWW_mll,"HWW","f");leg[8]->AddEntry(h_WW_mll,"WW","f");leg[8]->AddEntry(h_DY_mll,"DY","f");leg[8]->AddEntry(h_TTTo2L2Nu_mll,"TTTo2L2Nu","f");leg[8]->AddEntry(h_TTToSemileptonic_mll,"TTToSemileptonic","f");leg[8]->AddEntry(h_ST_mll,"ST","f");leg[8]->AddEntry(h_WJets_mll,"WJets","f");leg[8]->Draw();
  can[8]->SaveAs("histogram_mll_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
  THStack h_ptll("h_ptll","ptll"); can[9]->cd();
  h_HWW_ptll->SetFillColor(632); h_ptll.Add(h_HWW_ptll);h_WW_ptll->SetFillColor(851); h_ptll.Add(h_WW_ptll);h_DY_ptll->SetFillColor(418);  h_ptll.Add(h_DY_ptll);h_TTTo2L2Nu_ptll->SetFillColor(400);  h_ptll.Add(h_TTTo2L2Nu_ptll);h_TTToSemileptonic_ptll->SetFillColor(401);  h_ptll.Add(h_TTToSemileptonic_ptll);h_ST_ptll->SetFillColor(402);  h_ptll.Add(h_ST_ptll);h_WJets_ptll->SetFillColor(921);  h_ptll.Add(h_WJets_ptll);
  h_ptll.Draw("histo");  h_ptll.GetXaxis()->SetTitle("pt_ll [GeV]");h_ptll.GetYaxis()->SetTitle("Entries");
  leg[9]->AddEntry(h_HWW_ptll,"HWW","f");leg[9]->AddEntry(h_WW_ptll,"WW","f");leg[9]->AddEntry(h_DY_ptll,"DY","f");leg[9]->AddEntry(h_TTTo2L2Nu_ptll,"TTTo2L2Nu","f");leg[9]->AddEntry(h_TTToSemileptonic_ptll,"TTToSemileptonic","f");leg[9]->AddEntry(h_ST_ptll,"ST","f");leg[9]->AddEntry(h_WJets_ptll,"WJets","f");leg[9]->Draw();
  can[9]->SaveAs("histogram_ptll_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");
  THStack h_dphill("h_dphill","dphill"); can[10]->cd();
  h_HWW_dphill->SetFillColor(632); h_dphill.Add(h_HWW_dphill);h_WW_dphill->SetFillColor(851); h_dphill.Add(h_WW_dphill);h_DY_dphill->SetFillColor(418);  h_dphill.Add(h_DY_dphill);h_TTTo2L2Nu_dphill->SetFillColor(400);  h_dphill.Add(h_TTTo2L2Nu_dphill);h_TTToSemileptonic_dphill->SetFillColor(401);  h_dphill.Add(h_TTToSemileptonic_dphill);h_ST_dphill->SetFillColor(402);  h_dphill.Add(h_ST_dphill);h_WJets_dphill->SetFillColor(921);  h_dphill.Add(h_WJets_dphill);
  h_dphill.Draw("histo");  h_dphill.GetXaxis()->SetTitle("dphi_ll");h_dphill.GetYaxis()->SetTitle("Entries");
  leg[10]->AddEntry(h_HWW_dphill,"HWW","f");leg[10]->AddEntry(h_WW_dphill,"WW","f");leg[10]->AddEntry(h_DY_dphill,"DY","f");leg[10]->AddEntry(h_TTTo2L2Nu_dphill,"TTTo2L2Nu","f");leg[10]->AddEntry(h_TTToSemileptonic_dphill,"TTToSemileptonic","f");leg[10]->AddEntry(h_ST_dphill,"ST","f");leg[10]->AddEntry(h_WJets_dphill,"WJets","f");leg[10]->Draw();can[10]->SaveAs("histogram_dphill_electronWP_"+electronWP+"_"+channel+"_pt2cut_"+pt2_cut+"_"+njet+".png");

}
