class Solution {
public:
    int count = 0;
    int n = 0;
    void pali(string s,int l, int r){
        while(l >= 0  && r < n && s[l] == s[r]){
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        n = s.size();
        for(int i = 0 ; i < n ; i++){
            pali(s,i,i);
            pali(s,i,i+1);
        }
        return count;
    }
};
