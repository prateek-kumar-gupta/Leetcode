class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n =  nums.size();
        vector<int>prefixGcd(n) ;
        int mx = INT_MIN ;
        for(int i = 0 ; i < n ; i++){
            mx = max(nums[i],mx);
            prefixGcd[i] = gcd(mx,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int l = 0 ; int r = n-1 ;
        long long  ans = 0 ;
        while(l<r){
         ans = ans + gcd(prefixGcd[l],prefixGcd[r]);
         l++ ; r--;
        }
        return ans ;
    }
};