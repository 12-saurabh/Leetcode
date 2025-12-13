class Solution {
public:
    bool isAlphanumeric(string s){
        if(s==""){
            return false;
        }


        bool f=true;
        for(char ch:s){
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || isdigit(ch) || ch=='_'){
                continue;
            }
            else{
                f=false;
                break;
            }
        }

        if(f){
            return true;
        }
        else{
            return false;
        }
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<pair<int,string>>ans;

        int n=code.size();

        unordered_map<string,int>mp={
            {"electronics",0},
            {"grocery",1},
            {"pharmacy",2},
            {"restaurant",3}};

        for(int i=0;i<n;i++){
            if(isAlphanumeric(code[i]) && mp.count(businessLine[i]) && isActive[i]){
                ans.push_back({mp[businessLine[i]],code[i]});
            }
        }

        sort(ans.begin(),ans.end());

        vector<string>res;
        for(auto i:ans){

            res.push_back(i.second);
        }

        return res;
        
    }
};
