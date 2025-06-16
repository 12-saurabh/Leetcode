
class Solution {
public:
    string generateTag(string caption) {
        string s = "#";
        int n = caption.length();
        int i = 0;

        while (i < n && caption[i] == ' ') {
            i++;
        }

        if (i < n && isalpha(caption[i])) {
            s += tolower(caption[i]);
            i++;
        }

        while (i < n) {
            if (caption[i] == ' ') {
                while (i < n && caption[i] == ' ') {
                    i++;
                }
                if (i < n && isalpha(caption[i])) {
                    s += toupper(caption[i]);
                    i++;
                }
            } else if (isalpha(caption[i])) {
                s += tolower(caption[i]);
                i++;
            } else {
                i++;
            }
        }

        if (s.length() > 100) {
            s = s.substr(0, 100);
        }

        return s;
    }
};
