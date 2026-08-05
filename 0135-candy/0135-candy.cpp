class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
      int sum = 1 ; int i = 1 ;
      while(i<n){
        if(arr[i]==arr[i-1]){ sum = sum + 1;i++;continue ;
      }
      int peak = 1 ;
      while(i < n && arr[i] > arr[i-1]){peak = peak + 1 ; sum = sum + peak ; i++;}
      int down = 1 ;
      while(i < n && arr[i]< arr[i-1]){
        sum = sum + down ;
        down++;
        i++;
      }
      if(down>peak) sum = sum + down - peak ;
    }
    return sum ;}
};