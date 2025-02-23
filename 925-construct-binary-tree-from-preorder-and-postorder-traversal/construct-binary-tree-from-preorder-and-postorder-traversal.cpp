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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex; // Map to store postorder indices
        for (int i = 0; i < postorder.size(); ++i) {
            postIndex[postorder[i]] = i;
        }

        int preIndex = 0; // Index to traverse the preorder array
        return buildTree(preorder, postorder, postIndex, 0, postorder.size() - 1, preIndex);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& postIndex, int left, int right, int& preIndex) {
        if (left > right) return nullptr; // Base case: No nodes to process

        // Create the root node using the current preorder index
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        // If there's only one node in the current range, return it
        if (left == right) return root;

        // Find the split point in postorder for the left subtree
        int split = postIndex[preorder[preIndex]];

        // Recursively build the left and right subtrees
        root->left = buildTree(preorder, postorder, postIndex, left, split, preIndex);
        root->right = buildTree(preorder, postorder, postIndex, split + 1, right - 1, preIndex);

        return root;
    }
};
