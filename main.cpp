#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// calculates mean
double mean(vector<double> numList) {
  double sum = 0.0;
  for (unsigned int i = 0; i < numList.size(); ++i) {
    // Add the element to the sum
    sum += numList[i];
  }
  return sum/numList.size();
}

// calculates min
double min(vector<double> numList) {
  sort(numList.begin(), numList.end());
  return numList[0];
}

// caclulates max
double max(vector<double> numList) {
  sort(numList.begin(), numList.end());
  return numList[ numList.size() - 1 ];
}

// calculates median
double median(vector<double> numList) {
  sort(numList.begin(), numList.end());

  if (numList.size() % 2) {
     // if even number of elements
     return 0.5*(numList[ numList.size() / 2 ] + numList[ (numList.size() / 2) - 1]);

  } else {
     //odd number of elements
     return numList[ (numList.size() - 1 ) / 2];
  }
}

// parses the array to include space bt numbers
// The first number is the count
vector<double> s2a(string s) {
  istringstream iss(s);
  int count;
  iss >> count;
  vector<double> numList(count);
  for (int i = 0;
       i < count;
       ++i) {
    iss >> numList[i];
  }
  return numList;
}

void go(string s) {

  // Turn our string of input into an array (above)
  vector<double> numList = s2a(s);
  // Be polite and give the the user the basic stats on their data
  cout << "Thanks!\n" << "The minimum is " << min(numList) << ",\nthe maximum is " << max(numList) << ",\nthe median is " << median(numList) << ",\nand the mean is " << mean(numList) << ".\n\n";
  return;
}

int main(void) {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string s;
  while ( getline( cin , s ) ) {
    if ( s.length( ) == 0 )
        break;
    go(s);
  }
  return 0;
}
