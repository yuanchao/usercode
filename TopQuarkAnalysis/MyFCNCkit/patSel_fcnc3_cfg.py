#

import sys

import FWCore.ParameterSet.Config as cms

process = cms.Process( 'PAT' )


### Data or MC?
runOnMC = True

### Standard and PF work flow

# PF2PAT
runPF2PAT = True

### Switch on/off selection steps

# Step 0a
useTrigger      = True
# Step 0b
useGoodVertex   = True
# Step 1a
useLooseMuon    = True
# Step 1b
useTightMuon    = True
# Step 1c    for Top FCNC
useLooseElectron = True
# Step 1d
useTightElectron = True
# Step 2
useMuonVeto     = False # True
# Step 3
useElectronVeto = False # True
# Step 4a
use1Jet         = False
# Step 4b
use2Jets        = False   # for FCNC Top
# Step 4c
use3Jets        = False
# Step 5
use4Jets        = False
# Step 6
useBTag         = True   # for cross-check

addTriggerMatching = False

### Reference selection


from TopQuarkAnalysis.Configuration.patRefSel_PF2PAT import *

triggerSelection_163270   = 'HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v* OR HLT_Ele17_CaloIdT_TrkIdVL_CaloIsoVL_TrkIsoVL_Ele8_CaloIdT_TrkIdVL_CaloIsoVL_TrkIsoVL_v* OR HLT_DoubleMu7_* OR HLT_Mu13_Mu8_v* OR HLT_Mu17_Mu8_v*' # un-prescaled only
triggerSelection_Summer11 = 'HLT_Ele17_CaloIdT_TrkIdVL_CaloIsoVL_TrkIsoVL_Ele8_CaloIdT_TrkIdVL_CaloIsoVL_TrkIsoVL_v* OR HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v* OR HLT_DoubleMu3_v* OR HLT_DoubleMu6_v* OR HLT_DoubleMu7_v*'
triggerSelectionData = triggerSelection_163270
triggerSelectionMC   = triggerSelection_Summer11

### Muon selection

# PF2PAT top projection settings
pfMuonIsoConeR = 0.3 # for mu+jets, default: 0.4

# Minimal selection for all muons, also basis for signal and veto muons
muonCutBase  =     'pt > 10.'                                                    # transverse momentum
muonCutBase += ' && abs(eta) < 2.4'
# pseudo-rapisity range
# veto muon
muonCutVeto  = muonCutBase
muonCutVeto += ' && isGlobalMuon'                                                # general reconstruction property
# standard muon
muonCut  = muonCutVeto
muonCut += ' && (trackIso+caloIso)/pt < 0.2'                                     # relative isolation
# PF muon
muonCutPF  =  muonCutVeto
muonCutPF += ' && (chargedHadronIso+neutralHadronIso+photonIso)/pt < 0.2'        # relative isolation

# Signal muon selection on top of 'muonCut'
looseMuonCutBase  =     'isGlobalMuon'
# general reconstruction property
looseMuonCutBase += ' && pt > 20.'                                               # transverse momentum
looseMuonCutBase += ' && abs(eta) < 2.4'                                         # pseudo-rapisity range
looseMuonCutBase += ' && globalTrack.normalizedChi2 < 10.'                       # muon ID: 'isGlobalMuonPromptTight'
looseMuonCutBase += ' && globalTrack.hitPattern.numberOfValidMuonHits > 0'       # muon ID: 'isGlobalMuonPromptTight'
looseMuonCutBase += ' && abs(dB) < 0.02'                                         # 2-dim impact parameter with respect to beam spot (s. "PAT muon configuration" above)
looseMuonCutBase += ' && innerTrack.numberOfValidHits > 10'                      # tracker reconstruction
looseMuonCutBase += ' && innerTrack.hitPattern.pixelLayersWithMeasurement >= 1'  # tracker reconstruction
looseMuonCutBase += ' && numberOfMatches > 1'                                    # muon chamber reconstruction
#looseMuonCut += ' && ...'                                                        # DeltaZ between muon vertex and PV < 1. not accessible via configuration yet
# standard muon
looseMuonCut  = looseMuonCutBase
looseMuonCut += ' && (trackIso+caloIso)/pt < 0.1'                                # relative isolation
# PF muon
looseMuonCutPF = looseMuonCutBase
looseMuonCutPF += ' && (chargedHadronIso+neutralHadronIso+photonIso)/pt < 0.125' # relative isolation
# Signal muon distance from signal jet
muonJetsDR = 0.3                                                                 # minimal DeltaR of signal muons from any signal jet

# Tightened signal muon selection on top of 'looseMuonCut'
tightMuonCutBase  = looseMuonCutBase
# standard muon
tightMuonCut  = tightMuonCutBase
tightMuonCut += ' && (trackIso+caloIso)/pt < 0.05'                                   # relative isolation
# PF muon
tightMuonCutPF  = tightMuonCutBase
tightMuonCutPF += ' && (chargedHadronIso+neutralHadronIso+photonIso)/pt < 0.1'     # relative isolation

### Electron selection
process.load( "RecoEgamma.ElectronIdentification.cutsInCategoriesElectronIdentificationV06_cfi" )

