//--------------------------------------------------------------------------------------------------
// $Id: DMSTreeWriter.h,v 1.10 2013/10/21 19:34:02 dimatteo Exp $
//
// DMSTreeWriter
//
// Authors: L. Di Matteo        (original class from G.G.Ceballos)
//--------------------------------------------------------------------------------------------------
#ifndef MITMONOJET_MODS_DMSTreeWriter_H
#define MITMONOJET_MODS_DMSTreeWriter_H

#include <TH1D.h>
#include <TFile.h>

#include "MitAna/TreeMod/interface/BaseMod.h" 
#include "MitAna/DataTree/interface/MCEventInfo.h"
#include "MitAna/DataTree/interface/PileupInfoCol.h"
#include "MitAna/DataTree/interface/PileupEnergyDensityCol.h"
#include "MitAna/DataTree/interface/VertexCol.h"
#include "MitAna/DataTree/interface/PhotonFwd.h"
#include "MitAna/DataTree/interface/TrackCol.h"
#include "MitAna/DataTree/interface/PFCandidateCol.h"
#include "MitAna/DataTree/interface/DecayParticleCol.h"
#include "MitAna/DataTree/interface/ElectronCol.h"
#include "MitAna/DataTree/interface/MuonCol.h"
#include "MitAna/DataTree/interface/PFTauCol.h"
#include "MitAna/DataTree/interface/MCParticleCol.h"
#include "MitAna/DataTree/interface/MetCol.h"
#include "MitAna/DataTree/interface/PFMetCol.h"
#include "MitAna/DataTree/interface/JetCol.h"
#include "MitAna/DataTree/interface/PFJetCol.h"
#include "MitAna/DataTree/interface/TriggerObjectCol.h"
#include "MitPhysics/Utils/interface/PhotonFix.h"
#include "MitPhysics/Utils/interface/PhotonTools.h"
#include "MitPhysics/Utils/interface/VertexTools.h"
#include "MitMonoJet/DataTree/interface/XlMetCol.h"
#include "MitMonoJet/DataTree/interface/XlFatJetCol.h"
#include "MitMonoJet/DataTree/interface/XlSubJetCol.h"
#include "MitMonoJet/DataTree/interface/XlEvtSelData.h"

#include "MitMonoJet/Core/MitDMSTree.h"


namespace mithep 
{

  class DMSTreeWriter : public BaseMod
  {
  public:
    typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > LorentzVector;

    DMSTreeWriter(const char *name  = "DMSTreeWriter", 
                  const char *title = "DMS Tree writer");
    
    ~DMSTreeWriter();

    // setting all the input Names
    void    SetRawMetName(const char *n)            { fRawMetName= n;              }
    void    SetMetName(const char *n)               { fMetName= n;                 }
    void    SetMetFromBranch(bool b)                { fMetFromBranch = b;          }
    void    SetMetMVAName(const char *n)            { fMetMVAName= n;              }
    void    SetMetMVAFromBranch(bool b)             { fMetMVAFromBranch = b;       }
    void    SetPhotonsName(const char *n)           { fPhotonsName= n;             }
    void    SetPhotonsFromBranch(bool b)            { fPhotonsFromBranch = b;      }
    void    SetElectronsName(const char *n)         { fElectronsName = n;          }
    void    SetElectronsFromBranch(bool b)          { fElectronsFromBranch = b;    }
    void    SetMuonsName(const char *n)             { fMuonsName = n;              }
    void    SetMuonsFromBranch(bool b)              { fMuonsFromBranch = b;        }
    void    SetTausName(const char *n)              { fTausName = n;               }
    void    SetTausFromBranch(bool b)               { fTausFromBranch = b;         }
    void    SetJetsName(const char *n)              { fJetsName = n;               }
    void    SetJetsFromBranch(bool b)               { fJetsFromBranch = b;         }
    void    SetFatJetsName(const char *n)           { fFatJetsName = n;            }
    void    SetFatJetsFromBranch(bool b)            { fFatJetsFromBranch = b;      }
    void    SetSubJetsName(const char *n)           { fSubJetsName = n;            }
    void    SetSubJetsFromBranch(bool b)            { fSubJetsFromBranch = b;      }
                                                    
