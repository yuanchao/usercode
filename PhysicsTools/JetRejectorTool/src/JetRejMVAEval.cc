// -*- C++ -*-
//
// Package:    JetRejectorTool
// Class:      JetRejMVA
// 
/**\class JetRejectorTool JetRejMVAEval.cc PhysicsTools/JetRejectorTool/src/JetRejMVA.cc

 Description: MVA implementation for Ilaria's JetRejectorTool

 Implementation:
     Using MVA Toolproducer
*/
//
// Original Author:  Yuan CHAO
//         Created:  Apr. 2008
// $Id: JetRejMVAEval.cc,v 1.2 2008/05/07 13:09:51 yuanchao Exp $
//
//

#include "PhysicsTools/JetRejectorTool/interface/JetRejMVAEval.h"
#include "PhysicsTools/JetRejectorTool/interface/JetRejObsProducer.h"
#include "DataFormats/Common/interface/Association.h"
#include "DataFormats/Common/interface/RefToBase.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include "PhysicsTools/MVAComputer/interface/HelperMacros.h"

//
// constructor
//

static const AtomicId ObsIds[17] = {
        "target",
        "obs1",
        "obs2",
        "obs3",
        "obs4",
        "obs5",
        "obs6",
        "obs7",
        "obs8",
        "obs9",
        "obs10",
        "obs11",
        "obs12",
        "obs13",
        "obs14",
        "obs15",
        "obs16"
};

JetRejMVAEval::JetRejMVAEval(const edm::ParameterSet& iConfig){
  obssrc_ = iConfig.getParameter<edm::InputTag>( "obssrc" );
  selcalojetsrc_ = iConfig.getParameter<edm::InputTag>( "selcalojetsrc" );
  JetSelObs_ = iConfig.getUntrackedParameter< vector<int> > ( "JetSelObs"); 
 
  for(unsigned int j = 0; j < JetSelObs_.size(); j++){
    obsNrs.push_back(JetSelObs_[j]);
  }

  ///-----------------------------------------------------------------

  //produces<  vector< double > >(); 
  produces< JetRejMap >(); 
}

// destructor
JetRejMVAEval::~JetRejMVAEval()
{
  // delete myJetRejLRObs;
}

void JetRejMVAEval::produce( edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //std::vector <double >  *myObs = new std::vector <double> ;

  //read in jets, use jets to access JetRejObsMap:
  Handle<View<reco::CaloJet> > jets; 
  iEvent.getByLabel( selcalojetsrc_, jets); 

  Handle<JetRejObsProducer::JetRejObsMap> observables;
  iEvent.getByLabel(obssrc_, observables); 

  // update the cached MVAComputer from calibrations
  // passed via EventSetup.
  // you can use a MVAComputerContainer to pass around
  // multiple different MVA's in one event setup record
  // identify the right one by a definable name string
  mvaComputer.update<MVAJetRejRcd>(iSetup, "JetRejMVA");

  JetRejObs obsValue;
//  double myJet= -1;
//  double logLR;
  // get observable values
  vector<double> obsVals;
  
  Variable::Value values[32];

  // create map passing the handle to the matched collection
  std::auto_ptr<JetRejMap> jetmva(new JetRejMap);

  JetRejMap::Filler filler(*jetmva);
  {
    size_t n = jets->size();
    std::vector<double> mva(n);
    
    //View<CaloJet>::const_iterator thisjet = jets->begin();
    View<reco::CaloJet> thisjet = (*jets);

    //for(unsigned int i_jet=0; i_jet != jets->size(); ++ i_jet, ++thisjet) {
    for(View<CaloJet>::const_iterator i_jet = jets->begin();
        i_jet != jets->end(); ++i_jet) {
      // compute the match for i-th jet, store the index in genParticles collection

      RefToBase<CaloJet> thisjetref = jets->refAt(i_jet - jets->begin());
      obsValue = (*observables)[thisjetref]; // vector of observables for each jet!

      for(unsigned int i_os=0; i_os<obsValue.getSize(); i_os++){
        values[i_os]=Variable::Value(ObsIds[i_os],
	                             obsValue.getPair(i_os).second);
      }

      double result = mvaComputer->eval(values +1, values + obsValue.getSize());
      
      mva[i_jet - jets->begin()]=result;
    }
    
    filler.insert(jets, mva.begin(), mva.end());
  }
  
  // really fill the association map
  filler.fill();
  // put into the event
  iEvent.put( jetmva );
  ///-----------------------
  
}
 //define this as a plug-in
#include "FWCore/Framework/interface/MakerMacros.h"
 DEFINE_FWK_MODULE(JetRejMVAEval);

// define the plugins for the record
#include "PhysicsTools/MVAComputer/interface/HelperMacros.h"
MVA_COMPUTER_CONTAINER_IMPLEMENT(MVAJetRej);
// this will implictly define an EDM es_source named "MVADemoFileSource"
// which will allow to read the calibration from file into the EventSetup
// note that for CondDB the PoolDBESSource can be used instead
