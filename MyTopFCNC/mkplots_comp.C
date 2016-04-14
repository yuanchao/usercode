#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "THStack.h"
#include "TLegend.h"

#include <vector>

#define INT_LUM 4615.26


vector<TH1*>nPFJets;
vector<TH1*>mTopCZ;
vector<TH1*>mTopBW;
vector<TH1*>htSig;
vector<TH1*>htOther;

vector<TH1*>mTopCZb;
vector<TH1*>mTopBWb;

vector<TH1*>massZee;
vector<TH1*>massZmm;
vector<TH1*>ptZee;
vector<TH1*>ptZmm;
vector<TH1*>MET;
vector<TH1*>METphi;
vector<TH1*>METee;
vector<TH1*>METmm;
vector<TH1*>METeel;
vector<TH1*>METmml;
vector<TH1*>WeMT;
vector<TH1*>WeMTee;
vector<TH1*>WeMTmm;
vector<TH1*>WmMT;
vector<TH1*>WmMTee;
vector<TH1*>WmMTmm;
vector<TH1*>WMT;

vector<TH1*>VtxNo;
vector<TH1*>VtxNDoF;
vector<TH1*>VtxVz;
vector<TH1*>VtxVrho;

vector<TH1*>ElecPt;
vector<TH1*>ElecEta;
vector<TH1*>ElecPhi;

vector<TH1*>MuonPt;
vector<TH1*>MuonEta;
vector<TH1*>MuonPhi;
 
vector<TH1*>JetNo;
vector<TH1*>JetPt;
vector<TH1*>JetEta;
vector<TH1*>JetPhi;
 
vector<TH1*>GElecPt;
vector<TH1*>GElecEta;
vector<TH1*>GElecPhi;

vector<TH1*>GMuonPt;
vector<TH1*>GMuonEta;
vector<TH1*>GMuonPhi;
 
vector<TH1*>GJetNo;
vector<TH1*>GJetPt;
vector<TH1*>GJetEta;
vector<TH1*>GJetPhi;

const int nFiles=4;

std::string Labels[nFiles]={"Phase I no pile-up",
			    "Phase I pile-up 140",
			    "Phase II pile-up 140 conf 3",
			    "Phase II pile-up 140 v1"};

std::string dataFiles[2]={"hist_data_2e_all.root", "hist_data_2e_all.root"};

std::string histFiles[nFiles]={"hist_top_cz_p1_nopu.root",
				 "hist_top_cz_p1_pu140.root",
				 "hist_top_cz_p2_pu140_c3.root",
 				 "hist_top_cz_p2_pu140_v1.root"};

//double hist_scale[nFiles] = {0.95*INT_LUM/180702, 158.*INT_LUM/3697476,
double hist_scale[nFiles] = {1., 1., 1., 1.,}

double histMax[5];// = {30, };

//int histColor[nFiles] = {kRed+1, kRed-7, kGreen-3, kAzure-2, kGreen-9,
//int histColor[nFiles] = {kWhite, kRed+1, kGreen-3, kAzure-2, kGreen-9,
int histColor[nFiles] = {kBlack, kGreen-7, kAzure-2,
			 kRed+1};

TFile* inFile[nFiles+2];

