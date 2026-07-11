class Solution {
public:
    int numberOfSubstrings(string s) {
         int hash[3] = {-1 , -1 , -1}; int m = -1 ; int ans = 0 ;
       for(int i = 0 ; i < s.length() ; i++){
            hash[s[i]-'a'] = i;
            m = min({hash[0],hash[1],hash[2]});
            if(m!=-1){
            ans = ans + m + 1;
            }
       }
       return ans ;
    }
};