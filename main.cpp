/*CSCI 0318: Clean-up time assignment
 *Alec Wilson
 *3/1/2021
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class BasicStats {
public:
    string usrInput;
    vector<double> elems;

    // Function mean computes the mean of a vector of doubles called "a"
    double mean(){
      double sum = 0.0;
      for (unsigned int i = 0; i < elems.size(); ++i){
        sum += elems[i];
      }
      return sum/elems.size();
    }

    // Function min computes the minimum value of a vector of doubles called "a"
    double min(){
      sort(elems.begin(), elems.end());
      return elems[0];
    }

    // Function max computes the maximum value of a vector of doubles called "a"
    double max(){
      sort(elems.begin(), elems.end());
      return elems[ elems.size() - 1 ];
    }

    // Function med computes the median of a vector of doubles called "a"
    double med(){
      sort(elems.begin(), elems.end());
      // If/else used to account for different processes if number of elements is odd or even
      // If we have an odd number of elements, the median is the middle one
      if ((elems.size() % 2) > 0){
        return elems[ (elems.size() - 1 ) / 2];
      }
      // Otherwise, we average the values of the two middlemost elements
      else{
        return 0.5*(elems[ elems.size() / 2 ] + elems[ elems.size() / 2 - 1]);
      }
    }

    // Function str2arr will parse a line of whitespace-separated numbers into an array
    // The first number is the count of numbers, and the rest are the numbers
    vector<double> str2arr(string s) {
      istringstream iss(s);
      int numElem;
      iss >> numElem;
      vector<double> arr(numElem);
      for (int i = 0; i < numElem; ++i){
        iss >> arr[i];
      }
      return arr;
    }

    // Function prntOut prints out the statistics generated using the above method and a given string of elements
    void prntOut(){
      cout << "Thanks!\n" << "The minimum is " << min() << ",\nthe maximum is " << max() << ",\nthe median is " << med() << ",\nand the mean is " << mean() << ".\n\n";
      return;
    }

    // Constructor for the BasicStats class assigns the string grabbed from the users input to the class variable usrInput
    BasicStats(string _usrInput){
        usrInput = _usrInput;
        elems = str2arr(_usrInput);
    }
};

int main(void){
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string s;
  while ( getline( cin , s ) ) {
    if ( s.length( ) == 0 ){
        break;
    }
    BasicStats stats(s);
    stats.prntOut();
  }
  return 0;
}
