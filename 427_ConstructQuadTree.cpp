#include <vector>

using namespace std;

class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
  Node *build(vector<vector<int>> &grid, int fromX, int fromY, int size) {
    if (size == 1) {
      return new Node(grid[fromY][fromX], true);
    }

    bool val = grid[fromY][fromX];
    for (int j = fromY; j < fromY + size; j++) {
      for (int i = fromX; i < fromX + size; i++) {
        if (grid[j][i] != val) {
          return new Node(
              true, false, build(grid, fromX, fromY, size / 2),
              build(grid, fromX + size / 2, fromY, size / 2),
              build(grid, fromX, fromY + size / 2, size / 2),
              build(grid, fromX + size / 2, fromY + size / 2, size / 2));
        }
      }
    }

    return new Node(val, true);
  }

public:
  Node *construct(vector<vector<int>> &grid) {
    Node *qt = build(grid, 0, 0, grid.size());
    return qt;
  }
};
