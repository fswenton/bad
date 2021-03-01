#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

double mean(vector<double> a) {
  double sum = 0.0;
  for (unsigned int i = 0; i < a.size(); ++i)
  {
    sum += a[i];
  }
  return sum/a.size();

}

double min(vector<double> a) {
  sort(a.begin(), a.end());
  return a[0];
}

double max(vector<double> a) {
  sort(a.begin(), a.end());
  return a[ a.size() - 1 ];
}

double median(vector<double> a) {
  sort(a.begin(), a.end());
  if (a.size() % 2) {
    return a[ (a.size() - 1 ) / 2];
  }
  else {
    return 0.5*(a[ a.size() / 2 ] + a[ a.size() / 2 - 1]);
  }

}

vector<double> convert(string s) {
  istringstream iss(s);
  int n;
  iss >> n;
  vector<double> a(n);
  for (int i = 0;
       i < n;
       ++i) {
    iss >> a[i];
  }
  return a;
}

void go(string s) {
  vector<double> a = convert(s);
  if (a.size() > 0) {
    cout << "Thanks!\n" << "The minimum is " << min(a) << ",\nthe maximum is " << max(a) << ",\nthe median is " << median(a) << ",\nand the mean is " << mean(a) << ".\n\n";
  }
  else {
      cout << "Number is 0. Please enter a bigger number\n";
  }
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
