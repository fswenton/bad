#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class NumberInterpreter{
    private:
        vector<double> numbers;
        bool sorted;

        double mean();
        double min();
        double max();
        double median();
        void sortSelf(){ sort(numbers.begin(), numbers.end()); sorted = true; };
    public:
        NumberInterpreter(string x);
        void outputStats();
};

int main(void){
    cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces." << endl;
    cout << "Enter a blank line to exit.\n" << endl;

    string inputLine;

    while (getline(cin, inputLine)) {
        if ( inputLine.empty()) break;
        NumberInterpreter numbers(inputLine);
        numbers.outputStats();

    }

    return 0;
}

// This will parse a line of whitespace-separated numbers into an array.
// The first number is the count of numbers, and the rest are the numbers.
NumberInterpreter::NumberInterpreter(string input) {
    istringstream iss(input);
    int n;
    iss >> n;
    vector<double> parsedNumbers(n);

    for (int i = 0; i < n; i++){
        iss >> parsedNumbers[i];
    }
    sorted = false;
    numbers = parsedNumbers;
}

// This where the magic happens! Be polite and give the the user the basic stats on their data.
void NumberInterpreter::outputStats(){
    if(numbers.empty()){
        cout << "There are no stats for zero numbers" << endl;
        return;
    }
    cout << "Thanks!" << endl;
    cout << "The minimum is: " << min() << "," << endl;
    cout << "the maximum is: " << max() << "," << endl;
    cout << "the median is: " << median() << "," << endl;
    cout << "and the mean is: " << mean() << ".\n" << endl;

    return;
}

// This function computes the mean of a vector of doubles called "numbers"
double NumberInterpreter::mean(){
    double sum = 0;

    for (unsigned int i = 0; i < numbers.size(); ++i){
        sum += numbers[i];
    }

    return sum/numbers.size();
}

// This function computes the minimum value of a vector of doubles called "numbers"
// If the vector is already sorted from low to high then set preSorted to true to reduce computation
double NumberInterpreter::min(){
    if(!sorted) sortSelf();

    return numbers[0];
}

// This function computes the maximum value of a vector of doubles called "numbers"
// If the vector is already sorted from low to high then set preSorted to true to reduce computation
double NumberInterpreter::max(){
    if(!sorted) sortSelf();

    return numbers[ numbers.size() - 1 ];
}

// This function computes the median of a vector of doubles called "numbers"
// If the vector is already sorted from low to high then set preSorted to true to reduce computation
double NumberInterpreter::median(){
  if(!sorted) sortSelf();

  // If we have an odd number of elements, the median is the middle one
  if (numbers.size() % 2){
    return numbers[ (numbers.size() - 1 ) / 2];
  }
  // Otherwise, we average the values of the two middlemost elements
  else{
    return 0.5*(numbers[ numbers.size() / 2 ] + numbers[ numbers.size() / 2 - 1]);
  }
}
