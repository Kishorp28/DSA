# Array

## Easy

### Merge Sorted Array

https://leetcode.com/problems/merge-sorted-array/description/

```cpp
class RandomizedSet {
public:
    vector<int> res ;
    unordered_map<int,int> mp;
    RandomizedSet() {         
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end() ){
            return false;
        }
        res.push_back(val);
        int idx = res.size()-1;
        mp[val] = idx;
        return true;
        
    }
    
    bool remove(int val) {
        if(mp.find(val) !=  mp.end()){
            int last = res.back();
            int idx = mp[val];

            res[idx]= last;
            mp[last] = idx;

            res.pop_back();
            mp.erase(val);
            return true;

        }else{
            return false;
        }

        
    }
    
    int getRandom() {

        return res[rand() % res.size() ];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```

---

### Move Zeroes

https://leetcode.com/problems/move-zeroes/description/

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }  
        }
        while(j < nums.size()){
            nums[j] = 0;
            j++;

        }
        
    }
};
```

---

## Medium

### Product of Array Except Self

https://leetcode.com/problems/product-of-array-except-self/description/

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * right;
            right *= nums[i];
        }
        return ans;
    }
};
```

---

### Insert Delete GetRandom O(1)

https://leetcode.com/problems/insert-delete-getrandom-o1/description/

```cpp
class RandomizedSet {
public:
    vector<int> res ;
    unordered_map<int,int> mp;
    RandomizedSet() {         
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end() ){
            return false;
        }
        res.push_back(val);
        int idx = res.size()-1;
        mp[val] = idx;
        return true;
        
    }
    
    bool remove(int val) {
        if(mp.find(val) !=  mp.end()){
            int last = res.back();
            int idx = mp[val];

            res[idx]= last;
            mp[last] = idx;

            res.pop_back();
            mp.erase(val);
            return true;

        }else{
            return false;
        }

        
    }
    
    int getRandom() {

        return res[rand() % res.size() ];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```

---

## Hard

### Largest Rectangle in Histogram

https://leetcode.com/problems/largest-rectangle-in-histogram/description/

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n= heights.size();
        int maxarea = 0 ;

        for(int i = 0 ; i <= n; i++){

            int h = (i == n )? 0 :heights[i];

            while( !st.empty() && h < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                int width = right - left -1;
                maxarea = max(maxarea,width*height);
            }
            st.push(i);
        }
        return maxarea;  
    }
};
```

