# Recursion

## Mixed

### Letter Combinations of a Phone Number

https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

```cpp id="x9k2lm"
class Solution {
public:
    vector<string> ans;
    void solve(int idx,string digit,vector<string> &mp,string temp){
        if(idx == digit.size()){
            ans.push_back(temp);
            return;
        }

        string l = mp[digit[idx]-'0'];
        for(char c:l){
            solve(idx+1,digit,mp,temp+c);
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty())  return{};
        vector<string> mp = {
            ""," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        solve(0,digits,mp,"");
        return ans;
        
    }
};
```

---

### Partition to K Equal Sum Subsets

https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

---

### Maximum Length of a Concatenated String with Unique Characters

https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

---

### Flood Fill

https://leetcode.com/problems/flood-fill/description/

---

### Word Search

https://leetcode.com/problems/word-search/description/

---

### N-Queens

https://leetcode.com/problems/n-queens/description/
