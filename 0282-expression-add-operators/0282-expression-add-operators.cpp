class Solution {
public:

    void solve(vector<string>& ans,
               string& temp,
               string& num,
               int i,
               long long val,
               long long last,
               int target) {

        if(i == num.size()) {
            if(val == target)
                ans.push_back(temp);
            return;
        }

        long long curr = 0;
        int len = temp.size();

        for(int j = i; j < num.size(); j++) {

            // leading zero not allowed
            if(j > i && num[i] == '0')
                break;

            curr = curr * 10 + (num[j] - '0');
            string s = num.substr(i, j - i + 1);

            // +
            temp += "+" + s;
            solve(ans, temp, num, j + 1, val + curr, curr, target);
            temp.resize(len);

            // -
            temp += "-" + s;
            solve(ans, temp, num, j + 1, val - curr, -curr, target);
            temp.resize(len);

            // *
            temp += "*" + s;
            solve(ans, temp, num, j + 1,
                  val - last + last * curr,
                  last * curr,
                  target);
            temp.resize(len);
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        if(num.empty())
            return ans;

        long long curr = 0;
        string temp;

        for(int i = 0; i < num.size(); i++) {

            // leading zero
            if(i > 0 && num[0] == '0')
                break;

            curr = curr * 10 + (num[i] - '0');

            temp = num.substr(0, i + 1);

            solve(ans,
                  temp,
                  num,
                  i + 1,
                  curr,
                  curr,
                  target);
        }

        return ans;
    }
};