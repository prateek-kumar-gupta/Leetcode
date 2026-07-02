class Solution {
public:

    long long sumSubarrayMins(vector<int>& nums) {

        int n = nums.size();

        vector<int> prev(n), next(n);
        stack<int> st;

        // Previous Smaller
        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            if(st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller or Equal
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if(st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            st.push(i);
        }

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - prev[i];
            long long right = next[i] - i;

            sum += 1LL * nums[i] * left * right;
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& nums) {

        int n = nums.size();

        vector<int> prev(n), next(n);
        stack<int> st;

        // Previous Greater
        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            if(st.empty())
                prev[i] = -1;
            else
                prev[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Greater or Equal
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            if(st.empty())
                next[i] = n;
            else
                next[i] = st.top();

            st.push(i);
        }

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - prev[i];
            long long right = next[i] - i;

            sum += 1LL * nums[i] * left * right;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};