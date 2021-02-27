#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// This function computes the mean of a vector of doubles called "nums"
double mean(vector<double> nums) {
  double sum = 0.0;
 // Loop through all elements of the array
  for (unsigned int i = 0; i < nums.size(); i++) {
    sum += nums[i];
  }
  return (sum/nums.size());
}

// This function computes the minimum value of a vector of doubles called "nums"
double minimum(vector<double> nums) {
  sort(nums.begin(), nums.end());
  return nums[0];

}

// This function computes the maximum value of a vector of doubles called "nums"
double maximum(vector<double> nums) {
  sort(nums.begin(), nums.end());
  return nums[nums.size() - 1];

}

// This function computes the median of a vector of doubles called "nums"
double median(vector<double> nums) {
  sort(nums.begin(), nums.end());
  // If number of elements is odd, return average the two middle elements
  if (nums.size() % 2 != 0) {
    return nums[(nums.size() - 1 ) / 2];
  }
  // If number of elements is even, return middle element
  return (0.5*(nums[nums.size() / 2] + nums[nums.size() / 2 - 1]));

}

// This function will parse a line of whitespace-separated numbers into an array
// The first number is the count of numbers, and the rest are the numbers
vector<double> findNums(string str) {
  istringstream strStream(str);
  int numElem;
  strStream >> numElem;
  vector<double> nums(numElem);
  //Loop through all elements in the string and parse them into a vector
  for (int i = 0; i < numElem; i++) {
    strStream >> nums[i];
  }
  return nums;
}

// This function outputs information regarding our sequence of numbers
void info(vector<double> nums) {
  cout << "The minimum is " << minimum(nums) << ",\nthe maximum is " << maximum(nums) << ",\nthe median is " << median(nums) << ",\nand the mean is " << mean(nums) << ".\n\n";
  return;
}

int main() {
  cout << "Please enter, on one line, the count of numbers followed by the numbers themselves, separated by spaces.\nEnter a blank line to exit.\n\n";
  string str;
  getline(cin,str);
  //Skip rest of program if string is empty
  if (!(str.empty())) {
    vector<double> nums = findNums(str);
    info(nums);
  }
  return 0;
}
