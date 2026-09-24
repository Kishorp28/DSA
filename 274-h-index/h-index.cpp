class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n =  citations.size();
        int ans = 0;
        for(int h = 1; h <= n ;h++){

            int c = 0; 
            for(int cit : citations){
                if(cit >= h){
                    c++;
                }
            }
            if(c >= h){
                ans = h;
            }
        }
     return ans;   
    }
};