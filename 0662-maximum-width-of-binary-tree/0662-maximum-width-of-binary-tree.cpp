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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , long long>> q ;
        if(root==NULL) return 0 ;
        q.push({root , 1});
        long long ans = 0 ;
        while(!q.empty()){
            long long a = q.size();
            long long m = q.front().second;
             long long l = q.front().second - m;
            long long r = l;
            for(int i = 0 ; i < a ; i++){
                long long w = q.front().second - m;
                TreeNode* nd = q.front().first;
                l = min(l,w);
                r = max(r,w);
                q.pop();
                if(nd->left)q.push({nd->left,2*w + 1});
                if(nd->right)q.push({nd->right,2*w+ 2});
            }
            long long dist = r-l + 1;
                ans = max(ans , dist);
        }
        return (int)ans ;
    }
};