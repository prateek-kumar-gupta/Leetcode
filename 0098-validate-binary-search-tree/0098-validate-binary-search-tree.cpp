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
    bool solve(TreeNode* root , long long mx , long long mn ){ 
        if(root == NULL) return true ; 
        
        if(root->val >= mx || root->val <= mn) return false ; 
        
        return solve(root->left , root->val , mn ) && 
               solve(root->right , mx , root->val); 
    }     
     
    bool isValidBST(TreeNode* root) { 
        long long mx = LLONG_MAX ; 
        long long mn = LLONG_MIN ; 
        
        if(root == NULL) return true ; 
        
        return solve(root , mx , mn); 
    } 
};