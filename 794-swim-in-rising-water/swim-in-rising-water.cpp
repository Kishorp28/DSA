class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>,
        vector<vector<int>>,
        greater<vector<int>>> pq;
        
        int dir[4][2]={
            {1,0},{0,1},{-1,0},{0,-1}
        };
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        pq.push({grid[0][0],0,0});

        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();

            int t = i[0];
            int x = i[1];
            int y = i[2];

            if(vis[x][y]){
                continue;
            }

            vis[x][y] = true;

            if(x == n-1 && y == n-1){
                return t;
            } 

            for(auto &d : dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n ||vis[nx][ny]){
                    continue;
                }
                pq.push({
                    max(t,grid[nx][ny]),
                    nx,
                    ny
                });
            }


        }
        return -1;
    }
};