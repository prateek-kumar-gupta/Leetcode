class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n) ;
        right[n-1] = height[n-1];
        for(int i = n-2 ; i >=0 ; i--){
            right[i] = max(right[i+1], height[i]);
        }
        int left = height[0];
        int ans = 0 ;
        for(int i = 0 ; i < n; i++){
            left = max(left,height[i]);
            if(height[i]<left && height[i]<right[i]){
                 ans = ans + min(left,right[i]) - height[i];
            }
        }
        return ans ;
    }
};