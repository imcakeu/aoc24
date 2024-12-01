#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// Simple sorting algorithm to figure out the ascending order
// of the list values.
void selection_sort(vector<int> &arr) {
     int n = arr.size();

     for(int i=0; i<n-1; i++) {
          int min_idx = i;

          for(int j=i+1; j<n; j++) {
               if(arr[j] < arr[min_idx]) {
                    min_idx = j;
               }
          }

          swap(arr[i], arr[min_idx]);
     }
}

void print_array(vector<int> &arr) {
     for(int &val : arr) {
          cout << val << " ";
     }
     cout << endl;
}

vector<int> calc_distances(vector<int> &left, vector<int> &right) {
     vector<int> distances = {};

     // We suppose that both arrays are of same size.
     for(int i=0; i<left.size(); i++) {
          // To find the distance between two values we substract the smaller value from the bigger value.
          int value = left[i] - right[i];
          if(right[i] > left[i])
               value = right[i] - left[i];

          // We add the distance to the array
          distances.push_back(value);

          // This is for debugging. Had to disable for the final input lol, 1k values in console
          // cout << "Distance between " << left[i] << " and " << right[i] << " is " << value << endl;
     }

     return distances;
}

int sum_array(vector<int> &arr) {
     int sum = 0;
     for(int i=0; i<arr.size(); i++){
          sum += arr[i];
     }

     return sum;
}

// !! ngl i used ChatGPT for this lmao
// Function to read the input file and populate the vectors
void read_input_file(const string &filename, vector<int> &list_left, vector<int> &list_right) {
     ifstream file(filename);
     string line;

     // Read each line in the file
     while (getline(file, line)) {
          stringstream ss(line);
          int left, right;
          ss >> left >> right;
          list_left.push_back(left);
          list_right.push_back(right);
     }

     file.close();
}

int main() {
     // Example values
     /* vector<int> list_left = {3, 4, 2, 1, 3, 3};
     vector<int> list_right = {4, 3, 5, 3, 9, 3}; */

     // Puzzle input:
     vector<int> list_left;
     vector<int> list_right;
     string filename = "input_day1.txt";
     read_input_file(filename, list_left, list_right);

     vector<int> sorted_list_left = list_left;
     vector<int> sorted_list_right = list_right;

     selection_sort(sorted_list_left);
     selection_sort(sorted_list_right);

     cout << "Originals:" << endl;
     print_array(list_left);
     print_array(list_right);

     cout << "Sorted:" << endl;
     print_array(sorted_list_left);
     print_array(sorted_list_right);

     vector<int> distances = calc_distances(sorted_list_left, sorted_list_right);
     int sum = sum_array(distances);

     cout << "Sum of distances is: " << sum << endl;

     return 0;
}