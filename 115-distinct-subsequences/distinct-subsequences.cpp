class Solution {
public:
    int n,m;
    vector<vector<long long>> dp;
    long long dfs(string s,string t,int i,int j){
        if(j == m){
            return 1;
        }
        if(i == n){
            return 0;;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        

        if(s[i] == t[j]){
            return dp[i][j] = dfs(s,t,i+1,j)+dfs(s,t,i+1,j+1);
        }

        return dp[i][j] = dfs(s,t,i+1,j);
    }

    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        dp.assign(n,vector<long long>(m,-1));

        return dfs(s,t,0,0);

        
    }
};