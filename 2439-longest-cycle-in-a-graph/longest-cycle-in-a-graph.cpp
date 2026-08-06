class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n);
        for(int e : edges){
            if(e != -1){
                indegree[e]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            int nxt = edges[curr];
            if(nxt != -1){
                indegree[nxt]--;
                if(indegree[nxt] == 0){
                    q.push(nxt);
                }
            }
        }

        vector<bool> vis(n,false);
        
        int ans = -1;
        for(int i = 0 ; i < n; i++){
            if(vis[i] || indegree[i]== 0){
               continue;
            }
            int c = 0; 
            int curr = i;
            while(!vis[curr]){
                c++;
                vis[curr] = true;
                curr = edges[curr];
            }
            ans = max(ans,c);
        }
        return ans;
    }
};