# Minimal selection for all electrons, also basis for signal and veto muons
electronCutBase  =     'et > 20.'                                                  # transverse energy
electronCutBase += ' && abs(eta) < 2.5'                                            # pseudo-rapisity range
# veto electron
electronCutVeto = electronCutBase
# standard electron
electronCut  = electronCutVeto
electronCut += ' && (dr03TkSumPt+dr03EcalRecHitSumEt+dr03HcalTowerSumEt)/et < 0.2' # relative isolation
# PF electron
electronCutPF  = electronCutVeto
electronCutPF += ' && (chargedHadronIso+neutralHadronIso+photonIso)/et < 0.2'      # relative isolation
# Signal muon selection on top of 'muonCut'
looseElectronCutBase  = electronCutBase
# general reconstruction property
looseElectronCutBase += ' && et > 20.'                                             # transverse momentum
looseElectronCutBase += ' && abs(eta) < 2.5'                                       # pseudo-rapisity range
#looseElectronCutBase += ' && globalTrack.hitPattern.numberOfValidElectronHits > 0' # electron ID: 'isGlobalElectronPromptTight'
looseElectronCutBase += ' && abs(dB) < 0.02'                                       # 2-dim impact parameter with respect to beam spot (s. "PAT electron configuration" above)
looseElectronCutBase += '  && gsfTrack.trackerExpectedHitsInner.numberOfLostHits < 2'                                   # electron conversion veto
#looseElectronCut += ' && ...'                                                      # DeltaZ between electron vertex and PV < 1. not accessible via configuration yet
# standard electron
looseElectronCut  = looseElectronCutBase
looseElectronCut += ' && (trackIso+caloIso)/pt < 0.1'                                # relative isolation
# PF electron
looseElectronCutPF = looseElectronCutBase
looseElectronCutPF += ' && (chargedHadronIso+neutralHadronIso+photonIso)/pt < 0.125' # relative isolation
# Signal electron distance from signal jet
electronJetsDR = 0.3                                                                 # minimal DeltaR of signal electrons from any signal jet

# Tightened signal electron selection on top of 'looseElectronCut'
tightElectronCutBase  =  looseElectronCut
# standard electron
tightElectronCut  = tightElectronCutBase
tightElectronCut += '&& (trackIso+caloIso)/pt < 0.15'                                   # relative isolation
# PF electron
tightElectronCutPF  = tightElectronCutBase
tightElectronCutPF += '&& (chargedHadronIso+neutralHadronIso+photonIso)/pt < 0.1'     # relative isolation

### Jet selection

# Signal jet selection
jetCutBase  =     'pt > 30.'                                             # transverse momentum
jetCutBase += ' && abs(eta) < 2.5'                                       # pseudo-rapisity range
# standard jet
jetCut  = jetCutBase
jetCut += ' && emEnergyFraction > 0.01'                                  # jet ID: electro-magnetic energy fraction
jetCut += ' && jetID.n90Hits > 1'                                        # jet ID: number of RecHits carying 90% of the total energy
jetCut += ' && jetID.fHPD < 0.98'                                        # jet ID: fraction of energy in the hottest readout
# PF jet
jetCutPF  = jetCutBase
jetCutPF += ' && numberOfDaughters > 1'                                  # PF jet ID:
jetCutPF += ' && chargedEmEnergyFraction < 0.99'                         # PF jet ID:
jetCutPF += ' && neutralHadronEnergyFraction < 0.99'                     # PF jet ID:
jetCutPF += ' && neutralEmEnergyFraction < 0.99'                         # PF jet ID:
jetCutPF += ' && (chargedHadronEnergyFraction > 0. || abs(eta) >= 2.4)'  # PF jet ID:
jetCutPF += ' && (chargedMultiplicity > 0 || abs(eta) >= 2.4)'           # PF jet ID:
# Signal jet distance from signal muon
jetMuonsDRPF = 0.1


### ------------------------------------------------------------------------ ###


### Trigger matching

# Trigger object selection
#           run < 147196 (Run2010A)
triggerObjectSelection_000000   = 'type("TriggerMuon") && ( path("HLT_Mu9") )'
# 147196 <= run < 149442 (Run2010B)
triggerObjectSelection_147196   = 'type("TriggerMuon") && ( path("HLT_Mu15_v*") )'
# 160404 <= run < 163269 (Run2011A)
triggerObjectSelection_160404   = 'type("TriggerMuon") && ( path("HLT_Mu15_v*") || path("HLT_IsoMu17_v*") || ( filter("hltL1Mu7CenJetL3MuFiltered17") && ( path("HLT_Mu17_CentralJet30_v*", 0) || path("HLT_Mu17_DiCentralJet30_v*", 0) || path("HLT_Mu17_TriCentralJet30_v*", 0) || path("HLT_Mu17_CentralJet30_BTagIP_v*", 0) ) ) || ( filter("hltIsoMu17CenJet30L3IsoFiltered17") && path("HLT_IsoMu17_CentralJet30_BTagIP_v*", 0) ) )'
# 163270 <= run < ...    (Run2011A)
triggerObjectSelection_163270   = 'type("TriggerMuon") && ( path("HLT_IsoMu17_v*") || ( filter("hltL1Mu7CenJetL3MuFiltered17") && ( path("HLT_Mu17_TriCentralJet30_v*", 0) || path("HLT_Mu17_CentralJet30_BTagIP_v*", 0) ) ) || ( filter("hltIsoMu17CenJet30L3IsoFiltered17") && path("HLT_IsoMu17_CentralJet30_BTagIP_v*", 0) ) )'
triggerObjectSelection_Summer11 = 'type("TriggerMuon") && ( path("HLT_Mu20_v*") || path("HLT_Mu24_v*") || path("HLT_IsoMu17_v*") )'
triggerObjectSelectionData = triggerObjectSelection_163270
triggerObjectSelectionMC   = triggerObjectSelection_Summer11

