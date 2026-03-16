# Array Problems – LeetCode Solutions (C++)

This repository contains solutions to common **Array problems from LeetCode** implemented in **C++**.
Problems are organized by difficulty level.

---

# Easy

## 1. Find Pivot Index

🔗 https://leetcode.com/problems/find-pivot-index/

### Approach

Compute **prefix sum** and **suffix sum** arrays.
The pivot index is where both sums are equal.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,0);
        vector<int> suf(n,0);

        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + nums[i];
        }

        suf[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            suf[i] = suf[i+1] + nums[i];
        }

        for(int i = 0; i < n; i++){
            if(pre[i] == suf[i]){
                return i;
            }
        }

        return -1;
    }
};
```

---

## 2. Majority Element

🔗 https://leetcode.com/problems/majority-element/

### Approach

Use a **Hash Map** to count occurrences of each element.
Return the element whose frequency is greater than `n/2`.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i : nums){
            mp[i]++;
        }

        for(auto &i : mp){
            if(i.second > n/2){
                return i.first;
            }
        }

        return -1;
    }
};
```

---

# Medium

## 3. Spiral Matrix

🔗 https://leetcode.com/problems/spiral-matrix/

### Approach

Use four boundaries:

* top
* bottom
* left
* right

Traverse the matrix layer by layer in **spiral order**.

**Time Complexity:** `O(m × n)`
**Space Complexity:** `O(1)` (excluding output array)

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int t = 0;
        int b = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;

        while(l <= r && t <= b){

            for(int i = l; i <= r; i++){
                ans.push_back(matrix[t][i]);
            }
            t++;

            for(int i = t; i <= b; i++){
                ans.push_back(matrix[i][r]);
            }
            r--;

            if(t <= b){
                for(int i = r; i >= l; i--){
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }

            if(l <= r){
                for(int i = b; i >= t; i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        return ans;
    }
};
```

---

## 4. Container With Most Water

🔗 https://leetcode.com/problems/container-with-most-water/

### Approach

Use **Two Pointers**:

* Start from both ends
* Calculate area
* Move the pointer with smaller height

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;

        while(l <= r){
            int h = min(height[l], height[r]);
            int w = r - l;

            ans = max(ans, h * w);

            if(height[l] < height[r]){
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};
```

---

# Hard

## 5. Best Time to Buy and Sell Stock III

🔗 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

### Approach

Use **four variables** to track two transactions:

* First buy
* First sell
* Second buy
* Second sell

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = 0, profit2 = 0;

        for(int price : prices){
            buy1 = min(buy1, price);
            profit1 = max(profit1, price - buy1);

            buy2 = min(buy2, price - profit1);
            profit2 = max(profit2, price - buy2);
        }

        return profit2;
    }
};
```

---

# Topics Covered

* Prefix Sum
* Hash Map
* Two Pointers
* Matrix Traversal
* Dynamic Programming Optimization

---

⭐ If you found this repository helpful, consider giving it a **star**.
