# Array Problems – LeetCode Solutions (C++)

This repository contains solutions to **Array problems from LeetCode** in C++.

---

# Easy

## 1. Remove Duplicates from Sorted Array

🔗 https://leetcode.com/problems/remove-duplicates-from-sorted-array/

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <=1){
            return n;
        }
        int idx = 1;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] != nums[i-1]){
                nums[idx++] = nums[i]; 
            }
        }
    return idx;
    }
};
```

---

# Medium

## 2. Combination Sum

🔗 https://leetcode.com/problems/combination-sum/

> Code not added yet

---

## 3. Jump Game II

🔗 https://leetcode.com/problems/jump-game-ii/

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int far = 0;
        int jump = 0;
        for (int i = 0; i < n - 1; i++) {
            far = max(far, i + nums[i]);
            if (i == curr) {
                jump++;
                curr = far;
            }
        }
        return jump;
    }
};
```

---

## 4. Maximum Points You Can Obtain from Cards

🔗 https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(n<k) return -1;

        int sum = 0 ;
        for(int i = 0 ; i < k ; i++){
            sum += cardPoints[i];
        }

        int maxsum = sum ;
        int r = n -1 ;

        for(int i = k-1 ; i >= 0; i--){
            sum -= cardPoints[i];
            sum += cardPoints[r];
            r--;

            maxsum = max(maxsum,sum);
        }
        return maxsum; 
    }
};
```

---

## 5. Maximum Area of a Piece of Cake

🔗 https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

> Code not added yet

---

## 6. Max Area of Island

🔗 https://leetcode.com/problems/max-area-of-island/

> Code not added yet

---

## 7. Find All Duplicates in an Array

🔗 https://leetcode.com/problems/find-all-duplicates-in-an-array/

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>s;
        vector<int>n;
        for(int x : nums){
            s[x]++;
            if(s[x]==2){
                n.push_back(x);
            }
    }
    return n;
    }
};
```

---

# Notes

* Some problems are listed for tracking and will be implemented later.
* Solutions are written in C++.
