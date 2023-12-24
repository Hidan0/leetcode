object Solution {
  def minOperations(s: String): Int = {
    def aux(s: String, i: Int = 0, acc: Int = 0, acc2: Int = 0): Int = {
      if (i < s.length) {
        if (i % 2 == 0) {
          if (s.charAt(i) == '0') 
            aux(s, i + 1, acc, acc2 + 1)
          else
            aux(s, i + 1, acc + 1, acc2)
        } else {
          if (s.charAt(i) == '1') 
            aux(s, i + 1, acc, acc2 + 1)
          else
            aux(s, i + 1, acc + 1, acc2)
        }
      } else {
        acc min acc2
      }
    }
    aux(s)
  }
}
