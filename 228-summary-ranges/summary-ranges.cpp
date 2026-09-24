class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

       int i = 0;
       while(i < n){
            int s = nums[i];
            while(i < n-1 && nums[i]+1 == nums[i+1]){
                i++;
            }

            if(s != nums[i]){
                ans.push_back(to_string(s)+"->"+to_string(nums[i]));
            }else{
                ans.push_back(to_string(nums[i]));
            }
            i++;

       }  
       return ans;      
    }
};