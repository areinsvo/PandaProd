#ifndef PandaProd_Producer_PFCandsFiller_h
#define PandaProd_Producer_PFCandsFiller_h

#include "FillerBase.h"

#include "DataFormats/Candidate/interface/CandidateFwd.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"

class PFCandsFiller : public FillerBase {
 public:
  PFCandsFiller(std::string const&, edm::ParameterSet const&, edm::ConsumesCollector&);
  ~PFCandsFiller() {}

  void branchNames(panda::utils::BranchList& eventBranches, panda::utils::BranchList&) const override;
  void fill(panda::Event&, edm::Event const&, edm::EventSetup const&) override;
  void setRefs(ObjectMapStore const&) override;

 protected:
  typedef edm::ValueMap<reco::CandidatePtr> CandidatePtrMap;
  typedef edm::View<reco::Vertex> VertexView;
  typedef edm::Ptr<reco::Vertex> VertexPtr;

  NamedToken<reco::CandidateView> candidatesToken_;
  NamedToken<CandidatePtrMap> puppiMapToken_;
  NamedToken<reco::CandidateView> puppiInputToken_;
  NamedToken<CandidatePtrMap> puppiNoLepMapToken_;
  NamedToken<reco::CandidateView> puppiNoLepInputToken_;
  NamedToken<VertexView> verticesToken_;

  //! cache the candidate and vertex ordering (using ref keys) to use in setRefs
  panda::PFCandCollection* outCandidates_{};
  std::vector<VertexPtr> orderedVertices_{};
};

#endif
