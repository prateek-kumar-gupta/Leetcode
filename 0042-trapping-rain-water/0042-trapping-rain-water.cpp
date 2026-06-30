class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<int> right(n) ;
    //     right[n-1] = height[n-1];
    //     for(int i = n-2 ; i >=0 ; i--){
    //         right[i] = max(right[i+1], height[i]);
    //     }
    //     int left = height[0];
    //     int ans = 0 ;
    //     for(int i = 0 ; i < n; i++){
    //         left = max(left,height[i]);
    //         if(height[i]<left && height[i]<right[i]){
    //              ans = ans + min(left,right[i]) - height[i];
    //         }
    //     }
    //     return ans ;
    // }
    // lets optimize 
    int trap(vector<int>& height){
        int n = height.size();
        int r = n - 1 ;
        int l = 0 ;
        int left = 0 ;
        int right = 0 ;
        int ans = 0 ;
        while(l<r){
          left = max(left, height[l]);
          right = max(right,height[r]);
          if(left<=right){
               if(height[l]<left && height[l]<right){
                 ans = ans + min(left,right) - height[l];
            }
            l++;
          }
          else {
               if(height[r]<left && height[r]<right){
                 ans = ans + min(left,right) - height[r];
            }
            r--;
          }
        }
        return ans ;
    }
};