# ../python/patRefSel_refMuJets.py
# Trigger selection according to run range resp. MC sample:
# lower range limits for data available as suffix;
# available are: 000000, 147196, 160404, 163270 (default)
# sample name for MC available as suffix;
# available are: Summer11 (default)
#triggerSelectionData       = triggerSelection_163270
#triggerObjectSelectionData = triggerObjectSelection_163270
#triggerSelectionMC       = triggerSelection_Summer11
#triggerObjectSelectionMC = triggerObjectSelection_Summer11

### Particle flow
### takes effect only, if 'runPF2PAT' = True

pfSuffix = 'PF'
postfix = 'PF' # needs to be a non-empty string, if 'runStandardPAT' = True

# subtract charged hadronic pile-up particles (from wrong PVs)
# effects also JECs
usePFnoPU = True # before any top projection

# other switches for PF top projections (default: all 'True')
useNoMuon     = True # before electron top projection
useNoElectron = True # before jet top projection
useNoJet      = True # before tau top projection
useNoTau      = True # before MET top projection

# cuts used in top projections
# vertices
#pfVertices  = 'goodOfflinePrimaryVertices'
#pfD0Cut     = 0.2
#pfDzCut     = 0.5
# muons
#pfMuonSelectionCut = 'pt > 5.'
useMuonCutBasePF = False # use minimal (veto) muon selection cut on top of 'pfMuonSelectionCut'
#pfMuonIsoConeR   = 0.4
#pfMuonCombIsoCut = 0.2
# electrons
#pfElectronSelectionCut  = 'pt > 5. && gsfTrackRef.isNonnull && gsfTrackRef.trackerExpectedHitsInner.numberOfLostHits < 2'
useElectronCutBasePF = False # use minimal (veto) electron selection cut on top of 'pfElectronSelectionCut'
#pfElectronIsoConeR   = 0.3
#pfElectronCombIsoCut = 0.2

### JEC levels

# levels to be accessible from the jets
# jets are corrected to L3Absolute (MC), L2L3Residual (data) automatically, if enabled here
# and remain uncorrected, if none of these levels is enabled here
useL1FastJet    = True  # needs useL1Offset being off, error otherwise
useL1Offset     = False # needs useL1FastJet being off, error otherwise
useL2Relative   = True
useL3Absolute   = True
useL2L3Residual = True  # takes effect only on data
useL5Flavor     = True
useL7Parton     = True

### Input

# list of input files
useRelVals = False # if 'False', "inputFiles" is used
inputFiles = [ #'/store/mc/Summer11/DYToEE_M-20_CT10_TuneZ2_7TeV-powheg-pythia/GEN-SIM-RECO/PU_S4_START42_V11-v1/0000/FE9B7D60-2FA8-E011-9E49-001D0967D5A3.root'
#               '/store/mc/Summer11/DYToMuMu_M-20_FSRFilter_Pt-50_TuneZ2_7TeV-pythia6/GEN-SIM-RECO/X0Max_PU_S4_START42_V11-v1/0000/FCDBBBB9-90B2-E011-8A88-001F29C424E4.root'
               'store/mc/Summer11/DYJetsToLL_TuneZ2_M-50_7TeV-madgraph-tauola/AODSIM/PU _S4_START42_V11-v1/0000/32A359C8-B19C-E011-AF69-90E6BA19A213.root'
#               '/store/data/Run2011A/MuHad/AOD/PromptReco-v4/000/165/129/42DDEE9E-7B81-E011-AF29-003048F024DC.root'
#             , '/store/data/Run2011A/MuHad/AOD/PromptReco-v4/000/165/103/8AF0C4CD-EE80-E011-96B1-003048F1BF68.root'
#             , '/store/data/Run2011A/MuHad/AOD/PromptReco-v4/000/165/102/1298E7B3-CF80-E011-86E9-001617E30F4C.root'
#             , '/store/data/Run2011A/MuHad/AOD/PromptReco-v4/000/165/099/16D66DF0-D07F-E011-A922-003048F118C4.root'
#             , '/store/data/Run2011A/MuHad/AOD/PromptReco-v4/000/165/098/66526A73-DA7F-E011-84B4-003048F1BF68.root'
#             , '/store/data/Run2011A/MuHad/AOD/PromptReco-v4/000/165/093/2E545F72-C27F-E011-8CC1-003048D2C1C4.root'
#             , '/store/data/Run2011A/MuHad/AOD/PromptReco-v4/000/165/088/DED0B748-E47F-E011-9C6E-0030487C6A66.root'
#             , '/store/data/Run2011A/MuHad/AOD/PromptReco-v4/000/165/071/283C53A0-C37F-E011-A06F-0030487CD6D8.root'
             ] # overwritten, if "useRelVals" is 'True'

# maximum number of events
maxInputEvents = -1 # reduce for testing

### Conditions

# GlobalTags (w/o suffix '::All')
globalTagData = 'GR_R_42_V19' # default for CMSSW_4_2_8 RelVals: 'GR_R_42_V14'
globalTagMC   = 'START42_V13' # default for CMSSW_4_2_8 RelVals: 'START42_V12'

### Output

# output file
outputFile = 'patRefSel_FCNC.root'

# event frequency of Fwk report
fwkReportEvery = 1000

