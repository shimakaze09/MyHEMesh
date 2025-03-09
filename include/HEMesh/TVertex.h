//
// Created by Admin on 09/03/2025.
//

#pragma once

#include "ForwardDecl.h"

namespace My {
template <typename V, typename E = EmptyEP_E<V>,
          typename P = std::conditional<std::is_same<E, EmptyEP_E<V>>::value,
                                        EmptyEP_P<V>, EmptyP<V, E>>::type>
class TVertex {
 private:
  // internal use
  using HE = THalfEdge<V, E, P>;
  template <typename T>
  using ptr = HEMesh_ptr<T, HEMesh<V>>;
  template <typename T>
  using ptrc = ptr<const T>;

 public:
  // external use
  using Ptr = ptr<V>;
  using PtrC = ptrc<V>;

 private:
  // for _enable_HEMesh
  friend class _enable_HEMesh<V>;
  friend class HEMesh<V>;
  using _E = E;
  using _P = P;

 public:
  const ptr<HE> HalfEdge() { return ptr<HE>(halfEdge, mesh); }

  const ptrc<HE> HalfEdge() const {
    return const_cast<TVertex*>(this)->HalfEdge();
  }

  void SetHalfEdge(ptr<HE> he) {
    assert(he.mesh == nullptr || mesh == he.mesh);
    halfEdge = he.idx;
  }

  bool IsIsolated() const { return halfEdge == -1; }

  bool IsBoundary() const;

  size_t Degree() const { return OutHEs().size(); }

  const std::vector<ptr<HE>> OutHEs() {
    return IsIsolated() ? std::vector<ptr<HE>>() : HalfEdge()->RotateNextLoop();
  }

  const std::vector<ptrc<HE>> OutHEs() const {
    return Const(const_cast<TVertex*>(this)->OutHEs());
  }

  const std::vector<ptr<E>> AdjEdges();

  const std::vector<ptrc<HE>> AdjEdges() const {
    return Const(const_cast<TVertex*>(this)->AdjEdges());
  }

  const std::vector<ptr<V>> AdjVertices();

  const std::vector<ptrc<V>> AdjVertices() const {
    return Const<std::vector, V>(const_cast<TVertex*>(this)->AdjVertices());
  }

  const ptr<HE> FindFreeIncident();

  const ptrc<HE> FindFreeIncident() const {
    return const_cast<TVertex*>(this)->FindFreeOutHE();
  }

  const ptr<HE> HalfEdgeTo(ptr<V> end);

  static const ptr<HE> HalfEdgeAlong(ptr<V> origin, ptr<V> end) {
    return origin->HalfEdgeTo(end);
  }

  const ptr<E> EdgeWith(ptr<V> v);

  static const ptr<E> EdgeBetween(ptr<V> v0, ptr<V> v1) {
    return v0->EdgeWith(v1);
  }

  bool IsConnectedWith(ptr<V> v) const {
    return const_cast<TVertex*>(this)->EdgeWith(v);
  }

  static bool IsConnected(ptr<V> v0, ptr<V> v1) {
    return v0->IsConnectedWith(v1);
  }

 private:
  HEMesh<V>* mesh = nullptr;

  int halfEdge = -1;
};
}  // namespace My

#include "TVertex.inl"
