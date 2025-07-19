class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        int n=folder.size();
        sort(folder.begin(),folder.end());

        vector<string>ans;
        ans.push_back(folder[0]);

        for(int i=1;i<n;i++){
            string lastf=ans.back();
            lastf+="/";

            if(folder[i].substr(0,lastf.size())!=lastf){
                ans.push_back(folder[i]);
            }
        }

        return ans;


        
    }
};
