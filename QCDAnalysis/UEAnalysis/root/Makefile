objects = UEAnalysis.o UEAnalysisOnRootple.o 
source1 = UEAnalysis.cpp
source2 = UEAnalysisOnRootple.C

CXX           = g++
CXXFLAGS      = -O -Wall -fPIC
LD            = g++
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTGLIBS    := $(shell $(ROOTSYS)/bin/root-config --glibs)
CXXFLAGS     += $(ROOTCFLAGS)
LIBS          = $(ROOTGLIBS) -L/afs/cern.ch/cms/sw/slc4_ia32_gcc345/external/zlib/1.2.3-cms/lib -lEG
SHARE         = -shared
#NAMELIB       = $(CMSSW_BASE)/src/QCDAnalysis/UEAnalysis/root/UE.o
NAMELIB       = $(CMSSW_BASE)/src/QCDAnalysis/UEAnalysis/root/UE.o
BINFILE       = UEAnalysis
lib:	$(source1) $(source2)
	$(LD) -g $(ROOTCFLAGS) -c $(source1)
	$(LD) -g $(ROOTCFLAGS) -c $(source2)
	$(LD) -g $(objects) $(LIBS) $(SHARE) -o $(NAMELIB)
 
bin:	lib
	$(LD) -g $(LIBS) $(NAMELIB) -o $(BINFILE)
 
 
clean:
	rm $(objects) $(BINFILE) $(NAMELIB) G__a*
