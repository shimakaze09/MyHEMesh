//
// Created by Admin on 09/03/2025.
//

#pragma once

#include "detail/ForwardDecl.h"

namespace My {
template <typename Traits>
class TPolygon {
 public:
  using V = HEMeshTriats_V<Traits>;
  using E = HEMeshTriats_E<Traits>;
  using P = HEMeshTriats_P<Traits>;
  using H = HEMeshTriats_H<Traits>;

 public:
  H* const HalfEdge() { return halfEdge; }

  const H* const HalfEdge() const {
    return const_cast<TPolygon*>(this)->HalfEdge();
  }

  void SetHalfEdge(H* he) { halfEdge = he; }

  static bool IsBoundary(const P* p) { return p == nullptr; }

  size_t Degree() const {
    return static_cast<int>(const_cast<TPolygon*>(this)->AdjHalfEdges().size());
  }

  const std::vector<H*> AdjHalfEdges() { return HalfEdge()->NextLoop(); }

  const std::vector<E*> AdjEdges();

  const std::vector<V*> AdjVertices();

  const std::vector<P*> AdjPolygons();

 private:
  friend class HEMesh<Traits>;

  H* halfEdge{nullptr};
};
}  // namespace My

#include "detail/TPolygon.inl"
