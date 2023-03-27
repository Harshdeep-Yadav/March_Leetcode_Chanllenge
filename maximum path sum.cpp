class Solution {
public:
   int f(int m, int n, int i, int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
//        base case
        if(i==m-1&&j==n-1){ // last index of matrix
            return grid[i][j];
        }
       if(i>=m || j>=n){
            return INT_MAX; 
        }
        if(dp[i][j]!=-1) 
            return dp[i][j];
       
//recusrive call
        int x = f(m,n,i+1,j,grid,dp);
        int y = f(m,n,i,j+1,grid,dp);

//small calculation for recursion
        int ans = min(x,y) + grid[i][j];
        dp[i][j] = ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
//         start from 1 index(0,0) and go to till last index (m,n)
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m,n,0,0,grid,dp); 
    }
};

