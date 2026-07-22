class Trie{
    public:
    Trie* child[26];
    string word;
    Trie(){
        word="";
        for(int i = 0 ; i < 26; i++){
            child[i] = NULL;
        }
    }

};


class Solution {
public:
    vector<string> ans;
    int m,n;
    Trie* root = new Trie();
    void insert(string word){
        Trie* curr = root;
        for(char i : word){
            int idx = i - 'a';

        if(curr->child[idx] == NULL){
            curr->child[idx] = new Trie();
        }
        curr = curr->child[idx];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board,int r,int c,Trie* node){
        if(r<0 || c< 0 || r>= m || c >= n ){
            return;
        }
        char i = board[r][c];
        if(i == '#'){
            return;
        }
        if(node->child[i-'a'] == NULL){
            return;
        }
        node = node->child[i-'a'];

        if(node->word != ""){
            ans.push_back(node->word);
            node->word = "";

        }
        board[r][c] = '#';
        dfs(board,r+1,c,node);
        dfs(board,r,c+1,node);
        dfs(board,r-1,c,node);
        dfs(board,r,c-1,node);
        board[r][c] = i;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string w: words){
            insert(w);
        }
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                dfs(board,i,j,root);
            }
        }
        return ans;

    }
};
