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
  template <typename T>
  using ptr = HEMesh_ptr<T, HEMesh<V>>;
  template <typename T>
  using ptrc = ptr<const T>;

 public:
  // external use
  using Ptr = ptr<E>;
  using PtrC = ptrc<E>;

 public:
  const ptr<HE> HalfEdge() { return ptr<HE>(halfEdge, mesh); }

  const ptrc<HE> HalfEdge() const {
    return const_cast<TEdge*>(this)->HalfEdge();
  }

  void SetHalfEdge(ptr<HE> he) {
    assert(he.mesh == nullptr || mesh == he.mesh);
    halfEdge = he.idx;
  }

  bool IsBoundary() const {
    return HalfEdge()->IsBoundary() || HalfEdge()->Pair()->IsBoundary();
  }

  bool IsFree() const {
    return HalfEdge()->IsFree() && HalfEdge()->Pair()->IsFree();
  }

  // clockwise
  // + [he.RotateNext, he.RotateNext.RotateNext, ..., he)
  // + [he.next, he.next.RotateNext, ..., he.pair)
  const std::vector<ptr<HE>> OutHEs();
  const std::set<ptr<V>> AdjVertices();
  const std::vector<ptr<E>> AdjEdges();

 private:
  friend class HEMesh<V>;
  HEMesh<V>* mesh = nullptr;

  int halfEdge = -1;
};
}  // namespace My

#include "TEdge.inl"
