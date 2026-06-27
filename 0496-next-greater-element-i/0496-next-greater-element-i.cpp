class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st ;
        vector<int> ans ;
        int n = nums2.size();
        unordered_map<int,int> nge ;
        n = n-1 ;
        while(n>=0){
             if(st.empty()){
                st.push(nums2[n]);
               nge[nums2[n]] = -1;
             }
             else if(st.top()>nums2[n]){
                nge[nums2[n]] = st.top();
               st.push(nums2[n]);
               
             } 
             else {
                st.pop();
                continue;
            
             }
            
              n--;
        }
        for(int i = 0 ; i < nums1.size();i++){
          ans.push_back(nge[nums1[i]]);
        }
        return ans ;
    }
};