#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {
    int sum = 0;

    unordered_map<char, int> lookup;
    for (int i = 0; i < chars.length(); i++) {
      lookup[chars[i]]++;
    }

    unordered_map<char, int> wordLookup;
    bool valid;
    for (int i = 0; i < words.size(); i++) {
      valid = true;

      for (int j = 0; j < words[i].length(); j++) {
        wordLookup[words[i][j]]++;

        if (lookup[words[i][j]] < wordLookup[words[i][j]]) {
          valid = false;
          break;
        }
      }

      if (valid) {
        sum += words[i].length();
      }

      wordLookup.clear();
    }

    return sum;
  }
};
