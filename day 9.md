# Recursion

## Mixed

### Pow(x, n)

https://leetcode.com/problems/powx-n/

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n ;

        if(N < 0){
            x = 1 / x ;
            N = -N;
        }

        double ans = 1;
        while(N>0){
            if(N % 2 == 1){
                ans *= x;
            }
                x*= x ;
                N /= 2 ;

        }
        return ans;
        
    }
};
```

---

### Valid Palindrome

https://leetcode.com/problems/valid-palindrome/description/

---

### Subsets

https://leetcode.com/problems/subsets/description/

---

### Permutations

https://leetcode.com/problems/permutations/description/

---

### Permutations II

https://leetcode.com/problems/permutations-ii/description/
