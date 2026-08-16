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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans ;
        unordered_map<TreeNode* , TreeNode*> mp;
        queue<TreeNode*> q;
        if(root==NULL) return ans ;
        q.push(root);
        mp.insert({root,NULL});
        while(!q.empty()){
            if(q.front()->left) {mp.insert({q.front()->left, q.front()}) ; q.push(q.front()->left);}
            if(q.front()->right) {mp.insert({q.front()->right,q.front()}); q.push(q.front()->right);}
            q.pop();
        }
        unordered_map<TreeNode* , bool>visited;
        visited[target] = true ;
        q.push(target);
        int d = 0 ;
        while(!q.empty()&& d<k){
          int n= q.size();
          for(int i = 0 ; i <n ; i++){
            TreeNode*nd = q.front();
            if(nd->left && !visited[nd->left]){
                visited[nd->left]=true ;
                q.push(nd->left);
            }
             if(nd->right && !visited[nd->right]){
                visited[nd->right]=true ;
                q.push(nd->right);
            }
            if(mp[nd] && !visited[mp[nd]]){
                visited[mp[nd]] = true ;
                q.push(mp[nd]);
            }
            q.pop();
          }
          d++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans ;
    }
};