#include <string>

using namespace std;

class Solution {
public:
  string largestOddNumber(string num) {
    int rightmostIdx = -1;
    for (int i = 0; i < num.length(); i++) {
      if ((num[i] - 0x30) % 2 != 0) {
        rightmostIdx = i;
      }
    }

    return num.substr(0, rightmostIdx + 1);
  }
};
