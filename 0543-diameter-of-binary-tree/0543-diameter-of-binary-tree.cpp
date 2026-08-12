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
    int findh(TreeNode*root){
        if(root==NULL) return 0;
         return max(findh(root->left), findh(root->right)) + 1 ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0 ;
        int lh = 0 ;
        int rh = 0 ;
        lh = findh(root->left);
        rh = findh(root->right);
        return max({lh + rh ,diameterOfBinaryTree(root->left) , diameterOfBinaryTree(root->right)});
    }
};