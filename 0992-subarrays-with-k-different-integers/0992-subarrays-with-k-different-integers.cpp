class Solution {
public:
    long long solve(vector<int>& nums ,int k){
        unordered_map<int,int> mp ; long long ans = 0;
        int n = nums.size(); int r = 0 ; int l = 0;
        while(r<n){
            mp[nums[r]]++;
             while(l<r && mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            if(mp.size()<=k){
                ans += r-l+1;
            }
            r++;
        }
        return ans ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return int(solve(nums , k)- solve(nums,k-1)) ;
    }
};