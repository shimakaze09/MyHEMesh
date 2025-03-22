//
// Created by Admin on 09/03/2025.
//

#pragma once

#include "detail/ForwardDecl.h"

namespace My {
template <typename Traits>
class TEdge {
 public:
  using V = HEMeshTriats_V<Traits>;
  using E = HEMeshTriats_E<Traits>;
  using P = HEMeshTriats_P<Traits>;
  using H = HEMeshTriats_H<Traits>;

 public:
  H* const HalfEdge() noexcept { return halfEdge; }

  const H* const HalfEdge() const noexcept {
    return const_cast<TEdge*>(this)->HalfEdge();
  }

  void SetHalfEdge(H* he) noexcept { halfEdge = he; }

  bool IsBoundary() const noexcept {
    return HalfEdge()->IsBoundary() || HalfEdge()->Pair()->IsBoundary();
  }

  // clockwise
  // + [he.RotateNext, he.RotateNext.RotateNext, ..., he)
  // + [he.next, he.next.RotateNext, ..., he.pair)
  const std::vector<H*> AdjOutHalfEdges();

  const std::set<V*> AdjVertices();

  const std::vector<E*> AdjEdges();

 private:
  friend HEMesh<Traits>;

  bool IsFree() const noexcept {
    return HalfEdge()->IsFree() && HalfEdge()->Pair()->IsFree();
  }

  H* halfEdge{nullptr};
};
}  // namespace My

#include "detail/TEdge.inl"