# switch for 'TrigReport'/'TimeReport' at job end
wantSummary = True


###                              End of constants                            ###
###                                                                          ###
### ======================================================================== ###


###
### Basic configuration
###

# geometry and magnetic field
process.load( "TopQuarkAnalysis.Configuration.patRefSel_basics_cff" )
process.MessageLogger.cerr.FwkReport.reportEvery = fwkReportEvery
process.options.wantSummary = wantSummary
if runOnMC:
  process.GlobalTag.globaltag = globalTagMC   + '::All'
else:
  process.GlobalTag.globaltag = globalTagData + '::All'


###
### Input configuration
###

# no event sort, no duplicate check
process.load( "TopQuarkAnalysis.Configuration.patRefSel_inputModule_cfi" )
if useRelVals:
  from PhysicsTools.PatAlgos.tools.cmsswVersionTools import pickRelValInputFiles
  if runOnMC:
    inputFiles = pickRelValInputFiles( cmsswVersion  = 'CMSSW_4_2_8'
                                     , relVal        = 'RelValTTbar'
                                     , globalTag     = 'START42_V12'
                                     , numberOfFiles = -1
                                     )
  else:
    inputFiles = pickRelValInputFiles( cmsswVersion  = 'CMSSW_4_2_8'
                                     , relVal        = 'Mu'
                                     , dataTier      = 'RECO'
                                     , globalTag     = 'GR_R_42_V14_mu2010B'
                                     , numberOfFiles = -1
                                     )
process.source.fileNames = inputFiles
process.maxEvents.input  = maxInputEvents


###
### Output configuration
###

process.load( "TopQuarkAnalysis.Configuration.patRefSel_outputModule_cff" )
## # output file name
process.out.fileName = outputFile
## # event content
from PhysicsTools.PatAlgos.patEventContent_cff import patEventContent
process.out.outputCommands += patEventContent
## # clear event selection
process.out.SelectEvents.SelectEvents = []

process.TFileService = cms.Service("TFileService",
      fileName = cms.string('output.root')
      )


###
### Cleaning and trigger selection configuration
###

# ../python/patRefSel_refMuJets.py
### Trigger selection
if runOnMC:
  triggerSelection = triggerSelectionMC
else:
  triggerSelection = triggerSelectionData
from TopQuarkAnalysis.Configuration.patRefSel_triggerSelection_cff import triggerResults
process.step0a = triggerResults.clone(
  triggerConditions = [ triggerSelection ]
)

### Good vertex selection
process.load( "TopQuarkAnalysis.Configuration.patRefSel_goodVertex_cfi" )
process.step0b = process.goodOfflinePrimaryVertices.clone( filter = True )

### Event cleaning
process.load( 'TopQuarkAnalysis.Configuration.patRefSel_eventCleaning_cff' )
process.step0c = cms.Sequence(
  process.HBHENoiseFilter
+ process.scrapingFilter
)


###
### PAT/PF2PAT configuration
###

process.load( "PhysicsTools.PatAlgos.patSequences_cff" )
from PhysicsTools.PatAlgos.tools.coreTools import *

### Muon configuration

# PAT muons
muonsUsePV     = False # use beam spot rather than PV, which is necessary for 'dB' cut
muonEmbedTrack = True  # embedded track needed for muon ID cuts

### Check JECs

# JEC set
jetAlgo = 'AK5'

# JEC sets
jecSetBase = jetAlgo

jecSet      = jecSetBase + 'Calo'
jecSetAddPF = jecSetBase + pfSuffix
jecSetPF    = jecSetAddPF
if usePFnoPU:
  jecSetPF += 'chs'

# JEC levels
if useL1FastJet and useL1Offset:
  sys.exit( 'ERROR: switch off either "L1FastJet" or "L1Offset"' )
jecLevels = []
if useL1FastJet:
  jecLevels.append( 'L1FastJet' )
if useL1Offset:
  jecLevels.append( 'L1Offset' )
if useL2Relative:
  jecLevels.append( 'L2Relative' )
if useL3Absolute:
  jecLevels.append( 'L3Absolute' )
if useL2L3Residual and not runOnMC:
  jecLevels.append( 'L2L3Residual' )
if useL5Flavor:
  jecLevels.append( 'L5Flavor' )
if useL7Parton:
  jecLevels.append( 'L7Parton' )

### Switch configuration

