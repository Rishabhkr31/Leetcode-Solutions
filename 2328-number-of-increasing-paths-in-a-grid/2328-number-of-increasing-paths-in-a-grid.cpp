class Solution {
public:
int mod=1e9+7;
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};
bool isvalid(int x,int y,vector<vector<int>>& grid){
    if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size())return false;

    return true;
}
int solve(int x,int y,vector<vector<int>>& grid,vector<vector<int>>&dp){
    if(dp[x][y]!=-1)return dp[x][y];
    int ans=1;
    for(int i=0;i<4;i++){
        int nx=x+dirx[i];
        int ny=y+diry[i];
        
        if(isvalid(nx,ny,grid) && grid[x][y]<grid[nx][ny]){
            ans=(ans%mod+(solve(nx,ny,grid,dp))%mod)%mod;

        }

    }
    return dp[x][y]=ans%mod;
}

    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        long long count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count=(count%mod+(solve(i,j,grid,dp))%mod)%mod;

            }
        }
        return (int)count%mod;
        
        
    }
};