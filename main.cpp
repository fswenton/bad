#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Changes:
 * - better function names
 * - deleted unnecessary comments and whitespace
 * - restructured as class with statistics as members, which are calculated in methods
 */

// calculates basic statistics for a vector of doubles
class Stats {
public:
    vector<double> data;
    double mean;
    double min;
    double max;
    double median;

    Stats (vector<double> _data): data(_data){
        sort(data.begin(), data.end());
        mean = 0.0;
        min = 0.0;
        max = 0.0;
        median = 0.0;
    };

    friend double calcMean(Stats input) {
        double sum = 0.0;
        for (unsigned int i = 0; i < input.data.size(); ++i) { sum += input.data[i]; }
        return sum/input.data.size();
    }

    friend double calcMin(Stats sorted) { return sorted.data[0]; }

    friend double calcMax(Stats sorted) { return sorted.data[ sorted.data.size() - 1 ]; }

    friend double calcMedian(Stats sorted) {
        if (sorted.data.size() % 2) {
          // If we have an odd number of elements, the median is the middle one
          return sorted.data[ (sorted.data.size() - 1 ) / 2];
        }
        else {
          // Otherwise, we average the values of the two middlemost elements
          return 0.5*(sorted.data[ sorted.data.size() / 2 ] + sorted.data[ sorted.data.size() / 2 - 1 ]);
        }
      }
};

Stats calcStats(vector<double> input) {
    Stats raw (input);
    raw.mean = calcMean(raw);
    raw.min = calcMin(raw);
    raw.max = calcMax(raw);
    raw.median = calcMedian(raw);
    return raw;
}

// This will parse a line of whitespace-separated numbers into an array
vector<double> parseString(string input) {
  istringstream iss(input);

  int num_elements;
  iss >> num_elements;

  vector<double> rawData(num_elements);
  for (int i = 0; i < num_elements; ++i) { iss >> rawData[i]; }
  return rawData;
}

void go(string rawData) {
  Stats processed = calcStats(parseString(rawData));
  cout << "Thanks!\n" << "The minimum is " << processed.min << ",\nthe maximum is " << processed.max << ",\nthe median is " << processed.median << ",\nand the mean is " << processed.mean << ".\n\n";
  return;
}

int main(void) {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string s;
  while ( getline( cin , s ) ) {
    if ( s.length( ) == 0 ) { break; }
    go(s);
  }
  return 0;
}
