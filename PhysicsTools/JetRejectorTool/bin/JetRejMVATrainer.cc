#include <iostream>
#include <memory>

#include <TRandom.h>

#include "DataFormats/RecoCandidate/interface/RecoCaloTowerCandidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleCandidate.h"
#include "DataFormats/Candidate/interface/Candidate.h"
//#include "PhysicsTools/JetRejectorTool/interface/PhysicsJet.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/BTauReco/interface/JetTracksAssociation.h"
#include "DataFormats/BTauReco/interface/JetTag.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/Candidate/interface/CandMatchMap.h"
#include "PhysicsTools/JetRejectorTool/interface/JetRejLRObservables.h"
#include "AnalysisDataFormats/TopObjects/interface/JetRejObs.h"
//#include "PhysicsTools/JetRejectorTool/interface/JetRejObs.h"
#include "TopQuarkAnalysis/TopTools/interface/JetPartonMatching.h"

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "PhysicsTools/MVAComputer/interface/MVAComputerCache.h"

#include "PhysicsTools/MVATrainer/interface/HelperMacros.h"

//#include "PhysicsTools/MVAComputer/test/testMVAComputerEvaluate.h"

#include "CondFormats/PhysicsToolsObjects/interface/MVAComputer.h"
#include "PhysicsTools/MVAComputer/interface/Variable.h"
#include "PhysicsTools/MVAComputer/interface/MVAComputer.h"

// take the event setup record for "MVAJetRejRcd" from the header above
// definition shared with PhysicsTools/MVAComputer/test/testMVAComputerEvaluate
// (the "Rcd" is implicitly appended by the macro)
//
#include "PhysicsTools/MVAComputer/interface/HelperMacros.h"
MVA_COMPUTER_CONTAINER_DEFINE(MVAJetRej);

using namespace edm;
using namespace std;
using namespace reco;

using namespace PhysicsTools;

#define MAX_OBSERV 17   // max number + 1

static const AtomicId ObsIds[MAX_OBSERV] = {
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

class JetRejMVATrainer : public edm::EDAnalyzer {
    public:
	explicit JetRejMVATrainer(const edm::ParameterSet &params);

	virtual void beginRun(const edm::Run &run, const edm::EventSetup &iSetup);

	virtual void analyze(const edm::Event& iEvent,
	                     const edm::EventSetup& iSetup);

    private:
        edm::InputTag obssrc_;

        vector<int> JetSelObs_;

	MVAComputerCache mvaComputer;


};

JetRejMVATrainer::JetRejMVATrainer(const edm::ParameterSet &params)
{
  obssrc_ = params.getParameter<edm::InputTag>( "obssrc" );  
  JetSelObs_ = params.getUntrackedParameter< vector<int> > ( "JetSelObs");
}

void JetRejMVATrainer::beginRun(const edm::Run &run, const edm::EventSetup &iSetup)
{
	// reset the random number generator here
	// we are expected to feed the same training events for
	// each loop iteration. We normally run from a ROOT file,
	// so we wouldn't need to care... (don't do this with real data!)

	//gRandom->SetSeed(12345);
}

void JetRejMVATrainer::analyze(const edm::Event& iEvent,
                                   const edm::EventSetup& iSetup)
{
  // Note that the code here is almost IDENTICAL
  // to the code when just evaluating the MVA
  // The only differences are:
  // * EventSetup::get is called with additional argument "trainer"
  // * the variables contain a value for kTargetId with the truth
  // * the result of MVAComputer::eval is to be ignored
  //
  // So: When possible try to share the filling routine!
  
  // update the cached MVAComputer from calibrations
  // passed via EventSetup.
  // you can use a MVAComputerContainer to pass around
  // multiple different MVA's in one event setup record
  // identify the right one by a definable name string

  mvaComputer.update<MVAJetRejRcd>("trainer", iSetup, "JetRejMVA");

  // can occur in last iteration, when MVATrainer has completed
  // and is about to save the result
  if (!mvaComputer)
    return;
  
  Handle<vector<JetRejObs> > observables;
  iEvent.getByLabel(obssrc_, observables); 

  
  bool target=false;
  Variable::Value values[MAX_OBSERV];

  //Loop over all jet observable entries
  for(unsigned int i_obs=0; i_obs < observables->size(); i_obs++){
    int m_os=0;
    
    JetRejObs obsValue=(*observables)[i_obs];

    //Loop over all observables of a jet
    for(unsigned int i_val=0; i_val<obsValue.getSize(); i_val++){

      //Observable '0' is for matched/unmatched jet
      if(obsValue.getPair(i_val).first == 0 ){
	target = obsValue.getPair(i_val).second == 1;
	values[m_os++]=Variable::Value(MVATrainer::kTargetId, target);
      }
      
      for(unsigned int i_os=0; i_os<JetSelObs_.size(); i_os++){
      	if(obsValue.getPair(i_val).first == JetSelObs_[i_os]){
	  values[m_os++]=Variable::Value(ObsIds[JetSelObs_[i_os]],
					 obsValue.getPair(i_val).second);
	}
      }
    }
    
    mvaComputer->eval(values, values + m_os);
	// arguments are begin() and end() (for plain C++ arrays done this way)
	// std::vector also works, but plain array has better performance
	// for fixed-size arrays (no internal malloc/free)

	// mvaComputer->eval() can be called as many times per event as needed
  }
}

// define this as a plug-in
DEFINE_ANOTHER_FWK_MODULE(JetRejMVATrainer);

// Here come the definition(s) for the CMSSW interaction:

// define the plugins for the trainer
MVA_TRAINER_IMPLEMENT(MVAJetRej);
// this will implictly define a bunch of EDM plugins:
// * module "MVADemoJRContainerSaveCondDB"
// * module "MVADemoJRSaveFile"
// * looper "MVADemoJRTrainerLooper"
//
// - the looper is mandatory, it will read the .xml steering file and
//   provide the training mechanism via EventSetup
//
// - for saving the result, either a standalone .mva file can be written
//   via MVADemoJRSaveFile, see JetRejMVATrainer.cfg
//
// - or to the conditions database via the other module
//   (in conjuction with PoolDBOutputService)


/**********************************************************************
 *
 * ATTENTION: instead off calling this here, please link against
 *            the library defining the record in the first place instead!
 *
 *            (We can't do it here, since we would need to link against
 *             a file from the MVAComputer/test directory, which is
 *             not possible in example code)
 *
 */	EVENTSETUP_RECORD_REG(MVAJetRejRcd);
