class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(),asteroids.end());

        long long m=mass;
        for(auto &i:asteroids){
            if(m>=i){
                m+=i;
            }
            else{
                return false;
            }

        }

        return true;
    }
};
