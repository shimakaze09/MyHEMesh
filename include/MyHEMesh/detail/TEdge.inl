//
// Created by Admin on 09/03/2025.
//

#pragma once

namespace My {
template <typename Traits>
const std::vector<HEMeshTriats_H<Traits>*> TEdge<Traits>::OutHalfEdges() {
  std::vector<H*> hes;
  auto he01 = HalfEdge();  // v0 => v1
  for (auto he = he01->RotateNext(); he != he01; he = he->RotateNext())
    hes.push_back(he);
  for (auto he = he01->Next(); he != he01->Pair(); he = he->RotateNext())
    hes.push_back(he);
  return hes;
}

template <typename Traits>
const std::set<HEMeshTriats_V<Traits>*> TEdge<Traits>::AdjVertices() {
  std::set<V*> vertices;
  for (auto e : OutHalfEdges())
    vertices.insert(e->End());
  return vertices;
}

template <typename Traits>
const std::vector<HEMeshTriats_E<Traits>*> TEdge<Traits>::AdjEdges() {
  std::vector<E*> edges;
  for (auto he : OutHalfEdges())
    edges.push_back(he->Edge());
  return edges;
}
}  // namespace My
