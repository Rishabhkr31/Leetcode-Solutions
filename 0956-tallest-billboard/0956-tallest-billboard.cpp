class Solution {
public:
int dp[21][2*5000+1];
int solve(int i,int n,vector<int>& rods,int diff){
    if(i==n){
        if(diff==0)return 0;
        return INT_MIN;
    }
    if(dp[i][diff+5000]!=-1)return dp[i][diff+5000];
    int help1=solve(i+1,n,rods,diff);
    int help2=rods[i]+solve(i+1,n,rods,rods[i]+diff);
    int help3=solve(i+1,n,rods,diff-rods[i]);
    return dp[i][diff+5000]=max(help1,max(help2,help3));
}
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        memset(dp,-1,sizeof(dp));
        int ans= solve(0,n,rods,0);
        if(ans<0)return 0;
        else{
            return ans;
        }

    }
};