// class Solution {
// public:
//     int xorOperation(int n, int start) {
//         int ans = 0 ;
//         for(int i = 0 ; i < n ; i++){
//             ans = ans^(start + 2*i);
//         }
//         return ans ;
//     }
// };
class Solution {
public:
    int prefixXor(int x) {
        if (x % 4 == 0) return x;
        if (x % 4 == 1) return 1;
        if (x % 4 == 2) return x + 1;
        return 0;
    }

    int xorOperation(int n, int start) {
        int s = start >> 1;

        int ans = prefixXor(s + n - 1) ^ prefixXor(s - 1);

        ans <<= 1;

        if ((n & 1) && (start & 1))
            ans |= 1;

        return ans;
    }
};