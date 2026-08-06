class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_set<int> s;
        for(int b : bulbs){
            if(s.find(b) != s.end()){
                s.erase(b);
            }
            else{
                s.insert(b);
            }
        }
        vector<int> ans(s.begin(),s.end());
        sort(ans.begin(),ans.end());
        return ans;  
    }
};