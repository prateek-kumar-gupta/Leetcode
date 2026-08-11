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
// class Solution {
// public:
//     void solve(TreeNode* root, int depth, int &ans) {

//         if(root == NULL)
//             return;

//         ans = max(ans, depth);

//         solve(root->left, depth + 1, ans);
//         solve(root->right, depth + 1, ans);
//     }

//     int maxDepth(TreeNode* root) {

//         int ans = 0;

//         solve(root, 1, ans);

//         return ans;
//     }
// };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        return 1 + max(maxDepth(root->left),
                       maxDepth(root->right));
    }
};