if runPF2PAT:
  if useMuonCutBasePF:
    pfMuonSelectionCut += ' && %s'%( muonCutBase )
  if useElectronCutBasePF:
    pfElectronSelectionCut += ' && %s'%( electronCutBase )
  from PhysicsTools.PatAlgos.tools.pfTools import usePF2PAT
  usePF2PAT( process
           , runPF2PAT      = runPF2PAT
           , runOnMC        = runOnMC
           , jetAlgo        = jetAlgo
           , postfix        = postfix
           , jetCorrections = ( jecSetPF
                              , jecLevels
                              )
           )
  applyPostfix( process, 'pfNoPileUp'  , postfix ).enable = usePFnoPU
  applyPostfix( process, 'pfNoMuon'    , postfix ).enable = useNoMuon
  applyPostfix( process, 'pfNoElectron', postfix ).enable = useNoElectron
  applyPostfix( process, 'pfNoJet'     , postfix ).enable = useNoJet
  applyPostfix( process, 'pfNoTau'     , postfix ).enable = useNoTau
  applyPostfix( process, 'pfPileUp', postfix ).Vertices = cms.InputTag( pfVertices )
  if useL1FastJet:
    applyPostfix( process, 'pfPileUp', postfix ).checkClosestZVertex = False
    applyPostfix( process, 'pfJets', postfix ).doAreaFastjet = True
    applyPostfix( process, 'pfJets', postfix ).doRhoFastjet  = False
  applyPostfix( process, 'pfMuonsFromVertex'    , postfix ).vertices = cms.InputTag( pfVertices )
  applyPostfix( process, 'pfMuonsFromVertex'    , postfix ).d0Cut    = pfD0Cut
  applyPostfix( process, 'pfMuonsFromVertex'    , postfix ).dzCut    = pfDzCut
  applyPostfix( process, 'pfSelectedMuons'      , postfix ).cut = pfMuonSelectionCut
  applyPostfix( process, 'isoValMuonWithCharged', postfix ).deposits[0].deltaR = pfMuonIsoConeR
  applyPostfix( process, 'isoValMuonWithNeutral', postfix ).deposits[0].deltaR = pfMuonIsoConeR
  applyPostfix( process, 'isoValMuonWithPhotons', postfix ).deposits[0].deltaR = pfMuonIsoConeR
  applyPostfix( process, 'pfIsolatedMuons'      , postfix ).combinedIsolationCut = pfMuonCombIsoCut
  applyPostfix( process, 'pfElectronsFromVertex'    , postfix ).vertices = cms.InputTag( pfVertices )
  applyPostfix( process, 'pfElectronsFromVertex'    , postfix ).d0Cut    = pfD0Cut
  applyPostfix( process, 'pfElectronsFromVertex'    , postfix ).dzCut    = pfDzCut
  applyPostfix( process, 'pfSelectedElectrons'      , postfix ).cut = pfElectronSelectionCut
  applyPostfix( process, 'isoValElectronWithCharged', postfix ).deposits[0].deltaR = pfElectronIsoConeR
  applyPostfix( process, 'isoValElectronWithNeutral', postfix ).deposits[0].deltaR = pfElectronIsoConeR
  applyPostfix( process, 'isoValElectronWithPhotons', postfix ).deposits[0].deltaR = pfElectronIsoConeR
  applyPostfix( process, 'pfIsolatedElectrons'      , postfix ).combinedIsolationCut = pfElectronCombIsoCut
  applyPostfix( process, 'patElectrons', postfix ).pvSrc = cms.InputTag( pfVertices )
  applyPostfix( process, 'patMuons', postfix ).pvSrc = cms.InputTag( pfVertices )

#from TopQuarkAnalysis.Configuration.patRefSel_refLepJets_cfi import *

import FWCore.ParameterSet.Config as cms

from PhysicsTools.PatAlgos.patSequences_cff import *
from TopQuarkAnalysis.Configuration.patRefSel_common_cfi import *

intermediatePatMuons = cleanPatMuons.clone(
  preselection  = '' # looseMuonCut
)

loosePatMuons = cleanPatMuons.clone(
  src           = cms.InputTag( 'intermediatePatMuons' )
  , checkOverlaps = cms.PSet(
    jets = cms.PSet(
      src                 = cms.InputTag( 'goodPatJets' )
    , algorithm           = cms.string( 'byDeltaR' )
    , preselection        = cms.string( '' )
    , deltaR              = cms.double( 0.3 ) # muonJetsDR
    , checkRecoComponents = cms.bool( False )
    , pairCut             = cms.string( '' )
    , requireNoOverlaps   = cms.bool( True)
    )
  )
)

step1a = cms.EDFilter(
  "PATCandViewCountFilter"
, src = cms.InputTag( 'loosePatMuons' )
, minNumber = cms.uint32( 0 )
, maxNumber = cms.uint32( 99 )
)

tightPatMuons = cleanPatMuons.clone(
  src           = cms.InputTag( 'loosePatMuons' )
, preselection  = '' # tightMuonCut
, checkOverlaps = cms.PSet()
)

intermediatePatElectrons = cleanPatElectrons.clone(
  preselection  = '' # looseElectronCut
  , checkOverlaps = cms.PSet(
    muons = cms.PSet(
      src                 = cms.InputTag( 'selectedPatMuonsPF' )
    , algorithm           = cms.string( 'byDeltaR' )
    , preselection        = cms.string( '' )
    , deltaR              = cms.double( 0.3 ) # muonJetsDR
    , checkRecoComponents = cms.bool( False )
    , pairCut             = cms.string( '' )
    , requireNoOverlaps   = cms.bool( False)
    )
  )

)

loosePatElectrons = cleanPatElectrons.clone(
  src           = cms.InputTag( 'intermediatePatElectrons' )
  , checkOverlaps = cms.PSet(
    jets = cms.PSet(
      src                 = cms.InputTag( 'goodPatJets' )
    , algorithm           = cms.string( 'byDeltaR' )
    , preselection        = cms.string( '' )
    , deltaR              = cms.double( 0.3 ) # electronJetsDR
    , checkRecoComponents = cms.bool( False )
    , pairCut             = cms.string( '' )
    , requireNoOverlaps   = cms.bool( True)
    )
  )
)

tightPatElectrons = cleanPatElectrons.clone(
  src           = cms.InputTag( 'loosePatElectrons' )
, preselection  = '' # tightElectronCut
, checkOverlaps = cms.PSet()
)

