class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int,vector<int>>indexmap; // store every element index value in vector form
        for(int i=0;i<n;i++){
        indexmap[arr[i]].push_back(i); // 100-> [0,4] and so on
        }
        // simple bfs things
        vector<bool>vis(n); 
        
        vis[0]=true;
        queue<int>q;
        q.push(0);
        int steps=0;
        
        while(!q.empty()){
            // traversing the developed graph by bfs
            for(int i=q.size();i>0;i--){
            int node =q.front();
            q.pop();
                
            if(node==n-1) 
                return steps; // reached last index
            vector<int>&next =indexmap[arr[node]]; // ek node pe pahuch ke usse aage kha ja sakte bi btayega ye
            next.push_back(node-1);
            next.push_back(node+1);
                
            for(auto it : next){ 
                if(it>=0&&it<n&&!vis[it]){ // all condition
                        vis[it]=true;
                        q.push(it);
                }
            }
                indexmap[arr[node]].clear(); //ye map pe index di gai value ko hta dega jisse                                             //dubara na traver kar de
            }
            steps++;
        }
        return 0;
    }
};
    