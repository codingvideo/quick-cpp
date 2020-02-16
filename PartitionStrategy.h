#ifndef PartitionStrategy_h
#define PartitionStrategy_h
#include <iostream>
#include <vector>
using namespace std;

using Data = vector<int>;
using Compare = auto (int, int) -> bool;

class PartitionStrategy {
  public:
    PartitionStrategy();
    PartitionStrategy(function<Compare> compare);

    int partition(Data &data, int begin, int end);
  private:
    void swapItems(Data &data, int a, int b);
    function<Compare> _compare;
};

#endif