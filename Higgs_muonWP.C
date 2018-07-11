//root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight\", \"mm\")"

#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;


void Higgs_muonWP(TString sample, TString muonWP, TString channel) {


  Int_t MaxEvents = 200000;

  const Double_t MUON_MASS     = 0.106;     // [GeV]
  const Double_t ELECTRON_MASS = 0.000511;  // [GeV]
  const Double_t lumi = 41.3; // [fb-1]

  // Import the nanoLatino Tree
  //--------------------------------------------------------------------------------------------------------------------------------------
  TChain* tree = new TChain("Events");

  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW/";

  TString file = "";

  file = myFolder + sample + "__part0.root";
  tree->Add(file);
  file = myFolder + sample + "__part1.root";
  tree->Add(file);
  file = myFolder + sample + "__part2.root";
  tree->Add(file);
  file = myFolder + sample + "__part3.root";
  tree->Add(file);
  file = myFolder + sample + "__part4.root";
  tree->Add(file);
  file = myFolder + sample + "__part5.root";
  tree->Add(file);
  file = myFolder + sample + "__part6.root";
  tree->Add(file);
  file = myFolder + sample + "__part7.root";
  tree->Add(file);
  file = myFolder + sample + "__part8.root";
  tree->Add(file);
  file = myFolder + sample + "__part9.root";
  tree->Add(file);
  file = myFolder + sample + "__part10.root";
  tree->Add(file);
  file = myFolder + sample + "__part11.root";
  tree->Add(file);



  // Import the variables
  //--------------------------------------------------------------------------------------------------------------------------------------
  Int_t nLepton;
  tree->SetBranchAddress("nLepton",&nLepton);
 
  Int_t Lepton_muonIdx[20];
  tree->SetBranchAddress("Lepton_muonIdx",&Lepton_muonIdx);
  Int_t Lepton_electronIdx[20];
  tree->SetBranchAddress("Lepton_electronIdx",&Lepton_electronIdx);

  Int_t Lepton_isTightMuon_cut_Medium80x[20];
  tree->SetBranchAddress("Lepton_isTightMuon_cut_Medium80x",&Lepton_isTightMuon_cut_Medium80x);
  Int_t Lepton_isTightMuon_cut_Tight80x[20];
  tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight80x",&Lepton_isTightMuon_cut_Tight80x);
  Int_t Lepton_isTightMuon_cut_Tight80x_HWWW[20];
  tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight80x_HWWW",&Lepton_isTightMuon_cut_Tight80x_HWWW);

  Int_t Lepton_isTightElectron_mvaFall17Iso[20];
  tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17Iso",&Lepton_isTightElectron_mvaFall17Iso);


  Float_t Muon_dxy[20];
  tree->SetBranchAddress("Muon_dxy",&Muon_dxy);
  Float_t Muon_dz[20];
  tree->SetBranchAddress("Muon_dz",&Muon_dz);
  Float_t Lepton_pt[20];
  tree->SetBranchAddress("Lepton_pt",&Lepton_pt);
  Float_t Lepton_eta[20];
  tree->SetBranchAddress("Lepton_eta",&Lepton_eta);
  Float_t Lepton_phi[20];
  tree->SetBranchAddress("Lepton_phi",&Lepton_phi);
  Float_t MET_pt;
  tree->SetBranchAddress("MET_pt",&MET_pt);
  Float_t Jet_btagCSVV2[20];
  tree->SetBranchAddress("Jet_btagCSVV2",&Jet_btagCSVV2);
  Float_t Jet_pt[20];
  tree->SetBranchAddress("Jet_pt",&Jet_pt);
  Float_t puWeight;
  tree->SetBranchAddress("puWeight",&puWeight);
  Float_t baseW;
  tree->SetBranchAddress("baseW",&baseW);
  Float_t Generator_weight;
  tree->SetBranchAddress("Generator_weight",&Generator_weight);

  TLorentzVector lep1;
  TLorentzVector lep2;
  TLorentzVector ll;
  Float_t mass_1;
  Float_t mass_2;
  Float_t event_weight;


  // Create the output histograms
  //--------------------------------------------------------------------------------------------------------------------------------------
  TH1F* h_counter_pass2Leploose = new TH1F("h_counter_pass2Leploose","h_counter_pass2Leploose",1,0,999999999);
  TH1F* h_counter_passWP = new TH1F("h_counter_passWP","h_counter_passWP",1,0,999999999);
  TH1F* h_pt1 = new TH1F("h_pt1","h_pt1",40,0,300);
  TH1F* h_pt2 = new TH1F("h_pt2","h_pt2",40,0,150);
  TH1F* h_eta1 = new TH1F("h_eta1","h_eta1",40,-TMath::Pi(),TMath::Pi());
  TH1F* h_eta2 = new TH1F("h_eta2","h_eta2",40,-TMath::Pi(),TMath::Pi());
  TH1F* h_MET_pt = new TH1F("h_MET_pt","h_MET_pt",40,0,300);
  TH1F* h_mll = new TH1F("h_mll","h_mll",40,0,200);
  TH1F* h_ptll = new TH1F("h_ptll","h_ptll",40,0,200);
  TH1F* h_dphill = new TH1F("h_dphill","h_dphill",40,0,TMath::Pi());


  // Loop over the tree events
  //--------------------------------------------------------------------------------------------------------------------------------------
  for (int j = 0; j < tree->GetEntries(); ++j){
  //for (int j = 0; j < 1000; ++j){
     tree->GetEntry(j);

     if(nLepton<2){continue;}

     if(j > MaxEvents){
       cout << "finished for " << MaxEvents << " events" << endl;
       break;
     }


     //------------------------------ Built the dilepton system --------------------------------------

     mass_1 = -9999;
     mass_2 = -9999;

     if (Lepton_electronIdx[0] >= 0){
       mass_1   = ELECTRON_MASS;
     }
     else if (Lepton_muonIdx[0] >= 0){
       mass_1     = MUON_MASS;
     }
     else{
       continue;  //lepton 1 is not electron / muon;
     }


     if (Lepton_electronIdx[1] >= 0){
       mass_2   = ELECTRON_MASS;
     }
     else if (Lepton_muonIdx[1] >= 0){
       mass_2     = MUON_MASS;
     }
     else{
       continue;  //lepton 2 is not electron / muon;
     }

     lep1.SetPtEtaPhiM(Lepton_pt[0], Lepton_eta[0], Lepton_phi[0], mass_1); 
     lep2.SetPtEtaPhiM(Lepton_pt[1], Lepton_eta[1], Lepton_phi[1], mass_2); 

     ll = lep1 + lep2;

     

     //------------------------------ Preselection --------------------------------------
     if(Lepton_pt[0]<20){continue;}
     
     event_weight = puWeight * baseW * Generator_weight / TMath::Abs(Generator_weight) * lumi;

     h_counter_pass2Leploose->Fill(j, event_weight); //counter: at least l2Loose, pt1 > 20 GeV


     
     //------------------------------ Selection --------------------------------------
     if(nLepton>2 && Lepton_pt[2]>10){continue;}
     if(MET_pt<20){continue;}
     if(ll.M() < 12){continue;}
     if(ll.Pt() < 30){continue;}
     if(Jet_pt[0] > 20 && Jet_btagCSVV2[0] > -0.5884){continue;} //Jet variables: to be checked



     //------------------------------ Check the muon WP --------------------------------------

     if(channel == "em"){ //Different flavor channel: Reject ee and mm channels
       if((Lepton_muonIdx[0] >= 0 && Lepton_muonIdx[1] >= 0) || (Lepton_electronIdx[0] >= 0 && Lepton_electronIdx[1] >= 0)){ continue;}
       
       if(Lepton_muonIdx[0] >= 0 && Lepton_electronIdx[1] >= 0){ //me
	 //if(Lepton_isTightElectron_mvaFall17Iso[1] !=1) {continue;}
	 
	 if(muonWP == "Medium"){
	   if(Lepton_isTightMuon_cut_Medium80x[0] != 1){continue;}
	 }else if(muonWP == "Medium_HWW"){
	   if(Lepton_isTightMuon_cut_Medium80x[0] != 1 || Muon_dxy[Lepton_muonIdx[0]] > 0.02 || Muon_dz[Lepton_muonIdx[0]] > 0.1){continue;}
	 }else if(muonWP == "Tight"){
	   if(Lepton_isTightMuon_cut_Tight80x[0] != 1){continue;}
	 }else if(muonWP == "Tight_HWW"){
	   if(Lepton_isTightMuon_cut_Tight80x_HWWW[0] != 1){continue;}
	 }else{
	   cout << "muonWP options: Medium, Tight, Tight_HWW" << endl;
	   break;
	 }
	 

       }else if(Lepton_muonIdx[1] >= 0 && Lepton_electronIdx[0] >= 0){ //em
	 //if(Lepton_isTightElectron_mvaFall17Iso[0] !=1) {continue;}
	 
	 if(muonWP == "Medium"){
	   if(Lepton_isTightMuon_cut_Medium80x[1] != 1){continue;}
	 }else if(muonWP == "Medium_HWW"){
	   if(Lepton_isTightMuon_cut_Medium80x[1] != 1 || Muon_dxy[Lepton_muonIdx[1]] > 0.02 || Muon_dz[Lepton_muonIdx[1]] > 0.1){continue;}
	 }else if(muonWP == "Tight"){
	   if(Lepton_isTightMuon_cut_Tight80x[1] != 1){continue;}
	 }else if(muonWP == "Tight_HWW"){
	   if(Lepton_isTightMuon_cut_Tight80x_HWWW[1] != 1){continue;}
	 }else{
	   cout << "muonWP options: Medium, Tight, Tight_HWW" << endl;
	   break;
	 }
       }

     }

       
     else if(channel == "mm"){ //Same flavor channel
       if(Lepton_muonIdx[0] < 0 || Lepton_muonIdx[1] < 0){ continue;}
       
       if(muonWP == "Medium"){
	 if(Lepton_isTightMuon_cut_Medium80x[0] != 1 || Lepton_isTightMuon_cut_Medium80x[1] != 1){continue;}
	 }else if(muonWP == "Medium_HWW"){
	   if(Lepton_isTightMuon_cut_Medium80x[0] != 1 || Lepton_isTightMuon_cut_Medium80x[1] != 1 || Muon_dxy[Lepton_muonIdx[0]] > 0.02 || Muon_dz[Lepton_muonIdx[0]] > 0.1 || Muon_dxy[Lepton_muonIdx[1]] > 0.02 || Muon_dz[Lepton_muonIdx[1]] > 0.1){continue;}
       }else if(muonWP == "Tight"){
	 if(Lepton_isTightMuon_cut_Tight80x[0] != 1 || Lepton_isTightMuon_cut_Tight80x[1] != 1){continue;}
       }else if(muonWP == "Tight_HWW"){
	 if(Lepton_isTightMuon_cut_Tight80x_HWWW[0] != 1 || Lepton_isTightMuon_cut_Tight80x_HWWW[1] != 1){continue;}
       }else{
	 cout << "muonWP options: Medium, Tight, Tight_HWW" << endl;
	 break;
       }
     }

     
     else{
       cout << "channel options: em, mm" << endl;
       break;
     }
     


     h_counter_passWP->Fill(j, event_weight);	        
     h_pt1->Fill(Lepton_pt[0], event_weight);
     h_pt2->Fill(Lepton_pt[1], event_weight);
     h_eta1->Fill(Lepton_eta[0], event_weight);
     h_eta2->Fill(Lepton_eta[1], event_weight);
     h_MET_pt->Fill(MET_pt, event_weight);
     h_mll->Fill(ll.M(), event_weight);
     h_ptll->Fill(ll.Pt(), event_weight);
     h_dphill->Fill(lep1.DeltaPhi(lep2), event_weight);
    

  }
  



  // Save the results
  //--------------------------------------------------------------------------------------------------------------------------------------
  TFile output(sample + "_" + muonWP + "_"  + channel + ".root", "RECREATE");
  h_counter_pass2Leploose->Write();
  h_counter_passWP->Write();
  h_pt1->Write();
  h_pt2->Write();
  h_eta1->Write();
  h_eta2->Write();
  h_MET_pt->Write();
  h_mll->Write();
  h_ptll->Write();
  h_dphill->Write();
  output.Close();

}
