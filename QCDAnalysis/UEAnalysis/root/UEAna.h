//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 21 11:38:42 2008 by ROOT version 5.14/00f
// from TTree AnalysisTree/MBUE Analysis Tree 
// found on file: softjet/UE_softjet_1.root
//////////////////////////////////////////////////////////

#ifndef UEAna_h
#define UEAna_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class UEAna {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leave types
   Int_t           EventKind;
   Double_t        EventScale;
   Double_t        FilterEff;
   Double_t        CrossSect;
   Int_t           NumberMCParticles;
   Float_t         MomentumMC[207];   //[NumberMCParticles]
   Float_t         TransverseMomentumMC[207];   //[NumberMCParticles]
   Float_t         EtaMC[207];   //[NumberMCParticles]
   Float_t         PhiMC[207];   //[NumberMCParticles]
   Int_t           NumberTracks;
   Float_t         MomentumTK[434];   //[NumberTracks]
   Float_t         TrasverseMomentumTK[434];   //[NumberTracks]
   Float_t         EtaTK[434];   //[NumberTracks]
   Float_t         PhiTK[434];   //[NumberTracks]
   Int_t           NumberInclusiveJet;
   Float_t         MomentumIJ[68];   //[NumberInclusiveJet]
   Float_t         TrasverseMomentumIJ[68];   //[NumberInclusiveJet]
   Float_t         EtaIJ[68];   //[NumberInclusiveJet]
   Float_t         PhiIJ[68];   //[NumberInclusiveJet]
   Int_t           NumberChargedJet;
   Float_t         MomentumCJ[59];   //[NumberChargedJet]
   Float_t         TrasverseMomentumCJ[59];   //[NumberChargedJet]
   Float_t         EtaCJ[59];   //[NumberChargedJet]
   Float_t         PhiCJ[59];   //[NumberChargedJet]
   Int_t           NumberTracksJet;
   Float_t         MomentumTJ[31];   //[NumberTracksJet]
   Float_t         TrasverseMomentumTJ[31];   //[NumberTracksJet]
   Float_t         EtaTJ[31];   //[NumberTracksJet]
   Float_t         PhiTJ[31];   //[NumberTracksJet]
   Int_t           NumberCaloJet;
   Float_t         MomentumEHJ[48];   //[NumberCaloJet]
   Float_t         TrasverseMomentumEHJ[48];   //[NumberCaloJet]
   Float_t         EtaEHJ[48];   //[NumberCaloJet]
   Float_t         PhiEHJ[48];   //[NumberCaloJet]

   // List of branches
   TBranch        *b_EventKind;   //!
   TBranch        *b_EventScale;   //!
   TBranch        *b_FilterEff;   //!
   TBranch        *b_CrossSect;   //!
   TBranch        *b_NumberMCParticles;   //!
   TBranch        *b_MomentumMC;   //!
   TBranch        *b_TransverseMomentumMC;   //!
   TBranch        *b_EtaMC;   //!
   TBranch        *b_PhiMC;   //!
   TBranch        *b_NumberTracks;   //!
   TBranch        *b_MomentumTK;   //!
   TBranch        *b_TrasverseMomentumTK;   //!
   TBranch        *b_EtaTK;   //!
   TBranch        *b_PhiTK;   //!
   TBranch        *b_NumberInclusiveJet;   //!
   TBranch        *b_MomentumIJ;   //!
   TBranch        *b_TrasverseMomentumIJ;   //!
   TBranch        *b_EtaIJ;   //!
   TBranch        *b_PhiIJ;   //!
   TBranch        *b_NumberChargedJet;   //!
   TBranch        *b_MomentumCJ;   //!
   TBranch        *b_TrasverseMomentumCJ;   //!
   TBranch        *b_EtaCJ;   //!
   TBranch        *b_PhiCJ;   //!
   TBranch        *b_NumberTracksJet;   //!
   TBranch        *b_MomentumTJ;   //!
   TBranch        *b_TrasverseMomentumTJ;   //!
   TBranch        *b_EtaTJ;   //!
   TBranch        *b_PhiTJ;   //!
   TBranch        *b_NumberCaloJet;   //!
   TBranch        *b_MomentumEHJ;   //!
   TBranch        *b_TrasverseMomentumEHJ;   //!
   TBranch        *b_EtaEHJ;   //!
   TBranch        *b_PhiEHJ;   //!

   UEAna(TTree *tree=0);
   virtual ~UEAna();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef UEAna_cxx
