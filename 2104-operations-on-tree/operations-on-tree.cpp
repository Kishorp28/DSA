class LockingTree {
public:
    vector<int> parent;
    vector<vector<int>> child;
    vector<int> locked;
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        int n = parent.size();
        locked.assign(n,-1);
        child.resize(n);
        for(int i = 0 ; i < n ; i++){
            if(parent[i] != -1){
                child[parent[i]].push_back(i);
            }
        } 
    }
    
    bool lock(int num, int user) {
        if(locked[num] != -1){
            return false;
        }
        locked[num] = user;
        return true;
        
    }
    
    bool unlock(int num, int user) {
        if(locked[num] != user){
            return false;
        }
        locked[num] = -1;
        return true;
    }
    bool dfs(int num){
        bool found = false;

        for(int c : child[num]){
            found |= dfs(c);
            if(locked[c] != -1){
                locked[c] = -1;
                found = true;
            }
        }
        return found;
        
    }
    
    bool upgrade(int num, int user) {
        if(locked[num] != -1){
            return false;
        }

        int curr = parent[num];

        while(curr != -1){
            if(locked[curr] != -1){
                return false;
            }
            curr = parent[curr];
        }

        bool hasDecentlocked = dfs(num);
        if(!hasDecentlocked){
            return false;
        }

        locked[num]= user;
        return true;

    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */