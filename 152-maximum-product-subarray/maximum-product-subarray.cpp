class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxpro = nums[0];
        int minpro = nums[0];
        int ans = nums[0];

        for(int i = 1 ; i < n ; i++){
            if(nums[i] < 0){
                swap(maxpro,minpro);
            }

            maxpro = max(maxpro*nums[i],nums[i]);
            minpro = min(nums[i],nums[i] * minpro);

            ans = max(ans,maxpro);
        }
        return ans;
        
    }
};
