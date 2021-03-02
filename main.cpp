#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


class NumberList {
public:
    vector<double> sorted;
    int listSize;

    NumberList(vector<double> _a):sorted(_a), listSize(_a.size()) {
        sort(sorted.begin(), sorted.end());
    }

    double mean() {
        double s = 0.0;
        for ( int i = 0; i < listSize; ++i) {
            s += sorted[i];
        }
        return s/listSize;
    }

    double minimum() {
        return sorted[0];
    }

    double maximum() {
        return sorted[listSize-1];
    }

    double median() {
        if (listSize % 2) {
            return sorted[(listSize-1)/2];
        }
        else {
            int mid = listSize/2;
            return 0.5*(sorted[mid] + sorted[mid+1]);
        }
    }

};

// This where the magic happens!
void go(string userInput) {
    istringstream iss(userInput);

    // "n" is the number of elements in our array, which comes first
    int count;

    iss >> count; //remove n from the head of the stream

    vector<double> unsorted(count); // new vector a will be of size n

    int num;
    int i = 0;
    while (iss >> num) {
        if (i == count) {
            cout << "The list you gave is too long! \nTry again and don't lie to me this time. \n\n";
            return;
        }
        else {
            cout << i <<"th item: ";
            unsorted[i] = num;
            cout << unsorted[i] << "\n";
            ++i;
        }
    }

    if (i<count){
        cout << "The list you gave isn't long enough! \nTry again and don't lie to me this time. \n\n";
        return;
    }


    NumberList userInputList = NumberList(unsorted);

  // Be polite and give the the user the basic stats on their data
  cout << "Thanks!\n" << "The minimum is " << userInputList.minimum() << ",\nthe maximum is " << userInputList.maximum() << ",\nthe median is " << userInputList.median() << ",\nand the mean is " << userInputList.mean() << ".\n\n";

  return;

}

int main(void) {

  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

  string userInput;

  while ( getline( cin , userInput ) ) {
    if ( userInput.length( ) == 0 )
        break;

    go(userInput);

  }

  return 0;
}
