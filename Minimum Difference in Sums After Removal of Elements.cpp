class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int size=nums.size();

        int n=size/3;

        vector<long long>left(size,0),right(size,0);

        priority_queue<int>maxHeap;

        long long lsum=0;
        for(int i=0;i<size;++i){
            maxHeap.push(nums[i]);
            lsum+=nums[i];

            if(maxHeap.size()>n){
                lsum-=maxHeap.top();
                maxHeap.pop();
            }

            if(i>=n-1){
                left[i]=lsum;
            }

        }

        priority_queue<int,vector<int>,greater<>>minHeap;

        long long rsum=0;
        for(int i=size-1;i>=0;--i){
            minHeap.push(nums[i]);
            rsum+=nums[i];

            if(minHeap.size()>n){
                rsum-=minHeap.top();
                minHeap.pop();
            }

            if(i<=size-n){
                right[i]=rsum;
            }
        }

        long long d=LLONG_MAX;

        for(int i=n-1;i<=size-n-1;++i){
            d=min(d,left[i]-right[i+1]);
        }

        return d;




        
    }
};