UEAna::UEAna(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("softjet/UE_softjet_1.root");
      if (!f) {
         f = new TFile("softjet/UE_softjet_1.root");
      }
      tree = (TTree*)gDirectory->Get("AnalysisTree");

   }
   Init(tree);
}

UEAna::~UEAna()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t UEAna::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t UEAna::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void UEAna::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normaly not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventKind", &EventKind, &b_EventKind);
   fChain->SetBranchAddress("EventScale", &EventScale, &b_EventScale);
   fChain->SetBranchAddress("FilterEff", &FilterEff, &b_FilterEff);
   fChain->SetBranchAddress("CrossSect", &CrossSect, &b_CrossSect);
   fChain->SetBranchAddress("NumberMCParticles", &NumberMCParticles, &b_NumberMCParticles);
   fChain->SetBranchAddress("MomentumMC", MomentumMC, &b_MomentumMC);
   fChain->SetBranchAddress("TransverseMomentumMC", TransverseMomentumMC, &b_TransverseMomentumMC);
   fChain->SetBranchAddress("EtaMC", EtaMC, &b_EtaMC);
   fChain->SetBranchAddress("PhiMC", PhiMC, &b_PhiMC);
   fChain->SetBranchAddress("NumberTracks", &NumberTracks, &b_NumberTracks);
   fChain->SetBranchAddress("MomentumTK", MomentumTK, &b_MomentumTK);
   fChain->SetBranchAddress("TrasverseMomentumTK", TrasverseMomentumTK, &b_TrasverseMomentumTK);
   fChain->SetBranchAddress("EtaTK", EtaTK, &b_EtaTK);
   fChain->SetBranchAddress("PhiTK", PhiTK, &b_PhiTK);
   fChain->SetBranchAddress("NumberInclusiveJet", &NumberInclusiveJet, &b_NumberInclusiveJet);
   fChain->SetBranchAddress("MomentumIJ", MomentumIJ, &b_MomentumIJ);
   fChain->SetBranchAddress("TrasverseMomentumIJ", TrasverseMomentumIJ, &b_TrasverseMomentumIJ);
   fChain->SetBranchAddress("EtaIJ", EtaIJ, &b_EtaIJ);
   fChain->SetBranchAddress("PhiIJ", PhiIJ, &b_PhiIJ);
   fChain->SetBranchAddress("NumberChargedJet", &NumberChargedJet, &b_NumberChargedJet);
   fChain->SetBranchAddress("MomentumCJ", MomentumCJ, &b_MomentumCJ);
   fChain->SetBranchAddress("TrasverseMomentumCJ", TrasverseMomentumCJ, &b_TrasverseMomentumCJ);
   fChain->SetBranchAddress("EtaCJ", EtaCJ, &b_EtaCJ);
   fChain->SetBranchAddress("PhiCJ", PhiCJ, &b_PhiCJ);
   fChain->SetBranchAddress("NumberTracksJet", &NumberTracksJet, &b_NumberTracksJet);
   fChain->SetBranchAddress("MomentumTJ", MomentumTJ, &b_MomentumTJ);
   fChain->SetBranchAddress("TrasverseMomentumTJ", TrasverseMomentumTJ, &b_TrasverseMomentumTJ);
   fChain->SetBranchAddress("EtaTJ", EtaTJ, &b_EtaTJ);
   fChain->SetBranchAddress("PhiTJ", PhiTJ, &b_PhiTJ);
   fChain->SetBranchAddress("NumberCaloJet", &NumberCaloJet, &b_NumberCaloJet);
   fChain->SetBranchAddress("MomentumEHJ", MomentumEHJ, &b_MomentumEHJ);
   fChain->SetBranchAddress("TrasverseMomentumEHJ", TrasverseMomentumEHJ, &b_TrasverseMomentumEHJ);
   fChain->SetBranchAddress("EtaEHJ", EtaEHJ, &b_EtaEHJ);
   fChain->SetBranchAddress("PhiEHJ", PhiEHJ, &b_PhiEHJ);
   Notify();
}

Bool_t UEAna::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normaly not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void UEAna::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t UEAna::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef UEAna_cxx
