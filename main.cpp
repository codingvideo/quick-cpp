#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <limits>
#include "Quicksort.h"
#include "PartitionStrategy.h"
using namespace std;

using Data = vector<int>;
using Words = vector<string>;

template <typename T> void printVector(vector<T> &data);
Data getInputData(string message);
Words splitWords(const string &str);

int main() 
{  
  Data data = getInputData("Enter numbers: ");
  PartitionStrategy partition{};
  Quicksort quicksort{ partition };
  quicksort.sort(data, 0, data.size()-1);
  printVector(data);
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