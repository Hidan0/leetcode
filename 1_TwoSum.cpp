#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    if (nums.size() > 2) {

      unordered_map<int, int> idx;
      for (int i = 0; i < nums.size(); ++i) {
        idx[nums[i]] = i;
      }

      for (int i = 0; i < nums.size(); ++i) {
        int c = target - nums[i];

        if (idx.count(c) > 0) {
          if (idx[c] != i) {
            return {i, idx[c]};
          }
        }
      }
    }

    return {0, 1};
  }
};
