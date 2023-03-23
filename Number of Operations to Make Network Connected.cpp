class Solution {
public:
    void dfs(vector<int> adj[],vector<bool> &vis,int src){
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& nums) {
        int len =nums.size();
        if(len<n-1){
            return -1;
        }
        vector<int>adj[n];
        for(auto it:nums){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool>vis(n,false);
        int ans=0; // connected_Component
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                ans++;
            }
        }
        return ans-1;
    }
};