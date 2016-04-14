#define MyTcZAna_cxx
#include "MyTcZAna.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <TLorentzVector.h>

#define MASS_E 0.00051
#define MASS_MU 0.10566
#define MASS_H 125.000
#define MASS_Z0 91.1876
#define MASS_W 80.385

#define VTX_NDOF_CUT 4
#define VTX_SUMPT_CUT -1
#define VTX_ABSZ_CUT 24.
#define VTX_RHO_CUT 2.

#define ELE_PT_CUT 20.
#define ELE_ETA_CUT 2.5
#define ELE_PT_TCUT 30.
#define ELE_MVA_LCUT 0.1
#define ELE_MVA_TCUT 0.5

#define MU_PT_CUT 20.
#define MU_ETA_CUT 2.4
#define MU_PT_TCUT 30.

#define Z_MASS_LCUT 60.   // 78
#define Z_MASS_HCUT 120.   // 102

#define Z_MASS_TLCUT 78.   // 78
#define Z_MASS_THCUT 102.   // 102

#define W_MASS_LCUT 70.   // 78
#define W_MASS_HCUT 190.   // 102

#define MET_CUT 30.
#define MET_TCUT 30.

#define JET_PT_CUT 30.
#define JET_ETA_CUT 2.1
#define JET_PT_TCUT 50.
//#define JET_BTAG_CUT 1.7  // loose WP
#define JET_BTAG_CUT 1.5  // Medium WP


