class Solution {
public:
    string makeLargestSpecial(string s) {
        
        int n=s.size();
        vector<string>ans;

        int count=0;
        int l=0;

        for(int r=0;r<n;r++){
            if(s[r]=='1'){
                count+=1;
            }
            else{
                count-=1;
            }

            if(count==0){
                string str=makeLargestSpecial(s.substr(l+1,r-l-1));
                ans.push_back("1"+str+"0");
                l=r+1;
            }
        } 

        sort(ans.rbegin(),ans.rend());

        string answer="";
        for(string i:ans){
            answer+=i;
        }

        return answer;
    }
};
