# PandaProd
Package for production of PandA from CMSSW

Installation

    export CMSSW_RELEASE=CMSSW_8_0_29
    export TREE_BRANCH=master
    export PROD_BRANCH=branch-80X

    source /cvmfs/cms.cern.ch/cmsset_default.sh
    scram p CMSSW $CMSSW_RELEASE
    cd $CMSSW_RELEASE/src
    eval `scram runtime -sh`
    git clone -b $TREE_BRANCH https://github.com/PandaPhysics/PandaTree.git
    git clone -b $PROD_BRANCH https://github.com/LPCPandaPhysics/PandaProd.git
    #populate POG's and physics's packages
    sh PandaProd/Producer/cfg/setuprel.sh
    scram b -j12

Run

    cmsRun PandaProd/Producer/cfg/prod.py [options]

    #Example, running on 10 events:

    cmsRun PandaProd/Producer/cfg/prod.py config=Summer16 inputFiles=root://cmsxrootd.fnal.gov///store/mc/RunIISummer16MiniAODv2/TTbarDMJets_pseudoscalar_Mchi-1_Mphi-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/MINIAODSIM/PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/80000/74F12CB6-44B7-E611-A5FD-0CC47A13CFC0.root maxEvents=10

Crab Job Submission

     #please change the line in submitCrab.py https://github.com/LPCPandaPhysics/PandaProd/blob/branch-80X/Producer/cfg/submitCrab.py#L45 to point to your personal EOS area (Soon LPCPhysics EOS will exist for common storage)
     #setup
     cd PandaProd/Producer/cfg/
     source setupCrab.sh
     python submitCrab.py