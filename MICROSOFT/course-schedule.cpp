class Solution {
	public:
		bool canFinish(int n, vector<vector<int>>& pre) {
			vector<int> dev[n];
			for(int i=0;i<pre.size();i++) dev[pre[i][1]].push_back(pre[i][0]);
			vector<int> temp;
			vector<int> in(n,0);
			queue<int>q;
			for(int i=0;i<n;i++){
				for(auto j:dev[i]) in[j]++;
			}
			for(int node=0;node<n;node++){
				if(!in[node]) q.push(node);
			}
			while(!q.empty()){
				int node=q.front();
				q.pop();
				temp.push_back(node);
				for(auto i:dev[node]){
					in[i]--;
					if(!in[i]) q.push(i);
				}
			}
			return temp.size()==n;
		}
	};