// -*- C++ -*-
//
// Package:    JetRejectorTool
// Class:      JetRejMVA
// 
/**\class JetRejectorTool JetRejMVAEval.cc PhysicsTools/JetRejectorTool/src/JetRejMVA.cc

 Description: MVA implementation for Ilaria's JetRejectorTool

 Implementation:
     Using MVA Tool
*/
//
// Original Author:  Yuan CHAO
//         Created:  Apr. 2008
// $Id$
//
//

#include "PhysicsTools/JetRejectorTool/interface/JetRejMVA.h"

#include "PhysicsTools/MVAComputer/interface/HelperMacros.h"

//
// constructor
//

static const AtomicId ObsIds[17] = {
        "obs0",
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
  JetSelObs_ = iConfig.getUntrackedParameter< vector<int> > ( "JetSelObs"); 
 
  for(unsigned int j = 0; j < JetSelObs_.size(); j++){
    obsNrs.push_back(JetSelObs_[j]);
  }

  ///-----------------------------------------------------------------

  //produces<  vector< double > >(); 
}

// destructor
JetRejMVAEval::~JetRejMVAEval()
{
  // delete myJetRejLRObs;
}

void JetRejMVAEval::produce( edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  std::vector <double >  *myObs = new std::vector <double> ;

  Handle<vector<JetRejObs> > observables;
  iEvent.getByLabel(obssrc_, observables); 

  // update the cached MVAComputer from calibrations
  // passed via EventSetup.
  // you can use a MVAComputerContainer to pass around
  // multiple different MVA's in one event setup record
  // identify the right one by a definable name string
  mvaComputer.update<MVAJRRcd>(iSetup, "testMVA");

  JetRejObs obsValue;
  double myJet= -1;
  double logLR;
  // get observable values
  vector<double> obsVals;
  
  Variable::Value values[6];

  for(unsigned int i_obs=0; i_obs < observables->size(); i_obs++){

    int m_os=0;
    bool target=0;

    JetRejObs obsValue=(*observables)[i_obs];
    for(unsigned int i_val=0; i_val<obsValue.getSize(); i_val++){
      if(obsValue.getPair(i_val).first == 0 )
	target = obsValue.getPair(i_val).second;

      for(unsigned int i_os=0; i_os<JetSelObs_.size(); i_os++){
        if(obsValue.getPair(i_val).first == JetSelObs_[i_os]){
          values[m_os++]=Variable::Value(ObsIds[JetSelObs_[i_os]],
                                         obsValue.getPair(i_val).second);
        }
      }
    }
    
    double result = mvaComputer->eval(values, values + m_os);

    myObs->push_back( result );
    //std::cout << "mva.eval(x = 1.0, y = 1.5) = " << result <<
    //", \t" << target << std::endl;
  }
  
  //---------------------------------
  
  std::auto_ptr<std::vector< double > > pOut(myObs);
  iEvent.put( pOut );
  ///-----------------------
  
}
 //define this as a plug-in
#include "FWCore/Framework/interface/MakerMacros.h"
 DEFINE_FWK_MODULE(JetRejMVAEval);

// define the plugins for the record
#include "PhysicsTools/MVAComputer/interface/HelperMacros.h"
MVA_COMPUTER_CONTAINER_IMPLEMENT(MVAJR);
// this will implictly define an EDM es_source named "MVADemoFileSource"
// which will allow to read the calibration from file into the EventSetup
// note that for CondDB the PoolDBESSource can be used instead
