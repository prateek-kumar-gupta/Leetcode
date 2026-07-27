class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = 0 ;
        int m2 = 0 ;
        for(int i = 0  ; i < nums.size() ; i++){
        nums[i]>=m1?m2=m1:m2 = max(nums[i],m2);
        m1 = max(m1 , nums[i]);
        }
        return((m1-1)*(m2-1));
    }
};