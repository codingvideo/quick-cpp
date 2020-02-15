#ifndef Quicksort_h
#define Quicksort_h

#include <vector>
#include "PartitionStrategy.h"
using namespace std;

using Data = vector<int>;

class Quicksort {
  public:
    Quicksort(PartitionStrategy partitionStrategy);
    void sort(Data &data, int begin, int end);

  private:
    PartitionStrategy strategy;
};

#endif