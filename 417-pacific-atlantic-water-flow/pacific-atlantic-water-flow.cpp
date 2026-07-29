class Solution {
public:
int r,c;
int dir[4][2]={
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};
    void dfs(vector<vector<int>> &heights,vector<vector<bool>> &vis,int i,int j){
        vis[i][j] = true;

        for(auto &d :dir){
            int nx = d[0] + i;
            int ny = d[1] + j ;

            if(nx < 0 || ny < 0 || nx >= r || ny >= c || heights[nx][ny] < heights[i][j] || vis[nx][ny]){
                continue;
            }

            dfs(heights,vis,nx,ny);

        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r = heights.size();
        c = heights[0].size();

        vector<vector<bool>> pacific(r,vector<bool>(c,false));
        vector<vector<bool>> atlantic(r,vector<bool>(c,false));

        for(int i = 0 ; i < r;i++){
            dfs(heights,pacific,i,0);
        }

        for(int j = 0 ; j < c;j++){
            dfs(heights,pacific,0,j);
        }

        for(int i = 0 ; i < r;i++){
            dfs(heights,atlantic,i,c-1);
        }

        for(int j = 0 ; j < c;j++){
            dfs(heights,atlantic,r-1,j);
        }
        vector<vector<int>> ans;

        for(int i = 0 ; i < r; i++){
            for(int j = 0 ; j < c; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;  
    }
};
