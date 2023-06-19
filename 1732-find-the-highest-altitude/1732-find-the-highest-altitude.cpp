class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int n=gain.size();
        int ans=0;
        for(int i=0;i<n;i++){
            sum=sum+gain[i];
            ans=max(ans,sum);
        }
        return ans;
        
    }
};