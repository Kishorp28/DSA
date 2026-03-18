# Array Problems – LeetCode Solutions (C++)

Collection of **Array-based LeetCode problems** solved in **C++**, categorized by difficulty.

---

# Easy

## 1. Pascal’s Triangle

🔗 https://leetcode.com/problems/pascals-triangle/

### Approach

Build each row using values from the previous row.

**Time Complexity:** `O(n²)`
**Space Complexity:** `O(n²)`

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(row);
        }

        return ans;
    }
};
```

---

## 2. Remove Duplicates from Sorted Array

🔗 https://leetcode.com/problems/remove-duplicates-from-sorted-array/

### Approach

Use **two pointers** to overwrite duplicates in-place.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) return n;

        int idx = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[idx++] = nums[i];
            }
        }

        return idx;
    }
};
```

---

# Medium

## 3. 3Sum Closest

🔗 https://leetcode.com/problems/3sum-closest/

### Approach

Sort the array and use **two pointers**.

**Time Complexity:** `O(n²)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int close = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (abs(sum - target) < abs(close - target)) {
                    close = sum;
                }

                if (sum < target) l++;
                else if (sum > target) r--;
                else return sum;
            }
        }

        return close;
    }
};
```

---

## 4. Game of Life

🔗 https://leetcode.com/problems/game-of-life/

### Approach

Use **in-place state encoding**:

* `-1` → live → dead
* `2` → dead → live

**Time Complexity:** `O(m × n)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> dir = {-1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;

                for (int x : dir) {
                    for (int y : dir) {
                        if (x == 0 && y == 0) continue;

                        int r = i + x;
                        int c = j + y;

                        if (r >= 0 && c >= 0 && r < m && c < n &&
                            abs(board[r][c]) == 1) {
                            live++;
                        }
                    }
                }

                if (board[i][j] == 1 && (live < 2 || live > 3))
                    board[i][j] = -1;

                if (board[i][j] == 0 && live == 3)
                    board[i][j] = 2;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] > 0 ? 1 : 0;
            }
        }
    }
};
```

---

## 5. Pairs of Songs Divisible by 60

🔗 https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

### Approach

Use **remainder frequency array (mod 60)**.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60, 0);
        int ans = 0;

        for (int t : time) {
            int r = t % 60;
            int need = (60 - r) % 60;

            ans += c[need];
            c[r]++;
        }

        return ans;
    }
};
```

---

## 6. 4Sum

🔗 https://leetcode.com/problems/4sum/

### Approach

Sort + two nested loops + two pointers.

**Time Complexity:** `O(n³)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1, r = n - 1;

                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++; r--;

                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                    else if (sum < target) l++;
                    else r--;
                }
            }
        }

        return ans;
    }
};
```

---

## 7. Find the Duplicate Number

🔗 https://leetcode.com/problems/find-the-duplicate-number/

### Approach

Use **Hash Map** to count frequencies.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for (int x : nums) {
            mp[x]++;
            if (mp[x] > 1) return x;
        }

        return -1;
    }
};
```

---

# Topics Covered

* Two Pointers
* Hashing
* Sorting
* Matrix Simulation
* Backtracking Concepts
* Prefix/Modulo Logic
