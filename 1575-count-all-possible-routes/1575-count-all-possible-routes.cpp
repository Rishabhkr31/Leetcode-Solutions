class Solution {
public:
int mod=1e9+7;
int solve(int start,int fuel,int finish,int n,vector<int>& locations,vector<vector<int>>&dp){
    if(fuel<0)return 0;
    if(dp[start][fuel]!=-1)return dp[start][fuel];
    int ans=0;
    if(start==finish)ans++;
    for(int i=0;i<n;i++){
        if(i==start || abs(locations[i]-locations[start])>fuel)continue;
        ans+=(solve(i,fuel-abs(locations[i]-locations[start]),finish,n,locations,dp))%mod;
        ans%=mod;
    }
    return dp[start][fuel]=ans%mod;
}
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        return solve(start,fuel,finish,n,locations,dp);

        
    }
};