class Solution {
public:
    bool check(string pattern , string word){
     
    if(pattern.size() > word.size())
        return false;

    for(int i = 0; i <= word.size() - pattern.size(); i++) {

        int curr = 0;

        while(curr < pattern.size() &&
              word[i + curr] == pattern[curr]) {
            curr++;
        }

        if(curr == pattern.size())
            return true;
    }

    return false;

}
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
             if(check(patterns[i], word)) ans++;
        }
        return ans ;
    }
};