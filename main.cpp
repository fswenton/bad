#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/* A simple statstic program that calculates
 * mean, max, minimum, and median of a list of numbers */

class CalcStat {
public:
    vector<double> numList;

    // Construtor
    CalcStat(string inputStr) {
        stringToArray(inputStr);
    }

    // Methods
    double mean() {
        double sum = 0.0;

        for(unsigned int i = 0; i < numList.size(); ++i) {
          sum += numList[i];
        }

        return sum/numList.size();
    }

    double min() {
      return numList[0];
    }

    double max() {
      return numList[numList.size() - 1];
    }

    double median() {
      if (numList.size() % 2) {
        // If we have an odd number of elements, the median is the middle one
        return numList[(numList.size() - 1 ) / 2];
      }
      else {
        // Otherwise, we average the values of the two middlemost elements
        return 0.5*(numList[numList.size() / 2] + numList[numList.size() / 2 - 1]);
      }
    }

private:
    // This will parse a line of whitespace-separated numbers into an array
    // The first number is the count of numbers, and the rest are the numbers
    void stringToArray(string inputStr) {
      istringstream strStream(inputStr);
      int numElements;

      strStream >> numElements;
      vector<double> inputList(numElements);

      for(int i = 0; i < numElements; ++i) {
        strStream >> inputList[i];
      }

      sort(inputList.begin(), inputList.end());

      numList = inputList;
    }
};

int main() {
  string inputStr;

  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

  while(getline(cin, inputStr)) {
    if(inputStr.length() == 0)
        break;

    CalcStat getStat(inputStr);

    cout << "Thanks!\n" << "The minimum is " << getStat.min()
         << ",\nthe maximum is " << getStat.max()
         << ",\nthe median is " << getStat.median()
         << ",\nand the mean is " << getStat.mean() << ".\n\n";
  }

  return 0;
}
