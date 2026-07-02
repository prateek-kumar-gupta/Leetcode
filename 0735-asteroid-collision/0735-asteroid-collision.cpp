// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& astroids) {
//         vector<int>ans ;
//         stack<int>st ;
//         int n = astroids.size();
//         for(int i = 0 ; i < n ; i ++){
//             if(astroids[i]>0){st.push(astroids[i]);}
//             else{
//                 if(st.empty()){ans.push_back(astroids[i]);}
//                 else {
//                     if(st.top()> -1*astroids[i]){
//                         continue ;
//                     }
//                     else if(st.top()== -1*astroids[i]){
//                         st.pop();
//                         continue ;
//                     }
//                     else{
//                         st.pop() ;
//                         i--;
                        
//                     }
//                 }
//             }
//         }
//         stack<int>st1;
//         while(!st.empty()){
//             st1.push(st.top());
//             st.pop();
//         }
//         while(!st1.empty()){
//             ans.push_back(st1.top());
//             st1.pop();
//         }
//         return ans ;
//     }
// };
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++) {

            if(asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {

                if(st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
                else {

                    if(st.top() > -asteroids[i]) {
                        continue;
                    }
                    else if(st.top() == -asteroids[i]) {
                        st.pop();
                        continue;
                    }
                    else {
                        st.pop();
                        i--;
                    }
                }
            }
        }

        vector<int> ans(st.size());

        for(int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};