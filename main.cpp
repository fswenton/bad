#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Takes in a vector and returns the mean
double mean(vector<double> vect) {
  double sum = 0.0;
  for (unsigned int i = 0; i < vect.size(); ++i) {
    sum += vect[i];
  }
  return sum/vect.size();
}

// Takes in a vector and returns the minimum value
double min(vector<double> vect) {
  sort(vect.begin(), vect.end());
  return vect[0];
}

// Takes in a vector and returns the maximum value
double max(vector<double> vect) {
  sort(vect.begin(), vect.end());
  return vect[ vect.size() - 1 ];
}

// Takes in a vector and returns the median value
double median(vector<double> vect) {
  sort(vect.begin(), vect.end());
  // If we have an odd number of elements, the median is the middle one
  if (vect.size() % 2) {
    return vect[ (vect.size() - 1 ) / 2];
  }
  // Otherwise, we average the values of the two middlemost elements
  else {
    return 0.5*(vect[ vect.size() / 2 ] + vect[ vect.size() / 2 - 1]);
  }
}

// Takes in a string of numbers separated by white space and returns the numbers in an array
vector<double> s2a(string s) {
  istringstream iss(s);
  int n;
  iss >> n;
  vector<double> vect(n);
  for (int i = 0; i < n; ++i) {
    iss >> vect[i];
  }
  return vect;
}

// Prints associated information with the vector
void printInfo(string s) {
  vector<double> a = s2a(s);
  cout << "Thanks!\n" << "The minimum is " << min(a) << ",\nthe maximum is " << max(a) << ",\nthe median is " << median(a) << ",\nand the mean is " << mean(a) << ".\n\n";
  return;
}

// Takes in a vector and returns different information associated with the vector
int main(void) {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string userInput;
  while ( getline( cin , userInput ) ) {
    if ( userInput.length( ) == 0 )
        break;
    printInfo(userInput);
  }
  return 0;
}