void MyTcZAna::Loop()
{
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    //for (Long64_t jentry=0; jentry<10000;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    
    if(jentry%1000==0 && jentry>0){
      std::cout << "." << std::flush;
    }
    
    if(jentry%50000==0 && jentry>0){
      std::cout << " " << jentry << std::endl;
    }
    
    m_e_no=0;
    m_m_no=0;
    m_te_no=0;
    m_tm_no=0;
    m_z_no_m=0;
    m_z_no_e=0;
    
    m_w_no_m=0;
    m_w_no_e=0;
    
    m_w_idx=-1;
    m_z_idx=-1;
    
    m_jet_no=0;
    m_bjet_no=0;
    
    m_gen_zee_idx=-1;
    m_gen_wuu_idx=-1;
    
    m_gen_top1_idx=-1;
    m_gen_top2_idx=-1;
    m_top1_idx=-1;
    m_top2_idx=-1;
    m_top1b_idx=-1;
    m_top2b_idx=-1;
    
    m_gen_lep1_idx=-1;
    m_gen_lep2_idx=-1;
    m_gen_lep3_idx=-1;
    m_gen_lep4_idx=-1;
    
    Event_Weight_Tot += Event_Weight[0];
    
    // All event weight
    hist_evt_cut->Fill(0., Event_Weight[0]);
    hist_evt_cut_eee->Fill(0., Event_Weight[0]);
    hist_evt_cut_mmm->Fill(0., Event_Weight[0]);
    hist_evt_cut_eem->Fill(0., Event_Weight[0]);
    hist_evt_cut_emm->Fill(0., Event_Weight[0]);
    
    // Looping GEN info
    //if(Event_ProcessID[0] > 0){ // MC events
    if(Particle_size > 0){ // MC events
      if(Particle_size > kMaxParticle) cout << "!!!\n\n";

      for(int git=0; git < Particle_size && git < kMaxParticle; git++){
        Particle_P4[git].SetPtEtaPhiM(Particle_PT[git], Particle_Eta[git],
                                      Particle_Phi[git], Particle_Mass[git]);

        if(m_gen_zee_idx==-1 &&
           Particle_PID[git]==23 && Particle_Status[git]==3){
          m_gen_zee_idx=git;
          //continue;
        }
	  
        if(m_gen_wuu_idx==-1 &&
           abs(Particle_PID[git])==24 && Particle_Status[git]==3){
          m_gen_wuu_idx=git;
          //continue;
        }
	  
        if(m_gen_top1_idx==-1 && abs(Particle_PID[git]) == 6){
          m_gen_top1_idx = git;
          m_gen_top2_idx = git+1;
        }

        if(m_gen_zee_idx!=-1 && m_gen_top2_idx!=-1 &&
           Particle_fUniqueID[m_gen_top2_idx]==
           (Particle_M1[m_gen_zee_idx]-1)){
          m_gen_top1_idx=m_gen_top1_idx+1;
          m_gen_top2_idx=m_gen_top2_idx-1;  // swap them
        }

        if(jentry < 10 && git < kMaxParticle && Particle_Status[git]==3){
          if(git == 0) cout << endl;
          cout << "MC evt. " << jentry+1 << " #" << git << " "
               << Particle_fUniqueID[git] << " pdgID: "
               << Particle_PID[git] << " Mo: " << Particle_M1[git]
               << ","
               << Particle_M2[git] << " Da: " << Particle_D1[git]
               << ","
               << Particle_D2[git];

          if(m_gen_top1_idx == git)
            cout << " *\n";
          else if(m_gen_top2_idx == git)
            cout << " &\n";
          else
            cout << endl;
        }
      }  // GEN loop

      if(jentry < 10 && (m_gen_top1_idx!=-1 || m_gen_top2_idx!=-1)){
        cout << "Event #" << jentry << " top #1 " << m_gen_top1_idx
             << "; top #2 " << m_gen_top2_idx << endl;
      }


      for(int git=0; git < GenJet_size && git < kMaxGenJet; git++){
        GenJet_P4[git].SetPtEtaPhiM(GenJet_PT[git], GenJet_Eta[git],
                                    GenJet_Phi[git], GenJet_Mass[git]);
      }
    }  // IF MC

    // Trigger
    hist_evt_cut->Fill(1., Event_Weight[0]);
    hist_evt_cut_eee->Fill(1., Event_Weight[0]);
    hist_evt_cut_mmm->Fill(1., Event_Weight[0]);
    hist_evt_cut_eem->Fill(1., Event_Weight[0]);
    hist_evt_cut_emm->Fill(1., Event_Weight[0]);

    // Vertex
    hist_evt_cut->Fill(2., Event_Weight[0]);
    hist_evt_cut_eee->Fill(2., Event_Weight[0]);
    hist_evt_cut_mmm->Fill(2., Event_Weight[0]);
    hist_evt_cut_eem->Fill(2., Event_Weight[0]);
    hist_evt_cut_emm->Fill(2., Event_Weight[0]);

    // loop over leptons
    for(int il1=0; il1 < Electron_size; il1++){
      Electron_Good[il1]=0;
      Electron_Index[il1]=il1;
      Electron_GenMatch[il1]=-1;
      ReconElec(il1);
    }

    for(int il1=0; il1 < Muon_size; il1++){
      Muon_Good[il1]=0;
      Muon_Index[il1]=il1+100;
      Muon_GenMatch[il1]=-1;
      ReconMuon(il1);
    }

    hist_e_no->Fill(m_e_no, Event_Weight[0]);
    hist_m_no->Fill(m_m_no, Event_Weight[0]);
    hist_lep_no->Fill(m_e_no+m_m_no, Event_Weight[0]);
    
    if((m_e_no < 2) && (m_m_no < 2)) continue;

    // Two leptons
    hist_evt_cut->Fill(3, Event_Weight[0]);
    if(m_e_no >=2){
      hist_evt_cut_eee->Fill(3, Event_Weight[0]);
      hist_evt_cut_eem->Fill(3, Event_Weight[0]);
    }
    if(m_m_no >=2){
      hist_evt_cut_mmm->Fill(3, Event_Weight[0]);
      hist_evt_cut_emm->Fill(3, Event_Weight[0]);
    }
    
    m_z_no=0; m_z_no_e=0; m_z_no_m=0;
    m_tz_no=0; m_tz_no_e=0; m_tz_no_m=0;
    
    ReconJet();
    
    ReconZ();
    
    // One Z
    if(Zee_No==1){
      hist_evt_cut->Fill(4., Event_Weight[0]);
      
      if(Zee_lid1[0]<100){
        hist_evt_cut_eee->Fill(4., Event_Weight[0]);
        hist_evt_cut_eem->Fill(4., Event_Weight[0]);
        
        hist_met_pt_ee->Fill(MissingET_MET[0], Event_Weight[0]);
      }
      if(Zee_lid1[0]>=100){
        hist_evt_cut_mmm->Fill(4., Event_Weight[0]);
        hist_evt_cut_emm->Fill(4., Event_Weight[0]);
        
        hist_met_pt_mm->Fill(MissingET_MET[0], Event_Weight[0]);
      }
    }else
      continue;

    if((m_e_no + m_m_no) > 3) continue;
    
    // Three lepton
    if(Zee_No==1 && (m_e_no+m_m_no)==3){
      if(Zee_No==1){
        hist_evt_cut->Fill(5., Event_Weight[0]);
        
        if(Zee_lid1[0]<100){
          hist_met_pt_eel->Fill(MissingET_MET[0], Event_Weight[0]);
          if(m_e_no==3){
            hist_evt_cut_eee->Fill(5., Event_Weight[0]);
          }else{
            hist_evt_cut_eem->Fill(5., Event_Weight[0]);
          }
        }
        
        if(Zee_lid1[0]>=100){
          hist_met_pt_mml->Fill(MissingET_MET[0], Event_Weight[0]);
          if(m_m_no==3){
            hist_evt_cut_mmm->Fill(5., Event_Weight[0]);
          }else{
            hist_evt_cut_emm->Fill(5., Event_Weight[0]);
          }
        }
      }
    }else
      continue;

    if(MissingET_MET[0] < MET_TCUT) continue;

    ReconW();

    if(Wuu_No!=1) continue;
    
    hist_jet_no_c->Fill(m_jet_no, Event_Weight[0]);
    
    // One Z & W
    if(Zee_No==1 && Wuu_No==1){
      hist_evt_cut->Fill(6., Event_Weight[0]);
      
      if(Zee_lid1[0] < 100){
        if(m_w_no_m==1)
          hist_evt_cut_eem->Fill(6., Event_Weight[0]);
        else
          hist_evt_cut_eee->Fill(6., Event_Weight[0]);
      }
      if(Zee_lid1[0] >= 100){
        if(m_w_no_e==1)
          hist_evt_cut_emm->Fill(6., Event_Weight[0]);
        else
          hist_evt_cut_mmm->Fill(6., Event_Weight[0]);
      }
    }else
      continue;
    
    if(m_jet_no<2) continue;

    // Two jets
    hist_evt_cut->Fill(7., Event_Weight[0]);
    if(Zee_lid1[0]<100){
      if(m_w_no_m==1)
        hist_evt_cut_eem->Fill(7., Event_Weight[0]);
      else
        hist_evt_cut_eee->Fill(7., Event_Weight[0]);
    }
    if(Zee_lid1[0]>=100){
      if(m_w_no_e==1)
        hist_evt_cut_emm->Fill(7., Event_Weight[0]);
      else
        hist_evt_cut_mmm->Fill(7., Event_Weight[0]);
    }
    
    // No b-jet
    if(m_bjet_no==0){
      hist_evt_cut->Fill(8, Event_Weight[0]);
      if(Zee_lid1[0] < 100){
        if(m_w_no_m==1)
          hist_evt_cut_eem->Fill(8, Event_Weight[0]);
        else
          hist_evt_cut_eee->Fill(8, Event_Weight[0]);
      }
      if(Zee_lid1[0] >= 100){
        if(m_w_no_e==1)
          hist_evt_cut_emm->Fill(8, Event_Weight[0]);
        else
          hist_evt_cut_mmm->Fill(8, Event_Weight[0]);
      }
    }
    
    if(m_bjet_no!=1) continue;
    
    // One b-jet
    hist_evt_cut->Fill(9, Event_Weight[0]);
    if(Zee_lid1[0] < 100){
      if(m_w_no_m==1)
        hist_evt_cut_eem->Fill(9, Event_Weight[0]);
      else
        hist_evt_cut_eee->Fill(9, Event_Weight[0]);
    }
    if(Zee_lid1[0] >= 100){
      if(m_w_no_e==1)
        hist_evt_cut_emm->Fill(9, Event_Weight[0]);
      else
        hist_evt_cut_mmm->Fill(9, Event_Weight[0]);
    }
    
    Top_No=0;
    
    ReconTop();
    
    hist_top_no->Fill(Top_No, Event_Weight[0]);
    
    //int has_true=0;
    double max_dphi=-999., delta_phi=0.;
    //double min_dm=999.;
    m_top1_idx = m_top2_idx=-1;
    m_top1b_idx = m_top2b_idx=-1;
    
    for(int it1=0; it1 < Top_No; it1++){
      if(Top_Type[it1] != 1) continue;  // first is cZ
      
      for(int it2=0; it2 < Top_No; it2++){
        if(Top_Type[it2] != 2) continue;  // second is bW
        
        // check no duplicated jets
        if(Top_Jidx[it1] == Top_Jidx[it2]) continue;
        
        // The angle between T1 and T2 in phi
        delta_phi = fabs((Top_P4[it1]).DeltaPhi(Top_P4[it2]));
        
        // Take the candidate with max. delta phi
        if(delta_phi > max_dphi){
          max_dphi = delta_phi;
          //max_dphi = ptsum;
          m_top1_idx = it1;
          m_top2_idx = it2;
          
          m_z_idx = Top_Vidx[it1];
          m_w_idx = Top_Vidx[it2];
        }
        
        if(m_jet_no >= 2 && m_bjet_no == 1 &&
           Jet_Good[Top_Jidx[it1]]==1 && Jet_Good[Top_Jidx[it2]]==2){
          
          m_top2b_idx = it2;
          
        }
      }
    }

    hist_top_m_cz_f->Fill((Top_P4[m_top1_idx]).M(), Event_Weight[0]);
    hist_top_mt_cz_f->Fill((Top_P4[m_top1_idx]).Mt(), Event_Weight[0]);
    hist_top_pt_cz_f->Fill((Top_P4[m_top1_idx]).Pt(), Event_Weight[0]);
    
    hist_top_m_bw_f->Fill((Top_P4[m_top2_idx]).M(), Event_Weight[0]);
    hist_top_mt_bw_f->Fill((Top_P4[m_top2_idx]).Mt(), Event_Weight[0]);
    hist_top_pt_bw_f->Fill((Top_P4[m_top2_idx]).Pt(), Event_Weight[0]);
    
    hist_top_dphi->Fill((Top_P4[m_top1_idx]).DeltaPhi(Top_P4[m_top2_idx]),
                        Event_Weight[0]);
    
    hist_evt_cut->Fill(10, Event_Weight[0]);
    if(Zee_lid1[0] < 100){
      if(m_w_no_m>0)
        hist_evt_cut_eem->Fill(10, Event_Weight[0]);
      else
        hist_evt_cut_eee->Fill(10, Event_Weight[0]);
    }
    
    if(Zee_lid1[0] >= 100){
      if(m_w_no_e>0)
        hist_evt_cut_emm->Fill(10, Event_Weight[0]);
      else
        hist_evt_cut_mmm->Fill(10, Event_Weight[0]);
    }
    
    if(Top_P4[m_top1_idx].M()>147 && Top_P4[m_top1_idx].M()<197){
      
      hist_evt_cut->Fill(11, Event_Weight[0]); // top pair with mass cut
      
      if(Zee_lid1[0] < 100){
        if(m_w_no_m>0)
          hist_evt_cut_eem->Fill(11, Event_Weight[0]);
        else
          hist_evt_cut_eee->Fill(11, Event_Weight[0]);
      }
      if(Zee_lid1[0] >= 100){
        if(m_w_no_e>0)
          hist_evt_cut_emm->Fill(11, Event_Weight[0]);
        else
          hist_evt_cut_mmm->Fill(11, Event_Weight[0]);
      }
      
      if(Top_P4[m_top1_idx].M()>147 && Top_P4[m_top1_idx].M()<197 &&
         Top_P4[m_top2_idx].M()>137 && Top_P4[m_top2_idx].M()<207){
        
        hist_evt_cut->Fill(12, Event_Weight[0]); // top pair with mass cut
        
        if(Zee_lid1[0] < 100){
          if(m_w_no_m>0)
            hist_evt_cut_eem->Fill(12, Event_Weight[0]);
          else
            hist_evt_cut_eee->Fill(12, Event_Weight[0]);
        }
        if(Zee_lid1[0] >= 100){
          if(m_w_no_e>0)
            hist_evt_cut_emm->Fill(12, Event_Weight[0]);
          else
            hist_evt_cut_mmm->Fill(12, Event_Weight[0]);
        }
      }
    }
  }  // Event loop
  
  std::cout << "\n Finishing... " << nentries << std::endl;
}

