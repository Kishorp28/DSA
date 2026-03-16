# Array Problems – LeetCode Solutions (C++)

This repository contains **Array and Matrix problems from LeetCode** solved using **C++**.
Problems are categorized by **difficulty level**.

---

# Easy

## 1. Fibonacci Number

🔗 https://leetcode.com/problems/fibonacci-number/

### Approach

Use **recursion** to compute the Fibonacci sequence.

**Time Complexity:** `O(2^n)`
**Space Complexity:** `O(n)` (recursion stack)

```cpp
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};
```

---

## 2. Squares of a Sorted Array

🔗 https://leetcode.com/problems/squares-of-a-sorted-array/

### Approach

Square every element and then **sort the array**.

**Time Complexity:** `O(n log n)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = pow(nums[i], 2);
        }

        sort(nums.begin(), nums.end());
        return nums;
    }
};
```

---

# Medium

## 3. Rotate Image

🔗 https://leetcode.com/problems/rotate-image/

### Approach

Rotate the matrix **90° clockwise** using two steps:

1. **Transpose the matrix**
2. **Reverse each row**

**Time Complexity:** `O(n²)`
**Space Complexity:** `O(1)`

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

---

## 4. Word Search

🔗 https://leetcode.com/problems/word-search/

### Approach

Use **DFS + Backtracking** to explore possible paths in the grid.

Steps:

* Start DFS from each cell.
* Check all 4 directions.
* Mark the cell as visited during the path.
* Backtrack if the path fails.

**Time Complexity:** `O(m × n × 4^L)`
`m = rows`, `n = columns`, `L = length of word`

**Space Complexity:** `O(m × n)`

```cpp
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,
             vector<vector<bool>>& vis, int i, int j, int k) {

        if(k == word.size()) return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
           || vis[i][j] || board[i][j] != word[k]){
            return false;
        }

        vis[i][j] = true;

        bool found =
            dfs(board, word, vis, i+1, j, k+1) ||
            dfs(board, word, vis, i-1, j, k+1) ||
            dfs(board, word, vis, i, j+1, k+1) ||
            dfs(board, word, vis, i, j-1, k+1);

        vis[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n,false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dfs(board, word, vis, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
```

---

# Hard

## 5. Max Value of Equation

🔗 https://leetcode.com/problems/max-value-of-equation/

### Approach

Use a **deque (monotonic queue)** to maintain candidates that maximize the equation:

```
yi + yj + |xi - xj|
```

Since `xi < xj`, it becomes:

```
(yi - xi) + (yj + xj)
```

Maintain the best `(yi - xi)` values using a deque.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`

```cpp
