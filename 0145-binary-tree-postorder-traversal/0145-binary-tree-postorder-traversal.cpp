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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;

        while (root != nullptr || !st.empty()) {

            // Go as far left as possible
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            TreeNode* node = st.top();

            // If right subtree exists and hasn't been processed
            if (node->right != nullptr && lastVisited != node->right) {
                root = node->right;
            }
            else {
                // Both left and right are done
                ans.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }

        return ans;
    }
};