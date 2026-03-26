# DYNAMIC PROGRAMING:

## Medium:

https://leetcode.com/problems/palindromic-substrings/description/

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int c = 0;

        for(int center = 0 ; center < 2*n -1; center++){
            int l = center / 2;
            int r = l+ center%2;

            while(l >=0  && r <n && s[l] == s[r]){
                c++;
                l--;
                r++;
            }
        }
    return c;   
    }
};
```

https://leetcode.com/problems/house-robber/description/

https://leetcode.com/problems/continuous-subarray-sum/description/

https://leetcode.com/problems/knight-dialer/description/

## Hard:

https://leetcode.com/problems/maximal-rectangle/description/
