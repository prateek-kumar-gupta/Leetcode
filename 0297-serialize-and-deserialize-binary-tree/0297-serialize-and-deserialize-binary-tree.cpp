/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*>q ;
        string ans = ""; 
        if(root == NULL) return "#," ;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front() ;
            if(curr==NULL) ans.append("#,");
            else ans.append(to_string(curr->val)+",");
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
            q.pop();
        }
     return ans ;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string x;
getline(s, x, ',');
if (x == "#") {
   return NULL;
} 
TreeNode* root = new TreeNode(stoi(x));
queue<TreeNode*>q;
     q.push(root);
     while(!q.empty()){
        TreeNode* curr = q.front();
        getline(s, x, ',');
        if (x == "#") {
         curr->left = NULL;
        } 
        else {
            TreeNode* a = new TreeNode(stoi(x));
            curr->left = a;
            q.push(a);
        }
        getline(s, x, ',');
        if (x == "#") {
         curr->right = NULL;
        } 
         else {
            TreeNode* b = new TreeNode(stoi(x));
            curr->right = b;
            q.push(b);
        }
        q.pop();
        
     }
     return root ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));