class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a,int b,int c){
        this->data=a;
        this->rowIndex=b;
        this->colIndex=c;
    }

};

class Compare{
    public:
    bool operator()(Info* a,Info* b){
        return a->data>b->data;
    }
};

class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<Info*,vector<Info*>,Compare>pq;

        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            int element=nums[i][0];

            int row=i;
            int col=0;

            Info* temp=new Info(element,row,col);
            pq.push(temp);

            maxi=max(maxi,element);
            mini=min(mini,element);
        }

        int ansstart=mini;
        int ansend=maxi;

        while(!pq.empty()){
            Info* temp=pq.top();

            int topdata=temp->data;
            int toprow=temp->rowIndex;
            int topcol=temp->colIndex;

            pq.pop();

            mini=topdata;

            if((maxi-mini)<(ansend-ansstart)){
                ansstart=mini;
                ansend=maxi;
            }

            if(topcol+1<nums[toprow].size()){
                int newelement=nums[toprow][topcol+1];

                maxi=max(maxi,newelement);

                Info* newinfo=new Info(newelement,toprow,topcol+1);

                pq.push(newinfo);
            }
            else{
                break;
            }

            delete temp;
        }

        vector<int>ans;

        ans.push_back(ansstart);
        ans.push_back(ansend);

        return ans;
        
    }
};
