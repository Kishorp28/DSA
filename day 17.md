# Dynamic Programming

## Hard

### Best Time to Buy and Sell Stock IV

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

```cpp id="m1z8kd"
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        int profit = 0;
        if (n < 2) {
            return 0;
        }
        if (k > n / 2) {
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
        }

        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};
```

---

### Burst Balloons

https://leetcode.com/problems/burst-balloons/description/

---

### Minimum Cost to Merge Stones

https://leetcode.com/problems/minimum-cost-to-merge-stones/description/
