class Solution {
public:
    bool checkPerfectNumber(int num) {

        if(num == 1) return false;

        int sum = 0;

        for(int i = 1; i * i <= num; i++) {

            if(num % i == 0) {

                sum += i;

                if(num / i != i && num / i != num)
                    sum += num / i;

                if(sum > num) return false;
            }
        }

        return sum == num;
    }
};