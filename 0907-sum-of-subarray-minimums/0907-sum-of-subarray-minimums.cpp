// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         const int MOD = 1e9 + 7;
//         int n = arr.size();

//         long long ans = 0;

//         for(int i = 0; i < n; i++) {
//             int mini = arr[i];

//             for(int j = i; j < n; j++) {
//                 mini = min(mini, arr[j]);
//                 ans = (ans + mini) % MOD;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> previousSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        return pse;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> pse = previousSmaller(arr);
        vector<int> nse = nextSmaller(arr);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            ans = (ans + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return ans;
    }
};