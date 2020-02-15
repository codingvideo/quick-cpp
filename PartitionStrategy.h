#ifndef PartitionStrategy_h
#define PartitionStrategy_h

#include <vector>
using namespace std;

using Data = vector<int>;

class PartitionStrategy {
  public:
    int partition(Data &data, int begin, int end);
  private:
    void swapItems(Data &data, int a, int b);
};

#endif