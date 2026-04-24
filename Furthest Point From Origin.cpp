class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int count=0;
        int b=0;
        for(char ch:moves){
            if(ch=='L'){
                count--;
            }
            else if(ch=='_'){
                b++;
            }
            else{
                count++;
            }
        }

        return abs(count)+b;
        
    }
};
