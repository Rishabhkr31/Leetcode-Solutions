class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        
        vector<long long>pre(n);
        
        vector<int>ans(n,-1);
        if(2*k+1>n){
            return ans;
        }
        for(int i=0;i<n;i++){
            if(i>0){
                pre[i]=pre[i-1]+nums[i];
            }
            else{
                pre[i]=nums[i];
            }
        }
      
   
        for(int i=k;i<n-k;i++){
            int left=i-k-1;
            int right=i+k;
            long long sum=0;
            if(left<0){
                sum=pre[right];
            }
            else{
                sum=pre[right]-pre[left];
            }
            int avg=sum/(2*k+1);
            ans[i]=avg;


        }
        return ans;
        
    }
};