class Solution {
public:
long long solve(long long j,vector<int>& nums, vector<int>& cost){
    long long sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=abs(nums[i]-j)*cost[i];
    }
    return sum;


}

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int left=INT_MAX;
       int right=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            left=min(left,nums[i]);
            right=max(right,nums[i]);
        }
        long long ans;

        while(left<=right){
            long long mid=left+(right-left)/2;
            if(solve(mid,nums,cost)<solve(mid+1,nums,cost)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }


        }
        return solve(ans,nums,cost);
        
    }
};