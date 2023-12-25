#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    int n = s.length();
    vector<int> dp = vector<int>(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != '0') {
        if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
          dp[i] = dp[i + 1] + dp[i + 2];
        } else {
          dp[i] = dp[i + 1];
        }
      }
    }

    return dp[0];
  }
};
