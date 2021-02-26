#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

namespace vectorStats {
    double mean(vector<double> numbers);
    double min(vector<double> numbers);
    double max(vector<double> numbers);
    double median(vector<double> numbers);
};

namespace statsGen {
    vector<double> parseNumbers(string input);
    void run(vector<double> numbers);
}

int main(void){
    cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces." << endl;
    cout << "Enter a blank line to exit.\n" << endl;

    string inputLine;
    vector<double> numbers;

    while (getline(cin, inputLine)) {
        if ( inputLine.length( ) == 0 ) break;
        numbers = statsGen::parseNumbers(inputLine);
        statsGen::run(numbers);
    }

    return 0;
}

// This where the magic happens! Be polite and give the the user the basic stats on their data.
void statsGen::run(vector<double> numbers){
    if(numbers.size() == 0){
        cout << "There are no stats for zero numbers" << endl;
        return;
    }
    cout << "Thanks!" << endl;
    cout << "The minimum is: " << vectorStats::min(numbers) << "," << endl;
    cout << "the maximum is: " << vectorStats::max(numbers) << "," << endl;
    cout << "the median is: " << vectorStats::median(numbers) << "," << endl;
    cout << "and the mean is: " << vectorStats::mean(numbers) << ".\n" << endl;

    return;
}

// This will parse a line of whitespace-separated numbers into an array.
// The first number is the count of numbers, and the rest are the numbers.
vector<double> statsGen::parseNumbers(string input) {
    istringstream iss(input);
    int n;
    iss >> n;
    vector<double> numbers(n);

    for (int i = 0; i < n; i++){
        iss >> numbers[i];
    }
    return numbers;
}

// This function computes the mean of a vector of doubles called "numbers"
double vectorStats::mean(vector<double> numbers){
    double sum = 0;

    for (unsigned int i = 0; i < numbers.size(); ++i){
        sum += numbers[i];
    }

    return sum/numbers.size();
}

// This function computes the minimum value of a vector of doubles called "numbers"
double vectorStats::min(vector<double> numbers){
    sort(numbers.begin(), numbers.end());

    return numbers[0];
}

// This function computes the maximum value of a vector of doubles called "numbers"
double vectorStats::max(vector<double> numbers){
    sort(numbers.begin(), numbers.end());

    return numbers[ numbers.size() - 1 ];
}

// This function computes the median of a vector of doubles called "numbers"
double vectorStats::median(vector<double> numbers){
  sort(numbers.begin(), numbers.end());

  // If we have an odd number of elements, the median is the middle one
  if (numbers.size() % 2){
    return numbers[ (numbers.size() - 1 ) / 2];
  }
  // Otherwise, we average the values of the two middlemost elements
  else{
    return 0.5*(numbers[ numbers.size() / 2 ] + numbers[ numbers.size() / 2 - 1]);
  }
}
