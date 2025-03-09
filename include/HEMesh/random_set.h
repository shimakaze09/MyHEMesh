//
// Created by Admin on 09/03/2025.
//

#pragma once

#include <unordered_map>
#include <vector>

namespace My {
template <typename T, class Hasher = std::hash<T>>
class random_set {
 public:
  void insert(const T& e) {
    auto target = Tmap.find(e);
    if (target != Tmap.end())
      return;

    Tmap[e] = Tvec.size();
    Tvec.push_back(e);
  }

  void erase(const T& e) {
    auto target = Tmap.find(e);
    if (target == Tmap.end())
      return;
    auto eIdx = target->second;
    if (eIdx != Tvec.size() - 1) {
      Tmap[Tvec.back()] = eIdx;
      Tvec[eIdx] = Tvec.back();
    }
    Tvec.pop_back();
    Tmap.erase(target);
  }

  auto begin() { return Tvec.begin(); }

  auto begin() const { return Tvec.begin(); }

  auto end() { return Tvec.end(); }

  auto end() const { return Tvec.end(); }

  T& operator[](size_t i) { return Tvec[i]; }

  const T& operator[](size_t i) const { return Tvec[i]; }

  size_t size() const { return Tvec.size(); }

  void reserve(size_t n) {
    Tvec.reserve(n);
    Tmap.reserve(n);
  }

  void clear() {
    Tvec.clear();
    Tmap.clear();
  }

  const std::vector<T>& vec() const { return Tvec; }

  size_t idx(const T& e) const {
    auto target = Tmap.find(e);
    if (target == Tmap.end())
      return -1;
    return target->second;
  }

  bool contains(const T& e) const { return Tmap.find(e) != Tmap.end(); }

  bool empty() const { return Tvec.empty(); }

 private:
  std::unordered_map<T, size_t, Hasher> Tmap;
  std::vector<T> Tvec;
};
}  // namespace My
