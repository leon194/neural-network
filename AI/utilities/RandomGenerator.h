#ifndef UTILITIES_RNG_H
#define UTILITIES_RNG_H
#include<random>
#include<cmath>

namespace utilities {
  typedef float RNType;

  class RNG {
    std::random_device rd;
    std::mt19937 e2;
    std::uniform_real_distribution<> dist;

    public:
    RNG(unsigned min, unsigned max)
      : e2(rd()), dist(min, max)
    {}
    RNType Get() {
      return dist(e2);
    }

    unsigned GetLowerBound() {
      return std::floor(dist(e2));
    }

    unsigned GetUpperBound() {
      return std::ceil(dist(e2));
    }

    RNType GetBoolean() {
      return dist(e2) >= 0.5 ? 1 : 0;
    }
  };

  // Get a vector of randomly selected Size elements from sample space.
  template<typename T>
  std::vector<T> GetRandomizedSet(const std::vector<T> SampleSpace,
                                  unsigned Size) {
    RNG rng(0, SampleSpace.size());
    std::vector<T> RandomizedSet;
    for (size_t sz = 0; sz < Size; ++sz) {
      RandomizedSet.push_back(SampleSpace[rng.GetLowerBound()]);
    }
    return RandomizedSet;
  }
} // namespace utilities

#endif // UTILITIES_RNG_H