// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {

//         int n = nums.size();

//         int l = 0;
//         int r = 0;
//         int zeros = 0;
//         int ans = 0;

//         while(r < n){

//             if(nums[r] == 0)
//                 zeros++;

//             while(zeros > k){

//                 if(nums[l] == 0)
//                     zeros--;

//                 l++;
//             }

//             ans = max(ans, r - l + 1);

//             r++;
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int l = 0;
        int r = 0;
        int ans = 0;

        queue<int> q;

        while(r < n){

            if(nums[r] == 0)
                q.push(r);

            if(q.size() > k){
                l = q.front() + 1;
                q.pop();
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};