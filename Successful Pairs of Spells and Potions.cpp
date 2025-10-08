class Solution {
public:
    int binarySearch(int k,vector<int>&potions,int m){
        int i=0;
        int j=m-1;

        while(i<j){
            int mid=i+(j-i)/2;
            if(potions[mid]>=k){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }

        return i;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int n=spells.size();
        int m=potions.size();

        vector<int>ans(n,0);

        sort(potions.begin(),potions.end());

        int maxi=potions[m-1];

        for(int i=0;i<n;i++){
            int s=spells[i];

            long long k=ceil((double)success/s);

            if(k<=maxi){
                ans[i]=m-binarySearch(k,potions,m);
            }
        }

        return ans;
        
    }
};
