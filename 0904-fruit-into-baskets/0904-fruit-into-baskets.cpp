// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int n = fruits.size();
//         int t1 = -1 ;
//         int t2 = -1 ;
//         int l = 0 ; int r =0 ; int ans = 0 ;
//         stack<pair<int,int>>st;
//         while(r<n && l < n){
//             if(t1 == -1 && fruits[r]!=t2){t1 = fruits[r] ;}
//             else if(t2 == -1 && fruits[r]!=t1 ){t2 = fruits[r] ;}
//             if(fruits[r]!=t1 && fruits[r]!=t2){
//                 int a = fruits[r-1];
//                 if(a==t1)t2 = fruits[r];
//                 else t1 = fruits[r];
//                 while(!st.empty()&&st.top().second==a){
//                     l = st.top().first;
//                     st.pop();
//                 }
//             }
//             st.push({r , fruits[r]});
//             ans = max(ans , r - l + 1);
//             r++;
//         }
//         return ans ;
//     }

// };
class Solution {
     public : 
     int totalFruit(vector<int>&fruits){
        map<int,int>mp ;
        int l = 0 ; int r = 0 ; int ans = 0 ;
        int n = fruits.size();
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=2) ans = max(ans , r - l + 1);
            r++;
        }
        return ans ;
     }
};