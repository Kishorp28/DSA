# Recursion

## Mixed

### Subsets II

https://leetcode.com/problems/subsets-ii/description/

```cpp id="k3p1zs"
class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& temp) {
        ans.push_back(temp);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,ans,temp);
            temp.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, ans, temp);
        return ans;
    }
};
```

---

### Combinations

https://leetcode.com/problems/combinations/description/

```cpp id="r8g5xy"
class Solution {
public:
    void solve(int start,int k,int n,vector<vector<int>> &ans,vector<int> & temp){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i= start ; i <= n ; i++){
            temp.push_back(i);
            solve(i+1,k,n,ans,temp);
            temp.pop_back();

        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,k,n,ans,temp);
        return ans;
        
    }
};
```

---

### Combination Sum

https://leetcode.com/problems/combination-sum/description/

```cpp id="0g6t3l"
class Solution {
public:
    void solve(int idx, vector<int>& nums, int target, vector<vector<int>>& ans,
               vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;
        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);

            solve(i, nums, target - nums[i], ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, ans, temp);
        return ans;
    }
};
```

---

### Combination Sum II

https://leetcode.com/problems/combination-sum-ii/description/

```cpp id="1f0z9n"
class Solution {
public:
    void solve(int idx, vector<int>& nums, int target, vector<vector<int>>& ans,
               vector<int>& temp) {

                if(target == 0){
                    ans.push_back(temp);
                    return;
                }
                if(target < 0)  return;
                for(int i= idx; i < nums.size() ; i++){
                    if(i > idx && nums[i] == nums[i-1]){
                        continue;
                    }
                    if(nums[i] > target){
                        break;
                    }

                    temp.push_back(nums[i]);
                    solve(i+1,nums,target-nums[i],ans,temp);
                    temp.pop_back();
                }
               }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp ;
        solve(0,candidates,target,ans,temp);
        return ans;
    }
};
```

---

### Combination Sum III

https://leetcode.com/problems/combination-sum-iii/description/

```cpp id="9d5m2a"
class Solution {
public:
    void solve(int idx,int k,int target,vector<vector<int>> &ans,vector<int>&temp ){
        if(target == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || temp.size() > k)    return;
        for(int i = idx; i <= 9 ; i++){
            temp.push_back(i);
            solve(i+1,k,target-i,ans,temp);
            temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,k,n,ans,temp);
        return ans;
        
    }
};
```
