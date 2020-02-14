#include "Quicksort.h"

void Quicksort::sort(Data &data, int begin, int end){
  if(begin < end){
    int mid = partition(data, begin, end);
    sort(data, begin, mid-1);
    sort(data, mid+1, end);
  }
}

int Quicksort::partition(Data &data, int begin, int end){
  int pivot = data[begin];
  int right_begin = begin+1;
  for(int i=right_begin; i<=end; i++){
    if(data[i] < pivot){
      swapItems(data, i, right_begin);
      right_begin++;
    }
  }
  
  int mid = right_begin-1;
  swapItems(data, begin, mid);
  return mid;
}

void Quicksort::swapItems(Data &data, int a, int b){
  if(a != b){
    int x = data[a];
    data[a] = data[b];
    data[b] = x;
  }
}