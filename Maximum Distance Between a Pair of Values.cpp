class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int m=nums1.size();
        int n=nums2.size();
        
        int maxi=0;
        for(int i=0;i<m;i++){
            int low=i;
            int high=n-1;

            while(low<=high){
                int mid=low+(high-low)/2;

                if(nums1[i]<=nums2[mid] && i<=mid){
                    maxi=max(maxi,mid-i);
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }

        }

        return maxi;
    }
};
