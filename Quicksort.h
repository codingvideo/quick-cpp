#ifndef Quicksort_h
#define Quicksort_h

#include <vector>
using namespace std;

using Data = vector<int>;

class Quicksort {
  public:
    void sort(Data &data, int begin, int end);
  private:
    int partition(Data &data, int begin, int end);
    void swapItems(Data &data, int a, int b);
};

#endif