#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <limits>
using namespace std;

using Data = vector<int>;
using Words = vector<string>;

void quicksort(Data &data, int begin, int end);
int partition(Data &data, int begin, int end);
void swapItems(Data &data, int a, int b);
template <typename T> void printVector(vector<T> &data);
Data getInputData(string message);
Words splitWords(const string &str);

int main() 
{  
  Data data = getInputData("Enter numbers: ");
  quicksort(data, 0, data.size()-1);
  printVector(data);
}

void quicksort(Data &data, int begin, int end){
  if(begin < end){
    // sort the data left and right    
    int mid = partition(data, begin, end);
    // break the data in half, and then
    // repeat the process recursively
    // on each side
    quicksort(data, begin, mid-1);
    quicksort(data, mid+1, end);
  }
}

int partition(Data &data, int begin, int end){
  // make the first item as the pivot
  int pivot = data[begin];
  // make everything from the second item as the right side
  int right_begin = begin+1;
  // through the loop, grow the left side
  // with items smaller than the pivot
  for(int i=right_begin; i<=end; i++){
    if(data[i] < pivot){
      swapItems(data, i, right_begin);
      right_begin++;
    }
  }
  // put the pivot in the middle
  int mid = right_begin-1;
  swapItems(data, begin, mid);
  return mid;
}

void swapItems(Data &data, int a, int b){
  if(a != b){
    int x = data[a];
    data[a] = data[b];
    data[b] = x;
  }
}

template <typename T>
void printVector(vector<T> &data){
  for(auto item : data)
  {
    cout << item << " ";
  }
  cout << endl;
}

Data getInputData(string message){
  // 1. prompt input
  std::cout << message;
  // 2. get input
  std::string str;
  std::getline(std::cin, str);
  // 3. convert to vector (dynamic array)
  Words list = splitWords(str);
  // 4. convert to integers using a loop
  Data out;
  for(auto item : list)
  {
    out.push_back(stoi(item));
  }
  return out;
}

Words splitWords(const string &str) {
  Words words;
  istringstream stream(str);
  string item;
  while (getline(stream, item, ' ')) {
    words.push_back(item);
  }
  return words;
}