class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>ans;
        int temp=0;
        int count=0;
    

        if(n==1){
        string t=to_string(nums[0]);
        ans.push_back(t);
        return ans;
        }
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]+1){
                count++;
            }
            
            else{
                if(count==0){
                    string s1=to_string(nums[i]);
                    ans.push_back(s1);
                    temp=i+1;
                    
                }
                else{
                       string s2=to_string(nums[temp]);
                    string s3=to_string(nums[i]);
                 string s=s2+"->"+s3;
                 ans.push_back(s);
                    temp=i+1;
                    count=0;
                }
            }
                if(i+1==n-1){
                       
                    if(nums[i+1]!=nums[i]+1){
                        string s4=to_string(nums[i+1]);
                        ans.push_back(s4);
                    }
                    else if(nums[i+1]==nums[i]+1){
                       
                        string s4=to_string(nums[i+1]);
                        string s6=to_string(nums[temp]);
                        string s5=s6+"->"+s4;
                        ans.push_back(s5);

                    }
                }
            

        }
        return ans;

        
    }
};