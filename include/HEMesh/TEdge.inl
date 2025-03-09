//
// Created by Admin on 09/03/2025.
//

#pragma once

namespace My {
template <typename V, typename E, typename P>
const std::vector<HEMesh_ptr<THalfEdge<V, E, P>, HEMesh<V>>>
TEdge<V, E, P>::OutHEs() {
  std::vector<ptr<THalfEdge<V, E, P>>> hes;
  auto he01 = HalfEdge();  // v0 => v1
  for (auto he = he01->RotateNext(); he != he01; he = he->RotateNext())
    hes.push_back(he);
  for (auto he = he01->Next(); he != he01->Pair(); he = he->RotateNext())
    hes.push_back(he);
  return hes;
}

template <typename V, typename E, typename P>
const std::set<HEMesh_ptr<V, HEMesh<V>>> TEdge<V, E, P>::AdjVertices() {
  std::set<ptr<V>> vertices;
  for (auto e : OutHEs())
    vertices.insert(e->End());
  return vertices;
}

template <typename V, typename E, typename P>
const std::vector<HEMesh_ptr<E, HEMesh<V>>> TEdge<V, E, P>::AdjEdges() {
  std::vector<ptr<E>> edges;
  for (auto he : OutHEs())
    edges.push_back(he->Edge());
  return edges;
}
}  // namespace My
