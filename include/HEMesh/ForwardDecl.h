//
// Created by Admin on 09/03/2025.
//

#pragma once

#include <cassert>

#include <set>
#include <type_traits>
#include <vector>

namespace My {
template <typename V, typename E, typename P>
class THalfEdge;
template <typename V, typename E, typename P>
class TVertex;
template <typename V, typename E, typename P>
class TEdge;
template <typename V, typename E, typename P>
class TPolygon;

template <typename V>
class _enable_HEMesh;
template <typename V>
class HEMesh;

template <typename E, typename P>
class EmptyV;
template <typename V, typename E>
class EmptyP;
template <typename V, typename P>
class EmptyE;

template <typename V>
class EmptyEP_E;
template <typename V>
class EmptyEP_P;

class AllEmpty;

template <template <typename, typename...> class ContainerT, typename ElemT,
          typename... Args>
const ContainerT<const ElemT*> Const(
    const ContainerT<ElemT*, Args...>& container) {
  return ContainerT<const ElemT*>(container.begin(), container.end());
}
}  // namespace My
