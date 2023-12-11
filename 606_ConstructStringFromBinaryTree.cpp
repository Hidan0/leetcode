#include <string>
//
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };
//
using namespace std;

class Solution {
  void preorder(TreeNode *node, string *ss) {
    if (node == nullptr) {
      return;
    }

    *ss += to_string(node->val);

    if (node->left == nullptr && node->right == nullptr) {
      return;
    }

    if (node->left == nullptr) {
      *ss += "()(";
      preorder(node->right, ss);
      *ss += ")";
      return;
    }

    *ss += "(";
    preorder(node->left, ss);
    *ss += ")";
    if (node->right == nullptr) {
      return;
    }
    *ss += "(";
    preorder(node->right, ss);
    *ss += ")";
  }

public:
  string tree2str(TreeNode *root) {
    string out = "";

    this->preorder(root, &out);

    return out;
  }
};
