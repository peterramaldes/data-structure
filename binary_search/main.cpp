#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int value = 588;
  vector<int> values{0, 1, 29123, 123, 3, 4, 4884, 588};

  sort(values.begin(), values.end());

  /* for (int i = 0; i < values.size(); i++) { */
  /*   cout << values[i] << endl; */
  /* } */

  bool found = false;

  int start_pos = 1;
  int end_pos = values.size();
  int mid_index = (end_pos / 2) - 1;

  while (!found) {
    if (values[mid_index] == value) {
      found = true;
      cout << "Valor encontrado, pos: " << mid_index << endl;
    } else if (value < values[mid_index]) {
      end_pos = mid_index;
      mid_index = end_pos / 2;
      // Start não, acho que não faz sentido para uma segunda it.
    } else if (value > values[mid_index]) { 
      start_pos = mid_index;
      end_pos = values.size(); // Eu acho que isso está errado para uma segunda it.
      mid_index = (start_pos + end_pos) / 2; // 6
    }
  }

  cout << "\n";
  return 0;
}

