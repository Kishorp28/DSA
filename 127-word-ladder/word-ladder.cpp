class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> s(wordList.begin(),wordList.end());

        if(!s.count(endWord)){
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){

            int size = q.size();

            while(size--){

                string word = q.front();q.pop();

                if(word == endWord){
                    return level;
                }

                for(int i = 0 ; i < word.size() ; i++){
                    char ori = word[i];

                    for(char c = 'a' ; c <= 'z' ; c++){
                        word[i] = c;

                        if(s.count(word)){
                            q.push(word);
                            s.erase(word);
                        }
                    }
                    word[i] = ori;
                }

            }
            level++;
        }

        return 0;
        
    }
};