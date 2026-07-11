class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 ; int  r = 0 ;
        int maxlen = 0 ; int maxf = 0;
        int hash[26] = {0};
        while(r<s.length()){
            hash[s[r] - 'A']++;
            maxf = max(maxf , hash[s[r] - 'A']);
            if((r-l+1)-maxf > k){
                hash[s[l] - 'A']-- ;
                
                l= l + 1;
            }
            if(r-l +1 - maxf <= k){
                maxlen = max(maxlen , r-l+1);
            }
            r++;
        }
        return maxlen;

    }
};