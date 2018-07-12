//root -l -q -b "Higgs_muonWP.C(\"nanoLatino_GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight\", \"mm\", \"5\")"

#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;


void Higgs_muonWP(TString sample, TString muonWP, TString channel, TString cutLevel) {


  //  Int_t MaxEvents = 200000;

  const Double_t MUON_MASS     = 0.106;     // [GeV]
  const Double_t ELECTRON_MASS = 0.000511;  // [GeV]
  const Double_t lumi = 41.3; // [fb-1]

  // Import the nanoLatino Tree
  //--------------------------------------------------------------------------------------------------------------------------------------
  TChain* tree = new TChain("Events");

  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW__hadd/";

  TString file = "";

  file = myFolder + sample + ".root";
  tree->Add(file);
  
  for (int i=0; i<=20; i++){
    TString index [21] = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
    file = myFolder + sample + "__part" + index[i] + ".root";
    tree->Add(file);
  }



  // Import the variables
  //--------------------------------------------------------------------------------------------------------------------------------------
  Int_t nLepton;
  tree->SetBranchAddress("nLepton",&nLepton);
  Int_t nCleanJet;
  tree->SetBranchAddress("nCleanJet",&nCleanJet);
 
  Int_t Lepton_muonIdx[20];
  tree->SetBranchAddress("Lepton_muonIdx",&Lepton_muonIdx);
  Int_t Lepton_electronIdx[20];
  tree->SetBranchAddress("Lepton_electronIdx",&Lepton_electronIdx);
  Int_t CleanJet_jetIdx[20];
  tree->SetBranchAddress("CleanJet_jetIdx",&CleanJet_jetIdx);

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
  Float_t MET_phi;
  tree->SetBranchAddress("MET_phi",&MET_phi);
  Float_t TkMET_pt;
  tree->SetBranchAddress("TkMET_pt",&TkMET_pt);
  Float_t TkMET_phi;
  tree->SetBranchAddress("TkMET_phi",&TkMET_phi);
  Float_t Jet_btagCSVV2[20];
  tree->SetBranchAddress("Jet_btagCSVV2",&Jet_btagCSVV2);
  Float_t CleanJet_pt[20];
  tree->SetBranchAddress("CleanJet_pt",&CleanJet_pt);
  Float_t puWeight;
  tree->SetBranchAddress("puWeight",&puWeight);
  Float_t baseW;
  tree->SetBranchAddress("baseW",&baseW);
  Float_t Generator_weight;
  tree->SetBranchAddress("Generator_weight",&Generator_weight);

  TLorentzVector lep1;
  TLorentzVector lep2;
  TLorentzVector ll;
  TLorentzVector MET;
  TLorentzVector trkMET;
  Float_t mass_1;
  Float_t mass_2;
  Float_t event_weight;
  Float_t dphil1trkmet;
  Float_t dphil2trkmet;
  Float_t dphiltrkmet;
  Float_t dphil1met;
  Float_t dphil2met;
  Float_t dphilmet;
  Float_t fullpmet;
  Float_t trkpmet;
  Float_t mpmet;
  Int_t find_lep1;
  Int_t find_lep2;
  Int_t lep1Idx;
  Int_t lep2Idx;
  Int_t temp_value;



  // Create the output histograms
  //--------------------------------------------------------------------------------------------------------------------------------------
  TH1F* h_counter_pass = new TH1F("h_counter_pass","h_counter_pass",1,0,9999);
  TH1F* h_pt1 = new TH1F("h_pt1","h_pt1",40,0,300);
  TH1F* h_pt2 = new TH1F("h_pt2","h_pt2",40,0,150);
  TH1F* h_eta1 = new TH1F("h_eta1","h_eta1",40,-TMath::Pi(),TMath::Pi());
  TH1F* h_eta2 = new TH1F("h_eta2","h_eta2",40,-TMath::Pi(),TMath::Pi());
  TH1F* h_MET_pt = new TH1F("h_MET_pt","h_MET_pt",40,0,300);
  TH1F* h_mpmet = new TH1F("h_mpmet","h_mpmet",40,0,150);
  TH1F* h_mll = new TH1F("h_mll","h_mll",40,0,200);
  TH1F* h_ptll = new TH1F("h_ptll","h_ptll",40,0,200);
  TH1F* h_dphill = new TH1F("h_dphill","h_dphill",40,0,TMath::Pi());


  // Loop over the tree events
  //--------------------------------------------------------------------------------------------------------------------------------------
  for (int j = 0; j < tree->GetEntries(); ++j){
    tree->GetEntry(j);


     // if(j > MaxEvents){
     //   cout << "finished for " << MaxEvents << " events" << endl;
     //   break;
     // }


     if(nLepton<2){continue;}
     



     //------------------------------ Check the muon WP (select the objets) --------------------------------------


     if(channel == "mm"){ //Different flavor channel: Reject ee and mm channels

       find_lep1 = 0;
       find_lep2 = 0;
       lep1Idx = 0;

       for(int k = 0; k < nLepton - 1; k++){
	 
	 if(Lepton_muonIdx[k] >= 0){
	   
	   if(muonWP == "Medium"){
	     if(Lepton_isTightMuon_cut_Medium80x[k] == 1){find_lep1=1; lep1Idx=k; break;}
	   }else if(muonWP == "Medium_HWW"){
	     if(Lepton_isTightMuon_cut_Medium80x[k] == 1 && Muon_dxy[Lepton_muonIdx[k]] < 0.02 && Muon_dz[Lepton_muonIdx[k]] < 0.1){find_lep1=1; lep1Idx=k; break;}
	   }else if(muonWP == "Tight"){
	     if(Lepton_isTightMuon_cut_Tight80x[k] == 1){find_lep1=1; lep1Idx=k; break;}
	   }else if(muonWP == "Tight_HWW"){
	     if(Lepton_isTightMuon_cut_Tight80x_HWWW[k] == 1){find_lep1=1; lep1Idx=k; break;}
	   }else{
	     cout << "muonWP options: Medium, Tight, Tight_HWW" << endl;
	     break;
	   }
	   
	 }
	
       }


       if(find_lep1 == 0){continue;}       
       

       for(int m = lep1Idx + 1; m < nLepton; m++){
	 
	 if(Lepton_muonIdx[m] >= 0){
	   
	   if(muonWP == "Medium"){
	     if(Lepton_isTightMuon_cut_Medium80x[m] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(muonWP == "Medium_HWW"){
	     if(Lepton_isTightMuon_cut_Medium80x[m] == 1 && Muon_dxy[Lepton_muonIdx[m]] < 0.02 && Muon_dz[Lepton_muonIdx[m]] < 0.1){find_lep2=1; lep2Idx = m; break;}
	   }else if(muonWP == "Tight"){
	     if(Lepton_isTightMuon_cut_Tight80x[m] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(muonWP == "Tight_HWW"){
	     if(Lepton_isTightMuon_cut_Tight80x_HWWW[m] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else{
	     cout << "muonWP options: Medium, Tight, Tight_HWW" << endl;
	     break;
	   }
	   
	 }
	
       }

       if(find_lep2 == 0){continue;}       

     }






     if(channel == "em"){
       
       find_lep1 = 0;
       find_lep2 = 0;

       for(int k = 0; k < nLepton; k++){
	 //here you can require a tigher electron WP than the default looseWP one
	 if(Lepton_electronIdx[k] >= 0){
	   find_lep1=1;
	   lep1Idx=k;
	   break;
	 }
	   
       }
       
       if(find_lep1==0){continue;}


       for(int m = 0; m < nLepton; m++){
	 
	 if(Lepton_muonIdx[m] >= 0){
	   
	   if(muonWP == "Medium"){
	     if(Lepton_isTightMuon_cut_Medium80x[m] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(muonWP == "Medium_HWW"){
	     if(Lepton_isTightMuon_cut_Medium80x[m] == 1 && Muon_dxy[Lepton_muonIdx[m]] < 0.02 && Muon_dz[Lepton_muonIdx[m]] < 0.1){find_lep2=1; lep2Idx = m; break;}
	   }else if(muonWP == "Tight"){
	     if(Lepton_isTightMuon_cut_Tight80x[m] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(muonWP == "Tight_HWW"){
	     if(Lepton_isTightMuon_cut_Tight80x_HWWW[m] == 1){find_lep2=1; lep2Idx = m;break;}
	   }else{
	     cout << "muonWP options: Medium, Tight, Tight_HWW" << endl;
	     break;
	   }
	   
	 }
	
       }

       if(find_lep2 == 0){continue;}       
       

       // PT ORDERING (in case pt[m] > pt[k])
       
       if(Lepton_pt[lep2Idx] > Lepton_pt[lep1Idx]){
	 temp_value = lep2Idx;
	 lep1Idx = lep2Idx;
	 lep2Idx = temp_value;
       }

     }






     //------------------------------ Preselection --------------------------------------

     if(Lepton_pt[lep1Idx] < 20 || Lepton_pt[lep2Idx] < 10){continue;}
     


     //------------------------------ Built the dilepton system --------------------------------------

     mass_1 = -9999;
     mass_2 = -9999;

     if (Lepton_electronIdx[lep1Idx] >= 0){
       mass_1   = ELECTRON_MASS;
     }
     else if (Lepton_muonIdx[lep1Idx] >= 0){
       mass_1     = MUON_MASS;
     }
     else{
       continue;  //lepton 1 is not electron / muon;
     }


     if (Lepton_electronIdx[lep2Idx] >= 0){
       mass_2   = ELECTRON_MASS;
     }
     else if (Lepton_muonIdx[lep2Idx] >= 0){
       mass_2     = MUON_MASS;
     }
     else{
       continue;  //lepton 2 is not electron / muon;
     }

     lep1.SetPtEtaPhiM(Lepton_pt[lep1Idx], Lepton_eta[lep1Idx], Lepton_phi[lep1Idx], mass_1); 
     lep2.SetPtEtaPhiM(Lepton_pt[lep2Idx], Lepton_eta[lep2Idx], Lepton_phi[lep2Idx], mass_2); 

     ll = lep1 + lep2;


     //------------------------------ Built mpmet --------------------------------------

     MET.SetPtEtaPhiM(MET_pt, 0.0, MET_phi, 0.0);
     trkMET.SetPtEtaPhiM(TkMET_pt, 0.0, TkMET_phi, 0.0);

     fullpmet = MET.Et();
     trkpmet  = trkMET.Et();

     dphil1trkmet = TMath::Abs(lep1.DeltaPhi(trkMET));
     dphil2trkmet = TMath::Abs(lep2.DeltaPhi(trkMET));
     dphiltrkmet  = TMath::Min(dphil1trkmet, dphil2trkmet);

     dphil1met = TMath::Abs(lep1.DeltaPhi(MET));
     dphil2met = TMath::Abs(lep2.DeltaPhi(MET));
     dphilmet  = TMath::Min(dphil1met, dphil2met);

     if (dphilmet    < TMath::Pi() / 2.) fullpmet *= TMath::Sin(dphilmet);
     if (dphiltrkmet < TMath::Pi() / 2.) trkpmet  *= TMath::Sin(dphiltrkmet);

     mpmet = TMath::Min(trkpmet, fullpmet);



     
     //------------------------------ Selection --------------------------------------

     if(cutLevel == "1" || cutLevel == "2" || cutLevel == "3" || cutLevel == "4" || cutLevel == "5" || cutLevel == "6"){
       if(nLepton > (lep2Idx + 1) && Lepton_pt[lep2Idx + 1] > 10){continue;}
     }
     if(cutLevel == "2" || cutLevel == "3" || cutLevel == "4" || cutLevel == "5" || cutLevel == "6"){
       if(ll.M() < 12){continue;}
     }
     if(cutLevel == "3" || cutLevel == "4" || cutLevel == "5" || cutLevel == "6"){
       if(nCleanJet>=1  && CleanJet_pt[0] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[0]] > 0.5803){continue;}
       if(nCleanJet>=2  && CleanJet_pt[1] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[1]] > 0.5803){continue;}
       if(nCleanJet>=3  && CleanJet_pt[2] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[2]] > 0.5803){continue;}
       if(nCleanJet>=4  && CleanJet_pt[3] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[3]] > 0.5803){continue;}
       if(nCleanJet>=5  && CleanJet_pt[4] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[4]] > 0.5803){continue;}
       if(nCleanJet>=6  && CleanJet_pt[5] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[5]] > 0.5803){continue;}
       if(nCleanJet>=7  && CleanJet_pt[6] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[6]] > 0.5803){continue;}
       if(nCleanJet>=8  && CleanJet_pt[7] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[7]] > 0.5803){continue;}
       if(nCleanJet>=9  && CleanJet_pt[8] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[8]] > 0.5803){continue;}
       if(nCleanJet>=10 && CleanJet_pt[9] > 20 && Jet_btagCSVV2[CleanJet_jetIdx[9]] > 0.5803){continue;}
     }
     if(cutLevel == "4" || cutLevel == "5" || cutLevel == "6"){
	if(ll.Pt() < 30){continue;}
     }
     if(cutLevel == "5" || cutLevel == "6"){
       if(MET_pt < 20){continue;}
     }
     if(cutLevel == "6"){
       if(mpmet < 20){continue;}
     }




    
     event_weight = puWeight * baseW * Generator_weight / TMath::Abs(Generator_weight) * lumi;

     h_counter_pass->Fill(1, event_weight);	        
     h_pt1->Fill(Lepton_pt[lep1Idx], event_weight);
     h_pt2->Fill(Lepton_pt[lep2Idx], event_weight);
     h_eta1->Fill(Lepton_eta[lep1Idx], event_weight);
     h_eta2->Fill(Lepton_eta[lep2Idx], event_weight);
     h_MET_pt->Fill(MET_pt, event_weight);
     h_mpmet->Fill(mpmet, event_weight);
     h_mll->Fill(ll.M(), event_weight);
     h_ptll->Fill(ll.Pt(), event_weight);
     h_dphill->Fill(lep1.DeltaPhi(lep2), event_weight);
    

  }
  



  // Save the results
  //--------------------------------------------------------------------------------------------------------------------------------------
  TFile output(sample + "_" + muonWP + "_"  + channel + "_cutLevel_" + cutLevel + ".root", "RECREATE");
  h_counter_pass->Write();
  h_pt1->Write();
  h_pt2->Write();
  h_eta1->Write();
  h_eta2->Write();
  h_MET_pt->Write();
  h_mpmet->Write();
  h_mll->Write();
  h_ptll->Write();
  h_dphill->Write();
  output.Close();




  //for check_jobs.sh

  cout << endl;
  cout << "-------- Done ---------";
  cout << endl;


}
