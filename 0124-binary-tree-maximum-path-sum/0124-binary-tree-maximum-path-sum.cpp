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
    int finds(TreeNode* root){
       if(root==NULL) return 0 ;
       return max({0,finds(root->left) , finds(root->right)}) + root->val ;
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return INT_MIN ;
        int ls = 0 ; int rs = 0 ;
        ls = finds(root->left);
        rs = finds(root->right);
        
        return max({
    max(0, ls) + max(0, rs) + root->val,
    maxPathSum(root->left),
    maxPathSum(root->right)
});
    }
};