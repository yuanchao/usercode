//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 20 11:47:04 2013 by ROOT version 5.32/00
// from TTree Delphes/Analysis tree
// found on file: TTbar_FCNC_140.root
//////////////////////////////////////////////////////////

#ifndef MyTcZAna_h
#define MyTcZAna_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>

#include <TRef.h>
#include <TRefArray.h>

#include <TStyle.h>
#include <TCanvas.h>

#include <TLorentzVector.h>
/* #include <TVector2.h> */
/* #include "Math/GenVector/VectorUtil.h" */
/* #include "Math/GenVector/PxPyPzE4D.h" */

/* #include "Math/Vector4D.h" */

/* #include <iostream> */
#include <fstream>
/* #include <sstream> */
/* #include <iomanip> */
#include "Riostream.h"

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>

std::string  vtx_cut_label[] = {"All", "Type", "Valid", "nDoF", "pT_sum",
				"abs_Z", "Rho"};
std::string  evt_cut_label[] = {"All  ","HLTrig", "Vertex", "2_lep", "one_Z",
				"3_lep.", //"Miss ET", 
				"one_W_Z", "2_Jet", "zero_b",
				"one_b", "2_Top", "Mass_cZ", "Mass_bW",
				"GEN_match"};
std::string  ele_cut_label[] = {"All", "GEN", "pT", "Eta", "Hi_pT", "Rel_ISO",
				"GEN", "EID", "DUMMY"};
std::string  mu_cut_label[] = {"All", "GEN", // "global", "tracker", 
			       "pT", "Eta", "High_pT", "Rel_ISO",
			       "GEN", "rel_iso", "DUMMY"};
std::string  jet_cut_label[] = {"All", "GEN", "pT", "Eta", "JetID", "LepIso",
				"GEN", "BTAG", "DUMMY"};


// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxEvent = 8;
const Int_t kMaxParticle = 32;
const Int_t kMaxTrack = 8192;
const Int_t kMaxTower = 9216;
const Int_t kMaxEFlowTrack = 256;
const Int_t kMaxEFlowTower = 256;
const Int_t kMaxEFlowMuon = 8;
const Int_t kMaxGenJet = 32;
const Int_t kMaxCAJet = 32;
const Int_t kMaxJet = 32;
const Int_t kMaxElectron = 16;
const Int_t kMaxPhoton = 16;
const Int_t kMaxMuon = 16;
const Int_t kMaxZee = 8;
const Int_t kMaxWuu = 8;
const Int_t kMaxTop = 8;
const Int_t kMaxMissingET = 8;
const Int_t kMaxScalarHT = 8;
const Int_t kMaxRho = 8;

class MyTcZAna {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   TTree          *skimTree;

   /* Double_t      Event_Weight; */
   Double_t      Event_Weight_Tot;