void MyTcZAna::ReconElec(int il1){

  hist_ele_cut->Fill(0., Event_Weight[0]);

  Electron_P4[il1].SetPtEtaPhiM(Electron_PT[il1], Electron_Eta[il1],
				Electron_Phi[il1], 0.00051);

  hist_ae_pt->Fill(Electron_P4[il1].Pt(), Event_Weight[0]);
  hist_ae_eta->Fill(Electron_P4[il1].Eta(), Event_Weight[0]);
  hist_ae_phi->Fill(Electron_P4[il1].Phi(), Event_Weight[0]);

  // checking GEN matching

  double min_dr=0.3, delta_r=0.;
  for(int ig=3; ig < Particle_size && ig < kMaxParticle; ig++){
    delta_r = Particle_P4[ig].DeltaR(Electron_P4[il1]);
    
    if(Particle_P4[ig].Pt() > 0 && Electron_P4[il1].Pt() > 0 &&
       fabs(delta_r) < min_dr &&
       (Particle_P4[ig].Pt()/Electron_P4[il1].Pt()) > 1 / 2. &&
       (Particle_P4[ig].Pt()/Electron_P4[il1].Pt()) < 2.){
      Electron_GenMatch[il1] = ig;
      min_dr = delta_r;
    }
  }	      

  if(Electron_GenMatch[il1]!=-1 &&
     abs(Particle_PID[Electron_GenMatch[il1]])==11){
    hist_ge_pt->Fill(Electron_P4[il1].Pt(), Event_Weight[0]);
    hist_ge_phi->Fill(Electron_P4[il1].Phi(), Event_Weight[0]);
    hist_ge_eta->Fill(Electron_P4[il1].Eta(), Event_Weight[0]);
    
    hist_ele_cut->Fill(1., Event_Weight[0]);
  }
  
  if(Electron_PT[il1] > ELE_PT_CUT){
    hist_ele_cut->Fill(2., Event_Weight[0]);
    
    if(fabs(Electron_Eta[il1]) < ELE_ETA_CUT &&
       (fabs(Electron_Eta[il1])<1.4442 || fabs(Electron_Eta[il1])>1.566)){
      hist_ele_cut->Fill(3., Event_Weight[0]);
      
      hist_e_pt->Fill(Electron_P4[il1].Pt(), Event_Weight[0]);
      hist_e_eta->Fill(Electron_P4[il1].Eta(), Event_Weight[0]);
      hist_e_phi->Fill(Electron_P4[il1].Phi(), Event_Weight[0]);
      hist_e_iso->Fill(Electron_IsolationVar[il1], Event_Weight[0]);
      
      if(Electron_PT[il1] > ELE_PT_TCUT && 
         Electron_EhadOverEem[il1] < 0.5){  // EID
        hist_ele_cut->Fill(4., Event_Weight[0]); 
        
        Electron_Good[il1]=1;

        if(Electron_IsolationVar[il1] < 0.2){  // ISO
          hist_ele_cut->Fill(5., Event_Weight[0]); 
          
          Electron_Good[il1]=2;
          m_e_no++;
	
          if(Electron_GenMatch[il1]!=-1 &&
             abs(Particle_PID[Electron_GenMatch[il1]])==11){
            hist_ele_cut->Fill(6., Event_Weight[0]);
          }
          
        }
      }
    }
  }
}

