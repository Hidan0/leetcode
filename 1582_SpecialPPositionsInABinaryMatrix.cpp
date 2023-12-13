#include <vector>

using namespace std;

class Solution {
public:
  int numSpecial(vector<vector<int>> &mat) {
    int out = 0;

    for (int m = 0; m < mat.size(); ++m) {
      for (int n = 0; n < mat[0].size(); ++n) {
        if (mat[m][n] == 1 && isSpecial(mat, m, n)) {
          out++;
        }
      }
    }

    return out;
  }

  bool isSpecial(vector<vector<int>> &mat, int m, int n) {
    for (int i = 0; i < mat.size(); ++i) {
      if (i != m && mat[i][n] == 1) {
        return false;
      }
    }
    for (int j = 0; j < mat[0].size(); ++j) {
      if (j != n && mat[m][j] == 1) {
        return false;
      }
    }
    return true;
  }
};
