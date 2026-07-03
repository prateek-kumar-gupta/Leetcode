class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          int n = heights.size();
        vector<int>nse(n) ;
        stack<int>st;
        vector<int>pse(n) ;
       // pse  
        for(int i = 0 ; i < n ; i++){
             if(st.empty()){
                pse[i]=-1;
              st.push(i);
             }
             else {
                    if(heights[i]>heights[st.top()]){
                        pse[i] = st.top();
                        st.push(i);
                    }
                    else{
                        st.pop();
                       i -- ;  
                    }
             }
        }
        while(!st.empty()) st.pop();
        // nse 
         for(int i = n - 1; i >= 0 ; i--){
             if(st.empty()){
                nse[i]=n;
              st.push(i);
             }
             else {
                    if(heights[i]>heights[st.top()]){
                        nse[i] = st.top();
                        st.push(i);
                    }
                    else{
                        st.pop();
                       i++ ;  
                    }
             }
        }
        int area = 0 ;
        for(int i = 0  ; i<n ; i++){
            int a = heights[i]*(nse[i]-pse[i]-1);
            area = max(area , a);
        }
        return area ;
    }
};