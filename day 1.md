# Array

## Easy

### Two Sum
https://leetcode.com/problems/two-sum/description/

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> res;
        int sum = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++){
            int sum = target - nums[i] ;
             
            if(res.find(sum) != res.end()){
                return {res[sum],i};

            }
            res[nums[i]] = i;
        }  
        return {-1};  
    }
};
```

---

### Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0 ;
        int pric= INT_MAX;
        int profit = 0 ;
        for(int i = 0 ; i  < prices.size() ; i++){
            if(prices[i] < pric){
                pric = prices[i];
            }

            profit = prices[i] - pric;

            if(maxprofit < profit ){
                maxprofit = profit;
            }
            
            
        }
        return maxprofit ;

        
    }
};
```

---

## Medium

### Merge Intervals
https://leetcode.com/problems/merge-intervals/description/

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);

        for(int i = 1 ; i < intervals.size() ; i ++){
            vector<int>& last = res.back();
            vector<int> curr = intervals[i];

            if(curr[0] <= last[1]){
                last[1] = max(curr[1],last[1]);
            }
            else{
                res.push_back(curr);
            }
        }
        return res;  
    }
};
```

---

### #SUM
https://leetcode.com/problems/3sum/description/
```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {

                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};
```

---

## Hard

### First Missing Positive
https://leetcode.com/problems/first-missing-positive/description/

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == res){
                res++;

            }
            if(nums[i] > res){
                return res;
            }
        }
        return res; 
    }
};
```
