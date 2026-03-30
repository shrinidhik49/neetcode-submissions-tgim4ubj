class Solution {
public:

    string encode(vector<string>& strs) {
        
        string out="";
        for (string &s : strs) {
            out += to_string(s.size());
            out += "#";
            out += s;
        }
        return out;
    }
    
    
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int n = s.size();

        while (i < n) {
        int len = 0;

        while (i<n && s[i] != '#'){
            len = len * 10 + (s[i] - '0');
            ++i;
        }
        ++i;
        res.push_back(s.substr(i,len));
        i+=len;
            
        }

        return res;
    }
};
