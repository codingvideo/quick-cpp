#include "PartitionStrategy.h"

    PartitionStrategy::PartitionStrategy(){}
    PartitionStrategy::PartitionStrategy(function<Compare> compare){
      _compare = compare;
    }
int PartitionStrategy::partition(Data &data, int begin, int end){
  int pivot = data[begin];
  int rightBegin = begin+1;
  for(int i=rightBegin; i<=end; i++){
    if(_compare(data[i], pivot)){
      swapItems(data, i, rightBegin);
      rightBegin++;
    }
  }
  
  int mid = rightBegin-1;
  swapItems(data, begin, mid);
  return mid;
}

void PartitionStrategy::swapItems(Data &data, int a, int b){
  if(a != b){
    int x = data[a];
    data[a] = data[b];
    data[b] = x;
  }
}