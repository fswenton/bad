#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Customized version of the standard vector<double> from STL.
 * Think of this class as a wrapper around vector<double>.
 *
 * Defines methods for computing statistics (min, max, median, mean)
 * for the numerical data contained in vector<double>.
 */

class CustomVector{
public:

    vector<double> numbers;

    CustomVector(std::vector<double> _numbers) {
        numbers = _numbers;
    }

    double mean() {
        double sum = 0.0;

        for (std::vector<double>::iterator numPointer = numbers.begin();
             numPointer != numbers.end();
             ++numPointer) {
            double num = *numPointer;
            sum += num;
        }

        return sum/numbers.size();
    }

    double min() {
        sort(numbers.begin(), numbers.end());
        return numbers[0];
    }

    double max() {
        sort(numbers.begin(), numbers.end());
        return numbers[numbers.size() - 1];
    }

    double median() {
        sort(numbers.begin(), numbers.end());

        // Array has an even number of elements
        if (numbers.size() % 2) {
            return numbers[(numbers.size() - 1) / 2];
        } else { // Array has an odd number of elements
            return 0.5 * (numbers[numbers.size() / 2] + numbers[numbers.size() / 2 - 1]);
        }
    }
};


/*
 * Parse a string of whitespace-separated numbers into a vector.
 *
 * Args:
 *      str: string to be parsed
 * Returns:
 *      numbers: Newly created vector comprised of numbers the user has inputted
 */

vector<double> strToVector(string str) {
    istringstream strStream(str);

    int vecLen = -1;

    strStream >> vecLen; // First digit in input string is count of elements in input array

    vector<double> numbers(vecLen);

    for (int i = 0; i < vecLen; ++i) {
        strStream >> numbers[i];
    }

    return numbers;
}


void computeStatistics(CustomVector numbers) {
    cout << "Thanks!" << endl << endl;
    cout << "The minimum is: " << numbers.min() << endl;
    cout << "The maximum is: " << numbers.max() << endl;
    cout << "The mean is: " << numbers.mean() << endl;
    cout << "The median is: " << numbers.median() << endl << endl;
}


int main(void) {

  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, "
          "separated by spaces.\nEnter a blank line to exit.\n\n";

  string inputStr = "";
  getline(cin, inputStr);

  while (!inputStr.empty()) {

    // Create a CustomVector comprised of numbers the user has inputted
    CustomVector numbers(strToVector(inputStr));

    // Compute and print statistics related to inputted numbers
    computeStatistics(numbers);

    getline(cin, inputStr);

  }

  return 0;
}