void MyTcZAna::ReconMuon(int il1){

  hist_mu_cut->Fill(0., Event_Weight[0]);
  Muon_P4[il1].SetPtEtaPhiM(Muon_PT[il1], Muon_Eta[il1],
                            Muon_Phi[il1], 0.10566);
  
  hist_mu_cut->Fill(0., Event_Weight[0]);
  
  hist_am_pt->Fill(Muon_P4[il1].Pt(), Event_Weight[0]);
  hist_am_phi->Fill(Muon_P4[il1].Phi(), Event_Weight[0]);
  hist_am_eta->Fill(Muon_P4[il1].Eta(), Event_Weight[0]);
  
  // checking GEN matching
  
  double min_dr=0.3, delta_r=0.;
  for(int ig=3; ig < Particle_size && ig < kMaxParticle; ig++){
    delta_r = Particle_P4[ig].DeltaR(Muon_P4[il1]);
    
    if(Particle_P4[ig].Pt() > 0 && Muon_P4[il1].Pt() > 0 &&
       fabs(delta_r) < min_dr &&
       (Particle_P4[ig].Pt()/Muon_P4[il1].Pt()) > 1 / 2. &&
       (Particle_P4[ig].Pt()/Muon_P4[il1].Pt()) < 2.){
      Muon_GenMatch[il1] = ig;
    }
  }	      
  

  if(Muon_GenMatch[il1]!=-1 &&
     abs(Particle_PID[Muon_GenMatch[il1]])==13){
    hist_gm_pt->Fill(Muon_P4[il1].Pt(), Event_Weight[0]);
    hist_gm_phi->Fill(Muon_P4[il1].Phi(), Event_Weight[0]);
    hist_gm_eta->Fill(Muon_P4[il1].Eta(), Event_Weight[0]);
    
    hist_mu_cut->Fill(1., Event_Weight[0]);
  }
      
  if(Muon_PT[il1] > MU_PT_CUT){
    hist_mu_cut->Fill(2., Event_Weight[0]);
	
    if(fabs(Muon_Eta[il1]) < MU_ETA_CUT){
      hist_mu_cut->Fill(3., Event_Weight[0]);
      
      hist_m_pt->Fill(Muon_PT[il1], Event_Weight[0]);
      hist_m_eta->Fill(Muon_Eta[il1], Event_Weight[0]);
      hist_m_phi->Fill(Muon_Phi[il1], Event_Weight[0]);
      hist_m_iso->Fill(Muon_IsolationVar[il1], Event_Weight[0]);
      
      
      //if(Electron_EhadOverEem[il1] < 0.5){  // EID
      if(Muon_PT[il1] > MU_PT_TCUT){
        hist_mu_cut->Fill(4., Event_Weight[0]);
        
        Muon_Good[il1]=1;
        
        if(Muon_IsolationVar[il1] < 0.2){  // ISO
          hist_mu_cut->Fill(5., Event_Weight[0]); 
          
          Muon_Good[il1]=2;
          m_m_no++;
          
          if(Muon_GenMatch[il1]!=-1 &&
             abs(Particle_PID[Muon_GenMatch[il1]])==13){
            hist_mu_cut->Fill(6., Event_Weight[0]);
          }
        }
      }
    }
  }
}

