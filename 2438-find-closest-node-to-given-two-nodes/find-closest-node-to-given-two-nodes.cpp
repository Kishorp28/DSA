class Solution {
public:
    int n;
    vector<int> distance(vector<int> &edges,int src){
        vector<int> dist(n,-1);
        int d = 0;

        while(src != -1 && dist[src] == -1){
            d++;
            dist[src] = d;
            src = edges[src];
        }
        return dist;

    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int> dist1 = distance(edges,node1);
        vector<int> dist2 = distance(edges,node2);

        int ans = -1;

        int best = INT_MAX;

        for(int i = 0; i < n ; i++){
            if(dist1[i] == -1 || dist2[i] == -1){
                continue;
            }

            int mx = max(dist1[i],dist2[i]);

            if(mx < best){
                best = mx;
                ans = i;
            }
        }
        return ans;
        
        
    }
};