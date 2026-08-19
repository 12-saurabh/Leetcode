class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        sort(reservedSeats.begin(),reservedSeats.end());
        
        int i=0;
        int ans=0;

        int row=0;
        while(i<reservedSeats.size()){
            int x=reservedSeats[i][0];

            unordered_map<int,int>mp;

            while(i<reservedSeats.size() && reservedSeats[i][0]==x){
                mp[reservedSeats[i][1]]=1;
                i++;
            }

            if(mp[2]==0 && mp[3]==0 && mp[4]==0 && mp[5]==0 && mp[6]==0 && mp[7]==0 && mp[8]==0 && mp[9]==0){
                ans+=2;
            }
            else{
                if(mp[2]==0 && mp[3]==0 && mp[4]==0 && mp[5]==0){
                    ans+=1;
                }
                else if(mp[4]==0 && mp[5]==0 && mp[6]==0 && mp[7]==0){
                    ans+=1;
                }
                else if(mp[6]==0 && mp[7]==0 && mp[8]==0 && mp[9]==0){
                    ans+=1;
                }
            }

            row++;
        }

        return ans+(n-row)*2;

    }
};
