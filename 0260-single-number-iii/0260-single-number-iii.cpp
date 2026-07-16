class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;

        for (int num : nums)
            x ^= num;

        int mask = x & (-x);

        int b1 = 0, b2 = 0;

        for (int num : nums) {
            if (num & mask)
                b1 ^= num;
            else
                b2 ^= num;
        }

        return {b1, b2};
    }
};