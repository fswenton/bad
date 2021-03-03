#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// This function computes the mean of a vector of doubles called "a"
double mean(vector<double> a){
  double sum = 0.0;
  for (unsigned int i = 0; i < a.size(); ++i){
    sum += a[i];
  }
  return sum/a.size();
}

// This function computes the minimum value of a vector of doubles called "a"
double min(vector<double> a){
  sort(a.begin(), a.end());
  return a[0];
}

// This function computes the maximum value of a vector of doubles called "a"
double max(vector<double> a){
  sort(a.begin(), a.end());
  return a[ a.size() - 1 ];
}

// This function computes the median of a vector of doubles called "a"
double median(vector<double> a){
  sort(a.begin(), a.end());
  if (a.size() % 2){
    // If we have an odd number of elements, the median is the middle one
    return a[(a.size()-1)/2];
  }else{
    // Otherwise, we average the values of the two middlemost elements
    return 0.5*(a[ a.size() / 2 ] + a[ a.size() / 2 - 1]);
  }
}

// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
vector<double> stringToArray(string s) {
  istringstream iss(s);

  // "n" is the number of elements in our array, which comes first
  int n;
  iss >> n;
  vector<double> a(n);
  for (int i = 0;i < n;++i){
    iss >> a[i];
  }
  return a;

}

// This where the magic happens!
void go(string s){
  // Turn our string of input into an array (above)
  vector<double> a = stringToArray(s);
  // Be polite and give the the user the basic stats on their data
  cout << "Thanks!\n" << "The minimum is " << min(a) << ",\nthe maximum is " << max(a) << ",\nthe median is " << median(a) << ",\nand the mean is " << mean(a) << ".\n\n";

  return;
}

int main(void){

  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string s;
  while ( getline( cin , s ) ) {
    if ( s.length( ) == 0)
        break;
    if (s == "0"){
        cout << "Nothing to show!\n";
    }else{
        go(s);
    }
  }
  return 0;
}
