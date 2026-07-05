// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ma = nums[0];
//         vector<int>ans ;
//         for(int i = 0 ; i < n ; i ++){
//               if(i<k-1){ma = max(ma , nums[i]);}
//               else if(i==k-1){ma = max(ma,nums[i]); ans.push_back(ma);}
//               else{
//                 if(ma == nums[i-k] ) { ma = nums[i-k+1];
//                     for(int j = i-k+1 ; j <=i ; j++){ma = max(ma, nums[j]);}
//                 }
//                 ma = max(ma , nums[i]);
//                 ans.push_back(ma);
//               }
//         }
//         return ans ;
//     }
// };
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;    
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};