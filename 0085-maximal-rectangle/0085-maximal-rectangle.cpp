// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int n = matrix.size();
//         int n1 = matrix[0].size();
//         vector<int>heights(n1);
//         for(int i = 0 ; i < n1 ; i++){
//             int m = 0 ;
//             int a = 0;
//             for(int j = 0 ; j < n ; j++){
//                if(matrix[j][i]=='0') a = 0 ;
//                else a+= 1 ;
//                m = max(a, m);
//             }
//          heights[i] = m ;
//         }
//           n = n1 ;
//         vector<int>nse(n) ;
//         stack<int>st;
//         vector<int>pse(n) ;
//        // pse  
//         for(int i = 0 ; i < n ; i++){
//              if(st.empty()){
//                 pse[i]=-1;
//               st.push(i);
//              }
//              else {
//                     if(heights[i]>heights[st.top()]){
//                         pse[i] = st.top();
//                         st.push(i);
//                     }
//                     else{
//                         st.pop();
//                        i -- ;  
//                     }
//              }
//         }
//         while(!st.empty()) st.pop();
//         // nse 
//          for(int i = n - 1; i >= 0 ; i--){
//              if(st.empty()){
//                 nse[i]=n;
//               st.push(i);
//              }
//              else {
//                     if(heights[i]>heights[st.top()]){
//                         nse[i] = st.top();
//                         st.push(i);
//                     }
//                     else{
//                         st.pop();
//                        i++ ;  
//                     }
//              }
//         }
//         int area = 0 ;
//         for(int i = 0  ; i<n ; i++){
//             int a = heights[i]*(nse[i]-pse[i]-1);
//             area = max(area , a);
//         }
//         return area ;
//     }
// };
class Solution {
public:

    int largestRectangle(vector<int>& heights){

        int n = heights.size();

        vector<int> pse(n), nse(n);
        stack<int> st;

        // Previous Smaller
        for(int i = 0 ; i < n ; i++){

            if(st.empty()){
                pse[i] = -1;
                st.push(i);
            }
            else{

                if(heights[i] > heights[st.top()]){
                    pse[i] = st.top();
                    st.push(i);
                }
                else{
                    st.pop();
                    i--;
                }
            }
        }

        while(!st.empty()) st.pop();

        // Next Smaller
        for(int i = n-1 ; i >= 0 ; i--){

            if(st.empty()){
                nse[i] = n;
                st.push(i);
            }
            else{

                if(heights[i] > heights[st.top()]){
                    nse[i] = st.top();
                    st.push(i);
                }
                else{
                    st.pop();
                    i++;
                }
            }
        }

        int area = 0;

        for(int i = 0 ; i < n ; i++){

            int width = nse[i] - pse[i] - 1;
            area = max(area , heights[i] * width);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols,0);

        int ans = 0;

        for(int i = 0 ; i < rows ; i++){

            for(int j = 0 ; j < cols ; j++){

                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            ans = max(ans , largestRectangle(heights));
        }

        return ans;
    }
};