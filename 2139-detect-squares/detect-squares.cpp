class DetectSquares {
public:
    map<pair<int,int>,int> mp;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
        
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(auto &[q,c] : mp){
            int x2 = q.first;
            int y2 = q.second;

            if(y2 != y || x2 == x){
                continue;
            }

            int d = x2 - x;

            ans += c *mp[{x,y+d}] * mp[{x2,y+d}];
            ans += c *mp[{x,y-d}] * mp[{x2,y-d}];

        }
        return ans;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */