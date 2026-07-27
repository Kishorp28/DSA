class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans= INT_MIN;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            int curr = 0;
            for(int j = i+1; j < nums.size(); j++){
                curr = (nums[i]-1)*(nums[j]-1);
                ans = max(ans,curr);
            }
            
            
        }
        return ans;
        
    }
};