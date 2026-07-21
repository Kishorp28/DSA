class Trie
{
    public:
    Trie* child[26];
    bool end;
    Trie(){
        end = false;
        for(int i = 0 ; i < 26 ; i++){
            child[i] = NULL;
        }
    }
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root = new Trie();
        
    }
    
    void addWord(string word) {
        Trie* curr = root;
        for(char i : word){
            int idx = i - 'a';
            if(curr->child[idx] == NULL){
                curr->child[idx] = new Trie();

            }
            curr = curr->child[idx];
        }
        curr->end = true;
        
    }
    bool dfs(string word,int idx,Trie* curr){
        if(idx == word.size()){
            return curr->end;
        }

        if(word[idx] == '.'){
            for(int i = 0 ; i < 26 ; i++){
                if(curr->child[i] && dfs(word,idx+1,curr->child[i])){
                    return true;
                }
            }
            return false;
        }

        int id = word[idx]-'a';
        if(curr->child[id] == NULL){
            return false;   
        }
        return dfs(word,idx+1,curr->child[id]);
    }
    
    bool search(string word) {
        return dfs(word,0,root);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */