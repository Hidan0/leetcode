#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>> &points) {
    vector<int> xs = [](vector<vector<int>> &points) {
      vector<int> xs;
      for (vector<int> &point : points) {
        xs.push_back(point[0]);
      }
      sort(xs.begin(), xs.end());
      return xs;
    }(points);

    int out = 0;
    for (int i = 0; i < xs.size() - 1; i++) {
      out = max(out, xs[i + 1] - xs[i]);
    }

    return out;
  }
};
