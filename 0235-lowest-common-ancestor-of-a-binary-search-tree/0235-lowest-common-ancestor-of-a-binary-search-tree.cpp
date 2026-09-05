/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool solve(TreeNode* root , TreeNode* n , vector<TreeNode*>& a){
        if(root == NULL) return false;

        a.push_back(root);

        if(root == n) return true;

        if(root->left && solve(root->left , n , a)) return true;
        if(root->right && solve(root->right , n , a)) return true;

        a.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ap;
        vector<TreeNode*> aq;
        solve(root , p , ap);
        solve(root , q , aq);
        TreeNode* ans = NULL;

     int i = 0;
     while(i < ap.size() && i < aq.size() && ap[i] == aq[i]){
    ans = ap[i];
    i++;
     }

     return ans;

    }
};