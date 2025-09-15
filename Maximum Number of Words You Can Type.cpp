class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        int count=0;
        string word="";

        for(int i=0;i<=text.size();i++){
           
            if(i==text.size() || text[i]==' '){
                
                bool flag=false;

                for(char ch:brokenLetters){
                   
                    if(word.find(ch)!=string::npos){
                        flag=true;
                        break;
                    }
                }

                if(!flag && !word.empty()){
                    count++;
                }
                word="";
            }
            else{
                word+=text[i];
            }
        }

        return count;
    }
};
