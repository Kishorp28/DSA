# DYNAMIC PROGRAMING:

## Medium:

https://leetcode.com/problems/coin-change/description/

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        if (dp[amount] > amount) {
            return -1;
        }

        return dp[amount];
    }
};
```

https://leetcode.com/problems/maximum-product-subarray/description/

https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

## Hard:

https://leetcode.com/problems/regular-expression-matching/description/
