class Solution {
public:
    long long help(vector<int>& nums, int k){
        int odd = 0 ;
        int l = 0 ; int r = 0 ;
        long long ans ; 
        while(r < nums.size()){
            if(nums[r]%2!=0) odd++;
            while(odd>k){if(nums[l]%2!=0)odd--;
            l++;}
            ans = ans + r - l + 1 ;
            r++;
        }
        return ans ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return int(help(nums , k) - help(nums , k -1 ));
    }
};