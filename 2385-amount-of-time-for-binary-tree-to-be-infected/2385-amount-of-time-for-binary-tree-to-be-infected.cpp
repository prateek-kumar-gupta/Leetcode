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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*  , TreeNode*> mp ;
        if(root == NULL) return 0 ;
        queue<TreeNode*>q;
        q.push(root);
        mp[root] = NULL;
        TreeNode* st = NULL;
        while(!q.empty()){
           TreeNode* r = q.front();
            q.pop();
            if(r->left){mp[r->left]=r; q.push(r->left);}
            if(r->right){mp[r->right] = r ; q.push(r->right);}
            if(r->val == start) st = r;
        }
      if(st==NULL) return 0 ;
      q.push(st);
      int a = -1 ;
      unordered_map<TreeNode* , bool> m;
      m[st] = true;
      while(!q.empty()){
          a++;
          int h = q.size();
          TreeNode* nd = NULL;
          for(int i = 0 ; i < h ; i++){
            nd = q.front() ;
            if(nd->left && !m[nd->left]){q.push(nd->left);m[nd->left]=true;}
            if(nd->right && !m[nd->right]){q.push(nd->right);m[nd->right]=true;}
            if(mp[nd] && !m[mp[nd]]){q.push(mp[nd]);m[mp[nd]]=true;}
            q.pop();
          }
      }
      return a ;
    }
};