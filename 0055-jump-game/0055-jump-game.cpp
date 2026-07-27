class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0 ;
        int a =0  ;
        for(int i = 0 ; i < n && i <= farthest ; i++){
            a = i ;
              farthest = max(farthest , i + nums[i]) ;
        }
        if(a>=n-1) return true ;
        else return false;
    }
};