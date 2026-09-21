class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int n : nums){
            mp[n]++;
        }
        int n = nums.size()/2;

        for(auto &i : mp){
            if(i.second > n){
                return i.first;
            }
        }
        return 0;
        
    }
};