void MyTcZAna::ReconZ(){
  // Z selections
  Zee_No=0;
  
  double delta_m=0., min_dm=9999.;
  for(int il1=0; il1 < Electron_size; il1++){
    
    //if(Leptons_LeptonType[il1]==11 ){
    if(Electron_Good[il1]==2){
      
      for(int il2=il1; il2 < Electron_size; il2++){
        if(Electron_Good[il1]>=1 && Electron_Good[il2]>=1 &&
           Electron_Charge[il1]*Electron_Charge[il2]==-1){
          
          Zee_P4[Zee_No]=(Electron_P4[il1]+Electron_P4[il2]);
          delta_m = fabs(Zee_P4[Zee_No].M()-MASS_Z0);
          
          hist_zee_m->Fill(Zee_P4[Zee_No].M(), Event_Weight[0]);
          hist_zee_pt->Fill(Zee_P4[Zee_No].Pt(), Event_Weight[0]);
          
          if(Zee_P4[Zee_No].M() > Z_MASS_LCUT &&
             Zee_P4[Zee_No].M() < Z_MASS_HCUT && delta_m < min_dm){
            
            Zee_lid1[Zee_No]=Electron_Index[il1];
            Zee_lid2[Zee_No]=Electron_Index[il2];
            
            //cout << "Zee mass: " << Zee.mass() << endl;
            Zee_No++;
            m_z_no_e++;
          }
        }
        
      }
    }
  }

  for(int il1=0; il1 < Muon_size; il1++){
    // now look for muons
    if(Muon_Good[il1]==2){
      
      for(int il2=il1+1; il2 < Muon_size; il2++){
        if(Muon_Good[il1]>=1 && Muon_Good[il2]>=1 &&
           Muon_Charge[il1]*Muon_Charge[il2]==-1){
          
          Zee_P4[Zee_No]=(Muon_P4[il1]+Muon_P4[il2]);
          delta_m = fabs(Zee_P4[Zee_No].M()-MASS_Z0);
          
          hist_zmm_m->Fill(Zee_P4[Zee_No].M(), Event_Weight[0]);
          hist_zmm_pt->Fill(Zee_P4[Zee_No].Pt(), Event_Weight[0]);
          
          if(Zee_P4[Zee_No].M() > Z_MASS_LCUT &&
             Zee_P4[Zee_No].M() < Z_MASS_HCUT && delta_m < min_dm){
            
            Zee_lid1[Zee_No]=Muon_Index[il1];
            Zee_lid2[Zee_No]=Muon_Index[il2];
            
            Zee_No++;
            m_z_no_m++;
            
          }
        } // Leptons2 IF
      } // Leptons2 loop
    } // Leptons1 IF
  } // Leptons loop

  hist_z_n->Fill(Zee_No, Event_Weight[0]);
  hist_zee_n->Fill(m_z_no_e, Event_Weight[0]);
  hist_zmm_n->Fill(m_z_no_m, Event_Weight[0]);
}

