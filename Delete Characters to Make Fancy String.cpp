class Solution {
public:
    string makeFancyString(string s) {

        int n=s.size();

        string ans="";
        int count=1;
        char temp=s[0];
        ans+=temp;

        for(int i=1;i<n;i++){
            if(s[i]==temp){
                count++;
            }
            else{
                temp=s[i];
                count=1;
            }

            if(count<3){
                ans+=s[i];
            }
        }

        return ans;

        
    }
};
