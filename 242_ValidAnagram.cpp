#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> m;
    for (char c : s) {
      m[c]++;
    }

    for (char c : t) {
      m[c]--;
    }

    for (auto [_, v] : m) {
      if (v != 0) {
        return false;
      }
    }

    return true;
  }
};
