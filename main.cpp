#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

double mean(vector<double> a) {
  double sum = 0.0;
  for (unsigned int i = 0; i < a.size(); ++i) {
    sum += a[i];
  }
  return sum/a.size();
}

double min(vector<double> a) {
  return a[0];
}

double max(vector<double> a) {
  return a[a.size() - 1];
}

double median(vector<double> a) {
  // If we have an odd number of elements, the median is the middle one
  if (a.size() % 2 != 0)
    return a[(a.size()-1) / 2];
  // Otherwise, we average the values of the two middlemost elements
  else
    return 0.5*(a[a.size() / 2] + a[a.size() / 2 - 1]);
}

// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
vector<double> makeArray(string s) {
  istringstream iss(s);
  int count;
  iss >> count;
  vector<double> a(count);

  for (int i = 0; i < count; ++i) {
    iss >> a[i];
  }
  return a;
}

int main(void) {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, "
  "separated by spaces.\nEnter a blank line to exit.\n\n";
  string s;

  while (getline(cin, s)) {
    if (s.length() == 0)
        break;
    vector<double> a = makeArray(s);
    sort(a.begin(), a.end());
    cout << "Thanks!\n" << "The minimum is " << min(a) << ",\nthe maximum is " << max(a) <<
            ",\nthe median is " << median(a) << ",\nand the mean is " << mean(a) << ".\n\n";
  }
  return 0;
}
