// class Solution {
// public:
//     void solve(vector<vector<int>>& ans,vector<int>&temp, vector<int>& nums , int i , int n){
//         if(i>=n){
//             ans.push_back((temp));
//             return;
//         }
//         temp.push_back(nums[i]);
//         solve(ans , temp , nums , i + 1 , n);
//         temp.pop_back();
//         solve(ans , temp , nums , i+1 , n);
//         return ;

//      }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans ;
//         vector<int>temp;
//         solve(ans ,temp, nums , 0 ,  nums.size());
//         return ans ;
//     }
// };
class Solution{
    public :
     vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans ;
      int n = nums.size();
      for(int i = 0 ; i < (1<<n) ; i++){
        vector<int>cur;
              for(int j = 0 ; j < n ; j++){
                  if(i&(1<<j)) cur.push_back(nums[j]);
              }
              ans.push_back(cur);
      }
      return ans ;
     }
};