class Solution {
public:

bool isPalindrome(const string &str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

    int longestPalindrome(string s, string t) {
    int maxi = 1;
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            string ss = s.substr(i, j - i + 1);
            if (isPalindrome(ss)) {
                maxi = max(maxi, (int)ss.size());
            }
        }
    }
    
    for (int k = 0; k < t.size(); k++) {
        for (int p = k; p < t.size(); p++) {
            string st = t.substr(k, p - k + 1);
            if (isPalindrome(st)) {
                maxi = max(maxi, (int)st.size());
            }
        }
    }
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            string ss = s.substr(i, j - i + 1);
            
            for (int k = 0; k < t.size(); k++) {
                for (int l = k; l < t.size(); l++) {
                    string st = t.substr(k, l - k + 1);
                    
                    string c = ss + st;
                    if (isPalindrome(c)) {
                        maxi = max(maxi, (int)c.size());
                    }
                }
            }
        }
    }
    
    return maxi;  
        
               
    }
};
