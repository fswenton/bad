#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

double getMeanAverage(vector<double> arr) {

    double sum = 0;
    for (unsigned int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    return sum/arr.size();
}

double getMin(vector<double> arr) {

    sort(arr.begin(), arr.end());
    // array is now from least to greatest, first element is min
    return arr[0];
}

double getMax(vector<double> arr) {

    sort(arr.begin(), arr.end());
    // array is now from least to greatest, last element is max
    return arr[ arr.size() - 1 ];
}

double getMedian(vector<double> arr) {

    sort(arr.begin(), arr.end());

    if (arr.size() % 2 == 1) {
        // If we have an odd number of elements, the median is the middle one
        return arr[ (arr.size() - 1 ) / 2];

    } else {
        // Otherwise, we average the values of the two middlemost elements
        return 0.5*(arr[ arr.size() / 2 ] + arr[ arr.size() / 2 - 1]);
    }
}

// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
vector<double> parseDoubleArray(string input) {

    istringstream iss(input);
    int inputLength;
    iss >> inputLength;

    vector<double> arr(inputLength);
    for (int i = 0; i < inputLength; ++i) {
        iss >> arr[i];
    }
    return arr;
}


void getBasicStats(string input) {

    vector<double> arr = parseDoubleArray(input);
    if (arr.size() < 2) {
        cout << "Array is too small! Please enter array of at least size 1\n" << endl;
    } else {
        cout << "Thanks!\n" << "The minimum is " << getMin(arr) << ",\nthe maximum is " << getMax(arr) << ",\nthe median is " << getMedian(arr) << ",\nand the mean is " << getMeanAverage(arr) << ".\n" << endl;
    }
    return;
}


int main(void) {
    cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n";
    string input;

    while(getline(cin, input)) {
        if (input.length() == 0)
            break;
        getBasicStats(input);
    }
}


