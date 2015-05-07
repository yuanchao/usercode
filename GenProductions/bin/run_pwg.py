#!/usr/bin/python

'''
Script for POWHEG generator production
By Yuan CHAO  03/30/2015
Based on Pietro's script
'''

import commands
import fileinput
import argparse
import sys
import os

TESTING = 0
QUEUE = ''

rootfolder = os.getcwd()


def runCommand(command, printIt = 0, doIt = 1, TESTING = 0) :
    if TESTING : 
        printIt = 1
        doIt = 0
    if printIt : print ('> ' + command)
    if doIt : 
        commandOutput = commands.getstatusoutput(command)
        if printIt : print commandOutput[1]
        return commandOutput[0]
    else :    print ('    jobs not submitted')
    return 1
    
# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


def prepareJob(tag, i, folderName) :
    filename = folderName+'/run_' + tag + '.sh'
    f = open(filename, 'w')

    f.write('#!/bin/bash \n\n')

    f.write('echo "Start of job on " `date`\n\n')

    f.write('source /cvmfs/cms.cern.ch/cmsset_default.sh\n\n')
    f.write('eval `scramv1 runtime -sh`\n\n')

    f.write('### Prepare environments for FastJet ### \n\n')

    f.write('export FASTJET_BASE=`scram tool info fastjet | grep FASTJET_BASE | sed -e s%FASTJET_BASE=%%`\n')
    f.write('export PATH=$FASTJET_BASE/bin/:$PATH \n')

    f.write('### Prepare environments for LHAPDF ### \n\n')

    f.write('export LHAPDF_BASE=`scram tool info lhapdf | grep LHAPDF_BASE | sed -e s%LHAPDF_BASE=%%`    \n')
    f.write('export PATH=$LHAPDF_BASE/bin/:$PATH \n')
    f.write('export LHAPATH=`scram tool info lhapdf | grep LHAPATH | sed -e s%LHAPATH=%%`\n')

    f.write('export LHAPDF6TOOLFILE=$CMSSW_BASE/config/toolbox/$SCRAM_ARCH/tools/available/lhapdf6.xml \n\n')

    f.write('if [ -e $LHAPDF6TOOLFILE ]; then \n')
    f.write('    export LHAPDF6_BASE=`grep LHAPDF6_BASE $CMSSW_BASE/config/toolbox/$SCRAM_ARCH/tools/available/lhapdf6.xml | head -1 | cut -d \\" -f 4 `\n')
    f.write('    export LHAPDF_DATA_PATH=`$LHAPDF6_BASE/bin/lhapdf-config --datadir` \n')
    f.write('fi \n\n')
#    f.write('cd ' + rootfolder + '/' + folderName + '\n')
#    f.write('echo ' + str (i) + ' | ../pwhg_main > log_' + tag + '.log 2>&1' + '\n')

    f.close()
    return filename


# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


def prepareJobForEvents (tag, i, folderName, EOSfolder) :
    runCommand('rm ' + rootfolder + '/' + folderName + '/log_' + tag + '.log')
    filename = 'run_' + tag + '.sh'

    prepareJob(tag, i, folderName)

    f = open (filename, 'a')
    f.write ('cp -p ' + rootfolder + '/' + folderName + '/powheg.input ./' + '\n')
    f.write ('cp -p ' + rootfolder + '/' + folderName + '/JHUGen.input ./' + '\n')
    f.write ('cp -p ' + rootfolder + '/' + folderName + '/*.dat  ./' + '\n')

    f.write ('cd -' + '\n')

    f.write ('pwd' + '\n')
    f.write ('ls' + '\n')
    f.write ('echo ' + str (i) + ' | ' + rootfolder + '/pwhg_main > log_' + tag + '.log 2>&1' + '\n')
    f.write ('cp -p log_' + tag + '.log ' + rootfolder + '/' + folderName + '/. \n')
    #lhefilename = 'pwgevents-{:04d}.lhe'.format(i) 

    #f.write ('cmsStage ' + lhefilename + ' /store/user/govoni/LHE/powheg/' + EOSfolder + '/\n')
    #f.write ('rm -f ' + lhefilename + '\n')

    f.close ()
    return filename


# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


def runParallelXgrid(parstage, xgrid, folderName, nEvents, njobs, powInputName, jobtag, rndSeed) :
    # parstage, xgrid are strings!

    print 'running jobs for grid'
    print folderName

    inputName = folderName + "/powheg.input"

    sedcommand = 'sed -i "s/NEVENTS/' + nEvents + '/ ; s/SEED/'+rndSeed+'/ ; s/parallelstage.*/parallelstage '+parstage+'/ ; s/xgriditeration.*/xgriditeration '+xgrid+'/ ; s/fakevirt.*// " '+inputName

    #print sedcommand
    runCommand(sedcommand)

    if(parstage == '1' and xgrid == '1') :
        if not 'parallelstage' in open(inputName).read() :
            runCommand("echo \'\n\nparallelstage "+parstage+"\' >> "+inputName)
        if not 'xgriditeration' in open(inputName).read() :
            runCommand("echo \'xgriditeration "+xgrid+"\' >> "+inputName)

        if not 'manyseeds' in open(inputName).read() :
            runCommand("echo \'manyseeds 1\' >> "+ inputName)

        if not 'fakevirt' in open(inputName).read() :
            runCommand("echo \'fakevirt 1\' >> "+inputName)

    #runCommand('cp -p powheg.input ' + folderName)

    runCommand('cp -p '+inputName+' '+inputName+'.'+parstage+'_'+str(xgrid))

    for i in range (1, njobs + 1) :
        jobID = jobtag + '_' + str(i)
        jobname = prepareJob(jobID, i, folderName)

        filename = folderName+'/run_' + jobID + '.sh'
        f = open(filename, 'a')
        f.write('echo ' + str (i) + ' | ./pwhg_main > run_' + jobID + '.log 2>&1' + '\n')
        f.close()

        #runCommand('bsub -J ' + jobID + ' -u pippopluto -q ' + QUEUE + ' < ' + jobname, 1, TESTING == 0)

        if QUEUE == '':
            print 'Direct running... #'+str(i)+' \n'
            os.system('cd '+folderName+';bash run_'+jobID+'.sh &')
        else:
            print 'Submitting to queue: '+QUEUE+' #'+str(i)+' \n'
            runCommand ('bsub -J ' + jobID + ' -u $USER -q ' + QUEUE + ' ' + folderName + '/run_'+jobID+'.sh ', TESTING == 0)


    #runCommand ('mv *.sh ' + folderName)


# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
def runSingleXgrid(parstage, xgrid, folderName, nEvents, powInputName, seed) :

    print 'Running single job for Xgrid'
    print folderName

    inputName = folderName + "/powheg.input"

#    runCommand('mv -f powheg.input powheg.input.temp')
#    sedcommand = 'sed "s/parallelstage.*/parallelstage ' + parstage + '/ ; s/xgriditeration.*/xgriditeration ' + xgrid + '/" ' + powInputName + ' > ' + folderName + '/powheg.input'
    sedcommand = 'sed "s/NEVENTS/' + nEvents + '/ ; s/SEED/' + seed + '/" ' + powInputName + ' > ' + folderName + '/powheg.input'

    runCommand(sedcommand)

    prepareJob('Xgrid', '', folderName)

    #runCommand('rm -f ' + folderName + '/run_Xgrid.sh')
    #runCommand('cp -p run_Xgrid.sh ' + folderName + '/.')

    filename = folderName + '/run_Xgrid.sh'

    f = open(filename, 'a')
    #f.write('./pwhg_main > run_Xgrid.log 2>&1' + '\n')
    f.write('./pwhg_main \n')

    f.write('echo "\nEnd of job on " `date` \n')
    f.close()

    #runCommand ('bsub -J ' + jobID + ' -u pippopluto -q ' + QUEUE + ' < ' + jobname, 1, TESTING == 0)

    if QUEUE == '':
        print 'Direct running... \n'
        #runCommand ('cd ' + folderName + '/; bash run_Xgrid.sh', TESTING == 0)
        os.system('cd '+folderName+';bash run_Xgrid.sh >& run_Xgrid.log &')
        #print "Issue 'bash run_Xgrid.sh >& run_Xgrid.log &' to generate grid..."
        
    else:
        print 'Submitting to queue: '+QUEUE+' \n'
        runCommand ('bsub -J ' + jobID + ' -u $USER -q ' + QUEUE + ' ' + folderName + '/run_Xgrid.sh ', TESTING == 0)




# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
def runGetSource(parstage, xgrid, folderName, powInputName, process) :
    # parstage, xgrid are strings!

    print 'Getting and compiling POWHEG source...'

    prepareJob('source', '', '.')

    filename = 'run_source.sh'
    f = open (filename, 'a')

    f.write('export name='+folderName+'\n\n')
#    f.write('set process='+rootfolder+'\n\n')
    f.write('export cardInput='+powInputName+'\n\n')
    f.write('export process='+process+'\n\n')
    f.write(
'''
# Release to be used to define the environment and the compiler needed
export RELEASE=${CMSSW_VERSION}
export WORKDIR=`pwd`
export jhugenversion="v5.2.5"


# initialize the CMS environment 

#if [ -e ${name} ]; then
#  echo -e "The directory ${name} exists! Move the directory to old_${name}"
#  echo
#  mv ${name} old_${name}
#  mv output.lhe old_output.lhe
#  rm -rf ${name}
#  echo -e "Move the tar ball to old_${tarball}.tar.gz"
#  echo
#  mv ${tarball}_tarball.tar.gz old_${tarball}_tarball.tar.gz
#fi

mkdir -p ${name} ; 

cd ${name}
export PATH=`pwd`:${PATH}

## Get the input card
#wget --no-check-certificate http://cms-project-generators.web.cern.ch/cms-project-generators/${cardinput} -O powheg.input  || cp -p ${cardinput} powheg.input || fail_exit "Failed to get powheg input card " ${card}

cp -p ../${cardInput} powheg.input
cp -p ../JHUGen.input JHUGen.input

sed -i -e "s#--#-#g" powheg.input

myDir=`pwd`
card=${myDir}/powheg.input
cardj=${myDir}/JHUGen.input

## Try to get the JHUGen card
#wget --no-check-certificate http://cms-project-generators.web.cern.ch/cms-project-generators/${usejhugen} -O JHUGen.input || cp -p ${usejhugen} JHUGen.input

jhugen=0
if [[ -s ./JHUGen.input ]]; then
  jhugen=$(expr $jhugen + 1)
  echo "JHUGen activated!"
fi

### retrieve the powheg source tar ball
export POWHEGSRC=powhegboxV2_Feb2015.tar.gz

echo 'D/L POWHEG source...'

if [ ! -f ${POWHEGSRC} ]; then
  wget --no-check-certificate http://cms-project-generators.web.cern.ch/cms-project-generators/${SCRAM_ARCH}/powheg/V2.0/src/powhegboxV2_Feb2015.tar.gz || fail_exit "Failed to get powheg tar ball "
fi

tar zxf ${POWHEGSRC}
#
patch -l -p0 -i ${WORKDIR}/patches/pdfweights.patch
cd POWHEG-BOX/${process}

# This is just to please gcc 4.8.1
mkdir -p include

# Use dynamic linking and lhapdf
sed -i -e "s#STATIC[ \t]*=[ \t]*-static#STATIC=-dynamic#g" Makefile
sed -i -e "s#PDF[ \t]*=[ \t]*native#PDF=lhapdf#g" Makefile

# Use gfortran, not other compilers which are not free/licensed
sed -i -e "s#COMPILER[ \t]*=[ \t]*ifort#COMPILER=gfortran#g" Makefile

# Find proper histo booking routine (two of them exist)
BOOK_HISTO="pwhg_bookhist-multi.o"
if [ `echo ${name} | cut -d "_" -f 1` = "powhegboxV1" ]; then
   BOOK_HISTO="pwhg_bookhist.o"
fi 
if [ "$process" = "trijet" ]; then 
   BOOK_HISTO+=" observables.o"
fi  
if [ "$process" = "VBF_HJJJ" ]; then 
  sed -i 's/..\/pwhg_book.h/pwhg_book.h/g' pwhg_analysis-dummy.f
fi  
if [ "$process" = "VBF_H" ]; then 
  sed -i '/pwhginihist/d' pwhg_analysis-dummy.f 
fi  

# Remove ANY kind of analysis with parton shower
if [ `grep particle_identif pwhg_analysis-dummy.f` = ""]; then
   cp ../pwhg_analysis-dummy.f .
fi
sed -i -e "s#PWHGANAL[ \t]*=[ \t]*#\#PWHGANAL=#g" Makefile
sed -i -e "s#ANALYSIS[ \t]*=[ \t]*#\#ANALYSIS=#g" Makefile
sed -i -e "s#LHAPDF_CONFIG[ \t]*=[ \t]*#\#LHAPDF_CONFIG=#g" Makefile
sed -i -e "s#pwhg_bookhist.o# #g" Makefile
sed -i -e "s#pwhg_bookhist-new.o# #g" Makefile
sed -i -e "s#pwhg_bookhist-multi.o# #g" Makefile
if [ "$process" = "ttJ" ]; then
  sed -i -e "s#_PATH) -L#_PATH) #g" Makefile
  sed -i -e "s# -lvirtual#/libvirtual.so.1.0.0#g" Makefile
fi
if [ "$process" = "ttH" ]; then
  sed -i 's/O2/O0/g' Makefile
  sed -i 's/4.5d0/4.75d0/g' init_couplings.f
fi
if [ "$process" = "gg_H_MSSM" ]; then 
  sed -i 's/leq/le/g' nloreal.F
  cp -p ../gg_H_quark-mass-effects/SLHA.h .
  cp -p ../gg_H_quark-mass-effects/SLHADefs.h .
fi  
  
echo "ANALYSIS=none 
PWHGANAL=$BOOK_HISTO pwhg_analysis-dummy.o
LHAPDF_CONFIG=${LHAPDF6_BASE}/bin/lhapdf-config" >> tmpfile
mv Makefile Makefile.interm
cat tmpfile Makefile.interm > Makefile
rm -f Makefile.interm tmpfile

# Add libraries
echo "LIBS+=-lz -lstdc++" >> Makefile
if [ $jhugen = 1 ]; then
  if [ ! -f JHUGenerator.${jhugenversion}.tar.gz ]; then
    wget --no-check-certificate http://cms-project-generators.web.cern.ch/cms-project-generators/slc6_amd64_gcc481/JHUGenerator.${jhugenversion}.tar.gz || fail_exit "Failed to get JHUGen tar ball "
  fi

  tar xzf JHUGenerator.${jhugenversion}.tar.gz
  cd JHUGenerator
  sed -i -e "s#Comp = ifort#Comp = gfort#g" makefile
  make
  cd ..
fi
if [ "$process" = "gg_H_2HDM" ] || [ "$process" = "gg_H_MSSM" ]; then
  echo "Adding CHAPLIN 1.2 library"
  if [ ! -f chaplin-1.2.tar ]; then
    wget http://chaplin.hepforge.org/code/chaplin-1.2.tar || fail_exit "Failed to get CHAPLIN tar ball "
  fi
  tar xvf chaplin-1.2.tar
  cd chaplin-1.2
  ./configure --prefix=`pwd`/..
  make install
  cd .. 
  echo "LIBS+=-L`pwd`/lib/ -L`pwd`/lib64/" >> Makefile   # be safe
  export LD_LIBRARY_PATH=`pwd`/lib/:`pwd`/lib64/:${LD_LIBRARY_PATH}

  if [ "$process" = "gg_H_MSSM" ]; then
    echo "Adding FeynHiggs 2.10 library"
    if [ ! -f FeynHiggs-2.10.2.tar.gz ]; then
      wget http://wwwth.mpp.mpg.de/members/heinemey/feynhiggs/newversion/FeynHiggs-2.10.2.tar.gz || fail_exit "Failed to get FeynHiggs tar ball "
    fi
    tar xvf FeynHiggs-2.10.2.tar.gz
    cd FeynHiggs-2.10.2
    ./configure --prefix=`pwd`/..
    make 
    make install
    cd ..
  fi
fi  

echo 'Compiling pwhg_main...'

make pwhg_main || fail_exit "Failed to compile pwhg_main"

mkdir -p ${WORKDIR}/${name}
cp -p pwhg_main ${WORKDIR}/${name}/.
cd ${WORKDIR}/${name}

#mkdir -p workdir
#cd workdir
localDir=`pwd`

# Copy additional files
if [ -e  ${WORKDIR}/vbfnlo.input ]; then
  cp -p ${WORKDIR}/vbfnlo.input .
fi 
if [ -e ${WORKDIR}/br.a3_2HDM ]; then
  cp -p ${WORKDIR}/br*2HDM .
fi
if [ -e  ${WORKDIR}/powheg-fh.in ]; then
  cp -p ${WORKDIR}/powheg-fh.in .
fi
if [ -e  ${WORKDIR}/cteq6m ]; then
    cp -p ${WORKDIR}/cteq6m .
fi 

#rm -f ${WORKDIR}/${name}/powheg.input
#cat ${card} | sed -e "s#SEED#${seed}#g" | sed -e "s#NEVENTS#${nevt}#g" > powheg.input

#cat powheg.input
#if [[ -e ../pwhg_main-gnu ]]; then
#  mv ../pwhg_main-gnu ../pwhg_main
#  chmod a+x ../pwhg_main
#fi

#make sure env variable for pdfsets points to the right place
#export LHAPDF_DATA_PATH=`${myDir}/lhapdf-config --datadir`
#../pwhg_main &> log_${process}_${seed}.txt

cp -p ../runcms*.sh .

cd ${WORKDIR}

echo 'Compiling finished...'

if [ $jhugen = 1 ]; then
  cp -p ${cardj} .
  if [ ! -e  ${WORKDIR}/runcmsgrid_powhegjhugen.sh ]; then
   fail_exit "Did not find " ${WORKDIR}/runcmsgrid_powhegjhugen.sh 
  fi
  sed -e 's/PROCESS/'${process}'/g' ${WORKDIR}/runcmsgrid_powhegjhugen.sh > runcmsgrid.sh
else
  if [ ! -e  ${WORKDIR}/runcmsgrid_powheg.sh ]; then
   fail_exit "Did not find " ${WORKDIR}/runcmsgrid_powheg.sh 
  fi
  sed -e 's/PROCESS/'${process}'/g' ${WORKDIR}/runcmsgrid_powheg.sh > runcmsgrid.sh
fi

chmod 755 runcmsgrid.sh

''')

    f.close()

    if QUEUE == '':
        print 'Direct compiling... \n'
        #runCommand ('bash run_source.sh ', TESTING == 1)
        os.system('bash run_source.sh >& run_source.log &')
        #print "Issue 'bash run_source.sh >& run.log &' to compile powheg..."
        
    else:
        print 'Submitting to queue: '+QUEUE+' \n'
        runCommand ('bsub -J ' + jobID + ' -u $USER -q ' + QUEUE + ' run_source.sh ', TESTING == 0)


    #print "Source done..."
    #runCommand ('mv *.sh ' + folderName)

    #runCommand ('cp -p runcms*.sh ' + folderName + '/.')

    return

# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


def runEvents(parstage, folderName, EOSfolder, njobs, powInputName, jobtag) :
    print 'run : submitting jobs'
    #runCommand('rm -f ' + folderName + 'powheg.input')
    sedcommand = 'sed -i "s/parallelstage.*/parallelstage ' + parstage + '/ ; s/xgriditeration.*/xgriditeration 1/" '+folderName+'/powheg.input'

    runCommand(sedcommand)
    #runCommand('cp -p powheg.input ' + folderName)
    #runCommand('cp -p JHUGen.input ' + folderName)
    runCommand('cp -p ' + folderName + '/powheg.input ' + folderName + '/powheg.input.' + parstage)

    for i in range (1, njobs + 1) :
        tag = jobtag + '_' + str (i)
        # real run
        if parstage == '4' : jobname = prepareJobForEvents(tag, i, folderName, EOSfolder)
        else               : jobname = prepareJob(tag, i, folderName)
        jobID = jobtag + '_' + str (i)
        #runCommand ('bsub -J ' + jobID + ' -u pippopluto -q ' + QUEUE + ' < ' + jobname, 1, TESTING == 0)

        filename = folderName+'/run_' + tag + '.sh'
        f = open (filename, 'a')
        f.write('echo ' + str (i) + ' | ./pwhg_main > run_' + tag + '.log 2>&1' + '\n')
        f.close()


        if QUEUE == '':
            print 'Direct running... #'+str(i)+' \n'
            os.system('cd '+folderName+';bash run_'+tag+'.sh &')

        else:
            print 'Submitting to queue: '+QUEUE+' #'+str(i)+' \n'
            runCommand ('cd '+folderName+';bsub -J ' + jobID + ' -u $USER -q ' + QUEUE + ' ' + folderName + '/run_'+tag+'.sh', TESTING == 0)

    #runCommand('mv *.sh ' + folderName)


# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

def createTarBall(parstage, folderName, prcName, keepTop) :
    print 'Creating tarball distribution for ' + args.folderName + '_' + prcName
    print

    runCommand('cd ' + rootfolder)
    runCommand('rm -rf ' + folderName + '_' + prcName + '.tgz')

    runCommand('cp -p ' + rootfolder + '/run_pwg.py ' + rootfolder + '/' + folderName + '/.')
    runCommand('cp -p ' + rootfolder + '/runcmsgrid*.sh ' + rootfolder + '/' + folderName + '/.')

    if keepTop == '1' :
      print 'Keeping validation plots.'
      print
      runCommand('tar zcvf ' + rootfolder + '/' + folderName + '_' + prcName + '.tgz ' + folderName +' --exclude=POWHEG-BOX --exclude=powhegbox*.tar.gz --exclude=*.lhe --exclude=run_*.sh --exclude=*.log --exclude=*temp', printIt = 1)
    else :
      runCommand('tar zcvf ' + rootfolder + '/' + folderName + '_' + prcName + '.tgz ' + folderName +' --exclude=POWHEG-BOX --exclude=powhegbox*.tar.gz --exclude=*.top --exclude=*.lhe --exclude=run_*.sh --exclude=*.log --exclude=*temp', printIt = 1)

    print
    print 'Done.'

# ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


if __name__ == "__main__":

    eoscmd = '/afs/cern.ch/project/eos/installation/cms/bin/eos.select' ;

#    folderName = 'test_prod'
#    parser.parstage      = sys.argv[1]
#    xgrid         = sys.argv[2]
#    folderName    = sys.argv[3] # grids folder
#    totEvents     = sys.argv[4]
#    inputTemplate = sys.argv[5] # FIXME build the template... it simply should be the cfg file
#    eosFolderName = sys.argv[6]
    
    parser = argparse.ArgumentParser (description = 'run phantom productions on lxplus')
    parser.add_argument('-p', '--parstage'      , default= '0',            help='stage of the production process [0]')
    parser.add_argument('-x', '--xgrid'         , default= '1',            help='loop number for the girds production [1]')
    parser.add_argument('-f', '--folderName'    , default='testProd',      help='local folder and last eos folder name[testProd]')
    parser.add_argument('-e', '--eosFolder'     , default='NONE' ,         help='folder before the last one, on EOS')
    parser.add_argument('-t', '--totEvents'     , default= '10000',        help='total number of events to be generated [10000]')
    parser.add_argument('-n', '--numEvents'     , default= '2000',         help='number of events for a single job [2000]')
    parser.add_argument('-i', '--inputTemplate' , default= 'powheg.input', help='input cfg file (fixed) [=powheg.input]')
    parser.add_argument('-q', '--lsfQueue'      , default= '',          help='LSF queue [2nd]')
    parser.add_argument('-s', '--rndSeed'       , default= '42',           help='Starting random number seed [42]')
    parser.add_argument('-m', '--prcName'       , default= 'DMGG',           help='POWHEG process name [DMGG]')
    parser.add_argument('-k', '--keepTop'       , default= '0',           help='Keep the validation top draw plots [0]')

    args = parser.parse_args ()
    
    QUEUE = args.lsfQueue
    EOSfolder = args.folderName

    print
    print 'RUNNING PARAMS: args.parstage = ' + args.parstage + ' , args.xgrid = ' + args.xgrid  + ' , args.folderName = ' + args.folderName 
    print '                args.totEvents = ' + args.totEvents 
    print '                powheg input cfg file : ' + args.inputTemplate 
    print '                powheg process name : ' + args.prcName
    print '                working folder : ' + args.folderName
    print '                EOS folder : ' + args.eosFolder + '/' + EOSfolder
    print '                base folder : ' + rootfolder
    print
 
    if (TESTING == 1) :     
        print '  --- TESTNG, NO submissions will happen ---  '
        print

    res = runCommand('ls ' + args.folderName)
    if args.parstage == '1' and args.xgrid == '1' and res != 0 :
        print 'Working folder ' + args.folderName + ' not existing, exiting...'
        sys.exit (-1)
    if args.parstage == '1' and args.xgrid == '1' :
