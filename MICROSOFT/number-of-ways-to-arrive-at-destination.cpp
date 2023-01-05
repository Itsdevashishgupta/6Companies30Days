class Solution {
public:  
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>>dev(n);
        vector<long>temp(n,LONG_MAX);
        for(int i=0;i<roads.size();i++)
        {
            dev[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            dev[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int MOD = 1000000007;
        vector<long>ways(n,0); 
        ways[0] = 1;
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<>>pQ;
        pQ.push({0,0});
        temp[0] = 0;
        long cost;
        int node;        
        while(!pQ.empty())
        {
            cost = pQ.top().first;
            node = pQ.top().second;
            pQ.pop();
            if(temp[node]<cost)continue;
            for(auto &adj: dev[node])
            { 
                if(temp[node]+adj[1] < temp[adj[0]])
                {
                    temp[adj[0]] = temp[node]+adj[1];
                    ways[adj[0]] = ways[node];
                    pQ.push({temp[adj[0]],adj[0]});
                }
                else if(temp[node]+adj[1] == temp[adj[0]])
                {
                    ways[adj[0]] = (ways[adj[0]] + ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};