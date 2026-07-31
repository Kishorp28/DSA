class Solution {
public:
unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
vector<string> ans;

    void dfs(string s){
        while(!adj[s].empty()){
            string next = adj[s].top();
            adj[s].pop();
            dfs(next);

        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto & t : tickets){
            adj[t[0]].push(t[1]);
        }
        dfs("JFK");

        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};
