class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>galla(3 , 0);
        for(int i = 0 ; i < bills.size() ; i++ ){
            int a = bills[i];
            if(a == 5) {galla[0]++; }
            else if(a==10) {galla[1]++;
            if(galla[0]>0)galla[0]--;
            else return false ;}
            else if(a==20){galla[2]++;
            if(galla[0]>0)galla[0]--;
            else return false ;
            if(galla[1]>0)galla[1]-- ;
            else if (galla[0]>1)galla[0] = galla[0]-2;
            else return false ;}

        }
return true ;
    }
};