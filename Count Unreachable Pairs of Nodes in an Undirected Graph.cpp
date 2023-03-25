#define ll long long 

class Solution {
public:
    int bfs(int node, vector<vector<int>>&adj,vector<bool>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=true;
        int cnt=1;
        while(!q.empty()){
             node =q.front();
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it]=true;
                    cnt++;
                    q.push(it);
                }
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        ll cnt=0;
        ll sizeOfComp=0;// give the size of comp
        ll remainingNode=n;
        vector<bool>vis(n,false);
        
       for(int i=0;i<n;i++){
           // traverse for every node
           if(!vis[i]){
               sizeOfComp=bfs(i,adj,vis);
               cnt+=sizeOfComp*(remainingNode-sizeOfComp);
               remainingNode-=sizeOfComp;
           }
       }
        return cnt;
    }
};