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
    void solve(TreeNode* root , vector<string>& ans , string an ){
        if(root==NULL) return ;
        string a = an;
             if(root->left ==NULL && root->right==NULL ){ a = a + "->" + to_string(root->val);ans.push_back(a) ; return;}
              a = a + "->" + to_string(root->val);
             solve(root->left, ans , a);
             solve(root->right, ans ,a );
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans ;
      if(root==NULL)return ans ;
        string an = to_string(root->val);
        if(root->left == NULL && root->right==NULL) ans.push_back(an) ;
        solve(root->left , ans ,an);
        solve(root->right , ans ,an);
        return ans ;
    }
};