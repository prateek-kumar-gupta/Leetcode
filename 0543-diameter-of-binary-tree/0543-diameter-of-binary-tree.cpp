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
    int findh(TreeNode* root , int &ma){
        if(root==NULL) return 0;
        int lh = findh(root->left , ma);
        int rh = findh(root->right, ma );
        ma = max(ma , lh + rh);
        return 1 + max(lh , rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0 ;
        int ma = 0 ;
        findh( root , ma);
        return ma ;
    }
};