class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {    

        int n=landStartTime.size();
        
        int m=waterStartTime.size();

        int mini=INT_MAX;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){ 
                
                int sl=landStartTime[i];
                int fl=sl+landDuration[i];
                int sw=max(fl,waterStartTime[j]);
                int fw=sw+waterDuration[j];
                
                mini=min(mini,fw);
  
                int sw2=waterStartTime[j];
                int fw2=sw2+waterDuration[j];
                int sl2=max(fw2,landStartTime[i]);
                int fl2=sl2+landDuration[i];
                
                mini=min(mini,fl2);
            }
        }

        return mini;
    }
};
