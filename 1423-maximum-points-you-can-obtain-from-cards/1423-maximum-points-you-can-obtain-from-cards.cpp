class Solution {
public:
    long long minsr(vector<int>&arr , int k , int n){
        int l = 0 ; int r = 0 ; int cl = 0 ; long long sum = 0 ; long long ans = LLONG_MAX ;
        while(r<n){
            sum = sum + arr[r];
            cl = cl + 1;
            while(cl>k){
               sum = sum - arr[l];
               l++;
               cl--;
            }
            if(cl==k){
                ans = min(ans , sum );

            }
            r++;
        }
        return ans ;
    }
    int maxScore(vector<int>& cardPoints, int k) {
       int n = cardPoints.size();
       long long  total = 0 ;
       for(int i = 0 ; i  < n ; i++){
        total = total + cardPoints[i];
       }
       if(n-k==0) return int(total);
      return int(total - minsr(cardPoints , n-k , n));
    
    }
};