void MyTcZAna::ReconW(){
  // W selections
  //int Wen_No=0, Wmn_No=0;
  Wuu_No=0;
  
  hist_met_pt->Fill(MissingET_MET[0], Event_Weight[0]);
  hist_met_phi->Fill(MissingET_Phi[0], Event_Weight[0]);
  
  int m_lep_idx=-1;
  
  TLorentzVector nu;
  
  nu.SetPxPyPzE(MissingET_MET[0]*cos(MissingET_Phi[0]),
                MissingET_MET[0]*sin(MissingET_Phi[0]), 0.,
                MissingET_MET[0]);
  
  // loop over leptons for W
  m_te_no=0; m_tm_no=0;
  for(int il1=0; il1 < Electron_size; il1++){
    
    if(Electron_Good[il1] == 2 && Zee_No==1 && 
       Electron_Index[il1]!=Zee_lid1[0] && Electron_Index[il1]!=Zee_lid2[0]){
      
      m_lep_idx=il1;
      m_te_no++;

      hist_te_pt->Fill(Electron_P4[il1].Pt(), Event_Weight[0]);
      hist_te_eta->Fill(Electron_P4[il1].Eta(), Event_Weight[0]);
      hist_te_phi->Fill(Electron_P4[il1].Phi(), Event_Weight[0]);
      
      if(Electron_GenMatch[il1]!=-1){
        hist_get_pt->Fill(Electron_P4[il1].Pt(), Event_Weight[0]);
        hist_get_phi->Fill(Electron_P4[il1].Phi(), Event_Weight[0]);
        hist_get_eta->Fill(Electron_P4[il1].Eta(), Event_Weight[0]);
        
        hist_ele_cut->Fill(7, Event_Weight[0]);
      }
    }
  }
  
  for(int il1=0; il1 < Muon_size; il1++){
    if(Muon_Good[il1] == 2 && Zee_No==1 && 
       Muon_Index[il1]!=Zee_lid1[0] && Muon_Index[il1]!=Zee_lid2[0]){

      m_lep_idx=il1;
      m_tm_no++;

      hist_tm_pt->Fill(Muon_P4[il1].Pt(), Event_Weight[0]);
      hist_tm_eta->Fill(Muon_P4[il1].Eta(), Event_Weight[0]);
      hist_tm_phi->Fill(Muon_P4[il1].Phi(), Event_Weight[0]);
      
      if(Muon_GenMatch[il1]!=-1){
        hist_gmt_pt->Fill(Muon_P4[il1].Pt(), Event_Weight[0]);
        hist_gmt_phi->Fill(Muon_P4[il1].Phi(), Event_Weight[0]);
        hist_gmt_eta->Fill(Muon_P4[il1].Eta(), Event_Weight[0]);
        
        hist_mu_cut->Fill(15, Event_Weight[0]);
      }
    }
  }
  
  if((m_te_no+m_tm_no)==1){
    TLorentzVector lep;
    
    if(m_te_no==1){
      lep.SetPxPyPzE(Electron_P4[m_lep_idx].Px(), Electron_P4[m_lep_idx].Py(),
                     Electron_P4[m_lep_idx].Pz(), Electron_P4[m_lep_idx].E());
    }else{
      lep.SetPxPyPzE(Muon_P4[m_lep_idx].Px(), Muon_P4[m_lep_idx].Py(),
                     Muon_P4[m_lep_idx].Pz(), Muon_P4[m_lep_idx].E());   
    }
    
    double pz=0, b4ac=0, b=0;
    b=lep.Px()*nu.Px()+lep.Py()*nu.Py()+MASS_W*MASS_W/2;
    b4ac=b*b-nu.E()*nu.E()*(lep.E()*lep.E()-lep.Pz()*lep.Pz());
    
    if(b4ac>0){
      if((lep.Pz()*b) * (lep.E()*sqrt(b4ac)) >= 0){
        pz=(lep.Pz()*b - lep.E()*sqrt(b4ac)) /
          (lep.E()*lep.E()-lep.Pz()*lep.Pz());
      }else{
        pz=(lep.Pz()*b + lep.E()*sqrt(b4ac)) /
          (lep.E()*lep.E()-lep.Pz()*lep.Pz());
      }
    }else{
      pz=(lep.Pz()*b) / (lep.E()*lep.E()-lep.Pz()*lep.Pz());
    }
    
    nu.SetPxPyPzE(MissingET_MET[0]*cos(MissingET_Phi[0]),
                  MissingET_MET[0]*sin(MissingET_Phi[0]), pz,
                  sqrt(MissingET_MET[0]*MissingET_MET[0]+pz*pz));
    
    Wuu_P4[Wuu_No]=(nu+lep);
    
    if(m_te_no==1){
      Wuu_Mt[Wuu_No] = sqrt(2 * Electron_P4[m_lep_idx].Pt() * MissingET_MET[0]*
                            ( 1 - cos(MissingET_Phi[0]-
                                      Electron_P4[m_lep_idx].Phi())));
      
      hist_wen_m->Fill(Wuu_P4[Wuu_No].M(), Event_Weight[0]);
      hist_wen_mt->Fill(Wuu_Mt[Wuu_No], Event_Weight[0]);
      hist_wen_pt->Fill(Wuu_P4[Wuu_No].Pt(), Event_Weight[0]);
      
      if(m_z_no_e > 0){
        hist_wen_mt_ee->Fill(Wuu_Mt[Wuu_No], Event_Weight[0]);
      }
      if(m_z_no_m > 0){
        hist_wen_mt_mm->Fill(Wuu_Mt[Wuu_No], Event_Weight[0]);
      }
      
      Wuu_lid[Wuu_No]=Electron_Index[m_lep_idx];
      
      m_w_no_e++;
      Wuu_No++;
    }

    if(m_tm_no==1){
      Wuu_Mt[Wuu_No] = sqrt(2 * Muon_P4[m_lep_idx].Pt() * MissingET_MET[0] *
                            ( 1 - cos(MissingET_Phi[0]-
                                      Muon_P4[m_lep_idx].Phi())));
      
      hist_wmn_m->Fill(Wuu_P4[Wuu_No].M(), Event_Weight[0]);
      hist_wmn_mt->Fill(Wuu_Mt[Wuu_No], Event_Weight[0]);
      hist_wmn_pt->Fill(Wuu_P4[Wuu_No].Pt(), Event_Weight[0]);
      
      if(m_z_no_e > 0){
        hist_wmn_mt_ee->Fill(Wuu_Mt[Wuu_No], Event_Weight[0]);
      }
      if(m_z_no_m > 0){
        hist_wmn_mt_mm->Fill(Wuu_Mt[Wuu_No], Event_Weight[0]);
      }
      
      Wuu_lid[Wuu_No]=Muon_Index[m_lep_idx];
	
      m_w_no_m++;
      Wuu_No++;
    }
  }
}

