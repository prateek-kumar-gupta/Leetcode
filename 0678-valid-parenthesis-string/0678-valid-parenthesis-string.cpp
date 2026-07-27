class Solution {
public:
    bool checkValidString(string s) {

        int low = 0, high = 0;

        for(char c : s){

            if(c == '('){
                low++;
                high++;
            }
            else if(c == ')'){
                if(low > 0) low--;
                high--;

                if(high < 0)
                    return false;
            }
            else{ // '*'
                if(low > 0) low--;
                high++;
            }
        }

        return low == 0;
    }
};