goodPatJets = cleanPatJets.clone(
  preselection  = '' # jetCut
, checkOverlaps = cms.PSet(
    muons = cms.PSet(
      src                 = cms.InputTag( 'intermediatePatMuons' )
    , algorithm           = cms.string( 'byDeltaR' )
    , preselection        = cms.string( '' )
    , deltaR              = cms.double( 0. ) # jetMuonsDR
    , checkRecoComponents = cms.bool( False )
    , pairCut             = cms.string( '' )
    , requireNoOverlaps   = cms.bool( True)
    )
  )
)

step4a = cms.EDFilter(
  "PATCandViewCountFilter"
, src = cms.InputTag( 'goodPatJets' )
, minNumber = cms.uint32( 1 )
, maxNumber = cms.uint32( 999999 )
)
step4b = step4a.clone( minNumber = 2 )
step4c = step4a.clone( minNumber = 3 )
step5  = step4a.clone( minNumber = 4 )

# remove MC matching, object cleaning, objects etc.
jecLevelsCalo = copy.copy( jecLevels )

if runPF2PAT:
  if not runOnMC:
    runOnData( process
             , names = [ 'PFAll' ]
             , postfix = postfix
             )
  removeSpecificPATObjects( process
                          , names = [ 'Photons', 'Taus' ]
                          , postfix = postfix
                          ) # includes 'removeCleaning'

# JetCorrFactorsProducer configuration has to be fixed in standard work flow after a call to 'runOnData()':

# additional event content has to be (re-)added _after_ the call to 'removeCleaning()':
process.out.outputCommands += [ 'keep edmTriggerResults_*_*_*'
                              , 'keep *_hltTriggerSummaryAOD_*_*'
                              # vertices and beam spot
                              , 'keep *_offlineBeamSpot_*_*'
                              , 'keep *_offlinePrimaryVertices*_*_*'
                              , 'keep *_goodOfflinePrimaryVertices*_*_*'
                              ]
if runOnMC:
  process.out.outputCommands += [ 'keep GenEventInfoProduct_*_*_*'
                                , 'keep recoGenParticles_*_*_*'
                                , 'keep *_addPileupInfo_*_*'
                                ]


###
### Additional configuration
###

goodPatJetsAddPFLabel = 'goodPatJets' + jetAlgo + pfSuffix


if runPF2PAT:

  ### Muons

  intermediatePatMuonsPF = intermediatePatMuons.clone( src = cms.InputTag( 'selectedPatMuons' + postfix ) )
  setattr( process, 'intermediatePatMuons' + postfix, intermediatePatMuonsPF )

  loosePatMuonsPF = loosePatMuons.clone( src = cms.InputTag( 'intermediatePatMuons' + postfix ) )
  setattr( process, 'loosePatMuons' + postfix, loosePatMuonsPF )
  getattr( process, 'loosePatMuons' + postfix ).checkOverlaps.jets.src = cms.InputTag( 'goodPatJets' + postfix )

  step1aPF = step1a.clone( src = cms.InputTag( 'loosePatMuons' + postfix ) )
  setattr( process, 'step1a' + postfix, step1aPF )

  tightPatMuonsPF = tightPatMuons.clone( src = cms.InputTag( 'loosePatMuons' + postfix ) )
  setattr( process, 'tightPatMuons' + postfix, tightPatMuonsPF )

  ### Jets

  applyPostfix( process, 'patJetCorrFactors', postfix ).primaryVertices = cms.InputTag( pfVertices )
  if usePFnoPU:
    kt6PFJetsPFChs = kt6PFJetsChs.clone( src = cms.InputTag( 'pfNoElectron' + postfix ) )
    setattr( process, 'kt6PFJetsChs' + postfix, kt6PFJetsPFChs )
    getattr( process, 'patPF2PATSequence' + postfix).replace( getattr( process, 'patJetCorrFactors' + postfix )
                                                            , getattr( process, 'kt6PFJetsChs' + postfix ) * getattr( process, 'patJetCorrFactors' + postfix )
                                                            )
    if useL1FastJet:
      applyPostfix( process, 'patJetCorrFactors', postfix ).rho = cms.InputTag( 'kt6PFJetsChs' + postfix, 'rho' )
  else:
    kt6PFJetsPF = kt6PFJets.clone( doRhoFastjet = True )
    setattr( process, 'kt6PFJets' + postfix, kt6PFJetsPF )
    getattr( process, 'patPF2PATSequence' + postfix).replace( getattr( process, 'patJetCorrFactors' + postfix )
                                                            , getattr( process, 'kt6PFJets' + postfix ) * getattr( process, 'patJetCorrFactors' + postfix )
                                                            )
    if useL1FastJet:
      applyPostfix( process, 'patJetCorrFactors', postfix ).rho = cms.InputTag( 'kt6PFJets' + postfix, 'rho' )
##  process.out.outputCommands.append( 'keep double_kt6PFJets' + postfix + '_*_' + process.name_() )

  goodPatJetsPF = goodPatJets.clone( src = cms.InputTag( 'selectedPatJets' + postfix ) )
  setattr( process, 'goodPatJets' + postfix, goodPatJetsPF )
  getattr( process, 'goodPatJets' + postfix ).checkOverlaps.muons.src = cms.InputTag( 'intermediatePatMuons' + postfix )

  step4aPF = step4a.clone( src = cms.InputTag( 'goodPatJets' + postfix ) )
  setattr( process, 'step4a' + postfix, step4aPF )
  step4bPF = step4b.clone( src = cms.InputTag( 'goodPatJets' + postfix ) )
  setattr( process, 'step4b' + postfix, step4bPF )
  step4cPF = step4c.clone( src = cms.InputTag( 'goodPatJets' + postfix ) )
  setattr( process, 'step4c' + postfix, step4cPF )
  step5PF = step5.clone( src = cms.InputTag( 'goodPatJets' + postfix ) )
  setattr( process, 'step5'  + postfix, step5PF  )

  ### Electrons

