class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>ans;
        for(int i=0;i<n-1;i++){
            ans.push_back(weights[i]+weights[i+1]);
        }
        sort(ans.begin(),ans.end());
        long long int minsum=0;
        long long int maxsum=0;

        for(int i=0;i<k-1;i++){
            minsum+=ans[i];
            maxsum+=ans[n-2-i];

        }
        return maxsum-minsum;

        
    }
};