    void    SetPVName(const char *n)                { fPVName = n;                 }
    void    SetPVFromBranch(bool b)                 { fPVFromBranch = b;           }
    void    SetPUInfoName(const char *n)            { fPileUpName = n;             }

    void    SetTriggerObjectsName(const char *n)    { fTriggerObjectsName = n;     }
    void    SetIsData (Bool_t b)                    { fIsData = b;                 }

    void    SetInPUHistoFileName(const char *n)     { fPUInputFileName = n;        }
    void    SetTargetPUHistoFileName(const char *n) { fPUTargetFileName = n;       }

  protected:
    void    Process();
    void    SlaveBegin();
    void    SlaveTerminate();
            
  private:  
    void    CorrectMet(const float met, const float metPhi,
                                   const Particle *l1, const Particle *l2,
                                   float &newMet, float &newMetPhi);

    // Private auxiliary methods... Names of the input Collections

    TString                        fEvtSelDataName;
    TString                        fRawMetName;
    TString                        fMetName;
    TString                        fMetMVAName;
    TString                        fPhotonsName;
    TString                        fElectronsName;
    TString                        fMuonsName;
    TString                        fTausName;
    TString                        fJetsName;
    TString                        fFatJetsName;
    TString                        fSubJetsName;
    TString                        fPVName;
    TString                        fPileUpDenName;    
    TString                        fPileUpName;
    TString                        fMCEventInfoName;
    TString                        fMCParticlesName;
    TString                        fTriggerObjectsName;
			           
    Bool_t                         fIsData;
    Bool_t                         fMetFromBranch;
    Bool_t                         fMetMVAFromBranch;
    Bool_t                         fPhotonsFromBranch;
    Bool_t                         fElectronsFromBranch;
    Bool_t                         fMuonsFromBranch;
    Bool_t                         fTausFromBranch;
    Bool_t                         fJetsFromBranch;
    Bool_t                         fFatJetsFromBranch;
    Bool_t                         fSubJetsFromBranch;
    Bool_t                         fPVFromBranch;
			         
    const PFMetCol                *fRawMet;
    const MetCol                  *fMet;
    const XlMetCol                *fMetMVA;
    const PhotonCol               *fPhotons;
    const ElectronCol             *fElectrons;
    const MuonCol                 *fMuons;
    const PFTauCol                *fPFTaus;
    const PFJetCol                *fJets;
    const XlFatJetCol             *fFatJets;
    const XlSubJetCol             *fSubJets;
    const VertexCol               *fPV;
    const PileupInfoCol           *fPileUp;    
    const PileupEnergyDensityCol  *fPileUpDen;
    const MCEventInfo             *fMCEventInfo;
    const MCParticleCol           *fMCParticles;
    const XlEvtSelData            *fEvtSelData;
    const TriggerObjectCol        *fTrigObj;

    // Auxiliary
    TString                        fPUInputFileName;     // input PU histo file
    TString                        fPUTargetFileName;    // target PU histo file
    TH1D                          *fPUInput;             // input PU histo
    TH1D                          *fPUTarget;            // target PU histo
    const TH1D                    *fPUWeight;            // target PU histo
    Float_t                        PUWeight(Float_t npu);// PU reweighting function

    // Gen Level Info Analysis   
    void                           getGenLevelInfo(MitDMSTree& tree);
    // Hlt Objects Matcher   
    Bool_t                         IsHLTMatched(LorentzVector& v,
                                                TriggerObject::ETriggerObject,
                                                Float_t deltaR = 0.5,
                                                Float_t minPt = 0.,
                                                Float_t maxEta = 99.);
    // Jet-Parton Id Matcher   
    Int_t                          JetPartonMatch(LorentzVector& v,
                                                  Float_t deltaR = 0.5);

    // Get B-tag via FatJet-Standard Jet matching   
    Float_t                        GetFatJetBtag(LorentzVector& v,
                                                 Float_t deltaR = 0.3);
                                                
    TFile                         *fOutputFile;
    MitDMSTree                     fMitDMSTree;

    ClassDef(DMSTreeWriter,1)
  };
}
#endif