   // Declaration of leaf types
   Int_t           Event_;
   UInt_t          Event_fUniqueID[kMaxEvent];   //[Event_]
   UInt_t          Event_fBits[kMaxEvent];   //[Event_]
   Long64_t        Event_Number[kMaxEvent];   //[Event_]
   Float_t         Event_ReadTime[kMaxEvent];   //[Event_]
   Float_t         Event_ProcTime[kMaxEvent];   //[Event_]
   Int_t           Event_ProcessID[kMaxEvent];   //[Event_]
   Int_t           Event_MPI[kMaxEvent];   //[Event_]
   Float_t         Event_Weight[kMaxEvent];   //[Event_]
   Float_t         Event_Scale[kMaxEvent];   //[Event_]
   Float_t         Event_AlphaQED[kMaxEvent];   //[Event_]
   Float_t         Event_AlphaQCD[kMaxEvent];   //[Event_]
   Int_t           Event_ID1[kMaxEvent];   //[Event_]
   Int_t           Event_ID2[kMaxEvent];   //[Event_]
   Float_t         Event_X1[kMaxEvent];   //[Event_]
   Float_t         Event_X2[kMaxEvent];   //[Event_]
   Float_t         Event_ScalePDF[kMaxEvent];   //[Event_]
   Float_t         Event_PDF1[kMaxEvent];   //[Event_]
   Float_t         Event_PDF2[kMaxEvent];   //[Event_]
   Int_t           Event_size;
   Int_t           Particle_;
   UInt_t          Particle_fUniqueID[kMaxParticle];   //[Particle_]
   UInt_t          Particle_fBits[kMaxParticle];   //[Particle_]
   Int_t           Particle_PID[kMaxParticle];   //[Particle_]
   Int_t           Particle_Status[kMaxParticle];   //[Particle_]
   Int_t           Particle_IsPU[kMaxParticle];   //[Particle_]
   Int_t           Particle_M1[kMaxParticle];   //[Particle_]
   Int_t           Particle_M2[kMaxParticle];   //[Particle_]
   Int_t           Particle_D1[kMaxParticle];   //[Particle_]
   Int_t           Particle_D2[kMaxParticle];   //[Particle_]
   Int_t           Particle_Charge[kMaxParticle];   //[Particle_]
   Float_t         Particle_Mass[kMaxParticle];   //[Particle_]
   Float_t         Particle_E[kMaxParticle];   //[Particle_]
   Float_t         Particle_Px[kMaxParticle];   //[Particle_]
   Float_t         Particle_Py[kMaxParticle];   //[Particle_]
   Float_t         Particle_Pz[kMaxParticle];   //[Particle_]
   Float_t         Particle_PT[kMaxParticle];   //[Particle_]
   Float_t         Particle_Eta[kMaxParticle];   //[Particle_]
   Float_t         Particle_Phi[kMaxParticle];   //[Particle_]
   Float_t         Particle_Rapidity[kMaxParticle];   //[Particle_]
   Float_t         Particle_T[kMaxParticle];   //[Particle_]
   Float_t         Particle_X[kMaxParticle];   //[Particle_]
   Float_t         Particle_Y[kMaxParticle];   //[Particle_]
   Float_t         Particle_Z[kMaxParticle];   //[Particle_]
   TLorentzVector  Particle_P4[kMaxParticle];
   Int_t           Particle_size;
   Int_t           Track_;
   UInt_t          Track_fUniqueID[kMaxTrack];   //[Track_]
   UInt_t          Track_fBits[kMaxTrack];   //[Track_]
   Int_t           Track_PID[kMaxTrack];   //[Track_]
   Int_t           Track_Charge[kMaxTrack];   //[Track_]
   Float_t         Track_PT[kMaxTrack];   //[Track_]
   Float_t         Track_Eta[kMaxTrack];   //[Track_]
   Float_t         Track_Phi[kMaxTrack];   //[Track_]
   Float_t         Track_EtaOuter[kMaxTrack];   //[Track_]
   Float_t         Track_PhiOuter[kMaxTrack];   //[Track_]
   Float_t         Track_X[kMaxTrack];   //[Track_]
   Float_t         Track_Y[kMaxTrack];   //[Track_]
   Float_t         Track_Z[kMaxTrack];   //[Track_]
   Float_t         Track_XOuter[kMaxTrack];   //[Track_]
   Float_t         Track_YOuter[kMaxTrack];   //[Track_]
   Float_t         Track_ZOuter[kMaxTrack];   //[Track_]
   TRef            Track_Particle[kMaxTrack];
   Int_t           Track_size;
   Int_t           Tower_;
   UInt_t          Tower_fUniqueID[kMaxTower];   //[Tower_]
   UInt_t          Tower_fBits[kMaxTower];   //[Tower_]
   Float_t         Tower_ET[kMaxTower];   //[Tower_]
   Float_t         Tower_Eta[kMaxTower];   //[Tower_]
   Float_t         Tower_Phi[kMaxTower];   //[Tower_]
   Float_t         Tower_E[kMaxTower];   //[Tower_]
   Float_t         Tower_Eem[kMaxTower];   //[Tower_]
   Float_t         Tower_Ehad[kMaxTower];   //[Tower_]
   Float_t         Tower_Edges[kMaxTower][4];   //[Tower_]
   TRefArray       Tower_Particles[kMaxTower];
   Int_t           Tower_size;
   Int_t           EFlowTrack_;
   UInt_t          EFlowTrack_fUniqueID[kMaxEFlowTrack];   //[EFlowTrack_]
   UInt_t          EFlowTrack_fBits[kMaxEFlowTrack];   //[EFlowTrack_]
   Int_t           EFlowTrack_PID[kMaxEFlowTrack];   //[EFlowTrack_]
   Int_t           EFlowTrack_Charge[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_PT[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Eta[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Phi[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_EtaOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_PhiOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_X[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Y[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_Z[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_XOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_YOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   Float_t         EFlowTrack_ZOuter[kMaxEFlowTrack];   //[EFlowTrack_]
   TRef            EFlowTrack_Particle[kMaxEFlowTrack];
   Int_t           EFlowTrack_size;
   Int_t           EFlowTower_;
   UInt_t          EFlowTower_fUniqueID[kMaxEFlowTower];   //[EFlowTower_]
   UInt_t          EFlowTower_fBits[kMaxEFlowTower];   //[EFlowTower_]
   Float_t         EFlowTower_ET[kMaxEFlowTower];   //[EFlowTower_]
   Float_t         EFlowTower_Eta[kMaxEFlowTower];   //[EFlowTower_]
   Float_t         EFlowTower_Phi[kMaxEFlowTower];   //[EFlowTower_]
   Float_t         EFlowTower_E[kMaxEFlowTower];   //[EFlowTower_]
   Float_t         EFlowTower_Eem[kMaxEFlowTower];   //[EFlowTower_]
   Float_t         EFlowTower_Ehad[kMaxEFlowTower];   //[EFlowTower_]
   Float_t         EFlowTower_Edges[kMaxEFlowTower][4];   //[EFlowTower_]
   TRefArray       EFlowTower_Particles[kMaxEFlowTower];
   Int_t           EFlowTower_size;
   Int_t           EFlowMuon_;
   UInt_t          EFlowMuon_fUniqueID[kMaxEFlowMuon];   //[EFlowMuon_]
   UInt_t          EFlowMuon_fBits[kMaxEFlowMuon];   //[EFlowMuon_]
   Float_t         EFlowMuon_PT[kMaxEFlowMuon];   //[EFlowMuon_]
   Float_t         EFlowMuon_Eta[kMaxEFlowMuon];   //[EFlowMuon_]
   Float_t         EFlowMuon_Phi[kMaxEFlowMuon];   //[EFlowMuon_]
   Int_t           EFlowMuon_Charge[kMaxEFlowMuon];   //[EFlowMuon_]
   Float_t         EFlowMuon_IsolationVar[kMaxEFlowMuon];   //[EFlowMuon_]
   TRef            EFlowMuon_Particle[kMaxEFlowMuon];
   Int_t           EFlowMuon_size;
   Int_t           GenJet_;
   UInt_t          GenJet_fUniqueID[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_fBits[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PT[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Eta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Phi[kMaxGenJet];   //[GenJet_]
   TLorentzVector  GenJet_P4[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Mass[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaEta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaPhi[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_WTag[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_TopTag[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_HTag[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Tau1[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Tau2[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Tau3[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_NSubJets[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_MassDrop[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_TrimmedMass[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTag[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_TauTag[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_Charge[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_EhadOverEem[kMaxGenJet];   //[GenJet_]
   TRefArray       GenJet_Constituents[kMaxGenJet];
   TRefArray       GenJet_Particles[kMaxGenJet];
   Int_t           GenJet_size;
   Int_t           GenJet_No;
   Int_t           CAJet_;
   UInt_t          CAJet_fUniqueID[kMaxCAJet];   //[CAJet_]
   UInt_t          CAJet_fBits[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_PT[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_Eta[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_Phi[kMaxCAJet];   //[CAJet_]
   TLorentzVector  CAJet_P4[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_Mass[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_DeltaEta[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_DeltaPhi[kMaxCAJet];   //[CAJet_]
   UInt_t          CAJet_WTag[kMaxCAJet];   //[CAJet_]
   UInt_t          CAJet_TopTag[kMaxCAJet];   //[CAJet_]
   UInt_t          CAJet_HTag[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_Tau1[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_Tau2[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_Tau3[kMaxCAJet];   //[CAJet_]
   UInt_t          CAJet_NSubJets[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_MassDrop[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_TrimmedMass[kMaxCAJet];   //[CAJet_]
   UInt_t          CAJet_BTag[kMaxCAJet];   //[CAJet_]
   UInt_t          CAJet_TauTag[kMaxCAJet];   //[CAJet_]
   Int_t           CAJet_Charge[kMaxCAJet];   //[CAJet_]
   Float_t         CAJet_EhadOverEem[kMaxCAJet];   //[CAJet_]
   TRefArray       CAJet_Constituents[kMaxCAJet];
   TRefArray       CAJet_Particles[kMaxCAJet];
   Int_t           CAJet_size;
   Int_t           CAJet_No;
   Int_t           Jet_;
   UInt_t          Jet_fUniqueID[kMaxJet];   //[Jet_]
   UInt_t          Jet_fBits[kMaxJet];   //[Jet_]
   Float_t         Jet_PT[kMaxJet];   //[Jet_]
   Float_t         Jet_Eta[kMaxJet];   //[Jet_]
   Float_t         Jet_Phi[kMaxJet];   //[Jet_]
   TLorentzVector  Jet_P4[kMaxJet];   //[Jet_]
   Float_t         Jet_Mass[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaEta[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaPhi[kMaxJet];   //[Jet_]
   UInt_t          Jet_WTag[kMaxJet];   //[Jet_]
   UInt_t          Jet_TopTag[kMaxJet];   //[Jet_]
   UInt_t          Jet_HTag[kMaxJet];   //[Jet_]
   Float_t         Jet_Tau1[kMaxJet];   //[Jet_]
   Float_t         Jet_Tau2[kMaxJet];   //[Jet_]
   Float_t         Jet_Tau3[kMaxJet];   //[Jet_]
   UInt_t          Jet_NSubJets[kMaxJet];   //[Jet_]
   Float_t         Jet_MassDrop[kMaxJet];   //[Jet_]
   Float_t         Jet_TrimmedMass[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTag[kMaxJet];   //[Jet_]
   UInt_t          Jet_TauTag[kMaxJet];   //[Jet_]
   Int_t           Jet_Charge[kMaxJet];   //[Jet_]
   Float_t         Jet_EhadOverEem[kMaxJet];   //[Jet_]
   TRefArray       Jet_Constituents[kMaxJet];
   TRefArray       Jet_Particles[kMaxJet];
   Int_t           Jet_Good[kMaxJet];
   Int_t           Jet_GenMatch[kMaxJet];
   Int_t           Jet_size;
   Int_t           Jet_No;
   Int_t           Electron_;
   UInt_t          Electron_fUniqueID[kMaxElectron];   //[Electron_]
   UInt_t          Electron_fBits[kMaxElectron];   //[Electron_]
   Float_t         Electron_PT[kMaxElectron];   //[Electron_]
   Float_t         Electron_Eta[kMaxElectron];   //[Electron_]
   Float_t         Electron_Phi[kMaxElectron];   //[Electron_]
   TLorentzVector  Electron_P4[kMaxElectron];   //[Electron_]
   Int_t           Electron_Charge[kMaxElectron];   //[Electron_]
   Float_t         Electron_EhadOverEem[kMaxElectron];   //[Electron_]
   Float_t         Electron_IsolationVar[kMaxElectron];   //[Electron_]
   TRef            Electron_Particle[kMaxElectron];
   Int_t           Electron_Index[kMaxElectron];
   Int_t           Electron_GenMatch[kMaxElectron];
   Int_t           Electron_Good[kMaxElectron];
   Int_t           Electron_size;
   Int_t           Electron_No;
   Int_t           Photon_;
   UInt_t          Photon_fUniqueID[kMaxPhoton];   //[Photon_]
   UInt_t          Photon_fBits[kMaxPhoton];   //[Photon_]
   Float_t         Photon_PT[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Eta[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Phi[kMaxPhoton];   //[Photon_]
   Float_t         Photon_E[kMaxPhoton];   //[Photon_]
   TLorentzVector  Photon_P4[kMaxPhoton];   //[Photon_]
   Float_t         Photon_EhadOverEem[kMaxPhoton];   //[Photon_]
   Float_t         Photon_IsolationVar[kMaxPhoton];   //[Photon_]
   TRefArray       Photon_Particles[kMaxPhoton];
   Int_t           Photon_size;
   Int_t           Photon_No;
   Int_t           Muon_;
   UInt_t          Muon_fUniqueID[kMaxMuon];   //[Muon_]
   UInt_t          Muon_fBits[kMaxMuon];   //[Muon_]
   Float_t         Muon_PT[kMaxMuon];   //[Muon_]
   Float_t         Muon_Eta[kMaxMuon];   //[Muon_]
   Float_t         Muon_Phi[kMaxMuon];   //[Muon_]
   TLorentzVector  Muon_P4[kMaxMuon];   //[Muon_]
   Int_t           Muon_Charge[kMaxMuon];   //[Muon_]
   Float_t         Muon_IsolationVar[kMaxMuon];   //[Muon_]
   TRef            Muon_Particle[kMaxMuon];
   Int_t           Muon_Index[kMaxMuon];
   Int_t           Muon_GenMatch[kMaxMuon];
   Int_t           Muon_Good[kMaxMuon];
   Int_t           Muon_size;
   Int_t           Muon_No;
   Int_t           MissingET_;
   UInt_t          MissingET_fUniqueID[kMaxMissingET];   //[MissingET_]
   UInt_t          MissingET_fBits[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_MET[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Phi[kMaxMissingET];   //[MissingET_]
   Int_t           MissingET_size;
   Int_t           ScalarHT_;
   UInt_t          ScalarHT_fUniqueID[kMaxScalarHT];   //[ScalarHT_]
   UInt_t          ScalarHT_fBits[kMaxScalarHT];   //[ScalarHT_]
   Float_t         ScalarHT_HT[kMaxScalarHT];   //[ScalarHT_]
   Int_t           ScalarHT_size;
   Int_t           Rho_;
   UInt_t          Rho_fUniqueID[kMaxRho];   //[Rho_]
   UInt_t          Rho_fBits[kMaxRho];   //[Rho_]
   Float_t         Rho_HT[kMaxRho];   //[Rho_]
   Int_t           Rho_size;

   Int_t           Zee_No;
   Int_t           Zee_size;
   TLorentzVector  Zee_P4[kMaxZee];
   Double_t        Zee_Pt[kMaxZee];   //[Zee.No]
   Double_t        Zee_Eta[kMaxZee];   //[Zee.No]
   Double_t        Zee_Phi[kMaxZee];   //[Zee.No]
   Double_t        Zee_Px[kMaxZee];   //[Zee.No]
   Double_t        Zee_Py[kMaxZee];   //[Zee.No]
   Double_t        Zee_Pz[kMaxZee];   //[Zee.No]
   Double_t        Zee_Mass[kMaxZee];   //[Zee.No]
   Int_t           Zee_lid1[kMaxZee];   //[Zee.No]
   Int_t           Zee_lid2[kMaxZee];   //[Zee.No]
   Int_t           Zee_GenIdx[kMaxZee];   //[Zee.No]

   Int_t           Wuu_size;
   Int_t           Wuu_No;
   TLorentzVector  Wuu_P4[kMaxWuu];
   Double_t        Wuu_Pt[kMaxWuu];   //[Wuu.No]
   Double_t        Wuu_Px[kMaxWuu];   //[Wuu.No]
   Double_t        Wuu_Py[kMaxWuu];   //[Wuu.No]
   Double_t        Wuu_Pz[kMaxWuu];   //[Wuu.No]
   Double_t        Wuu_Mass[kMaxWuu];   //[Wuu.No]
   Double_t        Wuu_Mt[kMaxWuu];   //[Wuu.No]
   Double_t        Wuu_E[kMaxWuu];   //[Wuu.No]
   Int_t           Wuu_lid[kMaxWuu];   //[Wuu.No]
   Int_t           Wuu_GenIdx[kMaxWuu];   //[Wuu.No]

   Int_t           Top_size;
   Int_t           Top_No;
   TLorentzVector  Top_P4[kMaxTop];
   Double_t        Top_Pt[kMaxTop];   //[Top.No]
   Double_t        Top_Px[kMaxTop];   //[Top.No]
   Double_t        Top_Py[kMaxTop];   //[Top.No]
   Double_t        Top_Pz[kMaxTop];   //[Top.No]
   Double_t        Top_Mass[kMaxTop];   //[Top.No]
   Double_t        Top_Mt[kMaxTop];   //[Top.No]
   Int_t           Top_Type[kMaxTop];   //[Top.No]
   Double_t        Top_dPhi[kMaxTop];   //[Top.No]
   Int_t           Top_Jidx[kMaxTop];   //[Top.No]
   Int_t           Top_Vidx[kMaxTop];   //[Top.No]

   // List of branches
   TBranch        *b_Event_;   //!
   TBranch        *b_Event_fUniqueID;   //!
   TBranch        *b_Event_fBits;   //!
   TBranch        *b_Event_Number;   //!
   TBranch        *b_Event_ReadTime;   //!
   TBranch        *b_Event_ProcTime;   //!
   TBranch        *b_Event_ProcessID;   //!
   TBranch        *b_Event_MPI;   //!
   TBranch        *b_Event_Weight;   //!
   TBranch        *b_Event_Scale;   //!
   TBranch        *b_Event_AlphaQED;   //!
   TBranch        *b_Event_AlphaQCD;   //!
   TBranch        *b_Event_ID1;   //!
   TBranch        *b_Event_ID2;   //!
   TBranch        *b_Event_X1;   //!
   TBranch        *b_Event_X2;   //!
   TBranch        *b_Event_ScalePDF;   //!
   TBranch        *b_Event_PDF1;   //!
   TBranch        *b_Event_PDF2;   //!
   TBranch        *b_Event_size;   //!
   TBranch        *b_Particle_;   //!
   TBranch        *b_Particle_fUniqueID;   //!
   TBranch        *b_Particle_fBits;   //!
   TBranch        *b_Particle_PID;   //!
   TBranch        *b_Particle_Status;   //!
   TBranch        *b_Particle_IsPU;   //!
   TBranch        *b_Particle_M1;   //!
   TBranch        *b_Particle_M2;   //!
   TBranch        *b_Particle_D1;   //!
   TBranch        *b_Particle_D2;   //!
   TBranch        *b_Particle_Charge;   //!
   TBranch        *b_Particle_Mass;   //!
   TBranch        *b_Particle_E;   //!
   TBranch        *b_Particle_Px;   //!
   TBranch        *b_Particle_Py;   //!
   TBranch        *b_Particle_Pz;   //!
   TBranch        *b_Particle_PT;   //!
   TBranch        *b_Particle_Eta;   //!
   TBranch        *b_Particle_Phi;   //!
   TBranch        *b_Particle_Rapidity;   //!
   TBranch        *b_Particle_T;   //!
   TBranch        *b_Particle_X;   //!
   TBranch        *b_Particle_Y;   //!
   TBranch        *b_Particle_Z;   //!
   TBranch        *b_Particle_size;   //!
   TBranch        *b_Track_;   //!
   TBranch        *b_Track_fUniqueID;   //!
   TBranch        *b_Track_fBits;   //!
   TBranch        *b_Track_PID;   //!
   TBranch        *b_Track_Charge;   //!
   TBranch        *b_Track_PT;   //!
   TBranch        *b_Track_Eta;   //!
   TBranch        *b_Track_Phi;   //!
   TBranch        *b_Track_EtaOuter;   //!
   TBranch        *b_Track_PhiOuter;   //!
   TBranch        *b_Track_X;   //!
   TBranch        *b_Track_Y;   //!
   TBranch        *b_Track_Z;   //!
   TBranch        *b_Track_XOuter;   //!
   TBranch        *b_Track_YOuter;   //!
   TBranch        *b_Track_ZOuter;   //!
   TBranch        *b_Track_Particle;   //!
   TBranch        *b_Track_size;   //!
   TBranch        *b_Tower_;   //!
   TBranch        *b_Tower_fUniqueID;   //!
   TBranch        *b_Tower_fBits;   //!
   TBranch        *b_Tower_ET;   //!
   TBranch        *b_Tower_Eta;   //!
   TBranch        *b_Tower_Phi;   //!
   TBranch        *b_Tower_E;   //!
   TBranch        *b_Tower_Eem;   //!
   TBranch        *b_Tower_Ehad;   //!
   TBranch        *b_Tower_Edges;   //!
   TBranch        *b_Tower_Particles;   //!
   TBranch        *b_Tower_size;   //!
   TBranch        *b_EFlowTrack_;   //!
   TBranch        *b_EFlowTrack_fUniqueID;   //!
   TBranch        *b_EFlowTrack_fBits;   //!
   TBranch        *b_EFlowTrack_PID;   //!
   TBranch        *b_EFlowTrack_Charge;   //!
   TBranch        *b_EFlowTrack_PT;   //!
   TBranch        *b_EFlowTrack_Eta;   //!
   TBranch        *b_EFlowTrack_Phi;   //!
   TBranch        *b_EFlowTrack_EtaOuter;   //!
   TBranch        *b_EFlowTrack_PhiOuter;   //!
   TBranch        *b_EFlowTrack_X;   //!
   TBranch        *b_EFlowTrack_Y;   //!
   TBranch        *b_EFlowTrack_Z;   //!
   TBranch        *b_EFlowTrack_XOuter;   //!
   TBranch        *b_EFlowTrack_YOuter;   //!
   TBranch        *b_EFlowTrack_ZOuter;   //!
   TBranch        *b_EFlowTrack_Particle;   //!
   TBranch        *b_EFlowTrack_size;   //!
   TBranch        *b_EFlowTower_;   //!
   TBranch        *b_EFlowTower_fUniqueID;   //!
   TBranch        *b_EFlowTower_fBits;   //!
   TBranch        *b_EFlowTower_ET;   //!
   TBranch        *b_EFlowTower_Eta;   //!
   TBranch        *b_EFlowTower_Phi;   //!
   TBranch        *b_EFlowTower_E;   //!
   TBranch        *b_EFlowTower_Eem;   //!
   TBranch        *b_EFlowTower_Ehad;   //!
   TBranch        *b_EFlowTower_Edges;   //!
   TBranch        *b_EFlowTower_Particles;   //!
   TBranch        *b_EFlowTower_size;   //!
   TBranch        *b_EFlowMuon_;   //!
   TBranch        *b_EFlowMuon_fUniqueID;   //!
   TBranch        *b_EFlowMuon_fBits;   //!
   TBranch        *b_EFlowMuon_PT;   //!
   TBranch        *b_EFlowMuon_Eta;   //!
   TBranch        *b_EFlowMuon_Phi;   //!
   TBranch        *b_EFlowMuon_Charge;   //!
   TBranch        *b_EFlowMuon_IsolationVar;   //!
   TBranch        *b_EFlowMuon_Particle;   //!
   TBranch        *b_EFlowMuon_size;   //!
   TBranch        *b_GenJet_;   //!
   TBranch        *b_GenJet_fUniqueID;   //!
   TBranch        *b_GenJet_fBits;   //!
   TBranch        *b_GenJet_PT;   //!
   TBranch        *b_GenJet_Eta;   //!
   TBranch        *b_GenJet_Phi;   //!
   TBranch        *b_GenJet_Mass;   //!
   TBranch        *b_GenJet_DeltaEta;   //!
   TBranch        *b_GenJet_DeltaPhi;   //!
   TBranch        *b_GenJet_WTag;   //!
   TBranch        *b_GenJet_TopTag;   //!
   TBranch        *b_GenJet_HTag;   //!
   TBranch        *b_GenJet_Tau1;   //!
   TBranch        *b_GenJet_Tau2;   //!
   TBranch        *b_GenJet_Tau3;   //!
   TBranch        *b_GenJet_NSubJets;   //!
   TBranch        *b_GenJet_MassDrop;   //!
   TBranch        *b_GenJet_TrimmedMass;   //!
   TBranch        *b_GenJet_BTag;   //!
   TBranch        *b_GenJet_TauTag;   //!
   TBranch        *b_GenJet_Charge;   //!
   TBranch        *b_GenJet_EhadOverEem;   //!
   TBranch        *b_GenJet_Constituents;   //!
   TBranch        *b_GenJet_Particles;   //!
   TBranch        *b_GenJet_size;   //!
   TBranch        *b_CAJet_;   //!
   TBranch        *b_CAJet_fUniqueID;   //!
   TBranch        *b_CAJet_fBits;   //!
   TBranch        *b_CAJet_PT;   //!
   TBranch        *b_CAJet_Eta;   //!
   TBranch        *b_CAJet_Phi;   //!
   TBranch        *b_CAJet_Mass;   //!
   TBranch        *b_CAJet_DeltaEta;   //!
   TBranch        *b_CAJet_DeltaPhi;   //!
   TBranch        *b_CAJet_WTag;   //!
   TBranch        *b_CAJet_TopTag;   //!
   TBranch        *b_CAJet_HTag;   //!
   TBranch        *b_CAJet_Tau1;   //!
   TBranch        *b_CAJet_Tau2;   //!
   TBranch        *b_CAJet_Tau3;   //!
   TBranch        *b_CAJet_NSubJets;   //!
   TBranch        *b_CAJet_MassDrop;   //!
   TBranch        *b_CAJet_TrimmedMass;   //!
   TBranch        *b_CAJet_BTag;   //!
   TBranch        *b_CAJet_TauTag;   //!
   TBranch        *b_CAJet_Charge;   //!
   TBranch        *b_CAJet_EhadOverEem;   //!
   TBranch        *b_CAJet_Constituents;   //!
   TBranch        *b_CAJet_Particles;   //!
   TBranch        *b_CAJet_size;   //!
   TBranch        *b_Jet_;   //!
   TBranch        *b_Jet_fUniqueID;   //!
   TBranch        *b_Jet_fBits;   //!
   TBranch        *b_Jet_PT;   //!
   TBranch        *b_Jet_Eta;   //!
   TBranch        *b_Jet_Phi;   //!
   TBranch        *b_Jet_Mass;   //!
   TBranch        *b_Jet_DeltaEta;   //!
   TBranch        *b_Jet_DeltaPhi;   //!
   TBranch        *b_Jet_WTag;   //!
   TBranch        *b_Jet_TopTag;   //!
   TBranch        *b_Jet_HTag;   //!
   TBranch        *b_Jet_Tau1;   //!
   TBranch        *b_Jet_Tau2;   //!
   TBranch        *b_Jet_Tau3;   //!
   TBranch        *b_Jet_NSubJets;   //!
   TBranch        *b_Jet_MassDrop;   //!
   TBranch        *b_Jet_TrimmedMass;   //!
   TBranch        *b_Jet_BTag;   //!
   TBranch        *b_Jet_TauTag;   //!
   TBranch        *b_Jet_Charge;   //!
   TBranch        *b_Jet_EhadOverEem;   //!
   TBranch        *b_Jet_Constituents;   //!
   TBranch        *b_Jet_Particles;   //!
   TBranch        *b_Jet_size;   //!
   TBranch        *b_Electron_;   //!
   TBranch        *b_Electron_fUniqueID;   //!
   TBranch        *b_Electron_fBits;   //!
   TBranch        *b_Electron_PT;   //!
   TBranch        *b_Electron_Eta;   //!
   TBranch        *b_Electron_Phi;   //!
   TBranch        *b_Electron_Charge;   //!
   TBranch        *b_Electron_EhadOverEem;   //!
   TBranch        *b_Electron_IsolationVar;   //!
   TBranch        *b_Electron_Particle;   //!
   TBranch        *b_Electron_size;   //!
   TBranch        *b_Photon_;   //!
   TBranch        *b_Photon_fUniqueID;   //!
   TBranch        *b_Photon_fBits;   //!
   TBranch        *b_Photon_PT;   //!
   TBranch        *b_Photon_Eta;   //!
   TBranch        *b_Photon_Phi;   //!
   TBranch        *b_Photon_E;   //!
   TBranch        *b_Photon_EhadOverEem;   //!
   TBranch        *b_Photon_IsolationVar;   //!
   TBranch        *b_Photon_Particles;   //!
   TBranch        *b_Photon_size;   //!
   TBranch        *b_Muon_;   //!
   TBranch        *b_Muon_fUniqueID;   //!
   TBranch        *b_Muon_fBits;   //!
   TBranch        *b_Muon_PT;   //!
   TBranch        *b_Muon_Eta;   //!
   TBranch        *b_Muon_Phi;   //!
   TBranch        *b_Muon_Charge;   //!
   TBranch        *b_Muon_IsolationVar;   //!
   TBranch        *b_Muon_Particle;   //!
   TBranch        *b_Muon_size;   //!
   TBranch        *b_MissingET_;   //!
   TBranch        *b_MissingET_fUniqueID;   //!
   TBranch        *b_MissingET_fBits;   //!
   TBranch        *b_MissingET_MET;   //!
   TBranch        *b_MissingET_Phi;   //!
   TBranch        *b_MissingET_size;   //!
   TBranch        *b_ScalarHT_;   //!
   TBranch        *b_ScalarHT_fUniqueID;   //!
   TBranch        *b_ScalarHT_fBits;   //!
   TBranch        *b_ScalarHT_HT;   //!
   TBranch        *b_ScalarHT_size;   //!
   TBranch        *b_Rho_;   //!
   TBranch        *b_Rho_fUniqueID;   //!
   TBranch        *b_Rho_fBits;   //!
   TBranch        *b_Rho_HT;   //!
   TBranch        *b_Rho_size;   //!

   MyTcZAna(TTree *tree=0, Double_t weight=1.);
   virtual ~MyTcZAna();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual void     Tree();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   virtual void     Histogram();
   /* virtual void     Tree(); */
   virtual void     ReconElec(int);
   virtual void     ReconMuon(int);
   virtual void     ReconZ();
   virtual void     ReconW();
   virtual void     ReconJet();
   virtual void     ReconTop();
   virtual void     end();

   double DeltaPhi(TLorentzVector v1, TLorentzVector v2); 
   double DeltaPhi(double v1, double v2); 
   double DeltaR(TLorentzVector v1, TLorentzVector v2);

   // Histograms

   TH1D *hist_evt_cut;
   TH1D *hist_evt_cut_eee;
   TH1D *hist_evt_cut_mmm;
   TH1D *hist_evt_cut_emm;
   TH1D *hist_evt_cut_eem;
   TH1D *hist_ele_cut;
   TH1D *hist_mu_cut;
   TH1D *hist_jet_cut;

   TH1D *hist_npu;
   TH1D *hist_npu_raw;

   TH1D *hist_zmm_m;
   TH1D *hist_zee_m;
   TH1D *hist_zmm_pt;
   TH1D *hist_zee_pt;
   TH1D *hist_zmm_n;
   TH1D *hist_zee_n;
   TH1D *hist_z_n;

   TH1D *hist_zmm_w_m;
   TH1D *hist_zee_w_m;

   TH1D *hist_z_m_t;
   TH1D *hist_z_pt_t;

   TH1D *hist_wen_m;
   TH1D *hist_wmn_m;
   TH1D *hist_wen_mt;
   TH1D *hist_wmn_mt;
   TH1D *hist_wen_gmt;
   TH1D *hist_wmn_gmt;
   TH1D *hist_w_wmt_h;
   TH1D *hist_w_wmt_l;
   TH1D *hist_w_n;
   TH2D *hist_wen_mt_met;
   TH2D *hist_wmn_mt_met;
   TH1D *hist_wen_pt;
   TH1D *hist_wmn_pt;
   TH1D *hist_wen_lpt;
   TH1D *hist_wmn_lpt;
   TH1D *hist_wen_ldz;
   TH1D *hist_wmn_ldz;
   TH1D *hist_wen_n;
   TH1D *hist_wmn_n;

   TH1D *hist_wen_mt_ee;
   TH1D *hist_wen_mt_mm;
   TH1D *hist_wmn_mt_ee;
   TH1D *hist_wmn_mt_mm;

   TH1D *hist_e_no;
   TH1D *hist_m_no;
   TH1D *hist_lep_no;
   TH1D *hist_wz_no;

   TH1D *hist_ae_pt;
   TH1D *hist_ae_eta;
   TH1D *hist_ae_phi;

   TH1D *hist_e_pt;
   TH1D *hist_e_eta;
   TH1D *hist_e_phi;
   TH1D *hist_e_iso;

   TH1D *hist_lead_e_pt;
   TH1D *hist_lead_e_eta;
   TH1D *hist_lead_e_phi;

   TH1D *hist_lead_ge_pt;
   TH1D *hist_lead_ge_eta;
   TH1D *hist_lead_ge_phi;

   TH1D *hist_lead_el_pt;
   TH1D *hist_lead_el_eta;
   TH1D *hist_lead_el_phi;

   TH1D *hist_lead_gel_pt;
   TH1D *hist_lead_gel_eta;
   TH1D *hist_lead_gel_phi;

   TH1D *hist_lead_et_pt;
   TH1D *hist_lead_et_eta;
   TH1D *hist_lead_et_phi;

   TH1D *hist_lead_get_pt;
   TH1D *hist_lead_get_eta;
   TH1D *hist_lead_get_phi;

   TH1D *hist_am_pt;
   TH1D *hist_am_eta;
   TH1D *hist_am_phi;

   TH1D *hist_m_pt;
   TH1D *hist_m_eta;
   TH1D *hist_m_phi;
   TH1D *hist_m_iso;

   TH1D *hist_ge_pt;  // gen matched lepton
   TH1D *hist_ge_eta;
   TH1D *hist_ge_phi;

   TH1D *hist_gm_pt;
   TH1D *hist_gm_eta;
   TH1D *hist_gm_phi;

   TH1D *hist_gel_pt;  // gen matched lepton
   TH1D *hist_gel_eta;
   TH1D *hist_gel_phi;

   TH1D *hist_gml_pt;
   TH1D *hist_gml_eta;
   TH1D *hist_gml_phi;

   TH1D *hist_get_pt;  // gen matched lepton
   TH1D *hist_get_eta;
   TH1D *hist_get_phi;

   TH1D *hist_gmt_pt;
   TH1D *hist_gmt_eta;
   TH1D *hist_gmt_phi;

   TH1D *hist_genz_heli;
   TH1D *hist_genw_heli;

   TH1D *hist_te_pt;  // tight lepton selection
   TH1D *hist_te_eta;
   TH1D *hist_te_phi;

   TH1D *hist_tm_pt;
   TH1D *hist_tm_eta;
   TH1D *hist_tm_phi;

   TH1D *hist_jet_pt;
   TH1D *hist_jet_eta;
   TH1D *hist_jet_phi;
   TH1D *hist_ajet_pt;
   TH1D *hist_ajet_eta;
   TH1D *hist_ajet_phi;
   TH1D *hist_gjet_pt;
   TH1D *hist_gjet_eta;
   TH1D *hist_gjet_phi;
   TH1D *hist_gjetc_pt;
   TH1D *hist_gjetc_eta;
   TH1D *hist_gjetc_phi;
   TH1D *hist_jet_disc;
   TH1D *hist_jet_fish;
   TH1D *hist_jet_no;
   TH1D *hist_jet_no_c;
   TH1D *hist_jet_flav;
   TH1D *hist_jet_dz;
   
   TH1D *hist_jet_ptb;

   TH2D *hist_njet_mt;

   TH1D *hist_jet_pt_t;
   TH1D *hist_jet_eta_t;
   TH1D *hist_jet_disc_t;
   TH1D *hist_jet_fish_t;

   TH1D *hist_jet_pt1;
   TH1D *hist_jet_pt2;
   TH1D *hist_jet_pt3;

   TH1D *hist_jet_eta1;
   TH1D *hist_jet_eta2;
   TH1D *hist_jet_eta12;
   TH1D *hist_met_pt;
   TH1D *hist_met_sumEt;
   TH1D *hist_met_phi;

   TH1D *hist_met_pt_ee;
   TH1D *hist_met_pt_mm;
   TH1D *hist_met_pt_eel;
   TH1D *hist_met_pt_mml;

   TH1D *hist_met_cuts;
   TH1D *hist_wet_cuts;
   TH1D *hist_wmt_cuts;
   TH1D *hist_mt_cuts;

   TH1D *hist_top_m_cz;
   TH1D *hist_top_m_bw;
   TH1D *hist_top_m_cz_f;
   TH1D *hist_top_m_bw_f;
   TH1D *hist_top_m_cz_g;
   TH1D *hist_top_m_bw_g;
   TH1D *hist_top_m_cz_fb;
   TH1D *hist_top_m_bw_fb;
   TH1D *hist_top_m_cz_tr;
   TH1D *hist_top_m_bw_tr;
   TH1D *hist_top_mt_cz;
   TH1D *hist_top_mt_bw;
   TH1D *hist_top_mt_cz_f;
   TH1D *hist_top_mt_bw_f;
   TH1D *hist_top_mt_cz_fb;
   TH1D *hist_top_mt_bw_fb;
   TH1D *hist_top_mt_cz_tr;
   TH1D *hist_top_mt_bw_tr;
   TH1D *hist_top_pt_cz;
   TH1D *hist_top_pt_bw;
   TH1D *hist_top_pt_cz_f;
   TH1D *hist_top_pt_bw_f;
   TH1D *hist_top_pt_cz_tr;
   TH1D *hist_top_pt_bw_tr;
   TH1D *hist_top_eta_cz;
   TH1D *hist_top_eta_bw;
   TH1D *hist_top_eta_cz_f;
   TH1D *hist_top_eta_bw_f;
   TH1D *hist_top_eta_cz_g;
   TH1D *hist_top_eta_bw_g;
   TH1D *hist_top_eta_cz_gt;
   TH1D *hist_top_eta_bw_gt;
   TH1D *hist_top_eta_cz_tr;
   TH1D *hist_top_eta_bw_tr;
   TH1D *hist_top_dphi;
   TH1D *hist_top_gdphi;
   TH1D *hist_top_dr_ch;
   TH1D *hist_top_dr_bw;
   TH1D *hist_top_no;
   int m_e_no;
   int m_m_no;
   int m_te_no;
   int m_tm_no;
   int m_z_no;
   int m_tz_no;

   int m_z_no_m;
   int m_z_no_e;
   int m_tz_no_m;
   int m_tz_no_e;
   
   int m_w_no_m;
   int m_w_no_e;
   
   int m_w_idx;
   int m_z_idx;

   int m_jet_no;
   int m_bjet_no;

   int m_gen_top1_idx;
   int m_gen_top2_idx;
   int m_top1_idx;
   int m_top2_idx;
   int m_top1b_idx;
   int m_top2b_idx;
   
   int m_gen_lep1_idx;
   int m_gen_lep2_idx;
   int m_gen_lep3_idx;
   int m_gen_lep4_idx;
   
   int m_gen_zee_idx;
   int m_gen_wuu_idx;
   
   int m_gen_jet1_idx;
   int m_gen_jet2_idx;

};

#endif

#ifdef MyTcZAna_cxx
MyTcZAna::MyTcZAna(TTree *tree, Double_t weight) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TTbar_FCNC_140.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("TTbar_FCNC_140.root");
      }
      f->GetObject("Delphes",tree);

   }
   Init(tree);

   skimTree = new TTree("skimTree", "Tree for skimmed output");

   Tree();

   Histogram();

}

MyTcZAna::~MyTcZAna()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

void MyTcZAna::end()
{
   cout << "\n\nVoila! C'est fini.\n";
   //cout << hist_evt_cut->GetBinContent(1) << endl;

   cout << "\nElectron_selection:\n";
   for(int i=0; i < 8; i++){
     cout << ele_cut_label[i] << "   \t\t" << setprecision(9)
	  << hist_ele_cut->GetBinContent(i+1) << endl;
   }

   cout << "\nMuon_selection:\n";
   for(int i=0; i < 9; i++){
     cout << mu_cut_label[i] << "   \t\t" << setprecision(9)
	  << hist_mu_cut->GetBinContent(i+1) << endl;
   }

   cout << "\nJet_selection:\n";
   for(int i=0; i < 7; i++){
     cout << jet_cut_label[i] << " : \t\t" << setprecision(9)
	  << hist_jet_cut->GetBinContent(i+1) << endl;
   }

   cout << "\nEvent_selection  \t all \t eee \t eem \t emm \t mmm \n";
   for(int i=0; i < 14; i++){
     cout << evt_cut_label[i] << "   \t\t" << setprecision(9)
	  << hist_evt_cut->GetBinContent(i+1) << " \t "
	  << hist_evt_cut_eee->GetBinContent(i+1) << " \t "
	  << hist_evt_cut_eem->GetBinContent(i+1) << " \t "
	  << hist_evt_cut_emm->GetBinContent(i+1) << " \t "
	  << hist_evt_cut_mmm->GetBinContent(i+1) << endl;
   }

   cout << "Total event weight: " << Event_Weight_Tot << endl;
}

Int_t MyTcZAna::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MyTcZAna::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MyTcZAna::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_, &b_Event_);
   fChain->SetBranchAddress("Event.fUniqueID", Event_fUniqueID, &b_Event_fUniqueID);
   fChain->SetBranchAddress("Event.fBits", Event_fBits, &b_Event_fBits);
   fChain->SetBranchAddress("Event.Number", Event_Number, &b_Event_Number);
   fChain->SetBranchAddress("Event.ReadTime", Event_ReadTime, &b_Event_ReadTime);
   fChain->SetBranchAddress("Event.ProcTime", Event_ProcTime, &b_Event_ProcTime);
   fChain->SetBranchAddress("Event.ProcessID", Event_ProcessID, &b_Event_ProcessID);
   fChain->SetBranchAddress("Event.MPI", Event_MPI, &b_Event_MPI);
   fChain->SetBranchAddress("Event.Weight", Event_Weight, &b_Event_Weight);
   fChain->SetBranchAddress("Event.Scale", Event_Scale, &b_Event_Scale);
   fChain->SetBranchAddress("Event.AlphaQED", Event_AlphaQED, &b_Event_AlphaQED);
   fChain->SetBranchAddress("Event.AlphaQCD", Event_AlphaQCD, &b_Event_AlphaQCD);
   fChain->SetBranchAddress("Event.ID1", Event_ID1, &b_Event_ID1);
   fChain->SetBranchAddress("Event.ID2", Event_ID2, &b_Event_ID2);
   fChain->SetBranchAddress("Event.X1", Event_X1, &b_Event_X1);
   fChain->SetBranchAddress("Event.X2", Event_X2, &b_Event_X2);
   fChain->SetBranchAddress("Event.ScalePDF", Event_ScalePDF, &b_Event_ScalePDF);
   fChain->SetBranchAddress("Event.PDF1", Event_PDF1, &b_Event_PDF1);
   fChain->SetBranchAddress("Event.PDF2", Event_PDF2, &b_Event_PDF2);
   fChain->SetBranchAddress("Event_size", &Event_size, &b_Event_size);
   fChain->SetBranchAddress("Particle", &Particle_, &b_Particle_);
   fChain->SetBranchAddress("Particle.fUniqueID", Particle_fUniqueID, &b_Particle_fUniqueID);
   fChain->SetBranchAddress("Particle.fBits", Particle_fBits, &b_Particle_fBits);
   fChain->SetBranchAddress("Particle.PID", Particle_PID, &b_Particle_PID);
   fChain->SetBranchAddress("Particle.Status", Particle_Status, &b_Particle_Status);
   fChain->SetBranchAddress("Particle.IsPU", Particle_IsPU, &b_Particle_IsPU);
   fChain->SetBranchAddress("Particle.M1", Particle_M1, &b_Particle_M1);
   fChain->SetBranchAddress("Particle.M2", Particle_M2, &b_Particle_M2);
   fChain->SetBranchAddress("Particle.D1", Particle_D1, &b_Particle_D1);
   fChain->SetBranchAddress("Particle.D2", Particle_D2, &b_Particle_D2);
   fChain->SetBranchAddress("Particle.Charge", Particle_Charge, &b_Particle_Charge);
   fChain->SetBranchAddress("Particle.Mass", Particle_Mass, &b_Particle_Mass);
   fChain->SetBranchAddress("Particle.E", Particle_E, &b_Particle_E);
   fChain->SetBranchAddress("Particle.Px", Particle_Px, &b_Particle_Px);
   fChain->SetBranchAddress("Particle.Py", Particle_Py, &b_Particle_Py);
   fChain->SetBranchAddress("Particle.Pz", Particle_Pz, &b_Particle_Pz);
   fChain->SetBranchAddress("Particle.PT", Particle_PT, &b_Particle_PT);
   fChain->SetBranchAddress("Particle.Eta", Particle_Eta, &b_Particle_Eta);
   fChain->SetBranchAddress("Particle.Phi", Particle_Phi, &b_Particle_Phi);
   fChain->SetBranchAddress("Particle.Rapidity", Particle_Rapidity, &b_Particle_Rapidity);
   fChain->SetBranchAddress("Particle.T", Particle_T, &b_Particle_T);
   fChain->SetBranchAddress("Particle.X", Particle_X, &b_Particle_X);
   fChain->SetBranchAddress("Particle.Y", Particle_Y, &b_Particle_Y);
   fChain->SetBranchAddress("Particle.Z", Particle_Z, &b_Particle_Z);
   fChain->SetBranchAddress("Particle_size", &Particle_size, &b_Particle_size);
   
   fChain->SetBranchAddress("Track", &Track_, &b_Track_);
   fChain->SetBranchAddress("Track.fUniqueID", Track_fUniqueID, &b_Track_fUniqueID);
   fChain->SetBranchAddress("Track.fBits", Track_fBits, &b_Track_fBits);
   fChain->SetBranchAddress("Track.PID", Track_PID, &b_Track_PID);
   fChain->SetBranchAddress("Track.Charge", Track_Charge, &b_Track_Charge);
   fChain->SetBranchAddress("Track.PT", Track_PT, &b_Track_PT);
   fChain->SetBranchAddress("Track.Eta", Track_Eta, &b_Track_Eta);
   fChain->SetBranchAddress("Track.Phi", Track_Phi, &b_Track_Phi);
   fChain->SetBranchAddress("Track.EtaOuter", Track_EtaOuter, &b_Track_EtaOuter);
   fChain->SetBranchAddress("Track.PhiOuter", Track_PhiOuter, &b_Track_PhiOuter);
   fChain->SetBranchAddress("Track.X", Track_X, &b_Track_X);
   fChain->SetBranchAddress("Track.Y", Track_Y, &b_Track_Y);
   fChain->SetBranchAddress("Track.Z", Track_Z, &b_Track_Z);
   fChain->SetBranchAddress("Track.XOuter", Track_XOuter, &b_Track_XOuter);
   fChain->SetBranchAddress("Track.YOuter", Track_YOuter, &b_Track_YOuter);
   fChain->SetBranchAddress("Track.ZOuter", Track_ZOuter, &b_Track_ZOuter);
   fChain->SetBranchAddress("Track.Particle", Track_Particle, &b_Track_Particle);
   fChain->SetBranchAddress("Track_size", &Track_size, &b_Track_size);
   fChain->SetBranchAddress("Tower", &Tower_, &b_Tower_);
   fChain->SetBranchAddress("Tower.fUniqueID", Tower_fUniqueID, &b_Tower_fUniqueID);
   fChain->SetBranchAddress("Tower.fBits", Tower_fBits, &b_Tower_fBits);
   fChain->SetBranchAddress("Tower.ET", Tower_ET, &b_Tower_ET);
   fChain->SetBranchAddress("Tower.Eta", Tower_Eta, &b_Tower_Eta);
   fChain->SetBranchAddress("Tower.Phi", Tower_Phi, &b_Tower_Phi);
   fChain->SetBranchAddress("Tower.E", Tower_E, &b_Tower_E);
   fChain->SetBranchAddress("Tower.Eem", Tower_Eem, &b_Tower_Eem);
   fChain->SetBranchAddress("Tower.Ehad", Tower_Ehad, &b_Tower_Ehad);
   fChain->SetBranchAddress("Tower.Edges[4]", Tower_Edges, &b_Tower_Edges);
   fChain->SetBranchAddress("Tower.Particles", Tower_Particles, &b_Tower_Particles);
   fChain->SetBranchAddress("Tower_size", &Tower_size, &b_Tower_size);
   
   fChain->SetBranchAddress("EFlowTrack", &EFlowTrack_, &b_EFlowTrack_);
   fChain->SetBranchAddress("EFlowTrack.fUniqueID", EFlowTrack_fUniqueID, &b_EFlowTrack_fUniqueID);
   fChain->SetBranchAddress("EFlowTrack.fBits", EFlowTrack_fBits, &b_EFlowTrack_fBits);
   fChain->SetBranchAddress("EFlowTrack.PID", EFlowTrack_PID, &b_EFlowTrack_PID);
   fChain->SetBranchAddress("EFlowTrack.Charge", EFlowTrack_Charge, &b_EFlowTrack_Charge);
   fChain->SetBranchAddress("EFlowTrack.PT", EFlowTrack_PT, &b_EFlowTrack_PT);
   fChain->SetBranchAddress("EFlowTrack.Eta", EFlowTrack_Eta, &b_EFlowTrack_Eta);
   fChain->SetBranchAddress("EFlowTrack.Phi", EFlowTrack_Phi, &b_EFlowTrack_Phi);
   fChain->SetBranchAddress("EFlowTrack.EtaOuter", EFlowTrack_EtaOuter, &b_EFlowTrack_EtaOuter);
   fChain->SetBranchAddress("EFlowTrack.PhiOuter", EFlowTrack_PhiOuter, &b_EFlowTrack_PhiOuter);
   fChain->SetBranchAddress("EFlowTrack.X", EFlowTrack_X, &b_EFlowTrack_X);
   fChain->SetBranchAddress("EFlowTrack.Y", EFlowTrack_Y, &b_EFlowTrack_Y);
   fChain->SetBranchAddress("EFlowTrack.Z", EFlowTrack_Z, &b_EFlowTrack_Z);
   fChain->SetBranchAddress("EFlowTrack.XOuter", EFlowTrack_XOuter, &b_EFlowTrack_XOuter);
   fChain->SetBranchAddress("EFlowTrack.YOuter", EFlowTrack_YOuter, &b_EFlowTrack_YOuter);
   fChain->SetBranchAddress("EFlowTrack.ZOuter", EFlowTrack_ZOuter, &b_EFlowTrack_ZOuter);
   fChain->SetBranchAddress("EFlowTrack.Particle", EFlowTrack_Particle, &b_EFlowTrack_Particle);
   fChain->SetBranchAddress("EFlowTrack_size", &EFlowTrack_size, &b_EFlowTrack_size);
   fChain->SetBranchAddress("EFlowTower", &EFlowTower_, &b_EFlowTower_);
   fChain->SetBranchAddress("EFlowTower.fUniqueID", EFlowTower_fUniqueID, &b_EFlowTower_fUniqueID);
   fChain->SetBranchAddress("EFlowTower.fBits", EFlowTower_fBits, &b_EFlowTower_fBits);
   fChain->SetBranchAddress("EFlowTower.ET", EFlowTower_ET, &b_EFlowTower_ET);
   fChain->SetBranchAddress("EFlowTower.Eta", EFlowTower_Eta, &b_EFlowTower_Eta);
   fChain->SetBranchAddress("EFlowTower.Phi", EFlowTower_Phi, &b_EFlowTower_Phi);
   fChain->SetBranchAddress("EFlowTower.E", EFlowTower_E, &b_EFlowTower_E);
   fChain->SetBranchAddress("EFlowTower.Eem", EFlowTower_Eem, &b_EFlowTower_Eem);
   fChain->SetBranchAddress("EFlowTower.Ehad", EFlowTower_Ehad, &b_EFlowTower_Ehad);
   fChain->SetBranchAddress("EFlowTower.Edges[4]", EFlowTower_Edges, &b_EFlowTower_Edges);
   fChain->SetBranchAddress("EFlowTower.Particles", EFlowTower_Particles, &b_EFlowTower_Particles);
   fChain->SetBranchAddress("EFlowTower_size", &EFlowTower_size, &b_EFlowTower_size);
   fChain->SetBranchAddress("EFlowMuon", &EFlowMuon_, &b_EFlowMuon_);
   fChain->SetBranchAddress("EFlowMuon.fUniqueID", EFlowMuon_fUniqueID, &b_EFlowMuon_fUniqueID);
   fChain->SetBranchAddress("EFlowMuon.fBits", EFlowMuon_fBits, &b_EFlowMuon_fBits);
   fChain->SetBranchAddress("EFlowMuon.PT", EFlowMuon_PT, &b_EFlowMuon_PT);
   fChain->SetBranchAddress("EFlowMuon.Eta", EFlowMuon_Eta, &b_EFlowMuon_Eta);
   fChain->SetBranchAddress("EFlowMuon.Phi", EFlowMuon_Phi, &b_EFlowMuon_Phi);
   fChain->SetBranchAddress("EFlowMuon.Charge", EFlowMuon_Charge, &b_EFlowMuon_Charge);
   fChain->SetBranchAddress("EFlowMuon.IsolationVar", EFlowMuon_IsolationVar, &b_EFlowMuon_IsolationVar);
   fChain->SetBranchAddress("EFlowMuon.Particle", EFlowMuon_Particle, &b_EFlowMuon_Particle);
   fChain->SetBranchAddress("EFlowMuon_size", &EFlowMuon_size, &b_EFlowMuon_size);

   fChain->SetBranchAddress("GenJet", &GenJet_, &b_GenJet_);
   fChain->SetBranchAddress("GenJet.fUniqueID", GenJet_fUniqueID, &b_GenJet_fUniqueID);
   fChain->SetBranchAddress("GenJet.fBits", GenJet_fBits, &b_GenJet_fBits);
   fChain->SetBranchAddress("GenJet.PT", GenJet_PT, &b_GenJet_PT);
   fChain->SetBranchAddress("GenJet.Eta", GenJet_Eta, &b_GenJet_Eta);
   fChain->SetBranchAddress("GenJet.Phi", GenJet_Phi, &b_GenJet_Phi);
   fChain->SetBranchAddress("GenJet.Mass", GenJet_Mass, &b_GenJet_Mass);
   fChain->SetBranchAddress("GenJet.DeltaEta", GenJet_DeltaEta, &b_GenJet_DeltaEta);
   fChain->SetBranchAddress("GenJet.DeltaPhi", GenJet_DeltaPhi, &b_GenJet_DeltaPhi);
   fChain->SetBranchAddress("GenJet.WTag", GenJet_WTag, &b_GenJet_WTag);
   fChain->SetBranchAddress("GenJet.TopTag", GenJet_TopTag, &b_GenJet_TopTag);
   fChain->SetBranchAddress("GenJet.HTag", GenJet_HTag, &b_GenJet_HTag);
   fChain->SetBranchAddress("GenJet.Tau1", GenJet_Tau1, &b_GenJet_Tau1);
   fChain->SetBranchAddress("GenJet.Tau2", GenJet_Tau2, &b_GenJet_Tau2);
   fChain->SetBranchAddress("GenJet.Tau3", GenJet_Tau3, &b_GenJet_Tau3);
   fChain->SetBranchAddress("GenJet.NSubJets", GenJet_NSubJets, &b_GenJet_NSubJets);
   fChain->SetBranchAddress("GenJet.MassDrop", GenJet_MassDrop, &b_GenJet_MassDrop);
   fChain->SetBranchAddress("GenJet.TrimmedMass", GenJet_TrimmedMass, &b_GenJet_TrimmedMass);
   fChain->SetBranchAddress("GenJet.BTag", GenJet_BTag, &b_GenJet_BTag);
   fChain->SetBranchAddress("GenJet.TauTag", GenJet_TauTag, &b_GenJet_TauTag);
   fChain->SetBranchAddress("GenJet.Charge", GenJet_Charge, &b_GenJet_Charge);
   fChain->SetBranchAddress("GenJet.EhadOverEem", GenJet_EhadOverEem, &b_GenJet_EhadOverEem);
   fChain->SetBranchAddress("GenJet.Constituents", GenJet_Constituents, &b_GenJet_Constituents);
   fChain->SetBranchAddress("GenJet.Particles", GenJet_Particles, &b_GenJet_Particles);
   fChain->SetBranchAddress("GenJet_size", &GenJet_size, &b_GenJet_size);
   
   fChain->SetBranchAddress("CAJet", &CAJet_, &b_CAJet_);
   fChain->SetBranchAddress("CAJet.fUniqueID", CAJet_fUniqueID, &b_CAJet_fUniqueID);
   fChain->SetBranchAddress("CAJet.fBits", CAJet_fBits, &b_CAJet_fBits);
   fChain->SetBranchAddress("CAJet.PT", CAJet_PT, &b_CAJet_PT);
   fChain->SetBranchAddress("CAJet.Eta", CAJet_Eta, &b_CAJet_Eta);
   fChain->SetBranchAddress("CAJet.Phi", CAJet_Phi, &b_CAJet_Phi);
   fChain->SetBranchAddress("CAJet.Mass", CAJet_Mass, &b_CAJet_Mass);
   fChain->SetBranchAddress("CAJet.DeltaEta", CAJet_DeltaEta, &b_CAJet_DeltaEta);
   fChain->SetBranchAddress("CAJet.DeltaPhi", CAJet_DeltaPhi, &b_CAJet_DeltaPhi);
   fChain->SetBranchAddress("CAJet.WTag", CAJet_WTag, &b_CAJet_WTag);
   fChain->SetBranchAddress("CAJet.TopTag", CAJet_TopTag, &b_CAJet_TopTag);
   fChain->SetBranchAddress("CAJet.HTag", CAJet_HTag, &b_CAJet_HTag);
   fChain->SetBranchAddress("CAJet.Tau1", CAJet_Tau1, &b_CAJet_Tau1);
   fChain->SetBranchAddress("CAJet.Tau2", CAJet_Tau2, &b_CAJet_Tau2);
   fChain->SetBranchAddress("CAJet.Tau3", CAJet_Tau3, &b_CAJet_Tau3);
   fChain->SetBranchAddress("CAJet.NSubJets", CAJet_NSubJets, &b_CAJet_NSubJets);
   fChain->SetBranchAddress("CAJet.MassDrop", CAJet_MassDrop, &b_CAJet_MassDrop);
   fChain->SetBranchAddress("CAJet.TrimmedMass", CAJet_TrimmedMass, &b_CAJet_TrimmedMass);
   fChain->SetBranchAddress("CAJet.BTag", CAJet_BTag, &b_CAJet_BTag);
   fChain->SetBranchAddress("CAJet.TauTag", CAJet_TauTag, &b_CAJet_TauTag);
   fChain->SetBranchAddress("CAJet.Charge", CAJet_Charge, &b_CAJet_Charge);
   fChain->SetBranchAddress("CAJet.EhadOverEem", CAJet_EhadOverEem, &b_CAJet_EhadOverEem);
   fChain->SetBranchAddress("CAJet.Constituents", CAJet_Constituents, &b_CAJet_Constituents);
   fChain->SetBranchAddress("CAJet.Particles", CAJet_Particles, &b_CAJet_Particles);
   fChain->SetBranchAddress("CAJet_size", &CAJet_size, &b_CAJet_size);
   
   fChain->SetBranchAddress("Jet", &Jet_, &b_Jet_);
   fChain->SetBranchAddress("Jet.fUniqueID", Jet_fUniqueID, &b_Jet_fUniqueID);
   fChain->SetBranchAddress("Jet.fBits", Jet_fBits, &b_Jet_fBits);
   fChain->SetBranchAddress("Jet.PT", Jet_PT, &b_Jet_PT);
   fChain->SetBranchAddress("Jet.Eta", Jet_Eta, &b_Jet_Eta);
   fChain->SetBranchAddress("Jet.Phi", Jet_Phi, &b_Jet_Phi);
   fChain->SetBranchAddress("Jet.Mass", Jet_Mass, &b_Jet_Mass);
   fChain->SetBranchAddress("Jet.DeltaEta", Jet_DeltaEta, &b_Jet_DeltaEta);
   fChain->SetBranchAddress("Jet.DeltaPhi", Jet_DeltaPhi, &b_Jet_DeltaPhi);
   fChain->SetBranchAddress("Jet.WTag", Jet_WTag, &b_Jet_WTag);
   fChain->SetBranchAddress("Jet.TopTag", Jet_TopTag, &b_Jet_TopTag);
   fChain->SetBranchAddress("Jet.HTag", Jet_HTag, &b_Jet_HTag);
   fChain->SetBranchAddress("Jet.Tau1", Jet_Tau1, &b_Jet_Tau1);
   fChain->SetBranchAddress("Jet.Tau2", Jet_Tau2, &b_Jet_Tau2);
   fChain->SetBranchAddress("Jet.Tau3", Jet_Tau3, &b_Jet_Tau3);
   fChain->SetBranchAddress("Jet.NSubJets", Jet_NSubJets, &b_Jet_NSubJets);
   fChain->SetBranchAddress("Jet.MassDrop", Jet_MassDrop, &b_Jet_MassDrop);
   fChain->SetBranchAddress("Jet.TrimmedMass", Jet_TrimmedMass, &b_Jet_TrimmedMass);
   fChain->SetBranchAddress("Jet.BTag", Jet_BTag, &b_Jet_BTag);
   fChain->SetBranchAddress("Jet.TauTag", Jet_TauTag, &b_Jet_TauTag);
   fChain->SetBranchAddress("Jet.Charge", Jet_Charge, &b_Jet_Charge);
   fChain->SetBranchAddress("Jet.EhadOverEem", Jet_EhadOverEem, &b_Jet_EhadOverEem);
   fChain->SetBranchAddress("Jet.Constituents", Jet_Constituents, &b_Jet_Constituents);
   fChain->SetBranchAddress("Jet.Particles", Jet_Particles, &b_Jet_Particles);
   fChain->SetBranchAddress("Jet_size", &Jet_size, &b_Jet_size);
   fChain->SetBranchAddress("Electron", &Electron_, &b_Electron_);
   fChain->SetBranchAddress("Electron.fUniqueID", Electron_fUniqueID, &b_Electron_fUniqueID);
   fChain->SetBranchAddress("Electron.fBits", Electron_fBits, &b_Electron_fBits);
   fChain->SetBranchAddress("Electron.PT", Electron_PT, &b_Electron_PT);
   fChain->SetBranchAddress("Electron.Eta", Electron_Eta, &b_Electron_Eta);
   fChain->SetBranchAddress("Electron.Phi", Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron.Charge", Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron.EhadOverEem", Electron_EhadOverEem, &b_Electron_EhadOverEem);
   fChain->SetBranchAddress("Electron.IsolationVar", Electron_IsolationVar, &b_Electron_IsolationVar);
   fChain->SetBranchAddress("Electron.Particle", Electron_Particle, &b_Electron_Particle);
   fChain->SetBranchAddress("Electron_size", &Electron_size, &b_Electron_size);
   
   fChain->SetBranchAddress("Photon", &Photon_, &b_Photon_);
   fChain->SetBranchAddress("Photon.fUniqueID", Photon_fUniqueID, &b_Photon_fUniqueID);
   fChain->SetBranchAddress("Photon.fBits", Photon_fBits, &b_Photon_fBits);
   fChain->SetBranchAddress("Photon.PT", Photon_PT, &b_Photon_PT);
   fChain->SetBranchAddress("Photon.Eta", Photon_Eta, &b_Photon_Eta);
   fChain->SetBranchAddress("Photon.Phi", Photon_Phi, &b_Photon_Phi);
   fChain->SetBranchAddress("Photon.E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon.EhadOverEem", Photon_EhadOverEem, &b_Photon_EhadOverEem);
   fChain->SetBranchAddress("Photon.IsolationVar", Photon_IsolationVar, &b_Photon_IsolationVar);
   fChain->SetBranchAddress("Photon.Particles", Photon_Particles, &b_Photon_Particles);
   fChain->SetBranchAddress("Photon_size", &Photon_size, &b_Photon_size);
   
   fChain->SetBranchAddress("Muon", &Muon_, &b_Muon_);
   fChain->SetBranchAddress("Muon.fUniqueID", Muon_fUniqueID, &b_Muon_fUniqueID);
   fChain->SetBranchAddress("Muon.fBits", Muon_fBits, &b_Muon_fBits);
   fChain->SetBranchAddress("Muon.PT", Muon_PT, &b_Muon_PT);
   fChain->SetBranchAddress("Muon.Eta", Muon_Eta, &b_Muon_Eta);
   fChain->SetBranchAddress("Muon.Phi", Muon_Phi, &b_Muon_Phi);
   fChain->SetBranchAddress("Muon.Charge", Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon.IsolationVar", Muon_IsolationVar, &b_Muon_IsolationVar);
   fChain->SetBranchAddress("Muon.Particle", Muon_Particle, &b_Muon_Particle);
   fChain->SetBranchAddress("Muon_size", &Muon_size, &b_Muon_size);
   fChain->SetBranchAddress("MissingET", &MissingET_, &b_MissingET_);
   fChain->SetBranchAddress("MissingET.fUniqueID", MissingET_fUniqueID, &b_MissingET_fUniqueID);
   fChain->SetBranchAddress("MissingET.fBits", MissingET_fBits, &b_MissingET_fBits);
   fChain->SetBranchAddress("MissingET.MET", MissingET_MET, &b_MissingET_MET);
   fChain->SetBranchAddress("MissingET.Phi", MissingET_Phi, &b_MissingET_Phi);
   fChain->SetBranchAddress("MissingET_size", &MissingET_size, &b_MissingET_size);
   fChain->SetBranchAddress("ScalarHT", &ScalarHT_, &b_ScalarHT_);
   fChain->SetBranchAddress("ScalarHT.fUniqueID", ScalarHT_fUniqueID, &b_ScalarHT_fUniqueID);
   fChain->SetBranchAddress("ScalarHT.fBits", ScalarHT_fBits, &b_ScalarHT_fBits);
   fChain->SetBranchAddress("ScalarHT.HT", ScalarHT_HT, &b_ScalarHT_HT);
   fChain->SetBranchAddress("ScalarHT_size", &ScalarHT_size, &b_ScalarHT_size);

   fChain->SetBranchAddress("Rho", &Rho_, &b_Rho_);
   fChain->SetBranchAddress("Rho.fUniqueID", Rho_fUniqueID, &b_Rho_fUniqueID);
   fChain->SetBranchAddress("Rho.fBits", Rho_fBits, &b_Rho_fBits);
   fChain->SetBranchAddress("Rho.HT", Rho_HT, &b_Rho_HT);
   fChain->SetBranchAddress("Rho_size", &Rho_size, &b_Rho_size);
   
   Notify();
}

void MyTcZAna::Tree(){
   skimTree->Branch("Event", &Event_, "Event_/I");
   skimTree->Branch("Event_size", &Event_size, "Event_size/I");
   skimTree->Branch("Event.fUniqueID", Event_fUniqueID, "Event_fUniqueID[Event_size]/i");
   skimTree->Branch("Event.fBits", Event_fBits, "Event_fBits[Event_size]/i");
   skimTree->Branch("Event.Number", Event_Number, "Event_Number[Event_size]/L");
   skimTree->Branch("Event.ReadTime", Event_ReadTime, "Event_ReadTime[Event_size]/F");
   skimTree->Branch("Event.ProcTime", Event_ProcTime, "Event_ProcTime[Event_size]/F");
   skimTree->Branch("Event.ProcessID", Event_ProcessID, "Event_ProcessID[Event_size]/I");
   skimTree->Branch("Event.MPI", Event_MPI, "Event_MPI[Event_size]/I");
   skimTree->Branch("Event.Weight", Event_Weight, "Event_Weight[Event_size]/F");
   skimTree->Branch("Event.Scale", Event_Scale, "Event_Scale[Event_size]/F");
   skimTree->Branch("Event.AlphaQED", Event_AlphaQED, "Event_AlphaQED[Event_size]/F");
   skimTree->Branch("Event.AlphaQCD", Event_AlphaQCD, "Event_AlphaQCD[Event_size]/F");
   skimTree->Branch("Event.ID1", Event_ID1, "Event_ID1[Event_size]/I");
   skimTree->Branch("Event.ID2", Event_ID2, "Event_ID2[Event_size]/I");
   skimTree->Branch("Event.X1", Event_X1, "Event_X1[Event_size]/F");
   skimTree->Branch("Event.X2", Event_X2, "Event_X2[Event_size]/F");
   skimTree->Branch("Event.ScalePDF", Event_ScalePDF, "Event_ScalePDF[Event_size]/F");
   skimTree->Branch("Event.PDF1", Event_PDF1, "Event_PDF1[Event_size]/F");
   skimTree->Branch("Event.PDF2", Event_PDF2, "Event_PDF2[Event_size]/F");

   skimTree->Branch("Particle_size", &Particle_size, "Particle_size/I");
   skimTree->Branch("Particle", &Particle_, "Particle_/I");
   skimTree->Branch("Particle.fUniqueID", Particle_fUniqueID, "Particle_fUniqueID[Particle_size]/i");
   skimTree->Branch("Particle.fBits", Particle_fBits, "Particle_fBits[Particle_size]/i");
   skimTree->Branch("Particle.PID", Particle_PID, "Particle_PID[Particle_size]/I");
   skimTree->Branch("Particle.Status", Particle_Status, "Particle_Status[Particle_size]/I");
   skimTree->Branch("Particle.IsPU", Particle_IsPU, "Particle_IsPU[Particle_size]/I");
   skimTree->Branch("Particle.M1", Particle_M1, "Particle_M1[Particle_size]/I");
   skimTree->Branch("Particle.M2", Particle_M2, "Particle_M2[Particle_size]/I");
   skimTree->Branch("Particle.D1", Particle_D1, "Particle_D1[Particle_size]/I");
   skimTree->Branch("Particle.D2", Particle_D2, "Particle_D2[Particle_size]/I");
   skimTree->Branch("Particle.Charge", Particle_Charge, "Particle_Charge[Particle_size]/I");
   skimTree->Branch("Particle.Mass", Particle_Mass, "Particle_Mass[Particle_size]/F");
   skimTree->Branch("Particle.E", Particle_E, "Particle_E[Particle_size]/F");
   skimTree->Branch("Particle.Px", Particle_Px, "Particle_Px[Particle_size]/F");
   skimTree->Branch("Particle.Py", Particle_Py, "Particle_Py[Particle_size]/F");
   skimTree->Branch("Particle.Pz", Particle_Pz, "Particle_Pz[Particle_size]/F");
   skimTree->Branch("Particle.PT", Particle_PT, "Particle_PT[Particle_size]/F");
   skimTree->Branch("Particle.Eta", Particle_Eta, "Particle_Eta[Particle_size]/F");
   skimTree->Branch("Particle.Phi", Particle_Phi, "Particle_Phi[Particle_size]/F");
   skimTree->Branch("Particle.Rapidity", Particle_Rapidity, "Particle_Rapidity[Particle_size]/F");
   skimTree->Branch("Particle.T", Particle_T, "Particle_T[Particle_size]/F");
   skimTree->Branch("Particle.X", Particle_X, "Particle_X[Particle_size]/F");
   skimTree->Branch("Particle.Y", Particle_Y, "Particle_Y[Particle_size]/F");
   skimTree->Branch("Particle.Z", Particle_Z, "Particle_Z[Particle_size]/F");
   
   skimTree->Branch("Track_size", &Track_size, "Track_size/I");
   skimTree->Branch("Track", &Track_, "Track_/I");
   skimTree->Branch("Track.fUniqueID", Track_fUniqueID, "Track_fUniqueID[Track_size]/i");
   skimTree->Branch("Track.fBits", Track_fBits, "Track_fBits[Track_size]/i");
   skimTree->Branch("Track.PID", Track_PID, "Track_PID[Track_size]/I");
   skimTree->Branch("Track.Charge", Track_Charge, "Track_Charge[Track_size]/I");
   skimTree->Branch("Track.PT", Track_PT, "Track_PT[Track_size]/F");
   skimTree->Branch("Track.Eta", Track_Eta, "Track_Eta[Track_size]/F");
   skimTree->Branch("Track.Phi", Track_Phi, "Track_Phi[Track_size]/F");
   skimTree->Branch("Track.EtaOuter", Track_EtaOuter, "Track_EtaOuter[Track_size]/F");
   skimTree->Branch("Track.PhiOuter", Track_PhiOuter, "Track_PhiOuter[Track_size]/F");
   skimTree->Branch("Track.X", Track_X, "Track_X[Track_size]/F");
   skimTree->Branch("Track.Y", Track_Y, "Track_Y[Track_size]/F");
   skimTree->Branch("Track.Z", Track_Z, "Track_Z[Track_size]/F");
   skimTree->Branch("Track.XOuter", Track_XOuter, "Track_XOuter[Track_size]/F");
   skimTree->Branch("Track.YOuter", Track_YOuter, "Track_YOuter[Track_size]/F");
   skimTree->Branch("Track.ZOuter", Track_ZOuter, "Track_ZOuter[Track_size]/F");
   //skimTree->Branch("Track.Particle", Track_Particle, "Track_Particle[Track_size]/F");

   skimTree->Branch("Tower_size", &Tower_size, "Tower_size/I");
   skimTree->Branch("Tower", &Tower_, "Tower_/I");
   skimTree->Branch("Tower.fUniqueID", Tower_fUniqueID, "Tower_fUniqueID[Tower_size]/i");
   skimTree->Branch("Tower.fBits", Tower_fBits, "Tower_fBits[Tower_size]/i");
   skimTree->Branch("Tower.ET", Tower_ET, "Tower_ET[Tower_size]/F");
   skimTree->Branch("Tower.Eta", Tower_Eta, "Tower_Eta[Tower_size]/F");
   skimTree->Branch("Tower.Phi", Tower_Phi, "Tower_Phi[Tower_size]/F");
   skimTree->Branch("Tower.E", Tower_E, "Tower_E[Tower_size]/F");
   skimTree->Branch("Tower.Eem", Tower_Eem, "Tower_Eem[Tower_size]/F");
   skimTree->Branch("Tower.Ehad", Tower_Ehad, "Tower_Ehad[Tower_size]/F");
   skimTree->Branch("Tower.Edges[4]", Tower_Edges, "Tower_Edges[Tower_size][4]/F");
   //skimTree->Branch("Tower.Particles", Tower_Particles, "Tower_Particles[Tower_size]/F");
   
   skimTree->Branch("GenJet_size", &GenJet_size, "GenJet_size/I");
   skimTree->Branch("GenJet", &GenJet_, "GenJet_/I");
   skimTree->Branch("GenJet.fUniqueID", GenJet_fUniqueID, "GenJet_fUniqueID[GenJet_size]/i");
   skimTree->Branch("GenJet.fBits", GenJet_fBits, "GenJet_fBits[GenJet_size]/i");
   skimTree->Branch("GenJet.PT", GenJet_PT, "GenJet_PT[GenJet_size]/F");
   skimTree->Branch("GenJet.Eta", GenJet_Eta, "GenJet_Eta[GenJet_size]/F");
   skimTree->Branch("GenJet.Phi", GenJet_Phi, "GenJet_Phi[GenJet_size]/F");
   skimTree->Branch("GenJet.Mass", GenJet_Mass, "GenJet_Mass[GenJet_size]/F");
   skimTree->Branch("GenJet.DeltaEta", GenJet_DeltaEta, "GenJet_DeltaEta[GenJet_size]/F");
   skimTree->Branch("GenJet.DeltaPhi", GenJet_DeltaPhi, "GenJet_DeltaPhi[GenJet_size]/F");
   skimTree->Branch("GenJet.WTag", GenJet_WTag, "GenJet_WTag[GenJet_size]/i");
   skimTree->Branch("GenJet.TopTag", GenJet_TopTag, "GenJet_TopTag[GenJet_size]/i");
   skimTree->Branch("GenJet.HTag", GenJet_HTag, "GenJet_HTag[GenJet_size]/i");
   skimTree->Branch("GenJet.Tau1", GenJet_Tau1, "GenJet_Tau1[GenJet_size]/F");
   skimTree->Branch("GenJet.Tau2", GenJet_Tau2, "GenJet_Tau2[GenJet_size]/F");
   skimTree->Branch("GenJet.Tau3", GenJet_Tau3, "GenJet_Tau3[GenJet_size]/F");
   skimTree->Branch("GenJet.NSubJets", GenJet_NSubJets, "GenJet_NSubJets[GenJet_size]/i");
   skimTree->Branch("GenJet.MassDrop", GenJet_MassDrop, "GenJet_MassDrop[GenJet_size]/F");
   skimTree->Branch("GenJet.TrimmedMass", GenJet_TrimmedMass, "GenJet_TrimmedMass[GenJet_size]/F");
   skimTree->Branch("GenJet.BTag", GenJet_BTag, "GenJet_BTag[GenJet_size]/i");
   skimTree->Branch("GenJet.TauTag", GenJet_TauTag, "GenJet_TauTag[GenJet_size]/i");
   skimTree->Branch("GenJet.Charge", GenJet_Charge, "GenJet_Charge[GenJet_size]/I");
   skimTree->Branch("GenJet.EhadOverEem", GenJet_EhadOverEem, "GenJet_EhadOverEem[GenJet_size]/F");
   //skimTree->Branch("GenJet.Constituents", GenJet_Constituents, "GenJet_Constituents[GenJet_size]/F");
   //skimTree->Branch("GenJet.Particles", GenJet_Particles, "GenJet_Particles/F");
   
   skimTree->Branch("CAJet_size", &CAJet_size, "CAJet_size/I");
   skimTree->Branch("CAJet", &CAJet_, "CAJet_/I");
   skimTree->Branch("CAJet.fUniqueID", CAJet_fUniqueID, "CAJet_fUniqueID[CAJet_size]/i");
   skimTree->Branch("CAJet.fBits", CAJet_fBits, "CAJet_fBits[CAJet_size]/i");
   skimTree->Branch("CAJet.PT", CAJet_PT, "CAJet_PT[CAJet_size]/F");
   skimTree->Branch("CAJet.Eta", CAJet_Eta, "CAJet_Eta[CAJet_size]/F");
   skimTree->Branch("CAJet.Phi", CAJet_Phi, "CAJet_Phi[CAJet_size]/F");
   skimTree->Branch("CAJet.Mass", CAJet_Mass, "CAJet_Mass[CAJet_size]/F");
   skimTree->Branch("CAJet.DeltaEta", CAJet_DeltaEta, "CAJet_DeltaEta[CAJet_size]/F");
   skimTree->Branch("CAJet.DeltaPhi", CAJet_DeltaPhi, "CAJet_DeltaPhi[CAJet_size]/F");
   skimTree->Branch("CAJet.WTag", CAJet_WTag, "CAJet_WTag[CAJet_size]/i");
   skimTree->Branch("CAJet.TopTag", CAJet_TopTag, "CAJet_TopTag[CAJet_size]/i");
   skimTree->Branch("CAJet.HTag", CAJet_HTag, "CAJet_HTag[CAJet_size]/i");
   skimTree->Branch("CAJet.Tau1", CAJet_Tau1, "CAJet_Tau1[CAJet_size]/F");
   skimTree->Branch("CAJet.Tau2", CAJet_Tau2, "CAJet_Tau2[CAJet_size]/F");
   skimTree->Branch("CAJet.Tau3", CAJet_Tau3, "CAJet_Tau3[CAJet_size]/F");
   skimTree->Branch("CAJet.NSubJets", CAJet_NSubJets, "CAJet_NSubJets[CAJet_size]/i");
   skimTree->Branch("CAJet.MassDrop", CAJet_MassDrop, "CAJet_MassDrop[CAJet_size]/F");
   skimTree->Branch("CAJet.TrimmedMass", CAJet_TrimmedMass, "CAJet_TrimmedMass[CAJet_size]/F");
   skimTree->Branch("CAJet.BTag", CAJet_BTag, "CAJet_BTag[CAJet_size]/i");
   skimTree->Branch("CAJet.TauTag", CAJet_TauTag, "CAJet_TauTag[CAJet_size]/i");
   skimTree->Branch("CAJet.Charge", CAJet_Charge, "CAJet_Charge[CAJet_size]/I");
   skimTree->Branch("CAJet.EhadOverEem", CAJet_EhadOverEem, "CAJet_EhadOverEem[CAJet_size]/F");
   //skimTree->Branch("CAJet.Constituents", CAJet_Constituents, "CAJet_Constituents[CAJet_size]/F");
   //skimTree->Branch("CAJet.Particles", CAJet_Particles, "CAJet_Particles[CAJet_size]/F");
   
   skimTree->Branch("Jet_size", &Jet_size, "Jet_size/I");
   skimTree->Branch("Jet", &Jet_, "Jet_/I");
   skimTree->Branch("Jet.fUniqueID", Jet_fUniqueID, "Jet_fUniqueID[Jet_size]/i");
   skimTree->Branch("Jet.fBits", Jet_fBits, "Jet_fBits[Jet_size]/i");
   skimTree->Branch("Jet.PT", Jet_PT, "Jet_PT[Jet_size]/F");
   skimTree->Branch("Jet.Eta", Jet_Eta, "Jet_Eta[Jet_size]/F");
   skimTree->Branch("Jet.Phi", Jet_Phi, "Jet_Phi[Jet_size]/F");
   skimTree->Branch("Jet.Mass", Jet_Mass, "Jet_Mass[Jet_size]/F");
   skimTree->Branch("Jet.DeltaEta", Jet_DeltaEta, "Jet_DeltaEta[Jet_size]/F");
   skimTree->Branch("Jet.DeltaPhi", Jet_DeltaPhi, "Jet_DeltaPhi[Jet_size]/F");
   skimTree->Branch("Jet.WTag", Jet_WTag, "Jet_WTag[Jet_size]/i");
   skimTree->Branch("Jet.TopTag", Jet_TopTag, "Jet_TopTag[Jet_size]/i");
   skimTree->Branch("Jet.HTag", Jet_HTag, "Jet_HTag[Jet_size]/F");
   skimTree->Branch("Jet.Tau1", Jet_Tau1, "Jet_Tau1[Jet_size]/F");
   skimTree->Branch("Jet.Tau2", Jet_Tau2, "Jet_Tau2[Jet_size]/F");
   skimTree->Branch("Jet.Tau3", Jet_Tau3, "Jet_Tau3[Jet_size]/F");
   skimTree->Branch("Jet.NSubJets", Jet_NSubJets, "Jet_NSubJets[Jet_size]/i");
   skimTree->Branch("Jet.MassDrop", Jet_MassDrop, "Jet_MassDrop[Jet_size]/F");
   skimTree->Branch("Jet.TrimmedMass", Jet_TrimmedMass, "Jet_TrimmedMass[Jet_size]/F");
   skimTree->Branch("Jet.BTag", Jet_BTag, "Jet_BTag[Jet_size]/i");
   skimTree->Branch("Jet.TauTag", Jet_TauTag, "Jet_TauTag[Jet_size]/i");
   skimTree->Branch("Jet.Charge", Jet_Charge, "Jet_Charge[Jet_size]/I");
   skimTree->Branch("Jet.EhadOverEem", Jet_EhadOverEem, "Jet_EhadOverEem[Jet_size]/F");
   //skimTree->Branch("Jet.Constituents", Jet_Constituents, "Jet_Constituents[Jet_size]/F");
   //skimTree->Branch("Jet.Particles", Jet_Particles, "Jet_Particles[Jet_size]/F");

   skimTree->Branch("Electron_size", &Electron_size, "Electron_size/I");
   skimTree->Branch("Electron", &Electron_, "Electron_/I");
   skimTree->Branch("Electron.fUniqueID", Electron_fUniqueID, "Electron_fUniqueID[Electron_size]/i");
   skimTree->Branch("Electron.fBits", Electron_fBits, "Electron_fBits[Electron_size]/i");
   skimTree->Branch("Electron.PT", Electron_PT, "Electron_PT[Electron_size]/F");
   skimTree->Branch("Electron.Eta", Electron_Eta, "Electron_Eta[Electron_size]/F");
   skimTree->Branch("Electron.Phi", Electron_Phi, "Electron_Phi[Electron_size]/F");
   skimTree->Branch("Electron.Charge", Electron_Charge, "Electron_Charge[Electron_size]/I");
   skimTree->Branch("Electron.EhadOverEem", Electron_EhadOverEem, "Electron_EhadOverEem[Electron_size]/F");
   skimTree->Branch("Electron.IsolationVar", Electron_IsolationVar, "Electron_IsolationVar[Electron_size]/F");
   //skimTree->Branch("Electron.Particle", Electron_Particle, "Electron_Particle[Electron_size]/F");
   
   skimTree->Branch("Photon_size", &Photon_size, "Photon_size/I");
   skimTree->Branch("Photon", &Photon_, "Photon_/I");
   skimTree->Branch("Photon.fUniqueID", Photon_fUniqueID, "Photon_fUniqueID[Photon_size]/i");
   skimTree->Branch("Photon.fBits", Photon_fBits, "Photon_fBits[Photon_size]/i");
   skimTree->Branch("Photon.PT", Photon_PT, "Photon_PT[Photon_size]/F");
   skimTree->Branch("Photon.Eta", Photon_Eta, "Photon_Eta[Photon_size]/F");
   skimTree->Branch("Photon.Phi", Photon_Phi, "Photon_Phi[Photon_size]/F");
   skimTree->Branch("Photon.E", Photon_E, "Photon_E[Photon_size]/F");
   skimTree->Branch("Photon.EhadOverEem", Photon_EhadOverEem, "Photon_EhadOverEem[Photon_size]/F");
   skimTree->Branch("Photon.IsolationVar", Photon_IsolationVar, "Photon_IsolationVar[Photon_size]/F");
   //skimTree->Branch("Photon.Particles", Photon_Particles, "Photon_Particles[Photon_size]/F");
   
   skimTree->Branch("Muon_size", &Muon_size, "Muon_size/I");
   skimTree->Branch("Muon", &Muon_, "Muon_/I");
   skimTree->Branch("Muon.fUniqueID", Muon_fUniqueID, "Muon_fUniqueID[Muon_size]/i");
   skimTree->Branch("Muon.fBits", Muon_fBits, "Muon_fBits[Muon_size]/i");
   skimTree->Branch("Muon.PT", Muon_PT, "Muon_PT[Muon_size]/F");
   skimTree->Branch("Muon.Eta", Muon_Eta, "Muon_Eta[Muon_size]/F");
   skimTree->Branch("Muon.Phi", Muon_Phi, "Muon_Phi[Muon_size]/F");
   skimTree->Branch("Muon.Charge", Muon_Charge, "Muon_Charge[Muon_size]/I");
   skimTree->Branch("Muon.IsolationVar", Muon_IsolationVar, "Muon_IsolationVar[Muon_size]/F");
   //skimTree->Branch("Muon.Particle", Muon_Particle, "Muon_Particle/F");

   skimTree->Branch("MissingET_size", &MissingET_size, "MissingET_size/I");
   skimTree->Branch("MissingET", &MissingET_, "MissingET_/I");
   skimTree->Branch("MissingET.fUniqueID", MissingET_fUniqueID, "MissingET_fUniqueID[MissingET_size]/F");
   skimTree->Branch("MissingET.fBits", MissingET_fBits, "MissingET_fBits[MissingET_size]/F");
   skimTree->Branch("MissingET.MET", MissingET_MET, "MissingET_MET[MissingET_size]/F");
   skimTree->Branch("MissingET.Phi", MissingET_Phi, "MissingET_Phi[MissingET_size]/F");

   skimTree->Branch("ScalarHT_size", &ScalarHT_size, "ScalarHT_size/I");
   skimTree->Branch("ScalarHT", &ScalarHT_, "ScalarHT_/I");
   skimTree->Branch("ScalarHT.fUniqueID", ScalarHT_fUniqueID, "ScalarHT_fUniqueID[ScalarHT_size]/F");
   skimTree->Branch("ScalarHT.fBits", ScalarHT_fBits, "ScalarHT_fBits[ScalarHT_size]/F");
   skimTree->Branch("ScalarHT.HT", ScalarHT_HT, "ScalarHT_HT[ScalarHT_size]/F");

   skimTree->Branch("Rho_size", &Rho_size, "Rho_size/I");
   skimTree->Branch("Rho", &Rho_, "Rho_/I");
   skimTree->Branch("Rho.fUniqueID", Rho_fUniqueID, "Rho_fUniqueID[Rho_size]/i");
   skimTree->Branch("Rho.fBits", Rho_fBits, "Rho_fBits[Rho_size]/i");
   skimTree->Branch("Rho.HT", Rho_HT, "Rho_HT[Rho_size]/F");

}

void MyTcZAna::Histogram()
{
   // Definition of histograms
   hist_evt_cut = new TH1D("hist_evt_cut","Event selection cuts", 20, 0, 20);
   hist_evt_cut_eee = new TH1D("hist_evt_cut_eee","Event selection cuts", 20, 0, 20);
   hist_evt_cut_mmm = new TH1D("hist_evt_cut_mmm","Event selection cuts", 20, 0, 20);
   hist_evt_cut_emm = new TH1D("hist_evt_cut_emm","Event selection cuts", 20, 0, 20);
   hist_evt_cut_eem = new TH1D("hist_evt_cut_eem","Eletron selection cuts", 20, 0, 20);
   hist_ele_cut = new TH1D("hist_ele_cut","Eletron selection cuts", 10, 0, 10);
   hist_mu_cut = new TH1D("hist_mu_cut","Muon selection cuts", 10, 0, 10);
   hist_jet_cut = new TH1D("hist_jet_cut","Jet selection cuts", 10, 0, 10);

   hist_ae_pt = new TH1D("hist_ae_pt","e p_{T}",100,0,200);
   hist_ae_eta = new TH1D("hist_ae_eta","e #eta",100,-3.0,3.0);
   hist_ae_phi = new TH1D("hist_ae_phi","e #phi",100,-3.5,3.5);

   hist_e_pt = new TH1D("hist_e_pt","e p_{T}",100,0,200);
   hist_e_eta = new TH1D("hist_e_eta","e #eta",100,-3.0,3.0);
   hist_e_phi = new TH1D("hist_e_phi","e #phi",100,-3.5,3.5);
   hist_e_iso = new TH1D("hist_e_iso","e Rel. Iso.",100,-0.5,0.5);

   hist_am_pt = new TH1D("hist_am_pt","#mu p_{T}",100,0,200);
   hist_am_eta = new TH1D("hist_am_eta","#mu #eta",100,-3.0,3.0);
   hist_am_phi = new TH1D("hist_am_phi","#mu #phi",100,-3.14,3.14);

   hist_m_pt = new TH1D("hist_m_pt","#mu p_{T}",100,0,200);
   hist_m_eta = new TH1D("hist_m_eta","#mu #eta",100,-3.0,3.0);
   hist_m_phi = new TH1D("hist_m_phi","#mu #phi",100,-3.5,3.5);
   hist_m_iso = new TH1D("hist_m_iso","#mu Rel. Iso.",100,-0.5,0.5);

   hist_ge_pt = new TH1D("hist_ge_pt","GEN matched e p_{T}",100,0,200);
   hist_ge_eta = new TH1D("hist_ge_eta","GEN matched e #eta",100,-3.0,3.0);
   hist_ge_phi = new TH1D("hist_ge_phi","GEN matched e #phi",100,-3.14,3.14);

   hist_gm_pt = new TH1D("hist_gm_pt","GEN matched #mu p_{T}",100,0,200);
   hist_gm_eta = new TH1D("hist_gm_eta","GEN matched #mu #eta",100,-3.0,3.0);
   hist_gm_phi = new TH1D("hist_gm_phi","GEN matched #mu #phi",100,-3.14,3.14);

   hist_gel_pt = new TH1D("hist_gel_pt","GEN matched e p_{T}",100,0,200);
   hist_gel_eta = new TH1D("hist_gel_eta","GEN matched e #eta",100,-3.0,3.0);
   hist_gel_phi = new TH1D("hist_gel_phi","GEN matched e #phi",100,-3.14,3.14);

   hist_gml_pt = new TH1D("hist_gml_pt","GEN matched #mu p_{T}",100,0,200);
   hist_gml_eta = new TH1D("hist_gml_eta","GEN matched #mu #eta",100,-3.0,3.0);
   hist_gml_phi = new TH1D("hist_gml_phi","GEN matched #mu #phi",100,-3.14,3.14);
   hist_get_pt = new TH1D("hist_get_pt","GEN matched e p_{T}",100,0,200);
   hist_get_eta = new TH1D("hist_get_eta","GEN matched e #eta",100,-3.0,3.0);
   hist_get_phi = new TH1D("hist_get_phi","GEN matched e #phi",100,-3.14,3.14);

   hist_gmt_pt = new TH1D("hist_gmt_pt","GEN matched #mu p_{T}",100,0,200);
   hist_gmt_eta = new TH1D("hist_gmt_eta","GEN matched #mu #eta",100,-3.0,3.0);
   hist_gmt_phi = new TH1D("hist_gmt_phi","GEN matched #mu #phi",100,-3.14,3.14);

   hist_genz_heli = new TH1D("hist_genz_heli","GEN Z helicity",20,-1.,1.);
   hist_genw_heli = new TH1D("hist_genw_heli","GEN W helicity",20,-1.,1.);

   hist_te_pt = new TH1D("hist_te_pt","tight e p_{T}",100,0,200);
   hist_te_eta = new TH1D("hist_te_eta","tight e #eta",100,-3.0,3.0);
   hist_te_phi = new TH1D("hist_te_phi","tight e #phi",100,-3.14,3.14);

   hist_tm_pt = new TH1D("hist_tm_pt","tight #mu p_{T}",100,0,200);
   hist_tm_eta = new TH1D("hist_tm_eta","tight #mu #eta",100,-3.0,3.0);
   hist_tm_phi = new TH1D("hist_tm_phi","tight #mu #phi",100,-3.14,3.14);

   hist_zmm_m = new TH1D("hist_zmm_m","inv mass of Z(#mu^{+} #mu^{-})",50,60,120);
   hist_zee_m = new TH1D("hist_zee_m","inv mass of Z(e^{+} e^{-})",50,60,120);
   hist_zmm_pt = new TH1D("hist_zmm_pt","p_{T} of Z(#mu^{+} #mu^{-})",100,0,200);
   hist_zee_pt = new TH1D("hist_zee_pt","p_{T} of Z(e^{+} e^{-})",100,0,200);

   hist_zmm_n = new TH1D("hist_zmm_n", "No. of Z candidates (#mu)",5,0,5.);
   hist_zee_n = new TH1D("hist_zee_n", "No. of Z candidates (e)",5,0,5.);
   hist_z_n = new TH1D("hist_z_n", "No. of Z candidates (e/#mu)",5,0,5.);

   hist_zmm_w_m = new TH1D("hist_zmm_w_m","inv mass of Z(#mu^{+} #mu^{-}",50,60,120);
   hist_zee_w_m = new TH1D("hist_zee_w_m","inv mass of Z(e^{+} e^{-})",50,60,120);

   hist_z_m_t = new TH1D("hist_z_m_t","t inv mass of Z(#mu^{+} #mu^{-})",50,60,120);
   hist_z_pt_t = new TH1D("hist_z_pt_t","t p_{T} of Z(#mu^{+} #mu^{-})",100,0,200);

   hist_wen_m = new TH1D("hist_wen_m","invariant mass of W(e #nu)",50,0,250);
   hist_wmn_m = new TH1D("hist_wmn_m","invariant mass of W(#mu #nu)",50,0,250);
   hist_wen_mt = new TH1D("hist_wen_mt","transverse mass of W(e #nu)",50,0,250);
   hist_wmn_mt = new TH1D("hist_wmn_mt","transverse mass of W(#mu #nu)",50,0,250);
   hist_wen_gmt = new TH1D("hist_wen_gmt","trans. mass of gen W(e #nu)",50,0,250);
   hist_wmn_gmt = new TH1D("hist_wmn_gmt","trans. mass of gen W(#mu #nu)",50,0,250);
   hist_w_wmt_h = new TH1D("hist_wen_wmt_h","transverse mass of W high pt",50,0,200);
   hist_w_wmt_l = new TH1D("hist_wmn_wmt_l","transverse mass of W low pt",50,0,200);
   hist_w_n = new TH1D("hist_w_n","No. of W candidates (e/#mu)",5,0,5);
   hist_wen_mt_met = new TH2D("hist_wen_mt_met","Mt of W(e #nu) vs. MET",50,0,150,50,0,100);
   hist_wmn_mt_met = new TH2D("hist_wmn_mt_met","Mt of W(#mu #nu) vs. MET",50,0,150,50,0,100);
   hist_wen_pt = new TH1D("hist_wen_pt","p_{T} of W(e #nu)",50,0,250);
   hist_wmn_pt = new TH1D("hist_wmn_pt","p_{T} of W(#mu #nu)",50,0,250);
   hist_wen_n = new TH1D("hist_wen_n", "No. of W candidates (e)",5,0,5.);
   hist_wmn_n = new TH1D("hist_wmn_n", "No. of W candidates (#mu)",5,0,5.);

   hist_wen_mt_ee = new TH1D("hist_wen_mt_ee","transverse mass of W(e #nu)",50,0,250);
   hist_wen_mt_mm = new TH1D("hist_wen_mt_mm","transverse mass of W(e #nu)",50,0,250);
   hist_wmn_mt_ee = new TH1D("hist_wmn_mt_ee","transverse mass of W(#mu #nu)",50,0,250);
   hist_wmn_mt_mm = new TH1D("hist_wmn_mt_mm","transverse mass of W(#mu #nu)",50,0,250);


   hist_e_no = new TH1D("hist_e_no", "No. of electons",10,0,10);
   hist_m_no = new TH1D("hist_m_no", "No. of muons",10,0,10);
   hist_lep_no = new TH1D("hist_lep_no", "No. of leptons",10,0,10);
   hist_wz_no = new TH1D("hist_wz_no", "No. of W+Z",5,0,5);

   hist_jet_pt = new TH1D("hist_jet_pt", "p_{T} of jet",100,0,150);
   hist_jet_eta = new TH1D("hist_jet_eta", "#eta of jet",100,-3.,3.);
   hist_jet_phi = new TH1D("hist_jet_phi", "#phi of jet",100,-3.5,3.5);
   hist_ajet_pt = new TH1D("hist_ajet_pt", "p_{T} of jet",100,0,150);
   hist_ajet_eta = new TH1D("hist_ajet_eta", "#eta of jet",100,-3.,3.);
   hist_ajet_phi = new TH1D("hist_ajet_phi", "#phi of jet",100,-3.5,3.5);
   hist_gjet_pt = new TH1D("hist_gjet_pt", "p_{T} of gjet",100,0,150);
   hist_gjet_eta = new TH1D("hist_gjet_eta", "#eta of gjet",100,-3.,3.);
   hist_gjet_phi = new TH1D("hist_gjet_phi", "#phi of gjet",100,-3.5,3.5);
   hist_gjetc_pt = new TH1D("hist_gjetc_pt", "p_{T} of gjetc",100,0,150);
   hist_gjetc_eta = new TH1D("hist_gjetc_eta", "#eta of gjetc",100,-3.,3.);
   hist_gjetc_phi = new TH1D("hist_gjetc_phi", "#phi of gjetc",100,-3.5,3.5);
   hist_jet_disc = new TH1D("hist_jet_disc", "Disc of jet",100,-15,15);
   hist_jet_fish = new TH1D("hist_jet_fish", "Jet cleaning fisher",100,0,1.);
   hist_jet_no = new TH1D("hist_jet_no", "No. of jets",10,0,10);
   hist_jet_no_c = new TH1D("hist_jet_no_c", "No. of jets Cleaned",10,0,10);
   hist_jet_flav = new TH1D("hist_jet_flav", "Jet flavour",10,0,10);
   hist_jet_dz = new TH1D("hist_jet_dz", "#Delta z of Jet",100,-20.,20.);

   hist_jet_ptb = new TH1D("hist_jet_ptb", "p_{T} of jet to b",100,0,250);

   hist_njet_mt = new TH2D("hist_njet_mt", "Jet # vs. Mt(W)", 5, 0, 5, 10, 0, 150);
   
   hist_jet_pt1 = new TH1D("hist_jet_pt1", "p_{T} of 1st jet",100,0,150);
   hist_jet_pt2 = new TH1D("hist_jet_pt2", "p_{T} of 2nd jet",100,0,150);
   hist_jet_pt3 = new TH1D("hist_jet_pt3", "p_{T} of 3rd jet",100,0,150);

   hist_jet_eta1 = new TH1D("hist_jet_eta1", "#eta of 1st jet",100,-3, 3);
   hist_jet_eta2 = new TH1D("hist_jet_eta2", "#eta of 2nd jet",100,-3, 3);
   hist_jet_eta12 = new TH1D("hist_jet_eta12", "#Delta #eta of two jet",100,0, 6.3);
 
  hist_met_sumEt = new TH1D("hist_met_sumEt", "Sum E_{T} of MET",50,0,1000);
   hist_met_pt = new TH1D("hist_met_pt", "p_{T} of MET",100,0,150);
   hist_met_phi = new TH1D("hist_met_phi", "#phi of MET",100,-3.5,3.5);

   hist_met_pt_ee = new TH1D("hist_met_pt_ee", "p_{T} of MET ee",100,0,150);
   hist_met_pt_mm = new TH1D("hist_met_pt_mm", "p_{T} of MET mm",100,0,150);
   hist_met_pt_eel = new TH1D("hist_met_pt_eel", "p_{T} of MET eel",100,0,150);
   hist_met_pt_mml = new TH1D("hist_met_pt_mml", "p_{T} of MET mml",100,0,150);

   hist_met_cuts = new TH1D("hist_met_cuts", "p_{T} of MET cuts",20,0,200);

   hist_wet_cuts = new TH1D("hist_wet_cuts", "m_{T} of Wel cuts",20,0,200);
   hist_wmt_cuts = new TH1D("hist_wmt_cuts", "m_{T} of Wml cuts",20,0,200);
   hist_mt_cuts = new TH1D("hist_mt_cuts", "m_{T} of W cuts",20,0,200);

   hist_top_m_cz = new TH1D("hist_top_m_cz","inv mass of t(c Z) all",25,100,350);
   hist_top_m_bw = new TH1D("hist_top_m_bw","inv mass of t(b W) all",25,100,350);
   hist_top_m_cz_f = new TH1D("hist_top_m_cz_f","inv mass of t(c Z)",25,100,350);
   hist_top_m_bw_f = new TH1D("hist_top_m_bw_f","inv mass of t(b W)",25,100,350);
   hist_top_m_cz_g = new TH1D("hist_top_m_cz_g","inv mass of gen t(c Z)",25,100,350);
   hist_top_m_bw_g = new TH1D("hist_top_m_bw_g","inv mass of gen t(b W)",25,100,350);
   hist_top_m_cz_fb = new TH1D("hist_top_m_cz_fb","inv mass of t(c Z) b",25,100,350);
   hist_top_m_bw_fb = new TH1D("hist_top_m_bw_fb","inv mass of t(b W) b",25,100,350);
   hist_top_m_cz_tr = new TH1D("hist_top_m_cz_tr","Traced inv mass of t(c Z)",25,100,350);
   hist_top_m_bw_tr = new TH1D("hist_top_m_bw_tr","Traced inv mass of t(b W)",25,100,350);
   hist_top_mt_cz = new TH1D("hist_top_mt_cz","Trans. inv mass of t(c Z)",25,100,350);
   hist_top_mt_bw = new TH1D("hist_top_mt_bw","Trans. inv mass of b'(b W)",25,100,350);
   hist_top_mt_cz_f = new TH1D("hist_top_mt_cz_f","Trans. inv mass of t(c Z)",25,100,350);
   hist_top_mt_bw_f = new TH1D("hist_top_mt_bw_f","Trans. inv mass of t(b W)",25,100,350);
   hist_top_mt_cz_fb = new TH1D("hist_top_mt_cz_fb","Trans. inv mass of t(c Z)",25,100,350);
   hist_top_mt_bw_fb = new TH1D("hist_top_mt_bw_fb","Trans. inv mass of t(b W)",25,100,350);
   hist_top_mt_cz_tr = new TH1D("hist_top_mt_cz_tr","Trans. inv mass of t(c Z)",25,100,350);
   hist_top_mt_bw_tr = new TH1D("hist_top_mt_bw_tr","Trans. inv mass of t(b W)",25,100,350);
   hist_top_pt_cz = new TH1D("hist_top_pt_cz","Trans. mom. of t(c Z)",30, 0,300);
   hist_top_pt_bw = new TH1D("hist_top_pt_bw","Trans. mom. of t(b W)",30, 0,300);
   hist_top_pt_cz_f = new TH1D("hist_top_pt_cz_f","Trans. mom. of t(c Z)",30, 0,300);
   hist_top_pt_bw_f = new TH1D("hist_top_pt_bw_f","Trans. mom. of t(b W)",30, 0,300);
   hist_top_pt_cz_tr = new TH1D("hist_top_pt_cz_tr","Trans. mom. of t(c Z)",30, 0,300);
   hist_top_pt_bw_tr = new TH1D("hist_top_pt_bw_tr","Trans. mom. of t(b W)",30, 0,300);
   hist_top_eta_cz = new TH1D("hist_top_eta_cz","#eta of t(c Z)",20,-2.5,2.5);
   hist_top_eta_bw = new TH1D("hist_top_eta_bw","#eta of t(b W)",20,-2.5,2.5);
   hist_top_eta_cz_f = new TH1D("hist_top_eta_cz_f","#eta of t(c Z)",20,-2.5,2.5);
   hist_top_eta_bw_f = new TH1D("hist_top_eta_bw_f","#eta of t(b W)",20,-2.5,2.5);
   hist_top_eta_cz_g = new TH1D("hist_top_eta_cz_g","#eta of t(c Z)",20,-2.5,2.5);
   hist_top_eta_bw_g = new TH1D("hist_top_eta_bw_g","#eta of t(b W)",20,-2.5,2.5);
   hist_top_eta_cz_gt = new TH1D("hist_top_eta_cz_gt","#eta of t(c Z)",20,-2.5,2.5);
   hist_top_eta_bw_gt = new TH1D("hist_top_eta_bw_gt","#eta of t(b W)",20,-2.5,2.5);
   hist_top_eta_cz_tr = new TH1D("hist_top_eta_cz_tr","#eta of t(c Z)",20,-2.5,2.5);
   hist_top_eta_bw_tr = new TH1D("hist_top_eta_bw_tr","#eta of t(b W)",20,-2.5,2.5);
   hist_top_dphi = new TH1D("hist_top_dphi","#Delta #phi of Top pair",100,-3.5,3.5);
   hist_top_gdphi = new TH1D("hist_top_gdphi","#Delta #phi of gen Top pair",100,-3.5,3.5);

   hist_top_dr_ch = new TH1D("hist_top_dr_ch","dr t(c Z)",100, 0, 3.5);
   hist_top_dr_bw = new TH1D("hist_top_dr_bw","dr t(b W)",100, 0, 3.5);
   hist_top_no = new TH1D("hist_top_no","# of Top candidates",100, 0, 50);

}

Bool_t MyTcZAna::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MyTcZAna::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MyTcZAna::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

double MyTcZAna::DeltaPhi(TLorentzVector v1, TLorentzVector v2){
  cout << "(" << v1.Phi() << ", " << v2.Phi() << ")";
  //return TVector2::Phi_mpi_pi(v1.Phi()-v2.Phi());
  return (v1.Phi()-v2.Phi());
}
double MyTcZAna::DeltaPhi(double v1, double v2){
  //cout << "(" << v1 << ", " << v2 << ")";
  return TVector2::Phi_mpi_pi(v1-v2);
  //return (v1-v2);
}
double MyTcZAna::DeltaR(TLorentzVector v1, TLorentzVector v2){
  //return TVector2::Phi_mpi_pi(v1.Phi()-v2.Phi());
  return (v1.Phi()-v2.Phi());
}

#endif // #ifdef MyTcZAna_cxx
