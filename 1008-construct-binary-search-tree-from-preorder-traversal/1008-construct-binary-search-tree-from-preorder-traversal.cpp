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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n = preorder.size();
        for(int i = 1 ; i < n ; i++ ){
            TreeNode* a = new TreeNode(preorder[i]);
            TreeNode* curr = root;
            while(curr->left||curr->right){
                if(a->val < curr->val && curr->left) curr = curr->left;
                else if(a->val > curr->val && curr->right) curr = curr->right;
                else break;
            }
            if(a->val < curr->val) curr->left = a;
            else curr->right = a;
        }
        return root ;
    }
};