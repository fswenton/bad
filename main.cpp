#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

double findMean(vector<double> vectorOfNums) {
  double sum = 0.0;

  for(unsigned int i = 0; i < vectorOfNums.size(); ++i) {
    sum += vectorOfNums[i];
  }

  return sum/vectorOfNums.size();
}

double findMin(vector<double> vectorOfNums) {
  sort(vectorOfNums.begin(), vectorOfNums.end());

  return vectorOfNums[0];
}

double findMax(vector<double> vectorOfNums) {
  sort(vectorOfNums.begin(), vectorOfNums.end());

  return vectorOfNums[ vectorOfNums.size() - 1 ];
}

double findMedian(vector<double> vectorOfNums) {
  sort(vectorOfNums.begin(), vectorOfNums.end());

  if (vectorOfNums.size() % 2) {
    // If we have an odd number of elements, the median is the middle one
    return vectorOfNums[ (vectorOfNums.size() - 1 ) / 2];
  }
  else {
    // Otherwise, we average the values of the two middlemost elements
    return 0.5*(vectorOfNums[ vectorOfNums.size() / 2 ] + vectorOfNums[ vectorOfNums.size() / 2 - 1]);
  }
}

// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
vector<double> stringToArray(string inputString) {
  istringstream iss(inputString);

  // "n" is the number of elements in our array, which comes first
  int n;

  iss >> n;

  vector<double> VectorOfNums(n);

  for(int i = 0; i < n; ++i) {
    iss >> VectorOfNums[i];
  }

  return VectorOfNums;
}

void calculateStatistic(string inputString) {

  vector<double> vectorOfNums = stringToArray(inputString);

  cout << "Thanks!\n" << "The minimum is " << findMin(vectorOfNums)
       << ",\nthe maximum is " << findMax(vectorOfNums)
       << ",\nthe median is " << findMedian(vectorOfNums)
       << ",\nand the mean is " << findMean(vectorOfNums) << ".\n\n";

  return;
}

int main() {
  string inputString;

  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

  while(getline(cin, inputString)) {

    if(inputString.length() == 0)
        break;

    calculateStatistic(inputString);
  }

  return 0;
}
