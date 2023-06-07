class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(a>0 || b>0 || c>0){
            int m=a & 1;
            int n= b&1;
            int o= c&1;
            if(o==0){
                count+=m+n;
            }
            else{
                if(m==0 && n==0){
                    count+=1;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return count;
        
    }
};