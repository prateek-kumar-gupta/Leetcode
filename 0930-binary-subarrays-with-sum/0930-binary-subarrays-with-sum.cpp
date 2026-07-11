class Solution {
public:
    long long help(vector<int>& nums, int goal) {
        if(goal < 0) return 0 ;
        int n = nums.size();
        int l = 0 ; int r = 0 ; int sum = 0 ; long long ans = 0 ;
        while(r<n){
            sum = sum + nums[r];
            while( l<n && sum > goal){sum = sum - nums[l];
            l++;}
              ans = ans + r - l + 1 ;
              r++;
        }
    return ans ;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return  int(help(nums , goal) - help(nums,goal-1));
    }
};
    // while(l<=r && r < n){
    //         sum = sum + nums[r];
    //             if(sum<goal){
    //             r++;
    //             }
    //             else if(sum == goal){
    //                 ans++;
    //                 r++;
    //             }
    //             else {
    //                 sum = sum - nums[r] - nums[l];
    //                 l++;
    //             }
    //     }
    //     while(l<n){
    //         sum = sum - nums[l];
    //         if(sum == goal) ans++;
    //         l++;
    //     }
    //     return ans ;