#include <string>
#include <vector>

std::string join(const std::vector<std::string> *words) {
  std::string acc;
  for (const auto &word : *words) {
    acc += word;
  }
  return acc;
}

class Solution {
public:
  bool arrayStringsAreEqual(std::vector<std::string> &word1,
                            std::vector<std::string> &word2) {
    std::string str1 = join(&word1);
    std::string str2 = join(&word2);

    return str1 == str2;
  }
};
