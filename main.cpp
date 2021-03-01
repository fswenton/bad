// Jiaqi Li
// CSCI318 Assignment 1 Clean-up

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// class Bad with instance variable that is a number array
class Bad {
public:
    vector<double> numarray;

    // constructor
    Bad(vector<double> a): numarray(a) { }

    // methods
    double getMean();
    double getMin();
    double getMax();
    double getMedian();
};


// This method computes the mean of a vector of doubles called "a"
double Bad::getMean() {
    // This is the sum
    double sum = 0.0;

    // Loop through all elements of the array
    for (unsigned int i = 0; i < numarray.size(); ++i) {
        // Add the element to the sum
        sum += numarray[i];
    }

    // The mean is the sum divided by the count---return that
    return sum/numarray.size();
}

// This method computes the minimum value of a vector of doubles called "a"
double Bad::getMin() {

    // Sort the array
    sort(numarray.begin(), numarray.end());

    // Now we just return the first element, which after sorting is the minimum
    return numarray[0];

}

// This method computes the maximum value of a vector of doubles called "a"
double Bad::getMax() {

    // Sort the array
    sort(numarray.begin(), numarray.end());

    // Now we just return the last element, which after sorting is the Maximum
    return numarray[ numarray.size() - 1 ];

}

// This method computes the median of a vector of doubles called "a"
double Bad::getMedian() {

    // Sort the array
    sort(numarray.begin(), numarray.end());

    if (numarray.size() % 2 == 0) {
        // For even number of elements, average the values of the two middlemost elements
        return 0.5*(numarray[ numarray.size() / 2 ] + numarray[ numarray.size() / 2 - 1]);
    }
    else {
        // Otherwise, the median is the middle one
        return numarray[ (numarray.size() - 1 ) / 2];
    }
}

// This function parses a line of whitespace-separated numbers and return an object of Bad class
// The first number is the count of numbers, and the rest are the numbers
Bad s2a(string s) {
    istringstream iss(s);

    // n is the number of elements in our array, which comes first
    int n;

    iss >> n;

    vector<double> a(n);

    for (int i = 0; i < n; ++i) {
        iss >> a[i];
    }
    return Bad(a);
}

int main(void) {

    cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

    string s;

    while ( getline(cin , s) ) {

        if ( s.length() == 0 )
            break;

        Bad bad = s2a(s);

        cout << "Thanks!\n" << "The minimum is " << bad.getMin() << ",\nthe maximum is " << bad.getMax() << ",\nthe median is " << bad.getMedian() << ",\nand the mean is " << bad.getMean() << ".\n\n";

    }
    return 0;
}
