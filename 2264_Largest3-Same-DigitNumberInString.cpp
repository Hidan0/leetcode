#include <list>
#include <string>

using namespace std;

class Solution {
public:
  string largestGoodInteger(string num) {
    char prev = ' ';
    int prevc = 0;
    list<string> nums;

    for (int i = 0; i < num.length() - 2; i++) {
      string n = num.substr(i, 3);
      if (n[0] == n[1] && n[1] == n[2]) {
        nums.push_back(n);
      }
    }

    string max = "-1";

    for (const auto n : nums) {
      if (stoi(n) > stoi(max)) {
        max = n;
      }
    }

    return max == "-1" ? "" : max;
  }
};
