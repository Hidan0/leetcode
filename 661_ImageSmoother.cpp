#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
    int m = img.size();
    int n = img[0].size();
    vector<vector<int>> smoothed = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int sum = 0;
        int count = 0;

        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            int x = i + dx;
            int y = j + dy;

            if (x >= 0 && x < m && y >= 0 && y < n) {
              sum += img[x][y];
              count++;
            }
          }
        }

        smoothed[i][j] = sum / count;
      }
    }

    return smoothed;
  }
};
