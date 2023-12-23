object Solution {
  def isPathCrossing(path: String): Boolean = {
    def go(path: String, acc: List[(Int, Int)] = List((0, 0))): Boolean = {
      if (path.isEmpty())
        false
      else {
        val pos = path.head match {
          case 'N' => (acc.head._1, acc.head._2 + 1)
          case 'S' => (acc.head._1, acc.head._2 - 1)
          case 'E' => (acc.head._1 + 1, acc.head._2)
          case 'W' => (acc.head._1 - 1, acc.head._2)
        }
        if (acc.contains(pos))
          true
        else
          go(path.tail, pos :: acc)
      }
    }
    go(path)
  }
}
