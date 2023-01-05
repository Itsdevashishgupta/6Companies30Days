class Solution {
private:
    vector<vector<int>> dev;
    vector<int> temp;
    vector<int> path_B;
    int find_path_B(int n){
        if(n == 0){path_B.push_back(n); return 1;}  
        if(temp[n] == 1){return 0;}
        temp[n] = 1;
        for(auto &v: dev[n]){
            int flag = find_path_B(v);
            if(flag != 1){continue;}
            path_B.push_back(n);
            return 1;
        }
        return 0;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int len_n = amount.size();
        dev.resize(len_n, vector<int>());
        for(auto &E:edges){
            int u = E[0], v = E[1];
            dev[u].push_back(v);
            dev[v].push_back(u);
        }
        temp.resize(len_n, 0);
        find_path_B(bob);
        amount[bob] = 0;
        path_B.pop_back();
        using pii = pair<int,int>;
        int val = amount[0];
        queue<pii> Q({{0,val}});
        int Max = INT_MIN;
        vector<int> visited2(len_n, 0);
        visited2[0] = 1;
        while(!Q.empty()){
            int len_Q = Q.size();
            int n_bob = -1;
            if(!path_B.empty()){
                n_bob = path_B.back();
                path_B.pop_back();
            }
            while(len_Q--){
                int u = Q.front().first;
                int val = Q.front().second;
                Q.pop();
                if(dev[u].size() == 1 && u != 0){ 
                    Max = max(Max, val);
                    continue;
                } 
                for(int &v: dev[u]){
                    if(visited2[v] == 1){continue;}
                    visited2[v] = 1; 
                    if(v != n_bob){
                        Q.push({v, val+ amount[v]});
                        continue;
                    }       
                    Q.push({v, val+amount[v]/2});
                }
            }
            if(n_bob != -1){amount[n_bob] = 0;}
        }
        return Max;  
    }
};