void plot_hist(TCanvas *c1, vector<TH1*> &hists, //vector<TH1*> &hdata,
	       std::string histName, int nfiles, std::string xlabel="test"){

 
  //TCanvas *c1 = new TCanvas("c1","",600,600); 
  c1->cd();
//   TLegend* leg = new TLegend(0.60,0.70,0.85,0.93);
//   leg->SetTextSize(0.03);
//   leg->SetFillColor(0);

//   TLatex *t1a = new TLatex(0.40,0.85,"CMS Preliminary");
//   t1a->SetTextFont(42);
//   t1a->SetTextSize(0.05);
//   t1a->SetTextAlign(22);
//   t1a->SetNDC(kTRUE); 
  std::string ylabel="Events";
  const int size = nfiles;
  TH1* plots[size+2];
  TH1* plots1[size+2];

  TH1* sigHist;
  //THStack* bkgHist=new THStack("bkg", histName.c_str());
  TH1* bkgHist;
  THStack* allHist=new THStack("all", histName.c_str());

  Float_t tgx[500], tgy[500], tgex[500], tgey[500];

  //cout << "   to make plots... " << hists.size() << endl;

  TLegend* leg = new TLegend(0.66,0.66,0.975,0.93);
  //  leg->SetTextFont(42);
  leg->SetBorderSize(0);
  //leg->SetFillColor(0);
  //leg->SetLineColor(1);
  leg->SetLineStyle(0);
  //  leg->SetTextFont(42);
  leg->SetFillStyle(0);
  //leg->AddEntry(hdata, hdata->GetTitle(), "lp");

  for(int i = nfiles-1; i >= 0; i--){

    std::string histname = hists[i]->GetName();
    char name[100];
    sprintf(name,"%s_%d",histname.c_str(),i);
    
    //plots[i] = (TH1*)hists[i]->Clone(histname.c_str());
    plots[i] = (TH1*)hists[i]->Clone(name);
    plots[i]->SetXTitle(xlabel.c_str());
    plots[i]->UseCurrentStyle();

    plots[i]->SetNdivisions(505);

    //if(xlabel.find("[") < xlabel.Length())
    char label[100];
    sprintf(label, "%s", ylabel.c_str());
    if(xlabel.find("[") < 20){
      sprintf(label, "%s / %d %s", ylabel.c_str(),
	      plots[i]->GetBinWidth(1), xlabel.c_str()+xlabel.find("["));
    }
    //ylabel="Events / "+plots[i]->GetBinWidth(1);
    //+std::string(plots[i].GetBinWidth(1));//+xlabel.c_str()+xlabel.find("[");
    plots[i]->SetYTitle(label);//ylabel.c_str());
    plots[i]->GetYaxis()->SetTitleOffset(1.);
    //cout << label << " " << xlabel << " " << ylabel << endl;

//     if(i==4 || i==5)
//       plots[i]->Scale(hist_scale[i]);
//     else
       plots[i]->Scale(hist_scale[i]);
//       //plots[i]->Scale(hist_scale[i]/136.3*185);

    plots[i]->SetLineWidth(2);
    //plots[i]->SetFillColor(histColor[i]);
    plots[i]->SetLineColor(histColor[i]);

//     // set the last bin as SUM
//     int nbins=plots[i]->GetNbinsX();
//     double sum_bin=0;

//     if(histName.find("Mass") < histName.length()){
//       sum_bin+=plots[i]->GetBinContent(nbins);
//       sum_bin+=plots[i]->GetBinContent(nbins+1);
//       plots[i]->SetBinContent(nbins, sum_bin);
//     }

//     if(i == 5 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14 ){
//       plots[i]->SetLineWidth(0);
//       plots[i]->SetLineColor(histColor[i]);
//     }

//     plots1[i]=(TH1*)hists[i]->Clone();

//     for(int ib=1; ib <= nbins; ib++){
//       double m_err = 
// 	plots[i]->GetBinContent(ib)==0 ? 0 : sqrt(plots[i]->GetBinContent(ib));
//       plots1[i]->SetBinError(m_err);
//     }

//      plots[i]->Draw("");
//      c1->SaveAs(name);     

//     if(i==0){
//       sigHist=(TH1*)plots[i]->Clone();
//     }else if(i==nfiles-1){
//       bkgHist=(TH1*)plots[i]->Clone();
//       allHist->SetHistogram(plots[i]);
//     }else{
//       bkgHist->Add(plots[i]);
//       allHist->Add(plots[i]);
//     }		    
  }
  //cout << "plots loaded...\n";

//   hists[nfiles+1]->SetMarkerStyle(20);
//   hists[nfiles+1]->SetMarkerSize(0.8);

  //leg->AddEntry(hists[nfiles+1], "Data", "lp");

//   for(int i = 0; i < nfiles; i++){
//     //if(i != 8 && i != 10 && i != 12 )
//     if(i < 8 || i > 12 )
//       leg->AddEntry(plots[i], Labels[i].c_str(), "f");
//   }


  for(int i = 0; i <= nfiles-1; i++){
    leg->AddEntry(plots[i], Labels[i].c_str(), "l");
  }

//   leg->AddEntry(plots[2], Labels[2].c_str(), "f");
//   leg->AddEntry(plots[3], Labels[3].c_str(), "f");
//   leg->AddEntry(plots[4], Labels[4].c_str(), "f");
//   //leg->AddEntry(plots[4], Labels[4].c_str(), "f");
//   leg->AddEntry(plots[7], Labels[7].c_str(), "f");
//   //leg->AddEntry(plots[6], Labels[6].c_str(), "f");
//   leg->AddEntry(plots[9], Labels[9].c_str(), "f");
//   leg->AddEntry(plots[0], Labels[0].c_str(), "f");

//   allHist->Add(sigHist);
// //  allHist->SetMaximum(allHist->GetMaximum()*1.5);
//   if(allHist->GetMaximum()>100){
//     allHist->SetMaximum(1000);
//     allHist->SetMinimum(0.5);
//   }else if(allHist->GetMaximum()>15){
//     allHist->SetMaximum(25);
//     //allHist->SetNdivisions(505);
//   }else if(allHist->GetMaximum()>9){
//     allHist->SetMaximum(20);
//   }else{
//     allHist->SetMaximum(8);
//   }
//  allHist->SetMaximum(allHist->GetMaximum()*0.5);
//allHist->SetMinimum(0.5);
  //allHist->GetXaxis()->SetTitle("test");
//   allHist->UseCurrentStyle();
//   allHist->Draw();

//   bkgHist->UseCurrentStyle();
//   bkgHist->SetLineColor(kBlack);
//   bkgHist->SetFillColor(0);
//   bkgHist->SetLineWidth(2);
//   bkgHist->DrawCopy("same");

//   bkgHist->Sumw2();

//   for(int ib=1; ib <= bkgHist->GetNbinsX()+1; ib++){

//     tgx[ib-1]=bkgHist->GetXaxis()->GetBinCenter(ib);
//     tgy[ib-1]=bkgHist->GetBinContent(ib);
//     tgex[ib-1]=bkgHist->GetBinWidth(ib)/2;
//     tgey[ib-1]=bkgHist->GetBinError(ib);
//   }

//   plots[nfiles] = (TH1*)hists[nfiles]->Clone(histname.c_str());
//   plots[nfiles+1] = (TH1*)hists[nfiles+1]->Clone(histname.c_str());
  cout << "to draw...\n";

  plots[nfiles-1]->Draw();
  for(int i = nfiles-2; i >= 0; i--){
    plots[i]->Draw("same");
  }

  cout << "plots done...\n";

  //leg->AddEntry(plots[nfiles+1], "Data", "lp");


  //plots[nfiles]->Sumw2();
//   plots[nfiles+1]->Add(plots[nfiles]);
  
//   plots[nfiles+1]->Sumw2();

//   int nbin=plots[nfiles+1]->GetNbinsX();
//   double sum=0;

//   if(histName.find("Mass") < histName.length()){
//     sum+=plots[nfiles+1]->GetBinContent(nbin);
//     sum+=plots[nfiles+1]->GetBinContent(nbin+1);
//     plots[nfiles+1]->SetBinContent(nbin, sum);
//     plots[nfiles+1]->SetBinError(nbin, plots[nfiles+1]->GetBinError(nbin+1));
//   }

  //plots[nfiles]->Draw("same");
  //plots[nfiles+1]->Draw("same");
  //plots[nfiles+1]->Draw();

  //allHist->SetFillColor(50);
  
  //sigHist->SetFillColor(38);

  //allHist->Draw("same");

  leg->Draw();
  //plots[nfiles+1]->Draw("same");

//   bkgHist->SetFillColor(38);
//   bkgHist->Draw("same");
//   text1 = new TLatex(3.570061,23.08044,"CMS #sqrt{s} = 7 TeV, 5.0 fb^{-1}");
//   text1->SetNDC();
//   text1->SetTextAlign(13);
//   text1->SetX(0.174);
//   text1->SetY(0.918);
//   text1->SetTextFont(42);
//   text1->SetTextSizePixels(24);
//   text1->Draw();

//   text2 = new TLatex(3.570061,23.08044,"4.6 fb^{-1} at #sqrt{s} = 7 TeV");
//   text2->SetNDC();
//   text2->SetTextAlign(13);
//   text2->SetX(0.184);
//   text2->SetY(0.88);
//   text2->SetTextFont(42);
//   text2->SetTextSizePixels(24);
//   text2->Draw();
  
}

