//
// Created by Admin on 09/03/2025.
//

#pragma once

#include "detail/ForwardDecl.h"

namespace My {
template <typename Traits>
class TPolygon {
 public:
  using V = HEMeshTraits_V<Traits>;
  using E = HEMeshTraits_E<Traits>;
  using P = HEMeshTraits_P<Traits>;
  using H = HEMeshTraits_H<Traits>;

 public:
  H* HalfEdge() noexcept { return halfEdge; }

  const H* HalfEdge() const noexcept {
    return const_cast<TPolygon*>(this)->HalfEdge();
  }

  void SetHalfEdge(H* he) noexcept { halfEdge = he; }

  // p == nullptr
  static bool IsBoundary(const P* p) noexcept { return p == nullptr; }

  // number of edges/vertices
  std::size_t Degree() const noexcept {
    assert(HalfEdge());
    return HalfEdge()->PolygonDegree();
  }

  // halfedges : [ he, he.Next(), he.Next().Next(), ..., he)
  HalfEdgeNextView<false, Traits> AdjHalfEdges() {
    return HalfEdge()->NextLoop();
  }

  // halfedges : [ he, he.Next(), he.Next().Next(), ..., he)
  HalfEdgeNextView<true, Traits> AdjHalfEdges() const {
    return HalfEdge()->NextLoop();
  }

 private:
  friend HEMesh<Traits>;

  H* halfEdge{nullptr};
};
}  // namespace My

