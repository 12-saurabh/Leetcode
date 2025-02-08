class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        vector<int>merge;
        for(int i=0;i<n;i++){
            merge.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++){
            merge.push_back(nums2[i]);
        }

        sort(merge.begin(),merge.end());
        int t=merge.size();
        if(t%2==0){
            return double(merge[t/2-1]+merge[t/2])/2;
        }
        else{
            return double(merge[t/2]);
        }


    }
};
