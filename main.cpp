#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Statistics{
    bool isSorted = false;
    vector<double> array;
public: 
    // This will parse a line of whitespace-separated numbers into an array
    // The first number is the count of numbers, and the rest are the numbers
    Statistics(string s) {
        istringstream iss(s);
        int n; //Number of elements is first element
        iss >> n;
        array.resize(n);
        for (int i = 0;i < n;++i){
            iss >> array[i];
        }
    }
    
    void sortIfNeeded(){
        if (isSorted) return;
        sort(array.begin(), array.end());
        isSorted = true;
        return;
    }

    // This function computes the mean of a vector of doubles called "a"
    double mean(){
      double sum = 0;
      for (unsigned int i = 0; i < array.size(); ++i){
        sum += array[i];
      }
      return sum/array.size();
    }

    // This function computes the minimum value of a vector of doubles called "a"
    double min(){
      sortIfNeeded();
      return array[0];
    }

    // This function computes the maximum value of a vector of doubles called "a"
    double max(){
      sortIfNeeded();
      return array[array.size() - 1];
    }

    // This function computes the median of a vector of doubles called "a"
    double median(){
      sortIfNeeded();
      if (array.size() % 2){
        // If we have an odd number of elements, the median is the middle one
        return array[(array.size() - 1)/2];
      }else{
        // Otherwise, we average the values of the two middlemost elements
        return 0.5*(array[array.size()/2] + array[array.size()/2 - 1]);
      }
    }

    // This where the magic happens!
    void printStats(){
      cout << "Thanks!\n" 
           << "The minimum is " << min() 
           << ",\nthe maximum is " << max() 
           << ",\nthe median is " << median() 
           << ",\nand the mean is " << mean() << ".\n\n";
      return;
    }

};


int main(void){
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string s;
  while (getline(cin,s)){
    if (s.length() == 0)
        break;
    if (s == "0")
        cout << "Nothing to show!\n";
    else{ 
        Statistics stats(s);
        stats.printStats();
    }
  }
  return 0;
}
