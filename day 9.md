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

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {

            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
```

---

### Subsets

https://leetcode.com/problems/subsets/description/

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        dfs(0,nums,temp,res);
        return res;   
    }
    void dfs(int idx,vector<int>& nums,vector<int>& temp,vector<vector<int>> &res){
        res.push_back(temp);
        for(int i = idx ; i < nums.size() ; i++){
            temp.push_back(nums[i]);
            dfs(i+1,nums,temp,res);
            temp.pop_back();
        }
    }
};
```

---

### Permutations

https://leetcode.com/problems/permutations/description/

```cpp
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& temp,
                              vector<vector<int>>& ans, vector<bool>& used) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            temp.push_back(nums[i]);
            solve(nums, temp, ans, used);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        solve(nums, temp, ans, used);
        return ans;
    }
};
```

---

### Permutations II

https://leetcode.com/problems/permutations-ii/description/

```cpp
class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
               vector<bool>& used) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(used[i]) continue;
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]){
                continue;
            }
            used[i] = true;
            temp.push_back(nums[i]);
            solve(nums,ans,temp,used);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        solve(nums, ans, temp, used);
        return ans;
    }
};
```
