class Solution {
public:
    int solve(vector<int> & nums,int l,int r){
        int n = r-l+1;

        vector<int> dp(n);
        dp[0] = nums[l];

        if(n ==1){
            return dp[0];
        }
        dp[1] = max(nums[l],nums[l+1]);

        for(int i = 2; i < n ; i++){
            dp[i]= max(dp[i-1],nums[l+i]+dp[i-2]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        return max(solve(nums,0,n-2),solve(nums,1,n-1));
        
    }
};