/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stk;
        int i = 0;

        while (i < traversal.size()) {
            int depth = 0;

            // Count the number of dashes to determine the depth
            while (i < traversal.size() && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Parse the number (node value)
            int value = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(value);

            // Maintain the correct depth in the stack
            while (stk.size() > depth) {
                stk.pop();
            }

            // Attach the node to its parent
            if (!stk.empty()) {
                if (!stk.top()->left) {
                    stk.top()->left = node;
                } else {
                    stk.top()->right = node;
                }
            }

            // Push the current node onto the stack
            stk.push(node);
        }

        // The root of the tree is at the bottom of the stack
        while (stk.size() > 1) {
            stk.pop();
        }
        return stk.top();
    }
};
