class Solution {
public:
    int countPrimes(int n) {
        int count = 0 ;
        int prime[n+1];
        for(int i = 2 ; i < n +1 ; i++){
             prime[i] = 1;
        }
        for(int i = 2 ; i < n + 1 ; i++){
            if(prime[i]==1){
                for(long long j = 1LL * i * i; j < n; j += i){
                    prime[j] = 0 ;
                }
            }
        }

        for(int i = 2; i < n; i++) {
            if(prime[i]) count++;
        }
        return count;
    }
};