#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Statistics {
  public:
    double min, max, median, mean;
    vector<double> input;
    void calculateMax(vector<double>);
    void calculateMin(vector<double>);
    void calculateMean(vector<double>);
    void calculateMedian(vector<double>);
    void sortVector(vector<double>);
};

// Input a numeric vector and return the sorted vector from least to greatest
void Statistics::sortVector(vector<double> numberList) {
    sort(numberList.begin(), numberList.end());
    Statistics::input = numberList;
}

// This function computes the mean of a vector of doubles called "a"
void Statistics::calculateMean(vector<double> numberList) {
  double sum = 0.0;

 // Sum all elements of the array
  for (unsigned int i = 0; i < numberList.size(); ++i) {
    sum += numberList[i];
  }
  Statistics::mean = sum/numberList.size();
}

// This function computes the minimum value of a vector of doubles
void Statistics::calculateMin(vector<double> numberList) {
  Statistics::min = numberList[0];
}

// This function computes the maximum value of a vector of doubles
void Statistics::calculateMax(vector<double> numberList) {
  Statistics::max = numberList[numberList.size() - 1];
}

// This function computes the median of a vector of doubles
void  Statistics::calculateMedian(vector<double> numberList) {
  if (numberList.size() % 2) {
    // If we have an odd number of elements, return the middle element
     Statistics::median = numberList[(numberList.size() - 1)/2];
  }
  else {
    // Otherwise, we average the values of the two middlemost elements
    Statistics::median = 0.5*(numberList[numberList.size() / 2 ] + numberList[numberList.size()/2 - 1]);
  }
}

// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers to be added to the array
vector<double> stringToArray(string input) {
  istringstream iss(input);

  int len;
  iss >> len;

  // create array of numbers
  vector<double> numberList(len);

  for (int i = 0; i < len; ++i) {
    iss >> numberList[i];
  }

  return numberList;
}

void compute(string s) {
  // Turn our string of input into an array (above)
  vector<double> numberList = stringToArray(s);

  cout << "\n";
  Statistics stats;
  stats.sortVector(numberList);
  stats.calculateMax(stats.input);
  stats.calculateMean(stats.input);
  stats.calculateMedian(stats.input);
  stats.calculateMin(stats.input);


  cout << "Thanks!\n" << "The minimum is " << stats.min
       << ",\nthe maximum is " << stats.max
       << ",\nthe median is " << stats.median
       << ",\nand the mean is " << stats.mean
       << ".\n\n";

  return;

}

int main(void) {
  cout << "Please enter, on one line, the count of numbers followed"
          " by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

  string input;

  while (getline(cin, input)) {
    if ( input.length( ) == 0 )
        break;
    else
        compute(input);
  }

  return 0;
}
