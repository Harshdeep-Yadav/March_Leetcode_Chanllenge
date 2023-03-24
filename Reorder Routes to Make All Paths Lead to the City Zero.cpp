class Solution {
public:
    int cnt=0;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : connections){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it : adj[node]){
               int neighbNode=it.first;
               int sign=it.second;
                if(!vis[neighbNode]){
                    cnt+=sign;
                    vis[neighbNode]=true;
                    q.push(neighbNode);
                }
            }
        }
        return cnt;
    }
};