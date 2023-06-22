class Solution {
public:
int solve(int i,int p,int n,vector<int>& prices, int fee,vector<vector<int>> &dp){
    if(i>=n)return 0;
    if(dp[i][p]!=-1)return dp[i][p];
    int buy,sell,notbuy,notsell;
    if(p==0){
         buy=-prices[i]+solve(i+1,1,n,prices,fee,dp);
         notbuy=solve(i+1,0,n,prices,fee,dp);
          dp[i][p]=max(buy,notbuy);
    }
    else{
         sell=prices[i]+solve(i+1,0,n,prices,fee,dp)-fee;
         notsell=solve(i+1,1,n,prices,fee,dp);
          dp[i][p]=max(sell,notsell);
    }
    return dp[i][p];
    
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,n,prices,fee,dp);


        
    }
};