void mkplots_comp(){
  //Reset ROOT
  //gROOT->Reset();
  //gStyle->SetOptFit();

  gROOT->LoadMacro("setTDRStyle.C");
  setTDRStyle();
  // gROOT->LoadMacro("TdrStyle.C");
  // setTDRStyle(0);

 //gStyle->SetOptStat(1);
 // gStyle->SetPadLeftMargin(0.16);
 // gStyle->SetPadRightMargin(0.02);
 gStyle->SetTitleXOffset(0.9);
 gStyle->SetTitleYOffset(1.25);

 gStyle->SetHatchesSpacing(1.0);
 gStyle->SetOptTitle(0);

 double m_over=0., m_max=0.;

 TH1* hist;

 //TFile *f_hist_mc = TFile::Open("hist_top_cz1.root");
 cout << "reading histograms...\n";

 for(int if1=0; if1 < nFiles; if1++){
   //if(if1==7 || if1==8 || if1==9) continue;

   //cout << histFiles[if1].c_str() << endl;
   inFile[if1] = TFile::Open(histFiles[if1].c_str());
   gDirectory->cd("");

   // Vertex plots
//    hist = (TH1*) gDirectory->Get("hist_vtx_no");
//    VtxNo.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_vtx_ndof");
//    VtxNDoF.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_vtx_z");
//    VtxVz.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_vtx_rho");
//    VtxVrho.push_back(hist);

   // Leptons
   hist = (TH1*) gDirectory->Get("hist_e_pt");
   ElecPt.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_e_eta");
   ElecEta.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_e_phi");
   ElecPhi.push_back(hist);
   
   hist = (TH1*) gDirectory->Get("hist_m_pt");
   MuonPt.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_m_eta");
   MuonEta.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_m_phi");
   MuonPhi.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_jet_no");
   JetNo.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_jet_pt");
   JetPt.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_jet_eta");
   JetEta.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_jet_phi");
   JetPhi.push_back(hist);

   
   hist = (TH1*) gDirectory->Get("hist_ge_pt");
   GElecPt.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_ge_eta");
   GElecEta.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_ge_phi");
   GElecPhi.push_back(hist);
   
   hist = (TH1*) gDirectory->Get("hist_gm_pt");
   GMuonPt.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_gm_eta");
   GMuonEta.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_gm_phi");
   GMuonPhi.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_gjet_no");
   GJetNo.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_gjet_pt");
   GJetPt.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_gjet_eta");
   GJetEta.push_back(hist);

   hist = (TH1*) gDirectory->Get("hist_gjet_phi");
   GJetPhi.push_back(hist);
   

   //TH1* hist = (TH1*) gDirectoryinFile[if1]->Get("hist_jet_no");
//    hist = (TH1*) gDirectory->Get("hist_jet_no_c");
// //    nPFJets.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_top_m_cz_f");
//    mTopCZ.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_top_m_bw_f");
//    mTopBW.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_top_m_cz_fb");
//    mTopCZb.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_top_m_bw_fb");
//    mTopBWb.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_st_s");
//    htSig.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_st_o");
//    htOther.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_zee_m");
//    massZee.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_zmm_m");
//    massZmm.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_zee_pt");
//    ptZee.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_zmm_pt");
//    ptZmm.push_back(hist);

    hist = (TH1*) gDirectory->Get("hist_met_pt");
    MET.push_back(hist);

    hist = (TH1*) gDirectory->Get("hist_met_phi");
    METphi.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_met_pt_ee");
//    METee.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_met_pt_mm");
//    METmm.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_met_pt_eel");
//    METeel.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_met_pt_mml");
//    METmml.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_wet_cuts");
//    WeMT.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_wen_mt_ee");
//    WeMTee.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_wmt_cuts");
//    WmMT.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_wmn_mt_ee");
//    WmMTee.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_wen_mt_mm");
//    WeMTmm.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_wmn_mt_mm");
//    WmMTmm.push_back(hist);

//    hist = (TH1*) gDirectory->Get("hist_mt_cuts");
//    WMT.push_back(hist);

 }

 cout << "loading done...\n";
 //TCanvas *c1 = new TCanvas("c1","UEAnalyzer",10,10,700,500);
 //TCanvas *c1 = new TCanvas("c1","UEAnalyzer",10,10,1280,1024);
 TCanvas *c1 = new TCanvas("c1","Top FCNC",10,10,600,600);

 c1->cd();
 c1->cd()->SetRightMargin(0.04);

 c1->SetLogy();
 
  plot_hist(c1, ElecPt, "PT of Electrons", nFiles, "Electron p_{T} [GeV]");
  c1->SaveAs("hist_elec_pt.png");
  c1->SaveAs("hist_elec_pt.pdf");

  plot_hist(c1, ElecEta, "Eta of Electrons", nFiles, "Electron #eta");
  c1->SaveAs("hist_elec_eta.png");
  c1->SaveAs("hist_elec_eta.pdf");

  plot_hist(c1, ElecPhi, "Phi of Electrons", nFiles, "Electron #phi");
  c1->SaveAs("hist_elec_phi.png");
  c1->SaveAs("hist_elec_phi.pdf");

  plot_hist(c1, MuonPt, "PT of Muons", nFiles, "Muon p_{T} [GeV]");
  c1->SaveAs("hist_mu_pt.png");
  c1->SaveAs("hist_mu_pt.pdf");

  plot_hist(c1, MuonEta, "Eta of Muons", nFiles, "Muon #eta");
  c1->SaveAs("hist_mu_eta.png");
  c1->SaveAs("hist_mu_eta.pdf");

  plot_hist(c1, MuonPhi, "Phi of Muons", nFiles, "Muon #phi");
  c1->SaveAs("hist_mu_phi.png");
  c1->SaveAs("hist_mu_phi.pdf");

  plot_hist(c1, JetPt, "PT of Jets", nFiles, "Jet p_{T} [GeV]");
  c1->SaveAs("hist_jet_pt.png");
  c1->SaveAs("hist_jet_pt.pdf");

  plot_hist(c1, JetEta, "Eta of Jets", nFiles, "Jet #eta");
  c1->SaveAs("hist_jet_eta.png");
  c1->SaveAs("hist_jet_eta.pdf");

  plot_hist(c1, JetPhi, "Phi of Jets", nFiles, "Jet #phi");
  c1->SaveAs("hist_jet_phi.png");
  c1->SaveAs("hist_jet_phi.pdf");

  plot_hist(c1, JetNo, "No. of Jets", nFiles, "Number of Jets");
  c1->SaveAs("hist_jet_no.png");
  c1->SaveAs("hist_jet_no.pdf");

  plot_hist(c1, MET, "Missing ET with cuts", nFiles, "#slash{E}_{T} [GeV]");
  c1->SaveAs("hist_met_pt.png");
  c1->SaveAs("hist_met_pt.pdf");

  plot_hist(c1, METphi, "Missing ET #phi with cuts", nFiles, "#slash{E}_{T} #phi [GeV]");
  c1->SaveAs("hist_met_phi.png");
  c1->SaveAs("hist_met_phi.pdf");


  plot_hist(c1, GElecPt, "PT of Electrons", nFiles, "Electron p_{T} [GeV]");
  c1->SaveAs("hist_gelec_pt.png");

  plot_hist(c1, GElecEta, "Eta of Electrons", nFiles, "Electron #eta");
  c1->SaveAs("hist_gelec_eta.png");


  plot_hist(c1, GElecPhi, "Phi of Electrons", nFiles, "Electron #phi");
  c1->SaveAs("hist_gelec_phi.png");

//   plot_hist(c1, nPFJets, "No. of Jets", nFiles);
  plot_hist(c1, GMuonPt, "PT of Muons", nFiles, "Muon p_{T} [GeV]");
  c1->SaveAs("hist_gmu_pt.png");

  plot_hist(c1, GMuonEta, "Eta of Muons", nFiles, "Muon #eta");
  c1->SaveAs("hist_gmu_eta.png");

  plot_hist(c1, GMuonPhi, "Phi of Muons", nFiles, "Muon #phi");
  c1->SaveAs("hist_gmu_phi.png");

  plot_hist(c1, GJetPt, "PT of Jets", nFiles, "Jet p_{T} [GeV]");
  c1->SaveAs("hist_gjet_pt.png");

  plot_hist(c1, GJetEta, "Eta of Jets", nFiles, "Jet #eta");
  c1->SaveAs("hist_gjet_eta.png");

  plot_hist(c1, GJetPhi, "Phi of Jets", nFiles, "Jet #phi");
  c1->SaveAs("hist_gjet_phi.png");

//   plot_hist(c1, mTopCZ, "Mass of t(cZ)", nFiles);
//   c1->SaveAs("hist_top_m_cz.png");

//   plot_hist(c1, mTopBW, "Mass of t(bW)", nFiles);
//   c1->SaveAs("hist_top_m_bw.png");

//   plot_hist(c1, htSig, "H_T of sig.", nFiles);
//   c1->SaveAs("hist_ht_s.png");

//  plot_hist(c1, htOther, "H_T of non-tt", nFiles);
//  c1->SaveAs("hist_ht_o.png");

//  plot_hist(c1, nPFJets, "No. of Jets", nFiles, "Number of Jets");
//   c1->SaveAs("hist_jet_no.png");

// // c1->SaveAs("hist_njets.C");
//  c1->SaveAs("hist_njets_2.png");
//  c1->SaveAs("hist_njets_2.pdf");
//  c1->SaveAs("hist_njets_2.C");

//  c1->SetLogy(0);

//  plot_hist(c1, MET, "Missing ET with cuts", nFiles, "#slash{E}_{T} [GeV]");
//  c1->SaveAs("hist_met_2.png");
//  c1->SaveAs("hist_met_2.pdf");
//  c1->SaveAs("hist_met_2.C");

//  plot_hist(c1, WeMT, "MT of We with cuts", nFiles, "M_{T} [GeV]");
//  c1->SaveAs("hist_wet_2.png");
//  c1->SaveAs("hist_wet_2.pdf");

//  plot_hist(c1, WmMT, "MT of Wm with cuts", nFiles, "M_{T} [GeV]");
//  c1->SaveAs("hist_wmt_2.png");
//  c1->SaveAs("hist_wmt_2.pdf");

//  plot_hist(c1, WMT, "MT of W with cuts", nFiles, "m_{T}(l+#slash{E}_{T}) [GeV]");
//  c1->SaveAs("hist_mt_2.png");
//  c1->SaveAs("hist_mt_2.pdf");
//  c1->SaveAs("hist_mt_2.C");


//  plot_hist(c1, mTopCZ, "Mass of t(cZ)", nFiles, "m_{Zj} [GeV]");
//  TLine * tl = new TLine();
//  tl->SetLineColor(kRed);
//  tl->SetLineWidth(2);
//  tl->SetLineStyle(2);
//  tl->DrawLine(250,0,250,12);
//  c1->SaveAs("hist_tcz_2.png");
//  c1->SaveAs("hist_tcz_2.pdf");

//  plot_hist(c1, mTopBW, "Mass of t(bW)", nFiles, "m_{Wb} [GeV]");
//  TLine * tl = new TLine();
//  tl->SetLineColor(kRed);
//  tl->SetLineWidth(2);
//  tl->SetLineStyle(2);
//  tl->DrawLine(250,0,250,12);
//  c1->SaveAs("hist_tbw_2.png");
//  c1->SaveAs("hist_tbw_2.pdf");

//  plot_hist(c1, mTopCZb, "Mass of t(cZ)", nFiles, "m_{Zj} [GeV]");
//  TLine * tl = new TLine();
//  tl->SetLineColor(kRed);
//  tl->SetLineWidth(2);
//  tl->SetLineStyle(2);
//  tl->DrawLine(147,0,147,7);
//  tl->DrawLine(197,0,197,7);
//  c1->SaveAs("hist_tczb_2.png");
//  c1->SaveAs("hist_tczb_2.pdf");
//  c1->SaveAs("hist_tczb_2.C");

//  plot_hist(c1, mTopBWb, "Mass of t(bW)", nFiles, "m_{Wb} [GeV]");
//  TLine * tl = new TLine();
//  tl->SetLineColor(kRed);
//  tl->SetLineWidth(2);
//  tl->SetLineStyle(2);
//  tl->DrawLine(137,0,137,7);
//  tl->DrawLine(207,0,207,7);
//  c1->SaveAs("hist_tbwb_2.png");
//  c1->SaveAs("hist_tbwb_2.pdf");
//  c1->SaveAs("hist_tbwb_2.C");

//  c1->SetLogy(0);

//  plot_hist(c1, htSig, "HT_S", nFiles, "S_{T} [GeV]");
//  c1->SetRightMargin(0.05);
//  TLine * tl = new TLine();
//  tl->SetLineColor(kRed);
//  tl->SetLineWidth(2);
//  tl->SetLineStyle(2);
//  //tl->DrawLine(250,0,250,12);

//   text1 = new TLatex(3.570061,23.08044,"(c)");
//   text1->SetNDC();
//   text1->SetTextAlign(13);
//   text1->SetX(0.684);
//   text1->SetY(0.428);
//   text1->SetTextFont(42);
//   text1->SetTextSizePixels(24);
//   text1->Draw();
// 
//  c1->SaveAs("hist_hts_2.png");
//  c1->SaveAs("hist_hts_2.pdf");
//  c1->SaveAs("hist_hts_2.C");
 

}
