class Solution {
public:
     int fun(vector<int> &sat , int i , int c , vector<vector<int>> &dp ){
      if(i==sat.size()) return 0;
      if(dp[i][c] != -1) return dp[i][c];
      return dp[i][c] = max(fun(sat,i+1,c , dp) , sat[i]*(c) + fun(sat,i+1,c+1,dp));
  }

  int maxSatisfaction(vector<int>& sat) {
      sort(sat.begin() , sat.end()); 
      int n = sat.size();
      vector<vector<int>> dp(n , vector<int>(n+1,-1));
      return fun(sat , 0,1 , dp);
  }
};