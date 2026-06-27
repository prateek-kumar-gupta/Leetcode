class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>ans(n);
        n = 2*n-1 ;
        vector<int>num(n+1);
        for(int i = 0 ; i <= n; i ++){
            num[i]=nums[i%nums.size()];
        }
        stack<int>st;
         while(n>=0){
            if(n<nums.size()){
                if(st.empty()){ ans[n]= -1 ; st.push(num[n]);}
                else if (st.top()>num[n]){ans[n]=st.top(); st.push(num[n]);}
                else{st.pop(); continue;}

            }
            else {
                if(st.empty()){  st.push(num[n]);}
                else if (st.top()>num[n]){ st.push(num[n]);}
                else{st.pop(); continue;}
            }
            n--;
         }
         return ans;
    }
};