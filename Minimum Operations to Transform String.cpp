class Solution {
public:
    int minOperations(string s) {

        int answer=0;

        for(char ch:s){
            int step=('a'-ch+26)%26;
            answer=max(answer,step);
        }

        return answer;
    }
};