#  intermediatePatElectronsPF = intermediatePatElectrons.clone( src = cms.InputTag( 'selectedPatElectrons' + postfix ) )
  intermediatePatElectronsPF = intermediatePatElectrons.clone( src = cms.InputTag( 'selectedPatElectrons' + postfix ) )
  setattr( process, 'intermediatePatElectrons' + postfix, intermediatePatElectronsPF )

  loosePatElectronsPF = loosePatElectrons.clone( src = cms.InputTag( 'intermediatePatElectrons' + postfix ) )
  setattr( process, 'loosePatElectrons' + postfix, loosePatElectronsPF )
  getattr( process, 'loosePatElectrons' + postfix ).checkOverlaps.jets.src = cms.InputTag( 'goodPatJets' + postfix )

  tightPatElectronsPF = tightPatElectrons.clone( src = cms.InputTag( 'loosePatElectrons' + postfix ) )
  setattr( process, 'tightPatElectrons' + postfix, tightPatElectronsPF )


## process.looseCiCPatElectronsPF = cms.EDFilter("EleIdCutBased",
##                                               src = cms.InputTag("gsfElectrons"),
##                                               algorithm = cms.string("eIDCB"),
##                                               threshold = cms.double(14.5),
##                                               electronIDType = process.eidLooseMC.electronIDType,
##                                               electronQuality = process.eidLooseMC.electronQuality,
##                                               electronVersion = process.eidLooseMC.electronVersion,
##                                               additionalCategories = process.eidLooseMC.additionalCategories,
##                                               classbasedlooseEleIDCutsV06 = process.eidLooseMC.classbasedlooseEleIDCutsV06,
##                                               etBinning = cms.bool(False),
##                                               version = cms.string(""),
##                                               verticesCollection = cms.InputTag('offlinePrimaryVerticesWithBS'),
##                                               reducedBarrelRecHitCollection = cms.InputTag("reducedEcalRecHitsEB"),
##                                               reducedEndcapRecHitCollection = cms.InputTag("recucedEcalRecHitsEE"),
##                                               )



process.out.outputCommands.append( 'keep *_intermediatePatMuons*_*_*' )
process.out.outputCommands.append( 'keep *_loosePatMuons*_*_*' )
process.out.outputCommands.append( 'keep *_tightPatMuons*_*_*' )
process.out.outputCommands.append( 'keep *_intermediatePatElectrons*_*_*' )
process.out.outputCommands.append( 'keep *_loosePatElectrons*_*_*' )
process.out.outputCommands.append( 'keep *_tightPatElectrons*_*_*' )
process.out.outputCommands.append( 'keep *_goodPatJets*_*_*' )
process.out.outputCommands.append( 'keep *_eid*_*_*' )
#process.out.outputCommands.outputCommands = cms.untracked.vstring('drop *')


###
### Selection configuration
###

if runPF2PAT:

  applyPostfix( process, 'patMuons', postfix ).usePV      = muonsUsePV
  applyPostfix( process, 'patMuons', postfix ).embedTrack = muonEmbedTrack

  applyPostfix( process, 'selectedPatMuons', postfix ).cut = muonCutPF

  getattr( process, 'intermediatePatMuons' + postfix ).preselection = looseMuonCutBase

  getattr( process, 'loosePatMuons' + postfix ).preselection              = looseMuonCutPF
  getattr( process, 'loosePatMuons' + postfix ).checkOverlaps.jets.deltaR = muonJetsDR

  getattr( process, 'tightPatMuons' + postfix ).preselection = tightMuonCutPF

  ### Jets

  getattr( process, 'goodPatJets' + postfix ).preselection               = jetCutPF
  getattr( process, 'goodPatJets' + postfix ).checkOverlaps.muons.deltaR = jetMuonsDRPF

  ### Electrons

  applyPostfix( process, 'patElectrons', postfix ).electronIDSources = electronIDSources

  applyPostfix( process, 'selectedPatElectrons', postfix ).cut = electronCutPF

  getattr( process, 'intermediatePatElectrons' + postfix ).preselection = looseElectronCutBase

  getattr( process, 'loosePatElectrons' + postfix ).preselection              = looseElectronCutPF
  getattr( process, 'loosePatElectrons' + postfix ).checkOverlaps.jets.deltaR = electronJetsDR

  getattr( process, 'tightPatElectrons' + postfix ).preselection = tightElectronCutPF

###
### Trigger matching
###

