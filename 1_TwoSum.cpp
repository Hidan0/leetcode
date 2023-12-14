#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    if (nums.size() > 2) {
      for (int i = 0; i < nums.size(); ++i) {
        int c = target - nums[i];
        for (int j = 0; j < nums.size(); ++j) {
          if (i != j && nums[j] == c) {
            return {i, j};
          }
        }
      }
    }

    return {0, 1};
  }
};