#        runCommand ('mkdir ' + args.folderName)
#        runCommand ('cp -p pwgseeds.dat ' + args.folderName)
        res = runCommand('ls ' + args.folderName + '/pwgseeds.dat')
        if res != 0 :
            fseed = open(args.folderName + '/pwgseeds.dat', 'w')
            for ii in range(1, 501) :
                fseed.write(str(ii)+'\n')
#        #FIXME this is a crude hardcoded trick to overcome some problems in LHAPDF usage
#        runCommand ('ln -s /afs/cern.ch/user/g/govoni/work/HiggsPlusJets/lhapdf/share/lhapdf/PDFsets/CT10.LHgrid ./'  + args.folderName)

    if args.parstage == '4' :    
        runCommand (eoscmd + ' mkdir /eos/cms/store/user/${user}/LHE/powheg/' + args.eosFolder, 1, 1)
        runCommand (eoscmd + ' mkdir /eos/cms/store/user/${user}/LHE/powheg/' + args.eosFolder + '/' + EOSfolder, 1, 1)

    njobs = int (args.totEvents) / int (args.numEvents)

    powInputName = args.inputTemplate
    #powInputName = args.inputTemplate + '_tempo'
    #sedcommand = 'sed "s/numevts.*/numevts ' + args.numEvents + '/" ' + args.inputTemplate + ' > ' + powInputName
    #runCommand (sedcommand)

    jobtag = args.parstage + '_' + args.xgrid

    if args.parstage == '0' :
        #runCommand('cp -p JHUGen.input '+args.folderName+'/.')
        runGetSource(args.parstage, args.xgrid, args.folderName,
                     powInputName, args.prcName)
    elif args.parstage == '1' :
        runParallelXgrid(args.parstage, args.xgrid, args.folderName,
                         args.numEvents, njobs, powInputName, jobtag,
                         args.rndSeed)
    elif args.parstage == '123' :
        runSingleXgrid(args.parstage, args.xgrid, args.folderName,
                       args.numEvents, powInputName, args.rndSeed)
    elif args.parstage == '1239' :
        runSingleXgrid(args.parstage, args.xgrid, args.folderName,
                       args.numEvents, powInputName, args.rndSeed)
        createTarBall(args.parstage, args.folderName, args.prcName)
    elif args.parstage == '9' :
        createTarBall(args.parstage, args.folderName, args.prcName,
                      args.keepTop)
    else                    :
        runEvents(args.parstage, args.folderName,
                  args.eosFolder + '/' + EOSfolder, njobs, powInputName, jobtag)
