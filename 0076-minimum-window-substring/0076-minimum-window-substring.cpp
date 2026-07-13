class Solution {
public:
    string minWindow(string s, string t) {

        int h[256] = {0};

        for(char ch : t)
            h[ch]++;

        int l = 0, r = 0;
        int count = 0;

        int si = -1;
        int sz = INT_MAX;

        while(r < s.length()) {

            if(h[s[r]] > 0)
                count++;

            h[s[r]]--;
            r++;

            while(count == t.length()) {

                if(r - l < sz) {
                    sz = r - l;
                    si = l;
                }

                h[s[l]]++;

                if(h[s[l]] > 0)
                    count--;

                l++;
            }
        }

        if(si == -1)
            return "";

        return s.substr(si, sz);
    }
};