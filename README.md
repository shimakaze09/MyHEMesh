# MyHEMesh

> **My** **H**alf-**E**dge **Mesh**

[![repo-size](https://img.shields.io/github/languages/code-size/shimakaze09/MyHEMesh?style=flat)](https://github.com/shimakaze09/MyHEMesh/archive/main.zip) [![tag](https://img.shields.io/github/v/tag/shimakaze09/MyHEMesh)](https://github.com/shimakaze09/MyHEMesh/tags) [![license](https://img.shields.io/github/license/shimakaze09/MyHEMesh)](LICENSE)

an elegant, high-performance, user-friendly halfedge data structure

## Feature

- Elegant: store **topology** only
- High-performance: **cache-friendly**
- User-friendly: you can customize **Vertex, Edge, Polygon and Half-Edge** class

## Usage

### default Vertex, Edge, Polygon and Half-Edge class

```c++
#include <MyHEMesh/HEMesh.h>

#include <vector>

int main() {
    std::vector<size_t> indices = {0,1,2,0,2,3};
    My::HEMesh<> mesh(indices, 3);
    // ...
}
```

### custom Vertex, Edge, Polygon and Half-Edge class

```c++
#include <MyHEMesh/HEMesh.h>

#include <vector>

using namespace My;

// forward declaration
class V;
class E;
class P;
class H;
using Traits_VEPH = HEMeshTraits<V, E, P, H>;
// custom vertex, edge, polygon and half-edge class
class V : public TVertex  <Traits_VEPH> { /*...*/ }
class E : public TEdge    <Traits_VEPH> { /*...*/ }
class P : public TPolygon <Traits_VEPH> { /*...*/ }
class H : public THalfEdge<Traits_VEPH> { /*...*/ }
int main() {
    std::vector<size_t> indices = {0,1,2,0,2,3};
    HEMesh<Traits_VEPH> mesh(indices, 3);
    // ...
}
```

## Tips

- customized class `T` should `std::is_default_constructibl`
- you can get vertex, edge, polygon and halfedge type by `HEMesh<...>::V/E/P/HE`
- use `Empty*_*` type if you don't need to custom some class, see [Empty.h](include/MyHEMesh/Empty.h) for more details.

  > **example**
  >
  > if you just need to custom vertex and polygon, then you can do like this
  >
  > ```c++
  > class V;
  > class P;
  > using Traits_VP = HEMeshTriats_EmptyEH<V, P>;
  > class V : public TVertex <Traits_VP> { /*...*/ }
  > class P : public TPolygon<Traits_VP> { /*...*/ }
  > 
  > int main() {
  >     std::vector<size_t> indices = {0,1,2,0,2,3};
  >     HEMesh<Traits_VP> mesh(indices, 3);
  >     // ...
  > }
  > ```
- boundary polygon is `nullptr` or use `HEMesh<...>::P::IsBoundary(polygon)` to avoid literal value
