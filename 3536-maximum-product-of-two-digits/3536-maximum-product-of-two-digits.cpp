class Solution {
public:
    int maxProduct(int n) {
        int m1 = INT_MIN;
        int m2 = INT_MIN ;
        while(n>0){
            int a = n%10 ;
            n = n/10 ;
            if(a>=m1){
                m2 = m1 ;
                m1 = a ;
            }
            else if(a>m2 ) m2 = a;
        
        }
        return m1*m2 ;
    }
};