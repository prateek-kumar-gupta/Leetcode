class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flip = start^goal ;
        return  __builtin_popcount(flip);
    }
};