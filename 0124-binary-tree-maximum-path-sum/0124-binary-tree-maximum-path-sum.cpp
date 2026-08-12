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
    int finds(TreeNode* root , int &mxsum) {
       if(root==NULL) return 0 ;
       int ls = 0 ;
       int rs = 0 ;
       ls = finds(root->left , mxsum);
       rs = finds(root->right , mxsum);
       mxsum = max(max(0,ls) + max(0,rs)  + root->val , mxsum);
     return max(0, max(ls, rs)) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0 ;
        int mxsum = INT_MIN ;
        finds(root , mxsum);
        return mxsum ;
    }
};