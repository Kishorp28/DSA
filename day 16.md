# Dynamic Programming

## Medium

### Longest Increasing Subsequence

https://leetcode.com/problems/longest-increasing-subsequence/description/

```cpp id="lq8z2x"
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ;j++){
                if(nums[j] < nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};
```

---

### Unique Paths

https://leetcode.com/problems/unique-paths/description/

---

### Count Square Submatrices with All Ones

https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

---

### Range Sum Query 2D - Immutable

https://leetcode.com/problems/range-sum-query-2d-immutable/description/

---

### Longest Arithmetic Subsequence

https://leetcode.com/problems/longest-arithmetic-subsequence/description/

---

## Hard

### Longest Valid Parentheses

https://leetcode.com/problems/longest-valid-parentheses/description/
