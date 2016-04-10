#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "smoothing_filter.hpp"

using namespace std;

int main() {
  SmoothingFilter *filter = new SmoothingFilter();

  ifstream file_in("/home/eiger824/Programming/MatlabFiltering/data/raw_percentages.log");
  string line;
  vector<unsigned int>raw_samples;
  vector<unsigned int>filtered_samples;

  cout << "Opening file.." << endl;
  if (file_in.is_open()) {
    cout << "File open!" << endl;
    while (getline (file_in, line)) {
      cout << "Reading value: " << line << endl;
      int value = atoi(line.c_str()); 
      raw_samples.push_back(value);
      cout << "size now is: " << raw_samples.size() << endl;
    }
  }
  file_in.close();


  for (unsigned i = 0; i < raw_samples.size(); ++i) {
    filtered_samples.push_back(filter->smooth(raw_samples.at(i)));
  }

  for (unsigned i = 0; i < raw_samples.size(); ++i) {
    cout << raw_samples.at(i) << "-----" << filtered_samples.at(i) << endl;
  }
  
  delete filter;
  return 0;
}
