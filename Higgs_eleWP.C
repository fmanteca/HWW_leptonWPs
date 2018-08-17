//root -l -q -b "Higgs_eleWP.C(\"GluGluHToWWTo2L2NuPowheg_M125_private\",\"Tight_HWW\", \"em\", \"high\", \"0j\")"

#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;


void Higgs_eleWP(TString sample, TString eleWP, TString channel, TString pt2_cut, TString njet) {


  //Int_t MaxEvents = 1000;

  TFile* root_output = new TFile("/afs/cern.ch/work/f/fernanpe/CMSSW_10_1_0/src/jobs_output_ele/nanoLatino_" + sample + "_" + eleWP + "_" + channel + "_" + pt2_cut + "_" + njet + ".root", "recreate");
  
  const Double_t MUON_MASS     = 0.106;     // [GeV]
  const Double_t ELECTRON_MASS = 0.000511;  // [GeV]
  const Double_t lumi = 41.3; // [fb-1]
  
  // Import the nanoLatino Tree
  //--------------------------------------------------------------------------------------------------------------------------------------
  TChain* tree = new TChain("Events");

  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW__hadd/";

  TString file = "";

  file = myFolder + "nanoLatino_" +sample + ".root";
  cout<<file<<endl;
  if(ifstream(file))tree->Add(file);
  else cout<<"File not loaded"<<endl;
    
  // Import the variables
  //--------------------------------------------------------------------------------------------------------------------------------------
  Int_t nLepton;
  tree->SetBranchAddress("nLepton",&nLepton);
  Int_t nCleanJet;
  tree->SetBranchAddress("nCleanJet",&nCleanJet);
 
  Int_t Lepton_muonIdx[200];
  tree->SetBranchAddress("Lepton_muonIdx",&Lepton_muonIdx);
  Int_t Lepton_electronIdx[200];
  tree->SetBranchAddress("Lepton_electronIdx",&Lepton_electronIdx);
  Int_t CleanJet_jetIdx[200];
  tree->SetBranchAddress("CleanJet_jetIdx",&CleanJet_jetIdx);
  Int_t Lepton_pdgId[200];
  tree->SetBranchAddress("Lepton_pdgId",&Lepton_pdgId);

  Int_t Lepton_isTightMuon_cut_Medium80x[200];
  tree->SetBranchAddress("Lepton_isTightMuon_cut_Medium80x",&Lepton_isTightMuon_cut_Medium80x);
  Int_t Lepton_isTightMuon_cut_Tight80x[200];
  tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight80x",&Lepton_isTightMuon_cut_Tight80x);
  Int_t Lepton_isTightMuon_cut_Tight80x_HWWW[200];
  tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight80x_HWWW",&Lepton_isTightMuon_cut_Tight80x_HWWW);

  Int_t Lepton_isTightElectron_mvaFall17Iso[200];
  tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17Iso",&Lepton_isTightElectron_mvaFall17Iso);

  Bool_t Electron_mvaFall17Iso_WPL[200];
  tree->SetBranchAddress("Electron_mvaFall17Iso_WPL",&Electron_mvaFall17Iso_WPL);
  Bool_t Electron_mvaFall17Iso_WP80[200];
  tree->SetBranchAddress("Electron_mvaFall17Iso_WP80",&Electron_mvaFall17Iso_WP80);
  Bool_t Electron_mvaFall17Iso_WP90[200];
  tree->SetBranchAddress("Electron_mvaFall17Iso_WP90",&Electron_mvaFall17Iso_WP90);
  Bool_t Electron_mvaFall17noIso_WPL[200];
  tree->SetBranchAddress("Electron_mvaFall17noIso_WPL",&Electron_mvaFall17noIso_WPL);
  Bool_t Electron_mvaFall17noIso_WP80[200];
  tree->SetBranchAddress("Electron_mvaFall17noIso_WP80",&Electron_mvaFall17noIso_WP80);
  Bool_t Electron_mvaFall17noIso_WP90[200];
  tree->SetBranchAddress("Electron_mvaFall17noIso_WP90",&Electron_mvaFall17noIso_WP90);
  Int_t Electron_cutBased[200];
  tree->SetBranchAddress("Electron_cutBased",&Electron_cutBased);
  UChar_t Electron_lostHits[200];
  tree->SetBranchAddress("Electron_lostHits",&Electron_lostHits);
  Float_t Electron_dxy[200];
  tree->SetBranchAddress("Electron_dxy",&Electron_dxy);
  Float_t Electron_dz[200];
  tree->SetBranchAddress("Electron_dz",&Electron_dz);


  Float_t Muon_dxy[200];
  tree->SetBranchAddress("Muon_dxy",&Muon_dxy);
  Float_t Muon_dz[200];
  tree->SetBranchAddress("Muon_dz",&Muon_dz);
  Float_t Lepton_pt[200];
  tree->SetBranchAddress("Lepton_pt",&Lepton_pt);
  Float_t Lepton_eta[200];
  tree->SetBranchAddress("Lepton_eta",&Lepton_eta);
  Float_t Lepton_phi[200];
  tree->SetBranchAddress("Lepton_phi",&Lepton_phi);
  Float_t MET_pt;
  tree->SetBranchAddress("MET_pt",&MET_pt);
  Float_t MET_phi;
  tree->SetBranchAddress("MET_phi",&MET_phi);
  Float_t TkMET_pt;
  tree->SetBranchAddress("TkMET_pt",&TkMET_pt);
  Float_t TkMET_phi;
  tree->SetBranchAddress("TkMET_phi",&TkMET_phi);
  Float_t Jet_btagCSVV2[200];
  tree->SetBranchAddress("Jet_btagCSVV2",&Jet_btagCSVV2);
  Float_t CleanJet_pt[200];
  tree->SetBranchAddress("CleanJet_pt",&CleanJet_pt);
  Float_t CleanJet_eta[200];
  tree->SetBranchAddress("CleanJet_eta",&CleanJet_eta);
  Float_t puWeight;
  tree->SetBranchAddress("puWeight",&puWeight);
  Float_t baseW;
  tree->SetBranchAddress("baseW",&baseW);
  Float_t Generator_weight;
  tree->SetBranchAddress("Generator_weight",&Generator_weight);
  Int_t event;
  tree->SetBranchAddress("event",&event);

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
  Float_t dphillmet;
  Float_t mth;
  Float_t mtw2;
  Int_t find_lep1;
  Int_t find_lep2;
  Int_t lep1Idx;
  Int_t lep2Idx;
  Int_t temp_value;


  cout<<"Begin..."<<endl;

  // Create the output histograms
  //--------------------------------------------------------------------------------------------------------------------------------------
  TH1F* h_counter_pass_1 = new TH1F("h_counter_pass_1","h_counter_pass_1",1,-9999,9999);
  TH1F* h_counter_pass_2 = new TH1F("h_counter_pass_2","h_counter_pass_2",1,-9999,9999);
  TH1F* h_counter_pass_3 = new TH1F("h_counter_pass_3","h_counter_pass_3",1,-9999,9999);
  TH1F* h_counter_pass_4 = new TH1F("h_counter_pass_4","h_counter_pass_4",1,-9999,9999);
  TH1F* h_counter_pass_5 = new TH1F("h_counter_pass_5","h_counter_pass_5",1,-9999,9999);
  TH1F* h_counter_pass_6 = new TH1F("h_counter_pass_6","h_counter_pass_6",1,-9999,9999);
  TH1F* h_counter_pass_7 = new TH1F("h_counter_pass_7","h_counter_pass_7",1,-9999,9999);
  TH1F* h_counter_pass_8 = new TH1F("h_counter_pass_8","h_counter_pass_8",1,-9999,9999);
  TH1F* h_counter_pass_9 = new TH1F("h_counter_pass_9","h_counter_pass_9",1,-9999,9999);


  TH1F* h_pt1 = new TH1F("h_pt1","h_pt1",40,0,300);
  TH1F* h_pt2 = new TH1F("h_pt2","h_pt2",40,0,150);
  TH1F* h_eta1 = new TH1F("h_eta1","h_eta1",40,-TMath::Pi(),TMath::Pi());
  TH1F* h_eta2 = new TH1F("h_eta2","h_eta2",40,-TMath::Pi(),TMath::Pi());
  TH1F* h_MET_pt = new TH1F("h_MET_pt","h_MET_pt",40,0,300);
  TH1F* h_mpmet = new TH1F("h_mpmet","h_mpmet",40,0,150);
  TH1F* h_mth = new TH1F("h_mth","h_mth",40,0,300);
  TH1F* h_mtw2 = new TH1F("h_mtw2","h_mtw2",40,0,300);
  TH1F* h_mll = new TH1F("h_mll","h_mll",40,0,200);
  TH1F* h_ptll = new TH1F("h_ptll","h_ptll",40,0,200);
  TH1F* h_dphill = new TH1F("h_dphill","h_dphill",40,0,TMath::Pi());
  

  root_output->cd();  

  // Loop over the tree events
  //--------------------------------------------------------------------------------------------------------------------------------------
  for (int j = 0; j < tree->GetEntries(); ++j){
    tree->GetEntry(j);
    int nentries = tree->GetEntriesFast();
    if(fmod(j,100000)==0) Printf(" ..... event %d of %d", int(j), int(nentries));

     // if(j > MaxEvents){
     //   cout << "finished for " << MaxEvents << " events" << endl;
     //   break;
     // }

     //------------------------------ Pre-Preselection --------------------------------------

     if(nLepton<2){continue;}

     if(njet == "0j"){
       if(nCleanJet>=1 && (CleanJet_pt[0] > 30 || TMath::Abs(CleanJet_eta[0]) > 4.7)){continue;} //let pass the nCleanJet = 0 events
     }else if(njet == "1j"){
       if(nCleanJet == 0){ continue;}
       if(nCleanJet>=1 && (CleanJet_pt[0] < 30 || TMath::Abs(CleanJet_eta[0]) > 4.7)){continue;} // !0jet
       if(nCleanJet>=2 && CleanJet_pt[1] > 30){continue;}
     }
     

     //------------------------------ Check the electron WP (select the objets) --------------------------------------

     if(channel == "ee"){ //Different flavor channel: Reject ee and mm channels

       find_lep1 = 0;
       find_lep2 = 0;

       for(int k = 0; k < nLepton - 1; k++){
	 
	 if(Lepton_electronIdx[k] >= 0){
	   if(eleWP == "Tight_HWW"){
	     if(Lepton_eta[k] <= 1.479 && TMath::Abs(Electron_dz[Lepton_electronIdx[k]]) < 0.1 && TMath::Abs(Electron_dxy[Lepton_electronIdx[k]]) < 0.05 && Electron_cutBased[Lepton_electronIdx[k]] == 4 && Electron_lostHits[Lepton_electronIdx[k]] == 0){find_lep1=1; lep2Idx = k; break;}
	     else if(Lepton_eta[k] > 1.479 && TMath::Abs(Electron_dz[Lepton_electronIdx[k]]) < 0.2 && TMath::Abs(Electron_dxy[Lepton_electronIdx[k]]) < 0.1 && Electron_cutBased[Lepton_electronIdx[k]] == 4 && Electron_lostHits[Lepton_electronIdx[k]] == 0){find_lep1=1; lep2Idx = k; break;}
	   }else if(eleWP == "mvaFall17noIso_WPL"){
	     if(Electron_mvaFall17noIso_WPL[Lepton_electronIdx[k]] == 1){find_lep1=1; lep2Idx = k; break;}
	   }else if(eleWP == "mvaFall17Iso_WPL"){
	     if(Electron_mvaFall17Iso_WPL[Lepton_electronIdx[k]] == 1){find_lep1=1; lep2Idx = k; break;}
	   }else if(eleWP == "mvaFall17noIso_WP80"){
	     if(Electron_mvaFall17noIso_WP80[Lepton_electronIdx[k]] == 1){find_lep1=1; lep2Idx = k; break;}
	   }else if(eleWP == "mvaFall17Iso_WP80"){
	     if(Electron_mvaFall17Iso_WP80[Lepton_electronIdx[k]] == 1){find_lep1=1; lep2Idx = k; break;}
	   }else if(eleWP == "mvaFall17noIso_WP90"){
	     if(Electron_mvaFall17noIso_WP90[Lepton_electronIdx[k]] == 1){find_lep1=1; lep2Idx = k; break;}
	   }else if(eleWP == "mvaFall17Iso_WP90"){
	     if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[k]] == 1){find_lep1=1; lep2Idx = k; break;}
	   }else{
	     cout << "eleWP options: Medium, Tight, Tight_HWW" << endl;
	     break;
	   }
	   
	 }
	   	
       }


       if(find_lep1 == 0){continue;}       
       

       for(int m = lep1Idx + 1; m < nLepton; m++){
	 
	 if(Lepton_electronIdx[m] >= 0){
	   if(eleWP == "Tight_HWW"){
	     if(Lepton_eta[m] <= 1.479 && TMath::Abs(Electron_dz[Lepton_electronIdx[m]]) < 0.1 && TMath::Abs(Electron_dxy[Lepton_electronIdx[m]]) < 0.05 && Electron_cutBased[Lepton_electronIdx[m]] == 4 && Electron_lostHits[Lepton_electronIdx[m]] == 0){find_lep2=1; lep2Idx = m; break;}
	     else if(Lepton_eta[m] > 1.479 && TMath::Abs(Electron_dz[Lepton_electronIdx[m]]) < 0.2 && TMath::Abs(Electron_dxy[Lepton_electronIdx[m]]) < 0.1 && Electron_cutBased[Lepton_electronIdx[m]] == 4 && Electron_lostHits[Lepton_electronIdx[m]] == 0){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17noIso_WPL"){
	     if(Electron_mvaFall17noIso_WPL[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17Iso_WPL"){
	     if(Electron_mvaFall17Iso_WPL[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17noIso_WP80"){
	     if(Electron_mvaFall17noIso_WP80[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17Iso_WP80"){
	     if(Electron_mvaFall17Iso_WP80[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17noIso_WP90"){
	     if(Electron_mvaFall17noIso_WP90[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17Iso_WP90"){
	     if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else{
	     cout << "eleWP options: Medium, Tight, Tight_HWW" << endl;
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
	 // FIX the electron WP
	 if(Lepton_muonIdx[k] >= 0){
	   if(Lepton_isTightMuon_cut_Tight80x_HWWW[k] == 1){find_lep1=1; lep1Idx=k; break;}
	 }
       }
       
       if(find_lep1==0){continue;}




       for(int m = 0; m < nLepton; m++){
	 
	 if(Lepton_electronIdx[m] >= 0){
	   if(eleWP == "Tight_HWW"){
	     //	     cout << "Eta:" << Lepton_eta[m] << " dz: " << TMath::Abs(Electron_dz[Lepton_electronIdx[m]]) << " dxy: " << TMath::Abs(Electron_dxy[Lepton_electronIdx[m]]) << " cutBased: " <<  Electron_cutBased[Lepton_electronIdx[m]] << " lostHits: " << Electron_lostHits[Lepton_electronIdx[m]] << endl;
	     if(Lepton_eta[m] <= 1.479 && TMath::Abs(Electron_dz[Lepton_electronIdx[m]]) < 0.1 && TMath::Abs(Electron_dxy[Lepton_electronIdx[m]]) < 0.05 && Electron_cutBased[Lepton_electronIdx[m]] == 4 && Electron_lostHits[Lepton_electronIdx[m]] == 0){find_lep2=1; lep2Idx = m; break;}
	     else if(Lepton_eta[m] > 1.479 && TMath::Abs(Electron_dz[Lepton_electronIdx[m]]) < 0.2 && TMath::Abs(Electron_dxy[Lepton_electronIdx[m]]) < 0.1 && Electron_cutBased[Lepton_electronIdx[m]] == 4 && Electron_lostHits[Lepton_electronIdx[m]] == 0){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17noIso_WPL"){
	     if(Electron_mvaFall17noIso_WPL[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17Iso_WPL"){
	     if(Electron_mvaFall17Iso_WPL[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17noIso_WP80"){
	     if(Electron_mvaFall17noIso_WP80[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17Iso_WP80"){
	     if(Electron_mvaFall17Iso_WP80[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17noIso_WP90"){
	     if(Electron_mvaFall17noIso_WP90[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else if(eleWP == "mvaFall17Iso_WP90"){
	     if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[m]] == 1){find_lep2=1; lep2Idx = m; break;}
	   }else{
	     cout << "eleWP options: Medium, Tight, Tight_HWW" << endl;
	     break;
	   }
	   
	 }
	
       }


       if(find_lep2 == 0){continue;}       
       

       // PT ORDERING (in case pt[m] > pt[k])
       
       if(Lepton_pt[lep2Idx] > Lepton_pt[lep1Idx]){
	 temp_value = lep1Idx;
	 lep1Idx = lep2Idx;
	 lep2Idx = temp_value;
       }

     }



     //------------------------------ Preselection --------------------------------------

     if(TMath::Abs(Lepton_eta[lep1Idx]) > 2.4 || TMath::Abs(Lepton_eta[lep2Idx]) > 2.4){continue;}

     if(Lepton_pdgId[lep1Idx] * Lepton_pdgId[lep2Idx] > 0){continue;}

     if(pt2_cut == "high"){
       if(Lepton_pt[lep1Idx] < 25. || Lepton_pt[lep2Idx] < 20.){continue;}
     }else if (pt2_cut == "low"){
       if(Lepton_pt[lep1Idx] < 25. || Lepton_pt[lep2Idx] > 20. || Lepton_pt[lep2Idx] < 10.){continue;}
     }
     


     //------------------------------ Built the dilepton system --------------------------------------

     mass_1 = -9999;
     mass_2 = -9999;

     if (Lepton_electronIdx[lep1Idx] >= 0){
       mass_1   = ELECTRON_MASS;
     }
     else if (Lepton_muonIdx[lep1Idx] >= 0){
       mass_1     = MUON_MASS;
     }


     if (Lepton_electronIdx[lep2Idx] >= 0){
       mass_2   = ELECTRON_MASS;
     }
     else if (Lepton_muonIdx[lep2Idx] >= 0){
       mass_2     = MUON_MASS;
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


     //------------------------- Built mth and mtw2 ----------------------------------

     dphillmet = TMath::Abs(ll.DeltaPhi(MET));
     mth = TMath::Sqrt( 2. * ll.Pt() * MET.Pt() * (1. - TMath::Cos(dphillmet)));
     mtw2 = TMath::Sqrt( 2. * lep2.Pt() * MET.Pt() * (1. - TMath::Cos(dphil2met)));
      
     
     //------------------------------ Selection --------------------------------------

     //event_weight = puWeight * baseW * Generator_weight / TMath::Abs(Generator_weight) * lumi; //old 2016 latino weight
     event_weight = puWeight * baseW * Generator_weight * lumi;

     
     if(nLepton > (lep2Idx + 1) && Lepton_pt[lep2Idx + 1] > 10){continue;}
     h_counter_pass_1->Fill(1., event_weight);
     root_output->Write("",TObject::kOverwrite);
     
     if(ll.M() < 12.){continue;}
     h_counter_pass_2->Fill(1., event_weight);
     
     if(nCleanJet>=1  && CleanJet_pt[0] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[0]] > 0.5803){continue;}
     if(nCleanJet>=2  && CleanJet_pt[1] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[1]] > 0.5803){continue;}
     if(nCleanJet>=3  && CleanJet_pt[2] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[2]] > 0.5803){continue;}
     if(nCleanJet>=4  && CleanJet_pt[3] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[3]] > 0.5803){continue;}
     if(nCleanJet>=5  && CleanJet_pt[4] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[4]] > 0.5803){continue;}
     if(nCleanJet>=6  && CleanJet_pt[5] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[5]] > 0.5803){continue;}
     if(nCleanJet>=7  && CleanJet_pt[6] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[6]] > 0.5803){continue;}
     if(nCleanJet>=8  && CleanJet_pt[7] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[7]] > 0.5803){continue;}
     if(nCleanJet>=9  && CleanJet_pt[8] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[8]] > 0.5803){continue;}
     if(nCleanJet>=10 && CleanJet_pt[9] > 20. && Jet_btagCSVV2[CleanJet_jetIdx[9]] > 0.5803){continue;}
     h_counter_pass_3->Fill(1., event_weight);

     if(channel == "ee"){
       if(TMath::Abs(ll.M() - 91.188) < 15.){continue;}
       h_counter_pass_4->Fill(1., event_weight);
     }else if(channel == "em"){
       h_counter_pass_4->Fill(1., event_weight);
     }

     if(ll.Pt() < 30.){continue;}
     h_counter_pass_5->Fill(1., event_weight);

     if(MET.Et() < 20.){continue;}
     h_counter_pass_6->Fill(1., event_weight);

     if(mpmet < 20.){continue;}
     h_counter_pass_7->Fill(1., event_weight);
     
     if(mth < 60.){continue;}
     h_counter_pass_8->Fill(1., event_weight);

     if(mtw2 < 30.){continue;}
     h_counter_pass_9->Fill(1., event_weight);


     h_pt1->Fill(Lepton_pt[lep1Idx], event_weight);
     h_pt2->Fill(Lepton_pt[lep2Idx], event_weight);
     h_eta1->Fill(Lepton_eta[lep1Idx], event_weight);
     h_eta2->Fill(Lepton_eta[lep2Idx], event_weight);
     h_MET_pt->Fill(MET.Et(), event_weight);
     h_mpmet->Fill(mpmet, event_weight);
     h_mth->Fill(mth, event_weight);
     h_mtw2->Fill(mtw2, event_weight);
     h_mll->Fill(ll.M(), event_weight);
     h_ptll->Fill(ll.Pt(), event_weight);
     h_dphill->Fill(lep1.DeltaPhi(lep2), event_weight);
     
     //cout << event << endl; //for debuging
     
  }



  // h_counter_pass_1->Write();
  // h_counter_pass_2->Write();
  // h_counter_pass_3->Write();
  // h_counter_pass_4->Write();
  // h_counter_pass_5->Write();
  // h_counter_pass_6->Write();
  // h_counter_pass_7->Write();
  // h_counter_pass_8->Write();
  // h_counter_pass_9->Write();
  // h_pt1->Write();
  // h_pt2->Write();
  // h_eta1->Write();
  // h_eta2->Write();
  // h_MET_pt->Write();
  // h_mpmet->Write();
  // h_mth->Write();
  // h_mtw2->Write();
  // h_mll->Write();
  // h_ptll->Write();
  // h_dphill->Write();

  delete root_output;




  //for check_jobs.sh

  cout << endl;
  cout << "-------- Done ---------";
  cout << endl;


}
