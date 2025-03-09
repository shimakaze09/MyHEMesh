//
// Created by Admin on 09/03/2025.
//

#pragma once

#include "ForwardDecl.h"

namespace My {
template <typename V, typename E, typename P>
class TPolygon {
 private:
  // internal use
  using HE = THalfEdge<V, E, P>;

 public:
  HE* const HalfEdge() { return halfEdge; }

  const HE* const HalfEdge() const {
    return const_cast<TPolygon*>(this)->HalfEdge();
  }

  void SetHalfEdge(HE* he) { halfEdge = he; }

  static bool IsBoundary(P* p) { return p == nullptr; }

  size_t Degree() const {
    return static_cast<int>(const_cast<TPolygon*>(this)->BoundaryHEs().size());
  }

  const std::vector<HE*> BoundaryHEs() { return HalfEdge()->NextLoop(); }

  const std::vector<E*> BoundaryEdges();
  const std::vector<V*> BoundaryVertice();

 private:
  HE* halfEdge = nullptr;
};
}  // namespace My

#include "TPolygon.inl"
