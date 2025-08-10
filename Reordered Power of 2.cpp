
class Solution {
public:
    string find(int n){
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string ss=find(n);

        for(int i=0;i<32;i++){
            int target=1<<i;

            if(find(target)==ss){
                return true;
            }
        }
        return false;
        

        
    }
};
