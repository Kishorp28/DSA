class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<vector<int>,
        vector<vector<int>>,
        greater<vector<int>>> pq;

        for(auto &i : flights){
            adj[i[0]].push_back({i[1],i[2]});

        }
        vector<int> stop(n,INT_MAX);

        pq.push({0,src,0});
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();

            int cost = i[0];
            int node = i[1];
            int step = i[2];

            if(node == dst){
                return cost;
            }

            if(step > k || step > stop[node]){
                continue;
            }
            stop[node] = step;

            for(auto &[next,price] : adj[node]){
                pq.push({
                    price + cost,
                    next,
                    step+1
                });
            }
        }
        return -1;

        
    }
};