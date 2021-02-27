#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class BasicStats{
public:
    string str;

    BasicStats(string in_str){
        // Turn our string of input into an array (above)
        stringToArray(in_str);
    }

    double mean(){
      double sum = 0.0;

      for (unsigned int i = 0; i < array.size(); i++){
        sum += array[i];
      }

      return sum/array.size();
    }

    double min(){
      sort(array.begin(), array.end());
      return array[0];
    }

    double max(){
      sort(array.begin(), array.end());
      return array[ array.size() - 1 ];
    }

    double median(){
      sort(array.begin(), array.end());

      if (array.size() % 2){
         //if even
        return array[ (array.size() - 1 ) / 2];
      } else {
        // if odd, we average the values of the two middlemost elements
        return 0.5*(array[ array.size() / 2 ] + array[ array.size() / 2 - 1]);
      }

    }


private:
    vector<double> array;

    // This will parse a line of whitespace-separated numbers into an array
    // The first number is the count of numbers, and the rest are the numbers
    void stringToArray(string in_str) {
      istringstream stream(in_str);
      int numElts;

      stream >> numElts;

      vector<double> createArray(numElts);

      for (int i = 0; i < numElts; i++) {
        stream >> createArray[i];
      }

      array = createArray;
    }

};


int main(void)
{

  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";

  string str;

  while ( getline( cin , str ) ) {

    if ( str.length( ) == 0 )
        break;

    BasicStats stats(str);
    double min = stats.min();
    double max = stats.max();
    double median = stats.median();
    double mean = stats.mean();

    cout << "Thanks!\n" << "The minimum is " << min << ",\nthe maximum is " << max << ",\nthe median is " << median<< ",\nand the mean is " << mean << ".\n\n";

  }


//  return;

  return 0;
}
