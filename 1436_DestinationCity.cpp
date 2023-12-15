#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string destCity(vector<vector<string>> &paths) {
    unordered_map<string, string> m;

    for (auto path : paths) {
      m[path[0]] = path[1];
    }

    for (auto path : paths) {
      if (m.count(path[1]) == 0) {
        return path[1];
      }
    }

    return "";
  }
};