if addTriggerMatching:

  if runOnMC:
    triggerObjectSelection = triggerObjectSelectionMC
  else:
    triggerObjectSelection = triggerObjectSelectionData
  ### Trigger matching configuration
  from PhysicsTools.PatAlgos.triggerLayer1.triggerProducer_cfi import patTrigger
  from TopQuarkAnalysis.Configuration.patRefSel_triggerMatching_cfi import patMuonTriggerMatch
  from PhysicsTools.PatAlgos.tools.trigTools import *
  if runPF2PAT:
    triggerProducerPF = patTrigger.clone()
    setattr( process, 'patTrigger' + postfix, triggerProducerPF )
    triggerMatchPF = patMuonTriggerMatch.clone( matchedCuts = triggerObjectSelection )
    setattr( process, 'triggerMatch' + postfix, triggerMatchPF )
    switchOnTriggerMatchEmbedding( process
                                 , triggerProducer = 'patTrigger' + postfix
                                 , triggerMatchers = [ 'triggerMatch' + postfix ]
                                 , sequence        = 'patPF2PATSequence' + postfix
                                 , postfix         = postfix
                                 )
    removeCleaningFromTriggerMatching( process
                                     , sequence = 'patPF2PATSequence' + postfix
                                     )
    getattr( process, 'intermediatePatMuons' + postfix ).src = cms.InputTag( 'selectedPatMuons' + postfix + 'TriggerMatch' )


###
### Scheduling
###

# CiC electron ID

#process.load( "RecoEgamma.ElectronIdentification.cutsInCategoriesElectronIdentificationV06_cfi" )
process.load( "RecoEgamma.ElectronIdentification.cutsInCategoriesFixedIsolationElectronIdentificationV06_cfi")

process.eidCiCSequence = cms.Sequence(
#  process.eidVeryLoose
#+ process.eidLoose
#+ process.eidMedium
#+ process.eidTight
#+ process.eidSuperTight
#+ process.eidHyperTight1
#+ process.eidHyperTight2
#+ process.eidHyperTight3
#+ process.eidHyperTight4
  process.eidVeryLooseMC
+ process.eidLooseMC
+ process.eidMediumMC
+ process.eidTightMC
+ process.eidSuperTightMC
+ process.eidHyperTight1MC
+ process.eidHyperTight2MC
+ process.eidHyperTight3MC
+ process.eidHyperTight4MC
)

process.fcncKit = cms.EDAnalyzer('MyFCNCkit',
      MCtag = cms.untracked.bool(False),
      muonlabel = cms.InputTag("intermediatePatMuonsPF"),
      eleclabel = cms.InputTag("intermediatePatElectronsPF"),
      pfjetlabel= cms.InputTag("selectedPatJetsPF"),
      metlabel  = cms.InputTag("patMETsPF"),
      genlabel  = cms.InputTag("genParticles"),
      hltlabel  = cms.InputTag("TriggerResults::HLT"),
      pathltlabel = cms.InputTag("patTriggerEvent"),
      offlinePVlabel = cms.InputTag("offlinePrimaryVertices"),
      offlinePVBSlabel = cms.InputTag("offlinePrimaryVerticesWithBS"),
      offlineBSlabel = cms.InputTag("offlineBeamSpot"),
      pixelvtxlabel = cms.InputTag("pixelVertices"),
      genevtlabel = cms.InputTag("generator"),
      gtdigilabel = cms.InputTag("gtDigis"),
#      rhocorrectionlabel = cms.InputTag("kt6PFJetsPFlow","rho"),
#      sigmaLabel = cms.InputTag("kt6PFJetsPFlow","sigma"),
      puInfoLabel = cms.InputTag("addPileupInfo")
)



# The additional sequence

if runPF2PAT:
  patAddOnSequence = cms.Sequence(
    getattr( process, 'intermediatePatMuons' + postfix )
  * getattr( process, 'goodPatJets' + postfix )
##   * getattr( process, 'loosePatMuons' + postfix )
##   * getattr( process, 'tightPatMuons' + postfix )
  * getattr( process, 'intermediatePatElectrons' + postfix )
##   * getattr( process, 'loosePatElectrons' + postfix )
##   * getattr( process, 'tightPatElectrons' + postfix )
##   * getattr( process, 'looseCiCPatElectrons' + postfix )
  )
  setattr( process, 'patAddOnSequence' + postfix, patAddOnSequence )

# The paths

process.out.outputCommands.outputCommands = cms.untracked.vstring('drop *')

if runPF2PAT:

  pPF = cms.Path()
  if useTrigger:
    pPF += process.step0a
  pPF += process.goodOfflinePrimaryVertices
  if useGoodVertex:
    pPF += process.step0b
  if not runOnMC:
    pPF += process.step0c
  pPF += process.eidCiCSequence
  pPF += getattr( process, 'patPF2PATSequence' + postfix )
  pPF += getattr( process, 'patAddOnSequence' + postfix )
##   if useLooseMuon:
##     pPF += getattr( process, 'step1a' + postfix )
##   if useTightMuon:
##     pPF += getattr( process, 'step1b' + postfix )
##   if useLooseElectron:
##     pPF += getattr( process, 'step1c' + postfix )
##   if useTightElectron:
##     pPF += getattr( process, 'step1d' + postfix )
##   if useMuonVeto:
##     pPF += getattr( process, 'step2' + postfix )
##   if useElectronVeto:
##     pPF += getattr( process, 'step3' + postfix )
  if use1Jet:
    pPF += getattr( process, 'step4a' + postfix )
#  if use2Jets:
#    pPF += getattr( process, 'step4b' + postfix )
#  if use3Jets:
#    pPF += getattr( process, 'step4c' + postfix )
#  if use4Jets:
#    pPF += getattr( process, 'step5' + postfix )
    
#  pPF += process.fcncKit
  setattr( process, 'p' + postfix, pPF )
  process.out.SelectEvents.SelectEvents.append( 'p' + postfix )
