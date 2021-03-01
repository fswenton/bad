#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class myVector {
    public:
        vector<double> vect;
        myVector(vector<double> newVect) {
            vect = newVect;
            sort(vect.begin(), vect.end());
        }

        // Takes in a vector and returns the mean
        double mean() {
          double sum = 0.0;
          for (unsigned int i = 0; i < vect.size(); ++i) {
            sum += vect[i];
          }
          return sum/vect.size();
        }

        // Takes in a vector and returns the minimum value
        double min() {
          return vect[0];
        }

        // Takes in a vector and returns the maximum value
        double max() {
          return vect[ vect.size() - 1 ];
        }

        // Takes in a vector and returns the median value
        double median() {
          // If we have an odd number of elements, the median is the middle one
          if (vect.size() % 2) {
            return vect[ (vect.size() - 1 ) / 2];
          }
          // Otherwise, we average the values of the two middlemost elements
          else {
            return 0.5*(vect[ vect.size() / 2 ] + vect[ vect.size() / 2 - 1]);
          }
        }
};

// Takes in a string of numbers separated by white space and returns the numbers in an array.
// Quits if an incorrect number of numbers was inputted
vector<double> s2a(string s) {
  istringstream iss(s);
  int length;
  //head of the stream is the length
  iss >> length;
  vector<double> vect(length);
  int next;
  int index = 0;
  while( iss >> next) {
      vect[index] = next;
      index ++;
  }
  if(index < length) {
      cout << "You didn't enter enough numbers! Run the program and try again. ";
      exit(0);
  }
  if(index > length) {
      cout << "Too many numbers! Run the program and try again. ";
      exit(0);
  }
  return vect;
}

// Prints associated information with the vector
void printInfo(string s) {
  myVector newVect(s2a(s));
  cout << "Thanks!\n" << "The minimum is " << newVect.min() << ",\nthe maximum is " << newVect.max() << ",\nthe median is " << newVect.median() << ",\nand the mean is " << newVect.mean() << ".\n\n";
  return;
}

// Takes in a vector and returns different information associated with the vector
int main(void) {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string userInput;
  while ( getline( cin , userInput ) ) {
    if ( userInput.length( ) == 0 )
        break;
    printInfo(userInput);
  }
  return 0;
}
