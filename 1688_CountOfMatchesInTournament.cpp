class Solution {
public:
  int numberOfMatches(int n) {
    int acc = 0;
    while (n > 1) {
      if (n % 2 == 0) {
        acc += n / 2;
        n = n / 2;
      } else {
        acc += (n - 1) / 2;
        n = (n - 1) / 2 + 1;
      }
    }
    return acc;
  }
};
