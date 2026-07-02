class Solution {
public:
    string removeKdigits(string num, int k) {

        string ans = "";
        stack<int> st;

        int n = num.length();
        int i = 0;

        while(i < n){

            while(!st.empty() && st.top() > num[i]-'0' && k > 0){
                st.pop();
                k--;
            }

            st.push(num[i]-'0');
            i++;
        }

        while(k > 0){
            st.pop();
            k--;
        }

        while(!st.empty()){
            ans += ('0' + st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int idx = 0;

        while(idx < ans.size() && ans[idx] == '0')
            idx++;

        ans = ans.substr(idx);

        if(ans == "")
            return "0";

        return ans;
    }
};