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
  H* HalfEdge() noexcept { return halfEdge; }

  const H* HalfEdge() const noexcept {
    return const_cast<TPolygon*>(this)->HalfEdge();
  }

  void SetHalfEdge(H* he) noexcept { halfEdge = he; }

  // p == nullptr
  static bool IsBoundary(const P* p) noexcept { return p == nullptr; }

  // number of edges/vertices
  size_t Degree() const noexcept;

  // halfedges : [ he, he.Next(), he.Next().Next(), ..., he)
  std::vector<H*> AdjHalfEdges() { return HalfEdge()->NextLoop(); }

  // edges : { halfedge.Edge() for halfedge in AdjHalfEdges() }
  std::vector<E*> AdjEdges();

  // vertices : { halfedge.Origin() for halfedge in AdjHalfEdges() }
  std::vector<V*> AdjVertices();

  // adjacent polygons : { halfedge.Pair().Polygon() for halfedge in AdjHalfEdges() }
  // maybe contains boundary polygon (nullptr)
  // use IsBoundary() to find it
  std::vector<P*> AdjPolygons();

 private:
  friend HEMesh<Traits>;

  H* halfEdge{nullptr};
};
}  // namespace My

#include "detail/TPolygon.inl"
