class Solution {
public:
    int bestClosingTime(string customers) {

        int n=customers.size();

        int penalty=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                penalty++;
            }
        }

        int mini=penalty;
        int hr=0;

        for(int i=0;i<n;i++){
            char ch=customers[i];

            if(ch=='Y'){
                penalty--;
            }
            else{
                penalty++;
            }

            if(penalty<mini){
                hr=i+1;
                mini=penalty;
            }
        }

        return hr;


        
    }
};
