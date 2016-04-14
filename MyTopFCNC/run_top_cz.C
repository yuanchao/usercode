{
  //Reset ROOT
  gROOT->Reset();
  
  gROOT->LoadMacro("MyTcZAna.C+");

  // Create a chain of files. The parameter to the TChain constructor
  // is the name of the Tree to be processed in each file of the chain.
  TChain chain("Delphes");

  //chain.Add("results.root");
  //chain.Add("/nasdata2/yuanchao/TTbar_FCNC_MadGraph_7TeV/*.root");
  //chain.Add("TTbar_FCNC_140.root");
  chain.Add("TTbarFCNC_P1_NoPU-1.root");

  TFile *hfile = new TFile("hist_top_cz.root","RECREATE","Top to cZ decays");

  MyTcZAna t((TTree *)chain, 1.);
  //MyG4Ana t;
//  t.Histogram();
  t.Loop();

  hfile->Write();

  t.end();
}