void MyTcZAna::ReconJet(){
  // Looping over jets
  Jet_No=0;
  
  for(int ij1=0; ij1 < Jet_size && ij1 < kMaxJet; ij1++){
    hist_jet_cut->Fill(0., Event_Weight[0]);
    
    Jet_Good[ij1]=0;
    
    Jet_P4[ij1].SetPtEtaPhiM(Jet_PT[ij1], Jet_Eta[ij1],
                             Jet_Phi[ij1], Jet_Mass[ij1]);
    
    hist_ajet_pt->Fill(Jet_P4[ij1].Pt(), Event_Weight[0]);
    hist_ajet_eta->Fill(Jet_P4[ij1].Eta(), Event_Weight[0]);
    hist_ajet_phi->Fill(Jet_P4[ij1].Phi(), Event_Weight[0]);
    
    // checking GEN matching
    Jet_GenMatch[ij1]=-1;
    double min_dr=0.5, delta_r=0.;
    for(int ig=0; ig < GenJet_size && ig < kMaxGenJet; ig++){
      
      delta_r = GenJet_P4[ig].DeltaR(Jet_P4[ij1]);
      if(GenJet_P4[ig].Pt() > 0 && Jet_P4[ij1].Pt() > 0 &&
         fabs(delta_r) < min_dr &&
         (GenJet_P4[ig].Pt()/Jet_P4[ij1].Pt()) > 1 / 2. &&
         (GenJet_P4[ig].Pt()/Jet_P4[ij1].Pt()) < 2.){
        Jet_GenMatch[ij1] = ig;
      }
    }

    if(Jet_GenMatch[ij1] != -1){
      hist_gjet_pt->Fill(Jet_PT[ij1], Event_Weight[0]);
      hist_gjet_eta->Fill(Jet_Eta[ij1], Event_Weight[0]);
      hist_gjet_phi->Fill(Jet_Phi[ij1], Event_Weight[0]);
      
      hist_jet_cut->Fill(1, Event_Weight[0]);
    }
    
    //int jet_pass=0;
    if(Jet_PT[ij1] > JET_PT_CUT){
      hist_jet_cut->Fill(2, Event_Weight[0]);
	  
      if(fabs(Jet_Eta[ij1]) < JET_ETA_CUT){
        hist_jet_cut->Fill(3, Event_Weight[0]);
        
        hist_jet_pt->Fill(Jet_P4[ij1].Pt(), Event_Weight[0]);
        hist_jet_eta->Fill(Jet_P4[ij1].Eta(), Event_Weight[0]);
        hist_jet_phi->Fill(Jet_P4[ij1].Phi(), Event_Weight[0]);
	    
        //Jets.JetIDLOOSE[Jets.Size] = (JetID) ?  1 : 0;

        // Jet ID
        if(Jet_PT[ij1] > JET_PT_TCUT){
          hist_jet_cut->Fill(4, Event_Weight[0]);

//        Iso
          Jet_Good[ij1]=1;
          hist_jet_cut->Fill(5, Event_Weight[0]);
          
          if(Jet_GenMatch[ij1] != -1){
            hist_jet_cut->Fill(6, Event_Weight[0]);
          }

          if(Jet_BTag[ij1] > JET_BTAG_CUT){
            Jet_Good[ij1]=2;  // Tight WP
            m_bjet_no++;
          }
        
          Jet_No++;
          m_jet_no++;
        }
      }
    }
  }
  hist_jet_no->Fill(m_jet_no, Event_Weight[0]);   
}

