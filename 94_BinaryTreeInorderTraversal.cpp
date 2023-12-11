#include <vector>

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

using namespace std;

class Solution {
  void inorder(TreeNode *node, vector<int> *out) {
    if (node == nullptr) {
      return;
    }

    this->inorder(node->left, out);
    out->push_back(node->val);
    this->inorder(node->right, out);
  }

public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> out;

    this->inorder(root, &out);

    return out;
  }
};
