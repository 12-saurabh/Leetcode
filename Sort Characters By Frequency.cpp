class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int>mp;

        for(char i:s){
            mp[i]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto x:mp){
            pq.push({x.second,x.first});
        }

        string ans="";

        while(!pq.empty()){
            pair<int,char>p=pq.top();
            pq.pop();

            int freq=p.first;
            char ch=p.second;


            for(int i=0;i<freq;i++){
                ans+=ch;
            }


        }

        return ans;


        
    }
};
