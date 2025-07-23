
class Solution {
public:
    int maximumGain(string s, int x, int y) {

        char ch1='a';
        char ch2='b';

        int count1=0;
        int count2=0;

        int ans=0;

        if(x<y){
            swap(x,y);
            ch1='b';
            ch2='a';
        }

        for(char ch:s){
            if(ch==ch1){
                count1++;
            }
            else if(ch==ch2){
                if(count1>0){
                    count1--;
                    ans+=x;
                }
                else{
                    count2++;
                }
            }
            else{
                ans+=min(count1,count2)*y;
                count1=0;
                count2=0;
            }
        }

        if(count1!=0){
            ans+=min(count1,count2)*y;
        }


        return ans;


        
    }
};
