class Solution {
public:
    int r , c;
    int dir[4][2]={
        {-1,0},
        {0,1},
        {1,0},
        {0,-1}
    };
    int area = 0;
    void bfs(vector<vector<int>> &grid,int i ,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 0;
        int count = 1;

        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();

            for(auto &d : dir){
                int nx = x+ d[0];
                int ny = y + d[1];

                if(nx >= 0 && ny >= 0 && nx < r && ny < c && grid[nx][ny] == 1){
                    count++;
                    
                    grid[nx][ny] = '0';
                    q.push({nx,ny});
                }
            }
        }
        area = max(area,count);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(grid[i][j] == 1){
                    bfs(grid,i,j);

                }
            }
        }
        return area;
        
    }
};