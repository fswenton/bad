#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// This function computes the mean of a vector of doubles called "a"
double m0(vector<double> a)
{
  // This is the sum
  double s = 0.0;

 // Loop through all elements of the array
  for (unsigned int i = 0; i < a.size(); ++i)
  {
    // Add the element to the sum
    s += a[i];
  }

   // The mean is the sum divided by the count---return that
  return s/a.size();

}

// This function computes the minimum value of a vector of doubles called "a"
double m1(vector<double> a)
{

  // First, we sort the array
  sort(a.begin(), a.end());

  // Now we just return the first element, which after sorting is the minimum
  return a[0];

}

// This function computes the maximum value of a vector of doubles called "a"
double m2(vector<double> a)
{

  // First, we sort the array
  sort(a.begin(), a.end());

  // Now we just return the last element, which after sorting is the Maximum
  return a[ a.size() - 1 ];

}

// This function computes the median of a vector of doubles called "a"
double m3(vector<double> a)
{

  // First, we sort the array
  sort(a.begin(), a.end());

  // This bit's a little tricky
  if (a.size() % 2)
  {
    // If we have an odd number of elements, the median is the middle one
    return a[ (a.size() - 1 ) / 2];
  }
  else
  {
    // Otherwise, we average the values of the two middlemost elements
    return 0.5*(a[ a.size() / 2 ] + a[ a.size() / 2 - 1]);
  }

}

// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
vector<double> s2a(string s) {
  istringstream iss(s);

  // "n" is the number of elements in our array, which comes first
  int n;

  iss >> n;

  vector<double> a(n);

  for (int i = 0;
       i < n;
       ++i)
  {
    iss >> a[i];
  }


  return a;

}

// This where the magic happens!
void go(string s)
{

  // Turn our string of input into an array (above)
  vector<double> a = s2a(s);

  // Be polite and give the the user the basic stats on their data
  cout << "Thanks!\n" << "The minimum is " << m1(a) << ",\nthe maximum is " << m2(a) << ",\nthe median is " << m3(a) << ",\nand the mean is " << m0(a) << ".\n\n";

  return;

}

int main(void)
{

  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

  string s;

  while ( getline( cin , s ) ) {

    if ( s.length( ) == 0 )
        break;

    go(s);

  }

  return 0;
}
