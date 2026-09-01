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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
    return new TreeNode(val);
        TreeNode* pre = root ;
        TreeNode* curr = root ;
        while(curr!=NULL){
            pre = curr;
            curr->val < val ?curr = curr->right : curr = curr->left;
        }
        TreeNode* a = new TreeNode(val);
     pre->val > val ? pre->left = a : pre->right = a ;
     return root ;
    }
};