class Solution {
public:
unordered_set<int> seen;
    bool num(int n){
        if(n == 1 ){
            return true;
        }
        if(seen.count(n)){
            return false;
        }
        seen.insert(n);
        int sum = 0;
        while(n> 0){
            int d = n %10;
            sum += d*d;
            n= n/10;
        }
        return num(sum);
    }
    bool isHappy(int n) {
       return num(n);
    }
};