class NumArray {
    
public:
    vector<int> bit;
    vector<int> nums;
    int n;
    void add(int idx,int val){
        idx++;

        while(idx <= n){
            bit[idx] += val;
            idx += idx & - idx;
        }

    }
    
    int prefix(int idx){
        idx++;

        int sum = 0;

        while(idx >0){
            sum += bit[idx];
            idx -= idx & - idx;
        }
        return sum;

    }
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.resize(n+1,0);

        for(int i = 0 ; i< n ; i++){
            add(i,nums[i]);
        }
        
    }
    
    void update(int index, int val) {
        int d = val - nums[index];

        nums[index] = val;
        add(index,d)  ; 
    }
    
    int sumRange(int left, int right) {
        return prefix(right) - prefix(left-1);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */