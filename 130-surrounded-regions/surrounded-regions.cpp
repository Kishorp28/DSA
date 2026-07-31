class Solution {
public:
int r,c;

void dfs(vector<vector<char>>& board,int i,int j){
    
        if(i < 0 || j < 0 || i >= r || j >= c || board[i][j] != 'O'){
            return;
        }
        board[i][j] = '#';
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);  
}
    
    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();
        for(int i = 0 ; i < r ; i++){
            dfs(board,i,0);
            dfs(board,i,c-1);
        }
        for(int i = 0 ; i < c ; i++){
            dfs(board,0,i);
            dfs(board,r-1,i);
        }
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }

        
    }
};
