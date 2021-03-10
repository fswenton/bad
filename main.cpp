#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class ArrayStatistics {
    bool dataIsSorted;
    vector<double> data;

public:
    // This will parse a line of whitespace-separated numbers into an array
    // The first number is the count of numbers, and the rest are the numbers
    ArrayStatistics(string s):dataIsSorted(false) {
        istringstream inputFromString(s);
        int n; inputFromString >> n;
        data.resize(n);
        for (int i = 0; i < n; ++i) inputFromString >> data[i];
    }

    void maybeSortData() {
        if (dataIsSorted) return;
        sort(data.begin(), data.end());
        dataIsSorted = true;
    }

    double mean() const {
      double sum = 0.0;
      for (unsigned int i = 0; i < data.size(); ++i)
        sum += data[i];

      return sum/data.size();
    }

    double minimum() {
      maybeSortData();
      return data[0];
    }


    double maximum() {
      maybeSortData();
      return data[data.size()-1];
    }

    double median() {
      maybeSortData();
      if (data.size() % 2)
        return data[(data.size()-1)/2];
      else
        return 0.5*(data[data.size()/2] + data[data.size()/2 - 1]);
    }

    void generateReport(ostream &os) {
        if (data.size()==0) {
            cout << "No data to report on.\n";
            return;
        }

        os << "Thanks!\n" << "The minimum is " << minimum() << ",\n"
           << "the maximum is " << maximum() << ",\n"
           << "the median is " << median() << ",\n"
           << "and the mean is " << mean() << ".\n\n";
    }
};

int main(void) {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

  string line;
  while (getline(cin, line)) {
    if (line.length()==0)
        break;

    ArrayStatistics stats(line);
    stats.generateReport(cout);
  }

  return 0;
}
