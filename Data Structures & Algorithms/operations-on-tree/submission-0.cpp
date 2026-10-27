class LockingTree {
public:
    vector<int>parent,owner;
    vector<vector<int>>children;
    
    LockingTree(vector<int>& p) 
        : parent(p),owner(p.size(),0), children(p.size()) {
            for(int i=1;i<p.size();i++){
                children[p[i]].push_back(i);
            }
        }

    bool lock(int num, int user) {
        if(owner[num]) return false;
        owner[num]=user;
        return true;
    }
    bool unlock(int num, int user) {
        if(owner[num]!=user) return false;
        owner[num]=0;
        return true;
    }
    bool upgrade(int num, int user) {
        if(owner[num]) return false;
        for(int v=parent[num];v!=-1;v=parent[v]){
            if(owner[v]!=0) return false;
        }

        vector<int>stack = children[num];
        vector<int>locked;
        while(!stack.empty()){
            int v = stack.back();
            stack.pop_back();
            if(owner[v]!=0){
                locked.push_back(v);
            }
            for(int child:children[v]){
                stack.push_back(child);
            }
        }
        if(locked.empty()) return false;
        for(int v:locked){
            owner[v] = 0;
        }
        owner[num] = user;
        return true;
    }
};
