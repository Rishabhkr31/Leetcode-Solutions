class Solution {
public:
 int ans=0;
void solve(int i,int count,int n,vector<vector<int>>& requests,vector<int>&in){
    if(i==requests.size()){
        for(int j=0;j<n;j++){
            if(in[j]!=0){
                return;
            }
        }
        ans=max(ans,count);
        return;
    }
        in[requests[i][0]]--;
        in[requests[i][1]]++;
        solve(i+1,count+1,n,requests,in);
         in[requests[i][0]]++;
        in[requests[i][1]]--;
        solve(i+1,count,n,requests,in);
        

        

    
}
    int maximumRequests(int n, vector<vector<int>>& requests) {
   
        vector<int>in(n,0);
        solve(0,0,n,requests,in);
        return ans;

        
    }
};