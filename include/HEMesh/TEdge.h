//
// Created by Admin on 09/03/2025.
//

#pragma once

#include "ForwardDecl.h"

namespace My {
template <typename V, typename E, typename P = EmptyP<V, E>>
class TEdge {
 private:
  // internal use
  using HE = THalfEdge<V, E, P>;

 public:
  HE* const HalfEdge() { return halfEdge; }

  const HE* const HalfEdge() const {
    return const_cast<TEdge*>(this)->HalfEdge();
  }

  void SetHalfEdge(HE* he) { halfEdge = he; }

  bool IsBoundary() const {
    return HalfEdge()->IsBoundary() || HalfEdge()->Pair()->IsBoundary();
  }

  bool IsFree() const {
    return HalfEdge()->IsFree() && HalfEdge()->Pair()->IsFree();
  }

  // clockwise
  // + [he.RotateNext, he.RotateNext.RotateNext, ..., he)
  // + [he.next, he.next.RotateNext, ..., he.pair)
  const std::vector<HE*> OutHEs();
  const std::set<V*> AdjVertices();
  const std::vector<E*> AdjEdges();

 private:
  HE* halfEdge = nullptr;
};
}  // namespace My

#include "TEdge.inl"
