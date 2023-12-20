#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int buyChoco(vector<int> &prices, int money) {
    sort(prices.begin(), prices.end());
    int p1 = prices[0];
    int p2 = prices[1];

    if (p1 + p2 > money) {
      return money;
    }
    return money - (p1 + p2);
  }
};