void MyTcZAna::ReconTop(){
  for(int ij1=0; ij1 < Jet_size; ij1++){
    if(Jet_Good[ij1]>=1){	  
      for(int iz=0; iz < Zee_No; iz++){ 
        Top_P4[Top_No]=(Jet_P4[ij1]+Zee_P4[iz]);
        
        if(Jet_Good[ij1]>=1 && // apply anti-b?
           Top_P4[Top_No].M() > 90.){
          
          Top_Mt[Top_No]=Top_P4[Top_No].Mt();
          Top_Mass[Top_No]=Top_P4[Top_No].M();
          Top_Type[Top_No]=1;  // t -> c H
          Top_Vidx[Top_No]=iz;
          Top_Jidx[Top_No]=ij1;
          
          hist_top_m_cz->Fill(Top_P4[Top_No].M(), Event_Weight[0]);
          hist_top_mt_cz->Fill(Top_P4[Top_No].Mt(), Event_Weight[0]);
          hist_top_pt_cz->Fill(Top_P4[Top_No].Pt(), Event_Weight[0]);
          Top_No++;
        }
        
      }
      
      for(int iw=0; iw < Wuu_No; iw++){
        Top_P4[Top_No]=(Jet_P4[ij1]+Wuu_P4[iw]);
        
        if(Jet_Good[ij1]==2 && Top_P4[Top_No].M() > 90.){ // b-tagged
          
          Top_Mt[Top_No]=Top_P4[Top_No].Mt();
          Top_Mass[Top_No]=Top_P4[Top_No].M();
          Top_Type[Top_No]=2;  // t -> b W
          Top_Vidx[Top_No]=iw;
          Top_Jidx[Top_No]=ij1;
          
          hist_top_m_bw->Fill(Top_P4[Top_No].M(), Event_Weight[0]);
          hist_top_mt_bw->Fill(Top_P4[Top_No].Mt(), Event_Weight[0]);
          hist_top_pt_bw->Fill(Top_P4[Top_No].Pt(), Event_Weight[0]);
          //hist_top_eta_bw->Fill(Top_P4[Top_No].Eta(), Event_Weight[0]);
          
          Top_No++;
        }
      }
    }
  }
}
