#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

class Stats {
public:
    string str;
    double mean;
    double min;
    double max;
    double median;
    vector<double> array;

    // constructor
    Stats(string str);

    // public methods
    void parser();
    void getStats();
    void getMean();
    void getMin();
    void getMax();
    void getMedian();
};


// constructor
Stats::Stats(string str) {
    this->str = str;
    // Turn our string of input into an array (above)
    parser();
    // sort ahead to avoid sorting in each method
    sort(array.begin(), array.end());
}


// This where the magic happens!
void Stats::getStats() {
  getMean();
  getMin();
  getMax();
  getMedian();

  // Be polite and give the the user the basic stats on their data
  cout << "Thanks!\n"
       << "The minimum is "     << min
       << ",\nthe maximum is "  << max
       << ",\nthe median is "   << median
       << ",\nand the mean is " << mean
       << ".\n\n";
  return;
}


// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
void Stats::parser() {
  istringstream iss(str);

  // "n" is the number of elements in our array, which comes first
  int n;

  iss >> n;

  vector<double> a(n);

  for (int i = 0; i < n; ++i) {
    iss >> a[i];
  }

  array = a;
  return;
}


// This function computes the mean of a vector of doubles called "a"
void Stats::getMean() {
  // This is the sum
  double sum = 0.0;

 // Loop through all elements of the array
  for (unsigned int i = 0; i < array.size(); ++i) {
    // Add the element to the sum
    sum += array[i];
  }

  // The mean is the sum divided by the count---return that
  // casting the array size as a double for proper division
  mean = sum/(double)array.size();
  return;
}


// This function computes the minimum value of a vector of doubles called "a"
void Stats::getMin() {
  // Now we just return the first element, which after sorting is the minimum
  min = array[0];
  return;
}


// This function computes the maximum value of a vector of doubles called "a"
void Stats::getMax() {
  // Now we just return the last element, which after sorting is the Maximum
  max = array[ array.size() - 1 ];
  return;
}


// This function computes the median of a vector of doubles called "a"
void Stats::getMedian() {
  // This bit's a little tricky
  if (array.size() % 2) {
    // If we have an odd number of elements, the median is the middle one
    median = array[ (array.size() - 1 ) / 2];
  } else {
    // Otherwise, we average the values of the two middlemost elements
    median = 0.5*(array[ array.size() / 2 ] + array[ array.size() / 2 - 1]);
  }
  return;
}


int main(void) {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string s;

  while ( getline(cin, s) ) {
    if ( s.length() == 0 ) {
        break;
    }
    Stats stats(s);
    stats.getStats();
  }

  return 0;
}
