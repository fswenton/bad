#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// This function computes the mean of a vector of doubles called "a"
double mean(vector<double> a) {

    double sum = 0.0;
    for (unsigned int i = 0; i < a.size(); ++i) {
        sum += a[i];
    }
    return sum/a.size();
}

// This function computes the minimum value of a vector of doubles called "a"
double min(vector<double> a) {

    sort(a.begin(), a.end());
    return a[0];
}

// This function computes the maximum value of a vector of doubles called "a"
double max(vector<double> a) {

    sort(a.begin(), a.end());
    return a[ a.size() - 1 ];
}

// This function computes the median of a vector of doubles called "a"
double median(vector<double> a) {

    sort(a.begin(), a.end());
    if (a.size() % 2) {
        return a[ (a.size() - 1 ) / 2];
    }
    else {
        return 0.5*(a[ a.size() / 2 ] + a[ a.size() / 2 - 1]);
    }
}

// This will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
vector<double> stringToArray(string s) {

    istringstream iss(s);
    int n;
    iss >> n;
    vector<double> a(n);
    for (int i = 0; i < n; ++i) {
        iss >> a[i];
    }
    return a;
}

int main(void) {

    cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, "
            "separated by spaces.\nEnter a blank line to exit.\n\n";
    string s;
    while ( getline( cin , s ) ) {
        printf("IN WHILE\n");
        if ( s.length( ) == 0 ) {
            break;
        }
        vector<double> a = stringToArray(s);
        cout << "Thanks!\n" << "The minimum is " << min(a) << ",\n"
                "the maximum is " << max(a) << ",\n"
                "the median is " << median(a) << ",\n"
                "and the mean is " << mean(a) << ".\n\n";
    }
    printf("OUT WHILE\n");
    return 0;
}
