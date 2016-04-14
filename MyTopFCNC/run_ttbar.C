{
  //Reset ROOT
  gROOT->Reset();
  
  gROOT->LoadMacro("MyTcZAna.C+");

  // Create a chain of files. The parameter to the TChain constructor
  // is the name of the Tree to be processed in each file of the chain.
  TChain chain("Delphes");

  //chain.Add("TTbar_FCNC_140.root");
  chain.Add("tt-4p-0-600-v1510_14TEV_96468974_PhaseI_Conf0_140PileUp.root");

  TFile *hfile = new TFile("hist_ttbar.root","RECREATE","Top to cZ decays");

  MyTcZAna t((TTree *)chain, 1.);
  t.Loop();

  hfile->Write();

  t.end();
}
