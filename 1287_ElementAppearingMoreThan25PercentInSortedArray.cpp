#include <vector>

using namespace std;

class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    int target = arr.size() / 4;
    int out = arr[0];
    int count = 1;
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] == out) {
        count++;

        if (count > target) {
          return out;
        }
      } else {
        out = arr[i];
        count = 1;
      }
    }

    return out;
  }
};
