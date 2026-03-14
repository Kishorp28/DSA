# Array

## Easy

### Best Time to Buy and Sell Stock II

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 ;
        for(int i = 1  ; i < prices.size() ; i++){
            if(prices[i] > prices[i - 1]){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
         
        
    }
};
```

---

### Running Sum of 1D Array

https://leetcode.com/problems/running-sum-of-1d-array/description/

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = nums[0];
        ans.push_back(sum);

        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};
```

---

## Medium

### Subarray Sum Equals K

https://leetcode.com/problems/subarray-sum-equals-k/description/

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> arr;
        arr[0] = 1;
        int c =0 ;
        int sum =0 ;
        for(int i : nums){
            sum += i ;
            if(arr.find(sum - k) != arr.end()){
                c += arr[sum - k];
            }
            arr[sum]++;
        }
        return c ;
    }
};
```

---

### Next Permutation

https://leetcode.com/problems/next-permutation/description/

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

---

## Hard

### Insert Delete GetRandom O(1) – Duplicates Allowed

https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

```cpp
class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;
    RandomizedCollection() {}

    bool insert(int val) {
        nums.push_back(val);
        mp[val].insert(nums.size() - 1);
        return mp[val].size() == 1;
    }

    bool remove(int val) {
        if (mp[val].empty())
            return false;

        int idx = *mp[val].begin();
        mp[val].erase(idx);

        int last = nums.back();
        nums[idx] = last;

        mp[last].insert(idx);
        mp[last].erase(nums.size() - 1);
        nums.pop_back();
        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```
