#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Numbers{
public:
    Numbers(string s){
        this->s = s;
    }

    // This where the magic happens!
    void getInfo() {
      // Turn our string of input into an array
      vector<double> a = string2array(s);

      // Be polite and give the the user the basic stats on their data
      cout << "Thanks!\n" << "The minimum is " << minVal(a) << ",\nthe maximum is " << maxVal(a) << ",\nthe median is " << medianVal(a) << ",\nand the mean is " << meanVal(a) << ".\n\n";

      return;
    }
private:
    string s;

    // This function computes the mean of a vector of doubles called "a"
    double meanVal(vector<double> a) {
      // This is the sum
      double sum = 0.0;

      // Loop through all elements of the array
      for (unsigned int i = 0; i < a.size(); ++i)
      {
        // Add the element to the sum
        sum += a[i];
      }

      // The mean is the sum divided by the count---return that
      return sum/a.size();
    }

    // This function computes the minimum value of a vector of doubles called "a"
    double minVal(vector<double> a) {
      return *min_element(a.begin(), a.end());
    }

    // This function computes the maximum value of a vector of doubles called "a"
    double maxVal(vector<double> a) {
      return *max_element(a.begin(), a.end());
    }

    // This function computes the median of a vector of doubles called "a"
    double medianVal(vector<double> a) {
      // First, we sort the array
      sort(a.begin(), a.end());

      // This bit's a little tricky
      if (a.size() % 2) {
        // If we have an odd number of elements, the median is the middle one
        return a[(a.size() - 1 ) / 2];
      } else {
        // Otherwise, we average the values of the two middlemost elements
        return 0.5*(a[a.size() / 2] + a[a.size() / 2 - 1]);
      }
    }

    // This will parse a line of whitespace-separated numbers into an array
    // The first number is the count of numbers, and the rest are the numbers
    vector<double> string2array(string s) {
      istringstream iss(s);

      // "n" is the number of elements in our array, which comes first
      int n;

      iss >> n;

      vector<double> a(n);

      for (int i = 0; i < n; ++i) {
        iss >> a[i];
      }
      return a;
    }
};

int main(void) {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

  string s;

  while (getline(cin , s)) {
    if (s.length() == 0)
      break;
    Numbers nums(s);
    nums.getInfo();
  }
  return 0;
}
