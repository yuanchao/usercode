//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 14 14:56:58 2015 by ROOT version 5.34/07
// from TTree Delphes/Analysis tree
// found on file: zprime.root
//////////////////////////////////////////////////////////

#ifndef MyCZpSelector_h
#define MyCZpSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>
#include <TObject.h>
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"
#include "./classes/DelphesClasses.h"

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxEvent = 1;
const Int_t kMaxParticle = 3942;
const Int_t kMaxGenJet = 85;
const Int_t kMaxChargedHadron = 319;
const Int_t kMaxNeutralHadron = 489;
const Int_t kMaxPhoton = 694;
const Int_t kMaxElectron = 9;
const Int_t kMaxMuon = 7;
const Int_t kMaxJet = 78;
const Int_t kMaxMissingET = 1;
const Int_t kMaxScalarHT = 1;

class MyCZpSelector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

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
   Int_t           Particle_size;
   Int_t           GenJet_;
   UInt_t          GenJet_fUniqueID[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_fBits[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PT[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Eta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Phi[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_T[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Mass[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaEta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_DeltaPhi[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_BTag[kMaxGenJet];   //[GenJet_]
   UInt_t          GenJet_TauTag[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_Charge[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_EhadOverEem[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NCharged[kMaxGenJet];   //[GenJet_]
   Int_t           GenJet_NNeutrals[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Beta[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_BetaStar[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_MeanSqDeltaR[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_PTD[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_FracPt[kMaxGenJet][5];   //[GenJet_]
   Float_t         GenJet_Tau1[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Tau2[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Tau3[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Tau4[kMaxGenJet];   //[GenJet_]
   Float_t         GenJet_Tau5[kMaxGenJet];   //[GenJet_]
   TRefArray       GenJet_Constituents[kMaxGenJet];
   TRefArray       GenJet_Particles[kMaxGenJet];
   Int_t           GenJet_size;
   Int_t           ChargedHadron_;
   UInt_t          ChargedHadron_fUniqueID[kMaxChargedHadron];   //[ChargedHadron_]
   UInt_t          ChargedHadron_fBits[kMaxChargedHadron];   //[ChargedHadron_]
   Int_t           ChargedHadron_PID[kMaxChargedHadron];   //[ChargedHadron_]
   Int_t           ChargedHadron_Charge[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_PT[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_Eta[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_Phi[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_EtaOuter[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_PhiOuter[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_X[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_Y[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_Z[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_T[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_XOuter[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_YOuter[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_ZOuter[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_TOuter[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_Dxy[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_SDxy[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_Xd[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_Yd[kMaxChargedHadron];   //[ChargedHadron_]
   Float_t         ChargedHadron_Zd[kMaxChargedHadron];   //[ChargedHadron_]
   TRef            ChargedHadron_Particle[kMaxChargedHadron];
   Int_t           ChargedHadron_size;
   Int_t           NeutralHadron_;
   UInt_t          NeutralHadron_fUniqueID[kMaxNeutralHadron];   //[NeutralHadron_]
   UInt_t          NeutralHadron_fBits[kMaxNeutralHadron];   //[NeutralHadron_]
   Float_t         NeutralHadron_ET[kMaxNeutralHadron];   //[NeutralHadron_]
   Float_t         NeutralHadron_Eta[kMaxNeutralHadron];   //[NeutralHadron_]
   Float_t         NeutralHadron_Phi[kMaxNeutralHadron];   //[NeutralHadron_]
   Float_t         NeutralHadron_E[kMaxNeutralHadron];   //[NeutralHadron_]
   Float_t         NeutralHadron_T[kMaxNeutralHadron];   //[NeutralHadron_]
   Float_t         NeutralHadron_Eem[kMaxNeutralHadron];   //[NeutralHadron_]
   Float_t         NeutralHadron_Ehad[kMaxNeutralHadron];   //[NeutralHadron_]
   Float_t         NeutralHadron_Edges[kMaxNeutralHadron][4];   //[NeutralHadron_]
   TRefArray       NeutralHadron_Particles[kMaxNeutralHadron];
   Int_t           NeutralHadron_size;
   Int_t           Photon_;
   UInt_t          Photon_fUniqueID[kMaxPhoton];   //[Photon_]
   UInt_t          Photon_fBits[kMaxPhoton];   //[Photon_]
   Float_t         Photon_PT[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Eta[kMaxPhoton];   //[Photon_]
   Float_t         Photon_Phi[kMaxPhoton];   //[Photon_]
   Float_t         Photon_E[kMaxPhoton];   //[Photon_]
   Float_t         Photon_T[kMaxPhoton];   //[Photon_]
   Float_t         Photon_EhadOverEem[kMaxPhoton];   //[Photon_]
   TRefArray       Photon_Particles[kMaxPhoton];
   Int_t           Photon_size;
   Int_t           Electron_;
   UInt_t          Electron_fUniqueID[kMaxElectron];   //[Electron_]
   UInt_t          Electron_fBits[kMaxElectron];   //[Electron_]
   Float_t         Electron_PT[kMaxElectron];   //[Electron_]
   Float_t         Electron_Eta[kMaxElectron];   //[Electron_]
   Float_t         Electron_Phi[kMaxElectron];   //[Electron_]
   Float_t         Electron_T[kMaxElectron];   //[Electron_]
   Int_t           Electron_Charge[kMaxElectron];   //[Electron_]
   Float_t         Electron_EhadOverEem[kMaxElectron];   //[Electron_]
   TRef            Electron_Particle[kMaxElectron];
   Int_t           Electron_size;
   Int_t           Muon_;
   UInt_t          Muon_fUniqueID[kMaxMuon];   //[Muon_]
   UInt_t          Muon_fBits[kMaxMuon];   //[Muon_]
   Float_t         Muon_PT[kMaxMuon];   //[Muon_]
   Float_t         Muon_Eta[kMaxMuon];   //[Muon_]
   Float_t         Muon_Phi[kMaxMuon];   //[Muon_]
   Float_t         Muon_T[kMaxMuon];   //[Muon_]
   Int_t           Muon_Charge[kMaxMuon];   //[Muon_]
   TRef            Muon_Particle[kMaxMuon];
   Int_t           Muon_size;
   Int_t           Jet_;
   UInt_t          Jet_fUniqueID[kMaxJet];   //[Jet_]
   UInt_t          Jet_fBits[kMaxJet];   //[Jet_]
   Float_t         Jet_PT[kMaxJet];   //[Jet_]
   Float_t         Jet_Eta[kMaxJet];   //[Jet_]
   Float_t         Jet_Phi[kMaxJet];   //[Jet_]
   Float_t         Jet_T[kMaxJet];   //[Jet_]
   Float_t         Jet_Mass[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaEta[kMaxJet];   //[Jet_]
   Float_t         Jet_DeltaPhi[kMaxJet];   //[Jet_]
   UInt_t          Jet_BTag[kMaxJet];   //[Jet_]
   UInt_t          Jet_TauTag[kMaxJet];   //[Jet_]
   Int_t           Jet_Charge[kMaxJet];   //[Jet_]
   Float_t         Jet_EhadOverEem[kMaxJet];   //[Jet_]
   Int_t           Jet_NCharged[kMaxJet];   //[Jet_]
   Int_t           Jet_NNeutrals[kMaxJet];   //[Jet_]
   Float_t         Jet_Beta[kMaxJet];   //[Jet_]
   Float_t         Jet_BetaStar[kMaxJet];   //[Jet_]
   Float_t         Jet_MeanSqDeltaR[kMaxJet];   //[Jet_]
   Float_t         Jet_PTD[kMaxJet];   //[Jet_]
   Float_t         Jet_FracPt[kMaxJet][5];   //[Jet_]
   Float_t         Jet_Tau1[kMaxJet];   //[Jet_]
   Float_t         Jet_Tau2[kMaxJet];   //[Jet_]
   Float_t         Jet_Tau3[kMaxJet];   //[Jet_]
   Float_t         Jet_Tau4[kMaxJet];   //[Jet_]
   Float_t         Jet_Tau5[kMaxJet];   //[Jet_]
   TRefArray       Jet_Constituents[kMaxJet];
   TRefArray       Jet_Particles[kMaxJet];
   Int_t           Jet_size;
   Int_t           MissingET_;
   UInt_t          MissingET_fUniqueID[kMaxMissingET];   //[MissingET_]
   UInt_t          MissingET_fBits[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_MET[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Eta[kMaxMissingET];   //[MissingET_]
   Float_t         MissingET_Phi[kMaxMissingET];   //[MissingET_]
   Int_t           MissingET_size;
   Int_t           ScalarHT_;
   UInt_t          ScalarHT_fUniqueID[kMaxScalarHT];   //[ScalarHT_]
   UInt_t          ScalarHT_fBits[kMaxScalarHT];   //[ScalarHT_]
   Float_t         ScalarHT_HT[kMaxScalarHT];   //[ScalarHT_]
   Int_t           ScalarHT_size;

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
   TBranch        *b_GenJet_;   //!
   TBranch        *b_GenJet_fUniqueID;   //!
   TBranch        *b_GenJet_fBits;   //!
   TBranch        *b_GenJet_PT;   //!
   TBranch        *b_GenJet_Eta;   //!
   TBranch        *b_GenJet_Phi;   //!
   TBranch        *b_GenJet_T;   //!
   TBranch        *b_GenJet_Mass;   //!
   TBranch        *b_GenJet_DeltaEta;   //!
   TBranch        *b_GenJet_DeltaPhi;   //!
   TBranch        *b_GenJet_BTag;   //!
   TBranch        *b_GenJet_TauTag;   //!
   TBranch        *b_GenJet_Charge;   //!
   TBranch        *b_GenJet_EhadOverEem;   //!
   TBranch        *b_GenJet_NCharged;   //!
   TBranch        *b_GenJet_NNeutrals;   //!
   TBranch        *b_GenJet_Beta;   //!
   TBranch        *b_GenJet_BetaStar;   //!
   TBranch        *b_GenJet_MeanSqDeltaR;   //!
   TBranch        *b_GenJet_PTD;   //!
   TBranch        *b_GenJet_FracPt;   //!
   TBranch        *b_GenJet_Tau1;   //!
   TBranch        *b_GenJet_Tau2;   //!
   TBranch        *b_GenJet_Tau3;   //!
   TBranch        *b_GenJet_Tau4;   //!
   TBranch        *b_GenJet_Tau5;   //!
   TBranch        *b_GenJet_Constituents;   //!
   TBranch        *b_GenJet_Particles;   //!
   TBranch        *b_GenJet_size;   //!
   TBranch        *b_ChargedHadron_;   //!
   TBranch        *b_ChargedHadron_fUniqueID;   //!
   TBranch        *b_ChargedHadron_fBits;   //!
   TBranch        *b_ChargedHadron_PID;   //!
   TBranch        *b_ChargedHadron_Charge;   //!
   TBranch        *b_ChargedHadron_PT;   //!
   TBranch        *b_ChargedHadron_Eta;   //!
   TBranch        *b_ChargedHadron_Phi;   //!
   TBranch        *b_ChargedHadron_EtaOuter;   //!
   TBranch        *b_ChargedHadron_PhiOuter;   //!
   TBranch        *b_ChargedHadron_X;   //!
   TBranch        *b_ChargedHadron_Y;   //!
   TBranch        *b_ChargedHadron_Z;   //!
   TBranch        *b_ChargedHadron_T;   //!
   TBranch        *b_ChargedHadron_XOuter;   //!
   TBranch        *b_ChargedHadron_YOuter;   //!
   TBranch        *b_ChargedHadron_ZOuter;   //!
   TBranch        *b_ChargedHadron_TOuter;   //!
   TBranch        *b_ChargedHadron_Dxy;   //!
   TBranch        *b_ChargedHadron_SDxy;   //!
   TBranch        *b_ChargedHadron_Xd;   //!
   TBranch        *b_ChargedHadron_Yd;   //!
   TBranch        *b_ChargedHadron_Zd;   //!
   TBranch        *b_ChargedHadron_Particle;   //!
   TBranch        *b_ChargedHadron_size;   //!
   TBranch        *b_NeutralHadron_;   //!
   TBranch        *b_NeutralHadron_fUniqueID;   //!
   TBranch        *b_NeutralHadron_fBits;   //!
   TBranch        *b_NeutralHadron_ET;   //!
   TBranch        *b_NeutralHadron_Eta;   //!
   TBranch        *b_NeutralHadron_Phi;   //!
   TBranch        *b_NeutralHadron_E;   //!
   TBranch        *b_NeutralHadron_T;   //!
   TBranch        *b_NeutralHadron_Eem;   //!
   TBranch        *b_NeutralHadron_Ehad;   //!
   TBranch        *b_NeutralHadron_Edges;   //!
   TBranch        *b_NeutralHadron_Particles;   //!
   TBranch        *b_NeutralHadron_size;   //!
   TBranch        *b_Photon_;   //!
   TBranch        *b_Photon_fUniqueID;   //!
   TBranch        *b_Photon_fBits;   //!
   TBranch        *b_Photon_PT;   //!
   TBranch        *b_Photon_Eta;   //!
   TBranch        *b_Photon_Phi;   //!
   TBranch        *b_Photon_E;   //!
   TBranch        *b_Photon_T;   //!
   TBranch        *b_Photon_EhadOverEem;   //!
   TBranch        *b_Photon_Particles;   //!
   TBranch        *b_Photon_size;   //!
   TBranch        *b_Electron_;   //!
   TBranch        *b_Electron_fUniqueID;   //!
   TBranch        *b_Electron_fBits;   //!
   TBranch        *b_Electron_PT;   //!
   TBranch        *b_Electron_Eta;   //!
   TBranch        *b_Electron_Phi;   //!
   TBranch        *b_Electron_T;   //!
   TBranch        *b_Electron_Charge;   //!
   TBranch        *b_Electron_EhadOverEem;   //!
   TBranch        *b_Electron_Particle;   //!
   TBranch        *b_Electron_size;   //!
   TBranch        *b_Muon_;   //!
   TBranch        *b_Muon_fUniqueID;   //!
   TBranch        *b_Muon_fBits;   //!
   TBranch        *b_Muon_PT;   //!
   TBranch        *b_Muon_Eta;   //!
   TBranch        *b_Muon_Phi;   //!
   TBranch        *b_Muon_T;   //!
   TBranch        *b_Muon_Charge;   //!
   TBranch        *b_Muon_Particle;   //!
   TBranch        *b_Muon_size;   //!
   TBranch        *b_Jet_;   //!
   TBranch        *b_Jet_fUniqueID;   //!
   TBranch        *b_Jet_fBits;   //!
   TBranch        *b_Jet_PT;   //!
   TBranch        *b_Jet_Eta;   //!
   TBranch        *b_Jet_Phi;   //!
   TBranch        *b_Jet_T;   //!
   TBranch        *b_Jet_Mass;   //!
   TBranch        *b_Jet_DeltaEta;   //!
   TBranch        *b_Jet_DeltaPhi;   //!
   TBranch        *b_Jet_BTag;   //!
   TBranch        *b_Jet_TauTag;   //!
   TBranch        *b_Jet_Charge;   //!
   TBranch        *b_Jet_EhadOverEem;   //!
   TBranch        *b_Jet_NCharged;   //!
   TBranch        *b_Jet_NNeutrals;   //!
   TBranch        *b_Jet_Beta;   //!
   TBranch        *b_Jet_BetaStar;   //!
   TBranch        *b_Jet_MeanSqDeltaR;   //!
   TBranch        *b_Jet_PTD;   //!
   TBranch        *b_Jet_FracPt;   //!
   TBranch        *b_Jet_Tau1;   //!
   TBranch        *b_Jet_Tau2;   //!
   TBranch        *b_Jet_Tau3;   //!
   TBranch        *b_Jet_Tau4;   //!
   TBranch        *b_Jet_Tau5;   //!
   TBranch        *b_Jet_Constituents;   //!
   TBranch        *b_Jet_Particles;   //!
   TBranch        *b_Jet_size;   //!
   TBranch        *b_MissingET_;   //!
   TBranch        *b_MissingET_fUniqueID;   //!
   TBranch        *b_MissingET_fBits;   //!
   TBranch        *b_MissingET_MET;   //!
   TBranch        *b_MissingET_Eta;   //!
   TBranch        *b_MissingET_Phi;   //!
   TBranch        *b_MissingET_size;   //!
   TBranch        *b_ScalarHT_;   //!
   TBranch        *b_ScalarHT_fUniqueID;   //!
   TBranch        *b_ScalarHT_fBits;   //!
   TBranch        *b_ScalarHT_HT;   //!
   TBranch        *b_ScalarHT_size;   //!

   MyCZpSelector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~MyCZpSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(MyCZpSelector,0);
};

#endif

#ifdef MyCZpSelector_cxx
void MyCZpSelector::Init(TTree *tree)
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
   fChain->SetBranchAddress("GenJet", &GenJet_, &b_GenJet_);
   fChain->SetBranchAddress("GenJet.fUniqueID", GenJet_fUniqueID, &b_GenJet_fUniqueID);
   fChain->SetBranchAddress("GenJet.fBits", GenJet_fBits, &b_GenJet_fBits);
   fChain->SetBranchAddress("GenJet.PT", GenJet_PT, &b_GenJet_PT);
   fChain->SetBranchAddress("GenJet.Eta", GenJet_Eta, &b_GenJet_Eta);
   fChain->SetBranchAddress("GenJet.Phi", GenJet_Phi, &b_GenJet_Phi);
   fChain->SetBranchAddress("GenJet.T", GenJet_T, &b_GenJet_T);
   fChain->SetBranchAddress("GenJet.Mass", GenJet_Mass, &b_GenJet_Mass);
   fChain->SetBranchAddress("GenJet.DeltaEta", GenJet_DeltaEta, &b_GenJet_DeltaEta);
   fChain->SetBranchAddress("GenJet.DeltaPhi", GenJet_DeltaPhi, &b_GenJet_DeltaPhi);
   fChain->SetBranchAddress("GenJet.BTag", GenJet_BTag, &b_GenJet_BTag);
   fChain->SetBranchAddress("GenJet.TauTag", GenJet_TauTag, &b_GenJet_TauTag);
   fChain->SetBranchAddress("GenJet.Charge", GenJet_Charge, &b_GenJet_Charge);
   fChain->SetBranchAddress("GenJet.EhadOverEem", GenJet_EhadOverEem, &b_GenJet_EhadOverEem);
   fChain->SetBranchAddress("GenJet.NCharged", GenJet_NCharged, &b_GenJet_NCharged);
   fChain->SetBranchAddress("GenJet.NNeutrals", GenJet_NNeutrals, &b_GenJet_NNeutrals);
   fChain->SetBranchAddress("GenJet.Beta", GenJet_Beta, &b_GenJet_Beta);
   fChain->SetBranchAddress("GenJet.BetaStar", GenJet_BetaStar, &b_GenJet_BetaStar);
   fChain->SetBranchAddress("GenJet.MeanSqDeltaR", GenJet_MeanSqDeltaR, &b_GenJet_MeanSqDeltaR);
   fChain->SetBranchAddress("GenJet.PTD", GenJet_PTD, &b_GenJet_PTD);
   fChain->SetBranchAddress("GenJet.FracPt[5]", GenJet_FracPt, &b_GenJet_FracPt);
   fChain->SetBranchAddress("GenJet.Tau1", GenJet_Tau1, &b_GenJet_Tau1);
   fChain->SetBranchAddress("GenJet.Tau2", GenJet_Tau2, &b_GenJet_Tau2);
   fChain->SetBranchAddress("GenJet.Tau3", GenJet_Tau3, &b_GenJet_Tau3);
   fChain->SetBranchAddress("GenJet.Tau4", GenJet_Tau4, &b_GenJet_Tau4);
   fChain->SetBranchAddress("GenJet.Tau5", GenJet_Tau5, &b_GenJet_Tau5);
   fChain->SetBranchAddress("GenJet.Constituents", GenJet_Constituents, &b_GenJet_Constituents);
   fChain->SetBranchAddress("GenJet.Particles", GenJet_Particles, &b_GenJet_Particles);
   fChain->SetBranchAddress("GenJet_size", &GenJet_size, &b_GenJet_size);
   fChain->SetBranchAddress("ChargedHadron", &ChargedHadron_, &b_ChargedHadron_);
   fChain->SetBranchAddress("ChargedHadron.fUniqueID", ChargedHadron_fUniqueID, &b_ChargedHadron_fUniqueID);
   fChain->SetBranchAddress("ChargedHadron.fBits", ChargedHadron_fBits, &b_ChargedHadron_fBits);
   fChain->SetBranchAddress("ChargedHadron.PID", ChargedHadron_PID, &b_ChargedHadron_PID);
   fChain->SetBranchAddress("ChargedHadron.Charge", ChargedHadron_Charge, &b_ChargedHadron_Charge);
   fChain->SetBranchAddress("ChargedHadron.PT", ChargedHadron_PT, &b_ChargedHadron_PT);
   fChain->SetBranchAddress("ChargedHadron.Eta", ChargedHadron_Eta, &b_ChargedHadron_Eta);
   fChain->SetBranchAddress("ChargedHadron.Phi", ChargedHadron_Phi, &b_ChargedHadron_Phi);
   fChain->SetBranchAddress("ChargedHadron.EtaOuter", ChargedHadron_EtaOuter, &b_ChargedHadron_EtaOuter);
   fChain->SetBranchAddress("ChargedHadron.PhiOuter", ChargedHadron_PhiOuter, &b_ChargedHadron_PhiOuter);
   fChain->SetBranchAddress("ChargedHadron.X", ChargedHadron_X, &b_ChargedHadron_X);
   fChain->SetBranchAddress("ChargedHadron.Y", ChargedHadron_Y, &b_ChargedHadron_Y);
   fChain->SetBranchAddress("ChargedHadron.Z", ChargedHadron_Z, &b_ChargedHadron_Z);
   fChain->SetBranchAddress("ChargedHadron.T", ChargedHadron_T, &b_ChargedHadron_T);
   fChain->SetBranchAddress("ChargedHadron.XOuter", ChargedHadron_XOuter, &b_ChargedHadron_XOuter);
   fChain->SetBranchAddress("ChargedHadron.YOuter", ChargedHadron_YOuter, &b_ChargedHadron_YOuter);
   fChain->SetBranchAddress("ChargedHadron.ZOuter", ChargedHadron_ZOuter, &b_ChargedHadron_ZOuter);
   fChain->SetBranchAddress("ChargedHadron.TOuter", ChargedHadron_TOuter, &b_ChargedHadron_TOuter);
   fChain->SetBranchAddress("ChargedHadron.Dxy", ChargedHadron_Dxy, &b_ChargedHadron_Dxy);
   fChain->SetBranchAddress("ChargedHadron.SDxy", ChargedHadron_SDxy, &b_ChargedHadron_SDxy);
   fChain->SetBranchAddress("ChargedHadron.Xd", ChargedHadron_Xd, &b_ChargedHadron_Xd);
   fChain->SetBranchAddress("ChargedHadron.Yd", ChargedHadron_Yd, &b_ChargedHadron_Yd);
   fChain->SetBranchAddress("ChargedHadron.Zd", ChargedHadron_Zd, &b_ChargedHadron_Zd);
   fChain->SetBranchAddress("ChargedHadron.Particle", ChargedHadron_Particle, &b_ChargedHadron_Particle);
   fChain->SetBranchAddress("ChargedHadron_size", &ChargedHadron_size, &b_ChargedHadron_size);
   fChain->SetBranchAddress("NeutralHadron", &NeutralHadron_, &b_NeutralHadron_);
   fChain->SetBranchAddress("NeutralHadron.fUniqueID", NeutralHadron_fUniqueID, &b_NeutralHadron_fUniqueID);
   fChain->SetBranchAddress("NeutralHadron.fBits", NeutralHadron_fBits, &b_NeutralHadron_fBits);
   fChain->SetBranchAddress("NeutralHadron.ET", NeutralHadron_ET, &b_NeutralHadron_ET);
   fChain->SetBranchAddress("NeutralHadron.Eta", NeutralHadron_Eta, &b_NeutralHadron_Eta);
   fChain->SetBranchAddress("NeutralHadron.Phi", NeutralHadron_Phi, &b_NeutralHadron_Phi);
   fChain->SetBranchAddress("NeutralHadron.E", NeutralHadron_E, &b_NeutralHadron_E);
   fChain->SetBranchAddress("NeutralHadron.T", NeutralHadron_T, &b_NeutralHadron_T);
   fChain->SetBranchAddress("NeutralHadron.Eem", NeutralHadron_Eem, &b_NeutralHadron_Eem);
   fChain->SetBranchAddress("NeutralHadron.Ehad", NeutralHadron_Ehad, &b_NeutralHadron_Ehad);
   fChain->SetBranchAddress("NeutralHadron.Edges[4]", NeutralHadron_Edges, &b_NeutralHadron_Edges);
   fChain->SetBranchAddress("NeutralHadron.Particles", NeutralHadron_Particles, &b_NeutralHadron_Particles);
   fChain->SetBranchAddress("NeutralHadron_size", &NeutralHadron_size, &b_NeutralHadron_size);
   fChain->SetBranchAddress("Photon", &Photon_, &b_Photon_);
   fChain->SetBranchAddress("Photon.fUniqueID", Photon_fUniqueID, &b_Photon_fUniqueID);
   fChain->SetBranchAddress("Photon.fBits", Photon_fBits, &b_Photon_fBits);
   fChain->SetBranchAddress("Photon.PT", Photon_PT, &b_Photon_PT);
   fChain->SetBranchAddress("Photon.Eta", Photon_Eta, &b_Photon_Eta);
   fChain->SetBranchAddress("Photon.Phi", Photon_Phi, &b_Photon_Phi);
   fChain->SetBranchAddress("Photon.E", Photon_E, &b_Photon_E);
   fChain->SetBranchAddress("Photon.T", Photon_T, &b_Photon_T);
   fChain->SetBranchAddress("Photon.EhadOverEem", Photon_EhadOverEem, &b_Photon_EhadOverEem);
   fChain->SetBranchAddress("Photon.Particles", Photon_Particles, &b_Photon_Particles);
   fChain->SetBranchAddress("Photon_size", &Photon_size, &b_Photon_size);
   fChain->SetBranchAddress("Electron", &Electron_, &b_Electron_);
   fChain->SetBranchAddress("Electron.fUniqueID", Electron_fUniqueID, &b_Electron_fUniqueID);
   fChain->SetBranchAddress("Electron.fBits", Electron_fBits, &b_Electron_fBits);
   fChain->SetBranchAddress("Electron.PT", Electron_PT, &b_Electron_PT);
   fChain->SetBranchAddress("Electron.Eta", Electron_Eta, &b_Electron_Eta);
   fChain->SetBranchAddress("Electron.Phi", Electron_Phi, &b_Electron_Phi);
   fChain->SetBranchAddress("Electron.T", Electron_T, &b_Electron_T);
   fChain->SetBranchAddress("Electron.Charge", Electron_Charge, &b_Electron_Charge);
   fChain->SetBranchAddress("Electron.EhadOverEem", Electron_EhadOverEem, &b_Electron_EhadOverEem);
   fChain->SetBranchAddress("Electron.Particle", Electron_Particle, &b_Electron_Particle);
   fChain->SetBranchAddress("Electron_size", &Electron_size, &b_Electron_size);
   fChain->SetBranchAddress("Muon", &Muon_, &b_Muon_);
   fChain->SetBranchAddress("Muon.fUniqueID", Muon_fUniqueID, &b_Muon_fUniqueID);
   fChain->SetBranchAddress("Muon.fBits", Muon_fBits, &b_Muon_fBits);
   fChain->SetBranchAddress("Muon.PT", Muon_PT, &b_Muon_PT);
   fChain->SetBranchAddress("Muon.Eta", Muon_Eta, &b_Muon_Eta);
   fChain->SetBranchAddress("Muon.Phi", Muon_Phi, &b_Muon_Phi);
   fChain->SetBranchAddress("Muon.T", Muon_T, &b_Muon_T);
   fChain->SetBranchAddress("Muon.Charge", Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon.Particle", Muon_Particle, &b_Muon_Particle);
   fChain->SetBranchAddress("Muon_size", &Muon_size, &b_Muon_size);
   fChain->SetBranchAddress("Jet", &Jet_, &b_Jet_);
   fChain->SetBranchAddress("Jet.fUniqueID", Jet_fUniqueID, &b_Jet_fUniqueID);
   fChain->SetBranchAddress("Jet.fBits", Jet_fBits, &b_Jet_fBits);
   fChain->SetBranchAddress("Jet.PT", Jet_PT, &b_Jet_PT);
   fChain->SetBranchAddress("Jet.Eta", Jet_Eta, &b_Jet_Eta);
   fChain->SetBranchAddress("Jet.Phi", Jet_Phi, &b_Jet_Phi);
   fChain->SetBranchAddress("Jet.T", Jet_T, &b_Jet_T);
   fChain->SetBranchAddress("Jet.Mass", Jet_Mass, &b_Jet_Mass);
   fChain->SetBranchAddress("Jet.DeltaEta", Jet_DeltaEta, &b_Jet_DeltaEta);
   fChain->SetBranchAddress("Jet.DeltaPhi", Jet_DeltaPhi, &b_Jet_DeltaPhi);
   fChain->SetBranchAddress("Jet.BTag", Jet_BTag, &b_Jet_BTag);
   fChain->SetBranchAddress("Jet.TauTag", Jet_TauTag, &b_Jet_TauTag);
   fChain->SetBranchAddress("Jet.Charge", Jet_Charge, &b_Jet_Charge);
   fChain->SetBranchAddress("Jet.EhadOverEem", Jet_EhadOverEem, &b_Jet_EhadOverEem);
   fChain->SetBranchAddress("Jet.NCharged", Jet_NCharged, &b_Jet_NCharged);
   fChain->SetBranchAddress("Jet.NNeutrals", Jet_NNeutrals, &b_Jet_NNeutrals);
   fChain->SetBranchAddress("Jet.Beta", Jet_Beta, &b_Jet_Beta);
   fChain->SetBranchAddress("Jet.BetaStar", Jet_BetaStar, &b_Jet_BetaStar);
   fChain->SetBranchAddress("Jet.MeanSqDeltaR", Jet_MeanSqDeltaR, &b_Jet_MeanSqDeltaR);
   fChain->SetBranchAddress("Jet.PTD", Jet_PTD, &b_Jet_PTD);
   fChain->SetBranchAddress("Jet.FracPt[5]", Jet_FracPt, &b_Jet_FracPt);
   fChain->SetBranchAddress("Jet.Tau1", Jet_Tau1, &b_Jet_Tau1);
   fChain->SetBranchAddress("Jet.Tau2", Jet_Tau2, &b_Jet_Tau2);
   fChain->SetBranchAddress("Jet.Tau3", Jet_Tau3, &b_Jet_Tau3);
   fChain->SetBranchAddress("Jet.Tau4", Jet_Tau4, &b_Jet_Tau4);
   fChain->SetBranchAddress("Jet.Tau5", Jet_Tau5, &b_Jet_Tau5);
   fChain->SetBranchAddress("Jet.Constituents", Jet_Constituents, &b_Jet_Constituents);
   fChain->SetBranchAddress("Jet.Particles", Jet_Particles, &b_Jet_Particles);
   fChain->SetBranchAddress("Jet_size", &Jet_size, &b_Jet_size);
   fChain->SetBranchAddress("MissingET", &MissingET_, &b_MissingET_);
   fChain->SetBranchAddress("MissingET.fUniqueID", MissingET_fUniqueID, &b_MissingET_fUniqueID);
   fChain->SetBranchAddress("MissingET.fBits", MissingET_fBits, &b_MissingET_fBits);
   fChain->SetBranchAddress("MissingET.MET", MissingET_MET, &b_MissingET_MET);
   fChain->SetBranchAddress("MissingET.Eta", MissingET_Eta, &b_MissingET_Eta);
   fChain->SetBranchAddress("MissingET.Phi", MissingET_Phi, &b_MissingET_Phi);
   fChain->SetBranchAddress("MissingET_size", &MissingET_size, &b_MissingET_size);
   fChain->SetBranchAddress("ScalarHT", &ScalarHT_, &b_ScalarHT_);
   fChain->SetBranchAddress("ScalarHT.fUniqueID", ScalarHT_fUniqueID, &b_ScalarHT_fUniqueID);
   fChain->SetBranchAddress("ScalarHT.fBits", ScalarHT_fBits, &b_ScalarHT_fBits);
   fChain->SetBranchAddress("ScalarHT.HT", ScalarHT_HT, &b_ScalarHT_HT);
   fChain->SetBranchAddress("ScalarHT_size", &ScalarHT_size, &b_ScalarHT_size);
}

Bool_t MyCZpSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef MyCZpSelector_cxx
