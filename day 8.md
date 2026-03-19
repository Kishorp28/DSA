# Array Problems – LeetCode Solutions (C++)

Collection of **Medium-level Array problems** solved in C++.

---

# Medium

## 1. K-diff Pairs in an Array

🔗 https://leetcode.com/problems/k-diff-pairs-in-an-array/

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp ;
        for(int i : nums){
            mp[i]++;
        }  

        int c = 0 ;

        for(auto& i : mp){
            if(k == 0 ){
                if(i.second > 1){
                    c++;
                }
            }
            else{
                if(mp.count(i.first + k)){
                    c++;
                }
            }
        }
        return c;  
    }
};
```

---

## 2. Subsets

🔗 https://leetcode.com/problems/subsets/

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        dfs(0, nums, temp, res);
        return res;   
    }

    void dfs(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>> &res){
        res.push_back(temp);

        for(int i = idx; i < nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(i+1, nums, temp, res);
            temp.pop_back();
        }
    }
};
```

---

## 3. Invalid Transactions

🔗 https://leetcode.com/problems/invalid-transactions/

```cpp
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();

        vector<string> name(n), city(n);
        vector<int> amt(n), time(n);
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            vector<string> part;
            string temp = "";
            string s = transactions[i];

            for (char i : s) {
                if (i == ',') {
                    part.push_back(temp);
                    temp = "";
                } else {
                    temp += i;
                }
            }

            part.push_back(temp);

            name[i] = part[0];
            time[i] = stoi(part[1]);
            amt[i] = stoi(part[2]);
            city[i] = part[3];
        }

        for (int i = 0; i < n; i++) {
            bool invalid = false;

            if (amt[i] > 1000) {
                invalid = true;
            }

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (name[i] == name[j] && city[i] != city[j] &&
                    abs(time[i] - time[j]) <= 60) {
                    invalid = true;
                }
            }

            if (invalid) {
                ans.push_back(transactions[i]);
            }
        }

        return ans;
    }
};
```

---

## 4. Jump Game

🔗 https://leetcode.com/problems/jump-game/

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i > maxjump){
                return false;
            }
            maxjump = max(maxjump, i + nums[i]);
        }

        return true;
    }
};
```

---

## 5. Subarray Sums Divisible by K

🔗 https://leetcode.com/problems/subarray-sums-divisible-by-k/

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int sum = 0, c = 0;

        for(int i : nums){
            sum += i;

            int rem = sum % k;
            if(rem < 0){
                rem += k;
            }

            if(mp.count(rem)){
                c += mp[rem];
            }

            mp[rem]++;
        }

        return c;   
    }
};
```

---

# Topics Covered

* Hashing
* Backtracking
* Greedy
* Prefix Sum
* String Parsing
