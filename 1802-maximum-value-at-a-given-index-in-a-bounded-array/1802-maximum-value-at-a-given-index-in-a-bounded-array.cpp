#define l1 long long int
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int emptyr=n-index-1;
        int emptyl=index;
        l1 ans=0;
        int l=1;
        int r=maxSum;
        while(l<=r){
            l1 lsum=0;
            l1 rsum=0;
            int mid=l+(r-l)/2;
            l1 el=mid-1;
            if(emptyr<=el){
                 rsum=el*(el+1)/2 -((el-emptyr)*((el-emptyr)+1))/2;

            }
            else{
                 rsum=el*(el+1)/2 +(emptyr-el);
            }
            if(emptyl<=el){
                 lsum=el*(el+1)/2 -((el-emptyl)*((el-emptyl)+1))/2;

            }
            else{
                 lsum=el*(el+1)/2 +(emptyl-el);
            }
            l1 sum=lsum+rsum+mid;
            if(sum<=maxSum){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }

        }
        return ans;

        
    }
};