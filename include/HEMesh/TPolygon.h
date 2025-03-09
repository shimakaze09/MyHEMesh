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
  template <typename T>
  using ptr = HEMesh_ptr<T, HEMesh<V>>;
  template <typename T>
  using ptrc = ptr<const T>;

 public:
  // external use
  using Ptr = ptr<P>;
  using PtrC = ptrc<P>;

 public:
  const ptr<HE> HalfEdge() { return ptr<HE>(halfEdge, mesh); }

  const ptrc<HE> HalfEdge() const {
    return const_cast<TPolygon*>(this)->HalfEdge();
  }

  void SetHalfEdge(ptr<HE> he) {
    assert(he.mesh == nullptr || mesh == he.mesh);
    halfEdge = he.idx;
  }

  static bool IsBoundary(ptr<P> p) { return p == nullptr; }

  size_t Degree() const {
    return static_cast<int>(const_cast<TPolygon*>(this)->BoundaryHEs().size());
  }

  const std::vector<ptr<HE>> BoundaryHEs() { return HalfEdge()->NextLoop(); }

  const std::vector<ptr<E>> BoundaryEdges();
  const std::vector<ptr<V>> BoundaryVertice();

 private:
  friend class HEMesh<V>;
  HEMesh<V>* mesh = nullptr;

  int halfEdge = -1;
};
}  // namespace My

#include "TPolygon.inl"
