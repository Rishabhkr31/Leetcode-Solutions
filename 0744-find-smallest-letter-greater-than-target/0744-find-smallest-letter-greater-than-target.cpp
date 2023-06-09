class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int t=(int)target;
        for(int i=0;i<n;i++){
            if(t<(int)letters[i]){
                return letters[i];

            }
        }

       return letters[0];     
        
    }
};