class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>>pq;

        if(a>0){
            pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }

        string ans="";

        while(pq.size()>1){
            pair<int,char>first=pq.top();
            pq.pop();

            pair<int,char>second=pq.top();
            pq.pop();

            if(first.first>=2){
                ans.push_back(first.second);
                ans.push_back(first.second);

                first.first=first.first-2;

            }
            else{
                ans.push_back(first.second);
                first.first--;
            }

            if(second.first>=2 && second.first>first.first){
                ans.push_back(second.second);
                ans.push_back(second.second);

                second.first=second.first-2;

            }
            else{
                ans.push_back(second.second);
                second.first--;
            }

            if(first.first>0){
                pq.push(first);
            }
            if(second.first>0){
                pq.push(second);
            }
        }

        if(pq.size()==1){
            pair<int,char>first=pq.top();
            pq.pop();

            if(first.first>=2){
                ans.push_back(first.second);
                ans.push_back(first.second);
                first.first-=2;
            }
            else{
                ans.push_back(first.second);
                first.first--;
            }
        }


        return ans;

    
        
    }
};
