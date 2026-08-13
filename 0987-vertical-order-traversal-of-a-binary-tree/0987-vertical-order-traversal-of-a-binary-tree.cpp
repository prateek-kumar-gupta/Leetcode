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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>>mp;
        queue<tuple<TreeNode* , int , int>> q;
        vector<vector<int>> ans ;
        if(root==NULL) return ans ;
        q.push({root , 0 ,0});
        while(!q.empty()){
            TreeNode*  node = get<0>(q.front());
            int v = get<1>(q.front());
            int h = get<2>(q.front());
            mp[v][h].insert(node->val);
            if(node->left)q.push({node->left , v -1 , h + 1});
            if(node->right)q.push({node->right , v + 1 , h  + 1});
            q.pop();
        }
        for(auto &a :mp){
            vector<int>an ;
            for(auto &b : a.second){
                for(auto &c : b.second){
                       an.push_back(c);
                }
            }
            ans.push_back(an);
        }
//         for(auto &a : mp) {
//     vector<int> temp;

//     for(auto &b : a.second) {
//         for(auto x : b.second) {
//             temp.push_back(x);
//         }
//     }

//     ans.push_back(temp);
// }
        return ans ;
    }
};