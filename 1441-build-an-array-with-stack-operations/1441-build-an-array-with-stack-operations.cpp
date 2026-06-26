class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>arr ;
        int ind = 0 ;
        int i = 1 ;
        while(i<=n && ind<target.size()){
          if(target[ind] == i){
            arr.push_back("Push");
            ind++;
          }
          else{
            arr.push_back("Push");
            arr.push_back("Pop");
          }
          i++;
        }
        return arr;
    }
};