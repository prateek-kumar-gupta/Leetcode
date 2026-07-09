class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           int hash[256];
        memset(hash, -1, sizeof(hash));
           int ans = 0 ;
           int n = s.length();
           int l = 0 ;int r = 0 ;
          while(r < n){

    if(hash[s[r]] != -1 && hash[s[r]] >= l){
        l = hash[s[r]] + 1;
    }

    hash[s[r]] = r;

    ans = max(ans, r - l + 1);

    r++;
}
           return ans ;
           }
    }; 