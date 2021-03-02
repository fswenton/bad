#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// This function computes the mean of a vector of doubles called "array"
double mean(vector<double> array){
  double sum = 0.0;
  for (unsigned int i = 0; i < array.size(); ++i){
    sum += array[i];
  }
  return sum/array.size();
}

// This function computes the minimum value of a vector of doubles called "array" by sorting the array and returning the first index
double min(vector<double> array){
  sort(array.begin(), array.end());
  return array[0];
}

// This function computes the maximum value of a vector of doubles called "array" by sorting the array and returning the last index
double max(vector<double> array){
  sort(array.begin(), array.end());
  return array[array.size() - 1];
}

// This function computes the median of a vector of doubles called "array"
double median(vector<double> array){
  sort(array.begin(), array.end());
  if (array.size() % 2){
    return array[ (array.size() - 1 ) / 2];
  }
  else{
    return 0.5*(array[ array.size() / 2 ] + array[ array.size() / 2 - 1]);
  }
}

// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
vector<double> makeArray(string input) {
  istringstream iss(input);
  int size;
  iss >> size;
  vector<double> array(size);
  for (int i = 0;i < size;++i){
    iss >> array[i];
  }
  return array;
}

//Turns user input into array of numbers and returns basic stats on their data
void giveStats(string input){
  vector<double> array = makeArray(input);
  cout << "Thanks!\n" << "The minimum is " << min(array) << ",\nthe maximum is " << max(array) << ",\nthe median is " << median(array) << ",\nand the mean is " << mean(array) << ".\n\n";
  return;
}

int main(void){
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\n"
"Enter a blank line to exit.\n\n";
  string input;
  while (getline(cin, input)){
    if (input.length() == 0)
        break;
    giveStats(input);
  }
  return 0;
}
