class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long > score(n,0);

        for(int i = 0 ; i < n ; i++){
            score[edges[i]] += i;
        }
        long long mx = -1;
        int node = -1;
        for(int i = 0 ; i < n ; i++){
            if(mx < score[i]){
                mx = score[i];
                node = i;

            }
        }
        return node;
    }
};