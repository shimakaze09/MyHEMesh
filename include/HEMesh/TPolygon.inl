//
// Created by Admin on 09/03/2025.
//

#pragma once

namespace My {
template <typename V, typename E, typename P>
const std::vector<HEMesh_ptr<E, HEMesh<V>>> TPolygon<V, E, P>::BoundaryEdges() {
  std::vector<ptr<E>> edges;
  for (auto he : BoundaryHEs())
    edges.push_back(he->Edge());
  return edges;
}

template <typename V, typename E, typename P>
const std::vector<HEMesh_ptr<V, HEMesh<V>>>
TPolygon<V, E, P>::BoundaryVertice() {
  std::vector<ptr<V>> vertices;
  for (auto he : BoundaryHEs())
    vertices.push_back(he->Origin());
  return vertices;
}
}  // namespace My
