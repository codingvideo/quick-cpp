#include "Quicksort.h"

Quicksort::Quicksort(PartitionStrategy partitionStrategy){
  strategy = partitionStrategy;
}

void Quicksort::sort(Data &data, int begin, int end){
  if(begin < end){
    int mid = strategy.partition(data, begin, end);
    sort(data, begin, mid-1);
    sort(data, mid+1, end);
  }
}
